/*
2017-06-06 training.h ������ ��
*/

#include "tools.h"
#include "screen.h"
#include "player.h"

extern Player user;

int practiceTraining()
{
	FILE *ReadMapData;
	time_t startTime = 0, endTime = 0;
	int Loop = 0, Loop1 = 0, Loop2 = 0, Loop3 = 0;
	int Direction = 0;
	int Pass = 0;
	int CntTotalData = 0;
	int CntLineData = 0;
	int CntCollision = 0;
	int MapSize = 512;
	int MapData[15][512] = { 0, };        //��
	int PlusY = 0;
	int PlayerArr1 = 0;
	int PlayerArr2 = 0;
	int GageData = 0;
	int GageX = 0;  ///////////////////////������
	int Stage = 1;  ///////////////////////���ӽ�������
	int GameSK = 100;                      //���Ӽӵ�
	int Score = 0;
	int Remainder = 22; ///////////////////������
	int PlayTime = 0;
	int LastStage = 0;

	srand(time(NULL));// �������� ũ�����̶� ����ġ�� �ֱ� ���ؼ� 

	ReadMapData = fopen("GameMap\\Practice.txt", "r+");

	//�� �ҷ����� ����� ��ġ ���� ���� GameMap������ ���� Ȯ�� ����
	for (Loop1 = 0; Loop1 < 15; Loop1++)
	{
		for (Loop2 = 0; Loop2 < MapSize; Loop2++)
		{
			fscanf(ReadMapData, "%d", &MapData[Loop1][Loop2]);
			CntTotalData++;
			//����� ��ġ �ʱ�ȭ
			if (MapData[Loop1][Loop2] == 2)
			{
				PlayerArr1 = Loop1;
				PlayerArr2 = Loop2;
			}
		}
	}
	fclose(ReadMapData);

	CntLineData = CntTotalData / 15;

	gotoxy(24, 26);
	printf("���� : ");
	printf("%d      ", Score);
	gotoxy(43, 26);
	printf("���� �������� : ");
	printf("%d Stage", Stage);
	gotoxy(24, 28);
	printf("�ð� : 0");
	gotoxy(24, 30);
	printf("�浹 : 0");
	gotoxy(24, 35);
	printf(" 1       2       3       4       5         F");
	gotoxy(23, 36);
	printf("����������������������������������������������");
	gotoxy(23, 37);
	printf("��                                          ��");
	gotoxy(23, 38);
	printf("����������������������������������������������");

	//ī��Ʈ�ٿ�
	sndPlaySoundA("music\\count.wav", SND_ASYNC | SND_NODEFAULT);
	Sleep(200);
	for (Loop1 = 0; Loop1 < 7; Loop1++)
	{
		gotoxy(41, 10);
		switch (Loop1)
		{
		case 0:
			printf("R e a d y");
			break;
		case 1:
			printf("    5    ");
			break;
		case 2:
			printf("    4    ");
			break;
		case 3:
			printf("    3    ");
			break;
		case 4:
			printf("    2    ");
			break;
		case 5:
			printf("    1    ");
			break;
		case 6:
			printf("S t a r t");
			break;
		}
		Sleep(1000);
	}

	//���� ��µǴ� �뷡 ���� �� ���ο� �뷡 ���
	PlaySound(NULL, 0, 0);
	sndPlaySoundA("music\\advent.wav", SND_ASYNC | SND_NODEFAULT | SND_LOOP);
	startTime = clock();

	for (Loop1 = 0; Loop1 != CntTotalData / 15;)
	{
		// ��ġ Ȯ�� �� ������ �������� �� ǥ��
		if (LastStage + 2 == Stage)
		{
			LastStage = Stage - 1;
			switch (LastStage)
			{
			case 1:
				gotoxy(25, 35);
				printf("��");
				break;
			case 2:
				gotoxy(33, 35);
				printf("��");
				break;
			case 3:
				gotoxy(41, 35);
				printf("��");
				break;
			case 4:
				gotoxy(49, 35);
				printf("��");
				break;
			}
		}

		// 41���̻� ���ӵ� ��� ���� Ŭ����� �Ǵ�
		if (PlayTime == 41)
		{
			gotoxy(57, 35);
			printf("��");
		}

		//�ۼ�Ʈ ������ ä���ִ� �Լ� 
		if (Loop1 != 0 && Loop1 % 24 == 0)
		{
			textcolor(RED2,BLACK);
			GageX += 2;
			gotoxy(23 + GageX, 37);
			printf("��");
		}

		//���������� ������ ���� �ӵ� ���� 
		if (Loop1 != 0 && Loop1 % (CntLineData / 5) == 0)
		{
			GameSK -= 18;
			Stage++;
			if (Stage > 5)
				Stage = 5;
		}

		textcolor(BLACK,WHITE);
		gotoxy(31, 26);
		printf("%d      ", Score);
		gotoxy(59, 26);
		printf("%d", Stage);
		gotoxy(31, 28);
		printf("%d", PlayTime);
		gotoxy(31, 30);
		printf("%d", CntCollision);

		if (GetAsyncKeyState(0x46) && 0x0001 == TRUE)
		{
			shutDown();
		}

		if (GetAsyncKeyState(0x57) && 0x0001 == TRUE)
		{
			gotoxy(10, 29);
			textcolor(RED2, 0);
			printf("��");
			Sleep(50);
			gotoxy(10, 29);
			textcolor(WHITE, 0);
			printf("��");

			MapData[PlayerArr1][PlayerArr2] = 0;
			PlayerArr2++;
			PlayerArr1--;
			if (PlayerArr1 < 0)
				PlayerArr1--;
			if (MapData[PlayerArr1][PlayerArr2] == 1)
			{
				MapData[PlayerArr1][PlayerArr2] = 3;
				CntCollision++;
			}
			else
			{
				MapData[PlayerArr1][PlayerArr2] = 2;
			}
			Score += 5;
		}

		else if (GetAsyncKeyState(0x53) && 0x0001 == TRUE)
		{
			gotoxy(10, 35);
			textcolor(RED2, 0);
			printf("��");
			Sleep(50);
			gotoxy(10, 35);
			textcolor(WHITE, 0);
			printf("��");
			MapData[PlayerArr1][PlayerArr2] = 0;
			PlayerArr2++;
			PlayerArr1++;
			if (PlayerArr1 > 13)
				PlayerArr1++;
			if (MapData[PlayerArr1][PlayerArr2] == 1)
			{
				MapData[PlayerArr1][PlayerArr2] = 3;
				CntCollision++;
			}
			else
			{
				MapData[PlayerArr1][PlayerArr2] = 2;
			}
			Score += 5;
		}

		else if (GetAsyncKeyState(0x41) && 0x0001 == TRUE)
		{
			gotoxy(4, 32);
			textcolor(RED2, 0);
			printf("��");
			Sleep(50);
			gotoxy(4, 32);
			textcolor(WHITE, 0);
			printf("��");
			MapData[PlayerArr1][PlayerArr2] = 0;
			PlayerArr2++;
			if (MapData[PlayerArr1][PlayerArr2] == 1)
			{
				MapData[PlayerArr1][PlayerArr2] = 3;
				CntCollision++;
			}
			else
			{
				MapData[PlayerArr1][PlayerArr2] = 2;
			}
		}
		else if (GetAsyncKeyState(0x44) && 0x0001 == TRUE)
		{
			gotoxy(16, 32);
			textcolor(RED2, 0);
			printf("��");
			Sleep(50);
			gotoxy(16, 32);
			textcolor(WHITE, 0);
			printf("��");
			MapData[PlayerArr1][PlayerArr2] = 0;
			PlayerArr2++;
			if (MapData[PlayerArr1][PlayerArr2] == 1)
			{
				MapData[PlayerArr1][PlayerArr2] = 3;
				CntCollision++;
			}
			else
			{
				MapData[PlayerArr1][PlayerArr2] = 2;
			}
		}
		else if (GetAsyncKeyState(VK_LEFT) && 0x0001 == TRUE)
		{
			gotoxy(75, 31);
			textcolor(RED2, 0);
			printf("��");
			Sleep(50);
			gotoxy(75, 31);
			textcolor(WHITE, 0);
			printf("��");
			MapData[PlayerArr1][PlayerArr2] = 0;
			PlayerArr2++;
			if (MapData[PlayerArr1][PlayerArr2] == 1)
			{
				MapData[PlayerArr1][PlayerArr2] = 3;
				CntCollision++;
			}
			else
			{
				MapData[PlayerArr1][PlayerArr2] = 2;
			}
		}
		else if (GetAsyncKeyState(VK_UP) && 0x0001 == TRUE)
		{
			gotoxy(81, 28);
			textcolor(RED2, 0);
			printf("��");
			Sleep(50);
			gotoxy(81, 28);
			textcolor(WHITE, 0);
			printf("��");
			MapData[PlayerArr1][PlayerArr2] = 0;
			PlayerArr2++;
			if (MapData[PlayerArr1][PlayerArr2] == 1)
			{
				MapData[PlayerArr1][PlayerArr2] = 3;
				CntCollision++;
			}
			else
			{
				MapData[PlayerArr1][PlayerArr2] = 2;
			}
		}
		else if (GetAsyncKeyState(VK_DOWN) && 0x0001 == TRUE)
		{
			gotoxy(81, 34);
			textcolor(RED2, 0);
			printf("��");
			Sleep(50);
			gotoxy(81, 34);
			textcolor(WHITE, 0);
			printf("��");
			MapData[PlayerArr1][PlayerArr2] = 0;
			PlayerArr2++;
			if (MapData[PlayerArr1][PlayerArr2] == 1)
			{
				MapData[PlayerArr1][PlayerArr2] = 3;
				CntCollision++;
			}
			else
			{
				MapData[PlayerArr1][PlayerArr2] = 2;
			}
		}
		else if (GetAsyncKeyState(VK_RIGHT) & 0x0001 == TRUE)
		{
			gotoxy(87, 31);
			textcolor(RED2, 0);
			printf("��");
			Sleep(50);
			gotoxy(87, 31);
			textcolor(WHITE, 0);
			printf("��");
			textcolor(0,WHITE);
			MapData[PlayerArr1][PlayerArr2] = 0;
			PlayerArr2++;
			if (MapData[PlayerArr1][PlayerArr2] == 1)
			{
				MapData[PlayerArr1][PlayerArr2] = 3;
				CntCollision++;
			}
			else
			{
				MapData[PlayerArr1][PlayerArr2] = 2;
			}
		}
		else
		{
			MapData[PlayerArr1][PlayerArr2] = 0;
			PlayerArr2++;
			if (MapData[PlayerArr1][PlayerArr2] == 1)
			{
				MapData[PlayerArr1][PlayerArr2] = 3;
				CntCollision++;
			}
			else
			{
				MapData[PlayerArr1][PlayerArr2] = 2;
			}
		}

		PlusY = 3;

		if (Loop1 + Remainder > CntTotalData / 15)
			Remainder--;
		textcolor(BLACK,WHITE);

		for (Loop2 = 0; Loop2 != 15; Loop2++)
		{
			gotoxy(24, PlusY);
			for (Loop3 = Loop1; Loop3 < Loop1 + Remainder; Loop3++)
			{
				if (PlayTime <7)
					textcolor(RED2,1);
				else if (PlayTime < 11)
					textcolor(MAGENTA1,2);
				else if (PlayTime < 13)
					textcolor(CYAN2,3);
				else if (PlayTime < 17)
					textcolor(GREEN2,4);
				else if (PlayTime < 19)
					textcolor(WHITE,5);
				else if (PlayTime < 21)
					textcolor(WHITE,6);
				else if (PlayTime < 22)
					textcolor(WHITE,7);
				else if (PlayTime < 24)
					textcolor(WHITE,8);
				else if (PlayTime < 26)
					textcolor(WHITE,9);
				else if (PlayTime < 28)
					textcolor(WHITE,10);
				else if (PlayTime < 30)
					textcolor(WHITE,11);
				else if (PlayTime < 33)
					textcolor(WHITE,12);
				else if (PlayTime < 35)
					textcolor(WHITE,13);
				else if (PlayTime < 37)
					textcolor(WHITE,14);
				else if (PlayTime < 39)
					textcolor(WHITE,1);
				else if (PlayTime < 41)
					textcolor(WHITE,2);
				else
					textcolor(WHITE,3);

				switch (MapData[Loop2][Loop3])
				{
				case 0:
					textcolor(RED2,WHITE);
					printf("  ");
					break;
				case 1:
					printf("  ");
					break;
				case 2:
					textcolor(YELLOW2,YELLOW2);
					printf("  ");
					break;
				case 3:
					textcolor(BLUE1,BLUE1);
					printf("  ");
					break;
				case 4:
					textcolor(YELLOW2,BLACK);
					printf("��");
					break;
				case 5:
					textcolor(BLUE2,CYAN2);
					printf("  ");
					break;
				}
			}
			textcolor(BLACK, WHITE);
			PlusY++;
		}

		textcolor(BLACK,WHITE);
		Sleep(GameSK);
		Score += 3;
		Loop1++;
		endTime = clock();
		PlayTime = (endTime - startTime) / (CLOCKS_PER_SEC);
	}


	gotoxy(57, 35);
	printf("��");
	Sleep(300);

	clearScreen();

	gotoxy(37, 10);
	printf("All Stage Clear!");

	Sleep(1000);

	PracticeResult(Stage, Score, PlayTime, CntCollision);

	return;
}

