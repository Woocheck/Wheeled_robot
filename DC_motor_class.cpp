/* 
* DC_motor_class.cpp
*
* Created: 15.03.2019 18:47:58
* Author: Woocheck
*/

#include <wiringPi.h>
#include <softPwm.h>
//#include "./pin_settings.h"
#include "./DC_motor_class.h" 


// default constructor
DcMotorClass::DcMotorClass()
{
} //DC_motor_class
DcMotorClass::DcMotorClass(int a, int b, int enable)
{
		wiringPiSetupPhys();
		pinA = a;
		pinB = b;
		pinEnable = enable;
		pinMode (pinA, OUTPUT);
		pinMode (pinB, OUTPUT) ;
		softPwmCreate(pinEnable, 0, 100);
};
// default destructor
DcMotorClass::~DcMotorClass()
{
} //~DC_motor_class

void DcMotorClass::setDirection(Direction demandedDirection)
{
	DcMotorClass::direction=demandedDirection;
	if (direction==Direction::forward)
	{
		digitalWrite (pinA, HIGH); 
		digitalWrite (pinB,  LOW); 
	}
	else if(direction==Direction::backward)
	{
		digitalWrite (pinA, LOW); 
		digitalWrite (pinB,  HIGH);
	}
}


void DcMotorClass::setSpeed(volatile int demandedSpeed)
{
	speed = demandedSpeed;
	if(demandedSpeed<0)
	{
		softPwmWrite(pinEnable, speed);
	}
	else if(demandedSpeed>255)
	{
		softPwmWrite(pinEnable, speed);
	}
	else
	{
		softPwmWrite(pinEnable, speed);
	}
}

void DcMotorClass::start()
{
	setDirection(direction);
	softPwmWrite(pinEnable, speed);
}

void DcMotorClass::stop()
{
	digitalWrite (0, LOW); 
	digitalWrite (0, LOW);
}


void DcMotorClass::contol(Direction demandedDirection, int demandedSpeed)
{
	setDirection(demandedDirection);
	setSpeed(demandedSpeed); 
	start();
}
