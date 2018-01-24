// dbg_print.h

#ifndef _DBG_PRINT_h
#define _DBG_PRINT_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "Arduino.h"
#else
	#include "WProgram.h"
#endif

/*------------------------------------------
Debugging Functions
------------------------------------------*/
void debug_print(String s);

void debug_print(String s, int i);

void debug_print(int i);

void debug_print(String s1, String s2);

void debug_print(String s, int i1, int i2);

#endif

