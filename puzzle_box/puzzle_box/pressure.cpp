// Functions to support the user of Piezo pressure sensors 
// 
// 

#include "pressure.h"
#include "dbg_print.h"

/*------------------------------------------
Constants
------------------------------------------*/
#define NUM_PRESSURE_SENSORS 2
#define PRESSURE_THRESHOLD 5
int PIEZO[] = { 1, 2 };
#define INIT_WAIT 25 //ms

/*------------------------------------------
Global Variables
------------------------------------------*/
unsigned long pressure_time;

void pressure_init()
{
	pressure_time = millis();
}

boolean pressure_check()
{
	// Local Variables
	int pressure[NUM_PRESSURE_SENSORS];
	int x;
	boolean ret_val = true;

	// wait for a few ms to iron out the pressure sensors
	if (millis() - pressure_time < INIT_WAIT)
	{
		return;
	}


	// Process Pressure Sensor Data
	for (x = 0; x < NUM_PRESSURE_SENSORS; x++)
	{
		pressure[x] = analogRead(PIEZO[x]);
		debug_print("Pressure:", x + 1, pressure[x]);
		if (pressure[x] > PRESSURE_THRESHOLD)
		{
			ret_val = false;
		}
	}

	//debug_print("Pressure:", ret_val);
	return ret_val;
}
