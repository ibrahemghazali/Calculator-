/*
 * DIO_program.h
 *
 * Created: 9/9/2024 11:11:24 PM
 *  Author: ibrah
 */ 


#ifndef DIO_PROGRAM_H_
#define DIO_PROGRAM_H_

#include "DIO_register.h"
#include "DIO_interface.h"
#include "DIO_private.h"
#include "../../LIBRARY/BIT_MATH.h"
#include "../../LIBRARY/STD_TYPES.h"

/*************************************************************/
/*
@brief :set the val on the pin with high or low
@parameter:port name ,the pin number to set and HIGH or LOW mode
@ret: 0if function work if there is problem on parameters will return 1
*/
/**************************************************************/
uint8 DIO_set_pin_val(uint8 port_name,uint8 pin_number,uint8 val)
{
	uint8 ret=0;
	if(DIO_PORTA==port_name)
	{
		if(HIGH==val)
		{
			SET_BIT(PORTA,pin_number);	
		}
		else if(LOW==val)
		{
			CLEAR_BIT(PORTA,pin_number);
		}
		else
		{
			ret=1;
		}
	}
	else if(DIO_PORTB==port_name)
	{
		if(HIGH==val)
		{
			SET_BIT(PORTB,pin_number);
		}
		else if(LOW==val)
		{
			CLEAR_BIT(PORTB,pin_number);
		}
		else
		{
			ret=1;
		}
	}
	else if(DIO_PORTC==port_name)
	{
		if(HIGH==val)
		{
			SET_BIT(PORTC,pin_number);
		}
		else if(LOW==val)
		{
			CLEAR_BIT(PORTC,pin_number);
		}
		else
		{
			ret=1;
		}
	}
	else if(DIO_PORTD==port_name)
	{
		if(HIGH==val)
		{
			SET_BIT(PORTD,pin_number);
		}
		else if(LOW==val)
		{
			CLEAR_BIT(PORTD,pin_number);
		}
		else
		{
			ret=1;
		}
	}
	else 
	{
		ret=1;
	}
	return ret;
}

/*************************************************************/
/*
@brief :set the val on the pins on the port 
@parameter:port name and the value of pins on the port
@ret: 0if function work if there is problem on parameters will return 1
*/
/**************************************************************/

uint8 DIO_set_port_val(uint8 port_name,uint8 val)
{
	uint8 ret=0;
	if(DIO_PORTA==port_name)
	{
		PORTA=val;
	}
	else if(DIO_PORTB==port_name)
	{
		PORTB=val;
	}
	else if(DIO_PORTC==port_name)
	{
		PORTC=val;
	}
	else if(DIO_PORTD==port_name)
	{
		PORTD=val;
	}
	else 
	{
		ret=1;
	}
	return ret;
}

/*************************************************************/
/*
@brief :get the pin value 
@parameter:port name,pin number and pointer for errors
@ret: value of the pin state and the pointer will return 1 if there is a problem
if ret=2 the pointer is null
*/
/**************************************************************/

uint8 DIO_get_pin_val(uint8 port_name,uint8 pin_number)
{
	uint8 ret=0;
		if(DIO_PORTA==port_name)
		{
			ret=GET_BIT(PINA,pin_number);
		}
		else if(DIO_PORTB==port_name)
		{
			ret=GET_BIT(PINB,pin_number);
		}
		else if(DIO_PORTC==port_name)
		{
			ret=GET_BIT(PINC,pin_number);
		}
		else if(DIO_PORTD==port_name)
		{
			ret=GET_BIT(PIND,pin_number);
		}
		else
		{
			ret=200;
		}
	

	return ret;
}

/*************************************************************/
/*
@brief :get the port value
@parameter:port name and pointer for errors
@ret: value of the port state and the pointer will return 1 if there is a problem
if ret=-1 the pointer is null
*/
/**************************************************************/

sint8 DIO_get_port_val(uint8 port_name,uint8 *ptr_error)
{
	uint8 ret=0;
	if(NULL==ptr_error)
	{
		ret=-1;
	}
	else
	{
		if(DIO_PORTA==port_name)
		{
			ret=PORTA;
		}
		else if(DIO_PORTB==port_name)
		{
			ret=PORTB;
		}
		else if(DIO_PORTC==port_name)
		{
			ret=PORTC;
		}
		else if(DIO_PORTD==port_name)
		{
			ret=PORTD;
		}
		else
		{
			*ptr_error=1;
		}
	}
	return ret;
}


#endif /* DIO_PROGRAM_H_ */