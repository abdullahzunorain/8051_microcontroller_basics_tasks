
#include <reg52.h>

#define led_port P2
void msdelay(unsigned int);
	
void main(void){
	while(1)
	{
		led_port = 0x55;
		msdelay(250);
		led_port = ~0x55;
		msdelay(250);
	}
}

void msdelay(unsigned int z){
	unsigned int i,j;
	for(i=0; i<=z; i++)
		for(j=0; j<1275; j++);
}