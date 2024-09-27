#include <reg52.h>

#define LED_PORT P2

void msdelay(signed int);

void main(void) {
    while(1) {
        LED_PORT = 0xFE; // Set all bits of LED_PORT to 1
        msdelay(505);    // Delay for 500 milliseconds
				LED_PORT = 0xFF;
//        LED_PORT = LED_PORT & 0xEF; // Set the least significant bit of LED_PORT to 1
        msdelay(505);     // Delay for 500 milliseconds
    }
}

void msdelay(signed int X) {
    unsigned int i, j;
    for (i = 0; i < X; i++)
        for (j = 0; j < 113; j++);  // Adjust this value for your specific delay requirement
}

