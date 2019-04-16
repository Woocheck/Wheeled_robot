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
	if (direction==Direction::forward)
	{
		
	}
	else if(direction==Direction::backward)
	{
		
	}
}


void DcMotorClass::setSpeed(volatile int demandedSpeed)
{
	if(demandedSpeed<0)
	{
		
	}
	else if(demandedSpeed>255)
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
	setDirection(demandedDirection);
	setSpeed(demandedSpeed); 
	start();
}
