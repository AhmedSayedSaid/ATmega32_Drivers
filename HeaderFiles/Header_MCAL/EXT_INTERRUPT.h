/**
 *******************************************
 * @file    EXT_INTERRUPT.H
 * @author  AHMED SAYED SAID
 * @version 1.0
 * @date    12-7-2023
 * @brief   header file for external interrupt

 *******************************************
**/

#ifndef EXT_INTERRUPT_H_
#define EXT_INTERRUPT_H_
#include "Common_Includes.h"
typedef enum{
	INT0_pin=0,
	INT1_pin,
	INT2_pin,
	}Interrupt_Pin;
	
	typedef enum{
		Low_level=0,
		Logic_change,
		Falling_edge,
		Rising_edge,
	}Interrupt_logic;
STATUS EXT_interrupt_set_callback(Interrupt_Pin Pin,void (*Local_ptr)(void));
STATUS EXT_interrupt_logic_set(Interrupt_Pin Pin ,Interrupt_logic logic);
STATUS EXT_enable_interrupt(Interrupt_Pin Pin);
STATUS EXT_disable_interrupt(Interrupt_Pin Pin);

#endif /* EXT_INTERRUPT_H_ */