#include "LCD.h" // Include the LCD header file

int main() {
    
		while(1){
		lcd_init();    // Initialize the LCD
    lcd_clear(); // Clear the LCD

    // Example usage
    lcd_write(0, 0, 'A');
    lcd_write(0, 1, 'B');
    lcd_write(0, 2, 'D');
    lcd_write(0, 3, 'U');
    lcd_write(0, 4, 'L');
		lcd_write(0, 5, 'L');
		lcd_write(0, 6, 'A');
		lcd_write(0, 7, 'H');
			
			
    lcd_set_cursor(1, 0);  // Set cursor to the beginning of the second line
    lcd_write(1, 0, 'K');  // Write 'W' at the beginning of the second line
    lcd_write(1, 1, 'A');  // Write 'o' at the second position of the second line
    lcd_write(1, 2, 'M');  // Write 'r' at the third position of the second line
    lcd_write(1, 3, 'A');  // Write 'l' at the fourth position of the second line
    lcd_write(1, 4, 'L');  // Write 'd' at the fifth position of the second line

		//    while(1); // Infinite loop to keep the microcontroller running
    return 0;
		}
}