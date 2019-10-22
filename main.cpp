/*
 * Linefollower_1.cpp
 *
 * Created: 14.03.2019 18:31:32
 * Author : Woocheck
*/


#include <stdio.h>
#include <iostream>
#include <errno.h>
#include <string.h>
#include <vector>
#include <unistd.h>
#include <algorithm>


#include <wiringPi.h>
#include <softPwm.h>

#include "./pin_settings.h"

#include "./dcMotor/DCmotor.h"
#include "./wheelDrive/twoWheelDrive.h"
#include "./encoder/encoder.h"
#include "./timer/timer.h"
#include "./RoadControler/RoadControler.h"
#include "./translatorController/driveController.h"

bool isPassed20ms();
bool isOn();
void readLeftEncoderChange();
void readRightEncoderChange();


Gpio gpio;

Encoder leftEncoder( gpio.encoderLeftA, gpio.encoderLeftB );
Encoder rightEencoder( gpio.encoderRightA, gpio.encoderRightB );

DcMotor leftDc( gpio.engineLeftA, gpio.engineLeftB , gpio.engineLeftEnable );
DcMotor rightDc( gpio.engineRightA, gpio.engineRightB , gpio.engineRightEnable );
TwoWheelDrive drive( std::make_shared<DcMotor>( leftDc ), std::make_shared<DcMotor>( rightDc ));
RoadControler roadControler( leftEncoder, rightEencoder, drive );


int main( void )
{
  wiringPiSetup();
	
  wiringPiISR ( gpio.encoderRightB, INT_EDGE_BOTH, &readRightEncoderChange ); 
  wiringPiISR ( gpio.encoderLeftB, INT_EDGE_BOTH, &readLeftEncoderChange );

  int nominalSpeed { 60 };
  DriveController vehicleControler( drive, leftEncoder, rightEencoder, nominalSpeed );

  vehicleControler.move( 200, 0);
  
}

bool isPassed20ms()
{
  static MillisecondIntervalCounter interval20ms( 20 );
  return interval20ms.isPased();
};



void readRightEncoderChange()
{
  rightEencoder.readDistance();
};

void readLeftEncoderChange()
{
  leftEncoder.readDistance();
};




