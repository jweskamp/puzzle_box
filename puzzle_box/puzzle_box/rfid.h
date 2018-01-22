// rfid.h

#ifndef _RFID_h
#define _RFID_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "Arduino.h"
#else
	#include "WProgram.h"
#endif

/*------------------------------------------
Prototypes
------------------------------------------*/
void RFID_init();
boolean RFID_process();

#endif

