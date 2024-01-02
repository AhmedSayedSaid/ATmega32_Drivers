/**
 * @file EEPROM.h
 * @author Ahmed Sayed Said
 * @version 1.0
 * @date 9-7-2023
 * @brief Header file for EEPROM functionalities on ATmega32.

 */

#ifndef EEPROM_H_
#define EEPROM_H_

#include "Common_Includes.h"

/* Macro Definitions */
#define EEPROM_SIZE 1024u /* Define the size of EEPROM */

/* Function Declarations */

/**
 * @brief Writes a byte of data to a specific address in the EEPROM.
 * 
 * @param Address The address in the EEPROM where the data is to be written.
 * @param Data The data byte to be written to the EEPROM.
 * @return STATUS Indicates the success or failure of the write operation.
 */
STATUS EEPROM_WRITE(u16 Address, u8 Data);

/**
 * @brief Reads a byte of data from a specific address in the EEPROM.
 * 
 * @param Address The address in the EEPROM from which the data is to be read.
 * @param Data Pointer to a variable where the read data will be stored.
 * @return STATUS Indicates the success or failure of the read operation.
 */
STATUS EEPROM_READ(u16 Address, u8 *Data);

#endif /* EEPROM_H_ */
