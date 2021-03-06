/*
  monster.h 참조할 것 
*/

#include "monster.h"
#include "screen.h"
#include "tools.h"
#include "player.h"

extern Player user;

void showMonster(char blockInfo[][15])
{
	int y, x;

	COORD curPos = getxy();

	for(y = 0; y < 15; y++)
	{
		for(x = 0; x < 15; x++)
		{
			gotoxy(curPos.X + (x * 2), curPos.Y + y);

			if(blockInfo[y][x] == 1)
				printf("■");
		}
	}
}

void showModel(char blockInfo[][8])
{
	int y, x;

	COORD curPos = getxy();

	for(y = 0; y < 8; y++)
	{
		for(x = 0; x < 8; x++)
		{
			gotoxy(curPos.X + (x * 2), curPos.Y + y);

			if(blockInfo[y][x] == 1)
				printf("■");
		}
	}
}
char monsterModel[][15][15] =
{
	//디지몬 알
	{
		{0,0,0,0,0,0,1,1,1,0,0,0,0,0,0},
		{0,0,0,0,0,1,0,0,0,1,0,0,0,0,0},
		{0,0,0,0,1,1,0,0,0,1,1,0,0,0,0},
		{0,0,0,1,1,0,0,0,0,0,1,1,0,0,0},
		{0,0,1,0,0,0,0,0,1,1,0,0,1,0,0},
		{0,1,1,0,0,0,0,0,1,1,0,0,1,1,0},
		{0,1,1,0,0,0,0,0,0,0,0,0,1,1,0},
		{0,1,1,0,0,0,1,1,1,0,0,0,1,1,0},
		{0,1,0,0,0,0,1,1,1,0,0,0,0,1,0},
		{0,1,0,0,0,0,1,1,1,0,0,0,0,1,0},
		{0,0,1,0,0,0,0,0,0,0,0,0,1,0,0},
		{0,0,0,1,0,0,0,0,0,0,0,1,0,0,0},
		{0,0,0,0,1,1,0,0,0,1,1,0,0,0,0},
		{0,0,0,0,0,1,1,1,1,1,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}
	},
		//아구몬
	{
		{0,0,0,0,0,1,1,1,1,1,1,0,0,0,0},
		{0,0,0,0,1,0,0,0,0,0,0,1,0,0,0},
		{0,1,1,1,0,0,0,0,1,1,0,0,1,0,0},
		{1,0,0,0,0,0,0,0,0,1,1,0,1,0,0},
		{1,0,0,0,0,0,0,0,1,1,1,0,1,0,0},
		{1,0,0,0,0,1,1,0,0,0,0,0,1,0,0},
		{0,1,1,1,1,0,0,0,0,0,0,0,1,0,0},
		{0,1,0,0,0,0,0,1,1,0,0,1,0,0,0},
		{0,0,1,1,1,1,1,0,1,1,0,1,0,0,0},
		{0,1,0,0,1,0,0,1,0,0,0,0,1,0,0},
		{0,1,1,1,1,0,0,1,1,1,1,0,1,0,0},
		{0,0,0,0,1,1,0,0,0,0,1,0,0,1,0},
		{0,0,1,1,0,0,1,1,1,1,0,0,0,1,0},
		{0,1,0,1,0,0,1,0,1,0,1,0,1,0,1},
		{0,1,1,1,1,1,1,0,1,1,1,1,1,1,1}
	},
		//워그레이몬
	{
		{0,0,0,0,1,1,1,1,1,0,0,1,1,1,0},
		{1,1,0,1,1,1,1,1,1,1,1,1,1,1,0},
		{1,1,1,1,1,1,0,0,1,1,1,1,1,0,0},
		{1,1,1,1,1,0,0,1,1,1,1,1,0,0,0},
		{1,1,1,0,1,1,1,1,1,0,1,0,0,0,0},
		{0,1,0,0,1,1,1,0,0,0,1,0,0,0,0},
		{0,0,1,1,0,0,0,0,0,0,0,1,0,0,0},
		{0,0,0,1,1,1,0,0,0,1,0,1,0,0,0},
		{0,0,1,1,0,0,0,1,1,0,0,0,1,0,0},
		{0,1,0,1,0,0,1,0,0,0,0,0,1,1,1},
		{0,1,0,1,0,0,1,0,0,0,1,0,1,0,1},
		{0,0,1,1,0,0,0,1,1,1,0,0,1,0,1},
		{0,1,1,1,0,0,0,0,0,1,0,0,0,1,0},
		{1,0,1,0,1,1,1,1,1,0,1,0,1,0,1},
		{1,1,1,1,1,1,0,0,0,0,1,1,1,1,1}
	},
	//최종진화
	{
		{0,0,1,1,0,0,0,0,0,0,0,0,1,1,0},
		{0,0,1,0,1,0,1,1,1,1,1,1,0,1,0},
		{0,0,0,1,1,1,1,1,1,1,0,0,0,1,0},
		{0,0,1,1,1,1,1,0,0,1,1,1,1,0,0},
		{0,1,1,1,1,1,0,0,1,1,1,1,0,0,0},
		{1,0,1,1,1,1,1,1,1,1,1,1,1,1,1},
		{0,1,0,1,1,1,1,1,1,0,0,1,0,0,1},
		{1,0,1,1,0,0,0,0,0,0,1,0,0,1,0},
		{1,0,0,1,1,1,1,1,1,1,0,1,1,0,1},
		{1,0,1,1,1,0,0,1,0,0,0,1,0,0,1},
		{0,1,1,0,1,1,1,0,1,1,0,1,1,1,0},
		{1,0,0,1,0,1,0,0,0,1,1,0,1,1,1},
		{1,1,1,1,1,0,1,1,1,0,0,1,0,0,1},
		{0,0,1,0,1,0,1,0,1,1,1,0,1,1,0},
		{0,0,1,1,1,1,1,1,1,1,1,1,1,1,0}
	},
	//죽었을 떄
	{
		{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,1,1,1,1,1,0,0,0,0,1},
		{1,0,0,0,1,1,1,1,1,1,1,0,0,0,1},
		{1,0,0,1,1,1,1,1,1,1,1,1,0,0,1},
		{1,0,0,1,0,0,1,1,1,0,0,1,0,0,1},
		{1,0,0,1,0,1,1,1,1,1,0,1,0,0,1},
		{1,0,0,1,1,1,1,0,1,1,1,1,0,0,1},
		{1,0,0,1,1,1,0,0,0,1,1,1,0,0,1},
		{1,0,0,0,1,1,1,1,1,1,1,0,0,0,1},
		{1,0,0,0,1,0,1,0,1,0,1,0,0,0,1},
		{1,0,0,0,1,0,1,0,1,0,1,0,0,0,1},
		{1,0,0,0,0,1,1,1,1,1,0,0,0,0,1},
	    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
	}
};

