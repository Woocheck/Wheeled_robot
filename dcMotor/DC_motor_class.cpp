/* 
* DC_motor_class.cpp
*
* Created: 15.03.2019 18:47:58
* Author: Woocheck
*/

#include <iostream>
#include <wiringPi.h>
#include <softPwm.h>
#include "/home/pi/Wheel/Wheeled_robot/pin_settings.h"
#include "/home/pi/Wheel/Wheeled_robot/dcMotor/DC_motor_class.h" 



DcMotorClass::DcMotorClass()
{
} 



DcMotorClass::~DcMotorClass()
{
}

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
		digitalWrite ( pinA, LOW ); 
		digitalWrite ( pinB, HIGH );
	}
}


void DcMotorClass::setSpeed(volatile int demandedSpeed)
{	
	if(demandedSpeed < 0)
	{
		speed = 0;
	}
	else if( demandedSpeed > 100 )
	{
		speed = 100;
	}
	else
	{
		speed = demandedSpeed;
	}
	
	softPwmWrite( pinEnable, speed);
}

void DcMotorClass::start()
{
	setDirection( direction );
	softPwmWrite( pinEnable, speed );
}

void DcMotorClass::stop()
{
	digitalWrite ( pinA, LOW ); 
	digitalWrite ( pinB, LOW );
}


void DcMotorClass::control(Direction demandedDirection, int demandedSpeed)
{
	setDirection(demandedDirection);
	setSpeed(demandedSpeed); 
	start();
}
