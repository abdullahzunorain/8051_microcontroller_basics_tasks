




////#include <reg51.h>  // Include header file for 8051 microcontroller

////#define lcd_data P0  // Define lcd_data as Port 0 for data lines of the LCD

////// Define individual bits for control lines connected to Port 2
////sbit rs = P2^6;  // Register Select (RS) pin at P2.6
////sbit rw = P2^5;  // Read/Write (RW) pin at P2.5
////sbit en = P2^7;  // Enable (EN) pin at P2.7

////// Function prototypes
////void lcd_delay();
////void lcd_init();
////void cmd(unsigned char a);
////void dat(unsigned char b);
////void show(unsigned char *s);
////void store();

////// Function to introduce a delay for LCD operations
////void lcd_delay() {
////    unsigned int lcd_delay;
////    for(lcd_delay = 0; lcd_delay <= 6000; lcd_delay++);  // Simple for-loop delay
////}

////// Function to initialize the LCD
////void lcd_init() {
////    cmd(0x38);  // Command for 2 lines and 5x7 matrix
////    cmd(0x0c);  // Display on, cursor off
////    cmd(0x06);  // Increment cursor
////    cmd(0x01);  // Clear display screen
////    cmd(0x80);  // Force cursor to beginning of first line
////}

////// Function to send a command to the LCD
////void cmd(unsigned char a) {
////    lcd_data = a;  // Put command on data port
////    rs = 0;  // Select command register
////    rw = 0;  // Write operation
////    en = 1;  // Enable the LCD
////    lcd_delay();  // Wait for the command to be processed
////    en = 0;  // Disable the LCD
////}

////// Function to send data to the LCD
////void dat(unsigned char b) {
////    lcd_data = b;  // Put data on data port
////    rs = 1;  // Select data register
////    rw = 0;  // Write operation
////    en = 1;  // Enable the LCD
////    lcd_delay();  // Wait for the data to be processed
////    en = 0;  // Disable the LCD
////}

////// Function to display a string on the LCD
////void show(unsigned char *s) {
////    while(*s) {  // Loop through each character in the string
////        dat(*s++);  // Send each character to the LCD
////    }
////}

////// Function to store custom characters in CGRAM
////void store() {
////    // Store custom character at location 0
////    cmd(64);  // Set CGRAM address to 0x40
////    dat(0);  // First row of custom character
////    dat(10);  // Second row of custom character
////    dat(21);  // Third row of custom character
////    dat(17);  // Fourth row of custom character
////    dat(10);  // Fifth row of custom character
////    dat(4);  // Sixth row of custom character
////    dat(0);  // Seventh row of custom character
////    dat(0);  // Eighth row of custom character
////    cmd(0xc0); // Move to DDRAM address 0xC0 (second line)
////    dat(0);  // Display custom character stored at location 0
////    lcd_delay();

////    // Store custom character at location 1
////    cmd(72);  // Set CGRAM address to 0x48
////    dat(4);  // First row of custom character
////    dat(14);  // Second row of custom character
////    dat(14);  // Third row of custom character
////    dat(14);  // Fourth row of custom character
////    dat(31);  // Fifth row of custom character
////    dat(0);  // Sixth row of custom character
////    dat(4);  // Seventh row of custom character
////    dat(0);  // Eighth row of custom character
////    cmd(0xc2); // Move to DDRAM address 0xC2
////    dat(1);  // Display custom character stored at location 1
////    lcd_delay();

////    // Store custom character at location 2
////    cmd(80);  // Set CGRAM address to 0x50
////    dat(31);  // First row of custom character
////    dat(21);  // Second row of custom character
////    dat(31);  // Third row of custom character
////    dat(31);  // Fourth row of custom character
////    dat(14);  // Fifth row of custom character
////    dat(10);  // Sixth row of custom character
////    dat(27);  // Seventh row of custom character
////    dat(0);  // Eighth row of custom character
////    cmd(0xc4); // Move to DDRAM address 0xC4
////    dat(2);  // Display custom character stored at location 2
////    lcd_delay();

////    // Store custom character at location 3
////    cmd(88);  // Set CGRAM address to 0x58
////    dat(0);  // First row of custom character
////    dat(1);  // Second row of custom character
////    dat(3);  // Third row of custom character
////    dat(22);  // Fourth row of custom character
////    dat(28);  // Fifth row of custom character
////    dat(8);  // Sixth row of custom character
////    dat(0);  // Seventh row of custom character
////    dat(0);  // Eighth row of custom character
////    cmd(0xc6); // Move to DDRAM address 0xC6
////    dat(3);  // Display custom character stored at location 3
////    lcd_delay();

