/*
 * File: DIO_Private.h
 * Author: Ahmed Sayed
 * Created on: 7/13/2023 12:17:25 PM
 * 
 * Description:
 *  This private header file is part of the Digital Input/Output (DIO) driver for the ATmega32.
 *  It defines private data structures and declarations used internally by the DIO driver.
 */

#ifndef DIO_PRIVATE_H_
#define DIO_PRIVATE_H_

#include "DIO.h" /* Include the public interface of DIO driver */

/* External declaration of an array holding the status of each DIO pin. 
 * This array is defined in the DIO driver source file and holds the 
 * configuration status (as input, output, etc.) of each pin.
 */
extern const DIO_PNStatus Pins_Status_Array[TOTAL_PIN];

#endif /* DIO_PRIVATE_H_ */
