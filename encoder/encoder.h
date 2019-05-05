/* 
* encoder_class.h
*
* Created: 01.05.2019
* Author: Woocheck
*/

#include </home/user/workspace_project/wiringPi/wiringPi/wiringPi.h>
#include </home/user/workspace_project/wiringPi/wiringPi/softPwm.h>
#include "../pin_settings.h"
#include "/home/user/workspace_project/Wheeled_robot/dcMotor/DC_motor_class.h"

class Encoder 
{
  //variables
  private:
   const int pinA;
   const int pinB;
   int currentStatusPinA;
   int previousStatusPinA;
   int statusPinB;
   int numberOfPulses;
   
   Direction rotationDirection;
   bool wayside;
   bool result;
  
  //functions
  public:
  Encoder() = default;
  Encoder( int a, int b ):
         pinA { a },
         pinB { b }
  {
      pinMode ( pinA, INPUT ) ;
      pullUpDnControl (pinA, PUD_UP);
	    pinMode ( pinB, INPUT ) ;
      pullUpDnControl (pinB, PUD_UP);
      rotationDirection = Direction::forward;
  }
  
  void readDistance();

      
};
  



