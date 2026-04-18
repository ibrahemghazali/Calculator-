/*
 * LED.c
 *
 * Created: 9/10/2024 3:26:19 AM
 *  Author: ibrah
 */
#include "LED.h"
 uint8 LED_turn_led(LED_t *led_data,uint8 mode)
{
	uint8 ret=0;
	if(SOURCE_CONNECTION==led_data->connection_type)
	{
		DIO_set_pin_val(led_data->port_name,led_data->pin_number,mode);
	}	 
	else if(SINK_CONNECTION==led_data->connection_type)
	{
		DIO_set_pin_val(led_data->port_name,led_data->pin_number,!mode);
	}
	else
	{
		ret=1;
	}
	return ret;
}
