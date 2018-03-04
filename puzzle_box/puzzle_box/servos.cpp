// 
// 
// 

#include "servos.h"
#include <Servo.h>

/*------------------------------------------
Constants
------------------------------------------*/
#define SERVO_PIN 9
#define LOCK_POS 60
#define UNLOCK_POS 20

/*------------------------------------------
Global Variables
------------------------------------------*/
Servo lock_servo;

/*------------------------------------------
Init Function
------------------------------------------*/
void servo_init()
{
	lock_servo.attach(SERVO_PIN);
	lock_servo.write(LOCK_POS);
}

/*------------------------------------------
Proccessing Functions
------------------------------------------*/
void servo_lock()
{
	lock_servo.write(LOCK_POS);
}

void servo_unlock()
{
	lock_servo.write(UNLOCK_POS);
	delay(500);
	lock_servo.detach();
}

