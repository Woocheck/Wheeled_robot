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
#include "./pin_settings.h"
#include <unistd.h>
#include <wiringPi.h>
#include <softPwm.h>
#include "./DC_motor_class.h"
#include "./Two_wheel_drive_class.h"
#include <vector>



int main(void)
{
    wiringPiSetup ()  ;
    char buf [80] ;
  
    TwoWheelDriveClass drive;
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
