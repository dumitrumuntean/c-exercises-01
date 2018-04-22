
#define F_CPU 10000000L
#include <avr/io.h>
#include <util/delay.h>

void light_up_led(int led_no);
void light_off_led(int led_no);
void light_up_no(int no);
void light_off_all();
void wait_button_pressed();
int is_prime(int no);


int main(void)
{
    DDRA = 0xff;            // setting all I/O's in port A as outputs
	DDRB = 0x00;
	
	for(int i = 1; i < 100; i++)
		if(is_prime(i) == 1)
		{
			light_up_no(i);
			
			wait_button_pressed();
			
			light_off_all();
		}


	
}

void wait_button_pressed()
{	
	unsigned char temp = PINB;
	
	while(PINB == temp);
	temp = PINB;
	while(PINB == temp);

	return;
}

int is_prime(int no)
{
	for(int i = 2; i <= sqrt(no); i++)
		if(no%i == 0)
			return 0;
	
	return 1;
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

void light_up_no(int no)
{
	PORTA = ~(no<<PA0); 
}

void light_off_all()
{
	PORTA  = 0xff;
}




