/**************************************************************************************
*                           	3150104904 武鑫										  *																			  
***************************************************************************************/
#include "reg52.h"
#include "models.h"

typedef unsigned int u16;
typedef unsigned char u8;
				
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

	for(i=0;i<16;i++)
	{
		LcdWriteData(Disp1[i]);	
	}
	while(1){
		if(Command != '0'){
			LcdWriteCom(0x80+0x40);
			for(i=0;i<16;i++)
			{
				LcdWriteData(Disp1[i]);	
			}
			Lcd1602_Delay1ms(1000);
		}
		else{
			LcdWriteCom(0x80+0x40);
			for(i=0;i<16;i++)
			{
				LcdWriteData(Disp2[i]);	
			}
			Lcd1602_Delay1ms(1000);
		}
	}
}