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



DC_motor_class Left_DC;
DC_motor_class Right_DC;

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
