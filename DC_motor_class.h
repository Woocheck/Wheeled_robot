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

enum direction {forward, backward};

class DC_motor_class
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

volatile direction DC_direction=forward;
volatile uint8_t DC_speed=0;

//functions
public:
	DC_motor_class();
	DC_motor_class(volatile uint8_t* ddr_pin_a, volatile uint8_t* port_pin_a,uint8_t pin_a,
				   volatile uint8_t* ddr_pin_b, volatile uint8_t* port_pin_b,uint8_t pin_b,
				   volatile uint8_t* ddr_pin_enable, volatile uint8_t* port_pin_enable,
				   uint8_t pin_enable)
	{ 
		DDR_Pin_A=ddr_pin_a; Port_PIN_A=port_pin_a; PIN_A=pin_a; 
		DDR_Pin_B=ddr_pin_b; Port_PIN_B=port_pin_b; PIN_B=pin_b;
		DDR_Pin_Enable=ddr_pin_a; Port_PIN_Eenable=port_pin_enable; 
		PIN_Enable=pin_enable;
	}
	~DC_motor_class();
	
	void DC_initialization();
	
	void set_DC_direction(direction demanded_direction);					
	void set_DC_speed(uint8_t demanded_speed) {DC_speed=demanded_speed;};
	
	void DC_start();
	void DC_stop();
	void DC_contol(direction demanded_direction, uint8_t demanded_speed);
	
protected:
private:
	DC_motor_class( const DC_motor_class &c );
	DC_motor_class& operator=( const DC_motor_class &c );

}; //DC_motor_class

#endif //__DC_MOTOR_CLASS_H__
