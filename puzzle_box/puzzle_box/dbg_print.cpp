// Debugging Print Functions 
// 
// 

#include "dbg_print.h"

/*------------------------------------------
Constants
------------------------------------------*/
#define DEBUG_BUILD true

/*------------------------------------------
Debugging Functions
------------------------------------------*/
void debug_print(String s)
{
	if (DEBUG_BUILD && Serial)
	{
		Serial.println(s);
	}
}

void debug_print(String s, int i)
{
	if (DEBUG_BUILD && Serial)
	{
		Serial.print(s);
		Serial.print(" ");
		Serial.println(i);
	}
}

void debug_print(int i)
{
	if (DEBUG_BUILD && Serial)
	{
		Serial.println(i);
	}
}

void debug_print(String s1, String s2)
{
	if (DEBUG_BUILD && Serial)
	{
		Serial.print(s1);
		Serial.print(" ");
		Serial.println(s2);
	}
}