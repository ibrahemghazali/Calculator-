/*
 * KEYPAD_config.h
 *
 * Created: 9/11/2024 3:55:48 PM
 *  Author: ibrah
 */ 


#ifndef KEYPAD_CONFIG_H_
#define KEYPAD_CONFIG_H_

#define COL_NUMBERS 4
#define ROW_NUMBERS 4

#define KEYPAD_port DIO_PORTD
#define KEYPAD_buttons {{'7','8','9','/'},{'4','5','6','*'},{'1','2','3','-'},{'c','0','=','+'}}
	
#define KEYPAD_col0 0
#define KEYPAD_col1 1
#define KEYPAD_col2 2
#define KEYPAD_col3 3


#define KEYPAD_row0 4
#define KEYPAD_row1 5
#define KEYPAD_row2 6
#define KEYPAD_row3 7




#endif /* KEYPAD_CONFIG_H_ */