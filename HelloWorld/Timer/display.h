/*
 * display.h
 *
 * Created: 22/04/2018 22:11:08
 *  Author: Dima
 */ 

#ifndef DISPLAY_H_
#define DISPLAY_H_

#include <avr/io.h>
#include <stdlib.h>

typedef struct display * display_t;

display_t display_create(volatile uint8_t *port);
void destroy_display(display_t display);

void light_up_led(display_t self, int led_no);
void light_off_led(display_t self, int led_no);
void light_up_no(display_t self, int no);
void light_off_all(display_t self);

#endif