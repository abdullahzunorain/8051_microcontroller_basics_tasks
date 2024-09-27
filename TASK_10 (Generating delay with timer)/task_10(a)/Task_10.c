#include <reg52.h>
sbit led1 = P2^0;   // defining a bit(led)
sbit led2 = P2^1;
sbit led3 = P2^2;

void timer0_isr() interrupt 1 {
	unsigned int x, y, z;   // declaring a variable  ( unsigned int datatypes starts from `0`)
	x++;
	y++;
	z++;
	if(x==160){
		led1 = ~led1;
		x=0;
	}
	if(y==1600){
		led2 = ~led2;
		y=0;
	}
	if(z==16000){
		led3 = ~led3;
		z=0;
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