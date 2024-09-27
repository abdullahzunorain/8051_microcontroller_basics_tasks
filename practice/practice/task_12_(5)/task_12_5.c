////#include <reg52.h>

////sbit led1 = P2^0;
////sbit led8 = P2^7;
////sbit led7 = P2^6;

////sbit pin1 = P2^2;
////sbit pin2 = P2^3;
////sbit pin3 = P2^4;
////unsigned int x = 0;


////void timer0(void) interrupt 1{
////		led1 = ~led1;
////		x++;
////		led8 = ~led8;
////	
////		// display__0
////	  if (x==1){
////		pin1 = 0;
////		pin2 = 0;
////		pin3 = 0;
////		led7 = ~led7;
//////		LED = 0xFF;
//////		led1 = ~led1;
////	  }
////			
////  	if (x==2){
////		//  display__1
////		pin1 = 1;
////		pin2 = 0;
////		pin3 = 0;
//////		LED = 0xFF;
////		}
////		
////		if (x==3){
////		//  display__2
////		pin1 = 0;
////		pin2 = 1;
////		pin3 = 0;
//////		LED = 0xFF;
////		}
////		
////		if (x==4){
////		//  display__3
////		pin1 = 1;
////		pin2 = 1;
////		pin3 = 0;
//////		LED = 0xFF;
////		}
////		
////		if (x==5){
////		//  display__4
////		pin1 = 0;
////		pin2 = 0;
////		pin3 = 1;
//////		LED = 0xFF;
////		}
////		
////		if (x==6){
////		//  display__5
////		pin1 = 1;
////		pin2 = 0;
////		pin3 = 1;
//////		LED = 0xFF;
////		}
////		
////		if (x==7){
////		//  display__6
////		pin1 = 0;
////		pin2 = 1;
////		pin3 = 1;
//////		LED = 0xFF;
////		}
////		
////		if (x==8){
////		//  display__7
////		pin1 = 1;
////		pin2 = 1;
////		pin3 = 1;
//////		LED = 0xFF;
////		x=0;
////		}
////}




////void timer(){
////	TMOD = 0x01; // 16-bit non-auto reload mode
////	 TL0=0xFF;
////	 TH0=0xDB;
////	 IE = 0x82;
////	 TR0=1;
////	 while (TF0==0);
////	 TR0=0;
////	 TF0=0;
////}

////void main(){
////	void timer();
////	
//////	while (1){
//////	//....
//////	} 
////}









////////void msdelay(void){
////////	TMOD = 0x01; // 16-bit non-auto reload mode
////////	 TL0=0xFD;
////////	 TH0=0x4B;
////////	 TR0=1;
////////	 while (TF0==0);
////////	 TR0=0;
////////	 TF0=0;
////////}






//// -------------------------------------------------------------------------------------------------------------------------------------------------------------
//////  	if (x==2){
//////		//  display__1
//////		pin1 = 1;
//////		pin2 = 0;
//////		pin3 = 0;
////////		LED = 0xFF;
//////		}
//////		
//////		if (x==3){
//////		//  display__2
//////		pin1 = 0;
//////		pin2 = 1;
//////		pin3 = 0;
////////		LED = 0xFF;
//////		}
//////		
//////		if (x==4){
//////		//  display__3
//////		pin1 = 1;
//////		pin2 = 1;
//////		pin3 = 0;
////////		LED = 0xFF;
//////		}
//////		
//////		if (x==5){
//////		//  display__4
//////		pin1 = 0;
//////		pin2 = 0;
//////		pin3 = 1;
////////		LED = 0xFF;
//////		}
//////		
//////		if (x==6){
//////		//  display__5
//////		pin1 = 1;
//////		pin2 = 0;
//////		pin3 = 1;
////////		LED = 0xFF;
//////		}
//////		
//////		if (x==7){
//////		//  display__6
//////		pin1 = 0;   
//////		pin2 = 1;
//////		pin3 = 1;
////////		LED = 0xFF;
//////		}
//////		

















//// -------------------------------------------------


//#include<reg51.h>

//// define the input pins for LEDs
//sbit A0=P2^2;
//sbit A1=P2^3;
//sbit A2=P2^4;

//sbit led1 =P2^0;
// 
//void Timer0_delay()  // define function for delay of 65usec(maximum delay of timer)
//{
//	TMOD = 0x01;      // select timer_1 mode_1
//	TL1 = 0xCA;       // calculation for delay of 60msec NOTED
//	TH1 = 0xFF;
//	TR1 = 1;         // Timer ON
//	while(TF1==0);  // Run the LOOP untill the overflow occure
//	TR1=0;          // Turn OFF the Timer
//	TF1=0;          // Clear the Flag
//}



//void main(void)
//{ 
//	unsigned int i; 
//		led1 = ~led1;
//	for(i=0; i<232; i++)  // call the timer 8333 times for delay of 500ms
//	{
//		
//		Timer0_delay();
//	}
//	
//	
////	A2=1;A1=1;A0=1;        // Turn ON the LED_01
////	for(i=0; i<8333; i++)  // call the timer 8333 times for delay of 500ms
////	{
////		Timer0_delay();
////	}
////	 
////	A2=1;A1=1;A0=0;      // Turn ON the LED_02.  74hc138 decoder is used to turn ON  the LEDs 
////	for(i=0; i<8333; i++)
////	{
////		Timer0_delay();
////	}
////		A2=1;A1=0;A0=1;     // Turn ON the LED_03.  74hc138 decoder is used to turn ON  the LEDs
////	for(i=0; i<8333; i++)
////	{
////		Timer0_delay();
////	}
////	
////	A2=1;A1=0;A0=0;      // Turn ON the LED_04.  74hc138 decoder is used to turn ON  the LEDs
////	for(i=0; i<8333; i++)
////	{
////		Timer0_delay();
////	}
////		A2=0;A1=1;A0=1;   // Turn ON the LED_05.  74hc138 decoder is used to turn ON  the LEDs
////	for(i=0; i<8333; i++)
////	{
////		Timer0_delay();
////	}
////	
////	A2=0;A1=1;A0=0;    // Turn ON the LED_06.  74hc138 decoder is used to turn ON  the LEDs
////	for(i=0; i<8333; i++)
////	{
////		Timer0_delay();
////	}
////		A2=0;A1=0;A0=1;     // Turn ON the LED_07.  74hc138 decoder is used to turn ON  the LEDs
////	for(i=0; i<8333; i++)
////	{
////		Timer0_delay();
////	}
////	
////	A2=0;A1=0;A0=0;     // Turn ON the LED_02.  74hc138 decoder is used to turn ON  the LEDs
////	for(i=0; i<8333; i++)
////	{
////		Timer0_delay();
////	}

//	while(1){
////	led1 = ~led1;
////	Timer0_delay();
//	}

//}