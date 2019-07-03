/* 
* TwoWheelDrive.cpp
*
* Created: 15.03.2019 18:50:45
* Author: Woocheck
*/

#include <iostream>
#include <wiringPi.h>
#include <softPwm.h>
#include "../pin_settings.h"

#include "../dcMotor/DCmotor.h"
#include "./twoWheelDrive.h"

//#include "../regulatorPD/regulatorPD.h"
#include "../encoder/encoder.h"


TwoWheelDrive::~TwoWheelDrive()
{
} 

void TwoWheelDrive::setSpeed(int demandedSpeed)
{
	speed=demandedSpeed;
	leftDC.control(direction, speed);
	rightDC.control(direction, speed);
};

void TwoWheelDrive::goForward()
{
	direction = Direction::forward;
	leftDC.control(Direction::forward, speed);
	rightDC.control(Direction::forward, speed);
};

void TwoWheelDrive::goBackward()
{
	direction = Direction::backward;
	leftDC.control(Direction::backward, speed);
	rightDC.control(Direction::backward, speed);
};

void TwoWheelDrive::turnLeft()
{
	direction = Direction::left;
	leftDC.stop();
	rightDC.control(Direction::forward, speed);
};

void TwoWheelDrive::turnRight()
{
	direction = Direction::right;
	leftDC.control(Direction::forward, speed);
	rightDC.stop();
};

void TwoWheelDrive::stop()
{
	leftDC.stop();
	rightDC.stop();
};

void TwoWheelDrive::driveControll( int leftSpeed, int rightSpeed )
{
	Direction leftDirection {};
	Direction rightDirection {};

	if( leftSpeed >= 0)
		leftDirection = Direction::forward;
	else
		leftDirection = Direction::backward;

	if( rightSpeed >= 0)
		rightDirection = Direction::forward;
	else
		rightDirection = Direction::backward;
	
	leftDC.control( leftDirection, leftSpeed);
	rightDC.control( rightDirection, rightSpeed);
};

void TwoWheelDrive::regulateInLineFollwerMode( int correction )
{
	int leftWheelSpeed = speed + correction ;
	int rightWheelSpeed = speed - correction ;

	leftDC.control( direction, leftWheelSpeed);
	rightDC.control( direction, rightWheelSpeed);
};

void TwoWheelDrive::regulateInLineLookingForMode( int leftSpeed, int rightSpeed )
{
	driveControll( leftSpeed, rightSpeed );
};

void TwoWheelDrive::readEncoders()
{
	encoderLeft.readDistance();
	encoderRight.readDistance();
}

void TwoWheelDrive::printEncodersNumberOfPulses()
{
	std::cout << encoderLeft.getNumeberOfPulses() << std::endl;
	std::cout << encoderRight.getNumeberOfPulses() << std::endl;
};

