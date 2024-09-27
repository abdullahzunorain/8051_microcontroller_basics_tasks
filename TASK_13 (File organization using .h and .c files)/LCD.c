#include "LCD.h"
#include <reg51.h>



void turn_on_led() {
    P2 |= 0x01;  // Set P2.0 to turn on the LED
}



void turn_off_led() {
    P2 &= ~0x01; // Clear P2.0 to turn off the LED
}



void delay() {
	
    unsigned int x, y;
	
    for(x = 0; x < 500; x++){
        for(y = 0; y < 133; y++){
            // Empty loop for delay
        }
    }
		
}