/**
 *******************************************
 * @file    Watch_Dog.h
 * @author  AHMED El_SAYED EL_SAID
 * @version 1.0
 * @date    11-7-2023
 * @brief   HEADER file of the watch dog timer 
 * @note    https://github.com/AHMED_SAYED
 *******************************************
 **/


#ifndef WATCH_DOG_H_
#define WATCH_DOG_H_

typedef enum{
	timeout_16ms=0,
	timeout_32ms,
	timeout_65ms,
	timeout_130ms,
	timeout_260ms,
	timeout_520ms,
	timeout_1000ms,
	timeout_2100ms,
	}WDT_TimeOut;



#endif /* WATCH_DOG_H_ */