int PracticeResult(int ResultStage, int ResultScore, int ResultPlayTime, int ResultCollision)
{
	int Loop = 0, Loop1 = 0, Loop2 = 0;
	int ResultTotalScore = 0;
	int Pass = 0;

	clearScreen();

	gotoxy(41, 27);
	printf("�� �� �� ��");
	gotoxy(36, 30);
	Sleep(300);
	printf("���� : %d", ResultScore);
	Sleep(300);
	gotoxy(29, 32);
	printf("�÷��� �ð� : %d", ResultPlayTime);
	Sleep(300);
	gotoxy(27, 34);
	printf("�Ϸ� �������� :");

	gotoxy(43, 34);
	printf("Practice Mode Clear!");

	Sleep(300);
	ResultTotalScore = ResultScore + ResultStage * 50;

	ResultTotalScore += 100;

	gotoxy(31, 36);
	printf("�浹 Ƚ�� : %d", ResultCollision);
	Sleep(300);

	if(user.monster.LV == 0) user.isItem[2]=1;
	user.monster.hungry -= rand()%10+1;
	PlaySound(NULL, 0, 0);
	clearScreen();
	while(kbhit())getch();
	return 0;
}

int easyTraining()
{
	FILE *ReadMapData;
	time_t startTime = 0, endTime = 0;
	int Loop = 0, Loop1 = 0, Loop2 = 0, Loop3 = 0;
	int Direction = 0;
	int Pass = 0;
	int CntTotalData = 0;
	int CntLineData = 0;
	int MapSize = 512;
	int MapData[15][512] = { 0, };  ///////��
	int PlusY = 0;
	int PlayerArr1 = 0;
	int PlayerArr2 = 0;
	int GageData = 0;
	int GageX = 0;  ///////////////////////������
	int GameEnd = 0;  /////////////////////���� ���� Ȯ��
	int Stage = 1;  ///////////////////////���ӽ�������
	int GameSK = 100; /////////////////////���Ӽӵ�
	int 
		Score = 0;
	int Remainder = 22; ///////////////////������
	int PlayTime = 0;
	int LastStage = 0;
	int Life = 3;

	user.monster.hungry -= rand()%15+5;

	ReadMapData = fopen("GameMap\\Practice.txt", "r+");

	for (Loop1 = 0; Loop1 < 15; Loop1++)
	{
		for (Loop2 = 0; Loop2 < MapSize; Loop2++)
		{
			fscanf(ReadMapData, "%d", &MapData[Loop1][Loop2]);
			CntTotalData++;
			if (MapData[Loop1][Loop2] == 2)
			{
				PlayerArr1 = Loop1;
				PlayerArr2 = Loop2;
			}
		}
	}
	fclose(ReadMapData);

	CntLineData = CntTotalData / 15;

	gotoxy(24, 26);
	printf("���� ���� : ");
	printf("%d      ", Score);
	gotoxy(43, 26);
	printf("���� �������� : ");
	printf("%d Stage", Stage);
	gotoxy(24, 28);
	printf("�ð� : 0");
	gotoxy(24, 30);
	printf("��� : 3");
	gotoxy(24, 35);
	printf(" 1       2       3       4       5         F");
	gotoxy(23, 36);
	printf("����������������������������������������������");
	gotoxy(23, 37);
	printf("��                                          ��");
	gotoxy(23, 38);
	printf("����������������������������������������������");

	sndPlaySoundA("music\\count.wav", SND_ASYNC | SND_NODEFAULT);
	Sleep(200);
	for (Loop1 = 0; Loop1 < 7; Loop1++)
	{
		gotoxy(41, 10);
		switch (Loop1)
		{
		case 0:
			printf("R e a d y");
			break;
		case 1:
			printf("    5    ");
			break;
		case 2:
			printf("    4    ");
			break;
		case 3:
			printf("    3    ");
			break;
		case 4:
			printf("    2    ");
			break;
		case 5:
			printf("    1    ");
			break;
		case 6:
			printf("S t a r t");
			break;
		}
		Sleep(1000);
	}
	PlaySound(NULL, 0, 0);
	sndPlaySoundA("music\\easy.wav", SND_ASYNC | SND_NODEFAULT | SND_LOOP);
	startTime = clock();

	for (Loop1 = 0; Loop1 != CntTotalData / 15;)
	{
		if (GameEnd == 1)
			break;

		if (LastStage + 2 == Stage)
		{
			LastStage = Stage - 1;
			switch (LastStage)
			{
			case 1:
				gotoxy(25, 35);
				printf("��");
				break;
			case 2:
				gotoxy(33, 35);
				printf("��");
				break;
			case 3:
				gotoxy(41, 35);
				printf("��");
				break;
			case 4:
				gotoxy(49, 35);
				printf("��");
				break;
			}
		}

		if (Loop1 != 0 && Loop1 % 24 == 0)
		{
			textcolor(RED2,BLACK);
			GageX += 2;
			gotoxy(23 + GageX, 37);
			printf("��");
		}

		if (Loop1 != 0 && Loop1 % (CntLineData / 5) == 0)
		{
			GameSK -= 18;
			Stage++;
			if (Stage > 5)
				Stage = 5;
		}

		textcolor(BLACK,WHITE);
		gotoxy(31, 26);
		printf("%d      ", Score);
		gotoxy(59, 26);
		printf("%d", Stage);
		gotoxy(31, 28);
		printf("%d", PlayTime);

		fflush(stdin);

		if (GetAsyncKeyState(0x46) && 0x0001 == TRUE)
		{
			shutDown();
		}

		if (GetAsyncKeyState(0x57) && 0x0001 == TRUE)
		{
			MapData[PlayerArr1][PlayerArr2] = 0;
			PlayerArr2++;
			PlayerArr1--;
			if (PlayerArr1 < 0)
				PlayerArr1--;
			if (MapData[PlayerArr1][PlayerArr2] == 1)
			{
				MapData[PlayerArr1][PlayerArr2] = 3;
				textcolor(BLACK,WHITE);
				Life--;
				if (Life == 0)
					GameEnd = 1;
				gotoxy(31, 30);
				printf("%d  ", Life);
			}
			else
			{
				MapData[PlayerArr1][PlayerArr2] = 2;
			}
			Score += 5;
		}
		else if (GetAsyncKeyState(0x53) && 0x0001 == TRUE)
		{
			MapData[PlayerArr1][PlayerArr2] = 0;
			PlayerArr2++;
			PlayerArr1++;
			if (PlayerArr1 > 13)
				PlayerArr1++;
			if (MapData[PlayerArr1][PlayerArr2] == 1)
			{
				MapData[PlayerArr1][PlayerArr2] = 3;
				Life--;
				if (Life == 0)
					GameEnd = 1;
				gotoxy(31, 30);
				printf("%d  ", Life);
			}
			else
			{
				MapData[PlayerArr1][PlayerArr2] = 2;
			}
			Score += 5;
		}
		else if (GetAsyncKeyState(0x41) && 0x0001 == TRUE)
		{
			MapData[PlayerArr1][PlayerArr2] = 0;
			PlayerArr2++;
			if (MapData[PlayerArr1][PlayerArr2] == 1)
			{
				MapData[PlayerArr1][PlayerArr2] = 3;
				Life--;
				if (Life == 0)
					GameEnd = 1;
				gotoxy(31, 30);
				printf("%d  ", Life);
			}
			else
			{
				MapData[PlayerArr1][PlayerArr2] = 2;
			}
		}
		else if (GetAsyncKeyState(0x44) && 0x0001 == TRUE)
		{
			MapData[PlayerArr1][PlayerArr2] = 0;
			PlayerArr2++;
			if (MapData[PlayerArr1][PlayerArr2] == 1)
			{
				MapData[PlayerArr1][PlayerArr2] = 3;
				Life--;
				if (Life == 0)
					GameEnd = 1;
				gotoxy(31, 30);
				printf("%d  ", Life);
			}
			else
			{
				MapData[PlayerArr1][PlayerArr2] = 2;
			}
		}
		else if (GetAsyncKeyState(VK_LEFT) && 0x0001 == TRUE)
		{
			MapData[PlayerArr1][PlayerArr2] = 0;
			PlayerArr2++;
			if (MapData[PlayerArr1][PlayerArr2] == 1)
			{
				MapData[PlayerArr1][PlayerArr2] = 3;
				Life--;
				if (Life == 0)
					GameEnd = 1;
				gotoxy(31, 30);
				printf("%d  ", Life);
			}
			else
			{
				MapData[PlayerArr1][PlayerArr2] = 2;
			}
		}
		else if (GetAsyncKeyState(VK_UP) && 0x0001 == TRUE)
		{
			MapData[PlayerArr1][PlayerArr2] = 0;
			PlayerArr2++;
			if (MapData[PlayerArr1][PlayerArr2] == 1)
			{
				MapData[PlayerArr1][PlayerArr2] = 3;
				Life--;
				if (Life == 0)
					GameEnd = 1;
				gotoxy(31, 30);
				printf("%d  ", Life);
			}
			else
			{
				MapData[PlayerArr1][PlayerArr2] = 2;
			}
		}
		else if (GetAsyncKeyState(VK_DOWN) && 0x0001 == TRUE)
		{
			MapData[PlayerArr1][PlayerArr2] = 0;
			PlayerArr2++;
			if (MapData[PlayerArr1][PlayerArr2] == 1)
			{
				MapData[PlayerArr1][PlayerArr2] = 3;
				Life--;
				if (Life == 0)
					GameEnd = 1;
				gotoxy(31, 30);
				printf("%d  ", Life);
			}
			else
			{
				MapData[PlayerArr1][PlayerArr2] = 2;
			}
		}
		else if (GetAsyncKeyState(VK_RIGHT) & 0x0001 == TRUE)
		{
			MapData[PlayerArr1][PlayerArr2] = 0;
			PlayerArr2++;
			if (MapData[PlayerArr1][PlayerArr2] == 1)
			{
				MapData[PlayerArr1][PlayerArr2] = 3;
				Life--;
				if (Life == 0)
					GameEnd = 1;
				gotoxy(31, 30);
				printf("%d  ", Life);
			}
			else
			{
				MapData[PlayerArr1][PlayerArr2] = 2;
			}
		}
		else
		{
			MapData[PlayerArr1][PlayerArr2] = 0;
			PlayerArr2++;
			if (MapData[PlayerArr1][PlayerArr2] == 1)
			{
				MapData[PlayerArr1][PlayerArr2] = 3;
				Life--;
				if (Life == 0)
					GameEnd = 1;
				gotoxy(31, 30);
				printf("%d  ", Life);
			}
			else
			{
				MapData[PlayerArr1][PlayerArr2] = 2;
			}
		}

		PlusY = 3;

		if (Loop1 + Remainder > CntTotalData / 15)
			Remainder--;
		textcolor(BLACK,WHITE);

		for (Loop2 = 0; Loop2 != 15; Loop2++)
		{
			gotoxy(24, PlusY);
			for (Loop3 = Loop1; Loop3 != Loop1 + Remainder; Loop3++)
			{
				if (PlayTime <7)
					textcolor(RED2,1);
				else if (PlayTime < 11)
					textcolor(MAGENTA1,2);
				else if (PlayTime < 13)
					textcolor(CYAN2,3);
				else if (PlayTime < 17)
					textcolor(GREEN2,4);
				else if (PlayTime < 19)
					textcolor(WHITE,5);
				else if (PlayTime < 21)
					textcolor(WHITE,6);
				else if (PlayTime < 22)
					textcolor(WHITE,7);
				else if (PlayTime < 24)
					textcolor(WHITE,8);
				else if (PlayTime < 26)
					textcolor(WHITE,9);
				else if (PlayTime < 28)
					textcolor(WHITE,10);
				else if (PlayTime < 30)
					textcolor(WHITE,11);
				else if (PlayTime < 33)
					textcolor(WHITE,12);
				else if (PlayTime < 35)
					textcolor(WHITE,13);
				else if (PlayTime < 37)
					textcolor(WHITE,14);
				else if (PlayTime < 39)
					textcolor(WHITE,1);
				else if (PlayTime < 41)
					textcolor(WHITE,2);
				else
					textcolor(WHITE,3);

				switch (MapData[Loop2][Loop3])
				{
				case 0:
					textcolor(RED2,WHITE);
					printf("  ");
					break;
				case 1:
					printf("  ");
					break;
				case 2:
					textcolor(YELLOW2,YELLOW2);
					printf("  ");
					break;
				case 3:
					textcolor(BLUE1,BLUE1);
					printf("  ");
					break;
				case 4:
					textcolor(YELLOW2,BLACK);
					printf("��");
					break;
				case 5:
					textcolor(BLUE2,CYAN2);
					printf("  ");
					break;
				}
			}
			textcolor(BLACK, WHITE);
			PlusY++;
		}
		textcolor(BLACK,WHITE);
		Sleep(GameSK);
		Score += 3;
		Loop1++;
		endTime = clock();
		PlayTime = (endTime - startTime) / (CLOCKS_PER_SEC);
	}

	if (GameEnd == 0)
	{
		gotoxy(57, 35);
		printf("��");
	}

	Sleep(300);

	if (GameEnd == 1)
	{
		sndPlaySoundA("music\\gameover.wav", SND_ASYNC | SND_NODEFAULT );
		upClearScreen();
		gotoxy(42, 10);
		printf("Game Over");
	}
	else if (GameEnd == 0)
	{
		upClearScreen();
		gotoxy(37, 10);
		printf("All Stage Clear!");
	}

	Sleep(1000);

	easyPracticeResult(Stage, Score, PlayTime, GameEnd);

	return 0;
}

