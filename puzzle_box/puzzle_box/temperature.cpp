// Temperature Processsing Functions 
// 
// 

#include "temperature.h"
#include "dbg_print.h"

/*------------------------------------------
Constants
------------------------------------------*/
#define THERMISTOR 0
#define TEMP_OFFSET 20

/*------------------------------------------
Global Variables
------------------------------------------*/
int ambient_temp;

/*------------------------------------------
Init Function
------------------------------------------*/
void ambient_temp_init()
{
	// Local Variables
	unsigned long temp = 0;
	int x;

	for (x = 0; x < 100; x++)
	{
		temp += analogRead(THERMISTOR);
	}
	ambient_temp = temp / 100;
	debug_print("Ambient Temperature:", ambient_temp);
}

/*------------------------------------------
Proccessing Functions
------------------------------------------*/
boolean temp_process()
{
	// Local Variables 
	int temp;

	// Temperature Processing 
	temp = analogRead(THERMISTOR);
	debug_print("Temperature:", temp);
	if (temp > ambient_temp + TEMP_OFFSET)
	{
		return true;
	}
	else
	{
		return false;
	}
}