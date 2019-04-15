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

void DcMotorClass::initialize(int pin_a,int pin_b,int pin_enable)
{
	PIN_A=pin_a;
	PIN_B=pin_b;
	PIN_Enable=pin_enable;	
}

void DcMotorClass::initializePwm()
{
	//TODO: PWM settings	
}

void DcMotorClass::setDirection(Direction demanded_direction)
{
	DcMotorClass::direction=demanded_direction;
	if (direction==forward)
	{
		
	}
	else if(direction==backward)
	{
		
	}
}


void DcMotorClass::setSpeed(volatile int demanded_speed)
{
	if(demanded_speed<0)
	{
		*(DcMotorClass::speed)=0;
	}
	else if(demanded_speed>255)
	{
		*(DcMotorClass::speed)=255;
	}
	else
	{
		*(DcMotorClass::speed)=demanded_speed;
	}
}

void DcMotorClass::start()
{
	setDirection(direction);
}

void DcMotorClass::stop()
{
	*Port_PIN_A&=~(1<<DcMotorClass::PIN_A);
	*Port_PIN_B&=~(1<<DcMotorClass::PIN_B);
}


void DcMotorClass::contol(Direction demanded_direction, int demanded_speed)
{
	DcMotorClass::setDirection(demanded_direction);
	DcMotorClass::setSpeed(demanded_speed); 
	DcMotorClass::start();
}
