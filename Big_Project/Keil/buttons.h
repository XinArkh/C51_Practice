#ifndef __BUTTONS_H_
#define __BUTTONS_H_
/**********************************
����ͷ�ļ�
**********************************/
#include<reg52.h>

/**********************************
�ض���ؼ���
**********************************/
#ifndef uchar
#define uchar unsigned char
#endif

#ifndef uint 
#define uint unsigned int
#endif

/**********************************
PIN�ڶ���
**********************************/
sbit UP = P3^3;
sbit DOWN = P3^7;
sbit LEFT = P3^6;
sbit RIGHT = P3^4;
sbit START = P3^5;

/**********************************
��������
**********************************/
/*��ʼ�������߽���*/		
void BTInit();					  

#endif