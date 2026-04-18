/*
 * BIT_MATH.h
 *
 * Created: 9/9/2024 11:01:10 PM
 *  Author: ibrah
 */ 


#ifndef BIT_MATH_H_
#define BIT_MATH_H_

#define SET_BIT(x,BIT_NUMBER) (x|=(1<<BIT_NUMBER))
#define CLEAR_BIT(x,BIT_NUMBER) (x&=~(1<<BIT_NUMBER))
#define TOGGLE_BIT(x,BIT_NUMBER) (x^=(1<<BIT_NUMBER))
#define GET_BIT(x,BIT_NUMBER) ((x>>BIT_NUMBER)&1)


#endif /* BIT_MATH_H_ */