int easyPracticeResult(int ResultStage, int Score, int ResultPlayTime, int ResultGameEnd)  // ������� ���â
{
	int Loop = 0, Loop1 = 0, Loop2 = 0;
	int ResultRank = 1;
	int TotalScore = 0;
	int Pass = 0;
	int LastSel = 0;
	int SelNext = 0;
	int exp = 0;
	int credit = 0;
	char NickName[20] = { 0, };

	clearScreen();

	gotoxy(41, 27);
	printf("�� �� �� ��");
	gotoxy(36, 30);
	Sleep(300);
	printf("���� : %d", Score);
	Sleep(300);
	gotoxy(29, 32);
	printf("�÷��� �ð� : %d", ResultPlayTime);
	Sleep(300);
	gotoxy(27, 34);
	printf("�Ϸ� �������� :");
	switch (ResultStage)
	{
	case 1:
		gotoxy(43, 34);
		printf("1");
		break;
	case 2:
		gotoxy(43, 34);
		printf("1");
		Sleep(500);
		gotoxy(43, 34);
		printf("2");
		break;
	case 3:
		gotoxy(43, 34);
		printf("1");
		Sleep(500);
		gotoxy(43, 34);
		printf("2");
		Sleep(500);
		gotoxy(43, 34);
		printf("3");
		break;
	case 4:
		gotoxy(43, 34);
		printf("1");
		Sleep(500);
		gotoxy(43, 34);
		printf("2");
		Sleep(500);
		gotoxy(43, 34);
		printf("3");
		Sleep(500);
		gotoxy(43, 34);
		printf("4");
		break;
	case 5:
		gotoxy(43, 34);
		printf("1");
		Sleep(500);
		gotoxy(43, 34);
		printf("2");
		Sleep(500);
		gotoxy(43, 34);
		printf("3");
		Sleep(500);
		gotoxy(43, 34);
		printf("4");
		Sleep(500);
		gotoxy(43, 34);
		printf("5");
		break;
	}
	if (ResultGameEnd == 0)
	{
		gotoxy(43, 34);
		printf("All Stage Clear!");
	}
	Sleep(300);
	TotalScore = Score + ResultStage * 50;
	if (ResultGameEnd == 0)
		TotalScore += 100;

	gotoxy(36, 36);
	printf("��� : �� �� �� �� ��");

	if (TotalScore < 1100)
	{
		ResultRank = 1;
	}
	else if (TotalScore < 1500)
	{
		ResultRank = 2;
	}
	else if (TotalScore < 1900)
	{
		ResultRank = 3;
	}
	else if (TotalScore < 2100 || TotalScore > 2100 && ResultStage == 4)
	{
		ResultRank = 4;
	}
	else if (TotalScore >= 2200 && ResultStage == 5)
	{
		ResultRank = 5;
	}

	

	switch (ResultRank)
	{
	case 1:
		user.monster.current_evolution[user.monster.LV] += 10;
		user.credit += 10;
		PlaySound(NULL, 0, 0);
		sndPlaySoundA("music\\effect_1.wav", SND_ASYNC | SND_NODEFAULT);
		gotoxy(43, 36);
		printf("��");
		gotoxy(27, 37); 
		printf("ȹ���� ũ���� : %d", 10);
		gotoxy(47, 37);
		printf("ȹ���� ����ġ : %d", 10);
		break;
	case 2:
		user.monster.current_evolution[user.monster.LV] += 30;
		user.credit += 30;
		PlaySound(NULL, 0, 0);
		sndPlaySoundA("music\\effect_1.wav", SND_ASYNC | SND_NODEFAULT);
		gotoxy(43, 36);
		printf("��");
		Sleep(300);
		sndPlaySoundA("music\\effect_1.wav", SND_ASYNC | SND_NODEFAULT);
		gotoxy(46, 36);
		printf("��");
		gotoxy(27, 37); 
		printf("ȹ���� ũ���� : %d", 30);
		gotoxy(47, 37);
		printf("ȹ���� ����ġ : %d", 30);
		break;
	case 3:
		user.monster.current_evolution[user.monster.LV] += 90;
		user.credit += 90;
		PlaySound(NULL, 0, 0);
		sndPlaySoundA("music\\effect_1.wav", SND_ASYNC | SND_NODEFAULT);
		gotoxy(43, 36);
		printf("��");
		Sleep(300);
		sndPlaySoundA("music\\effect_1.wav", SND_ASYNC | SND_NODEFAULT);
		gotoxy(46, 36);
		printf("��");
		Sleep(300);
		sndPlaySoundA("music\\effect_1.wav", SND_ASYNC | SND_NODEFAULT);
		gotoxy(49, 36);
		printf("��");
		gotoxy(27, 37); 
		printf("ȹ���� ũ���� : %d", 90);
		gotoxy(47, 37);
		printf("ȹ���� ����ġ : %d", 90);
		break;
	case 4:
		user.monster.current_evolution[user.monster.LV] += 180;
		user.credit += 180;
		PlaySound(NULL, 0, 0);
		sndPlaySoundA("music\\effect_1.wav", SND_ASYNC | SND_NODEFAULT);
		gotoxy(43, 36);
		printf("��");
		Sleep(300);
		sndPlaySoundA("music\\effect_1.wav", SND_ASYNC | SND_NODEFAULT);
		gotoxy(46, 36);
		printf("��");
		Sleep(300);
		sndPlaySoundA("music\\effect_1.wav", SND_ASYNC | SND_NODEFAULT);
		gotoxy(49, 36);
		printf("��");
		Sleep(300);
		sndPlaySoundA("music\\effect_1.wav", SND_ASYNC | SND_NODEFAULT);
		gotoxy(52, 36);
		printf("��");
		gotoxy(27, 37); 
		printf("ȹ���� ũ���� : %d", 180);
		gotoxy(47, 37);
		printf("ȹ���� ����ġ : %d", 180);
		break;
	case 5:
		if (ResultGameEnd == 1)
		{
			user.monster.current_evolution[user.monster.LV] += 220;
			user.credit += 220;
			PlaySound(NULL, 0, 0);
			sndPlaySoundA("music\\effect_1.wav", SND_ASYNC | SND_NODEFAULT);
			gotoxy(43, 36);
			printf("��");
			Sleep(300);
			sndPlaySoundA("music\\effect_1.wav", SND_ASYNC | SND_NODEFAULT);
			gotoxy(46, 36);
			printf("��");
			Sleep(300);
			sndPlaySoundA("music\\effect_1.wav", SND_ASYNC | SND_NODEFAULT);
			gotoxy(49, 36);
			printf("��");
			Sleep(300);
			sndPlaySoundA("music\\effect_1.wav", SND_ASYNC | SND_NODEFAULT);
			gotoxy(52, 36);
			printf("��");
			Sleep(300);
			sndPlaySoundA("music\\effect_1.wav", SND_ASYNC | SND_NODEFAULT);
			gotoxy(55, 36);
			printf("��");
			gotoxy(27, 37); 
			printf("ȹ���� ũ���� : %d", 220);
			gotoxy(47, 37);
			printf("ȹ���� ����ġ : %d", 220);
		}
		else
		{
			user.monster.current_evolution[user.monster.LV] += 300;
			user.credit += 300;
			gotoxy(43, 36);
			printf("��");
			Sleep(300);
			gotoxy(46, 36);
			printf("��");
			Sleep(300);
			gotoxy(49, 36);
			printf("��");
			Sleep(300);
			gotoxy(52, 36);
			printf("��");
			Sleep(300);
			gotoxy(55, 36);
			printf("��");
			gotoxy(27, 37); 
			printf("ȹ���� ũ���� : %d", 300);
			gotoxy(47, 37);
			printf("ȹ���� ����ġ : %d", 300);
		}
		break;
	}

	Sleep(1500);
	while(kbhit())getch();
	clearScreen();
	return 0;
}	   

