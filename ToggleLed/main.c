#include <16F886.h>                           

#fuses INTRC,NOWDT,NOPROTECT,NOLVP
#use delay(clock=8MHZ)

#define BTN PIN_B0
#define LED PIN_B7

void main() { 

	do{
		if(input(BTN)==1){
		delay_ms(250);
		output_toggle(LED);
	 	}	
	}while(true);
}
