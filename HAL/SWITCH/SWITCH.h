/*
 * SWITCH.h
 *
 * Created: 9/10/2024 3:43:20 AM
 *  Author: ibrah
 */ 


#ifndef SWITCH_H_
#define SWITCH_H_
#include "../../MCAL/DIO/DIO_interface.h"

#define PULL_UP_RESISTOR 1
#define PULL_DOWN_RESISTOR 2
#define BOUNCING 1
#define MAINTAINED 2
#define NULL 0
typedef struct SWITCH_t
{
	uint8 port_name;
	uint8 pin_number;
	uint8 connection_type;
	uint8 switch_type;	
}SWITCH_t;

sint8 SWITCH_get_val(SWITCH_t *switch_details,uint8 *ptr_error);



#endif /* SWITCH_H_ */