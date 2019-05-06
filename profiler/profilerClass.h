/* 
* profilerClass.h.h
*
* Created: 01.05.2019
* Author: Woocheck
*/

#ifndef __PROFILER_CLASS_H__
#define __PROFILER_CLASS_H__


enum class ProfilerStatus {drive, braking, end};

class RotationProfiler 
{
   private:
   ProfilerStatus status {ProfilerStatus::drive};
   int targetSpeed  {50};        // docelowa_T - docelowa prędkość, do której stopniowo dąży profiler 
                                 // max_T - maksymalna dozwolona prędkość 
   int nextStepSpeed {50};
   int currentSpeed {0};         // aktualnie zadana prędkość 
   int givenAcceleration {10};   // zadane przyspieszenie 
   int calculatedRotation {0};   // wyliczony kąt do przejechania - wykorzystywany jako setpoint regulatora PD 
   int targetAngle {45};         // zadany całkowity kąt do przejechania
   
   public:
   RotationProfiler() = default;
   RotationProfiler(int max, int next): targetSpeed{max}, nextStepSpeed{next}{};
   
   int getCalculatedRotation();

   void setGivenAcceleration(int);
   int getGivenAcceleration();
   
   void setTargetSpeed(int);
   int getTargetSpeed();

   private:
   int calculateTheRotation();
   int calculateTheTranslation();
   bool isNecessaryToBrake();
};   

#endif