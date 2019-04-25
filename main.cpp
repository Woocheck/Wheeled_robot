/*
 * Linefollower_1.cpp
 *
 * Created: 14.03.2019 18:31:32
 * Author : Woocheck
*/


#include <stdio.h>
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
    while(1)
    {
	drive.setSpeed(100);
	fgets (buf, 80, stdin) ;
	drive.goForward();
	fgets (buf, 80, stdin) ;
	drive.goBackward();
	fgets (buf, 80, stdin) ;
	drive.setSpeed(10);
	fgets (buf, 80, stdin) ;
	drive.stop();
	fgets (buf, 80, stdin) ;
	drive.goForward();
	fgets (buf, 80, stdin) ;
	drive.turnLeft();
	fgets (buf, 80, stdin) ;
	drive.turnRight();
	fgets (buf, 80, stdin) ;
    }
}
