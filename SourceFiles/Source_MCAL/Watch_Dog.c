/**
 *******************************************
 * @file    Watch_Dog.c
 * @author  AHMED El_SAYED EL_SAID
 * @version 1.0
 * @date    11-7-2023
 * @brief   Source file of the watch dog timer 
 * @note    https://github.com/AHMED_SAYED
 *******************************************
 **/

#include "Watch_Dog.h"
#include "Common_Includes.h"
/**
 *******************************************
 * @brief   Enable watch dog timer 
 * @param WDT_TimeOut (enum)[in] ,the timeOut of the watch dog timer to count down from.
 *******************************************
 **/


STATUS WDT_Enable(WDT_TimeOut TimeOut)
{
	// If the given timeout is greater than the maximum supported timeout (2100ms)
	if(TimeOut>timeout_2100ms)
	{
		// Return an error indicating an invalid parameter
		return PARAM_ERROR;
	}
	else
	{
		// Create a variable to store the register value we're going to write
		u8 register_value_var =0;

		// Set the value of the variable to be the desired timeout, with the watch dog enable (WDE) bit also set
		register_value_var |=(TimeOut|(1<<WDE));

		// Write the computed value to the Watch Dog Timer Control Register (WDTCR)
		WDTCR=register_value_var;
	}

	// If the function executes successfully without returning PARAM_ERROR 
	return SUCCESS;
}


/**
 *******************************************
 * @brief   Enable watch dog timer 
 * @param WDT_TimeOut (enum)[in] ,the timeOut of the watch dog timer to count down from.
 *******************************************
 **/

STATUS WDT_Disable(void)
{
	// Set the Watch Dog Timer Control Register (WDTCR) to enable Watch Dog Timer in timed sequence mode,
	// by setting the WDTOE (Watchdog Turn Off Enable) and WDE (Watchdog Enable) bits
	WDTCR=(1<<WDTOE)|(1<<WDE);

	// Clear the WDE bit to disable the Watch Dog Timer
	CLR_BIT(WDTCR,WDE);

	// Return SUCCESS to indicate the Watch Dog Timer was successfully disabled
	return SUCCESS;
}

