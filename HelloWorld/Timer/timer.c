/*
 * timer.c
 *
 * Created: 22/04/2018 22:04:11
 *  Author: Dima
 */ 

#include "timer.h"

struct timer
{
	int time;
	bool started;
};

timer_t timer_create(int time2)
{
	timer_t new_timer = (timer_t)malloc(sizeof(struct timer));
	new_timer->time = time2;
	new_timer->started = false;

	return new_timer;
}

void timer_destroy(timer_t self)
{
	free(self);
}

void timer_start(timer_t self)
{
	self->started = true;
	DDRA = 0xFF;
	DDRB = 0;
	
	display_t display = display_create(&PORTA);
	light_off_all(display);

	while(self->time > 0)
	{			
		light_up_no(display, self->time);
		_delay_ms(1000);
		light_off_all(display);
		self->time--;
	}	
	self->started = false;
}

bool timer_isStarted(timer_t self)
{
	return self->started;
}

void timer_setTime(timer_t self, int time)
{
	self->time = time;
}
int timer_getTime(timer_t self)
{
	return self->time;
}
