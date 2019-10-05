#include <unistd.h>

#include "./driveController.h"

void DriveController::timer_handler (int signum);
{
    static int counter= 0;
    printf ("timerHandler: counter= %d\n", counter++);
    fflush (stdout);
}

void DriveController::move( int distance, int angle )
{

}

