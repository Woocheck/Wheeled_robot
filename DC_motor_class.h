/* 
* DC_motor_class.h
*
* Created: 15.03.2019 18:47:58
* Author: Woocheck
*/


#ifndef __DC_MOTOR_CLASS_H__
#define __DC_MOTOR_CLASS_H__

#include "avr/io.h"
#include "pin_settings.h"

enum Direction {forward, backward};

class DcMotorClass
{
//variables
public:
protected:
private:
volatile uint8_t* DDR_Pin_A;
volatile uint8_t* DDR_Pin_B;
volatile uint8_t* DDR_Pin_Enable;
volatile uint8_t* Port_PIN_A;
volatile uint8_t* Port_PIN_B;
volatile uint8_t* Port_PIN_Eenable;
volatile uint8_t  PIN_A;
volatile uint8_t  PIN_B;
volatile uint8_t  PIN_Enable;

volatile uint8_t* ddrRegister;
volatile uint8_t pwmPinRegister;
volatile uint8_t* tccrRegisterA;
volatile uint8_t* tccrRegisterB;	

volatile Direction direction=forward;
volatile uint8_t* speedRegister;

//functions
public:
	DcMotorClass();
	~DcMotorClass();
	
	void initialize(volatile uint8_t* ddr_pin_a, volatile uint8_t* port_pin_a,uint8_t pin_a,
					volatile uint8_t* ddr_pin_b, volatile uint8_t* port_pin_b,uint8_t pin_b,
					volatile uint8_t* ddr_pin_enable, volatile uint8_t* port_pin_enable,
					uint8_t pin_enable);
				   
	void initializePwm(volatile uint8_t *ddr, volatile uint8_t pin, 
					volatile uint8_t* tccrA,volatile uint8_t* tccrB, 
					volatile uint8_t* ocr);
	
	void setDirection(Direction demanded_direction);					
	void setSpeed(uint8_t demanded_speed);
	
	void start();
	void stop();
	void contol(Direction demanded_direction, uint8_t demanded_speed);
	
protected:
private:
	DcMotorClass( const DcMotorClass &c );
	DcMotorClass& operator=( const DcMotorClass &c );

}; //DcMmotorClass

#endif //__DC_MOTOR_CLASS_H__
