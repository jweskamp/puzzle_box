// rfid2.h

#ifndef _RFID2_h
#define _RFID2_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "Arduino.h"
#else
	#include "WProgram.h"
#endif

/*------------------------------------------
Prototypes
------------------------------------------*/
void RFID_init();
boolean RFID_binary_check();

#endif

