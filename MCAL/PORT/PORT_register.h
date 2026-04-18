/*
 * PORT_register.h
 *
 * Created: 9/9/2024 11:49:52 PM
 *  Author: ibrah
 */ 


#ifndef PORT_REGISTER_H_
#define PORT_REGISTER_H_
#include "../../LIBRARY/STD_TYPES.h"
#define PORTA *((uint8 *)0x3B)
#define DDRA *((uint8 *)0x3A)
#define PINA *((uint8 *)0x39)

#define PORTB *((uint8 *)0x38)
#define DDRB *((uint8 *)0x37)
#define PINB *((uint8 *)0x36)

#define PORTC *((uint8 *)0x35)
#define DDRC *((uint8 *)0x34)
#define PINC *((uint8 *)0x33)

#define PORTD *((uint8 *)0x32)
#define DDRD *((uint8 *)0x31)
#define PIND *((uint8 *)0x30)




#endif /* PORT_REGISTER_H_ */