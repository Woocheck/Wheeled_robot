
/* 
* translationProfilerClass.h.h
*
* Created: 07.05.2019
* Author: Woocheck
*/

#ifndef __REGUlATOR_PD_CLASS_H__
#define __REGUlATOR_PD_CLASS_H__




class RegulatorPD 
{
   private:
   
   double maximalValue;
   double minimalValue;
   double proportionalParameter;
   double derivateParameter;
   double previousError;
   double integral;

   public:
   RegulatorPD() = default;
   RegulatorPD(  double max, double min, double Kp, double Kd ):
               maximalValue ( max ),
               minimalValue ( min ),
               proportionalParameter ( Kp ),
               derivateParameter ( Kd ) {};
   ~RegulatorPD() {};
   double calculate( double );
   
};   

#endif