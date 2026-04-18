/*
 * IncFile1.h
 *
 * Created: 9/9/2024 11:02:48 PM
 *  Author: ibrah
 */ 


#ifndef _STD_TYPES_H
#define _STD_TYPES_H
#define cpu_type_64 64
#define cpu_type_32 32
#define cpu_type_16 16
#define cpu_type_8 8

#define cpu_type cpu_type_64

#if(cpu_type==cpu_type_64)
typedef unsigned char boolen;
typedef unsigned char uint8;
typedef unsigned short uint16;
typedef unsigned int uint32;
typedef unsigned long long uint64;
typedef signed char sint8;
typedef signed short sint16;
typedef signed int sint32;
typedef signed long long sint64;
typedef float float32;
typedef double float64;
#elif(cpu_type==cpu_type_32)
typedef unsigned char boolen;
typedef unsigned char uint8;
typedef unsigned short uint16;
typedef unsigned long uint32;
typedef unsigned long long uint64;
typedef signed char sint8;
typedef signed short sint16;
typedef signed long uint32;
typedef signed long long uint64;
typedef float float32;
typedef double float64;
#elif(cpu_type==cpu_type_16)
typedef unsigned char boolen;
typedef unsigned char uint8;
typedef unsigned short uint16;
typedef unsigned int uint32;
typedef unsigned long long uint64;
typedef signed char sint8;
typedef signed short sint16;
typedef signed int uint32;
typedef signed long long uint64;
typedef float float32;
typedef double float64;
#elif(cpu_type==cpu_type_8)
typedef unsigned char boolen;
typedef unsigned char uint8;
typedef unsigned short uint16;
typedef unsigned short long uint24;
typedef unsigned long uint32;
typedef signed char sint8;
typedef signed short sint16;
typedef signed short long sint24;
typedef signed long sint32;
typedef float float32;
typedef double float32;
#endif
#endif /*STD_TYPES.h*/