/*
 * Linefollower_1.cpp
 *
 * Created: 14.03.2019 18:31:32
 * Author : Woocheck
*/


//#include "./pin_settings.h"
#include <unistd.h>
#include <wiringPi.h>
#include <softPwm.h>
#include "./Two_wheel_drive_class.h"

TwoWheelDriveClass drive;

int main(void)
{
    wiringPiSetupPhys();
    //drive.goFoward();
    //drive.setSpeed(120);
    while (1) 
    {
	    /*
		
		usleep(1000000);
		drive.stop();
		usleep(1000000);
		drive.goFoward();
		usleep(1000000);
		drive.turnLeft();
		usleep(1000000);
		drive.turnRight();
		usleep(1000000);
		drive.goBackward();
		* */
	pinMode (22, OUTPUT);
	pinMode (23, OUTPUT) ;
	softPwmCreate(24, 0, 100);
	
	digitalWrite (23, LOW); 
	digitalWrite (22, HIGH);
	softPwmCreate(24, 50, 100);
	while(1);
		
    }
}

