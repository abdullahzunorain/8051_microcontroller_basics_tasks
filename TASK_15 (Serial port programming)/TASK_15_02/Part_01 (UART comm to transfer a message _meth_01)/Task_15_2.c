/*
TASK_15_02:
Write a program to send data to PC from the microcontroller using serial port at 9600 baud rate. 
Send any message like “Hello world”. Use \n\r to see how it takes the cursor to a new 
line on the Hercules software e.g “Hello world\n\r”
*/


/*
//To write a program that sends data from a microcontroller to a PC using the serial port at 9600 baud rate, 
//you can use the following C code. This program is designed for the 8051 microcontroller (using the Keil compiler), 
//and it will send the message "Hello world" followed by a newline and carriage return ("\n\r") to a PC. 
//The delay function ensures there is enough time for each character to be transmitted.
*/


/*1st Method:*/

//////		#include <reg51.h>

//////		void delay(unsigned int itime) {
//////				int i, j;
//////				for (i = 0; i < itime; i++) {
//////						for (j = 0; j < 114; j++);
//////				}
//////		}

//////		unsigned int u = 0;

//////		void main() {
//////				unsigned char Mystring[] = "Hello World \n\r";  // The message to be sent

//////				TMOD = 0x20;  // Timer1 in Mode2 (8-bit auto-reload)
//////				TH1 = 0xFD;   // Baud rate 9600 for 11.0592 MHz
//////				SCON = 0x50;  // Serial mode 1, 8-data bit, 1 stop bit, REN enabled
//////				TR1 = 1;      // Start Timer1

//////				for (u = 0; u < 14; u++) {
//////						SBUF = Mystring[u];  // Load the character to SBUF
//////						while (TI == 0);     // Wait until the transmission is complete
//////						TI = 0;              // Clear the TI flag
//////				}

//////				delay(300);  // Wait for a while to ensure transmission is complete
//////		}




//-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------



//	/*2nd Method*/

//	#include <reg51.h>

//	// Delay function
//	void delay(unsigned int itime) {
//			int i, j;
//			for(i = 0; i < itime; i++)
//					for(j = 0; j < 114; j++);
//	}

//	void main() {
//			unsigned char Mystring[] = "Abdullah Zunorain is here \n\r";  // The message to be sent
//			unsigned char u = 0;

//			TMOD = 0x20;  // Timer1 in Mode2 (8-bit auto-reload)
//			TH1 = 0xFD;   // Baud rate 9600 for 11.0592 MHz
//			SCON = 0x50;  // Serial mode 1, 8-data bit, 1 stop bit, REN enabled
//			TR1 = 1;      // Start Timer1

//			while (1) {  // Infinite loop to continuously send the message
//					for(u = 0; Mystring[u] != '\0'; u++) {
//							SBUF = Mystring[u];  // Load character into Serial Buffer
//							while(TI == 0);      // Wait until transmission is complete
//							TI = 0;              // Clear the Transmit Interrupt flag
//					}
//					delay(1000);  // Delay between sending the entire string
//			}
//	}




//--------------------------------------------------------------------------------------------------------------------------------------------------------


/*3rd Method*/

#include <reg51.h>

void serial_init() {
    TMOD = 0x20;  // Timer1 in Mode 2: 8-bit auto-reload mode
    TH1 = 0xFD;   // Load value for 9600 baud rate (assuming 11.0592 MHz clock)
    SCON = 0x50;  // Serial mode 1, 8-data bit, 1 stop bit, receive enabled
    TR1 = 1;      // Start Timer1
}

void serial_write(char c) {
    SBUF = c;     // Load the data into the serial buffer
    while (TI==0);  // Wait until the transmission is complete
    TI = 0;       // Clear the TI flag
}

void serial_write_string(char* str) {
    while (*str) {
        serial_write(*str++);  // Send characters one by one
    }
}

void main() {
	int i;
    serial_init();             // Initialize serial communication
    while (1) {
        serial_write_string("Hello world This is Abdullah Zunorain\n\r");  // Send the message
        for (i = 0; i < 30000; i++);  // Simple delay to avoid flooding the terminal
    }
}




// -----------------------------------------------------------------------------------------------------------------------------------------------------------------





/*
 Function of the Code:
			The code initializes the 8051 microcontroller's UART for serial communication and continuously sends the string "Embetronicx " over the serial port with a delay between each transmission. 
			The delay is created by a simple busy-wait loop.
			
	
		The provided code snippet sends data from the microcontroller to the PC (or any device connected to the microcontroller's serial port). Here’s how it works:
- The `send` function transmits the string "Embetronicx  " from the microcontroller through its serial port.
- The microcontroller’s serial port is configured using the `SCON` register, and the baud rate is set using Timer 1.
- Each character in the string is placed in the `SBUF` register (Serial Buffer), which is then sent out via the serial port.
- The PC or any receiving device connected to the microcontroller’s serial port would receive this data.

In summary, the direction of data flow in this code is from the `microcontroller to the PC`.	
			
*/


//		#include<reg51.h>
//		void send(unsigned char *s)
//		{
//				while(*s) {
//						SBUF=*s++;
//						while(TI==0);
//						TI=0;
//				}
//		}

//		void main()
//		{
//				unsigned int i;
//				SCON=0x50;
//				TMOD=0x20;
//				TH1=TL1=0xfd;
//				TR1=1;
//				while(1) {
//						send("Embetronicx ");
//						for(i=0; i<=35000; i++);
//				}
//		}

