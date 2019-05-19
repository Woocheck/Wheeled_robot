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
#include "../pin_settings.h"
#include "../dcMotor/DC_motor_class.h"
#include "../regulatorPD/regulatorPD.h"
#include "../encoder/encoder.h"
#include "../profiler/translationProfiler.h"
#include "../profiler/rotationProfiler.h"


class TwoWheelDrive
{
	private:

		double currentTranslationError {0}; 
		double distanceToGo {0}; 
		double totalDistanceFromEnkoder {0};  

		double currentRotationError {0}; 
		double angleToGo {0}; 
		double totalAngleFromEnkoder {0};                

		int minimalPWM {0}, maximalPWM {100};
		double translationProportionalParameter {1}, translationDerivateParameter {1};
		double rotationProportionalParameter {1}, rotationDerivateParameter {1};

		DcMotorClass Left_DC;
		DcMotorClass Right_DC;

		Encoder encoderLeft;
		Encoder encoderRight;

		TranslationProfiler translationProfiler;
		RotationProfiler rotationProfiler;

		RegulatorPD translationRegulator;
		RegulatorPD rotationRegulator;

		int speed {0};
		Direction direction {Direction::forward};

	public:
		TwoWheelDrive():
			Left_DC(  PIN_LEFT_A, PIN_LEFT_B , PIN_LEFT_ENABLE ),
			Right_DC( PIN_RIGHT_A, PIN_RIGHT_B , PIN_RIGHT_ENABLE ),
			encoderLeft( PIN_ENCODER_LEFT_A, PIN_ENCODER_LEFT_B ),
			encoderRight( PIN_ENCODER_RIGHT_A, PIN_ENCODER_RIGHT_B ),
			translationRegulator( maximalPWM, minimalPWM, 
										translationProportionalParameter, 
										translationDerivateParameter ),
			rotationRegulator( maximalPWM, minimalPWM, 
										rotationProportionalParameter, 
										rotationDerivateParameter )
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
		void setNewDistanceToBeTraveled(int newTranslation, int newRotation);
		void readEncoders();
		void calculateCorrectionsForDrive();
		void printEncodersNumberOfPulses();
	
	private:
		TwoWheelDrive( const TwoWheelDrive &c );
		TwoWheelDrive& operator=( const TwoWheelDrive &c );

}; 

#endif 
