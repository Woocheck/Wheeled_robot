/* 
* Two_wheel_drive_class.cpp
*
* Created: 15.03.2019 18:50:45
* Author: Woocheck
*/

#include <wiringPi.h>
#include <softPwm.h>
#include "/home/pi/Wheel/Wheeled_robot/pin_settings.h"

#include "/home/pi/Wheel/Wheeled_robot/dcMotor/DC_motor_class.h"
#include "/home/pi/Wheel/Wheeled_robot/wheelDrive/Two_wheel_drive.h"

#include "/home/pi/Wheel/Wheeled_robot/regulatorPD/regulatorPD.h"
#include "/home/pi/Wheel/Wheeled_robot/encoder/encoder.h"


TwoWheelDrive::~TwoWheelDrive()
{
} 

void TwoWheelDrive::setSpeed(int demandedSpeed)
{
	speed=demandedSpeed;
	Left_DC.control(direction, speed);
	Right_DC.control(direction, speed);
};
void TwoWheelDrive::goForward()
{
	direction = Direction::forward;
	Left_DC.control(Direction::forward, speed);
	Right_DC.control(Direction::forward, speed);
};
void TwoWheelDrive::goBackward()
{
	direction = Direction::backward;
	Left_DC.control(Direction::backward, speed);
	Right_DC.control(Direction::backward, speed);
};
void TwoWheelDrive::turnLeft()
{
	direction = Direction::left;
	Left_DC.stop();
	Right_DC.control(Direction::forward, speed);
};
void TwoWheelDrive::turnRight()
{
	direction = Direction::right;
	Left_DC.control(Direction::forward, speed);
	Right_DC.stop();
};

void TwoWheelDrive::stop()
{
	Left_DC.stop();
	Right_DC.stop();
};

void TwoWheelDrive::setNewDistanceToBeTraveled(int newTranslation, 
												int newRotation )
{
	distanceToGo = newTranslation;
	angleToGo = newRotation;
	
}

void TwoWheelDrive::readEncoders()
{
	encoderLeft.readDistance();
	encoderRight.readDistance();
}

void TwoWheelDrive::calculateCorrectionsForDrive()
{
	int translation = encoderLeft.getNumeberOfPulses() + encoderRight.getNumeberOfPulses() ; 
	double translationError = translationProfiler.getCalculatedTranslation() - translation ;
	int newTranslationSets = translationRegulator.calculate( translationError ) ;

	int rotation = encoderLeft.getNumeberOfPulses() - encoderRight.getNumeberOfPulses() ;
	double rotationError = rotationProfiler.getCalculatedRotation() - rotation ;
	int newRotationSets = rotationRegulator.calculate( rotationError ) ;

	Left_DC.control( Direction::forward , newTranslationSets + newRotationSets ) ;
	Right_DC.control( Direction::forward , newTranslationSets - newRotationSets ) ;

};

