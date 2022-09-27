#include "stm32f10x.h"   // Device header
#include "exti.h"
#include "snake.h"
#include "timer.h"
#include "lcd.h"
#include "timer.h"
#include "snake.h"


//float len;//�ߵ����峤��
//float score;//��Ϸ�÷����
//float flag;//�ߵĴ���־
//float sanke_x;//�ߵ�x����
//float sanke_y;//�ߵ�y����

Snake snake;


//�ߵ��ƶ�����
void Snake_Move(u8 dir)
{
	u8 i;
	Snake_Off_Unit(snake.x[0],snake.y[0]);//�����һ��λ��Ϊ�հ�λ��
		
	if(dir==1)//�ж��������Ϊ����
	{
		for(i=0;i<snake.len-1;i++)
		{
			snake.x[i]=snake.x[i+1];
			snake.y[i]=snake.y[i+1];
		}
		snake.x[snake.len-1]=snake.x[snake.len-2]-5;
		snake.y[snake.len-1]=snake.y[snake.len-2];
	}
	
	if(dir==2)//�ж��������Ϊ����
	{
		for(i=0;i<snake.len-1;i++)
		{
			snake.x[i]=snake.x[i+1];
			snake.y[i]=snake.y[i+1];
		}
		snake.x[snake.len-1]=snake.x[snake.len-2]+5;
		snake.y[snake.len-1]=snake.y[snake.len-2];
	}
	
	if(dir==3)//�ж��������Ϊ����
	{
		for(i=0;i<snake.len-1;i++)
		{
			snake.x[i]=snake.x[i+1];
			snake.y[i]=snake.y[i+1];
		}
		snake.x[snake.len-1]=snake.x[snake.len-2];
		snake.y[snake.len-1]=snake.y[snake.len-2]+5;
	}
	
	if(dir==4)//�ж��������Ϊ����
	{
		for(i=0;i<snake.len-1;i++)
		{
			snake.x[i]=snake.x[i+1];
			snake.y[i]=snake.y[i+1];
		}
		snake.x[snake.len-1]=snake.x[snake.len-2];
		snake.y[snake.len-1]=snake.y[snake.len-2]-5;
	}
	
	for(i=0;i<snake.len;i++)//������ʾ��lcd��
	{
		Snake_Body_Unit(snake.x[i],snake.y[i]);
	}
}

//�����һ�����ȵ�λ
void Snake_Body_Unit(u16 x,u16 y)
{
//	snake.x=150,snake.y=100;
//	for(snake.x=100;snake.x<100+6*snake.len;)
//	{
		LCD_Fill(x,y,x+5,y+5,RED);
//		snake.x=snake.x+6;
//	}
}

//��������һ�����ȵ�λ
void Snake_Off_Unit(u16 x,u16 y)
{
	LCD_Fill(x,y,x+5,y+5,WHITE);
}

void Game_Back()
{
	LCD_Fill(0,0,240,30,BLUE);
	LCD_Fill(0,290,240,320,BLUE);
}

//̰���߳�ʼ��
void Sanke_Init()
{
	u8 i;
	snake.flag=1;//��ʼ����־λ
	snake.len=4;//Ĭ��ʱ�ߵĳ���Ϊ�ĸ���λ
	snake.score=0;//Ĭ����Ϸ�ĳ�ʼ����Ϊ0
	for(i=0;i<snake.len;i++)
	{
		snake.x[i]=100+i*5;
		snake.y[i]=100;
	}
	for(i=0;i<snake.len;i++)
	{
		Snake_Body_Unit(snake.x[i],snake.y[i]);
	}
}




