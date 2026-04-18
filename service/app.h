/*
 * app.h
 *
 * Created: 4/17/2026 9:25:42 PM
 *  Author: ibrah
 */ 


#ifndef APP_H_
#define APP_H_



#include "../MCAL/PORT/PORT_interface.h"
#include "../MCAL/PORT/PORT_register.h"
#include "../MCAL/DIO/DIO_interface.h"
#include "../HAL/LED/LED.h"
#include "../HAL/SWITCH/SWITCH.h"
#include "../HAL/CLCD/CLCD_interface.h"
#include "../HAL/KEYPAD/KEYPAD_interface.h"
#define F_CPU 8000000UL
#include "stdio.h"
#include <util/delay.h>



#define VALID_SYNTAX   1
#define INVALID_SYNTAX 0
#define MAX_SYNTAX_LONG 50


uint8 is_operator(char c);

uint8 validate_syntax(char *ptr);

void addtion_subtraction(char *ptr);



void multiplication_division(char *ptr);

uint8 convert_to_number(char *ptr);


void syntax_edit(char *ptr);
#endif /* APP_H_ */