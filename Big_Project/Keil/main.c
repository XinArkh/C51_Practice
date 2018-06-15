/**************************************************************************************
*                           	3150104904 ����										  *																			  
***************************************************************************************/
#include "reg52.h"
#include "lcd.h"

typedef unsigned int u16;
typedef unsigned char u8;
			
u8 Disp1[]="3150104904 WUXIN";
u8 Disp2[]="  Hello World!  ";

/*******************************************************************************
* �� �� ��         : main
* ��������		   : ������
* ��    ��         : ��
* ��    ��         : ��
*******************************************************************************/
void main(void)
{
	u8 i;
	LcdInit();
	for(i=0;i<16;i++)
	{
		LcdWriteData(Disp1[i]);	
	}
	LcdWriteCom(0x80+0x40);
	for(i=0;i<16;i++)
	{
		LcdWriteData(Disp2[i]);	
	}
	Lcd1602_Delay1ms(2000);

	LcdWriteCom(0x80+0x40);
	for(i=0;i<16;i++)
	{
		LcdWriteData(Disp1[i]);	
	}

	Lcd1602_Delay1ms(2000);
	LcdWriteCom(0x80+0x40);
	for(i=0;i<16;i++)
	{
		LcdWriteData(Disp2[i]);	
	}

	while(1);
}