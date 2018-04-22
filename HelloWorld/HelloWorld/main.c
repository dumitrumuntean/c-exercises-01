
#define F_CPU 10000000L
#include <avr/io.h>
#include <util/delay.h>

void light_up_led(int led_no);
void light_off_led(int led_no);


int main(void)
{
    DDRA = 0xff;            // setting all I/O's in port A as outputs
	PORTA = 0XFF;
		
	for(int i = 0; i < 8; i++)
	{
		light_up_led(i);
		_delay_ms(500);
		light_off_led(i);
	}
	
	
}

void light_up_led(int led_no)
{
	PORTA &= ~(1<<led_no);
	return;
}

void light_off_led(int led_no)
{
	PORTA |= (1 << led_no);
	return;
}


