#include <unistd.h>
#include <utility>

#include "./driveController.h"

void DriveController::timer_handler (int signum);
{
//     static int counter= 0;
//     printf ("timerHandler: counter= %d\n", counter++);
//     fflush (stdout);
//TODO: software counter to run next tep calculations;
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
}

std::pair<int,int> DriveController::calculateNextStep()
{
    int currentErrorTranslation = zad_S - enk_totalS;                // obliczenie aktualnego błędu translacji 
    int currentErrorRotation = zad_T - enk_totalT;                // obliczenie aktualnego błędu rotacji 
                                                // zmienne enk_totalS oraz enk_totalT zawierają aktualne pomiary z enkoderów, zgodnie ze schematem zamieszczonym powyżej 
 
    static int previousErrorTranslation = currentErrorTranslation; 
    static int previousErrorRotation = currentErrorRotation;

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
 
    return std::make_pair( static_cast<int>( regulatorNewPwmLeft ), 
                           static_cast<int>( regulatorNewPwmRight ) );
}

void DriveController::moveNextStep()
{
    int leftPWM;
    int rightPWM;

    [ leftPWM, righPWM ] = calculateNextStep();
    
    drive_.driveControll( leftPWM, rightPWM );
}