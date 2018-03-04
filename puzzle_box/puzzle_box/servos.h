// servos.h

#ifndef _SERVOS_h
#define _SERVOS_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "Arduino.h"
#else
	#include "WProgram.h"
#endif

/*------------------------------------------
Function Prototypes
------------------------------------------*/
void servo_init();
void servo_lock();
void servo_unlock();

#endif

