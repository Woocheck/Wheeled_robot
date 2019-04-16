/* 
* DC_motor_class.cpp
*
* Created: 15.03.2019 18:47:58
* Author: Woocheck
*/

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

void DcMotorClass::initialize(int a,int b,int enable)
{
	pinA=a;
	pinB=b;
	pinEnable=enable;	
}

void DcMotorClass::initializePwm()
{
	//TODO: PWM settings	
}

void DcMotorClass::setDirection(Direction demandedDirection)
{
	DcMotorClass::direction=demandedDirection;
	if (direction==forward)
	{
		
	}
	else if(direction==backward)
	{
		
	}
}


void DcMotorClass::setSpeed(volatile int demandedSpeed)
{
	if(demandedSpeed<0)
	{
		
	}
	else if(demanded_speed>255)
	{
		
	}
	else
	{
		
	}
}

void DcMotorClass::start()
{
	setDirection(direction);
}

void DcMotorClass::stop()
{
	
}


void DcMotorClass::contol(Direction demandedDirection, int demandedSpeed)
{
	DcMotorClass::setDirection(demandedDirection);
	DcMotorClass::setSpeed(demandedSpeed); 
	DcMotorClass::start();
}