char monsterModel2[][15][15] =
{
	//디지몬 알
	{
		{0,0,0,0,0,0,1,1,1,0,0,0,0,0,0},
		{0,0,0,0,0,1,0,0,0,1,0,0,0,0,0},
		{0,0,0,0,1,1,0,0,0,1,1,0,0,0,0},
		{0,0,0,1,1,0,0,0,0,0,1,1,0,0,0},
		{0,0,1,0,0,0,0,0,1,1,0,0,1,0,0},
		{0,1,1,0,0,0,0,0,1,1,0,0,1,1,0},
		{0,1,1,0,0,0,0,0,0,0,0,0,1,1,0},
		{0,1,1,0,0,0,1,1,1,0,0,0,1,1,0},
		{0,1,0,0,0,0,1,1,1,0,0,0,0,1,0},
		{0,1,0,0,0,0,1,1,1,0,0,0,0,1,0},
		{0,0,1,0,0,0,0,0,0,0,0,0,1,0,0},
		{0,0,0,1,0,0,0,0,0,0,0,1,0,0,0},
		{0,0,0,0,1,1,0,0,0,1,1,0,0,0,0},
		{0,0,0,0,0,1,1,1,1,1,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}
	},

	//아구몬2
	{
		{0,0,0,0,0,1,1,1,1,1,1,0,0,0,0},
		{0,1,1,1,1,0,0,0,0,0,0,1,0,0,0},
		{1,0,0,0,0,0,0,0,1,1,0,0,1,0,0},
		{1,1,1,1,1,1,0,0,0,1,1,0,1,0,0},
		{0,0,1,1,1,1,1,0,1,1,1,0,1,0,0},
		{0,0,0,1,1,1,1,0,0,0,0,0,1,0,0},
		{0,1,1,1,1,1,0,0,0,0,0,0,1,0,0},
		{0,1,0,0,0,0,0,1,1,0,0,1,0,0,0},
		{0,1,1,1,1,1,1,0,0,1,0,1,0,0,0},
		{0,0,1,0,1,0,0,0,1,0,0,0,1,0,0},
		{0,0,1,1,1,0,0,0,1,1,1,0,1,0,0},
		{0,0,0,0,1,1,0,0,0,0,1,0,0,1,0},
		{0,0,1,1,0,0,1,1,1,1,0,0,0,1,0},
		{0,1,0,1,0,0,1,0,1,0,1,0,1,0,1},
		{0,1,1,1,1,1,1,0,1,1,1,1,1,1,1}
	},
		//워그레이몬2
	{
		{1,1,0,0,0,1,1,1,1,1,0,0,1,1,1},
		{1,1,1,0,1,1,1,1,1,1,1,1,1,1,1},
		{1,1,1,1,1,1,0,0,1,1,1,1,1,1,0},
		{0,1,1,1,1,1,1,1,0,1,1,1,1,0,0},
		{0,0,0,0,0,0,1,1,1,1,0,1,0,0,0},
		{0,0,0,0,0,0,1,1,1,0,0,1,0,0,0},
		{0,1,1,1,1,1,0,0,0,0,0,1,0,0,0},
		{0,1,0,0,0,0,1,0,0,0,1,0,1,0,0},
		{0,0,1,1,1,1,0,0,1,1,0,0,1,0,0},
		{0,1,0,1,0,0,0,1,0,0,0,0,1,1,1},
		{0,1,0,1,0,0,0,1,0,0,1,0,1,0,1},
		{0,0,1,1,0,0,0,0,1,1,0,0,1,0,1},
		{0,1,1,0,1,0,0,0,0,0,1,0,0,1,0},
		{1,0,1,0,0,1,1,1,1,0,1,0,1,0,1},
		{1,1,1,1,1,1,1,0,0,1,1,1,1,1,1}
	},
	//최종진화 2
	{
		{0,0,1,1,0,0,0,0,0,0,0,1,1,0,0},
		{0,0,1,0,1,0,1,1,1,1,1,0,1,0,0},
		{0,0,1,0,1,1,1,1,1,1,0,0,1,0,0},
		{0,0,1,1,1,1,1,1,1,1,1,1,0,0,0},
		{1,1,1,1,1,1,1,0,0,1,1,1,1,1,1},
		{1,0,1,1,1,1,0,0,1,1,1,1,0,0,1},
		{1,0,0,1,1,1,1,1,1,1,1,1,1,0,1},
		{1,0,1,1,0,0,0,0,0,1,0,1,0,0,1},
		{1,1,0,1,1,0,0,0,1,1,0,1,1,1,0},
		{0,0,1,1,0,1,1,1,1,1,1,1,0,0,0},
		{0,0,0,0,1,0,0,0,0,0,1,0,0,0,0},
		{0,0,0,1,1,1,1,1,1,1,0,1,0,0,0},
		{0,0,0,1,0,1,0,1,0,1,1,1,1,0,0},
		{0,0,1,0,1,1,0,1,1,1,0,1,0,1,0},
		{0,0,1,1,1,1,1,1,0,1,1,1,1,1,0}
	}
};

