#ifndef __SNAKE_H
#define __SNAKE_H

#include "stm32f10x.h"

#define Max_Len 100
#define left 1;//宏定义蛇的前进方向
#define right 2;
#define up 3;
#define down 4;


typedef struct
{
	u8 x[Max_Len];//蛇的x坐标
	u8 y[Max_Len];//蛇的y坐标
	u8 len;//蛇的身体长度
	u8 flag;//蛇的存活标志
	u8 score;//游戏得分情况
}Snake;

void Sanke_Init(void);//游戏初始化
void Snake_Body_Unit(u16 x,u16 y);//蛇体的一个长度单位
void Game_Back(void);//游戏背景颜色
void Snake_Off_Unit(u16 x,u16 y);//清除蛇体的一个长度单位
void Snake_Move(u8 dir);//蛇的运动函数
void Game_Init(void);//游戏的初始化界面
void Snake_Food(void);//贪吃蛇吃果实函数
void Snake_Dead(void);//游戏结束界面
	
#endif

