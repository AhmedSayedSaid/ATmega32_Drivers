/**
 *******************************************
 * @file    EEPROM.H
 * @author  AHMED SAYED SAID
 * @version 1.0
 * @date    9-7-2023
 * @brief   header file for EEPROM
 * @note    https://github.com/AHMED_SAYED
 *******************************************
**/

#ifndef EEPROM_H_
#define EEPROM_H_

#define EEPROM_SIZE 1024
#include "Common_Includes.h"
STATUS EEPROM_WRITE(u16 Address,u8 Data);
STATUS EEPROM_READ(u16 Address,u8 *Data);




#endif /* EEPROM_H_ */