
#include <reg52.h>
sbit led = P2^0;   // defining a bit(led)
unsigned int x;    // declaring a variable

void timer0_isr() interrupt 1 {
	x++;
	if(x==160){
		led = ~led;
		x=0;
	}
}
           
void main() {
	EA = 1;    // Global Enable (Enable All)
	ET0 = 1;   // enable Interrupt timer 0
	TMOD = 0x02; // timer_0 , mode_2 -> (8-bit_auto_reload timer)
	TH0 = 0xC6;  // define a value
	TR0 = 1;   // Start timer_0

    while (1) {
        // Your main code here (if any)
    }
}














//////////#include <reg52.h>

//////////sbit led_1 = P2^0;

//////////void Timer_0() interrupt 1 {
//////////	unsigned char x,y;
//////////	
//////////	for (x=0;x<41;x++)
//////////		for (y=0;y<36;y++);
//////////	
//////////	led_1 = ~led_1;      // Toggle LED
//////////}

//////////void main() {
//////////  IE = 0x82;           // Enable Timer 0 interrupt
//////////  TMOD = 0x02;         // Set Timer 0 mode to 8-bit auto reload
//////////  TH0 = -27;           // Set initial value for Timer 0 high byte
//////////  TR0=1;
//////////}