/**************************************************************************************
*                           	3150104904 武鑫				                    						  *																			  
***************************************************************************************/
#include "reg52.h"
#include "models.h"

// 定义关键词
typedef unsigned int u16;
typedef unsigned char u8;

//定义引脚
sbit PWM = P2^1;  // 电机PWM控制
sbit SWI = P2^2;  // 电化开关，低电平接通
sbit Dir = P2^3;  // 电机方向
sbit beep = P2^4;  // 蜂鸣器,低电平响

// 定义LCD显示变量
u8 Disp0[]="                ";
u8 Disp1[]="3150104904 WUXIN";
u8 Disp2[]="    Stopped!    ";
u8 Disp3[]="  Dir1  Speed1  ";
u8 Disp4[]="  Dir1  Speed2  ";
u8 Disp5[]="  Dir2  Speed1  ";
u8 Disp6[]="  Dir2  Speed2  ";

u8 Command='-';

u16 low = 200;
u16 high = 250;

u16 pwm = 200;

// 定义函数
void Init();
void CtrlInit();
void LcdDisp(uchar *dat);

/*******************************************************************************
* 函 数 名         : main
* 函数功能		   : 主函数
* 输    入         : 无
* 输    出         : 无
*******************************************************************************/
void main(void)
{
	u8 i;
	
	Init();  // 初始化所有模块
	
	for(i=0;i<16;i++)  // LED第一行信息，只需要执行一次
	{
		LcdWriteData(Disp1[i]);	
	}
	LcdDisp(Disp2);

	// 程序主循环
	while(1){
		beep = 1;
		
		if(!START){
			beep = 0;
			Command = '4';
			while(!START);
		}
		if(!SWI){
			if(!UP){
				beep = 0;
				Command = '9';
				while(!UP);
			}
			else if(!DOWN){
				beep = 0;
				Command = '5';
				while(!DOWN);
			}
			else if(!LEFT){
				beep = 0;
				Command = '0';
				while(!LEFT);
			}
			else if(!RIGHT){
				beep = 0;
				Command = '3';
				while(!RIGHT);
			}
		}
		
		
		switch(Command){
			case '4':
				SWI = !SWI;
				if(SWI){  // 停机
					LcdDisp(Disp2);
				}
				else{  // 开启
					Dir = 0;
					pwm = low;
					LcdDisp(Disp3);
				}
				break;
			case '9':
				if(!Dir){
					pwm = high;
					LcdDisp(Disp4);
				}
				else{
					pwm = high;
					LcdDisp(Disp6);
				}
				break;
			case '5':
				if(!Dir){
					pwm = low;
					LcdDisp(Disp3);
				}
				else{
					pwm = low;
					LcdDisp(Disp5);
				}
				break;
			case '0':
				Dir = 0;
				pwm = low;
				LcdDisp(Disp3);
				break;
			case '3':
				Dir = 1;
				pwm = low;
				LcdDisp(Disp5);
				break;
			default:
				break;
		}
		Command = '-';
		
		if(!SWI){
			// Dir和DIR电位相反
			// DIR和PWM电位相同时为无效状态
			if(!Dir){  // PWM=1 invalid(at this time DIR=1)
				PWM = 0;
				delay(pwm);
				PWM = 1;
				delay(500-pwm);
				//PWM = 0;
				//delay(500);
			}
			else{  // PWM=0 invalid(at this time DIR=0)
				PWM = 1;
				delay(pwm);
				PWM = 0;
				delay(500-pwm);
				//PWM = 1;
				//delay(500);
			}
		}
		else{
			PWM = !Dir;  //PWM和Dir电位相反时PWM与DIR电位相同，无效状态
			delay(500);
		}
	}
}





void Init(){
	LcdInit();  // 初始化LCD
	IrInit();  // 初始化红外接收器
	BTInit();  // 初始化按钮引脚电平
	CtrlInit();  // 初始化控制引脚
}

void CtrlInit(){
	// 开机时需要初始化继电器
	SWI = 0;
	delay(200);
	SWI = 1;  // 电路板通电后电机默认关闭，即SWI=1
	Dir = 1;
	delay(200);
	Dir = 0;  // 方向1
}

void LcdDisp(uchar *dat)
{
	u8 i;
	LcdWriteCom(0x80+0x40);
	for(i=0;i<16;i++)
	{
		LcdWriteData(dat[i]);	
	}
	Lcd1602_Delay1ms(100);
}