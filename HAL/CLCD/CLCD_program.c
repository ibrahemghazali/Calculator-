/*
 * CLCD_program.c
 *
 * Created: 9/10/2024 3:59:56 AM
 *  Author: ibrah
 */ 
#include "../../MCAL/DIO/DIO_interface.h"
#include "CLCD_interface.h"
#include "CLCD_config.h"
#define F_CPU 8000000UL
#include <util/delay.h>

void CLCD_send_data(uint8 data)
{
	/*set RS pin with 1*/
	DIO_set_pin_val(CONTROL_PORT,CONTROL_PORT_RS,HIGH);
	
	/*set Rw with 0*/
	DIO_set_pin_val(CONTROL_PORT,CONTROL_PORT_RW,LOW);
	
	/*send data*/
	DIO_set_port_val(DATA_PORT,data);
	
	/*enable*/
	DIO_set_pin_val(CONTROL_PORT,CONTROL_PORT_ENABLE,HIGH);
	_delay_ms(2);
	DIO_set_pin_val(CONTROL_PORT,CONTROL_PORT_ENABLE,LOW);
}

void CLCD_send_command(uint8 command)
{
	/*set RS pin with 0*/
	DIO_set_pin_val(CONTROL_PORT,CONTROL_PORT_RS,LOW);
	
	/*set Rw with 0*/
	DIO_set_pin_val(CONTROL_PORT,CONTROL_PORT_RW,LOW);
	
	/*send data*/
	DIO_set_port_val(DATA_PORT,command);
	
	/*enable*/
	DIO_set_pin_val(CONTROL_PORT,CONTROL_PORT_ENABLE,HIGH);
	_delay_ms(2);
	DIO_set_pin_val(CONTROL_PORT,CONTROL_PORT_ENABLE,LOW);
}

void CLCD_INIT(void)
{
	_delay_ms(30);
	/*initialize and modes of line and fonts*/
	CLCD_send_command(0b00111100);
	/*display on off control*/
	CLCD_send_command(0b00001100);
	/*display clear*/
	CLCD_send_command(0b00000001);
}

void CLCD_send_string(const char *string)
{
	uint8 counter=0;
	while(string[counter]!='\0')
	{
		CLCD_send_data(string[counter]);
		counter++;
	}
}

void CLCD_go_to_xy_pos(uint8 x_pos,uint8 y_pos)
{
	uint8 address=64*x_pos+y_pos;
	CLCD_send_command(address+128);
}

static uint8 count_digits(uint8 number)
{
	uint8 number_of_digits=0;
	uint8 counter=1;
	while((number/counter)>0)
	{
		number_of_digits++;
		counter=counter*10;
	}
	return number_of_digits;
}

static uint8 ten_power(uint8 power)
{
	uint8 counter=0;
	uint8 result=1;
	for(counter=0;counter<power;counter++)
	{
		result*=10;
	}
	return result;
}

void CLCD_send_number(uint8 number)
{
	uint8 number_of_digits=0;
	uint8 counter=0;	
	uint8 temp=0;
	if(0==number)
	{
		CLCD_send_data('0');
	}
	else
	{
		number_of_digits=count_digits(number);
		for(counter=1;counter<=number_of_digits;counter++)
		{
			temp=number/ten_power(number_of_digits-counter);
			number%=ten_power(number_of_digits-counter);
			CLCD_send_data(temp+'0');
		}
	}
}

void CLCD_write_special_pattern(uint8 *pattern,uint8 block_number,uint8 x_pos,uint8 y_pos)
{
	uint8 CG_RAM_address=block_number*8;
	uint8 local_counter=0;
	CLCD_send_command(64+CG_RAM_address);
	for(local_counter=0;local_counter<8;local_counter++)
	{
		CLCD_send_data(pattern[local_counter]);
	}
	CLCD_go_to_xy_pos(x_pos,y_pos);
	
}