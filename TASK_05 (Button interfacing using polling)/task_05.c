
/* Task 5 : Button interfacing using polling;
Write a C program to read the button state using polling. If button K1 is pressed it should turn on 
LED D1. If pressed again it should turn off the LED D1. Add debouncing in the code so one button 
press is detected only once. This should continue in a loop. 
 */

#include <reg52.h>

sbit led_1 = P2^0;
sbit button = P3^1;

void delay(unsigned int milliseconds) {
    unsigned int i, j;
    for(i = 0; i < milliseconds; i++)
        for(j = 0; j < 125; j++);  // Delay approximation for 1 ms
}

void main(void) {

    while(1) {
        if(button == 0) {
            delay(20); // Debounce delay
            if(button == 1) {
                led_1 = !led_1; // Toggle LED state
                while(button == 1); // Wait for button release
                delay(20); // Debounce delay for button release
            }
        }
    }
}





// Task_05:  If button K1 is pressed it should turn on LED D1. If pressed again it should turn off the LED D1.

/*

#include <reg52.h>
sbit B1 = P3^1;
sbit D1 = P2^0;

void msdelay(unsigned int m_sec);

void main (){
	while(1){
		if(B1 == 1){
			msdelay(50);
			if(B1 == 1){
					D1 = ~D1;
				}
			while(B1==1){
					msdelay(50);
				}
		}
	}
}
	


void msdelay(unsigned int m_sec){
	unsigned int i, j;
	for (i=0; i<m_sec; i++)
		for(j=0; j<15; j++);
}

*/



// Task # 05:  If button K1 is pressed it should turn on LED D1. If pressed again it should turn off the LED D1.
// but if button is pressed for more than the delay time & kept pressed, so it will be toggles.

/*

# include <reg52.h>
sbit k1 = P3^1;
sbit d1 = P2^0;

void delay(unsigned int milliseconds) {
    unsigned int i, j;
    for(i = 0; i < milliseconds; i++)
        for(j = 0; j < 1275; j++);  // Delay approximation for 1 ms
}

void main(){
	while(1){
	if (k1==0)
	{
		delay(10);
		d1 = !d1;
		while(k1==1);
		delay(10);
	}
}
}


*/