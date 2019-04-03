/*
 * Linefollower_1.cpp
 *
 * Created: 14.03.2019 18:31:32
 * Author : Woocheck
*/
#define F_CPU 16000000
#include <avr/io.h>
#include <util/delay.h>
#include "pin_settings.h"
#include "Two_wheel_drive_class.h"

TwoWheelDriveClass drive;

int main(void)
{
    drive.goFoward();
	drive.setSpeed(120);
    while (1) 
    {
		
		_delay_ms(1000);
		drive.stop();
		_delay_ms(1000);
		drive.goFoward();
		_delay_ms(1000);
		drive.turnLeft();
		_delay_ms(1000);
		drive.turnRight();
		_delay_ms(1000);
		drive.goBackward();
		
    }
}