////    // Store custom character at location 4
////    cmd(96);  // Set CGRAM address to 0x60
////    dat(1);  // First row of custom character
////    dat(3);  // Second row of custom character
////    dat(15);  // Third row of custom character
////    dat(15);  // Fourth row of custom character
////    dat(15);  // Fifth row of custom character
////    dat(3);  // Sixth row of custom character
////    dat(1);  // Seventh row of custom character
////    dat(0);  // Eighth row of custom character
////    cmd(0xc8); // Move to DDRAM address 0xC8
////    dat(4);  // Display custom character stored at location 4
////    lcd_delay();

////    // Store custom character at location 5
////    cmd(104);  // Set CGRAM address to 0x68
////    dat(1);  // First row of custom character
////    dat(3);  // Second row of custom character
////    dat(5);  // Third row of custom character
////    dat(9);  // Fourth row of custom character
////    dat(9);  // Fifth row of custom character
////    dat(11);  // Sixth row of custom character
////    dat(27);  // Seventh row of custom character
////    dat(24);  // Eighth row of custom character
////    cmd(0xca); // Move to DDRAM address 0xCA
////    dat(5);  // Display custom character stored at location 5
////    lcd_delay();

////    // Store custom character at location 6
////    cmd(112);  // Set CGRAM address to 0x70
////    dat(0);  // First row of custom character
////    dat(14);  // Second row of custom character
////    dat(21);  // Third row of custom character
////    dat(27);  // Fourth row of custom character
////    dat(14);  // Fifth row of custom character
////    dat(14);  // Sixth row of custom character
////    dat(0);  // Seventh row of custom character
////    dat(0);  // Eighth row of custom character
////    cmd(0xcc); // Move to DDRAM address 0xCC
////    dat(6);  // Display custom character stored at location 6
////    lcd_delay();

////    // Store custom character at location 7
////    cmd(120);  // Set CGRAM address to 0x78
////    dat(14);  // First row of custom character
////    dat(17);  // Second row of custom character
////    dat(17);  // Third row of custom character
////    dat(31);  // Fourth row of custom character
////    dat(27);  // Fifth row of custom character
////    dat(27);  // Sixth row of custom character
////    dat(31);  // Seventh row of custom character
////    dat(0);  // Eighth row of custom character
////    cmd(0xce); // Move to DDRAM address 0xCE
////    dat(7);  // Display custom character stored at location 7
////    lcd_delay();
////}

////// Main function
////void main() {
////    lcd_init();  // Initialize the LCD
////    show("CUSTOM CHARACTER");  // Display the string "CUSTOM CHARACTER"
////    while(1) {  // Infinite loop
////        store();  // Continuously store and display custom characters
////    }
////}




//----------------------------------------------------------------------------------------------------------------------------------------------------





#include <reg51.h>  // Include header file for 8051 microcontroller

#define lcd_data P0  // Define lcd_data as Port 0 for data lines of the LCD

// Define individual bits for control lines connected to Port 2
sbit rs = P2^6;  // Register Select (RS) pin at P2.6
sbit rw = P2^5;  // Read/Write (RW) pin at P2.5
sbit en = P2^7;  // Enable (EN) pin at P2.7

// Function prototypes
void lcd_delay();
void lcd_init();
void cmd(unsigned char a);
void dat(unsigned char b);
void show(unsigned char *s);
void store();

// Function to introduce a delay for LCD operations
void lcd_delay() {
    unsigned int lcd_delay;
    for(lcd_delay = 0; lcd_delay <= 6000; lcd_delay++);  // Simple for-loop delay
}

// Function to initialize the LCD
void lcd_init() {
    cmd(0x38);  // Command for 2 lines and 5x7 matrix
    cmd(0x0c);  // Display on, cursor off
    cmd(0x06);  // Increment cursor
    cmd(0x01);  // Clear display screen
    cmd(0x80);  // Force cursor to beginning of first line
}

// Function to send a command to the LCD
void cmd(unsigned char a) {
    lcd_data = a;  // Put command on data port
    rs = 0;  // Select command register
    rw = 0;  // Write operation
    en = 1;  // Enable the LCD
    lcd_delay();  // Wait for the command to be processed
    en = 0;  // Disable the LCD
}

