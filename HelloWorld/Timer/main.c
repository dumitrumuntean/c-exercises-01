/*
 * Timer.c
 *
 * Created: 22/04/2018 22:03:38
 * Author : Dima
 */ 

#include <avr/io.h>

#include "timer.h"
#include "keyboard.h"

int main(void)
{
	
	DDRA = 0xff;
	DDRB = 0;
	int val=-1;
	int temp;
	
	timer_t timer			= timer_create(0);
	keyboard_t keyboard		= keyboard_create(&PINB);
	display_t display		= display_create(&PORTA);
	
	while(val != 0)
	{
		val = get_input(keyboard);
		
		if(val == 7)
			timer_increment_time(timer);
		else if(val == 6)
			timer_decrement_time(timer);
		
		temp =  val;
		while(temp == val)
				temp =  get_input(keyboard);

		
		light_up_no(display, timer_getTime(timer));
	}
	
	timer_start(display, timer);
	timer_destroy(timer);
	
	while(1);
}
