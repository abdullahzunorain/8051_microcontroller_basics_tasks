/*
Task_12(Part_6):
Write a lookup table to show numbers from 0-9 on the displays. 
*/





///*__ A practice to do the task __*/
//#include <reg52.h>

//// declaring pins for 74HC138-decoder/demultiplexer IC (used for blinking specific `7-segment` display seperately)
//sbit pin1 = P2^2;
//sbit pin2 = P2^3;
//sbit pin3 = P2^4;

//#define Port_0 P0

////sbit a = P0^0;
////sbit b = P0^1;
////sbit c = P0^2;
////sbit d = P0^3;
////sbit e = P0^4;
////sbit f = P0^5;
////sbit g = P0^6;
////sbit h = P0^7;

//void M0T0delay(void){
//	unsigned int x;
//	for(x=0; x<10; x++){
//		TMOD = 0x01;    // 16-bit non-autoreload mode, timer_0, mode_1
//		TL0 = 0x00; 
//		TH0 = 0x00;
//		TR0 = 1;
//		while(TF0==0);
//		TR0 = 0;
//		TF0 = 0;
//	}
//}

//void main(){
//	
//	while(1){
//		pin1 = 0;
//		pin2 = 0;
//		pin3 = 0;
//		Port_0 = 0x3F;
//		M0T0delay();
//		
//		pin1 = 1;
//		pin2 = 0;
//		pin3 = 0;
//		Port_0 = 0x06;
//		M0T0delay();
//		
//		pin1 = 0;
//		pin2 = 1;
//		pin3 = 0;
//		Port_0 = 0x5B;
//		M0T0delay();
//		
//		pin1 = 1;
//		pin2 = 1;
//		pin3 = 0;
//		Port_0 = 0x4F;
//		M0T0delay();
//		
//		pin1 = 0;
//		pin2 = 0;
//		pin3 = 1;
//		Port_0 = 0x66;
//		M0T0delay();
//		
//		pin1 = 1;
//		pin2 = 0;
//		pin3 = 1;
//		Port_0 = 0x6D;
//		M0T0delay();
//		
//		pin1 = 0;
//		pin2 = 1;
//		pin3 = 1;
//		Port_0 = 0x7D;
//		M0T0delay();
//		
//		pin1 = 1;
//		pin2 = 1;
//		pin3 = 1;
//		Port_0 = 0x07;
//		M0T0delay();
//		
//		pin1 = 1;
//		pin2 = 1;
//		pin3 = 1;
//		Port_0 = 0x7F;
//		M0T0delay();
//		
//		pin1 = 1;
//		pin2 = 1;
//		pin3 = 1;
//		Port_0 = 0x6F;
//		M0T0delay();
//		
//		pin1 = 1;
//		pin2 = 1;
//		pin3 = 1;
//		Port_0 = 0x77;
//		M0T0delay();
//		
//		pin1 = 1;
//		pin2 = 1;
//		pin3 = 1;
//		Port_0 = 0x7C;
//		M0T0delay();
//		
//		pin1 = 1;
//		pin2 = 1;
//		pin3 = 1;
//		Port_0 = 0x39;
//		M0T0delay();
//		
//		pin1 = 1;
//		pin2 = 1;
//		pin3 = 1;
//		Port_0 = 0x5E;
//		M0T0delay();
//		
//		pin1 = 1;
//		pin2 = 1;
//		pin3 = 1;
//		Port_0 = 0x79;
//		M0T0delay();
//		
//		pin1 = 1;
//		pin2 = 1;
//		pin3 = 1;
//		Port_0 = 0x71;
//		M0T0delay();
//	}
//}






/*-------------------------------------------------------------------------------------------------------------------------------------------------------------*/

///*..1st Approch to task..*/
//#include <reg52.h>

//sbit pin1 = P2^2;
//sbit pin2 = P2^3;
//sbit pin3 = P2^4;

//#define Port_0 P0

//void M0T0delay(void){
//	
//		TMOD = 0x01;  // 16-bit non-autoreload mode, timer_0, mode_1
//		TL0 = 0xFE; 
//		TH0 = 0xFA;
//		TR0 = 1;
//		while(TF0==0);
//		TR0 = 0;
//		TF0 = 0;
//}

