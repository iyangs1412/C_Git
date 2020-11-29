#include "reg52.h"
#define GPIO_KEY P1
#define GPIO_DIG P0
typedef unsigned char u8;
typedef unsigned int u16;
sbit LSA = P2^2;
sbit LSB = P2^3;//74HC138译码器
sbit LSC = P2^4;//控制哪个数码管的输出
u8 code  smg[] = {0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f,0x77,0x7c,0x39,0x5e,0x79,0x71};
u8 keyvalue;
void delay(u16 i)
{
	while(i--);
}
void keydown()
{
	u8 a=0;
	GPIO_KEY=0x0f;
		if(GPIO_KEY!=0x0f)
		{
			delay(1000);
			if(GPIO_KEY!=0x0f)
			{                  //可有可无因为18行已经切换了
				GPIO_KEY=0x0f;//执行该语句的时候按键还处于按下的状态
				switch(GPIO_KEY)//确保单片机的IO口是0x0f状态
				{
					case 0x07:keyvalue=0;break;
					case 0x0b:keyvalue=1;break;
					case 0x0d:keyvalue=2;break;
					case 0x0e:keyvalue=3;break;
				
				}
				GPIO_KEY=0xf0;//执行该语句的时候按键还处于按下的状态
				switch(GPIO_KEY)//切换单片机IO口的状态为0xf
				{
					case 0x70:keyvalue=keyvalue;break;
					case 0xb0:keyvalue=keyvalue+4;break;
					case 0xd0:keyvalue=keyvalue+8;break;
					case 0xe0:keyvalue=keyvalue+12;break;
				}       //确保按下按键后如果一直按着while循环还可以退出
				while(a<50 && GPIO_KEY!=0xf0)
				{
					delay(1000);
					a++;
				}
			}
		}
}
void main()
{
	LSA = 0;
	LSB = 0;
	LSC = 0;
	while(1)
	{
		keydown();
		GPIO_DIG=smg[keyvalue];
	}														
}
