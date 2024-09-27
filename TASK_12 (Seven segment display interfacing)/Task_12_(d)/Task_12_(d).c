/*
TASK#12. part(4): 
Configure a timer interrupt for 10 ms. 
Now decrease the delay in the previous program to 10ms using the timer interrupt
(Update seven segment displays in timer ISR and not in main function, don’t use CPU cycle wasting delays). 
The 7 segment displays will appear as all working simultaneously. 
This happens because too fast moving things appear as continuous to a human eye. 
Calculate the refresh rate of the displays. The displays won’t be smooth due to the low refresh rate. 
*/



////// Method_01 //-----------------------------------------------------------------------------------------------------------------------------------------------------
////#include <reg52.h>

//// // declaring pins for 74HC138-decoder/demultiplexer IC (used for blinking specific `7-segment` display seperately)
////sbit pin1 = P2^2;
////sbit pin2 = P2^3;
////sbit pin3 = P2^4;

////sbit pin0 = P2^0;

////unsigned int x = 0;


////// ISR function
////void timer0(void) interrupt 1{
////		
////		x++;
////		// for each 7-segment display these pins have different values...
////		// display__0
////		if (x==205){
////		pin1 = 0;
////		pin2 = 0;
////		pin3 = 0;
////		pin0 = ~pin0;
////		}
////			
////		if (x==410){
////		//  display__1
////		pin1 = 1;
////		pin2 = 0;
////		pin3 = 0;
////		}
////		
////		if (x==615){
////		//  display__2
////		pin1 = 0;
////		pin2 = 1;
////		pin3 = 0;
////		}
////		
////		if (x==820){
////		//  display__3
////		pin1 = 1;
////		pin2 = 1;
////		pin3 = 0;
////		}
////		
////		if (x==1025){
////		//  display__4
////		pin1 = 0;
////		pin2 = 0;
////		pin3 = 1;
////		}
////		
////		if (x==1230){
////		//  display__5
////		pin1 = 1;
////		pin2 = 0;
////		pin3 = 1;
////		}
////		
////		if (x==1435){
////		//  display__6
////		pin1 = 0;
////		pin2 = 1;
////		pin3 = 1;
////		}
////		
////		if (x==1640){
////		//  display__7
////		pin1 = 1;
////		pin2 = 1;
////		pin3 = 1;
////		x=0;
////		}
////}

////void main(){
////TMOD = 0x02;   // 8-bit autoreload mode_2, timer_0
////TH0 = 0xFF;    // ....
////IE = 0x82;     // Enable global interrupt and timer-interrupt
////TR0 = 1;       // start the timer

////	while (1){
////	// ...
////	}
////}






////// Method_02 //----------------------------------------------------------------------------------------------------------------------------------------------------
////#include <reg52.h>

////// declaring pins for 74HC138-decoder/demultiplexer IC (used for blinking specific `7-segment` display seperately)
////sbit pin1 = P2^2;
////sbit pin2 = P2^3;
////sbit pin3 = P2^4;

////sbit pin0 = P2^0;

////unsigned int x = 0;


////// ISR function
////void timer0(void) interrupt 1{
////		
////		x++;
////		// for each 7-segment display these pins have different values...
////		// display__0
////	  if (x==24){
////		pin1 = 0;
////		pin2 = 0;
////		pin3 = 0;
////		pin0 = ~pin0;
////	  }
////			
////  	if (x==48){
////		//  display__1
////		pin1 = 1;
////		pin2 = 0;
////		pin3 = 0;
////		}
////		
////		if (x==72){
////		//  display__2
////		pin1 = 0;
////		pin2 = 1;
////		pin3 = 0;
////		}
////		
////		if (x==96){
////		//  display__3
////		pin1 = 1;
////		pin2 = 1;
////		pin3 = 0;
////		}
////		
////		if (x==120){
////		//  display__4
////		pin1 = 0;
////		pin2 = 0;
////		pin3 = 1;
////		}
////		
////		if (x==144){
////		//  display__5
////		pin1 = 1;
////		pin2 = 0;
////		pin3 = 1;
////		}
////		
////		if (x==168){
////		//  display__6
////		pin1 = 0;
////		pin2 = 1;
////		pin3 = 1;
////		}
////		
////		if (x==192){
////		//  display__7
////		pin1 = 1;
////		pin2 = 1;
////		pin3 = 1;
////		x=0;
////		}
////}

////void main(){
////TMOD = 0x02;   // 8-bit autoreload mode_2, timer_0
////TH0 = 0xFF;    // ....
////IE = 0x82;     // Enable global interrupt and timer-interrupt
////TR0 = 1;       // start the timer

////	while (1){
////	// ...
////	}
////}





