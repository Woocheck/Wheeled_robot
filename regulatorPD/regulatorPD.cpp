
#include "./regulatorPDClass.h"

double RegulatorPD::calculate(double pe)
{
   previousError = pe;

   // Calculate error
    double error = setpoint - pv;

    // Proportional term
    double Pout = _Kp * error;


    // Derivative term
    double derivative = (error - _pre_error) / _dt;
    double Dout = _Kd * derivative;

    // Calculate total output
    double output = Pout + Iout + Dout;

    // Restrict to max/min
    if( output > _max )
        output = _max;
    else if( output < _min )
        output = _min;

    // Save error to previous error
    _pre_error = error;

    return output
};
