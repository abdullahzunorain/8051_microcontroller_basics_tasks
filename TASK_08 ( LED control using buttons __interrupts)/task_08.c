/*
Task 8 : LED control using buttons (external interrupts);

Interface buttons K1 to K4 such that buttons K1-K4 turn ON/OFF LEDs D1-D4 
using interrupts when available and polling if interrupt is not available. 
K1 should control D1, K2 should control D2 and so on. Use debouncing as well. 
*/


#include <reg52.h>
// button's
sbit btn0 = P3^1;
sbit btn1 = P3^0;
//sbit btn2 = P3^2;   // interrupt
//sbit btn3 = P3^3;		// interrupt

// led's
sbit led_0 = P2^0;
sbit led_1 = P2^1;
sbit led_2 = P2^2;
sbit led_3 = P2^3;

void MSDelay(unsigned int);

void main(){
  IE = 0x85;
	
	while(1){
		
    // Check if button 0 is pressed
		if(btn0 == 0){
      // Toggle LED 0 state
			led_0 = ~led_0;
      // Wait until button 0 is released before proceeding
			while(btn0 == 0); // check continuously whether the button is pressed or not, it means to keep the state of the toggled LED
      // Introduce a delay for debouncing
			MSDelay(250);
		}
		
		if(btn1 == 0){
			led_1 = ~led_1;
			while(btn1 == 0);
			MSDelay(250);
		}
}
}

void external_int0() interrupt 0
{
	led_2=~led_2;
	MSDelay(250);
}

void external_int1() interrupt 2
{
	led_3=~led_3;
	MSDelay(250);
}

void MSDelay(unsigned int itime) {
    unsigned int i, j;
    for(i = 0; i < itime; i++)
        for(j = 0; j<114; j++);
}