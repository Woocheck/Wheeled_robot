
#include <algorithm>
#include <vector>

#include "detector.h"



void Detector::readSensorsState()
{
   for(int sensorNumer ; sensorNumer < sensor.size() ; ++sensorNumer )
   {
      sensorsState.at(sensorNumer) = digitalRead ( sensorNumer );
   }
};

std::vector<int> Detector::getSensorsState()
{
   return sensorsState;
};