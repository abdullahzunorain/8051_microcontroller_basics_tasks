# 8051_microcontroller_basics_tasks

# STC89C52 training manual
## General Guidelines for Each Task
1. **Understand the Objective**: For each task, first ensure you know exactly what the microcontroller should be doing (e.g., blinking an LED, displaying data on an LCD, communicating via UART).
2. **Plan the Setup**: Based on the objective, determine what peripherals you’ll need to interface with the microcontroller (e.g., LED, LCD, sensors) and how they will connect.
3. **Write the Code**: Stick to writing your code based on the requirements of the task, using helper functions when needed but avoiding directly copying from sources.
4. **Test and Debug**: Use your development board to test the code, making sure it behaves as expected. Debug any issues that arise.
5. **Create a Demonstration Video**: After testing, record a video demonstrating the functionality.
6. **Organize Files**: Keep all task-related files, including the code, video, and simulation in a well-organized folder.

## Sample Workflow for a Task

### Task 1: Blinking an LED
**Objective**: Use the STC89C52 microcontroller to blink an LED connected to one of the GPIO pins.

1. **Setup**:
   - Connect an LED to one of the GPIO pins (e.g., P2.0) with a current-limiting resistor.
   
2. **Code**:
   - Write the code to toggle the LED on and off with a delay in between. The delay will create the blinking effect.
   
   Example code outline:
   ```c
   #include <reg52.h>

   sbit LED = P2^0; // Assign LED to pin P2.0

   void delay(unsigned int time); // Declare delay function

   void main() {
       while(1) {
           LED = 0;  // Turn LED on
           delay(50000); // Delay
           LED = 1;  // Turn LED off
           delay(50000); // Delay
       }
   }

   void delay(unsigned int time) {
       unsigned int i;
       for(i = 0; i < time; i++);
   }
   ```


### Task 1: Setting up the development environment and studying STC89C52RC microcontroller

