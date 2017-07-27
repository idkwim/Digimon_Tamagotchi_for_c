/*
	login.h ���� 
*/

#include "login.h"
#include "player.h"
#include "tools.h"
#include "screen.h"

#include <stdio.h>
#include <string.h>


#define  MAXSIZE 30
extern Player user;

void makeID()    //���̵� ������Լ�
{
	char fileName[MAXSIZE] = " ";
	char ID[MAXSIZE];
	char reID[MAXSIZE]; 
	char temp[MAXSIZE];
	int  Loop = 0;

	FILE * fp;
	clearReadBuffer(); 
	gotoxy(35,6);
	printf("���ο� ���̵� �Է�");

	gotoxy(35,7);
	fflush(stdin);
	gets(ID);


	//���̵� ������ �ʱ⼼�̺����ϻ���
	strcpy(temp,ID);
	strcpy(fileName, strcat(temp,".txt"));

	gotoxy(29,28);
	//������ �о NULL���� �ƴϸ�, 
	if((fp = fopen(fileName, "r")) != NULL)
	{
		gotoxy(35,28);
		printf("�̹� ��ϵ� ���̵��Դϴ�");
		gotoxy(34,29);
		printf("�ٸ� ���̵�� ������ּ���");
		exit(0);
	}

	//���� �о NULL�̸� ���ϵ��
	else
	{
		fp = fopen(fileName, "w+b");

		if (fp == NULL)
		{
			printf("������ �����ϴ�. �ٽø�����ּ���\n");
			exit(0);
		}
		else
		{
			//��й�ȣ���� ����ϸ� �ߵ��� ����
			printf("�ߺ��� ���̵� �����ϴ�.");
		}
	}

	Sleep(2000);

	for (Loop = 22; Loop < 35; Loop++)
	{
		gotoxy(23, 4 + Loop);
		printf("                                              ");
	}

	fclose(fp);
	strcpy(user.ID, ID);
}

int restriction(char * text)
{
	int i;

	//flag[0] = �����Ǻ� flag[1] = �����Ǻ�
	int flag[2] = {0};

	if(strlen(text)-1 >= 8 && strlen(text)-1 <= 13)
	{
		for(i = 0; i < strlen(text)-1; i++)
		{
			if(isdigit(text[i]))
				flag[0] = 1;
			if(isalpha(text[i]))
				flag[1] = 1;
		}

		if(flag[0] == 1 && flag[1] == 1)
			return 1;
		else
			return 0;
	}
	else
		return 0;
}

void makePW()    //��й�ȣ ����� �Լ�
{
	char password[MAXSIZE];
	char repassword[MAXSIZE]; 
	char fileName[MAXSIZE] = " ";
	char temp[MAXSIZE];

	int  Loop = 0;

	FILE * fp;

	strcpy(temp,user.ID);
	strcpy(fileName, strcat(temp,".txt"));

	fp = fopen(fileName, "w+b");

	gotoxy(35, 9);
	printf("��й�ȣ�� ����մϴ�.\n");
	while(1)
	{
		gotoxy(31, 29);
		printf("�ݺ�й�ȣ�� ����, ���� ����");
		gotoxy(28, 30);
		printf("�ּ��� 8�ڸ� �ִ� 12�ڸ��̾�� �մϴ�.\n");

		gotoxy(35, 11);
		fflush(stdin);
		printf("���ο� ��й�ȣ �Է�");
		gotoxy(35, 12);
		printf("                     ");

		fflush(stdin); 
		gotoxy(35,12);
		gets(password);

		if(restriction(password))
		{
			gotoxy(35,11);
			printf("��й�ȣ �ѹ��� �Է�");
			gotoxy(35,12);
			printf("            ");
			fflush(stdin);
			gotoxy(35,12);
			gets(repassword);
			clearScreen();

			if(!strcmp(password,repassword))
			{
				for (Loop = 22; Loop < 35; Loop++)
				{
					gotoxy(23, 4 + Loop);
					printf("                                              ");
				}
				gotoxy(34,32);
				printf("��й�ȣ�� ��ϵǾ����ϴ�.\n");
				strcpy(user.password, password);
				user.isMonster = 0;
				user.credit = 0;
				user.isItem[0] = 0;
				user.isItem[1] = 0;
				user.isItem[2] = 0;
				fwrite(&user, sizeof(user), 1,fp); 
				fclose(fp);
				return;
			}
			else
			{
				for (Loop = 22; Loop < 35; Loop++)
				{
					gotoxy(23, 4 + Loop);
					printf("                                              ");
				}
				gotoxy(34,32);
				printf("��й�ȣ�� ��Ȯ�� �Է��ϼ���.\n");
				Sleep(1000);
				continue;
			}		
		}
	}
}

void islogin()
{
	FILE * fp;

	char fileName[MAXSIZE] = " ";
	char temp[MAXSIZE];
	char id[MAXSIZE];
	char password[MAXSIZE];

	int count = 1;

	gotoxy(35,6);
	printf("���̵� �Է�");
	gotoxy(35,7);
	scanf("%s", id);

	strcpy(fileName,strcat(id,".txt"));

	fp = fopen(fileName,"r+b");

	if(fp == NULL)
	{
		gotoxy(35,6);
		printf("���̵� �����ϴ�");
		gotoxy(35,7);
		printf("���̵� ������ּ���");
		Sleep(1000);
		signinScreen();
	}

	fread(&user, sizeof(user), 1, fp);

	fclose(fp);

	gotoxy(35,8);
	printf("��й�ȣ : ");
	gotoxy(35,9);
	scanf("%s",&password);


		while(strcmp(password,user.password) != 0)
		{
			gotoxy(35,32);
			printf("��й�ȣ�� %d�� Ʋ�Ƚ��ϴ�. ",count);
			gotoxy(35,33);
			printf("�ٽ��Է����ּ���");
			Sleep(1000);
			clearScreen();
			
			gotoxy(35,8);
			printf("��й�ȣ : ");
			gotoxy(35,9);
			scanf("%s",&password);

			count++;

			if(count > 5)
			{
				gotoxy(35,32);
				printf("��й�ȣ�� 5ȸ�̻� Ʋ�Ƚ��ϴ�.\n");
				gotoxy(35,33);
				printf("���α׷��� �����մϴ�.\n");
				downClearScreen();
				exit(0);
			}
		}

	gotoxy(35,32);
	printf("�α��ο� �����ϼ̽��ϴ�.");
	Sleep(1000);

}