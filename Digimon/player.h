/*
    2017-05-20
	�÷��̾ ���� ����ü�� ���� �Լ� ���
*/

#ifndef __PLAYER_H__
#define __PLAYER_H__

#include "monster.h"
#include <stdlib.h>

typedef struct player
{
	char ID[20];
	char password[20];
	int credit;        //�������� ������ �� �� ����
	int isMonster;     //���Ͱ� �ִ��� ������ falg
	int isItem[2];     //��ȭ�� �ʿ��� ������ �ִ��� ������
	monster monster;   //�÷��̾��ϳ��� ���� �Ѹ���
}Player;

void init();

#endif