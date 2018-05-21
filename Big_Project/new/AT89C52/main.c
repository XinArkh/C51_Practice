/********************************
FILE NAME:        dcmotor.c
CHIP TYPE:        AT89C51
CLOCK FREQUENCY:  12MHZ
IDE:              VSMStudio
COMPILER:         IAR for 8051
TIME:             September 2010
********************************/

#include "ioAT89C51.h"
#include "intrinsics.h"

// Define P3 pins
#define CGE   (P3_bit.P3_5)
#define Dir   (P3_bit.P3_6) 
#define PWM   (P3_bit.P3_7)

// Define new types
typedef unsigned char   uchar;
typedef unsigned int    uint;

void delay(uint);

void main(void)
 { int speed;
   int flag=0;
   // Select initial direction and speed.
   //Dir = 1;
   speed = 250;
   
   // Main control loop
   while(1)
    { 
      if(!CGE){
		  flag = 1-flag;
		  delay(1000);
	  }
	  if(flag==0){
		  Dir = 1;
		  PWM=1;
		  delay(speed);
		  PWM=0;
		  delay(500-speed);
	  }
	  else{
		  PWM = 1;
		  Dir=1;
		  delay(speed);
		  Dir=0;
		  delay(500-speed);
	  }
    }
 }

void delay(uint j)
 { for(; j>0; j--)
    { __no_operation();
    }
 }