// pressure.h

#ifndef _PRESSURE_h
#define _PRESSURE_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "Arduino.h"
#else
	#include "WProgram.h"
#endif

/*------------------------------------------
Prototypes
------------------------------------------*/
boolean pressure_check();

#endif

