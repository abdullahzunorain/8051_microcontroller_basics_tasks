
//			/*
//			Sending character/text from PC to Microcontroller
//			*/


//	#include <reg51.h>

//	void UART_Init() {
//			TMOD = 0x20;    /* Timer 1, 8-bit auto reload mode */
//			TH1 = 0xFD;     /* Load value for 9600 baud rate */
//			SCON = 0x50;    /* Mode 1, 8-bit data, reception enable */
//			TR1 = 1;        /* Start timer 1 */
//	}

//	void Transmit_data(char tx_data) {
//			SBUF = tx_data;    /* Load char in SBUF register */
//			while (TI == 0);   /* Wait until stop bit transmit */
//			TI = 0;            /* Clear TI flag */
//	}

//	void main() {
//			char received_char;
//			UART_Init();    /* UART initialize function */

//			while (1) {
//					if (RI) {  /* Check if data received */
//							received_char = SBUF;  /* Read the received character */
//							RI = 0;  /* Clear the receive interrupt flag */

//							if (received_char == '\r') { /* Check if carriage return received */
//									/* Message terminated, do something with the received message */
//									// For now, let's just echo the received message back to PC
//									Transmit_data('\r');  /* Send carriage return to PC */
//									Transmit_data('\n');  /* Send newline to PC */
//							} else {
//									/* Received character, do something with it */
//									Transmit_data(received_char);  /* Echo the received character back to PC */
//							}
//					}
//			}
//	}







//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------






////		// Sending character/text from PC to Microcontroller

//#include <reg51.h>

//void UART_Init() {
//		TMOD = 0x20;    /* Timer 1, 8-bit auto reload mode */
//		TH1 = 0xFD;     /* Load value for 9600 baud rate */
//		SCON = 0x50;    /* Mode 1, 8-bit data, reception enable */
//		TR1 = 1;        /* Start timer 1 */
//}

//void Transmit_data(char tx_data) {
//		SBUF = tx_data;    /* Load char in SBUF register */
//		while (TI == 0);   /* Wait until stop bit transmit */
//		TI = 0;            /* Clear TI flag */
//}

//void main() {
//		char received_char;
//		char message_buffer[100];
//		int index = 0;
//		int i;  // Declare loop variable outside the for loop

//		UART_Init();    /* UART initialize function */

//		while (1) {
//				if (RI) {  /* Check if data received */
//						received_char = SBUF;  /* Read the received character */
//						RI = 0;  /* Clear the receive interrupt flag */

//						if (received_char == '\n') {
//								message_buffer[index++] = received_char;  /* Store received character in buffer */
//						} else if (received_char == '\r') {
//								message_buffer[index] = '\0';  /* Terminate the message string */

//								/* Message terminated, do something with the received message */
//								/* For now, let's just echo the received message back to PC */
//								for (i = 0; i < index; i++) {
//										Transmit_data(message_buffer[i]);  /* Echo each character */
//								}
//								Transmit_data('\r');  /* Send carriage return to PC */
//								Transmit_data('\n');  /* Send newline to PC */

//								index = 0;  /* Reset buffer index for next message */
//						} else {
//								message_buffer[index++] = received_char;  /* Store received character in buffer */
//						}
//				}
//		}
//}




















// ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------






#include<reg51.h>
#include<stdio.h>
#include <stdio.h>
#include <string.h>

#define LCD_Port P0				/* P2 port as data_port */
sbit rs=P2^6;							/* Register select pin */
sbit rw=P2^5;							/* Read/Write pin */
sbit en=P2^7;							/* Enable pin */
unsigned char i;
unsigned char k;
char Mystring[];
char string[15 + 1];


void delay(unsigned int count)    			/* Function to provide delay Approx 1ms with 12 Mhz crystal*/
{
     int i,j;
     for(i=0;i<count;i++)
     for(j=0;j<114;j++);
}

void LCD_Cmd (char f)										/* LCD16x2 command funtion */
{
	LCD_Port = f;	/* Send upper nibble */
	rs=0;																					/* Command reg. */
	rw=0;																					/* Write operation */
	en=1; 
	delay(1);
	en=0;
	delay(2);
}

void LCD_dat (char d)  										/* 	LCD_data write function */
{

	LCD_Port  = d;/*  Send upper nibble */
	rs=1;  																						/*	Data reg.*/
	rw=0;  																						/*Write operation*/
	en=1;  
	delay(1);
	en=0;
	delay(2);
}

void LCD_String (char *str)					/* Send string to LCD function */
{
	int i;
	for(i=0;str[i]!=0;i++)  					/* Send each character of string till the NULL */
	{
		LCD_dat (str[i]); 							/* Call LCD_data write */
	}
}

//void LCD_String_xy (char row, char pos, char *str)  /* Send string to LCD function */
//{
//	if (row == 0)
//	LCD_Cmd((pos & 0x0F)|0x80);
//	else if (row == 1)
//	LCD_Cmd((pos & 0x0F)|0xC0);
//	LCD_String(str);  																/* Call LCD string function */
//}

void LCD_Init (void)								/* LCD Initialize function */
{	
	delay(20);		/* LCD Power ON Initialization time >15ms */
	LCD_Cmd (0x38);	/* Initialization of 16X2 LCD in 8bit mode */
	LCD_Cmd (0x0C);	/* Display ON Cursor OFF */
	LCD_Cmd (0x06);	/* Auto Increment cursor */
	LCD_Cmd (0x01);	/* clear display */
	LCD_Cmd (0x80);	/* cursor at home position */
}

void cnvrt_array_int_string(char charArray[]){
	// Convert the character array into a string by adding a null terminator
    strncpy(string, charArray, 15);
    string[16] = '\0';  // Null-terminate the string
}

void main()
{
LCD_Init();	

	TMOD=0x20;
	TH1=0xFD; 
	SCON=0x50;
	PCON=0x00;
	TR1=1;
	while(1)
	{
	for(i=0;i<16;i++)
		{ 
			while(RI==0);
			RI = 0;
			Mystring[i] = SBUF;
		}
		 cnvrt_array_int_string(Mystring);
		LCD_String(string);
//		LCD_String("abdullah");
}
}




