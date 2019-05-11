/* 
* DC_motor_class.cpp
*
* Created: 15.03.2019 18:47:58
* Author: Woocheck
*/

#include </home/user/workspace_project/wiringPi/wiringPi/wiringPi.h>
#include </home/user/workspace_project/wiringPi/wiringPi/softPwm.h>
#include "/home/user/workspace_project/Wheeled_robot/pin_settings.h"
#include "/home/user/workspace_project/Wheeled_robot/dcMotor/DC_motor_class.h" 



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


void DcMotorClass::control(Direction demandedDirection, int demandedSpeed)
{
	setDirection(demandedDirection);
	setSpeed(demandedSpeed); 
	start();
}
