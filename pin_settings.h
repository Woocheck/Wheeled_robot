/*
 * pin_settings.h
 *
 * Created: 17.03.2019 21:34:45
 *  Author: Woocheck
*/

#ifndef PIN_SETTINGS_H_
#define PIN_SETTINGS_H_
 #include "avr/io.h"
 
 #define MICROCONTROLER ATMEGA2560-15AU
 #define F_CPU 16000000

 #define DDR_LEFT_A DDRA
 #define DDR_LEFT_B DDRA
 #define DDR_LEFT_ENABLE DDRH
 #define PORT_LEFT_A PORTA
 #define PORT_LEFT_B PORTA
 #define PORT_LEFT_ENABLE PORTH
 #define PIN_LEFT_A PINA7
 #define PIN_LEFT_B PINA5
 #define PIN_LEFT_ENABLE PINH6
 
 #define DDR_RIGHT_A DDRA
 #define DDR_RIGHT_B DDRA
 #define DDR_RIGHT_ENABLE DDRH
 #define PORT_RIGHT_A PORTA
 #define PORT_RIGHT_B PORTA
 #define PORT_RIGHT_ENABLE PORTH
 #define PIN_RIGHT_A PINA3
 #define PIN_RIGHT_B PINA1
 #define PIN_RIGHT_ENABLE PINH5

 #define PWM_DDR_LEFT DDRB
 #define PWM_PIN_LEFT PINB4 
 #define TCCR_LEFT_A TCCR2A
 #define TCCR_LEFT_B TCCR2B
 #define OCR_LEFT OCR2A
 
 #define PWM_DDR_RIGHT DDRH
 #define PWM_PIN_RIGHT PINH6
 #define TCCR_RIGHT_A TCCR2A
 #define TCCR_RIGHT_B TCCR2B
 #define OCR_RIGHT OCR2B
 
#endif /* PIN_SETTINGS_H_ */