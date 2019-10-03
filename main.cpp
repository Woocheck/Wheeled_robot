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

  wiringPiISR (gpio.frontSensor_1, INT_EDGE_BOTH, &readDetectorChange ); 
  wiringPiISR (gpio.frontSensor_2, INT_EDGE_BOTH, &readDetectorChange ); 
  wiringPiISR (gpio.frontSensor_3, INT_EDGE_BOTH, &readDetectorChange ); 
  wiringPiISR (gpio.frontSensor_4, INT_EDGE_BOTH, &readDetectorChange ); 
  wiringPiISR (gpio.frontSensor_5, INT_EDGE_BOTH, &readDetectorChange ); 

  wiringPiISR (gpio.rearSensor_1, INT_EDGE_BOTH, &readDetectorChange ); 
  wiringPiISR (gpio.rearSensor_2, INT_EDGE_BOTH, &readDetectorChange ); 
  wiringPiISR (gpio.rearSensor_3, INT_EDGE_BOTH, &readDetectorChange ); 
  wiringPiISR (gpio.rearSensor_4, INT_EDGE_BOTH, &readDetectorChange ); 
  wiringPiISR (gpio.rearSensor_5, INT_EDGE_BOTH, &readDetectorChange );

  int nominalSpeed { 60 };
  
  
}

bool isPassed20ms()
{
  static MillisecondIntervalCounter interval20ms( 20 );
  return interval20ms.isPased();
};

 bool isOn()
 {
   pinMode ( gpio.OnButton, INPUT ) ;
   return digitalRead ( gpio.OnButton ); 
 }

void readRightEncoderChange()
{
  rightEencoder.readDistance();
};

void readLeftEncoderChange()
{
  leftEncoder.readDistance();
};




