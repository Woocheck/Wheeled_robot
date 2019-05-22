/* 
* translationProfilerClass.h.h
*
* Created: 07.05.2019
* Author: Woocheck
*/
#include <cstdlib>
#include "translationProfiler.h"

int TranslationProfiler::getCalculatedTranslation()
{
   return calculateTheTranslation();
};

void TranslationProfiler::setGivenAcceleration( const int acceleration )
{
   givenAcceleration = acceleration;
};

int TranslationProfiler::getGivenAcceleration()
{
   return givenAcceleration;
};

void TranslationProfiler::setTargetSpeed( const int speed )
{
   targetSpeed = speed;
   nextStepSpeed = speed;
};
int TranslationProfiler::getTargetSpeed()
{
   return targetSpeed;
};

bool TranslationProfiler::isNecessaryToBrake()
{
    return ( ( currentSpeed * currentSpeed ) / ( 2 * givenAcceleration ) >=
                std::abs( targetRoad ) - std::abs( calculatedRoad ) );
};

int TranslationProfiler::calculateTheTranslation()
{
   if( status == ProfilerStatus::drive ) 
   { 
     if(isNecessaryToBrake()) 
     { 
         status = ProfilerStatus::braking; 
         targetSpeed = nextStepSpeed; 
     } 
    }
 
    if( calculatedRoad >= targetRoad || ( status == ProfilerStatus::braking && currentSpeed == 0 ) ) 
    { 
     status = ProfilerStatus::end; 
     targetSpeed = nextStepSpeed;
      
    } 
 
    if( currentSpeed < targetSpeed ) 
    { 
     currentSpeed += givenAcceleration; 
     if( currentSpeed > targetSpeed ) currentSpeed = targetSpeed; 
    } 
 
    if( currentSpeed > targetSpeed ) 
    { 
     currentSpeed -= givenAcceleration; 
     if( currentSpeed < targetSpeed ) currentSpeed = targetSpeed; 
    } 
 
    calculatedRoad += currentSpeed; 

    return calculatedRoad;
 
};
