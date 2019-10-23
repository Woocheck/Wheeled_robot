#include <unistd.h>
#include <utility>

#include "./driveController.h"

void DriveController::timer_handler(int signum)
{ 
  if( isMoveOrdered_ )
    moveNextStep();
}

bool DriveController::isTimeToNextStep()
{
    auto isTime = isTimeToClaculateNextStep_;
    isTimeToClaculateNextStep_ = false;
    return isTime;
}
void DriveController::move( int dist, int ang )
{
    distance_ = dist;
    angle_ = ang;

    rightEncoder_.resetNumberOfPulses();
    leftEncoder_.resetNumberOfPulses();    

    isMoveOrdered_ = true;
  }

std::pair<int,int> DriveController::calculateNextStep()
{
    static int previousErrorTranslation { 0 }; 
    static int previousErrorRotation { 0 };

    int currentErrorTranslation;
    int currentErrorRotation;

    [ currentErrorTranslation, currentErrorRotation ] = calculateCurrentError();

    auto regulatorNewPwmLeft = translationRegulator_.calculate( 
                       currentErrorTranslation , 
                       currentErrorTranslation - previousErrorTranslation )
                     + rotationRegulator_.calculate( 
                       currentErrorRotation , 
                       currentErrorRotation - previousErrorRotation ); 

    auto regulatorNewPwmRight = translationRegulator_.calculate( 
                       currentErrorTranslation , 
                       currentErrorTranslation - previousErrorTranslation )
                     - rotationRegulator_.calculate( 
                       currentErrorRotation , 
                       currentErrorRotation - previousErrorRotation ); 

    previousErrorTranslation = currentErrorTranslation; 
    previousErrorRotation = currentErrorRotation; 
 
    return std::make_pair( static_cast<int>( regulatorNewPwmLeft ), 
                           static_cast<int>( regulatorNewPwmRight ) );
}

void DriveController::moveNextStep()
{
    int leftPWM;
    int rightPWM;

    [ leftPWM, rightPWM ] = calculateNextStep();
    
    drive_.driveControll( leftPWM, rightPWM );
}

std::pair<int,int> DriveController::calculateCurrentError()
{
  int translation = distance_ - ( leftEncoder_.getNumeberOfPulses
                                + rightEncoder_.getNumeberOfPulses );
  int rotation = angle_ - ( leftEncoder_.getNumeberOfPulses
                          - rightEncoder_.getNumeberOfPulses );
  
  return std::make_pair<int, int>( translation, rotation );
}
