/* 
* profilerClass.h.h
*
* Created: 01.05.2019
* Author: Woocheck
*/
#include <cstdlib>
#include "profilerClass.h"

int RotationProfiler::getCalculatedRotation()
{
   return calculateTheRotation();
};
void RotationProfiler::setGivenAcceleration( const int acceleration )
{
   givenAcceleration = acceleration;
};
int getGivenAcceleration();

void RotationProfiler::setTargetSpeed( const int speed )
{
   targetSpeed = speed;
};
int RotationProfiler::getTargetSpeed()
{
   return targetSpeed;
};

bool RotationProfiler::isNecessaryToBrake()
{
    return ( ( currentSpeed * currentSpeed ) / ( 2 * givenAcceleration ) >=
                std::abs( targetAngle ) - std::abs( calculatedRotation ) );
};


int RotationProfiler::calculateTheRotation()
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
     if( currentSpeed > targetSpeed ) 
         currentSpeed = targetSpeed; 
 } 
 
 if( currentSpeed > targetSpeed ) 
 { 
     currentSpeed -= givenAcceleration; 
     if( currentSpeed < targetSpeed ) 
         currentSpeed = targetSpeed; 
 } 
 
 if( targetAngle > 0 ) 
     calculatedRotation += ( ( currentSpeed + 128 ) >> 8 ); 
 else 
     calculatedRotation -= ( ( currentSpeed + 128 ) >> 8 );
};
