/* 
* encoder_class.h
*
* Created: 01.05.2019
* Author: Woocheck
*/

#include </home/user/workspace_project/wiring/wiringPi/wiringPi/wiringPi.h>
#include </home/user/workspace_project/wiring/wiringPi/wiringPi/softPwm.h>
#include "../pin_settings.h"

class Encoder 
{
  //variables
  private:
   const int pinA;
   const int pinB;
   int encoder0PinALast;
   double duration,abs_duration;//the number of the pulses
   bool Direction;//the rotation direction
   bool result;
  
  //functions
  public:
  Encoder() = default;
  Encoder( int a, int b ):
         pinA { a },
         pinB { b }
  {
      pinMode ( pinA, INPUT ) ;
	   pinMode ( pinB, INPUT ) ;
  }


double val_output;//Power supplied to the motor PWM value.
double Setpoint;
double Kp=0.6, Ki=5, Kd=0;
PID myPID(&abs_duration, &val_output, &Setpoint, Kp, Ki, Kd, DIRECT);

void setup()
{
  Serial.begin(9600);//Initialize the serial port
   pinMode(M_left, OUTPUT);   //L298P Control port settings DC motor driver board for the output mode
   pinMode(E_left, OUTPUT);
   Setpoint =80;  //Set the output value of the PID
   myPID.SetMode(AUTOMATIC);//PID is set to automatic mode
   myPID.SetSampleTime(100);//Set PID sampling frequency is 100ms
  EncoderInit();//Initialize the module
}

void loop()
{
      advance();//Motor Forward
      abs_duration=abs(duration);
      result=myPID.Compute();//PID conversion is complete and returns 1
      if(result)
      {
        Serial.print("Pluse: ");
        Serial.println(duration);
        duration = 0; //Count clear, wait for the next count
      }


}

void EncoderInit()
{
  Direction = true;//default -> Forward
  pinMode(encoder0pinB,INPUT);
  attachInterrupt(0, wheelSpeed, CHANGE);
}

void wheelSpeed()
{
  int Lstate = digitalRead(encoder0pinA);
  if((encoder0PinALast == LOW) && Lstate==HIGH)
  {
    int val = digitalRead(encoder0pinB);
    if(val == LOW && Direction)
    {
      Direction = false; //Reverse
    }
    else if(val == HIGH && !Direction)
    {
      Direction = true;  //Forward
    }
  }
  encoder0PinALast = Lstate;

  if(!Direction)  duration++;
  else  duration--;

}
void advance()//Motor Forward
{
     digitalWrite(M_left,LOW);
     analogWrite(E_left,val_output);
}
void back()//Motor reverse
{
     digitalWrite(M_left,HIGH);
     analogWrite(E_left,val_output);
}

void Stop()//Motor stops
{
     digitalWrite(E_left, LOW);
}

}