/* 
* rotationProfilerClass.h
*
* Created: 01.05.2019
* Author: Woocheck
*/
#include <cstdlib>
#include "./rotationProfiler.h"

int RotationProfiler::getCalculatedRotation()
{
   return calculateTheRotation();
};

void RotationProfiler::setGivenAcceleration( const int acceleration )
{
   givenAcceleration = acceleration;
};

int RotationProfiler::getGivenAcceleration()
{
   return givenAcceleration;
};

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
   if( status == rProfilerStatus::drive ) 
   { 
     if(isNecessaryToBrake()) 
     { 
         status = rProfilerStatus::braking; 
         targetSpeed = nextStepSpeed; 
     } 
    } 
 
    if( status == rProfilerStatus::braking && currentSpeed == 0 ) 
    { 
     status = rProfilerStatus::end; 
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
 
    if( targetAngle > 0 ) 
     calculatedRotation += currentSpeed; 
    else 
     calculatedRotation -= currentSpeed;

     return calculatedRotation;
};
