#include "stm32f10x.h"   // Device header
#include "exti.h"
#include "snake.h"
#include "timer.h"
#include "lcd.h"



void Snake_Body()
{
	float i;
//	LCD_Init();
	for(i=100;i<=109;)
	{
		LCD_Draw_Circle(i,100,3);
		
		
		i=i+6;
		if(i==109)
		{
			i=100;
		}
	}
}



void Sanke_Init()//Ì°³ÔÉß³õÊ¼»¯
{
	
		
}

