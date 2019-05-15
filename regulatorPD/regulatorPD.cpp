
#include "./regulatorPD.h"

double RegulatorPD::calculate(double error)
{
   
    double outputP = proportionalParameter * error; 

    double derivative = (error - previousError);
    double outputD = derivateParameter * derivative;

    double output = outputP + outputD;

    if( output > maximalValue )
        output = maximalValue;
    else if( output < minimalValue )
        output = minimalValue;

    previousError = error;

    return output;
};
