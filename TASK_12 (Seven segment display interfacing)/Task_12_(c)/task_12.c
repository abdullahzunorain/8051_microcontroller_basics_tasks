/*
task_12: (3). Write a program to select LED1 to LED8 with a delay of 500 ms (use timer delay), the final 
	          result of the program will be that 7 segment displays will turn ON one by one from first to 
	          eighth display.  
*/




/*...Practice (for understanding the mechanism)...*///-----------------------------------------------------------------------------------------------------------------------------------------------------

//////#include <reg52.h>
///////////////////////////////
//////sbit pin1 = P2^2;   /////  these pins are used for Activation of any 7-segment display of LED.
//////sbit pin2 = P2^3;   /////       //
//////sbit pin3 = P2^4;   /////       //
///////////////////////////////

///////////////////////////////
//////#define LED P0    /////// this `Port_0` is used for any value, alphabet or whatever we want to display on `7-segment display`
///////////////////////////////

//////sbit led0 = P2^0; 

//////void M0T0delay(unsigned int);

//////void main(){
//////	while(1){
//////		
////////		///////////////////////////////////////////////////////
////////    Here we are going to check the delay for the Seven segment display through using `PIN 2.0` -->> led0
////////		/////// 1-th seven segment display /////////////////////
////////				pin1 = 0;//////////////////////////////////////////
////////				pin2 = 0;//////////////////////////////////////////
////////				pin3 = 0;//////////////////////////////////////////
////////				led0 = ~led0;//////////////////////////////////////
////////				M0T0delay(500);////////////////////////////////////
////////		///////////////////////////////////////////////////////
//////		
//////////		2nd method to check the delay for the Seven segment display
////////		// 2-nd seven segment display
////////		pin1 = 1;
////////		pin2 = 0;
////////		pin3 = 0;
////////		LED = ~LED;
////////		led0 = ~led0;
////////		M0T0delay(500);
//////		
//////		
//////		
//////		
////////		
////////		// 2
////////		pin1 = 0;
////////		pin2 = 1;
////////		pin3 = 0;
////////		M0T0delay(500);
////////		
////////		// 3
////////		pin1 = 1;
////////		pin2 = 1;
////////		pin3 = 0;
////////		M0T0delay(500);
////////		
////////		// 4
////////		pin1 = 0;
////////		pin2 = 0;
////////		pin3 = 1;
////////		M0T0delay(500);
////////		
////////		// 5
////////		pin1 = 1;
////////		pin2 = 0;
////////		pin3 = 1;
////////		M0T0delay(500);
////////		
////////		// 6
////////		pin1 = 0;
////////		pin2 = 1;
////////		pin3 = 1;
////////		M0T0delay(500);
////////		
////////		// 7
////////		pin1 = 1;
////////		pin2 = 1;
////////		pin3 = 1;
////////		M0T0delay(500);
//////		
//////	}
//////}

//////void M0T0delay(unsigned int ms) {
//////    unsigned int i, j;
//////    for (i = 0; i < ms; i++)
//////        for (j = 0; j < 112; j++);
//////}





/////////*...Method_01...*///--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
////////#include <reg52.h>
////////sbit pin1 = P2^2;
////////sbit pin2 = P2^3;
////////sbit pin3 = P2^4;

////////void M0T0delay(unsigned int);

////////void main(){
////////	while(1){
////////		
////////		// 0
////////		pin1 = 0;
////////		pin2 = 0;
////////		pin3 = 0;
////////		M0T0delay(500);
////////		
////////		// 1
////////		pin1 = 1;
////////		pin2 = 0;
////////		pin3 = 0;
////////		M0T0delay(500);
////////		
////////		// 2
////////		pin1 = 0;
////////		pin2 = 1;
////////		pin3 = 0;
////////		M0T0delay(500);
////////		
////////		// 3
////////		pin1 = 1;
////////		pin2 = 1;
////////		pin3 = 0;
////////		M0T0delay(500);
////////		
////////		// 4
////////		pin1 = 0;
////////		pin2 = 0;
////////		pin3 = 1;
////////		M0T0delay(500);
////////		
////////		// 5
////////		pin1 = 1;
////////		pin2 = 0;
////////		pin3 = 1;
////////		M0T0delay(500);
////////		
////////		// 6
////////		pin1 = 0;
////////		pin2 = 1;
////////		pin3 = 1;
////////		M0T0delay(500);
////////		
////////		// 7
////////		pin1 = 1;
////////		pin2 = 1;
////////		pin3 = 1;
////////		M0T0delay(500);
////////		
////////	}
////////}

