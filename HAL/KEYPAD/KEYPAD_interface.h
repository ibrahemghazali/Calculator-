/*
 * KEYPAD_interface.h
 *
 * Created: 9/11/2024 3:56:16 PM
 *  Author: ibrah
 */ 


#ifndef KEYPAD_INTERFACE_H_
#define KEYPAD_INTERFACE_H_

#include "../../LIBRARY/STD_TYPES.h"

#define KEYPAD_NO_INPUT 0xff

uint8 KEYPAD_get_pressed_key(void);




#endif /* KEYPAD_INTERFACE_H_ */