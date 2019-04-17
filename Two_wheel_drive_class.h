/* 
* Two_wheel_drive_class.h
*
* Created: 15.03.2019 18:50:45
* Author: Woocheck
*/


#ifndef __TWO_WHEEL_DRIVE_CLASS_H__
#define __TWO_WHEEL_DRIVE_CLASS_H__

#include <wiringPi.h>
#include <softPwm.h>
//#include "pin_settings.h"
#include "DC_motor_class.h"

//enum VehicleDirection {ahead, back, left, right};

class TwoWheelDriveClass
{
//variables
public:
protected:
private:

DcMotorClass Left_DC;
DcMotorClass Right_DC;

int speed {0};
Direction direction {Direction::forward};

//functions
public:
	TwoWheelDriveClass():Left_DC(21,22,23), Right_DC(28,29,24) {
	wiringPiSetupPhys();	
	};
	~TwoWheelDriveClass();
	void setSpeed(int demandedSpeed);
	void goFoward();
	void goBackward();
	void turnLeft();
	void turnRight();
	void stop();
	
	
protected:
private:
	TwoWheelDriveClass( const TwoWheelDriveClass &c );
	TwoWheelDriveClass& operator=( const TwoWheelDriveClass &c );

}; //Two_wheel_drive_class

#endif //__TWO_WHEEL_DRIVE_CLASS_H__
