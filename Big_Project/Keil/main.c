/**************************************************************************************
*                           	3150104904 ����										  *																			  
***************************************************************************************/
#include "reg52.h"
#include "models.h"

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
	u8 flag;
	LcdInit();
	for(i=0;i<16;i++)
	{
		LcdWriteData(Disp1[i]);	
	}
	while(1){
		if(flag){
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
		flag = 1 - flag;
	}
}