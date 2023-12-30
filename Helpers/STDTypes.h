/**
 *******************************************
 * @file    STDTypes.h
 * @author  AHMED El_SAYED EL_SAID
 * @version 1.0
 * @date    9-7-2023
 * @brief   HEADER file for standard type 
 * @note    https://github.com/AHMED_SAYED
 *******************************************
 **/ 


#ifndef STDTYPES_H_
#define STDTYPES_H_

typedef  unsigned char u8;
typedef  signed char s8;

typedef  unsigned short u16;
typedef signed short s16;


typedef  unsigned long u32;
typedef  signed long s32;

typedef  float f32;

typedef enum{
	FALSE=0,
	TRUE=1
}bool_t;

#define NULL 0
#define NULLPTR ((void*)0)


#endif /* STDTYPES_H_ */