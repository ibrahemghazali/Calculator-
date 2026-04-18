/*
 * DIO_interfernce.h
 *
 * Created: 9/9/2024 11:11:01 PM
 *  Author: ibrah
 */ 


#ifndef DIO_INTERFERNCE_H_
#define DIO_INTERFERNCE_H_
#include "../../LIBRARY/STD_TYPES.h"
#include "DIO_private.h"
uint8 DIO_set_pin_val(uint8 port_name,uint8 pin_number,uint8 val);
uint8 DIO_set_port_val(uint8 port_name,uint8 val);
uint8 DIO_get_pin_val(uint8 port_name,uint8 pin_number);
sint8 DIO_get_port_val(uint8 port_name,uint8 *ptr_error);


#endif /* DIO_INTERFERNCE_H_ */