/* 
* translationProfilerClass.h.h
*
* Created: 07.05.2019
* Author: Woocheck
*/
#include <cstdlib>
#include "translationProfilerClass.h"

int TranslationProfiler::getCalculatedTranslation()
{
   return calculateTheTranslation();
};

void TranslationProfiler::setGivenAcceleration( const int acceleration )
{
   givenAcceleration = acceleration;
};

int getGivenAcceleration();

void TranslationProfiler::setTargetSpeed( const int speed )
{
   targetSpeed = speed;
};

int TranslationProfiler::getTargetSpeed()
{
   return targetSpeed;
};

bool TranslationProfiler::isNecessaryToBrake()
{
    return ( ( currentSpeed * currentSpeed ) / ( 2 * givenAcceleration ) >=
                std::abs( targetRoad ) - std::abs( calculatedTranslation ) );
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
 
    if( status == ProfilerStatus::braking && currentSpeed == 0 ) 
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
 
    calculatedTranslation += ( ( currentSpeed + 128 ) >> 8 ); 
 
};
