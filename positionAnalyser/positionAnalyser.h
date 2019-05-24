#ifndef __POSITION_ANALYSER_H__
#define __POSITION_ANALYSER_H__

#include <vector>
class PositionAnalyser
{
private:
   std::vector<int> sensorsState { 0, 0, 0, 0, 0 };
   double calculatedError {0};
   int previousError {0};
   int offTheRoad {0};
   int error {0};

public:
   PositionAnalyser(){};
   ~PositionAnalyser(){};
   void setSensorsState(std::vector<int>);
   void calculateError();
   double getCalculatedError();
};



#endif 
