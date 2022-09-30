#include "stm32f10x.h"   // Device header
#include "exti.h"
#include "snake.h"
#include "timer.h"
#include "lcd.h"
#include "timer.h"
#include "stdlib.h"

//float len;//�ߵ����峤��
//float score;//��Ϸ�÷����
//float flag;//�ߵĴ���־
//float sanke_x;//�ߵ�x����
//float sanke_y;//�ߵ�y����

Snake snake;
Food food;
u8 flag;//��Ϸ��ʼ��־λ


//��Ϸ�Ŀ�ʼ����
void Game_Init()
{
		LCD_Fill(0,0,240,320,BLUE);
		LCD_ShowString(40,30,200,40,16,"Welcome to the Snake!");
		LCD_ShowString(65,150,150,30,16,"Gluttonous Snake");
		LCD_ShowString(110,300,40,40,12,"Start");
//		LCD_Fill(0,290,240,320,BLUE);
		while(1)
		{
			if(flag==1)
			{
				LCD_Clear(WHITE);
				break;
			}
		}
	
}

void Snake_Dead()//�ߵ���������,����Ϸ��������
{
	if((snake.x[snake.len-1]<=1)||(snake.x[snake.len-1]>=240)||(snake.y[snake.len-1]<=1)||(snake.y[snake.len-1]>=240))
	{
		snake.flag=0;
		LCD_Clear(WHITE);
		if(snake.flag==0)
		{
			LCD_Fill(0,0,240,320,BLACK);
			LCD_ShowString(50,100,150,40,16,"You are Dead!");
			LCD_ShowString(80,180,50,30,16,"Score");
	//	LCD_ShowChar(70,260,20,12,':');
			LCD_ShowNum(70,220,snake.score,20,16);
			while(1){}
		}
	}
}

void Snake_Food()//̰���߳Թ�ʵ����
{
	u8 i;
	if(snake.x[snake.len-1]==food.x && snake.y[snake.len-1]==food.y)//�ж��Ƿ��߳Ե���ʵ
	{
		snake.len++;
		snake.score+=2;
		snake.x[snake.len-1] = food.x;
		snake.y[snake.len-1] = food.y;
		food.flag = 1;//��ʵ���Ե�
	}
	
	if(food.flag==0)//��־λΪ��ʱ���ù�ʵ
	{
		Snake_Body_Unit(food.x,food.y);
	}
	if(food.flag==1)
	{
		srand(RTC_GetCounter());
		while(1)
		{
			food.x=rand()%120+1;
			food.y=rand()%120+1;
			
			for(i=0;i<snake.len;i++)
			{
				if((food.x==snake.x[i])&&(food.y==snake.y[i]))
				{
					break;
				}
				if(i==snake.len)
				{
					food.flag=0;
					break;
				}
			}
		}
		
	}
	
	LCD_Fill(0,250,240,320,YELLOW);
	LCD_ShowString(20,260,50,30,16,"Score");
//	LCD_ShowChar(70,260,20,12,':');
	LCD_ShowNum(65,260,snake.score,20,12);
	
}


//�ߵ��ƶ�����
void Snake_Move(u8 dir)
{
	u8 i;
	Snake_Off_Unit(snake.x[0],snake.y[0]);//�����һ��λ��Ϊ�հ�λ��
		
	if(dir==1)//�ж��������Ϊ����
	{
		snake.flag=1;
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
	
	Snake_Dead();
	Snake_Food();
	
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

//void Game_Back()
//{
//	LCD_Fill(0,0,240,30,BLUE);
//	LCD_Fill(0,290,240,320,BLUE);
//	
//}


	


//̰���߳�ʼ��
void Sanke_Init()
{
	u8 i;
	flag=0;//��ʼ����־λ
	snake.flag=1;//�ߵĴ�����־λ
	snake.len=4;//Ĭ��ʱ�ߵĳ���Ϊ�ĸ���λ
	snake.score=0;//Ĭ����Ϸ�ĳ�ʼ����Ϊ0
//	Game_Init();//��Ϸ�����ʼ��
//	if(snake.flag==1)
//	{
		for(i=0;i<snake.len;i++)
		{
			snake.x[i]=100+i*5;
			snake.y[i]=100;
		}
		for(i=0;i<snake.len;i++)
		{
			Snake_Body_Unit(snake.x[i],snake.y[i]);
		}
//	}
}




