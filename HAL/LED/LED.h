/*
 * LED.h
 *
 * Created: 9/10/2024 3:26:10 AM
 *  Author: ibrah
 */ 


#ifndef LED_H_
#define LED_H_
#include "../../MCAL/DIO/DIO_interface.h"
#define SOURCE_CONNECTION 1
#define SINK_CONNECTION 2
#define HIGH 1
#define LOW 0
typedef struct LED_t
{
	uint8 port_name;
	uint8 pin_number;
	uint8 connection_type;
}LED_t;

uint8 LED_turn_led(LED_t *led_data,uint8 mode);


#endif /* LED_H_ */