/**
*******************************************
* @file    EXT_INTERRUPT.c
* @author  AHMED SAYED SAID
* @version 1.0
* @date    12-7-2023
* @brief   source file for external interrupt
* @note    https://github.com/AHMED_SAYED
*******************************************
**/
#include "EXT_INTERRUPT.h"
#include "DIO.h"

/*
pointer to function to be assigned to the isr of the external interrupts.
*/
static void (*INT0_FPtr)(void)=NULLPTR;
static void (*INT1_FPtr)(void)=NULLPTR;
static void (*INT2_FPtr)(void)=NULLPTR;


/*
*@brief Enable the specific external interrupt pin
*@param[in] Pin, external interrupt pin to be enabled
*@return enum STATUS, SUCCESS if operation is successful, PARAM_ERROR if the Pin input is out of range
*/
STATUS EXT_enable_interrupt(Interrupt_Pin Pin)
{
	switch(Pin)
	{
		case INT0_pin:
		SET_BIT(GICR,INT0);
		break;
		case INT1_pin:
		SET_BIT(GICR,INT1);
		break;
		case INT2_pin:
		SET_BIT(GICR,INT2);
		break;
		default:
		return PARAM_ERROR;
	}
	return SUCCESS;
}

/*
*@brief Disable the specific external interrupt pin
*@param[in] Pin, external interrupt pin to be disabled
*@return enum STATUS, SUCCESS if operation is successful, PARAM_ERROR if the Pin input is out of range
*/
STATUS EXT_disable_interrupt(Interrupt_Pin Pin)
{
	switch(Pin)
	{
		case INT0_pin:
		CLR_BIT(GICR,INT0);
		break;
		case INT1_pin:
		CLR_BIT(GICR,INT1);
		break;
		case INT2_pin:
		CLR_BIT(GICR,INT2);
		break;
		default:
		return PARAM_ERROR;
	}
	return SUCCESS;
}

/*
*@brief Set the interrupt logic for a specific external interrupt pin
*@param[in] Pin, external interrupt pin for which logic is to be set
*@param[in] logic, logic to be set for the interrupt (Low_level, Logic_change, Falling_edge, Risign_edge)
*@return enum STATUS, SUCCESS if operation is successful, PARAM_ERROR if the Pin or logic inputs are out of range
*/
STATUS EXT_interrupt_logic_set(Interrupt_Pin Pin ,Interrupt_logic logic)
{
	switch(Pin)
	{
		case INT0_pin:
		switch(logic)
		{
			case Low_level:
			CLR_BIT(MCUCR,ISC00);
			CLR_BIT(MCUCR,ISC01);
			break;
			case Logic_change:
			SET_BIT(MCUCR,ISC00);
			CLR_BIT(MCUCR,ISC01);
			break;
			case Falling_edge:
			CLR_BIT(MCUCR,ISC00);
			SET_BIT(MCUCR,ISC01);
			break;
			case Rising_edge:
			SET_BIT(MCUCR,ISC00);
			SET_BIT(MCUCR,ISC01);
			break;
			default:
			return PARAM_ERROR;
		}
		break;
		case INT1_pin:
		switch(logic)
		{
			case Low_level:
			CLR_BIT(MCUCR,ISC10);
			CLR_BIT(MCUCR,ISC11);
			break;
			case Logic_change:
			SET_BIT(MCUCR,ISC10);
			CLR_BIT(MCUCR,ISC11);
			break;
			case Falling_edge:
			CLR_BIT(MCUCR,ISC10);
			SET_BIT(MCUCR,ISC11);
			break;
			case Rising_edge:
			SET_BIT(MCUCR,ISC10);
			SET_BIT(MCUCR,ISC11);
			break;
			default:
			return PARAM_ERROR;
		}
		break;
		case INT2_pin:
		switch(logic)
		{
			case Low_level:
			return PARAM_ERROR;
			break;
			case Logic_change:
			return PARAM_ERROR;
			break;
			case Falling_edge:
			CLR_BIT(MCUCSR,ISC2);
			break;
			case Rising_edge:
			SET_BIT(MCUCSR,ISC2);
			break;
			default:
			return PARAM_ERROR;
		}
		break;
		default:
		return PARAM_ERROR;
	}
	return SUCCESS;
}

/*
*@brief Set the interrupt logic for a specific external interrupt pin
*@param[in] Pin, external interrupt pin for which logic is to be set
*@param[in] logic, logic to be set for the interrupt (Low_level, Logic_change, Falling_edge, Risign_edge)
*@return enum STATUS, SUCCESS if operation is successful, PARAM_ERROR if the Pin or logic inputs are out of range
*/
STATUS EXT_interrupt_set_callback(Interrupt_Pin Pin,void (*Local_ptr)(void))
{
	if (Local_ptr==NULLPTR)
	{
		return PARAM_ERROR;
	}
	else{
		switch(Pin)
		{
			case INT0_pin:
			INT0_FPtr=Local_ptr;
			break;
			case INT1_pin:
			INT1_FPtr=Local_ptr;
			break;
			case INT2_pin:
			INT2_FPtr=Local_ptr;
			break;
			default:
			return PARAM_ERROR;
		}
	}

	return SUCCESS;
}



ISR(INT0_vect)
{
	if (INT0_FPtr!=NULLPTR)
	{
		INT0_FPtr();
	}
	
	
}

ISR(INT1_vect)
{
	if (INT1_FPtr!=NULLPTR)
	{
		INT1_FPtr();
	}
	
}

ISR(INT2_vect)
{
	if (INT2_FPtr!=NULLPTR)
	{
		INT2_FPtr();
	}
	

	
}