/* 
* Two_wheel_drive_class.cpp
*
* Created: 15.03.2019 18:50:45
* Author: Woocheck
*/


#include </home/user/workspace_project/wiring/wiringPi/wiringPi/wiringPi.h>
#include </home/user/workspace_project/wiring/wiringPi/wiringPi/softPwm.h>
#include "./pin_settings.h"
#include "/home/user/workspace_project/Wheeled_robot/dcMotor/DC_motor_class.h"
#include "/home/user/workspace_project/Wheeled_robot/wheelDrive/Two_wheel_drive_class.h"


// default constructor
TwoWheelDriveClass::TwoWheelDriveClass()
{
			
} //Two_wheel_drive_class

// default destructor
TwoWheelDriveClass::~TwoWheelDriveClass()
{
} //~Two_wheel_drive_class

void TwoWheelDriveClass::setSpeed(int demandedSpeed)
{
	speed=demandedSpeed;
	Left_DC.contol(direction, speed);
	Right_DC.contol(direction, speed);
};
void TwoWheelDriveClass::goFoward()
{
	Left_DC.contol(forward, speed);
	Right_DC.contol(forward, speed);
};
void TwoWheelDriveClass::goBackward()
{
	Left_DC.contol(backward, speed);
	Right_DC.contol(backward, speed);
};
void TwoWheelDriveClass::turnLeft()
{
	Left_DC.stop();
	Right_DC.contol(forward, speed);
};
void TwoWheelDriveClass::turnRight()
{
	Left_DC.contol(forward, speed);
	Right_DC.stop();
};
void TwoWheelDriveClass::stop()
{
	Left_DC.stop();
	Right_DC.stop();
};

