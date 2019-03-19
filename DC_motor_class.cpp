/* 
* DC_motor_class.cpp
*
* Created: 15.03.2019 18:47:58
* Author: Woocheck
*/

#include "avr/io.h"
#include "pin_settings.h"
#include "DC_motor_class.h" 


// default constructor
DC_motor_class::DC_motor_class()
{
} //DC_motor_class


// default destructor
DC_motor_class::~DC_motor_class()
{
} //~DC_motor_class

void DC_motor_class::DC_initialization(volatile uint8_t* ddr_pin_a, volatile uint8_t* port_pin_a,uint8_t pin_a,
volatile uint8_t* ddr_pin_b, volatile uint8_t* port_pin_b,uint8_t pin_b,
volatile uint8_t* ddr_pin_enable, volatile uint8_t* port_pin_enable,
uint8_t pin_enable)
{
		
		DDR_Pin_A=ddr_pin_a; Port_PIN_A=port_pin_a; PIN_A=pin_a; 
		DDR_Pin_B=ddr_pin_b; Port_PIN_B=port_pin_b; PIN_B=pin_b;
		DDR_Pin_Enable=ddr_pin_a; Port_PIN_Eenable=port_pin_enable; 
		PIN_Enable=pin_enable;
	
}

void DC_motor_class::set_DC_direction(direction demanded_direction)
{
	DC_motor_class::DC_direction=demanded_direction;
	if (DC_direction==forward)
	{
		*Port_PIN_A|=(1<<DC_motor_class::PIN_A);
		*Port_PIN_B&=~(1<<DC_motor_class::PIN_B);
	}
	else if(DC_direction==backward)
	{
		*Port_PIN_A&=~(1<<DC_motor_class::PIN_A);
		*Port_PIN_B|=(1<<DC_motor_class::PIN_B);
	}
}

void DC_motor_class::DC_start()
{
	set_DC_direction(DC_direction);
}

void DC_motor_class::DC_stop()
{
	*Port_PIN_A&=~(1<<DC_motor_class::PIN_A);
	*Port_PIN_B&=~(1<<DC_motor_class::PIN_B);
}


void DC_motor_class::DC_contol(direction demanded_direction, uint8_t demanded_speed)
{
	DC_motor_class::set_DC_direction(demanded_direction);
	DC_motor_class::set_DC_speed(demanded_speed); 
	DC_motor_class::DC_start();
}
