#include <unistd.h>

#include "./driveController.h"

void DriveController::timer_handler (int signum);
{
    static int counter= 0;
    printf ("timerHandler: counter= %d\n", counter++);
    fflush (stdout);
    isTimeToClaculateNextStep = true;
}

void DriveController::move( int dist, int ang )
{
    distance_ = dist;
    angle_ = ang;

    rightEncoder_.resetNumberOfPulses();
    leftEncoder_.resetNumberOfPulses();    
}

void DriveController::calculateNextStep()
{
    regV_aktE = zad_S - enk_totalS;                // obliczenie aktualnego błędu translacji 
    regT_aktE = zad_T - enk_totalT;                // obliczenie aktualnego błędu rotacji 
                                                // zmienne enk_totalS oraz enk_totalT zawierają aktualne pomiary z enkoderów, zgodnie ze schematem zamieszczonym powyżej 
 
    reg_newPWML = regV_P * regV_aktE + regV_D * (regV_aktE - regV_prevE) 
                + regT_P * regT_aktE + regT_D * (regT_aktE - regT_prevE); 
    reg_newPWMP = regV_P * regV_aktE + regV_D * (regV_aktE - regV_prevE) 
                - regT_P * regT_aktE + regT_D * (regT_aktE - regT_prevE); 
 
    regV_prevE = regV_aktE; 
    regT_prevE = regT_aktE; 
 
    setPWM(reg_newPWML, reg_newPWMP);
}