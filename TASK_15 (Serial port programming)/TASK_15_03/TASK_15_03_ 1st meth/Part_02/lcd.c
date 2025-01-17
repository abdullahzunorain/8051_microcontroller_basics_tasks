#include "task_3.h"

// Delay function to create a short delay
void lcd_delay() {
    unsigned int i;
    for (i = 0; i <= 30; i++);
}

// Function to send a command to the LCD
void lcd_cmd(unsigned char cmd) {
    text = cmd;    // Put the command on the data port
    rs = 0;        // Select command register (RS=0)
    rw = 0;        // Select write operation (RW=0)
    en = 1;        // Generate a high-to-low pulse on the enable pin
    lcd_delay();   // Wait for the command to be processed
    en = 0;        // End the enable pulse
}

// Function to send data to the LCD
void lcd_data(unsigned char dat) {
    text = dat;    // Put the data on the data port
    rs = 1;        // Select data register (RS=1)
    rw = 0;        // Select write operation (RW=0)
    en = 1;        // Generate a high-to-low pulse on the enable pin
    lcd_delay();   // Wait for the data to be processed
    en = 0;        // End the enable pulse
}

void show(unsigned char *s) {
    while (*s) {
        lcd_data(*s++);
    }
}


// Function to display a single character on the LCD
void show_char(unsigned char c) {
    lcd_data(c);
}

// Function to initialize the LCD
void lcd_init() {
    lcd_cmd(0x38); // Set LCD to 8-bit mode, 2 lines, 5x7 matrix
    lcd_delay();   // Wait for the command to be processed
    lcd_cmd(0x0C); // Display ON, cursor OFF
    lcd_delay();   // Wait for the command to be processed
    lcd_cmd(0x06); // Entry mode, auto increment with no shift
    lcd_delay();   // Wait for the command to be processed
    lcd_cmd(0x01); // Clear the display
    lcd_delay();   // Wait for the command to be processed
}

// Function to set the cursor position
void lcd_set_cursor(unsigned char row, unsigned char col) {
    unsigned char pos;
    if (row == 0)
        pos = 0x80 + col; // Set cursor position for the first line
    else if (row == 1)
        pos = 0xC0 + col; // Set cursor position for the second line
    lcd_cmd(pos); // Send command to set the cursor position
}

// Function to write data at a specific position
void lcd_write(unsigned char row, unsigned char col, unsigned char dat) {
    lcd_set_cursor(row, col); // Set cursor to specified position
    lcd_data(dat);            // Write data at that position
}

// Function to clear the display
void lcd_clear() {
    lcd_cmd(0x01); // Clear display screen
    lcd_delay();   // Wait for the command to be processed
}