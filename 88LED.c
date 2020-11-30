#include "reg51.h"//reg52.h已经定义了sbit srclk rclk ser 
#include "intrins.h"			//595是具有8位移位寄存器和一个存储器，三态输出功能。
typedef unsigned char u8;
typedef unsigned int u16;
u8 led_col[] = {0x00, 0x00, 0x3e, 0x41, 0x41, 0x41, 0x3e, 0x00};
u8 led_row[] = {0x00, 0x1c, 0x22, 0x22, 0x22, 0x22, 0x22, 0x1c};
sbit srclk = P3 ^ 6;
sbit rclk = P3 ^ 5;
sbit ser = P3 ^ 4;//一个一个字节的发   发送最高位
void delay (u16 i);
//发送数据
void hc595sendbyte(u8 dat)
{
	srclk = 0;
	rclk = 0;
	for (u8 i; i < 8;i++)
	{
		ser = dat>>7;//左移7位不改变dat的数据,将左移7位在将最高位给ser
		dat << 1;		//次高位变为最高位
		srclk = 1;//	将移位寄存器移位
		_nop_();
		_nop_();
		srclk = 0;
	}
	rclk = 1;
	_nop_();
	_nop_();
	rclk = 0;
}
void main()
{		
	
	
	
	
	
	
	
	
	//点亮第一行第一列的LED
	//hc595sendbyte(0x80) //1000 0000第一列的第一个位高电平
	//P0 = 0x7f; 0111 1111//
	//while(1);
}
void delay (u16 i)
{
	while(i--);
}

