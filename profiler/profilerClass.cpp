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
     if(currentSpeed * ((currentSpeed + 128) >> 8)/(2 * givenAcceleration) >= std::abs(targetAngle) - std::abs(calculatedRotation)) 
     { 
         status = ProfilerStatus::braking; 
         targetSpeed = nextStepTargetSpeed; 
     } 
 } 
 
 if(status == ProfilerStatus::braking && currentSpeed == 0) 
 { 
     status = ProfilerStatus::end; 
     targetSpeed = nextStepTargetSpeed; 
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
 
 if(targetAngle > 0) 
     calculatedRotation += ((currentSpeed + 128) >> 8); 
 else 
     calculatedRotation -= ((currentSpeed + 128) >> 8);
};
