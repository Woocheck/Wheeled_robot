/* 
* DC_motor_class.cpp
*
* Created: 15.03.2019 18:47:58
* Author: Woocheck
*/

#include <iostream>
#include <wiringPi.h>
#include <softPwm.h>
#include "../pin_settings.h"
#include "../dcMotor/DCmotor.h" 



DcMotor::DcMotor()
{
} 



DcMotor::~DcMotor()
{
}

void DcMotor::setDirection(Direction demandedDirection)
{
	DcMotor::direction=demandedDirection;
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


void DcMotor::setSpeed(volatile int demandedSpeed)
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

void DcMotor::start()
{
	setDirection( direction );
	softPwmWrite( pinEnable, speed );
}

void DcMotor::stop()
{
	digitalWrite ( pinA, LOW ); 
	digitalWrite ( pinB, LOW );
}


void DcMotor::control(Direction demandedDirection, int demandedSpeed)
{
	setDirection(demandedDirection);
	setSpeed(demandedSpeed); 
	start();
}
