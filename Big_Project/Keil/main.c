/**************************************************************************************
*                           	3150104904 武鑫										  *																			  
***************************************************************************************/
#include "reg52.h"
#include "models.h"

typedef unsigned int u16;
typedef unsigned char u8;

sbit beep=P2^4;
				
u8 Disp1[]="3150104904 WUXIN";
u8 Disp2[]="  Hello World!  ";

extern u8 Command;

/*******************************************************************************
* 函 数 名         : main
* 函数功能		   : 主函数
* 输    入         : 无
* 输    出         : 无
*******************************************************************************/
void main(void)
{
	u8 i;

	LcdInit();
	IrInit();

	for(i=0;i<16;i++)  // LED第一行信息，只需要执行一次
	{
		LcdWriteData(Disp1[i]);	
	}

	// 程序主循环
	while(1){
		beep = 1;
		if(Command == '0'){
			//beep = 0;
			//delay(10);
			LcdWriteCom(0x80+0x40);
			for(i=0;i<16;i++)
			{
				LcdWriteData(Disp1[i]);	
			}
			Lcd1602_Delay1ms(100);
		}
		else{
			LcdWriteCom(0x80+0x40);
			for(i=0;i<16;i++)
			{
				LcdWriteData(Disp2[i]);	
			}
			Lcd1602_Delay1ms(100);
		}
	}
}