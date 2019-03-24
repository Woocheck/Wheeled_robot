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
TwoWheelDriveClass::TwoWheelDriveClass()
{
	Left_DC.initialize(&DDR_LEFT_A,&PORT_LEFT_A,PIN_LEFT_A,
						&DDR_LEFT_B,&PORT_LEFT_B,PIN_LEFT_B,
						&DDR_LEFT_ENABLE,&PORT_LEFT_ENABLE,
						PIN_LEFT_ENABLE);
	Right_DC.initialize(&DDR_RIGHT_A,&PORT_RIGHT_A,PIN_RIGHT_A,
						&DDR_RIGHT_B,&PORT_RIGHT_B,PIN_RIGHT_B,
						&DDR_RIGHT_ENABLE,&PORT_RIGHT_ENABLE,
						PIN_RIGHT_ENABLE);	
						
	Left_DC.initializePwm(&PWM_DDR_LEFT, PWM_PIN_LEFT,
						&TCCR_LEFT_A, &TCCR_LEFT_B, &OCR_LEFT);
	Right_DC.initializePwm(&PWM_DDR_RIGHT, PWM_PIN_RIGHT,
						&TCCR_RIGHT_A, &TCCR_RIGHT_B, &OCR_RIGHT);	
	
} //Two_wheel_drive_class

// default destructor
TwoWheelDriveClass::~TwoWheelDriveClass()
{
} //~Two_wheel_drive_class
