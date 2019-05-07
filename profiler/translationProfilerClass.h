/* 
* translationProfilerClass.h.h
*
* Created: 07.05.2019
* Author: Woocheck
*/

#ifndef __TRANSLATION_PROFILER_CLASS_H__
#define __TRANSLATION_PROFILER_CLASS_H__


enum class ProfilerStatus {drive, braking, end};

class TranslationProfiler 
{
   private:
   ProfilerStatus status {ProfilerStatus::drive};
   int targetSpeed  {50};         
   int nextStepSpeed {50};
   int currentSpeed {0};      
   int givenAcceleration {10};   
   int calculatedTranslation {0};   
   int targetRoad {45};        
   
   public:
   TranslationProfiler() = default;
   TranslationProfiler(int max, int next): 
                       targetSpeed{max}, 
                       nextStepSpeed{next}{};
   
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
