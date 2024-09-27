////#include <reg52.h>

////void Delay100ms(void); //@24MHz

////void main(void)
////{
////    while(1)
////    {
////        P2 = ~0x00; // Set Port 2 to all ones (inverted 0x00), which should turn off the LEDs
////        Delay100ms(); // Delay
////        P2 = ~0xFF; // Set Port 2 to all zeros (inverted 0xFF), which should turn on the LEDs
////        Delay100ms(); // Delay
////    };
////}


////void Delay100ms(void) //@24MHz
////{
////    unsigned char i, j;

////    i = 195;
////    j = 138;
////    do
////    {
////        while (--j);
////    } while (--i);
////}







////// ---------------------------------------------------------------------------------------------------------------

////#include <reg52.h>

//////#define port_2 P2
////sbit d1=P2^0;  // `D1(pin)` is declared



////void main(void){
////	unsigned int x;
////	while(1)
////	{
////		d1 = 1;
////		for(x=0; x<50000; x++);
////		d1 = 0;
//////		d1 = ~0x00;
//////		for(x=0; x<500; x++);
////	}
////}





//////void main(void){
//////	unsigned int x;
//////	while(1)
//////	{
//////		port_2 = ~0x01;
//////		for(x=0; x<5000; x++);
//////		port_2 = ~0x00;
//////		for(x=0; x<5000; x++);
//////	}
//////}




//////Toggle P1 forever
////#include <reg52.h>
////#define port_2 P2

////void main(void)
////{
////for (;;)
////{
////port_2=0xAA;
////port_2=0x55;
////}
////}


////#include <reg51.h>
////void MSDelay(unsigned int X);
////#define port1 P1
////#define port2 P2

////void main(void){
////unsigned char mybyte;
////P1=0x00; //make P1 input port
////while (1){
////mybyte=P1; //get a byte from P1
////MSDelay(500);
////P2=mybyte; //send it to P2
////}
////}

//// 
////void MSDelay(unsigned int X){
////    unsigned char i, j;
////		for (i=0; i<X; i++)
////			for(j=0; j<125; j++);
////}






//////Toggling an individual bit
//// #include <reg51.h>
//// sbit mybit=P2^4;
//// 
//// void MSDelay(unsigned int X);
//// 
//// void main(void)
//// {
//// while(1){
////		mybit=0;
////	  MSDelay(200);
////		mybit=1;
////	  MSDelay(200);
////}
////}
//// 
//// 
//// void MSDelay(unsigned int X){
////    unsigned int i, j;
////		for (i=0; i<X; i++)
////			for(j=0; j<1275; j++);
////}



