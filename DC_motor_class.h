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
#include "./pin_settings.h"

enum class Direction {forward, backward};

class DcMotorClass
{
//variables
private:

volatile int  pinA;
volatile int  pinB;
volatile int  pinEnable;

volatile Direction direction = Direction::forward;
volatile int speed;

//functions
public:
	DcMotorClass() = default;
	DcMotorClass(int a, int b, int enable):
					pinA {a},
					pinB {b},
					pinEnable {enable} {};
	
	~DcMotorClass(); 
				   	
	void setDirection(Direction demanded_direction);					
	void setSpeed(int demanded_speed);
	
	void start();
	void stop();
	void contol(Direction demanded_direction, int demanded_speed);
	
private:
	DcMotorClass( const DcMotorClass &c );
	DcMotorClass& operator=( const DcMotorClass &c );

}; //DcMmotorClass

#endif //__DC_MOTOR_CLASS_H__
