/*
 * keyboard.h
 *
 * Created: 22/04/2018 22:50:30
 *  Author: Dima
 */ 

#ifndef KEYBOARD_H_
#define KEYBOARD_H_

#include <avr/io.h>
#include <stdlib.h>

typedef struct keyboard * keyboard_t;

keyboard_t	keyboard_create(volatile uint8_t *port);
void		destroy_keyboard(keyboard_t self);

#endif