// Function to send data to the LCD
void dat(unsigned char b) {
    lcd_data = b;  // Put data on data port
    rs = 1;  // Select data register
    rw = 0;  // Write operation
    en = 1;  // Enable the LCD
    lcd_delay();  // Wait for the data to be processed
    en = 0;  // Disable the LCD
}

// Function to display a string on the LCD
void show(unsigned char *s) {
    while(*s) {  // Loop through each character in the string
        dat(*s++);  // Send each character to the LCD
    }
}

// Function to store custom characters in CGRAM
void store() {
    // Store custom character at location 0
    cmd(64);  // Set CGRAM address to 0x40
    dat(0);  // First row of custom character
    dat(10);  // Second row of custom character
    dat(21);  // Third row of custom character
    dat(17);  // Fourth row of custom character
    dat(10);  // Fifth row of custom character
    dat(4);  // Sixth row of custom character
    dat(0);  // Seventh row of custom character
    dat(0);  // Eighth row of custom character
    cmd(0xc0); // Move to DDRAM address 0xC0 (second line)
    dat(0);  // Display custom character stored at location 0
    lcd_delay();

    // Store custom character at location 1
    cmd(72);  // Set CGRAM address to 0x48
    dat(4);  // First row of custom character
    dat(14);  // Second row of custom character
    dat(14);  // Third row of custom character
    dat(14);  // Fourth row of custom character
    dat(31);  // Fifth row of custom character
    dat(0);  // Sixth row of custom character
    dat(4);  // Seventh row of custom character
    dat(0);  // Eighth row of custom character
    cmd(0xc1); // Move to DDRAM address 0xC2
    dat(1);  // Display custom character stored at location 1
    lcd_delay();

    // Store custom character at location 2
    cmd(80);  // Set CGRAM address to 0x50
    dat(31);  // First row of custom character
    dat(21);  // Second row of custom character
    dat(31);  // Third row of custom character
    dat(31);  // Fourth row of custom character
    dat(14);  // Fifth row of custom character
    dat(10);  // Sixth row of custom character
    dat(27);  // Seventh row of custom character
    dat(0);  // Eighth row of custom character
    cmd(0xc2); // Move to DDRAM address 0xC4
    dat(2);  // Display custom character stored at location 2
    lcd_delay();

    // Store custom character at location 3
    cmd(88);  // Set CGRAM address to 0x58
    dat(0);  // First row of custom character
    dat(1);  // Second row of custom character
    dat(3);  // Third row of custom character
    dat(22);  // Fourth row of custom character
    dat(28);  // Fifth row of custom character
    dat(8);  // Sixth row of custom character
    dat(0);  // Seventh row of custom character
    dat(0);  // Eighth row of custom character
    cmd(0xc3); // Move to DDRAM address 0xC6
    dat(3);  // Display custom character stored at location 3
    lcd_delay();

    // Store custom character at location 4
    cmd(96);  // Set CGRAM address to 0x60
    dat(1);  // First row of custom character
    dat(3);  // Second row of custom character
    dat(15);  // Third row of custom character
    dat(15);  // Fourth row of custom character
    dat(15);  // Fifth row of custom character
    dat(3);  // Sixth row of custom character
    dat(1);  // Seventh row of custom character
    dat(0);  // Eighth row of custom character
    cmd(0xc4); // Move to DDRAM address 0xC8
    dat(4);  // Display custom character stored at location 4
    lcd_delay();

    // Store custom character at location 5
    cmd(104);  // Set CGRAM address to 0x68
    dat(1);  // First row of custom character
    dat(3);  // Second row of custom character
    dat(5);  // Third row of custom character
    dat(9);  // Fourth row of custom character
    dat(9);  // Fifth row of custom character
    dat(11);  // Sixth row of custom character
    dat(27);  // Seventh row of custom character
    dat(24);  // Eighth row of custom character
    cmd(0xc5); // Move to DDRAM address 0xCA
    dat(5);  // Display custom character stored at location 5
    lcd_delay();

    // Store custom character at location 6
    cmd(112);  // Set CGRAM address to 0x70
    dat(0);  // First row of custom character
    dat(14);  // Second row of custom character
    dat(21);  // Third row of custom character
    dat(27);  // Fourth row of custom character
    dat(14);  // Fifth row of custom character
    dat(14);  // Sixth row of custom character
    dat(0);  // Seventh row of custom character
    dat(0);  // Eighth row of custom character
    cmd(0xc6); // Move to DDRAM address 0xCC
    dat(6);  // Display custom character stored at location 6
    lcd_delay();

    // Store custom character at location 7
    cmd(120);  // Set CGRAM address to 0x78
    dat(14);  // First row of custom character
    dat(17);  // Second row of custom character
    dat(17);  // Third row of custom character
    dat(31);  // Fourth row of custom character
    dat(27);  // Fifth row of custom character
    dat(27);  // Sixth row of custom character
    dat(31);  // Seventh row of custom character
    dat(0);  // Eighth row of custom character
    cmd(0xc7); // Move to DDRAM address 0xCE
    dat(7);  // Display custom character stored at location 7
    lcd_delay();
		
		
}

