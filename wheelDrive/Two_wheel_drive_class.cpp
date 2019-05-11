/* 
* Two_wheel_drive_class.cpp
*
* Created: 15.03.2019 18:50:45
* Author: Woocheck
*/

#include </home/user/workspace_project/wiringPi/wiringPi/wiringPi.h>
#include </home/user/workspace_project/wiringPi/wiringPi/softPwm.h>
#include "/home/user/workspace_project/Wheeled_robot/pin_settings.h"

#include "/home/user/workspace_project/Wheeled_robot/dcMotor/DC_motor_class.h"
#include "/home/user/workspace_project/Wheeled_robot/wheelDrive/Two_wheel_drive_class.h"

#include "/home/user/workspace_project/Wheeled_robot/regulatorPD/regulatorPDClass.h"
#include "/home/user/workspace_project/Wheeled_robot/encoder/encoder.h"


TwoWheelDriveClass::~TwoWheelDriveClass()
{
} 

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

