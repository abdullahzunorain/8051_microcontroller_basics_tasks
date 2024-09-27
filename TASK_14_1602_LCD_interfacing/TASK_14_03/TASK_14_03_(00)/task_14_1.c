////////////////#include <reg51.h>

////////////////// Define the data port for the LCD
////////////////#define lcd_data P0

////////////////// Define control pins for the LCD
////////////////sbit rs = P2^6;  // Register select pin
////////////////sbit rw = P2^5;  // Read/Write pin
////////////////sbit en = P2^7;  // Enable pin

////////////////// Function prototypes
////////////////void lcd_init();           // Initialize the LCD
////////////////void cmd(unsigned char a); // Send command to the LCD
////////////////void dat(unsigned char b); // Send data to the LCD
////////////////void show(unsigned char *s); // Display a string on the LCD
////////////////void lcd_delay();         // Delay function for LCD

////////////////// Function to initialize the LCD
////////////////void lcd_init()
////////////////{
////////////////    cmd(0x38); // Initialize the LCD in 8-bit mode, 2 lines, 5x7 matrix
////////////////    cmd(0x0e); // Display ON, cursor ON
////////////////    cmd(0x01); // Clear display screen
////////////////    cmd(0x06); // Entry mode, auto increment with no shift
////////////////    cmd(0x0c); // Display ON, cursor OFF
////////////////    cmd(0x80); // Set cursor position to the beginning of the first line
////////////////}

////////////////// Function to send a command to the LCD
////////////////void cmd(unsigned char a)
////////////////{
////////////////    lcd_data = a; // Send command to data port
////////////////    rs = 0;       // Select command register
////////////////    rw = 0;       // Write operation
////////////////    en = 1;       // Generate enable pulse
////////////////    lcd_delay();  // Wait for the command to be processed
////////////////    en = 0;       // End enable pulse
////////////////}

////////////////// Function to send data to the LCD
////////////////void dat(unsigned char b)
////////////////{
////////////////    lcd_data = b; // Send data to data port
////////////////    rs = 1;       // Select data register
////////////////    rw = 0;       // Write operation
////////////////    en = 1;       // Generate enable pulse
////////////////    lcd_delay();  // Wait for the data to be processed
////////////////    en = 0;       // End enable pulse
////////////////}

////////////////// Function to display a string on the LCD
////////////////void show(unsigned char *s)
////////////////{
////////////////    while(*s) {   // Loop until the end of the string
////////////////        dat(*s++); // Send each character to the LCD
////////////////    }
////////////////}

////////////////// Delay function for LCD timing
////////////////void lcd_delay()
////////////////{
////////////////    unsigned int lcd_delay;
////////////////    for(lcd_delay = 0; lcd_delay <= 6000; lcd_delay++); // Simple delay loop
////////////////}

////////////////int main()
////////////////{
////////////////    unsigned int j;
////////////////    lcd_init(); // Initialize the LCD
////////////////    while(1) {
////////////////        cmd(0x80); // Set cursor position to the beginning of the first line
////////////////        show("   Welcome To   "); // Display the first line
////////////////        cmd(0xc0); // Set cursor position to the beginning of the second line
////////////////        show(" EMBETRONICX.COM"); // Display the second line
////////////////        for(j = 0; j < 30000; j++); // Delay to keep the message on the screen
////////////////        cmd(0x01); // Clear the display
////////////////        for(j = 0; j < 30000; j++); // Delay before the next iteration
////////////////    }
////////////////}












#include <reg51.h>

sbit rs = P2^6;
sbit rw = P2^5;
sbit en = P2^7;

#define text P0

void delay() {
    int i, j;
    for(i = 0; i < 100; i++) {
        for (j = 0; j < 100; j++);
    }
}

// Add lcd_delay function prototype
void lcd_delay();

// Define lcd_delay function
void lcd_delay() {
    delay();
}

void lcd_cmd(unsigned char a) {
    text = a;
    rs = 0;
    rw = 0;
    en = 1;
    lcd_delay();
    en = 0;
}

void lcd_data(unsigned char b) {
    text = b;
    rs = 1;
    rw = 0;
    en = 1;
    lcd_delay();
    en = 0;
}

void lcd_init() {
    lcd_cmd(0x01);
    delay();
    lcd_cmd(0x38);
    delay();
    lcd_cmd(0x0E);
    delay();
    lcd_cmd(0x10);
    delay();
    lcd_cmd(0x80);
    delay();
}

int main() {
    text = 0x00;
    lcd_init();
    
    lcd_data('A');
    delay();

    lcd_data('B');
    delay();

    lcd_data('D');
    delay();    
    
    lcd_data('U');
    delay();
    lcd_data('L');
    delay();   

    lcd_data('L');
    delay();
    
    lcd_data('A');
    delay();    

    lcd_data('H');
    delay();    
    
//    lcd_data('H');
//    delay();    
//    
//    lcd_data('A');
//    delay();    
//    
//    lcd_data('N');
//    delay();    
//    
//    lcd_data('*');
//    delay();
//    
    // Return statement for main function
    return 0;        
}
