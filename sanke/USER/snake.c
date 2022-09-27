#include "stm32f10x.h"   // Device header
#include "exti.h"
#include "snake.h"
#include "timer.h"
#include "lcd.h"
#include "timer.h"
#include "snake.h"


//float len;//蛇的身体长度
//float score;//游戏得分情况
//float flag;//蛇的存活标志
//float sanke_x;//蛇的x坐标
//float sanke_y;//蛇的y坐标

Snake snake;

void Snake_Move(u8 dir)//蛇的移动函数
{
	u8 i;
	Snake_Off_Unit(snake.x[0],snake.y[0]);//清除第一个位置为空白位置
	if(dir==1)//判断如果命令为左转
	{
		for(i=0;i<snake.len-1;i++)
		{
			snake.x[i]=snake.x[i+1];
			snake.y[i]=snake.y[i+1];
		}
		snake.x[snake.len-1]=snake.y[snake.len-2];
	}
}


void Snake_Body_Unit(u16 x,u16 y)//蛇体的一个长度单位
{
//	snake.x=150,snake.y=100;
//	for(snake.x=100;snake.x<100+6*snake.len;)
//	{
		LCD_Fill(x,y,x+5,y+5,RED);
//		snake.x=snake.x+6;
//	}
}

void Snake_Off_Unit(u16 x,u16 y)//清除蛇体的一个长度单位
{
	LCD_Fill(x,y,x+5,y+5,WHITE);
}

void Game_Back()
{
	LCD_Fill(0,0,240,30,BLUE);
	LCD_Fill(0,290,240,320,BLUE);
}


void Sanke_Init()//贪吃蛇初始化
{
	u8 i;
	snake.flag=1;//初始化标志位
	snake.len=4;//默认时蛇的长度为四个单位
	snake.score=0;//默认游戏的初始分数为0
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

