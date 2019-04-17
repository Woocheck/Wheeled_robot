/* 
* DC_motor_class.cpp
*
* Created: 15.03.2019 18:47:58
* Author: Woocheck
*/

#include <wiringPi.h>
#include <softPwm.h>
#include "./pin_settings.h"
#include "./DC_motor_class.h" 


// default constructor
DcMotorClass::DcMotorClass()
{
} //DC_motor_class


// default destructor
DcMotorClass::~DcMotorClass()
{
} //~DC_motor_class

void DcMotorClass::setDirection(Direction demandedDirection)
{
	DcMotorClass::direction=demandedDirection;
	if (direction==Direction::forward)
	{
		digitalWrite (0, HIGH); 
		digitalWrite (0,  LOW); 
	}
	else if(direction==Direction::backward)
	{
		digitalWrite (0, LOW); 
		digitalWrite (0,  HIGH);
	}
}


void DcMotorClass::setSpeed(volatile int demandedSpeed)
{
	speed = demandedSpeed;
	if(demandedSpeed<0)
	{
		softPwmCreate(pinEnable, speed, 100);
	}
	else if(demandedSpeed>255)
	{
		softPwmCreate(pinEnable, speed, 100);
	}
	else
	{
		softPwmCreate(pinEnable, speed, 100);
	}
}

void DcMotorClass::start()
{
	setDirection(direction);
	softPwmCreate(pinEnable, speed, 100);
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
