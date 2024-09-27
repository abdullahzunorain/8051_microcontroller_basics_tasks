#ifndef LCD_H
#define LCD_H

#include <reg51.h>

// Define the data port and control pins
#define text P0 

sbit rs = P2^6;  // Register select pin
sbit rw = P2^5;  // Read/Write pin
sbit en = P2^7;  // Enable pin

//// Function prototypes
void lcd_delay();
void delay();
void lcd_cmd(unsigned char a);
void lcd_data(unsigned char b);
void lcd_init();

#endif
