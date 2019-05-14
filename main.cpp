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

#include "/home/user/workspace_project/Wheeled_robot/pin_settings.h"

#include "/home/user/workspace_project/Wheeled_robot/dcMotor/DC_motor_class.h"
#include "/home/user/workspace_project/Wheeled_robot/wheelDrive/Two_wheel_drive.h"
#include "/home/user/workspace_project/Wheeled_robot/encoder/encoder.h"

void readEncodersChange();
TwoWheelDrive drive;

int main(void)
{
    wiringPiSetup ()  ;
    wiringPiISR (PIN_ENCODER_LEFT_A, INT_EDGE_BOTH,  readEncodersChange);
    wiringPiISR (PIN_ENCODER_RIGHT_A, INT_EDGE_BOTH,  readEncodersChange);
    char buf [80] ;
  
    
    int speed {0};
    char key[8];
		while(1)
		{
      
		}

}

void readEncodersChange()
{
  drive.readEncoders();
};
