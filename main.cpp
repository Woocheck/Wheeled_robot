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

#include </home/user/workspace_project/wiringPi/wiringPi/wiringPi.h>
#include </home/user/workspace_project/wiringPi/wiringPi/softPwm.h>

#include "./pin_settings.h"

#include "./dcMotor/DC_motor_class.h"
#include "./wheelDrive/Two_wheel_drive.h"
#include "./encoder/encoder.h"


void readEncodersChange();
TwoWheelDrive drive;

int main(void)
{
  if(wiringPiSetup() == -1)
  { 
		printf("setup wiringPi failed !");
		return 1; 
  }
    
  char buf [80] ;

    
    int speed {0};
    char key[8];
    while(1)
    {fgets (key, 80, stdin) ;
	switch( key[0] )
	{
	case 'w':
	{
	  drive.goForward();
	  std::cout << "Forward." << std::endl;
	  break;
	}
	case 's':
	{
	  drive.goBackward();
	  std::cout << "Backward." << std::endl;
	  break;
	}
	case 'a':
	{
	  drive.turnLeft();
	  std::cout << "Left." << std::endl;
	  break;
	}
	case 'd':
	{
	  drive.turnRight();
	  std::cout << "Right." << std::endl;
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
	  break;
	}	
	default:
	{}
	break;
	}
    }
}

void readEncodersChange()
{
  drive.readEncoders();
};