1. **Install development tools/IDE and drivers:**
   - Follow the instructions provided in the [YouTube video](https://www.youtube.com/watch?v=_GlKeRqBq4s) to install the development tools and drivers for your setup.

2. **STC89C52RC Microcontroller Datasheet Review:**
   - The [datasheet for STC89C52RC microcontroller](http://www.stcmicro.com/datasheet/STC89C51RC-en.pdf) provides detailed specifications and capabilities.

**Questions about the STC89C52RC:**

a. **Size of the RAM and Flash:**
   - **RAM:** 1280 bytes
   - **Flash:** 8KB of in-system programmable flash memory

b. **Number of I/O Pins:**
   - 32 I/O pins available (Ports P0, P1, P2, P3)

c. **Available Peripherals:**
   - Serial port (UART)
   - Timers (Timer0, Timer1)
   - Interrupts
   - Watchdog timer (WDT)
   - External interrupt sources

d. **What is meant by IAP:**
   - **In-Application Programming (IAP):** This allows the microcontroller to update its program memory (flash) without using an external programmer, enabling firmware updates while the system is running.

e. **Number of Timers:**
   - 2 timers (Timer0 and Timer1)

f. **Number of Interrupt Sources:**
   - 6 interrupt sources

g. **Maximum Clock Frequency Supported:**
   - 40 MHz

3. **Study the schematic of the development board:**
   - Locate the **"A2 development board schematic diagram (With translation).pdf"** in the “STC89C52 training” folder to familiarize yourself with the connections and hardware setup.

---

### Task 2: Logic Analyzer Setup

1. **Install Logic Analyzer Software:**
   - Download and install the **Logic 1.2.18 software** from this [link](https://downloads.saleae.com/logic/1.2.18/Logic+Setup+1.2.18.exe).

2. **Watch the video:**
   - [Logic Analyzer Video](https://www.youtube.com/watch?v=rR5cEFRO9_s) to understand how to use a logic analyzer to capture and analyze digital signals.

---

### Task 3: Blink an LED

1. **Write a program to blink LED D1 on the development board:**
   - Implement a delay of 500 ms using a `while` or `for` loop to waste CPU cycles.

2. **Measure the delay using a logic analyzer:**
   - Attach screenshots of the measured 500 ms delay from the logic analyzer.

**Bit Manipulation:**

- Use OR operator to set a bit:
  ```c
  REG = REG | 0x01;  // Sets bit 0
  ```
- Use AND operator to clear a bit:
  ```c
  REG = REG & ~0x01;  // Clears bit 0
  ```
- Define bits for easy usage:
  ```c
  #define LED_D1 0x01
  ```

---

### Task 4: LED Pattern

1. **Blink LEDs D1-D8 in an alternating pattern:**
   - Pattern 1: D1, D3, D5, D7 ON; D2, D4, D6, D8 OFF
   - Pattern 2: D1, D3, D5, D7 OFF; D2, D4, D6, D8 ON

---

### Task 5: Button Interfacing Using Polling

1. **Write a program to control LED D1 using button K1:**
   - When K1 is pressed, toggle LED D1.
   - Use polling and debouncing techniques to ensure only one button press is detected.

---

### Task 6: Button Interfacing Using Interrupt

1. **Write a program to control LED D1 using button K1 with an interrupt:**
   - Implement interrupt-based button press detection with debouncing.

---

### Task 7: LED Control Using Buttons (Polling)

1. **Interface K1-K4 to control LEDs D1-D4 using polling:**
   - K1 controls D1, K2 controls D2, and so on. Implement debouncing.

---

### Task 8: LED Control Using Buttons (Interrupts)

1. **Interface K1-K4 to control LEDs D1-D4 using interrupts and polling:**
   - Use interrupts when available, fall back to polling otherwise.

---

### Task 9: Timer Interrupt

1. **Configure a timer to generate an interrupt every 10 ms:**
   - In the Interrupt Service Routine (ISR), toggle LED D1.

---

### Task 10: Generating Delay with Timer

1. **Generate delays of 100 ms and 1000 ms using the 10 ms timer interrupt:**
   - Toggle LEDs D1, D2, and D3 at intervals of 10 ms, 100 ms, and 1000 ms, respectively.

---

### Task 11: Debouncing Using Timer Interrupt

1. **Implement button debouncing using a 10 ms timer interrupt:**
   - Use variables to detect stable press and release events for button K1.

---

### Task 12: Seven Segment Display Interfacing

1. **Study 74HC245 and 74HC138 datasheets:**
   - The 74HC245 is used as a bus transceiver to drive the 7-segment display.
   - The 74HC138 is a 3-to-8 decoder used to select between the 7-segment displays.

2. **Write programs to control 7-segment displays:**
   - Blink displays one by one with a 500 ms delay.
   - Use timer interrupts to reduce the delay to 10 ms.
   - Calculate the refresh rate for a smooth display.

3. **Display numbers on the 7-segment displays:**
   - Write a lookup table for numbers 0-9.
   - Implement a function `display_num_7seg()` to show arbitrary numbers on the displays.

---

### Task 13: File Organization Using .h and .c Files

1. **Organize your project into `.h` and `.c` files:**
   - Watch this [video](https://www.youtube.com/watch?v=5UMHbzZGQuE) to understand file structuring in embedded systems projects.
   - Split your code for different modules (e.g., LCD, buttons) into `.h` and `.c` files.
  
---

## Task 14: 1602 LCD Interfacing
1. **Study the Datasheets**:
   - Study the datasheet of the 16x2 LCD: [1602 LCD Datasheet](https://www.sparkfun.com/datasheets/LCD/ADM1602K-NSW-FBS-3.3v.pdf)
   - Study the datasheet of the LCD controller HD44780: [HD44780 Datasheet](https://www.sparkfun.com/datasheets/LCD/HD44780.pdf)
   
2. **Connect LCD to Development Board**:  
   - Connect the 16x2 LCD to the development board as shown in the image provided.

3. **Write a Driver for the 8-bit Interface**:
   - Write a driver to control the 16x2 LCD using the 8-bit interface (using eight data lines).
   - Implement the following functions:
     - `lcd_init()`
     - `lcd_set_cursor(row, col)`
     - `lcd_write(row, col)`
     - `lcd_clear()`

4. **Repeat with 4-bit Interface**:
   - Repeat the above task using the 4-bit interface (using four data lines).

5. **Display Custom Characters**:
   - Display custom characters on the LCD, such as a battery symbol, tick, cross, etc.

6. **Organize Code**:
   - Organize the LCD code in `LCD.h` and `LCD.c` files so it can be easily included and used in future tasks.
  
---

## Task 15: Serial Port Programming
1. **Download Hercules Serial Terminal Software**:  
   - Download the Hercules serial terminal software from [here](https://www.hw-group.com/software/hercules-setup-utility).

2. **Send Data to PC**:
   - Write a program to send data from the microcontroller to the PC using the serial port at a baud rate of 9600.
   - Send a message such as "Hello world".
   - Use `\n\r` in the message to see how it takes the cursor to a new line in the Hercules software (e.g., `"Hello world\n\r"`).

3. **Receive Data from PC**:
   - Send data from the PC to the microcontroller.
   - Use `\n\r` to terminate the message and implement an `if` condition in the program to detect when a complete message has arrived.

4. **Send Time to Microcontroller**:
   - Send time information to the microcontroller over the serial port in the following format:  
     `hh:mm:ss\n\r`  
     Example:  
     `11:58:05\n\r`
   - In the program, keep receiving bytes from the serial port until a newline sequence (`\n\r`) is detected.
   - When the newline sequence is detected, stop receiving data and process the received string to parse/extract the values of the hour, minute, and second from the received string.
   - Store these values in the variables `hour`, `min`, and `sec`.

5. **Display Time on LCD**:
   - Display the values of the hour, minute, and second processed in the last step on the 16x2 LCD.
   - Optionally, send date information via the serial port and display it on the LCD.
   - Use the `LCD.h` and `LCD.c` files to include and reuse the LCD code.

--- 
