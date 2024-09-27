#include <stdio.h>
#include <reg51.h>
#include "LCD.h"  //including the header file(LCD.h)


int main() {
    text = 0x00; 
    lcd_init();  
    
    lcd_data('Z');
    delay();     

    lcd_data('U');
    delay();  

    lcd_data('L');
    delay();

    lcd_data('Q');
    delay();      

    lcd_data('A');
    delay();

    lcd_data('R');
    delay();    
   
    lcd_data('N');
    delay();       

    lcd_data('A');
    delay();      

    lcd_data('I');
    delay();      
    
    lcd_data('N');
    delay();      

    return 0;        
}