// Some important explanation about timer delay ---------------------------------------------------------------------------------------------------------------------------
/*
	```
	TMOD = 0x02;   // 8-bit autoreload mode_2, timer_0
	TH0 = 0xFF;    // ....
	IE = 0x82;     // Enable global interrupt and timer-interrupt
	TR0 = 1;       // start the timer
	```

Explanation of the Above Code(for timer interrupt):

1. **Timer Configuration**: The Timer (Timer 0 in this case) is configured to count up from 0 to 255 in 8-bit auto-reload mode. 
	This means that once it reaches the maximum value (255), it automatically resets to 0 and continues counting.

2. **Interrupt Enable**: The code sets the Interrupt Enable register (`IE`) to enable Timer 0 interrupt (bit 1 set to 1). 
	This means that when Timer 0 overflows (reaches 255 and resets to 0), it will trigger an interrupt.

3. **Timer Start**: The Timer is started by setting the run control bit (`TR0`) to 1. 
	This means that the Timer starts counting from 0 towards 255 and then resets to 0 automatically, in a loop.

4. **Interrupt Service Routine (ISR)**: When Timer 0 overflows (reaches 255 and resets to 0), it generates an interrupt. 
	This interrupt is caught by the microcontroller's interrupt controller.

5. **Interrupt Handling**: Since Timer 0 interrupt is enabled (`IE` bit 1 is set to 1), the microcontroller responds to the interrupt. 
It stops the current execution flow, saves the current context (like the state of the program counter and other relevant registers), 
and jumps to the Timer 0 interrupt service routine (ISR).

6. **ISR Execution**: Inside the ISR, you could have custom code that needs to be executed when the Timer 0 overflow interrupt occurs. 
This could include tasks such as updating a display, toggling an output pin, or performing any other action that needs to happen at a regular interval.

7. **Return from ISR**: Once the ISR completes its execution, 
the microcontroller restores the saved context and resumes the interrupted program flow from where it was halted, 
continuing with the code inside the main loop or wherever the program was executing before the interrupt occurred.

In summary, the timer interrupt allows the microcontroller to perform certain tasks with precise timing. 
When the timer overflows, it interrupts the normal program flow, executes a specific function (ISR), and then resumes normal operation. 
This mechanism is commonly used in embedded systems for tasks such as periodic sampling, generating precise time delays, 
or controlling events at regular intervals.
*/







////	// Method_03------------------------------------------(an easy way of performing this task)------------------------------------------------------------------------------------
////	//////// // the below code is just for understanding the concept of 7-segment display as these all are connected to `Port-0`
////	//////// // so here we are going to toggle the 7-segment display that we can examine the delay exactly by logic analyzer.

////	#include <reg52.h>

////	#define LED P0

////	// declaring pins for 74HC138-decoder/demultiplexer IC (used for blinking specific `7-segment` display seperately)
////	sbit pin1 = P2^2;
////	sbit pin2 = P2^3;
////	sbit pin3 = P2^4;
////	unsigned int x = 0;


////	void timer0(void) interrupt 1{
////			x++;
////		
////			// display__0
////			if (x==200){
////			pin1 = 0;
////			pin2 = 0;
////			pin3 = 0;
////			LED = 0xFF;
////			}
////				
////			if (x==400){
////			//  display__1
////			pin1 = 1;
////			pin2 = 0;
////			pin3 = 0;
////			LED = 0x00;
////			}
////			
////			if (x==600){
////			//  display__2
////			pin1 = 0;
////			pin2 = 1;
////			pin3 = 0;
////			LED = 0xFF;
////			}
////			
////			if (x==800){
////			//  display__3
////			pin1 = 1;
////			pin2 = 1;
////			pin3 = 0;
////			LED = 0x00;
////			}
////			
////			if (x==1000){
////			//  display__4
////			pin1 = 0;
////			pin2 = 0;
////			pin3 = 1;
////			LED = 0xFF;
////			}
////			
////			if (x==1200){
////			//  display__5
////			pin1 = 1;
////			pin2 = 0;
////			pin3 = 1;
////			LED = 0x00;
////			}
////			
////			if (x==1400){
////			//  display__6
////			pin1 = 0;
////			pin2 = 1;
////			pin3 = 1;
////			LED = 0xFF;
////			}
////			
////			if (x==1600){
////			//  display__7
////			pin1 = 1;
////			pin2 = 1;
////			pin3 = 1;
////			LED = 0x00;
////			x=0;
////			}
////	}



////	void main(){
////		TMOD = 0x02; // 8-bit non-auto reload mode
////		TH0 = 0xFF;
////		IE = 0x82;
////		TR0 = 1;
////			
////		while (1){
////		// ..
////		}
////	}






// Method_04 //----------------------------------------------------------------------------------------------------------------------------------------------------
#include <reg52.h>

// declaring pins for 74HC138-decoder/demultiplexer IC (used for blinking specific `7-segment` display seperately)
sbit pin1 = P2^2;
sbit pin2 = P2^3;
sbit pin3 = P2^4;

sbit pin0 = P2^0;  //---

unsigned int x = 0;


// ISR function
void timer0(void) interrupt 1{
		
		x++;
		// for each 7-segment display these pins have different values...
		// display__0
		if (x==21){
		pin1 = 0;
		pin2 = 0;
		pin3 = 0;
		}
			
		if (x==42){
		//  display__1
		pin1 = 1;
		pin2 = 0;
		pin3 = 0;
		}
		
		if (x==63){
		//  display__2
		pin1 = 0;
		pin2 = 1;
		pin3 = 0;
		}
		
		if (x==84){
		//  display__3
		pin1 = 1;
		pin2 = 1;
		pin3 = 0;
		}
		
		if (x==105){
		//  display__4
		pin1 = 0;
		pin2 = 0;
		pin3 = 1;
		}
		
		if (x==126){
		//  display__5
		pin1 = 1;
		pin2 = 0;
		pin3 = 1;
		}
		
		if (x==147){
		//  display__6
		pin1 = 0;
		pin2 = 1;
		pin3 = 1;
		}
		
		if (x==168){
		//  display__7
		pin1 = 1;
		pin2 = 1;
		pin3 = 1;
			pin0 = ~pin0;  // LED_01 on pin 2.0(checking the delay in btw this `seven_segment_display` after one complete cycle
		x=0;
		}
}

void main(){
TMOD = 0x02;   // 8-bit autoreload mode_2, timer_0
TH0 = 0xFF;    // ....
IE = 0x82;     // Enable global interrupt and timer-interrupt
TR0 = 1;       // start the timer

	while (1){
	// ...
	}
}