int hardTraining()
{
	FILE *ReadMapData;
	time_t startTime = 0, endTime = 0;
	int Loop = 0, Loop1 = 0, Loop2 = 0, Loop3 = 0, Loop4 = 0, Loop5 = 0, Loop6 = 0;
	int Direction = 0;
	int Pass = 0;
	int CntTotalData = 0;
	int CntLineData = 0;
	int MapSize = 512;
	int MapData[15][512] = { 0, };  ///////��
	int BackUpMapData[15][512] = { 0, };
	int PlusY = 0;
	int PlayerArr1 = 0;
	int PlayerArr2 = 0;
	int GageData = 0;
	int GageX = 0;  ///////////////////////������
	int GameEnd = 0;  /////////////////////���� ���� Ȯ��
	int Score = 0;
	int CP5Score = 0, CP6Score = 0, CP7Score = 0, CP8Score = 0, CP9Score = 0;
	int Remainder = 22; ///////////////////������
	float PlayTime = 0;
	int CheckPoint = 5;
	int LastCheckPoint = 4;
	int CP5_1 = 0, CP5_2 = 0, CP6_1 = 0, CP6_2 = 0, CP7_1 = 0, CP7_2 = 0, CP8_1 = 0, CP8_2 = 0, CP9_1 = 0, CP9_2 = 0;	// üũ����Ʈ 1~5
	int Life = 2;	// ����

	user.monster.hungry -= rand()%30+20;

	ReadMapData = fopen("GameMap\\Hard.txt", "r+");		// Taptap_2.txt���� ���� �о��

	for (Loop1 = 0; Loop1 < 15; Loop1++)
	{
		for (Loop2 = 0; Loop2 < MapSize; Loop2++)
		{
			fscanf(ReadMapData, "%d", &MapData[Loop1][Loop2]);
			CntTotalData++;
		}
	}
	fclose(ReadMapData);

	// �о�� �ʿ� �ִ� üũ����Ʈ�� �迭�� �־���
	for (Loop1 = 0; Loop1 < 15; Loop1++)
	{
		for (Loop2 = 0; Loop2 < MapSize; Loop2++)
		{
			BackUpMapData[Loop1][Loop2] = MapData[Loop1][Loop2];
			switch (MapData[Loop1][Loop2])
			{
			case 5:
				CP5_1 = Loop1;
				CP5_2 = Loop2;
				break;
			case 6:
				CP6_1 = Loop1;
				CP6_2 = Loop2;
				break;
			case 7:
				CP7_1 = Loop1;
				CP7_2 = Loop2;
				break;
			case 8:
				CP8_1 = Loop1;
				CP8_2 = Loop2;
				break;
			case 9:
				CP9_1 = Loop1;
				CP9_2 = Loop2;
				break;
			}
		}
	}

	MapData[6][2] = 2;
	PlayerArr1 = 6;
	PlayerArr2 = 2;

	CntLineData = CntTotalData / 15;

	gotoxy(24, 26);
	printf("���� ���� : ");
	printf("%d      ", Score);
	gotoxy(24, 28);
	printf("��� : 2");
	gotoxy(24, 30);
	printf("üũ����Ʈ 1 : ?");
	gotoxy(24, 32);
	printf("üũ����Ʈ 2 : ?");
	gotoxy(24, 34);
	printf("üũ����Ʈ 3 : ?");
	gotoxy(24, 36);
	printf("üũ����Ʈ 4 : ?");
	gotoxy(24, 38);
	printf("üũ����Ʈ 5 : ?");

	// �뷡 ���
	PlaySound(NULL, 0, 0);
	sndPlaySoundA("music\\count.wav", SND_ASYNC | SND_NODEFAULT);
	Sleep(200);

	// ī��Ʈ�ٿ�
	for (Loop1 = 0; Loop1 < 7; Loop1++)
	{
		gotoxy(41, 10);
		switch (Loop1)
		{
		case 0:
			printf("R e a d y");
			break;
		case 1:
			printf("    5    ");
			break;
		case 2:
			printf("    4    ");
			break;
		case 3:
			printf("    3    ");
			break;
		case 4:
			printf("    2    ");
			break;
		case 5:
			printf("    1    ");
			break;
		case 6:
			printf("S t a r t");
			break;
		}
		Sleep(1000);
	}

	// �ΰ��� �뷡 ���
	sndPlaySoundA("music\\hard.wav", SND_ASYNC | SND_NODEFAULT | SND_LOOP);

	// ���ӽ���
	startTime = clock();
	for (Loop1 = 0; Loop1 != CntTotalData / 15;)
	{
		if (GameEnd == 1)
			break;

		textcolor(BLACK,WHITE);
		gotoxy(35, 26);
		printf("%d      ", Score);

		fflush(stdin);
		textcolor(BLACK,WHITE);

		if (GetAsyncKeyState(0x46) && 0x0001 == TRUE)
		{
			shutDown();
		}

		// ����ڿ��� Ű�� �Է¹޾� ��ġ �� ������Ʈ
		if (GetAsyncKeyState(0x57) && 0x0001 == TRUE)
		{
			MapData[PlayerArr1][PlayerArr2] = 0;
			PlayerArr2++;
			PlayerArr1--;
			switch (MapData[PlayerArr1][PlayerArr2])
			{
			case 1:
				MapData[PlayerArr1][PlayerArr2] = 1;
				textcolor(BLACK,WHITE);
				Life--;
				switch (Life)
				{
				case 0:
					GameEnd = 1;
					gotoxy(31, 28);
					printf("%d  ", Life);
					break;
				default:
					switch (CheckPoint)
					{
					case 5:
						Loop1 = CP5_2 - 2;
						PlayerArr1 = CP5_1;
						PlayerArr2 = CP5_2;
						Score = CP5Score;
						break;
					case 6:
						Loop1 = CP6_2 - 2;
						PlayerArr1 = CP6_1;
						PlayerArr2 = CP6_2;
						Score = CP6Score;
						break;
					case 7:
						Loop1 = CP7_2 - 2;
						PlayerArr1 = CP7_1;
						PlayerArr2 = CP7_2;
						Score = CP7Score;
						break;
					case 8:
						Loop1 = CP8_2 - 2;
						PlayerArr1 = CP8_1;
						PlayerArr2 = CP8_2;
						Score = CP8Score;
						break;
					case 9:
						Loop1 = CP9_2 - 2;
						PlayerArr1 = CP9_1;
						PlayerArr2 = CP9_2;
						Score = CP9Score;
						break;
					}
					break;
				}
				gotoxy(35, 26);
				printf("%d      ", Score);
				gotoxy(31, 28);
				printf("%d  ", Life);
				if (GameEnd != 1)
				{
					for (Loop6 = 0; Loop6 < 4; Loop6++)
					{
						gotoxy(41, 10);
						switch (Loop6)
						{
						case 0:
							printf("    3    ");
							break;
						case 1:
							printf("    2    ");
							break;
						case 2:
							printf("    1    ");
							break;
						case 3:
							printf("S t a r t");
							break;
						}
						Sleep(1000);
					}
				}
				break;
			case 4:
				Life++;
				gotoxy(31, 28);
				printf("%d  ", Life);
				break;
			case 5:
				CheckPoint = 5;
				if (LastCheckPoint != CheckPoint)
				{
					CP5Score = Score;
					gotoxy(39, 30);
					printf("%d", Score);
					LastCheckPoint = CheckPoint;
				}
				break;
			case 6:
				CheckPoint = 6;
				if (LastCheckPoint != CheckPoint)
				{
					CP6Score = Score;
					gotoxy(39, 32);
					printf("%d", Score);
					LastCheckPoint = CheckPoint;
				}
				break;
			case 7:
				CheckPoint = 7;
				if (LastCheckPoint != CheckPoint)
				{
					CP7Score = Score;
					gotoxy(39, 34);
					printf("%d", Score);
					LastCheckPoint = CheckPoint;
				}
				break;
			case 8:
				CheckPoint = 8;
				if (LastCheckPoint != CheckPoint)
				{
					CP8Score = Score;
					gotoxy(39, 36);
					printf("%d",Score);
					LastCheckPoint = CheckPoint;
				}
				break;
			case 9:
				CheckPoint = 9;
				if (LastCheckPoint != CheckPoint)
				{
					CP9Score = Score;
					gotoxy(39, 38);
					printf("%d", Score);
					LastCheckPoint = CheckPoint;
				}
				break;
			default:
				break;
			}
			MapData[PlayerArr1][PlayerArr2] = 2;
			Score += 5;
		}
		else if (GetAsyncKeyState(0x53) && 0x0001 == TRUE)
		{
			MapData[PlayerArr1][PlayerArr2] = 0;
			PlayerArr2++;
			PlayerArr1++;
			switch (MapData[PlayerArr1][PlayerArr2])
			{
			case 1:
				MapData[PlayerArr1][PlayerArr2] = 1;
				Life--;
				switch (Life)
				{
				case 0:
					GameEnd = 1;
					gotoxy(31, 28);
					printf("%d  ", Life);
					break;
				default:
					switch (CheckPoint)
					{
					case 5:
						Loop1 = CP5_2 - 2;
						PlayerArr1 = CP5_1;
						PlayerArr2 = CP5_2;
						Score = CP5Score;
						break;
					case 6:
						Loop1 = CP6_2 - 2;
						PlayerArr1 = CP6_1;
						PlayerArr2 = CP6_2;
						Score = CP6Score;
						break;
					case 7:
						Loop1 = CP7_2 - 2;
						PlayerArr1 = CP7_1;
						PlayerArr2 = CP7_2;
						Score = CP7Score;
						break;
					case 8:
						Loop1 = CP8_2 - 2;
						PlayerArr1 = CP8_1;
						PlayerArr2 = CP8_2;
						Score = CP8Score;
						break;
					case 9:
						Loop1 = CP9_2 - 2;
						PlayerArr1 = CP9_1;
						PlayerArr2 = CP9_2;
						Score = CP9Score;
						break;
					}
					break;
				}
				gotoxy(35, 26);
				printf("%d      ", Score);
				gotoxy(31, 28);
				printf("%d  ", Life);
				if (GameEnd != 1)
				{
					for (Loop6 = 0; Loop6 < 4; Loop6++)
					{
						gotoxy(41, 10);
						switch (Loop6)
						{
						case 0:
							printf("    3    ");
							break;
						case 1:
							printf("    2    ");
							break;
						case 2:
							printf("    1    ");
							break;
						case 3:
							printf("S t a r t");
							break;
						}
						Sleep(1000);
					}
				}
				break;
			case 4:
				Life++;
				gotoxy(31, 28);
				printf("%d  ", Life);
				break;
			case 5:
				CheckPoint = 5;
				if (LastCheckPoint != CheckPoint)
				{
					CP5Score = Score;
					gotoxy(39, 30);
					printf("%d", Score);
					LastCheckPoint = CheckPoint;
				}
				break;
			case 6:
				CheckPoint = 6;
				if (LastCheckPoint != CheckPoint)
				{
					CP6Score = Score;
					gotoxy(39, 32);
					printf("%d", Score);
					LastCheckPoint = CheckPoint;
				}
				break;
			case 7:
				CheckPoint = 7;
				if (LastCheckPoint != CheckPoint)
				{
					CP7Score = Score;
					gotoxy(39, 34);
					printf("%d", Score);
					LastCheckPoint = CheckPoint;
				}
				break;
			case 8:
				CheckPoint = 8;
				if (LastCheckPoint != CheckPoint)
				{
					CP8Score = Score;
					gotoxy(39, 36);
					printf("%d", Score);
					LastCheckPoint = CheckPoint;
				}
				break;
			case 9:
				CheckPoint = 9;
				if (LastCheckPoint != CheckPoint)
				{
					CP9Score = Score;
					gotoxy(39, 38);
					printf("%d", Score);
					LastCheckPoint = CheckPoint;
				}
				break;
			default:
				break;
			}
			MapData[PlayerArr1][PlayerArr2] = 2;
			Score += 5;
		}
		else
		{
			MapData[PlayerArr1][PlayerArr2] = 0;
			PlayerArr2++;
			switch (MapData[PlayerArr1][PlayerArr2])
			{
			case 1:
				MapData[PlayerArr1][PlayerArr2] = 1;
				Life--;
				gotoxy(31, 28);
				printf("%d  ", Life);
				switch (Life)
				{
				case 0:
					GameEnd = 1;
					gotoxy(31, 28);
					printf("%d  ", Life);
					break;
				default:
					switch (CheckPoint)
					{
					case 5:
						Loop1 = CP5_2 - 2;
						PlayerArr1 = CP5_1;
						PlayerArr2 = CP5_2;
						Score = CP5Score;
						break;
					case 6:
						Loop1 = CP6_2 - 2;
						PlayerArr1 = CP6_1;
						PlayerArr2 = CP6_2;
						Score = CP6Score;
						break;
					case 7:
						Loop1 = CP7_2 - 2;
						PlayerArr1 = CP7_1;
						PlayerArr2 = CP7_2;
						Score = CP7Score;
						break;
					case 8:
						Loop1 = CP8_2 - 2;
						PlayerArr1 = CP8_1;
						PlayerArr2 = CP8_2;
						Score = CP8Score;
						break;
					case 9:
						Loop1 = CP9_2 - 2;
						PlayerArr1 = CP9_1;
						PlayerArr2 = CP9_2;
						Score = CP9Score;
						break;
					}
					break;
				}
				gotoxy(35, 26);
				printf("%d      ", Score);
				gotoxy(31, 28);
				printf("%d  ", Life);
				if (GameEnd != 1)
				{
					for (Loop6 = 0; Loop6 < 4; Loop6++)
					{
						gotoxy(41, 10);
						switch (Loop6)
						{
						case 0:
							printf("    3    ");
							break;
						case 1:
							printf("    2    ");
							break;
						case 2:
							printf("    1    ");
							break;
						case 3:
							printf("S t a r t");
							break;
						}
						Sleep(1000);
					}
				}
				break;
			case 4:
				Life++;
				gotoxy(31, 28);
				printf("%d  ", Life);
				break;
			case 5:
				CheckPoint = 5;
				if (LastCheckPoint != CheckPoint)
				{
					CP5Score = Score;
					gotoxy(39, 30);
					printf("%d", Score);
					LastCheckPoint = CheckPoint;
				}
				break;
			case 6:
				CheckPoint = 6;
				if (LastCheckPoint != CheckPoint)
				{
					CP6Score = Score;
					gotoxy(39, 32);
					printf("%d", Score);
					LastCheckPoint = CheckPoint;
				}
				break;
			case 7:
				CheckPoint = 7;
				if (LastCheckPoint != CheckPoint)
				{
					CP7Score = Score;
					gotoxy(39, 34);
					printf("%d", Score);
					LastCheckPoint = CheckPoint;
				}
				break;
			case 8:
				CheckPoint = 8;
				if (LastCheckPoint != CheckPoint)
				{
					CP8Score = Score;
					gotoxy(39, 36);
					printf("%d", Score);
					LastCheckPoint = CheckPoint;
				}
				break;
			case 9:
				CheckPoint = 9;
				if (LastCheckPoint != CheckPoint)
				{
					CP9Score = Score;
					gotoxy(39, 38);
					printf("%d", Score);
					LastCheckPoint = CheckPoint;
				}
				break;
			default:
				break;
			}
			MapData[PlayerArr1][PlayerArr2] = 2;
		}

		PlusY = 3;

		if (Loop1 + Remainder > CntTotalData / 15)
			Remainder--;
		textcolor(BLACK,WHITE);

		endTime = clock();
		PlayTime = endTime - startTime;

		// ���� ���
		for (Loop2 = 0; Loop2 != 15; Loop2++)
		{
			gotoxy(24, PlusY);
			for (Loop3 = Loop1; Loop3 != Loop1 + Remainder; Loop3++)
			{
				switch (MapData[Loop2][Loop3])
				{
				case 0:                                       //��
					textcolor(WHITE,WHITE);
					printf("  ");
					break;
				case 1:                                       //��
					textcolor(WHITE,RED2);
					printf("  ");
					break;
				case 2:                                       //�÷��̾�
					textcolor(WHITE,BLUE2);
					printf("  ");
					break;
				case 3:                                       //������
					textcolor(WHITE,CYAN2);
					printf("  ");
					break;
				case 4:                                       //���������
					textcolor(WHITE,GREEN2);
					printf("  ");
					break;
				case 5:                                       //üũ����Ʈ1
					textcolor(WHITE,9);
					printf("  ");
					break;
				case 6:                                       //üũ����Ʈ2
					textcolor(WHITE,10);
					printf("  ");
					break;
				case 7:                                       //üũ����Ʈ3
					textcolor(WHITE,13);
					printf("  ");
					break;
				case 8:                                       //üũ����Ʈ4
					textcolor(WHITE,12);
					printf("  ");
					break;
				case 9:                                       //üũ����Ʈ5
					textcolor(WHITE,14);
					printf("  ");
					break;
				}
			}
			PlusY++;
		}
		Sleep(100);
		Score += 3;
		Loop1++;
		textcolor(BLACK,WHITE);
	}

	Sleep(300);

	if (GameEnd == 1)
	{
		sndPlaySoundA("music\\gameover.wav", SND_ASYNC | SND_NODEFAULT);
		upClearScreen();
		gotoxy(42, 10);
		printf("Game Over");
	}
	else if (GameEnd == 0)
	{
		upClearScreen();
		gotoxy(37, 10);
		printf("All Stage Clear!");
	}

	Sleep(1000);

	hardTrainingResult(Score, CP5Score, CP6Score, CP7Score, CP8Score, CP9Score, Life);	// �ϵ� ��� ���â���� �Ѿ

	return 0;
}

