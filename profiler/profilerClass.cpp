/* 
* profilerClass.h.h
*
* Created: 01.05.2019
* Author: Woocheck
*/
#include <cstdlib>
#include "profilerClass.h"

int Profiler::getCalculatedRotation()
{
   return calculateTheRotation();
};
void Profiler::setGivenAcceleration(const int acceleration)
{
   givenAcceleration = acceleration;
};
int getGivenAcceleration();

void Profiler::setTargetSpeed(const int speed)
{
   targetSpeed = speed;
};
int Profiler::getTargetSpeed()
{
   return targetSpeed;
};
int Profiler::calculateTheRotation()
{
   if(status == ProfilerStatus::drive) 
 { 
     if(currentSpeed * ((currentSpeed + 128) >> 8)/(2 * givenAcceleration) >= std::abs(target_T) - std::abs(zad_T)) 
     { 
         status = ProfilerStatus::braking; 
         docelowa_T_8 = nextStepTargetSpeed; 
     } 
 } 
 
 if(status == ProfilerStatus::braking && currentSpeed == 0) 
 { 
     status = ProfilerStatus::end; 
     docelowa_T_8 = nextStepTargetSpeed; 
 } 
 
 if(currentSpeed < targetSpeed) 
 { 
     currentSpeed += givenAcceleration; 
     if(currentSpeed > targetSpeed) 
         currentSpeed = targetSpeed; 
 } 
 
 if(currentSpeed > targetSpeed) 
 { 
     currentSpeed -= givenAcceleration; 
     if(currentSpeed < targetSpeed) 
         currentSpeed = targetSpeed; 
 } 
 
 if(target_T > 0) 
     calculatedRotation += ((currentSpeed + 128) >> 8); 
 else 
     calculatedRotation -= ((currentSpeed + 128) >> 8);
};
