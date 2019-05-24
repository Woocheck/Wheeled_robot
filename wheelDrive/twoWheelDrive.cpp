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

#include "../regulatorPD/regulatorPD.h"
#include "../encoder/encoder.h"


TwoWheelDrive::~TwoWheelDrive()
{
} 

void TwoWheelDrive::setSpeed(int demandedSpeed)
{
	speed=demandedSpeed;
	Left_DC.control(direction, speed);
	Right_DC.control(direction, speed);
};

void TwoWheelDrive::goForward()
{
	direction = Direction::forward;
	Left_DC.control(Direction::forward, speed);
	Right_DC.control(Direction::forward, speed);
};

void TwoWheelDrive::goBackward()
{
	direction = Direction::backward;
	Left_DC.control(Direction::backward, speed);
	Right_DC.control(Direction::backward, speed);
};

void TwoWheelDrive::turnLeft()
{
	direction = Direction::left;
	Left_DC.stop();
	Right_DC.control(Direction::forward, speed);
};

void TwoWheelDrive::turnRight()
{
	direction = Direction::right;
	Left_DC.control(Direction::forward, speed);
	Right_DC.stop();
};

void TwoWheelDrive::stop()
{
	Left_DC.stop();
	Right_DC.stop();
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

