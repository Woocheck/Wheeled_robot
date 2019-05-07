/* 
* Two_wheel_drive_class.h
*
* Created: 15.03.2019 18:50:45
* Author: Woocheck
*/


#ifndef __TWO_WHEEL_DRIVE_CLASS_H__
#define __TWO_WHEEL_DRIVE_CLASS_H__

#include </home/user/workspace_project/wiringPi/wiringPi/wiringPi.h>
#include </home/user/workspace_project/wiringPi/wiringPi/softPwm.h>
#include "/home/user/workspace_project/Wheeled_robot/pin_settings.h"
#include "/home/user/workspace_project/Wheeled_robot/dcMotor/DC_motor_class.h"



class TwoWheelDriveClass
{
//variables
public:
protected:
private:

double currentTranslationError {0}; 
double distanceToGo {0}; 
double totalDistanceFromEnkoder {0};  
   
double currentRotationError {0}; 
double angleToGo {0}; 
double totalAngleFromEnkoder {0};                
   
int minimalPWM {0}, maximalPWM {100};

DcMotorClass Left_DC;
DcMotorClass Right_DC;

int speed {0};
Direction direction {Direction::forward};

//functions
public:
	TwoWheelDriveClass():Left_DC(28,29,25),Right_DC(22,23,24){
		wiringPiSetup();
	};
	~TwoWheelDriveClass();
	void setSpeed(int demandedSpeed);
	void goForward();
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
