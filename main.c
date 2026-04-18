

#include "service/app.h"


char syntax[MAX_SYNTAX_LONG];
uint8 ret=KEYPAD_NO_INPUT;
uint8 counter=0;
uint8 res=0;
#define CLCD_SCREEN_MAX_LINE_POS 15
int main(void)
{
	PORT_INIT();
	CLCD_INIT();
    while(1)
    {
		ret=KEYPAD_get_pressed_key();
		while(ret!='=')
		{
			ret=KEYPAD_get_pressed_key();
			while(KEYPAD_NO_INPUT==ret)
			{
				ret=KEYPAD_get_pressed_key();
			}
			CLCD_send_data(ret);
			
			//clear input and display 
			if('c'==ret)
			{
				for(counter=0;counter<MAX_SYNTAX_LONG;counter++)
				{
					syntax[counter]=0;
				}
				CLCD_go_to_xy_pos(0,0);
				counter=0;
				CLCD_send_command(CLCD_COMMAND_DISPLAY_CLEAR);
			}
			else
			{
				//don't validate = in the syntax calc 
				if(ret!='='){syntax[counter]=ret;}
				counter++;
				if(counter>=CLCD_SCREEN_MAX_LINE_POS)
				{
					CLCD_send_command(CLCD_COMMAND_SHIFT_LEFT);
				}
			}

		}
		uint8 validation=validate_syntax(syntax);
		if(VALID_SYNTAX==validation)
		{
			syntax_edit(syntax);
			multiplication_division(syntax);
			addtion_subtraction(syntax);
			CLCD_send_number(syntax[0]);			
		}
		else
		{
			CLCD_send_command(CLCD_COMMAND_DISPLAY_CLEAR);//clear display
			CLCD_go_to_xy_pos(0,0);
			CLCD_send_string("syntax error");
			_delay_ms(4000);
			CLCD_send_command(CLCD_COMMAND_DISPLAY_CLEAR);//clear display
			CLCD_go_to_xy_pos(0,0);
		}

		
    }
}
