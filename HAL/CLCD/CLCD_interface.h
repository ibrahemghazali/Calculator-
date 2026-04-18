/*
 * CLCD_interface.h
 *
 * Created: 9/10/2024 3:59:41 AM
 *  Author: ibrah
 */ 


#ifndef CLCD_INTERFACE_H_
#define CLCD_INTERFACE_H_


#define CLCD_COMMAND_DISPLAY_CLEAR	0b00000001
#define CLCD_COMMAND_SHIFT_LEFT		0b00011000


void CLCD_send_data(uint8 data);
void CLCD_send_command(uint8 command);
void CLCD_INIT(void);
void CLCD_send_string(const char *string);
void CLCD_go_to_xy_pos(uint8 x_pos,uint8 y_pos);
void CLCD_write_special_pattern(uint8 *pattern,uint8 block_number,uint8 x_pos,uint8 y_pos);
void CLCD_send_number(uint8 number);





#endif /* CLCD_INTERFACE_H_ */