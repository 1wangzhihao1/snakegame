#include "stm32f10x.h"   // Device header
#include "exti.h"
#include "snake.h"
#include "timer.h"
#include "lcd.h"

float len;
float score;
float flag;


void Snake_Move()
{
	
}


void Snake_Body()//ÉßÌå
{
	float x,y;
//	LCD_Init();
	for(x=100;x<=118;)
	{
		LCD_Draw_Circle(x,100,3);
		x=x+6;
		if(x==124)
		{
			x=100;
		}
	}
}

void Game_Back()
{
	LCD_Fill(0,0,240,30,BLUE);
	LCD_Fill(0,290,240,320,BLUE);
}


void Sanke_Init()//Ì°³ÔÉß³õÊ¼»¯
{
	Game_Back();
	Snake_Body();
}

