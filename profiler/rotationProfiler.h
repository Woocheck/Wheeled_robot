/* 
* rotationPprofiler.h
*
* Created: 01.05.2019
* Author: Woocheck
*/

#ifndef __ROTATION_PROFILER_CLASS_H__
#define __ROTATION_PROFILER_CLASS_H__


enum class rProfilerStatus {drive, braking, end};

class RotationProfiler 
{
   private:
   rProfilerStatus status {rProfilerStatus::drive};
   int targetSpeed  {50};         
   int nextStepSpeed {50};
   int currentSpeed {0};         
   int givenAcceleration {10};    
   int calculatedRotation {0};   
   int targetAngle {45};         
   
   public:
   RotationProfiler() = default;
   RotationProfiler(int max, int next): 
                    targetSpeed{max}, 
                    nextStepSpeed{next}{};
   
   int getCalculatedRotation();

   void setGivenAcceleration(int);
   int getGivenAcceleration();
   
   void setTargetSpeed(int);
   int getTargetSpeed();

   private:
   int calculateTheRotation();
   bool isNecessaryToBrake();
};   

#endif
