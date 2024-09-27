//#include <reg52.h>
//sbit led = P2^0;
////void ext_intrpt_0();
//void msdelay(unsigned int);



//void main (){
//	IE = 0x81;
//}

//void ext_intrpt_0() interrupt 0{
//	msdelay(50);
//	led = ~led;
//	msdelay(300);
//}

//void msdelay(unsigned int delay) {
//    unsigned int i, j;
//    for(i = 0; i < delay; i++)
//        for(j = 0; j < 115; j++);
//}


// **********************************************************************************************************************

//#include <reg52.h>
//sbit led = P2^0;
//void ext_intrpt_0();

//void main (){
//	IE = 0x81;
//	while(1){
//	
//	}
//}

//void ext_intrpt_0() interrupt 0{
//	led = ~led;
//}





// / **********************************************************************************************************************




#include <reg51.h>
sbit led=P2^0;

void MSDelay(unsigned int);


void external_int0() interrupt 0
{
	led=~led;
	MSDelay(250);
	
}

void main()
{
	IE=0x81;

}


void MSDelay(unsigned int itime) {
    unsigned int i, j;
    for(i = 0; i < itime; i++)
        for(j = 0; j<114; j++);
}

