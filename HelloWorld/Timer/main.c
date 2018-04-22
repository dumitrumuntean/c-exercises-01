/*
 * Timer.c
 *
 * Created: 22/04/2018 22:03:38
 * Author : Dima
 */ 

#include <avr/io.h>

#include "timer.h"

int main(void)
{
	timer_t timer = timer_create(255);
	timer_start(timer);
	timer_destroy(timer);

	while (1)
	{
	}
}
