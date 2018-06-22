#include<reg51.h>
#include<intrins.h>
sbit SRCLK=P3^6;
sbit RCLK=P3^5;
sbit SER=P3^4;

//--定义要使用的IO口--//
#define COMMONPORTS		P0
//--列选通控制--//
unsigned char code TAB[8]  = {0x7f,0xbf,0xdf,0xef,0xf7,0xfb,0xfd,0xfe};
//--点阵字码--//
unsigned char code CHARCODE[10][8]=
{
{0x00,0x00,0x3e,0x41,0x41,0x41,0x3e,0x00}, //0
{0x00,0x00,0x00,0x00,0x21,0x7f,0x01,0x00}, //1
{0x00,0x00,0x27,0x45,0x45,0x45,0x39,0x00}, //2
{0x00,0x00,0x22,0x49,0x49,0x49,0x36,0x00}, //3
{0x00,0x00,0x0c,0x14,0x24,0x7f,0x04,0x00}, //4
{0x00,0x00,0x72,0x51,0x51,0x51,0x4e,0x00}, //5
{0x00,0x00,0x3e,0x49,0x49,0x49,0x26,0x00}, //6
{0x00,0x00,0x40,0x40,0x40,0x4f,0x70,0x00}, //7
{0x00,0x00,0x36,0x49,0x49,0x49,0x36,0x00}, //8
{0x00,0x00,0x32,0x49,0x49,0x49,0x3e,0x00}, //9

};
void delay(unsigned int i)
{
  	while(i--);
}

/*******************************************************************************
* 函数名         : HC595SendByte(unsigned char dat)
* 函数功能		 : 向74H595发送一个字节的数据
* 输入           : 无
* 输出         	 : 无
*******************************************************************************/
void HC595SendByte(unsigned char dat)
{
	unsigned char a;
	SRCLK=0;
	RCLK=0;
	for(a=0;a<8;a++)
	{
		SER=dat>>7;
		dat<<=1;

		SRCLK=1;
		_nop_();
		_nop_();
		SRCLK=0;	
	}

	RCLK=1;
	_nop_();
	_nop_();
	RCLK=0;
}
/***********************************************************
* 函数名         : main
* 函数功能		   : 主函数
* 输入           : 无
* 输出         	 : 无
*********************************************************/

void main()
{	
 	unsigned char tab, j;
	unsigned int  i;
	while(1)
	{	
		for(i= 0; i<50; i++ )   //两个字之间的扫描间隔时间
		{
			for(tab=0;tab<8;tab++)
			{	

				HC595SendByte(0x00);			     //消隐																
				COMMONPORTS	= TAB[tab];				 //输出字码	
				HC595SendByte(CHARCODE[j][tab]);	
				delay(200);		
			}
			 
		}
		j++;
		if(j == 10)
		{
			j = 0;
		}
	}	
}
