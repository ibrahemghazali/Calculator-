/*
 * PORT_program.c
 *
 * Created: 9/9/2024 11:48:58 PM
 *  Author: ibrah
 */ 
#include "PORT_private.h"
#include "PORT_register.h"
#include "PORT_interface.h"


void PORT_INIT(void)
{
	DDRA=PORTA_DIR;
	DDRB=PORTB_DIR;
	DDRC=PORTC_DIR;
	DDRD=PORTD_DIR;
	PORTA=PORTA_INIT_VAl;
	PORTB=PORTB_INIT_VAL;
	PORTC=PORTC_INIT_VAL;
	PORTD=PORTD_INIT_VAL;
}