/**
 *******************************************
 * @file    EEPROM.c
 * @author  AHMED SAYED SAID
 * @version 1.0
 * @date    9-7-2023
 * @brief   Source file for EEPROM
 * @note    https://github.com/AHMED_SAYED
 *******************************************
**/

#include "EEPROM.h"



/*
*@brief write to the EEPROM
*@param[in] Write_Address, address to write to in the EEPROM
*@param[in] DATA, data to write to in the EEPROM
*@return enum STATUS.
*/

STATUS EEPROM_WRITE(u16 Address,u8 Data)
{
	   // Check if the address is within the valid range
	   if (Address >= EEPROM_SIZE)
	   {
		   // Address is out of range, return failure status
		   return PARAM_ERROR;
	   }
	/*wait for the previous write operation to be finished
	,while writing operation this bit is 1*/
	while(READ_BIT(EECR,EEWE));
	/*write the address register */
	WRITE_NUM_BITS(EEAR,Address,10);
	/*write the data register */
	WRITE_NUM_BITS(EEDR,Data,8);
	/*enable the master write enable bit to start writing */
	SET_BIT(EECR,EEMWE);
	/*within than four cycles of writing EEMWE set the EEWE bit to write the data 
	to the given address*/
	SET_BIT(EECR,EEWE);
	
	return SUCCESS;
}


/*
*@brief READ from the EEPROM
*@param[in] Write_Address, address to write from in the EEPROM
*@param[out] DATA, data that is coming from EEPROM.
*@return enum STATUS.
*/

STATUS EEPROM_READ(u16 Address,u8 *Data)
{
	   // Check if the address is within the valid range
	   if (Address >= EEPROM_SIZE)
	   {
		   // Address is out of range, return failure status
		   return PARAM_ERROR;
	   }
	/*wait for the previous write operation to be finished
	,while writing operation this bit is 1*/
	while(READ_BIT(EECR,EEWE));
	/*write the address register */
	WRITE_NUM_BITS(EEAR,Address,10);
	
	/*enable the EEROM READ ENABLE BIT */
	SET_BIT(EECR,EERE);
	
	/*Read the data coming from the EERPOM from the EEPROM DATA REGISTER*/
	*Data=EEDR;
	
	return SUCCESS;
}
