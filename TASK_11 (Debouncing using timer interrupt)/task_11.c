#include <reg52.h>

sbit k1_btn = P3^0;
sbit LED = P2^0;

//#################################///////////
unsigned char k1_btn_state = 0;       ///////
unsigned char k1_press_cntr = 0;     ///////
unsigned char k1_release_cntr = 0;  ///////
//#################################///////


void timer0_isr() interrupt 1 {
   TH0 = 0x4C;
   TL0 = 0x00;

   if (k1_btn_state == 0) {
       if (k1_btn == 0) {
           k1_press_cntr++;
           if (k1_press_cntr == 10) {
               LED = ~LED;
               k1_btn_state = 1;
							 }
       }
			 
			 else {
           k1_press_cntr = 0;
       }
   }
	 
	 
	 else {
       if (k1_btn == 1) {
           k1_release_cntr++;
           if (k1_release_cntr == 10) {
               k1_btn_state = 0;
           }
       } else {
           k1_release_cntr = 0;
       }
   }
	 
	 
}

void main() {
   TMOD = 0x01;
   TH0 = 0x4C;
   TL0 = 0x00;
   TR0 = 1;
   ET0 = 1;
   EA = 1;

   while (1) {
       // Other tasks can be performed here
   }
}