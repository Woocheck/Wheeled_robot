/* 
* TwoWheelDrive.h
*
* Created: 15.03.2019 18:50:45
* Author: Woocheck
*/


#ifndef __TWO_WHEEL_DRIVE_CLASS_H__
#define __TWO_WHEEL_DRIVE_CLASS_H__

#include <wiringPi.h>
#include <softPwm.h>
#include "../pin_settings.h"
#include "../dcMotor/DCmotor.h"
#include "../regulatorPD/regulatorPD.h"
#include "../encoder/encoder.h"
#include "../profiler/translationProfiler.h"
#include "../profiler/rotationProfiler.h"


class TwoWheelDrive
{
	private:               

		const int minimalPWM {0};
		const int maximalPWM {100};
		const double Kp {1};
		const double Kd {0};
		
		DcMotorClass Left_DC;
		DcMotorClass Right_DC;

		Encoder encoderLeft;
		Encoder encoderRight;

		RegulatorPD regulator;

		int speed {0};
		Direction direction {Direction::forward};

	public:
		TwoWheelDrive():
			Left_DC(  PIN_LEFT_A, PIN_LEFT_B , PIN_LEFT_ENABLE ),
			Right_DC( PIN_RIGHT_A, PIN_RIGHT_B , PIN_RIGHT_ENABLE ),
			
			encoderLeft( PIN_ENCODER_LEFT_A, PIN_ENCODER_LEFT_B ),
			encoderRight( PIN_ENCODER_RIGHT_A, PIN_ENCODER_RIGHT_B ),

			regulator( minimalPWM, maximalPWM, Kp, Kd )
		{
			wiringPiSetup();
		};
		~TwoWheelDrive();
		void setSpeed(int demandedSpeed);
		void goForward();
		void goBackward();
		void turnLeft();
		void turnRight();
		void stop();
		
		void control
		void readEncoders();
	
	private:
		TwoWheelDrive( const TwoWheelDrive &c );
		TwoWheelDrive& operator=( const TwoWheelDrive &c );

}; 

#endif 
