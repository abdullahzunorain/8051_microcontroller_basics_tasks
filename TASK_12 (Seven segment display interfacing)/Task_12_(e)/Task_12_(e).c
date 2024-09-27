/*
Task# 12(Part_5):
Decrease the timer interrupt time so that the refresh rate of the displays becomes 50 Hz. 
Please note that each display gets its turn to refresh after 8 timer interrupts so the refresh 
rate you calculate has to be divided by 8. Show your calculations for a refresh rate of 50 Hz. 
*/




////	/* _Method_01(displaying each seven_segment_display using timer-interrupt with a delay of 10ms)_ */
////	#include <reg52.h>

////	//#define LED P0
////	//sbit led1 = P2^0;


////	// declaring pins for 74HC138-decoder/demultiplexer IC (used for blinking specific `7-segment` display seperately)
////	sbit pin1 = P2^2;
////	sbit pin2 = P2^3;
////	sbit pin3 = P2^4;
////	unsigned int x = 0;


////	void timer0(void) interrupt 1{
////			x++;
////			
////		// Timer configuration for 10ms delay..
////		// The delay in each seven segment display is 10ms(two consecutive display will turns ON after 10ms)
////			TMOD = 0x01; // 16-bit non-auto reload mode
////			TL0=0xFF;
////			TH0=0xDC;
////		
////			// display__0
////			if (x==1){
////			pin1 = 0;
////			pin2 = 0;
////			pin3 = 0;
////	//		LED = 0xFF;
////	//		led1 = ~led1;
////			}
////				
////			if (x==2){
////			//  display__1
////			pin1 = 1;
////			pin2 = 0;
////			pin3 = 0;
////	//		LED = 0xFF;
////			}
////			
////			if (x==3){
////			//  display__2
////			pin1 = 0;
////			pin2 = 1;
////			pin3 = 0;
////	//		LED = 0xFF;
////			}
////			
////			if (x==4){
////			//  display__3
////			pin1 = 1;
////			pin2 = 1;
////			pin3 = 0;
////	//		LED = 0xFF;
////			}
////			
////			if (x==5){
////			//  display__4
////			pin1 = 0;
////			pin2 = 0;
////			pin3 = 1;
////	//		LED = 0xFF;
////			}
////			
////			if (x==6){
////			//  display__5
////			pin1 = 1;
////			pin2 = 0;
////			pin3 = 1;
////	//		LED = 0xFF;
////			}
////			
////			if (x==7){
////			//  display__6
////			pin1 = 0;
////			pin2 = 1;
////			pin3 = 1;
////	//		LED = 0xFF;
////			}
////			
////			if (x==8){
////			//  display__7
////			pin1 = 1;
////			pin2 = 1;
////			pin3 = 1;
////	//		LED = 0xFF;
////			x=0;
////			}
////	}



////	void main(){
////		 TMOD = 0x01; // 16-bit non-auto reload mode
////		 TL0=0xFF;
////		 TH0=0xDC;
////		 IE = 0x82;
////		 TR0=1;
////		
////		while (1){
////		// ..
////		}
////	}

////	 





// --------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

#include <reg52.h>

//#define LED P0
//sbit led1 = P2^0;


// declaring pins for 74HC138-decoder/demultiplexer IC (used for blinking specific `7-segment` display seperately)
sbit pin1 = P2^2;
sbit pin2 = P2^3;
sbit pin3 = P2^4;
unsigned int x = 0;

sbit led0 = P2^0;

void timer0(void) interrupt 1{
		x++;

		TMOD=0x01; // 16-bit non-auto reload mode
		TL0=0xFF;
		TH0=0xDC;
	
		// display__0
		if (x==1){
		pin1 = 0;
		pin2 = 0;
		pin3 = 0;
			
		led0 = ~led0;
			
//		LED = 0xFF;
//		led1 = ~led1;
		}
			
		if (x==2){
		//  display__1
		pin1 = 1;
		pin2 = 0;
		pin3 = 0;
		}
		
		if (x==3){
		//  display__2
		pin1 = 0;
		pin2 = 1;
		pin3 = 0;
		}
		
		if (x==4){
		//  display__3
		pin1 = 1;
		pin2 = 1;
		pin3 = 0;
		}
		
		if (x==5){
		//  display__4
		pin1 = 0;
		pin2 = 0;
		pin3 = 1;
		}
		
		if (x==6){
		//  display__5
		pin1 = 1;
		pin2 = 0;
		pin3 = 1;
		}
		
		if (x==7){
		//  display__6
		pin1 = 0;
		pin2 = 1;
		pin3 = 1;
		}
		
		if (x==8){
		//  display__7
		pin1 = 1;
		pin2 = 1;
		pin3 = 1;
		x=0;
 		}
}



void main(){
	 TMOD=0x01; // 16-bit non-auto reload mode
	 TL0=0xFF;
	 TH0=0xDC;
	 IE =0x82;
	 TR0 = 1;
	
	while (1){
	// ..
	}
}

	 
