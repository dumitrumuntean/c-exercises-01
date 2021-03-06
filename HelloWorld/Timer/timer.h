/*
 * timer.h
 *
 * Created: 22/04/2018 22:04:25
 *  Author: Dima
 */ 
#ifndef TIMER_H_
#define TIMER_H_

#define F_CPU 10000000L
#include <stdbool.h>
#include <stdlib.h>
#include <util/delay.h>
#include "display.h"

typedef struct timer * timer_t;

timer_t timer_create(int time2);
void timer_destroy(timer_t self);

void timer_start(display_t display, timer_t self);
bool timer_isStarted( timer_t self);
void timer_setTime(timer_t self, int time);
void timer_increment_time(timer_t self);
void timer_decrement_time(timer_t self);
void timer_stop(timer_t self);
void timer_continue(display_t display, timer_t self);
int timer_getTime(timer_t self);

#endif