/*

Task_12_Part(8):
Make a function called display_num_7seg(long num) which takes any arbitrary number as input,
converts it and displays it on the seven segment displays. 

e.g. If you call long num = 42354245; display_num_7seg(num); 

The above code should display 42354245 on the seven segment displays.
If num = 97561654 then the seven segment displays should display 97561654. 
Do conversion in real time and don’t hard code the number to be displayed.

*/

#include <reg52.h>

sbit p1 = P2^2;
sbit p2 = P2^3;
sbit p3 = P2^4;

void my_func(int my_array[], int x);
#define Port_0 P0
int my_array[]={8,1,2,6,7,9,9,2};

void M0T0delay(void){
	
		TMOD = 0x01;  // 16-bit non-autoreload mode, timer_0, mode_1
		TL0 = 0x99; 
		TH0 = 0xEF;
		TR0 = 1;
		while(TF0==0);
		TR0 = 0;
		TF0 = 0;
}

void main(){
	while(1){
		
		//display1
		p1=1; p2=1; p3=1;
		my_func(my_array, 0);
		M0T0delay();
//		M0T0delay();
		
		//display2
		p1=0; p2=1; p3=1;
		my_func(my_array, 1);
		M0T0delay();
//		M0T0delay();
		
		//display3
		p1=1; p2=0; p3=1;
		my_func(my_array, 2);
		M0T0delay();
//		M0T0delay();
		
		//display4
		p1=0; p2=0; p3=1;
		my_func(my_array, 3);
		M0T0delay();
//		M0T0delay();
		
		//display5
		p1=1; p2=1; p3=0;
		my_func(my_array, 4);
		M0T0delay();
//		M0T0delay();
		
		//display6
		p1=0; p2=1; p3=0;
		my_func(my_array, 5);
		M0T0delay();
//		M0T0delay();
		
		//display7
		p1=1; p2=0; p3=0;
		my_func(my_array, 6);
		M0T0delay();
//		M0T0delay();
		
		//display8
		p1=0; p2=0; p3=0;
		my_func(my_array, 7);
		M0T0delay();
//		M0T0delay();
	}
}

void my_func(int my_array[], int x){
			if(my_array[x] == 0){
			Port_0=0x3F;
			}
			else if(my_array[x] == 1){
			Port_0=0x06;
			}
		  else if(my_array[x] == 2){
			Port_0=0x5B;
			}
			else if(my_array[x] == 3){
			Port_0=0x4F;
			}
			else if(my_array[x] == 4){
			Port_0=0x66;
			}
			else if(my_array[x] == 5){
			Port_0=0x6D;
			}
			else if(my_array[x] == 6){
			Port_0=0x7D;
			}
			else if(my_array[x] == 7){
			Port_0=0x07;
			}
			else if(my_array[x] == 8){
			Port_0=0x7F;
			}
			else if(my_array[x] == 9){
			Port_0=0x6F;
			}
}