int hardTrainingResult(int ResultScore, int ResultCP5, int ResultCP6, int ResultCP7, int ResultCP8, int ResultCP9, int ResultLife)
{
	int Loop = 0, Loop1 = 0, Loop2 = 0;
	int ResultRank = 1;
	int ResultTotalScore = 0;
	int Pass = 0;
	int LastSel = 0;
	int SelNext = 0;
	int exp = 0;
	int credit = 0;
	char NickName[20] = { 0, };

	clearScreen();

	gotoxy(41, 27);
	printf("�� �� �� ��");
	gotoxy(35, 30);
	Sleep(300);
	printf("���� : %d", ResultScore);
	Sleep(300);
	gotoxy(30, 32);
	printf("���� ��� : %d", ResultLife);
	Sleep(300);
	if (ResultCP9 != 0)
	{
		credit = rand()%250+150;
		exp = rand()%600+300;
		
		if(user.monster.LV > 0)
		{
			user.monster.current_evolution[user.monster.LV] += exp;
			user.credit += credit;
		}

		gotoxy(27, 34);
		printf("üũ����Ʈ 1 : %d", ResultCP5);
		Sleep(300);
		gotoxy(27, 35);
		printf("üũ����Ʈ 2 : %d", ResultCP6);
		Sleep(300);
		gotoxy(27, 36);
		printf("üũ����Ʈ 3 : %d", ResultCP7);
		Sleep(300);
		gotoxy(27, 37);
		printf("üũ����Ʈ 4 : %d", ResultCP8);
		Sleep(300);
		gotoxy(27, 38);
		printf("üũ����Ʈ 5 : %d", ResultCP9);
		gotoxy(27, 39);
		printf("ȹ���� ����ġ : %d", exp);
		gotoxy(47, 39);
		printf("ȹ���� ũ���� : %d", credit);
		
	}
	else if (ResultCP8 != 0)
	{
		exp = rand()%400+200;
		credit = rand()%80+100;

		if(user.monster.LV > 0)
		{
			user.monster.current_evolution[user.monster.LV] += exp;
			user.credit += credit;
		}

		gotoxy(27, 34);
		printf("üũ����Ʈ 1 : %d", ResultCP5);
		Sleep(300);
		gotoxy(27, 35);
		printf("üũ����Ʈ 2 : %d", ResultCP6);
		Sleep(300);
		gotoxy(27, 36);
		printf("üũ����Ʈ 3 : %d", ResultCP7);
		Sleep(300);
		gotoxy(27, 37);
		printf("üũ����Ʈ 4 : %d", ResultCP8);
		Sleep(300);
		gotoxy(27, 38);
		printf("üũ����Ʈ 5 : X");
		gotoxy(27, 39);
		printf("ȹ���� ����ġ : %d", exp);
		gotoxy(47, 39);
		printf("ȹ���� ũ���� : %d", credit);
		
	}
	else if (ResultCP7 != 0)
	{

		exp = rand()%200+100;
		credit = rand()%40+60;

		if(user.monster.LV > 0)
		{
			user.monster.current_evolution[user.monster.LV] += exp;
			user.credit += credit;
		}

		gotoxy(27, 34);
		printf("üũ����Ʈ 1 : %d", ResultCP5);
		Sleep(300);
		gotoxy(27, 35);
		printf("üũ����Ʈ 2 : %d", ResultCP6);
		Sleep(300);
		gotoxy(27, 36);
		printf("üũ����Ʈ 3 : %d", ResultCP7);
		Sleep(300);
		gotoxy(27, 37);
		printf("üũ����Ʈ 4 : X");
		Sleep(300);
		gotoxy(27, 38);
		printf("üũ����Ʈ 5 : X");
		gotoxy(27, 39);
		printf("ȹ���� ����ġ : %d", exp);
		gotoxy(47, 39);
		printf("ȹ���� ũ���� : %d", credit);

	}
	else if (ResultCP6 != 0)
	{
		exp = rand()%100+60;
		credit = rand()%20+30;

		if(user.monster.LV > 0)
		{
			user.monster.current_evolution[user.monster.LV] += exp;
			user.credit += credit;
		}
		gotoxy(27, 34);
		printf("üũ����Ʈ 1 : %d", ResultCP5);
		Sleep(300);
		gotoxy(27, 35);
		printf("üũ����Ʈ 2 : %d", ResultCP6);
		Sleep(300);
		gotoxy(27, 36);
		printf("üũ����Ʈ 3 : X");
		Sleep(300);
		gotoxy(27, 37);
		printf("üũ����Ʈ 4 : X");
		Sleep(300);
		gotoxy(27, 38);
		printf("üũ����Ʈ 5 : X");
		gotoxy(27, 39);
		printf("ȹ���� ����ġ : %d", exp);
		gotoxy(47, 39);
		printf("ȹ���� ũ���� : %d", credit);
	}
	else if (ResultCP5 != 0)
	{

		exp = rand()%50+10;
		credit = rand()%10+10;

		if(user.monster.LV > 0)
		{
			user.monster.current_evolution[user.monster.LV] += exp;
			user.credit += credit;
		}

		gotoxy(27, 34);
		printf("üũ����Ʈ 1 : %d", ResultCP5);
		Sleep(300);
		gotoxy(27, 35);
		printf("üũ����Ʈ 2 : X");
		Sleep(300);
		gotoxy(27, 36);
		printf("üũ����Ʈ 3 : X");
		Sleep(300);
		gotoxy(27, 37);
		printf("üũ����Ʈ 4 : X");
		Sleep(300);
		gotoxy(27, 38);
		printf("üũ����Ʈ 5 : X");
		gotoxy(27, 39);
		printf("ȹ���� ����ġ : %d", exp);
		gotoxy(47, 39);
		printf("ȹ���� ũ���� : %d", credit);
	}
	PlaySound(NULL, 0, 0);
	Sleep(1500);
	
	clearScreen();
	while(kbhit())getch();
	return 0;
}