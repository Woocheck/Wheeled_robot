/* 
* DC_motor_class.h
*
* Created: 15.03.2019 18:47:58
* Author: Woocheck
*/


#ifndef __DC_MOTOR_CLASS_H__
#define __DC_MOTOR_CLASS_H__

#include <wiringPi.h>
#include <softPwm.h>
#include "/home/pi/Wheel/Wheeled_robot/pin_settings.h"

enum class Direction {forward, backward, left, right};

class DcMotorClass
{

private:

	volatile int  pinA;
	volatile int  pinB;
	volatile int  pinEnable;

	volatile Direction direction = Direction::forward;
	volatile int speed;


public:
	
	DcMotorClass();
	DcMotorClass(int a, int b, int enable):
					pinA {a},
					pinB {b},
					pinEnable {enable} {
		
		pinMode (pinA, OUTPUT);
		pinMode (pinB, OUTPUT) ;
		softPwmCreate(pinEnable, 100, 100);
	};
	
	~DcMotorClass(); 
				   	
	void setDirection(Direction demanded_direction);					
	void setSpeed(int demanded_speed);
	
	void start();
	void stop();
	void control(Direction demanded_direction, int demanded_speed);
	
private:
	DcMotorClass( const DcMotorClass &c );
	DcMotorClass& operator=( const DcMotorClass &c );

}; 

#endif 
