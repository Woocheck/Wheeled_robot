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


void setEncodersInterrupts();
void setDetectorInterrupts();
void readEncodersChange();
void readDetectorChange();

Detector lineDetector( PIN_SENSOR_1, PIN_SENSOR_2, PIN_SENSOR_3,
			PIN_SENSOR_4, PIN_SENSOR_5 );
TwoWheelDrive drive;

int main(void)
{
  wiringPiSetup();
<<<<<<< HEAD
	setEncodersInterrupts();
  setDetectorInterrupts();
/*
  wiringPiISR ( PIN_ENCODER_LEFT_A, INT_EDGE_BOTH,  &readEncodersChange ) ; 
  wiringPiISR ( PIN_ENCODER_RIGHT_A, INT_EDGE_BOTH,  &readEncodersChange ) ;

  wiringPiISR (PIN_SENSOR_1, INT_EDGE_BOTH,  &readDetectorChange ) ; 
  wiringPiISR (PIN_SENSOR_2, INT_EDGE_BOTH,  &readDetectorChange ) ; 
  wiringPiISR (PIN_SENSOR_3, INT_EDGE_BOTH,  &readDetectorChange ) ; 
  wiringPiISR (PIN_SENSOR_4, INT_EDGE_BOTH,  &readDetectorChange ) ; 
  wiringPiISR (PIN_SENSOR_5, INT_EDGE_BOTH,  &readDetectorChange ) ; 
*/
=======
  
  void setEncodersInterrupts();
  void setDetectorInterrupts();
 
>>>>>>> 433aede9e4503a61a90aca1596d0f3fd9e49e3f3
  char buf [80] ;

    
  int speed {0};
  char key[8];
	
  while(1)
  {
		fgets (key, 80, stdin) ;
		switch( key[0] )
		{
			case 'w':
			{
			  drive.goForward();
			  std::cout << "Forward." << std::endl;
			  drive.printEncodersNumberOfPulses();
			  break;
			}
			case 's':
			{
			  drive.goBackward();
			  std::cout << "Backward." << std::endl;
			  drive.printEncodersNumberOfPulses();
			  break;
			}
			case 'a':
			{
			  drive.turnLeft();
			  std::cout << "Left." << std::endl;
			  drive.printEncodersNumberOfPulses();
			  break;
			}
			case 'd':
			{
			  drive.turnRight();
			  std::cout << "Right." << std::endl;
			  drive.printEncodersNumberOfPulses();
			  break;
			}
			case ' ':
			{
			  if(speed >=10) 
			  {
			    speed = speed - 10;
			    drive.setSpeed( speed );
			  }
			  std::cout << "Speed:" << speed << std::endl;	
			  break;
			}
			case 'e':
			{
			  if(speed <=90) 
			  {
			    speed = speed + 10;
			    drive.setSpeed( speed );
			  }
			  std::cout << "Speed:" << speed << std::endl;
			  break;
			}
			case 'q':
			{
			  drive.stop();
			  std::cout << "Stop." << std::endl;
			  drive.printEncodersNumberOfPulses();
			  break;
			}	
			default:
			{}
			break;
		
			drive.calculateCorrectionsForDrive();
		
		}
  }
}

void setEncodersInterrupts()
{
  wiringPiISR ( PIN_ENCODER_LEFT_A, INT_EDGE_BOTH,  &readEncodersChange ) ; 
  wiringPiISR ( PIN_ENCODER_RIGHT_A, INT_EDGE_BOTH,  &readEncodersChange ) ; 
};

void setDetectorInterrupts()
{
  wiringPiISR (PIN_SENSOR_1, INT_EDGE_BOTH,  &readDetectorChange ) ; 
  wiringPiISR (PIN_SENSOR_2, INT_EDGE_BOTH,  &readDetectorChange ) ; 
  wiringPiISR (PIN_SENSOR_3, INT_EDGE_BOTH,  &readDetectorChange ) ; 
  wiringPiISR (PIN_SENSOR_4, INT_EDGE_BOTH,  &readDetectorChange ) ; 
  wiringPiISR (PIN_SENSOR_5, INT_EDGE_BOTH,  &readDetectorChange ) ;
 
};
 

void readEncodersChange()
{
	std::cout << "Encoder."<< std::endl;
 drive.readEncoders();
};

void readDetectorChange()
{
	lineDetector.readSensorsState();
	lineDetector.printSensorsState();	
};