// Main function
void main() {
    
    while(1) {  // Infinite loop
				lcd_init();  // Initialize the LCD
				show("CUSTOM CHARACTER");  // Display the string "CUSTOM CHARACTER"
        store();  // Continuously store and display custom characters
    }
}











//------------------------------------------------------------------------------------------------------------------------------------------
















//#include <reg51.h>  // Include header file for 8051 microcontroller

//#define lcd_data P0  // Define lcd_data as Port 0 for data lines of the LCD

//// Define individual bits for control lines connected to Port 2
//sbit rs = P2^6;  // Register Select (RS) pin at P2.6
//sbit rw = P2^5;  // Read/Write (RW) pin at P2.5
//sbit en = P2^7;  // Enable (EN) pin at P2.7

//// Function prototypes
//void lcd_delay();
//void lcd_init();
//void cmd(unsigned char a);
//void dat(unsigned char b);
//void show(unsigned char *s);
//void store();

//// Function to introduce a delay for LCD operations
//void lcd_delay() {
//    unsigned int lcd_delay;
//    for(lcd_delay = 0; lcd_delay <= 6000; lcd_delay++);  // Simple for-loop delay
//}

//// Function to initialize the LCD
//void lcd_init() {
//    cmd(0x38);  // Command for 2 lines and 5x7 matrix
//    cmd(0x0c);  // Display on, cursor off
//    cmd(0x06);  // Increment cursor
//    cmd(0x01);  // Clear display screen
//    cmd(0x80);  // Force cursor to beginning of first line
//}

//// Function to send a command to the LCD
//void cmd(unsigned char a) {
//    lcd_data = a;  // Put command on data port
//    rs = 0;  // Select command register
//    rw = 0;  // Write operation
//    en = 1;  // Enable the LCD
//    lcd_delay();  // Wait for the command to be processed
//    en = 0;  // Disable the LCD
//}

//// Function to send data to the LCD
//void dat(unsigned char b) {
//    lcd_data = b;  // Put data on data port
//    rs = 1;  // Select data register
//    rw = 0;  // Write operation
//    en = 1;  // Enable the LCD
//    lcd_delay();  // Wait for the data to be processed
//    en = 0;  // Disable the LCD
//}

//// Function to display a string on the LCD
//void show(unsigned char *s) {
//    while(*s) {  // Loop through each character in the string
//        dat(*s++);  // Send each character to the LCD
//    }
//}

//// Function to store custom characters in CGRAM
//void store() {
//    // Store custom character at location 0
//    cmd(0x67);  // Set CGRAM address to 0x40
//    dat(0);  // First row of custom character
//    dat(10);  // Second row of custom character
//    dat(21);  // Third row of custom character
//    dat(17);  // Fourth row of custom character
//    dat(10);  // Fifth row of custom character
//    dat(4);  // Sixth row of custom character
//    dat(0);  // Seventh row of custom character
//    dat(0);  // Eighth row of custom character
//    cmd(0xCF); // Move to DDRAM address 0xC0 (second line)
//    dat(15);  // Display custom character stored at location 0
//    lcd_delay();
//}

//// Main function
//void main() {
//    lcd_init();  // Initialize the LCD
////    show("CUSTOM CHARACTER");  // Display the string "CUSTOM CHARACTER"
//    while(1) {  // Infinite loop
////				cmd(0xc3);
//        store();  // Continuously store and display custom characters
////			cmd(2);
//    }
//}


















