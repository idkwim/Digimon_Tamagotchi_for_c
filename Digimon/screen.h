/*
    2017-05-20
	UI������ �پ��� ���� �̿��� ��ũ���� ���õ� �Լ����� ��Ƴ��� ����̴�.
*/


#ifndef __SCREEN_H__
#define __SCREEN_H__

int mainScreen();		 //���� ȭ����(���ٵ�) ��� �Լ�
int gameOn();	    	 //ȭ���� ������ ȿ���� ����� �Լ�
int shutDown();		     //ȭ���� ������ ȿ���� ����� �Լ�
int loginSelect();		 //���̵���, �α��� ����ȭ�� 
int introScreen();		 //��Ʈ�� ȭ��
int playScreen();		 //�÷��� ȭ�� �α����� �Ǿ��ְ� ���Ͱ��־�� �޴����� ����
int signinScreen();		 //���̵� ��� ��ũ��
int loginScreen();		 //�α���ȭ�� ��ũ��
int playScreen();		 //����ȭ��
int selectMenu();		 //�޴� ����
int saveScreen();		 //���� ȭ��
int traningMenuScreen(); //�Ʒ� ȭ��
int storeScreen();       //���� ȭ��
int foodSelectScreen();  //���� ����ȭ��
int eatBeef();           //���Դ¿���
int eatPeel();           //��Դ¿���
int evolution1();        //��ȭ�����
int evolution2();
int evolution3();
int hintScreen();
int monsterMove();       //���Ͱ� ���������� �����̴� ���� �������ʿ� ������ ����


void clearScreen();      // ���� ȭ�� Ŭ����
void upClearScreen();    // ���� ȭ�� �� Ŭ����
void downClearScreen();  // �Ʒ� ���� ȭ�� Ŭ����

#endif