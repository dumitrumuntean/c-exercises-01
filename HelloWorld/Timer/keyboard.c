/*
 * keyboard.c
 *
 * Created: 22/04/2018 22:50:15
 *  Author: Dima
 */ 

#include "keyboard.h"

struct keyboard
{
	volatile uint8_t *port;
};

keyboard_t keyboard_create(volatile uint8_t *port)
{
	*port = 0;
	
	keyboard_t new_keyboard = (keyboard_t)malloc(sizeof(struct keyboard));
	new_keyboard->port = port;
	
	return new_keyboard;	
}

void destroy_keyboard(keyboard_t self)
{
	free(self);
}