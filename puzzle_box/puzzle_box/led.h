// led.h

#ifndef _LED_h
#define _LED_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "Arduino.h"
#else
	#include "WProgram.h"
#endif

void led_init();
void morse_init(String s);
void letter_to_morse(char c);
void toggle_led(int led);
void morse_print_to_serial();
void morse_blink();

#endif

