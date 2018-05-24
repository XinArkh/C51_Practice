#include "ioAT89C51.h"
#include "intrinsics.h"

//#include "reg52.h"

// Define pins
#define Dirctl (P0_bit.P0_7)
#define runctl (P3_bit.P3_0) // run/stop
#define run   (P3_bit.P3_1)  // run/stop control
#define Dir1  (P3_bit.P3_2)  // direction-1
#define Dir2  (P3_bit.P3_3)  // direction-2
#define Inc   (P3_bit.P3_4)  // speed up 
#define Dec   (P3_bit.P3_5)  // speed down 
#define Dir   (P3_bit.P3_6)  // motor direction control
#define PWM   (P3_bit.P3_7)  // PWM control

// Define new types
typedef unsigned int u16;
typedef unsigned char u8;

void delay(u16);

void main(void){
	int speed;
    // Select initial direction and speed.
    speed = 250;    
    Dirctl = 0;
    run = 1;
	Dir1 = 1; 
	Dir = 1;
    
    // Main control loop
    while(1){
    	// Read from keyboard
    	if(!runctl){
    		delay(1000);
    		if(!runctl){
    			run = 1 - run;
			}
		}
		if(!Dir1){
			delay(1000);
    		if(!Dir1){
    			Dirctl = 1;
				speed = 250;
			}
		}
		if(!Dir2){
			delay(1000);
    		if(!Dir2){
    			Dirctl = 0;
				speed = 250;
			}
		}
		if(!Inc){
			delay(1000);
    		if(!Inc){
    			if(Dir){
    				speed = speed > 0 ? speed - 50 : 0;
				}
				else{
					speed = speed < 500 ? speed + 50 : 500;
				}
			}
		}
		if(!Dec){
			delay(1000);
    		if(!Dec){
    			if(Dir){
					speed = speed < 500 ? speed + 50 : 500;
				}
				else{
    				speed = speed > 0 ? speed - 50 : 0;
				}
			}
		}
    	
    	
      	// PWM 
      	PWM=1;
      	delay(speed);
      	PWM=0;
      	delay(500-speed);
    }
}

void delay(u16 i){ 
 	while(i--);
 }
