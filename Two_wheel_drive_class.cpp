/* 
* Two_wheel_drive_class.cpp
*
* Created: 15.03.2019 18:50:45
* Author: Woocheck
*/

#include <wiringPi.h>
#include <softPwm.h>
#include "./pin_settings.h"
#include "./DC_motor_class.h"
#include "./Two_wheel_drive_class.h"

/*
// default constructor
TwoWheelDriveClass::TwoWheelDriveClass()
{
			
} //Two_wheel_drive_class
*/
// default destructor
TwoWheelDriveClass::~TwoWheelDriveClass()
{
} //~Two_wheel_drive_class

void TwoWheelDriveClass::setSpeed(int demandedSpeed)
{
	speed=demandedSpeed;
	Left_DC.control(direction, speed);
	Right_DC.control(direction, speed);
};
void TwoWheelDriveClass::goForward()
{
	direction = Direction::forward;
	Left_DC.control(Direction::forward, speed);
	Right_DC.control(Direction::forward, speed);
};
void TwoWheelDriveClass::goBackward()
{
	direction = Direction::backward;
	Left_DC.control(Direction::backward, speed);
	Right_DC.control(Direction::backward, speed);
};
void TwoWheelDriveClass::turnLeft()
{
	direction = Direction::left;
	Left_DC.stop();
	Right_DC.control(Direction::forward, speed);
};
void TwoWheelDriveClass::turnRight()
{
	direction = Direction::right;
	Left_DC.control(Direction::forward, speed);
	Right_DC.stop();
};
void TwoWheelDriveClass::stop()
{
	Left_DC.stop();
	Right_DC.stop();
};

