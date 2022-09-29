#ifndef __SNAKE_H
#define __SNAKE_H

#include "stm32f10x.h"

#define Max_Len 100
#define left 1;//�궨���ߵ�ǰ������
#define right 2;
#define up 3;
#define down 4;


typedef struct
{
	u8 x[Max_Len];//�ߵ�x����
	u8 y[Max_Len];//�ߵ�y����
	u8 len;//�ߵ����峤��
	u8 flag;//�ߵĴ���־
	u8 score;//��Ϸ�÷����
}Snake;

void Sanke_Init(void);//��Ϸ��ʼ��
void Snake_Body_Unit(u16 x,u16 y);//�����һ�����ȵ�λ
void Game_Back(void);//��Ϸ������ɫ
void Snake_Off_Unit(u16 x,u16 y);//��������һ�����ȵ�λ
void Snake_Move(u8 dir);//�ߵ��˶�����
void Game_Init(void);//��Ϸ�ĳ�ʼ������
void Snake_Food(void);//̰���߳Թ�ʵ����
void Snake_Dead(void);//��Ϸ��������
	
#endif

