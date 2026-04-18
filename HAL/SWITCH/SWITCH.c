/*
 * SWITCH.c
 *
 * Created: 9/10/2024 3:43:30 AM
 *  Author: ibrah
 */ 
#include <util/delay.h>
#include "SWITCH.h"
sint8 SWITCH_get_val(SWITCH_t *switch_details,uint8 *ptr_error)
{
	sint8 ret=0;
	if(NULL==ptr_error)
	{
		ret=-1;
	}
	else
	{
		if(BOUNCING==switch_details->switch_type)
		{
			if(PULL_DOWN_RESISTOR==switch_details->connection_type)
			{
				ret=DIO_get_pin_val(switch_details->port_name,switch_details->pin_number);
				_delay_ms(250);
			}
			else if(PULL_UP_RESISTOR==switch_details->connection_type)
			{
				ret=!(DIO_get_pin_val(switch_details->port_name,switch_details->pin_number));
				_delay_ms(250);
			}
			else
			{
			}
		}
		else if(MAINTAINED==switch_details->switch_type)
		{
			if(PULL_DOWN_RESISTOR==switch_details->connection_type)
			{
				ret=DIO_get_pin_val(switch_details->port_name,switch_details->pin_number);
			}
			else if(PULL_UP_RESISTOR==switch_details->connection_type)
			{
				ret=!(DIO_get_pin_val(switch_details->port_name,switch_details->pin_number));
			}
			else
			{
			}
		}
		else
		{
			*ptr_error=1;
		}
	}
	return ret;
}