////////void M0T0delay(unsigned int ms) {
////////    unsigned int i, j;
////////    for (i = 0; i < ms; i++)
////////        for (j = 0; j < 112; j++);
////////}






///*_Method_02_(using timer_0 mode_2: 8_bit auto-reload)_*///---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

////	#include <reg52.h>

////	// declaring pins for 74HC138-decoder/demultiplexer IC (used for blinking specific `7-segment` display seperately)
////	sbit pin1 = P2^2;
////	sbit pin2 = P2^3;
////	sbit pin3 = P2^4;

////	void M0T0delay(void);  // delay function prototype

////	void main(){
////		
////		while(1){
////			// for each 7-segment display these pins have different values...
////			// 1st seven segment display
////			pin1 = 0;
////			pin2 = 0;
////			pin3 = 0;
////			M0T0delay();
////			
////			//  2nd seven segment display
////			pin1 = 1;
////			pin2 = 0;
////			pin3 = 0;
////			M0T0delay();
////			
////			//  3rd seven segment display
////			pin1 = 0;
////			pin2 = 1;
////			pin3 = 0;
////			M0T0delay();
////			
////			//  4th seven segment display
////			pin1 = 1;
////			pin2 = 1;
////			pin3 = 0;
////			M0T0delay();
////			
////			//  5th seven segment display
////			pin1 = 0;
////			pin2 = 0;
////			pin3 = 1;
////			M0T0delay();
////			
////			//  6th seven segment display
////			pin1 = 1;
////			pin2 = 0;
////			pin3 = 1;
////			M0T0delay();
////			
////			//  7th seven segment display
////			pin1 = 0;
////			pin2 = 1;
////			pin3 = 1;
////			M0T0delay();
////			
////			//  8th seven segment display
////			pin1 = 1;
////			pin2 = 1;
////			pin3 = 1;
////			M0T0delay();
////		}
////	}

////	/*... timer delay using 8-bit autoreload mode, timer_0, mode_2 ...*/
////	void M0T0delay(void){
////		unsigned long y;         // declaring a variable
////		for(y=0; y<9050; y++){  // for loop: for contineous iteration up to 100, then the timer delay will be called.
////			TMOD = 0x02;          // 8-bit auto-reload mode, timer_0, mode_2
////			TH0 = 0x00;
////			TR0 = 1;
////		}
////	}







/*.Method_03_(using timer_0 mode_2: 16_bit non-autoreload).*///---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

#include <reg52.h>

// declaring pins for 74HC138-decoder/demultiplexer IC (used for blinking specific `7-segment` display seperately)
sbit pin1 = P2^2;
sbit pin2 = P2^3;
sbit pin3 = P2^4;

void M0T0delay(void);  // delay function prototype

void main(){
	
	while(1){
		// for each 7-segment display these pins have different values...
		// 1st seven segment display
		pin1 = 0;
		pin2 = 0;
		pin3 = 0;
		M0T0delay();
		
		//  2nd seven segment display
		pin1 = 1;
		pin2 = 0;
		pin3 = 0;
		M0T0delay();
		
		//  3rd seven segment display
		pin1 = 0;
		pin2 = 1;
		pin3 = 0;
		M0T0delay();
		
		//  4th seven segment display
		pin1 = 1;
		pin2 = 1;
		pin3 = 0;
		M0T0delay();
		
		//  5th seven segment display
		pin1 = 0;
		pin2 = 0;
		pin3 = 1;
		M0T0delay();
		
		//  6th seven segment display
		pin1 = 1;
		pin2 = 0;
		pin3 = 1;
		M0T0delay();
		
		//  7th seven segment display
		pin1 = 0;
		pin2 = 1;
		pin3 = 1;
		M0T0delay();
		
		//  8th seven segment display
		pin1 = 1;
		pin2 = 1;
		pin3 = 1;
		M0T0delay();
	}
}

/*... 16-bit non-autoreload mode, timer_0, mode_1 ...*/

void M0T0delay(void){
	unsigned int y;         // declaring a variable
	for(y=0; y<10; y++){    // for loop: for contineous iteration up to 100, then the timer delay will be called.
		TMOD = 0x01;          // 16-bit non-autoreload mode, timer_0, mode_1
		TL0 = 0x00; 
		TH0 = 0x4B;
		TR0 = 1;
		while(TF0==0);
		TR0 = 0;
		TF0 = 0;
	}
}

