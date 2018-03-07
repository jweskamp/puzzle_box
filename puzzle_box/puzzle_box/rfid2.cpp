// Updated RFID control functions 
// 
// 

#include "rfid2.h"
#include "dbg_print.h"
#include <SoftwareSerial.h>

/*------------------------------------------
Object Declarations
------------------------------------------*/
SoftwareSerial RFID = SoftwareSerial(5, 6);

/*------------------------------------------
Init Functions
------------------------------------------*/
void RFID_init()
{
	Serial.begin(9600);
	RFID.begin(9600);
}

/*------------------------------------------
Proccessing Functions
------------------------------------------*/
boolean RFID_binary_check()
{
	if (RFID.available() > 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}
