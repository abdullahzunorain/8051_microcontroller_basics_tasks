#include <reg52.h>

int cntr_100ms = 0;         
int cntr_1000ms = 0; 
int flag_100_ms = 0; 
int flag_1000_ms = 0; 

sbit LED_D1 = P2^0;      
sbit LED_D2 = P2^1;      
sbit LED_D3 = P2^2;      
sbit LED_D4 = P2^3;      



void ISR_timer0(void) interrupt 1{  
	cntr_100ms++; 
	cntr_1000ms++; 
		if (cntr_100ms >= 600){
			LED_D1 =~ LED_D1 ;            
			flag_100_ms = 1;            
			cntr_100ms = 0;
		}
  
	  if (cntr_1000ms >= 1500){
			LED_D2 =~ LED_D2;
			cntr_1000ms = 0; 
			flag_1000_ms = 1;
	 }
}
 


void main (void){
	
	EA = 1;    // Global Enable (Enable All)
	ET0 = 1;   // enable Interrupt timer 0
	TMOD = 0x02; // timer_0 , mode_2 -> (8-bit_auto_reload timer)
	TH0 = 0xC6;  // define a value
	TR0 = 1;   // Start timer_0
	
 while(1) 
{ 
	 if(flag_100_ms) { 
				flag_100_ms = 0; 
				LED_D3 = ~LED_D3;
		 } 
 

	 if(flag_1000_ms){ 
				flag_1000_ms = 0; 
				LED_D4 = ~LED_D4; 
	   }
} 
} 