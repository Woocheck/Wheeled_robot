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

#include <wiringPi.h>
#include <softPwm.h>

#include "./pin_settings.h"

#include "./dcMotor/DCmotor.h"
#include "./wheelDrive/twoWheelDrive.h"
#include "./encoder/encoder.h"
#include "./lineDetector/detector.h"
#include "./positionAnalyser/positionAnalyser.h"



bool isPassed20ms();
bool isOn();
void readEncodersChange();
void readDetectorChange();

Detector lineDetector( PIN_SENSOR_1, PIN_SENSOR_2, PIN_SENSOR_3,
                       PIN_SENSOR_4, PIN_SENSOR_5 );
PositionAnalyser analyser;
TwoWheelDrive drive;

int main(void)
{
  wiringPiSetup();
	
  wiringPiISR ( PIN_ENCODER_LEFT_A, INT_EDGE_BOTH,  &readEncodersChange ) ; 
  wiringPiISR ( PIN_ENCODER_RIGHT_A, INT_EDGE_BOTH,  &readEncodersChange ) ;

  wiringPiISR (PIN_SENSOR_1, INT_EDGE_BOTH,  &readDetectorChange ) ; 
  wiringPiISR (PIN_SENSOR_2, INT_EDGE_BOTH,  &readDetectorChange ) ; 
  wiringPiISR (PIN_SENSOR_3, INT_EDGE_BOTH,  &readDetectorChange ) ; 
  wiringPiISR (PIN_SENSOR_4, INT_EDGE_BOTH,  &readDetectorChange ) ; 
  wiringPiISR (PIN_SENSOR_5, INT_EDGE_BOTH,  &readDetectorChange ) ; 

  int nominalSpeed {50};
	
  while(1)
  {
		if(isOn())
		{
		  if(isPassed20ms())
		  {
				lineDetector.readSensorsState();

				analyser.setSensorsState( lineDetector.getSensorsState() );
        analyser.calculateError();
        
				int correction = static_cast<int>( analyser.getCalculatedError() );
        drive.regulateInLineFollwerMode( correction );	
		  }
		}
  }
}


 bool isPassed20ms()
 {
	 return ( millis()%20) == 0;
 };

 bool isOn()
 {
	 return true; //digitalRead (PIN_BUTTON); 
 }

void readEncodersChange()
{
  drive.readEncoders();
};

void readDetectorChange()
{
	lineDetector.readSensorsState();
	lineDetector.printSensorsState();	
};
