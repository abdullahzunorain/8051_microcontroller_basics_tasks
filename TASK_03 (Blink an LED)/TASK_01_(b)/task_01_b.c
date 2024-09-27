
#include <reg52.h>

#define LED_PORT P2

void msdelay(signed int);

void main(void) {
    while(1) 
			{
        LED_PORT = 0xFF;
        msdelay(505);
				LED_PORT = LED_PORT & 0xFE;
        msdelay(505);
			}
}

void msdelay(signed int X) {
    unsigned int i, j;
    for (i = 0; i < X; i++)
        for (j = 0; j < 113; j++);  // Adjust this value for your specific delay requirement
}

