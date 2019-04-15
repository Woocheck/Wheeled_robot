/* 
* DC_motor_class.h
*
* Created: 15.03.2019 18:47:58
* Author: Woocheck
*/


#ifndef __DC_MOTOR_CLASS_H__
#define __DC_MOTOR_CLASS_H__

#include "./pin_settings.h"

enum class Direction {forward, backward};

class DcMotorClass
{
//variables
private:

volatile int  PIN_A;
volatile int  PIN_B;
volatile int  PIN_Enable;

volatile Direction direction = forward;
volatile int speed;

//functions
public:
	DcMotorClass();
	~DcMotorClass();
	
	void initialize(int pin_a, int pin_b, int pin_enable);
				   
	void initializePwm();
	
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
