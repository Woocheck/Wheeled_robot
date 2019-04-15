/* 
* Two_wheel_drive_class.h
*
* Created: 15.03.2019 18:50:45
* Author: Woocheck
*/


#ifndef __TWO_WHEEL_DRIVE_CLASS_H__
#define __TWO_WHEEL_DRIVE_CLASS_H__


#include "avr/io.h"
#include "pin_settings.h"
#include "DC_motor_class.h"

enum DemandedDirection {ahead, back, left, right};

class TwoWheelDriveClass
{
//variables
public:
protected:
private:

DcMotorClass Left_DC;
DcMotorClass Right_DC;
int speed {0};
Direction direction {forward};

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
