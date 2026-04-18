/*
 * KEYPAD_program.c
 *
 * Created: 9/11/2024 3:56:30 PM
 *  Author: ibrah
 */ 
#include "KEYPAD_config.h"
#include "KEYPAD_interface.h"
#include "KEYPAD_private.h"
#include "../../MCAL/DIO/DIO_interface.h"
#include "../../MCAL/DIO/DIO_register.h"
uint8 KEYPAD_get_pressed_key(void)
{
	uint8 col_counter=0,row_counter=0;
	uint8 pressed_key=KEYPAD_NO_INPUT;
	static uint8  col_arr[COL_NUMBERS]={KEYPAD_col0,KEYPAD_col1,KEYPAD_col2,KEYPAD_col3};
	static uint8  row_arr[ROW_NUMBERS]={KEYPAD_row0,KEYPAD_row1,KEYPAD_row2,KEYPAD_row3};
	static char KEYPAD_arr[ROW_NUMBERS][COL_NUMBERS]=KEYPAD_buttons;
	for(col_counter=0;col_counter<COL_NUMBERS;col_counter++)
	{
		DIO_set_pin_val(KEYPAD_port,col_arr[col_counter],LOW);
		for(row_counter=0;row_counter<ROW_NUMBERS;row_counter++)
		{
			
			if(!(DIO_get_pin_val(KEYPAD_port,row_arr[row_counter])))
			{
				DDRC=1;
				pressed_key=KEYPAD_arr[row_counter][col_counter];
				while(!(DIO_get_pin_val(KEYPAD_port,row_arr[row_counter])));
				return pressed_key;
			}
		}
		DIO_set_pin_val(KEYPAD_port,col_arr[col_counter],HIGH);
	}
	return pressed_key;
}