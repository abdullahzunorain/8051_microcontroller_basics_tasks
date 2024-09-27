/*...Method_01...*/
#include <reg52.h>

/////////////////////////
sbit pin1 = P2^2;   /////  these pins are used for Activation of any 7-segment display of LED.
sbit pin2 = P2^3;   /////       //
sbit pin3 = P2^4;   /////       //
/////////////////////////

/////////////////////////
#define LED P0    /////// this `Port_0` is used for any value, alphabet or whatever we want to display on `7-segment display`
/////////////////////////

sbit led0 = P2^0; 

void M0T0delay(unsigned int);

void main(){
	while(1){
		
//		///////////////////////////////////////////////////////
//    Here we are going to check the delay for the Seven segment display through using `PIN 2.0` -->> led0
//		/////// 1-th seven segment display /////////////////////
//				pin1 = 0;//////////////////////////////////////////
//				pin2 = 0;//////////////////////////////////////////
//				pin3 = 0;//////////////////////////////////////////
//				led0 = ~led0;//////////////////////////////////////
//				M0T0delay(500);////////////////////////////////////
//		///////////////////////////////////////////////////////
		
////		2nd method to check the delay for the Seven segment display
//		// 2-nd seven segment display
//		pin1 = 1;
//		pin2 = 0;
//		pin3 = 0;
//		LED = ~LED;
//		led0 = ~led0;
//		M0T0delay(500);
		
		
		
		
////		
////		// 2
////		pin1 = 0;
////		pin2 = 1;
////		pin3 = 0;
////		M0T0delay(500);
////		
////		// 3
////		pin1 = 1;
////		pin2 = 1;
////		pin3 = 0;
////		M0T0delay(500);
////		
////		// 4
////		pin1 = 0;
////		pin2 = 0;
////		pin3 = 1;
////		M0T0delay(500);
////		
////		// 5
////		pin1 = 1;
////		pin2 = 0;
////		pin3 = 1;
////		M0T0delay(500);
////		
////		// 6
////		pin1 = 0;
////		pin2 = 1;
////		pin3 = 1;
////		M0T0delay(500);
////		
////		// 7
////		pin1 = 1;
////		pin2 = 1;
////		pin3 = 1;
////		M0T0delay(500);
		
	}
}

void M0T0delay(unsigned int ms) {
    unsigned int i, j;
    for (i = 0; i < ms; i++)
        for (j = 0; j < 112; j++);
}
