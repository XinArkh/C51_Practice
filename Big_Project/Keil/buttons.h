#ifndef __BUTTONS_H_
#define __BUTTONS_H_
/**********************************
包含头文件
**********************************/
#include<reg52.h>

/**********************************
重定义关键词
**********************************/
#ifndef uchar
#define uchar unsigned char
#endif

#ifndef uint 
#define uint unsigned int
#endif

/**********************************
PIN口定义
**********************************/
sbit UP = P3^3;
sbit DOWN = P3^7;
sbit LEFT = P3^6;
sbit RIGHT = P3^4;
sbit START = P3^5;

/**********************************
函数声明
**********************************/
/*初始化红外线接收*/		
void BTInit();					  

#endif