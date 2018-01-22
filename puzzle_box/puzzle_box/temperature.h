// temperature.h

#ifndef _TEMPERATURE_h
#define _TEMPERATURE_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "Arduino.h"
#else
	#include "WProgram.h"
#endif

/*------------------------------------------
Prototypes
------------------------------------------*/
void ambient_temp_init();
boolean temp_process();

#endif