char foodModel[][8][8] =
{
	//고기
	{
		{0,0,0,0,0,0,1,1},
		{0,0,0,1,1,1,0,1},
		{0,0,1,0,1,1,1,0},
		{0,1,0,1,1,1,1,0},
		{0,1,1,1,1,1,1,0},
		{0,1,0,1,1,1,0,0},
		{1,0,1,1,1,0,0,0},
		{1,1,0,0,0,0,0,0}
	},
		//고기먹는거
	{
		{0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0},
		{0,1,0,0,0,0,0,0},
		{0,1,1,1,0,0,0,0},
		{0,1,0,1,1,0,0,0},
		{1,0,1,1,1,0,0,0},
		{1,1,0,0,0,0,0,0}
	},

		//알약
	{
		{0,0,0,0,1,1,1,0},
		{0,0,0,1,0,0,1,1},
		{0,0,1,0,1,1,1,1},
		{0,1,0,1,1,1,1,1},
		{1,0,0,0,1,1,1,0},
		{1,0,0,0,0,1,0,0},
		{1,0,0,0,1,0,0,0},
		{0,1,1,1,0,0,0,0}
	},
		//알약 먹는거
	{
		{0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0},
		{0,0,1,0,0,0,0,0},
		{0,1,0,1,0,0,0,0},
		{1,0,0,0,0,1,0,0},
		{1,0,0,0,0,1,0,0},
		{1,0,0,0,1,0,0,0},
		{0,1,1,1,0,0,0,0}
	},
	//다먹은거
	{
		{0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0}
	}
};

