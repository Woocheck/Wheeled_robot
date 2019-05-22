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

#include "./dcMotor/DC_motor_class.h"
#include "./wheelDrive/Two_wheel_drive.h"
#include "./encoder/encoder.h"
#include "./lineDetector/detector.h"


void setEncodersInterrupts();
void setDetectorInterrupts();
void readEncodersChange();
void readDetectorChange();

Detector lineDetector;
TwoWheelDrive drive;

int main(void)
{
  wiringPiSetup();
  
	void setEncodersInterrupts();
	void setDetectorInterrupts();
 
  char buf [80] ;

    
  int speed {0};
  char key[8];
  while(1)
  {
		fgets (key, 80, stdin) ;
		witch( key[0] )
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
	wiringPiISR (PIN_ENCODER_LEFT_A, CHANGE,  readEncodersChange ) ; 
  wiringPiISR (PIN_ENCODER_RIGHT_A, CHANGE,  readEncodersChange ) ; 
};

void setDetectorInterrupts()
{
	wiringPiISR (PIN_ENCODER_RIGHT_A, CHANGE,  readEncodersChange ) ; 
  wiringPiISR (PIN_ENCODER_RIGHT_A, CHANGE,  readEncodersChange ) ; 
};

void readEncodersChange()
{
 drive.readEncoders();
};

void readDetectorChange()
{
	lineDetector.readSensorsState();
};