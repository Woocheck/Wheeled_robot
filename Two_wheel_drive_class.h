/* 
* Two_wheel_drive_class.h
*
* Created: 15.03.2019 18:50:45
* Author: Woocheck
*/


#ifndef __TWO_WHEEL_DRIVE_CLASS_H__
#define __TWO_WHEEL_DRIVE_CLASS_H__


#include "pin_settings.h"
#include "DC_motor_class.h"

enum VehicleDirection {ahead, back, left, right};

class TwoWheelDriveClass
{
//variables
public:
protected:
private:

DcMotorClass Left_DC(PIN_LEFT_A,PIN_LEFT_B,PIN_LEFT_ENABLE);
DcMotorClass Right_DC(PIN_RIGHT_A,PIN_RIGHT_B,PIN_RIGHT_ENABLE);

int speed {0};
VehicleDirection direction {VehicleDirection::ahead);

//functions
public:
	TwoWheelDriveClass();
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
