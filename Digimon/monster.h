/*
    2017-05-20
	��������ü �� ������� ���õ� �Լ� ��� 
	������ �ִ� ��Ʈ���� y=13, x=50�����̴�.
*/

#ifndef __MONSTER_H__
#define __MONSTER_H__

typedef struct monster
{
	char name[20];     //�̸�
	
	int power;          //�ٸ� ����� ��Ʋ���
	int hungry;         //������� ����, ���� �پ��
	int stamina;        //���¹̳� �پ��� �Ʒø���, �����ɷ� ä��
	int weight;         //���� ��ü���̰ų� ��ü���̸� �г�Ƽ
	int LV;             //��ȭ �ܰ踦 �ǹ� ���������� �������
	int evolution_gage[4]; //���������� ä���� ��ȭ���� //�迭
	int current_evolution[4]; //���� ����ġ
}monster;

char monsterModel[][15][15];              //���͵��� ��Ʈ �����迭
char monsterModel2[][15][15];             //�Թ��� ���� ��Ʈ ����       
char foodModel[][8][8];					  //���� ��Ʈ���� �迭
char itemModel[][8][8];                   //���� ������ ��Ʈ
void showMonster(char blockInfo[][15]);   //���͸� ������ִ� �Լ�
void showModel(char blockInfo[][8]);       //������ ������ִ� �Լ�
void monsterInit();                       //���� �������ͽ� �ʱ�ȭ�Լ�


#endif