/* 
* Two_wheel_drive_class.cpp
*
* Created: 15.03.2019 18:50:45
* Author: Woocheck
*/

#include "avr/io.h"
#include "pin_settings.h"
#include "DC_motor_class.h"
#include "Two_wheel_drive_class.h"


// default constructor
Two_wheel_drive_class::Two_wheel_drive_class()
{
	Left_DC.DC_initialization(&DDR_LEFT_A,&PORT_LEFT_A,PIN_LEFT_A,
							&DDR_LEFT_B,&PORT_LEFT_B,PIN_LEFT_B,
							&DDR_LEFT_ENABLE,&PORT_LEFT_ENABLE,PIN_LEFT_ENABLE);
	Right_DC.DC_initialization(&DDR_RIGHT_A,&PORT_RIGHT_A,PIN_RIGHT_A,
							&DDR_RIGHT_B,&PORT_RIGHT_B,PIN_RIGHT_B,
							&DDR_RIGHT_ENABLE,&PORT_RIGHT_ENABLE,PIN_RIGHT_ENABLE);		
} //Two_wheel_drive_class

// default destructor
Two_wheel_drive_class::~Two_wheel_drive_class()
{
} //~Two_wheel_drive_class
