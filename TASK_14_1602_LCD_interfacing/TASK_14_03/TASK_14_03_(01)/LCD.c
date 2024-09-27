

#include "LCD.h"

// Delay function to create a short delay
void delay() {
    int i, j;
    for(i = 0; i < 100; i++) {
        for (j = 0; j < 100; j++);
    }
}


// Define lcd_delay function to create a delay for LCD timing
void lcd_delay() {
    delay();
}


// Function to send a command to the LCD
void lcd_cmd(unsigned char a) {
    text = a;    // Put the command on the data port
    rs = 0;      // Select command register (RS=0)
    rw = 0;      // Select write operation (RW=0)
    en = 1;      // Generate a high-to-low pulse on the enable pin
    lcd_delay(); // Wait for the command to be processed
    en = 0;      // End the enable pulse
}


// Function to send data to the LCD
void lcd_data(unsigned char b) {
    text = b;    // Put the data on the data port
    rs = 1;      // Select data register (RS=1)
    rw = 0;      // Select write operation (RW=0)
    en = 1;      // Generate a high-to-low pulse on the enable pin
    lcd_delay(); // Wait for the data to be processed
    en = 0;      // End the enable pulse
}


// Function to initialize the LCD
void lcd_init() {
    lcd_cmd(0x01); // Clear the display
    delay();       // Wait for the command to be processed
    lcd_cmd(0x38); // Set LCD to 8-bit mode, 2 lines, 5x7 matrix
    delay();       // Wait for the command to be processed
    lcd_cmd(0x0E); // Display ON, cursor ON
    delay();       // Wait for the command to be processed
    lcd_cmd(0x10); // Shift cursor position to the left
    delay();       // Wait for the command to be processed
    lcd_cmd(0x80); // Set cursor position to the beginning of the first line
    delay();       // Wait for the command to be processed
}



























