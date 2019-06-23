#ifndef __POSITION_ANALYSER_H__
#define __POSITION_ANALYSER_H__

#include <vector>

#include "../regulatorPD/regulatorPD.h"

class PositionAnalyser
{
private:
   std::vector<int> sensorsState { 0, 0, 0, 0, 0 };
   double calculatedError {0};
   int previousError {0};
   int offTheRoad {0};
   int error {0};
   const double Kp {2};
   const double Kd {0.003};

   RegulatorPD regulator;

public:
   PositionAnalyser():
      regulator( Kp, Kd )
      {};
   ~PositionAnalyser(){};
   void setSensorsState(std::vector<int>);
   void calculateError();
   double getCalculatedError();
};



#endif 
