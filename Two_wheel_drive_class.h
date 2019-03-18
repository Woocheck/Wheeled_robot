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


class Two_wheel_drive_class
{
//variables
public:
protected:
private:



DC_motor_class Left_DC(&DDR_LEFT_A,&PORT_LEFT_A,PIN_LEFT_A,
						&DDR_LEFT_B,&PORT_LEFT_B,PIN_LEFT_B,
						&DDR_LEFT_ENABLE,&PORT_LEFT_ENABLE,
						PIN_LEFT_ENABLE);
DC_motor_class Right_DC(&DDR_RIGHT_A,&PORT_RIGHT_A,PIN_RIGHT_A,
						  &DDR_RIGHT_B,&PORT_RIGHT_B,PIN_RIGHT_B,
						  &DDR_RIGHT_ENABLE,&PORT_RIGHT_ENABLE,
						  PIN_RIGHT_ENABLE);

//functions
public:
	Two_wheel_drive_class();
	~Two_wheel_drive_class();
protected:
private:
	Two_wheel_drive_class( const Two_wheel_drive_class &c );
	Two_wheel_drive_class& operator=( const Two_wheel_drive_class &c );

}; //Two_wheel_drive_class

#endif //__TWO_WHEEL_DRIVE_CLASS_H__
