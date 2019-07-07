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
#include "./lineDetector/detector.h"
#include "./positionAnalyser/positionAnalyser.h"
#include "./timer/timer.h"



bool isPassed20ms();
bool isOn();
void readLeftEncoderChange();
void readRightEncoderChange();
void readDetectorChange();
void lookingForLine();
bool isLineDetected();

Detector lineDetector( PIN_SENSOR_1, PIN_SENSOR_2, PIN_SENSOR_3,
                       PIN_SENSOR_4, PIN_SENSOR_5 );
PositionAnalyser analyser;
TwoWheelDrive drive;

int main(void)
{
  wiringPiSetup();
	
  wiringPiISR ( PIN_ENCODER_RIGHT_B, INT_EDGE_BOTH,  &readRightEncoderChange ) ; 
  wiringPiISR ( PIN_ENCODER_LEFT_B, INT_EDGE_BOTH,  &readLeftEncoderChange ) ;

  wiringPiISR (PIN_SENSOR_1, INT_EDGE_BOTH,  &readDetectorChange ) ; 
  wiringPiISR (PIN_SENSOR_2, INT_EDGE_BOTH,  &readDetectorChange ) ; 
  wiringPiISR (PIN_SENSOR_3, INT_EDGE_BOTH,  &readDetectorChange ) ; 
  wiringPiISR (PIN_SENSOR_4, INT_EDGE_BOTH,  &readDetectorChange ) ; 
  wiringPiISR (PIN_SENSOR_5, INT_EDGE_BOTH,  &readDetectorChange ) ; 

  int nominalSpeed {70};
	drive.setSpeed( nominalSpeed );
  
  if(!isOn()) 
  {
    std::cout << "looking for line\n";
    lookingForLine();
    std::cout << "line founded\n";
  }
  while(1)
  {
		if(!isOn())
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
   pinMode ( PIN_BUTTON, INPUT ) ;
	 return digitalRead (PIN_BUTTON); 
 }

void readRightEncoderChange()
{
  drive.readRightEncoder();
  drive.printEncodersNumberOfPulses();
};

void readLeftEncoderChange()
{
  drive.readLeftEncoder();
  drive.printEncodersNumberOfPulses();
};

void readDetectorChange()
{
	lineDetector.readSensorsState();
	lineDetector.printSensorsState();	
};

void lookingForLine()
{
  Timer timeBetweenRadiusChange;
  
  int increaseSpeedForBiggerRadius {15};
  int leftWheelSpeed {50};
  int rightWheelSpeed {0};
  
  timeBetweenRadiusChange.start();
  
  while(1)
  {
    drive.regulateInLineLookingForMode( leftWheelSpeed, 
              rightWheelSpeed + increaseSpeedForBiggerRadius );
              
    timeBetweenRadiusChange.stop();
    if( static_cast< std::chrono::duration<double> >( 2 ) <= timeBetweenRadiusChange.getDuration() )
      {
        increaseSpeedForBiggerRadius++;
        timeBetweenRadiusChange.start(); 
      }

    if(isLineDetected())
    {
      drive.stop();
      std::cout << "I found the line!\n";
      break;
    }
  }
}

bool isLineDetected()
{
  lineDetector.readSensorsState();
  std::vector<int> sensorsState = lineDetector.getSensorsState();
  bool result = std::any_of( std::begin( sensorsState ), std::end( sensorsState ), 
                             []( const int & sensor ) { return sensor != 1; } );
  return result;
}
