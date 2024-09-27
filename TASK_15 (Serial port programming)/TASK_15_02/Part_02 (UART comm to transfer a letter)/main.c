/*
write a C program for 8051 to transfer the letter "C" serially at 
9600 baud continuously. Use 8-bit data and 1 stop bit.
*/



#include <reg51.h>

void delay(){
	unsigned int i;
	for(i=0; i<=70; i++);
}

void main(void) {
    TMOD = 0x20; // Timer1 in mode 2, 8-bit auto-reload
    TH1 = 0xFD;  // Load TH1 to set baud rate to 9600 (11.0592 MHz clock)
    SCON = 0x50; // 8-bit data, 1 stop bit, REN enabled
    TR1 = 1;     // Start Timer 1
    
    while (1) {
        SBUF = "C\n\r"; // Load 'A' into serial buffer
        while (TI == 0); // Wait for transmission to complete
        TI = 0; // Clear the transmit interrupt flag
			  delay();
    }
}
