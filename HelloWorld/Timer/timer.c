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

void timer_start(display_t display ,timer_t self)
{
	self->started = true;

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

void timer_increment_time(timer_t self)
{
		self->time++;
}
void timer_decrement_time(timer_t self)
{
	self->time--;
}

void timer_stop(timer_t self)
{
	self->started = false;
}

void timer_continue(display_t display, timer_t self)
{
	self->started = true;
	timer_start(display, self);
}