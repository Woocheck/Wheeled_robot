/* 
* encoder_class.h
*
* Created: 01.05.2019
* Author: Woocheck
*/

#include </home/user/workspace_project/wiringPi/wiringPi/wiringPi.h>
#include </home/user/workspace_project/wiringPi/wiringPi/softPwm.h>
#include "/home/user/workspace_project/Wheeled_robot/pin_settings.h"

#include "encoder.h"

void Encoder::readDistance()
{
  int currentStatusPinA = digitalRead (pinA);
  if((previousStatusPinA == LOW) && currentStatusPinA==HIGH)
  {
    int statusPinB = digitalRead (pinB);
    if(statusPinB == LOW && wayside)
    {
      wayside = false; //Reverse
    }
    else if(statusPinB == HIGH && !wayside)
    {
      wayside = true;  //Forward
    }
  }
  previousStatusPinA = currentStatusPinA;

  if(!wayside)  numberOfPulses++;
  else  numberOfPulses--;

}

int Encoder::getNumeberOfPulses()
{
  return numberOfPulses;
};