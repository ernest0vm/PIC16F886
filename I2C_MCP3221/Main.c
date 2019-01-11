#include <16F886.h>

#fuses INTRC,NOWDT,NOPROTECT,NOLVP
#use delay(internal=4M)

#use i2c(MASTER, SDA=PIN_C4, SCL=PIN_C3, FAST=400000, FORCE_HW)
#use rs232(BAUD=9600,RCV=PIN_C7,XMIT=PIN_C6)

#define LED PIN_B7

int MSB, LSB;
int16 ADC;
float value5, value12;
void main()
   {
    printf("Device ok\n\r");
	set_tris_b(0b00000000);

	printf("Init Reading\n\r");
	i2c_stop();

   while(TRUE)
      {
         
        delay_ms(1000);
        i2c_start();
        i2c_write(0x9B);                     // Device address 10011011 read for A5T
        delay_us(10);
        MSB = i2c_read(1);
        LSB = i2c_read(0);
        i2c_stop();
        ADC = make16(MSB,LSB);
        printf("Data = %LU\n\r",ADC); 
		//conversion
		value5 = (5.0/4096)* ADC;
		printf("Conv1 = %0.1f Vdc\n\r",value5);
		value12 = (12.0/4096)* ADC;
		printf("Conv2 = %0.1f Vdc\n\r",value12);
      }
} 