//void main(){
//	while(1){
//		pin1 = 0;
//		pin2 = 0;
//		pin3 = 0;
//		Port_0 = 0x06;
//		M0T0delay();
//		
//		pin1 = 1;
//		pin2 = 0;
//		pin3 = 0;
//		Port_0 = 0x5B;
//		M0T0delay();
//		
//		pin1 = 0;
//		pin2 = 1;
//		pin3 = 0;
//		Port_0 = 0x4F;
//		M0T0delay();
//		
//		pin1 = 1;
//		pin2 = 1;
//		pin3 = 0;
//		Port_0 = 0x66;
//		M0T0delay();
//		
//		pin1 = 0;
//		pin2 = 0;
//		pin3 = 1;
//		Port_0 = 0x6D;
//		M0T0delay();
//		
//		pin1 = 1;
//		pin2 = 0;
//		pin3 = 1;
//		Port_0 = 0x7D;
//		M0T0delay();
//		
//		pin1 = 0;
//		pin2 = 1;
//		pin3 = 1;
//		Port_0 = 0x07;
//		M0T0delay();
//		
//		pin1 = 1;
//		pin2 = 1;
//		pin3 = 1;
//		Port_0 = 0x7F;
//		M0T0delay();
//		
//		pin1 = 1;
//		pin2 = 1;
//		pin3 = 1;
//		Port_0 = 0x6F;
//		M0T0delay();
//	}
//}








//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

/*..2nd Approach to task..*/
#include <reg52.h>

sbit pin1 = P2^2;
sbit pin2 = P2^3;
sbit pin3 = P2^4;

#define Port_0 P0


void display_zero_to_F();

void M0T0delay(void){
	
		TMOD = 0x01;  // 16-bit non-autoreload mode, timer_0, mode_1
		TL0 = 0x00; 
		TH0 = 0x00;
		TR0 = 1;
		while(TF0==0);
		TR0 = 0;
		TF0 = 0;
}


void main(){
	while(1){
		
		pin1 = 0;
		pin2 = 0;
		pin3 = 0;
		
		display_zero_to_F();
		M0T0delay();
		
		pin1 = 1;
		pin2 = 0;
		pin3 = 0;
		
		display_zero_to_F();
		M0T0delay();
		
		
		pin1 = 0;
		pin2 = 1;
		pin3 = 0;
	
		display_zero_to_F();
		M0T0delay();
		
		pin1 = 1;
		pin2 = 1;
		pin3 = 0;

		display_zero_to_F();
		M0T0delay();
		
		pin1 = 0;
		pin2 = 0;
		pin3 = 1;
	
		display_zero_to_F();
		M0T0delay();

		pin1 = 1;
		pin2 = 0;
		pin3 = 1;

		display_zero_to_F();
		M0T0delay();
		
		pin1 = 0;
		pin2 = 1;
		pin3 = 1;
	
		display_zero_to_F();
		M0T0delay();
		
		pin1 = 1;
		pin2 = 1;
		pin3 = 1;

		display_zero_to_F();
		M0T0delay();
		
		pin1 = 1;
		pin2 = 1;
		pin3 = 1;

	}
}


void display_zero_to_F(){
	
		Port_0 = 0x3F;
		M0T0delay();
		M0T0delay();
	
		Port_0 = 0x06;
		M0T0delay();
		M0T0delay();


		Port_0 = 0x5B;
		M0T0delay();
		M0T0delay();

		Port_0 = 0x4F;
		M0T0delay();
		M0T0delay();		

		Port_0 = 0x66;
		M0T0delay();
		M0T0delay();

		Port_0 = 0x6D;
		M0T0delay();
		M0T0delay();

		Port_0 = 0x7D;
		M0T0delay();
		M0T0delay();

		Port_0 = 0x07;
		M0T0delay();
		M0T0delay();

		Port_0 = 0x7F;
		M0T0delay();
		M0T0delay();

		Port_0 = 0x6F;
		M0T0delay();
		M0T0delay();
		
		
		Port_0 = 0x77;
		M0T0delay();
		M0T0delay();
		
		
		Port_0 = 0x7C;
		M0T0delay();
		M0T0delay();
		
		
		Port_0 = 0x39; 
		M0T0delay();
		M0T0delay();
		
		Port_0 = 0x5E;
		M0T0delay();
		M0T0delay();
		
		Port_0 = 0x79;
		M0T0delay();
		M0T0delay();
}
