
//	#include <reg52.h>

//	//#define LED P0
//	//sbit led1 = P2^0;


//	// declaring pins for 74HC138-decoder/demultiplexer IC (used for blinking specific `7-segment` display seperately)
//	sbit pin1 = P2^2;
//	sbit pin2 = P2^3;
//	sbit pin3 = P2^4;
//	unsigned int x = 0;


//	void timer0(void) interrupt 1{
//			x++;
//		
//			// display__0
//			if (x==1){
//			pin1 = 0;
//			pin2 = 0;
//			pin3 = 0;
//	//		LED = 0xFF;
//	//		led1 = ~led1;
//			}
//				
//			if (x==2){
//			//  display__1
//			pin1 = 1;
//			pin2 = 0;
//			pin3 = 0;
//	//		LED = 0xFF;
//			}
//			
//			if (x==3){
//			//  display__2
//			pin1 = 0;
//			pin2 = 1;
//			pin3 = 0;
//	//		LED = 0xFF;
//			}
//			
//			if (x==4){
//			//  display__3
//			pin1 = 1;
//			pin2 = 1;
//			pin3 = 0;
//	//		LED = 0xFF;
//			}
//			
//			if (x==5){
//			//  display__4
//			pin1 = 0;
//			pin2 = 0;
//			pin3 = 1;
//	//		LED = 0xFF;
//			}
//			
//			if (x==6){
//			//  display__5
//			pin1 = 1;
//			pin2 = 0;
//			pin3 = 1;
//	//		LED = 0xFF;
//			}
//			
//			if (x==7){
//			//  display__6
//			pin1 = 0;
//			pin2 = 1;
//			pin3 = 1;
//	//		LED = 0xFF;
//			}
//			
//			if (x==8){
//			//  display__7
//			pin1 = 1;
//			pin2 = 1;
//			pin3 = 1;
//	//		LED = 0xFF;
//			x=0;
//			}
//	}



//	void main(){
//		 TMOD = 0x02; // 8-bit auto-reload mode
//	//	 TL0=0xFD;
//		 TH0=0x4B;
//		 IE = 0x82;
//		 TR0=1;
//	//	 while (TF0==0);
//	//	 TR0=1;
//	//	 TF0=1;
//		
//		while (1){
//		// ..
//		}
//	}

//	 













#include <reg52.h>
sbit LED = P2^2;
unsigned int x = 0;

void timer0(void) interrupt 1{
		LED = ~LED;
		x=0;

}

void main(){
	 TMOD = 0x01; // 16-bit non_auto-reload mode
	 TL0=0xDB;
	 TH0=0xFF;
	 IE = 0x82;
	 TR0=1;
			IE0 =1;
	IT0 = 1;
	//	while (TF0==0);
	//TF0=0;
	while (1){
	// ..
	}
}

 

