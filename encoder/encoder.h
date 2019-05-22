/* 
* encoder.h
*
* Created: 01.05.2019
* Author: Woocheck
*/

#ifndef __ENCODER_H__
#define __ENCODER_H__

#include <wiringPi.h>
#include <softPwm.h>
#include "../pin_settings.h"
#include "../dcMotor/DC_motor_class.h"

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
      wiringPiSetup();
      pinMode ( pinA, INPUT ) ;
      
	    pinMode ( pinB, INPUT ) ;
      
      rotationDirection = Direction::forward;
  }
  
  void readDistance();
  int getNumeberOfPulses();

      
};
  

#endif

