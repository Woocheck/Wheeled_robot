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
DcMotorClass::DcMotorClass()
{
} //DC_motor_class


// default destructor
DcMotorClass::~DcMotorClass()
{
} //~DC_motor_class

void DcMotorClass::initialize(volatile uint8_t* ddr_pin_a, volatile uint8_t* port_pin_a,uint8_t pin_a,
							 volatile uint8_t* ddr_pin_b, volatile uint8_t* port_pin_b,uint8_t pin_b,
							  volatile uint8_t* ddr_pin_enable, volatile uint8_t* port_pin_enable,
							  uint8_t pin_enable)
{
		
		DDR_Pin_A=ddr_pin_a; Port_PIN_A=port_pin_a; PIN_A=pin_a; 
		DDR_Pin_B=ddr_pin_b; Port_PIN_B=port_pin_b; PIN_B=pin_b;
		DDR_Pin_Enable=ddr_pin_a; Port_PIN_Eenable=port_pin_enable; 
		PIN_Enable=pin_enable;
	
}

void DcMotorClass::initializePwm(volatile uint8_t* ddr, volatile uint8_t pin,  
							volatile uint8_t* tccrA,volatile uint8_t* tccrB,
							volatile uint8_t* ocr)
{
	DcMotorClass::tccrRegisterA=tccrA;
	DcMotorClass::tccrRegisterB=tccrB;
	DcMotorClass::speedRegister=ocr;
	DcMotorClass::ddrRegister=ddr;
	DcMotorClass::pwmPinRegister=pin;
	
	*ddrRegister|=(1<<pwmPinRegister);
	*tccrRegisterA|=(1<<COM2A1);
	*tccrRegisterA|=(1<<WGM21)|(1<<WGM10);
	*tccrRegisterB|=(1<<CS20);
	*speedRegister=0;
	
}

void DcMotorClass::setDirection(Direction demanded_direction)
{
	DcMotorClass::direction=demanded_direction;
	if (direction==forward)
	{
		*Port_PIN_A|=(1<<PIN_A);
		*Port_PIN_B&=~(1<<PIN_B);
	}
	else if(direction==backward)
	{
		*Port_PIN_A&=~(1<<PIN_A);
		*Port_PIN_B|=(1<PIN_B);
	}
}


void DcMotorClass::setSpeed(volatile uint8_t demanded_speed)
{
	if(demanded_speed<0)
	{
		*(DcMotorClass::speedRegister)=0;
	}
	else if(demanded_speed>255)
	{
		*(DcMotorClass::speedRegister)=255;
	}
	else
	{
		*(DcMotorClass::speedRegister)=demanded_speed;
	}
}

void DcMotorClass::start()
{
	setDirection(direction);
}

void DcMotorClass::stop()
{
	*Port_PIN_A&=~(1<<DcMotorClass::PIN_A);
	*Port_PIN_B&=~(1<<DcMotorClass::PIN_B);
}


void DcMotorClass::contol(Direction demanded_direction, uint8_t demanded_speed)
{
	DcMotorClass::setDirection(demanded_direction);
	DcMotorClass::setSpeed(demanded_speed); 
	DcMotorClass::start();
}
