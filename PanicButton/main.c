#include <16F886.h>

#fuses INTRC, NOWDT, NOPROTECT, NOLVP
#use delay(clock=8MHZ)

#use RS232(BAUD=4800, XMIT=PIN_C6, RCV=PIN_C7, PARITY=N, BITS=8, STOP=1)

#define BTN PIN_B0
#define CTL PIN_C5	//RS485 control 1=TX 0=RX

void main(){

set_tris_b(0b00000001);
set_tris_c(0b10000000);

	while(true){
	
		if(input(BTN)==1){
		delay_ms(250);
		output_high(CTL);
		printf("/*ALERTBTN*/");
		delay_ms(4);
		output_low(CTL);
		}
	
	}

}