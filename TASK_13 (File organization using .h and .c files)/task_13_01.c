#include "LCD.h"
#include <stdio.h>

int main(){

	while(1){	
		turn_on_led(); // Turn on the LED	
		delay();
		
		turn_off_led(); // Turn off the LED
		delay();		
	}
	
}