/* ______________________________________________________________________________________________________________________________________________________________________________
Sure! Let's go through this code step by step and explain each part in simple terms. This code is for controlling an LCD display using an 8051 microcontroller.

### Include Header and Define Pins

```c
#include <reg51.h>  // Include the header file for 8051 microcontroller registers and definitions
```
This line includes a header file which contains the definitions for working with the 8051 microcontroller.

```c
sbit rs = P2^6;    // Define the register select pin as bit 6 of port 2
sbit rw = P2^5;    // Define the read/write pin as bit 5 of port 2
sbit en = P2^7;    // Define the enable pin as bit 7 of port 2
```
Here, three special bits (sbit) are defined to control the LCD:
- `rs` (Register Select) on bit 6 of port 2.
- `rw` (Read/Write) on bit 5 of port 2.
- `en` (Enable) on bit 7 of port 2.

These pins help control the LCD by telling it whether we want to send a command, write data, or enable it.

```c
#define text P0    // Define the data port for the LCD as port 0
```
This line defines the entire port 0 (P0) as the data port for sending commands and data to the LCD.

### Delay Functions

```c
void delay() {
    int i, j;
    for(i = 0; i < 100; i++) {
        for (j = 0; j < 100; j++);
    }
}
```
This function creates a small delay. It uses two nested loops to waste time, making sure that operations on the LCD have time to complete.

```c
void lcd_delay() {
    delay();
}
```
This function is just a wrapper around the delay function, specifically named to indicate it's for LCD timing.

### Sending Commands to the LCD

```c
void lcd_cmd(unsigned char a) {
    text = a;    // Put the command on the data port
    rs = 0;      // Select command register (RS=0)
    rw = 0;      // Select write operation (RW=0)
    en = 1;      // Generate a high-to-low pulse on the enable pin
    lcd_delay(); // Wait for the command to be processed
    en = 0;      // End the enable pulse
}
```
This function sends a command to the LCD:
- `text = a;` puts the command data on port 0.
- `rs = 0;` sets the LCD to command mode.
- `rw = 0;` sets the LCD to write mode.
- `en = 1;` sends an enable signal.
- `lcd_delay();` waits for the command to be processed.
- `en = 0;` turns off the enable signal.

### Sending Data to the LCD

```c
void lcd_data(unsigned char b) {
    text = b;    // Put the data on the data port
    rs = 1;      // Select data register (RS=1)
    rw = 0;      // Select write operation (RW=0)
    en = 1;      // Generate a high-to-low pulse on the enable pin
    lcd_delay(); // Wait for the data to be processed
    en = 0;      // End the enable pulse
}
```
This function sends data (characters) to the LCD:
- `text = b;` puts the data on port 0.
- `rs = 1;` sets the LCD to data mode.
- `rw = 0;` sets the LCD to write mode.
- `en = 1;` sends an enable signal.
- `lcd_delay();` waits for the data to be processed.
- `en = 0;` turns off the enable signal.

### Initializing the LCD

```c
void lcd_init() {
    lcd_cmd(0x01); // Clear the display
    delay();       // Wait for the command to be processed
    lcd_cmd(0x38); // Set LCD to 8-bit mode, 2 lines, 5x7 matrix
    delay();       // Wait for the command to be processed
    lcd_cmd(0x0E); // Display ON, cursor ON
    delay();       // Wait for the command to be processed
    lcd_cmd(0x10); // Shift cursor position to the left
    delay();       // Wait for the command to be processed
    lcd_cmd(0x80); // Set cursor position to the beginning of the first line
    delay();       // Wait for the command to be processed
}
```
This function initializes the LCD:
- `lcd_cmd(0x01);` clears the display.
- `lcd_cmd(0x38);` sets the LCD to 8-bit mode, with 2 lines and a 5x7 matrix for characters.
- `lcd_cmd(0x0E);` turns on the display and the cursor.
- `lcd_cmd(0x10);` shifts the cursor to the left.
- `lcd_cmd(0x80);` sets the cursor to the beginning of the first line.

### Main Function

```c
int main() {
    text = 0x00;   // Clear the data port
    lcd_init();    // Initialize the LCD
    
    // Write 'Z' to the LCD
    lcd_data('Z');
    delay();       // Wait for the data to be processed

    // Write 'U' to the LCD
    lcd_data('U');
    delay();       // Wait for the data to be processed

    // Write 'L' to the LCD
    lcd_data('L');
    delay();       // Wait for the data to be processed    
    
    // Write 'Q' to the LCD
    lcd_data('Q');
    delay();       // Wait for the data to be processed

    // Write 'A' to the LCD
    lcd_data('A');
    delay();       // Wait for the data to be processed   

    // Write 'R' to the LCD
    lcd_data('R');
    delay();       // Wait for the data to be processed
    
    // Write 'N' to the LCD
    lcd_data('N');
    delay();       // Wait for the data to be processed    

    // Write 'A' to the LCD
    lcd_data('A');
    delay();       // Wait for the data to be processed    
    
    // Write 'I' to the LCD
    lcd_data('I');
    delay();       // Wait for the data to be processed    
    
    // Write 'N' to the LCD
    lcd_data('N');
    delay();       // Wait for the data to be processed    

    // Return 0 to indicate successful execution
    return 0;        
}
```
The `main` function does the following:
- `text = 0x00;` clears the data port.
- `lcd_init();` initializes the LCD.
- Then it writes the characters 'Z', 'U', 'L', 'Q', 'A', 'R', 'N', 'A', 'I', and 'N' one by one to the LCD. After each character, it waits for the data to be processed.

### Summary
- **Include necessary headers and define control pins.**
- **Create delay functions to allow time for LCD operations.**
- **Functions to send commands and data to the LCD.**
- **Initialize the LCD to prepare it for displaying characters.**
- **In the main function, clear the data port, initialize the LCD, and display the word "ZULQARNAIN" on the LCD.**

This step-by-step process ensures that the LCD is correctly set up and displays the intended characters.
______________________________________________________________________________________________________________________________________________________________________________
*/