char itemModel[][8][8] = 
{
//문장 상점용
	{
		{1,0,1,1,1,1,0,1},
		{0,1,0,0,0,0,1,0},
		{1,0,0,1,1,0,0,1},
		{0,0,1,0,1,1,0,0},
		{0,0,1,1,0,1,0,0},
		{1,0,0,1,1,0,0,1},
		{0,1,0,0,0,0,1,0},
		{1,0,1,1,1,1,0,1}
	},
    
	//문장 상점용
	{
	    {1,0,0,1,1,0,0,1},
		{0,0,0,1,1,0,0,0},
		{0,1,1,1,1,1,1,0},
		{0,1,1,1,1,1,1,0},
		{0,0,0,1,1,0,0,0},
		{0,0,1,1,1,1,0,0},
		{0,1,0,1,1,0,1,0},
		{1,0,0,1,1,0,0,1}
	},

	//솔드아웃
	{
	    {0,1,0,0,0,0,0,},
		{1,0,1,0,0,0,0,0},
		{0,1,0,0,0,0,0,0},
		{0,0,1,0,1,0,0,0},
		{0,0,1,0,1,0,0,0},
		{0,0,0,1,0,1,1,1},
		{0,0,0,0,0,0,1,0},
		{0,0,0,0,0,0,1,0}
	}
};

void monsterInit()
{
	int i;
	int answer;
	gotoxy(32,7);
	printf("몬스터를 생성하시겠습니까?");
	gotoxy(32,8);
	printf("예 : 1, 아니요 : 0");
	gotoxy(35,9);
	scanf("%d",&answer);

	if(answer == 1)
	{
		gotoxy(32,30);
		printf("디지몬의 이름을 입력해주세요");
		gotoxy(32,31);
		scanf("%s",user.monster.name);

		user.monster.hungry = 100;
		user.monster.LV = 0;
		user.monster.power = 0;
		user.monster.stamina = 100;
		user.monster.weight = 0;
		
		for(i = 0; i < 4; i++)
		{
			user.monster.evolution_gage[i] = i*1000;
			user.monster.current_evolution[i] = 0;
		}

		user.isMonster = 1;
	}
	else
		exit(0);
}