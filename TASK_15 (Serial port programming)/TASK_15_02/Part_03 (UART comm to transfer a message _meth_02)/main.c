//		// Write an 8051 C program to transfer the message "YES" serially at 9600 baud, 8-bit data, 1 stop bit. Do this continuously

//		#include <reg51.h>
//		void delay(){
//			unsigned int i;
//			for(i=0; i<=7000; i++);
//		}

//		void SerTx(unsigned char);
//		void main(void)
//		{
//				TMOD=0x20;          // use Timer 1, mode 2
//				TH1=0xFD;           // 9600 baud rate
//				SCON=0x50;
//				TR1=1;              // start timer
//				
//			while (1) {
//						SerTx('Y');
//						SerTx('E');
//						SerTx('S');
//					
//						SerTx('L');
//						SerTx('O');
//						SerTx('L');
//					
//						SerTx('\n');     // Newline character
//						SerTx('\r');     // Carriage return character
//				}
//		}

//		void SerTx(unsigned char x)
//		{
//				SBUF=x;             // place value in buffer
//				while (TI==0);      // wait until transmitted
//				TI=0;
//				delay();
//		}







// Write an 8051 C program to transfer the message "YES" serially at 9600 baud, 8-bit data, 1 stop bit. Do this continuously

#include <reg51.h>
void delay(){
	unsigned int i;
	for(i=0; i<=7000; i++);
}

void SerTx(unsigned char);
void main(void)
{
		TMOD=0x20;          // use Timer 1, mode 2
		TH1=0xFD;           // 9600 baud rate
		SCON=0x50;
		TR1=1;              // start timer
		
	while (1) {
				SerTx('Y');
				SerTx('E');
				SerTx('S');
			
				SerTx('L');
				SerTx('O');
				SerTx('L');
			
				SerTx('\n');     // Newline character
				SerTx('\r');     // Carriage return character
		}
}

void SerTx(unsigned char x)
{
		SBUF=x;             // place value in buffer
		while (TI==0);      // wait until transmitted
		TI=0;
		delay();
}
