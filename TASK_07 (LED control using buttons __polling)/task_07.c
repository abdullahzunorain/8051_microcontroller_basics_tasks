#include <reg52.h>
// button's
sbit btn0 = P3^1;
sbit btn1 = P3^0;
sbit btn2 = P3^2;
sbit btn3 = P3^3;
// led's
sbit led_0 = P2^0;
sbit led_1 = P2^1;
sbit led_2 = P2^2;
sbit led_3 = P2^3;

void msdelay(unsigned int);

void main(){
	while(1){
		if(btn0 == 0){
			led_0 = ~led_0;
			msdelay(250);
		}
		if(btn1 == 0){
			led_1 = ~led_1;
			msdelay(250);
		}
		if(btn2 == 0){
			led_2 = ~led_2;
			msdelay(250);
		}
		if(btn3 == 0){
			led_3 = ~led_3;
			msdelay(250);
		}
	}
}


void msdelay(unsigned int delay) {
    unsigned int i, j;
    for(i = 0; i < delay; i++)
        for(j = 0; j < 175; j++);
}