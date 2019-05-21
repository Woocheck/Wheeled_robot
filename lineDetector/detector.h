/* 
* detector.h
*
* Created: 21.05.2019 20:30:00
* Author: Woocheck
*/


#ifndef __DETECTOR_H__
#define __DETECTOR_H__

#include <vector>
#include <wiringPi.h>

class Detector 
{
   private:
      std::vector<int> sensor;
      std::vector<int> sensorsState { 0, 0, 0, 0, 0 };

   public:
      Detector(){};
      Detector(int pin1, int pin2, int pin3, int pin4, int pin5 )
      {
         sensor.at(0) = pin1;
         sensor.at(1) = pin2;
         sensor.at(2) = pin3;
         sensor.at(3) = pin4;
         sensor.at(4) = pin5;

         for(int sesorNumber : sensor)
         {
            pinMode ( sensorNumber, INPUT);
         }
         
      }

      void readSensorsState();
      std::vector<int> getSensorsState();
};


#endif