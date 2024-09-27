#include <reg52.h>

#define LED_PORT P2
#define BIT0 0xFF 
#define BIT1 0x02 
#define BIT2 0x04 
#define BIT3 0x08 
#define BIT4 0x10 
#define BIT5 0x20 
#define BIT6 0xFE

void msdelay(signed int);

void main(void) {
    while(1) 
			{
        LED_PORT = BIT0;
        msdelay(505);
				LED_PORT = BIT0 & BIT6;
        msdelay(505);
			}
}

void msdelay(signed int X) {
    unsigned int i, j;
    for (i = 0; i < X; i++)
        for (j = 0; j < 113; j++);  // Adjust this value for your specific delay requirement
}

