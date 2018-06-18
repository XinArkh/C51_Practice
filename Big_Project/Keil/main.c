/**************************************************************************************
*                           	3150104904 ����				                    						  *																			  
***************************************************************************************/
#include "reg52.h"
#include "models.h"

// ����ؼ���
typedef unsigned int u16;
typedef unsigned char u8;

//��������
sbit PWM = P2^1;  // ���PWM����
sbit SWI = P2^2;  // �绯���أ��͵�ƽ��ͨ
sbit Dir = P2^3;  // �������
sbit beep = P2^4;  // ������,�͵�ƽ��

// ����LCD��ʾ����
u8 Disp0[]="                ";
u8 Disp1[]="3150104904 WUXIN";
u8 Disp2[]="    Stopped!    ";
u8 Disp3[]="  Dir1  Speed1  ";
u8 Disp4[]="  Dir1  Speed2  ";
u8 Disp5[]="  Dir2  Speed1  ";
u8 Disp6[]="  Dir2  Speed2  ";

u8 Command='-';

u16 low = 60;
u16 high = 70;
u16 pwm = 55;
//u16 offset = 850;

// ���庯��
void Init();
void CtrlInit();
void LcdDisp(uchar *dat);

/*******************************************************************************
* �� �� ��         : main
* ��������		   : ������
* ��    ��         : ��
* ��    ��         : ��
*******************************************************************************/
void main(void)
{
	u8 i;
	
	Init();  // ��ʼ������ģ��
	
	for(i=0;i<16;i++)  // LED��һ����Ϣ��ֻ��Ҫִ��һ��
	{
		LcdWriteData(Disp1[i]);	
	}
	LcdDisp(Disp2);

	// ������ѭ��
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
				if(SWI){  // ͣ��
					LcdDisp(Disp2);
				}
				else{  // ����
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
					//pwm = 1000-high-offset;
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
					//pwm = 1000-low-offset;
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
				//pwm = 1000-low-offset;
				pwm = low;
				LcdDisp(Disp5);
				break;
			default:
				break;
		}

		Command = '-';
		
		if(!SWI){
			PWM = 0;
			delay(pwm);
			PWM = 1;
			delay(1000-pwm);
		}
		else{
			PWM = 1;
			delay(1000);
		}
	}
}

void Init(){
	LcdInit();  // ��ʼ��LCD
	IrInit();  // ��ʼ�����������
	BTInit();  // ��ʼ����ť���ŵ�ƽ
	CtrlInit();  // ��ʼ����������
}

void CtrlInit(){
	SWI = 1;  // ��·��ͨ�����Ĭ�Ϲر�
	Dir = 0;  // ����1
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