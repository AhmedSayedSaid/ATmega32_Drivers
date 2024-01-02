/* 
 * File: DIO.h
 * Author: Ahmed Sayed
 * Created on: 7/13/2023 12:15:14 PM
 * 
 * Description: 
 *  This file provides an interface for the Digital Input/Output (DIO) functionalities 
 *  for the ATmega32 microcontroller. It includes definitions, types, and function 
 *  declarations for handling digital pins and ports.
 */

#ifndef DIO_H_
#define DIO_H_

#include "Common_Includes.h"

/* Macro Definitions */
#define PORT_PINS_TOTAL_NUM 8u  /* Total number of pins per port */

/* Type Definitions */

/* Enum for DIO pin status */
typedef enum
{
    OUTPUT,     /* Configure pin as output */
    INFREE,     /* Configure pin as input, floating */
    INPULL      /* Configure pin as input, with pull-up resistor */
} DIO_PNStatus;

/* Enum for DIO port type */
typedef enum 
{
    PA = 0,    /* Port A */
    PB,        /* Port B */
    PC,        /* Port C */
    PD         /* Port D */
} DIO_Port_Type;

/* Enum for DIO pin voltage level */
typedef enum
{
    LOW = 0,   /* Low voltage level */
    HIGH       /* High voltage level */
} DIO_PNVoltage;

/* Enum for DIO pin identifiers */
typedef enum
{
    PINA0 = 0,  /* Pin A0 */
    PINA1,      /* Pin A1 */
    PINA2,      /* Pin A2 */
    PINA3,      /* Pin A3 */
    PINA4,      /* Pin A4 */
    PINA5,      /* Pin A5 */
    PINA6,      /* Pin A6 */
    PINA7,      /* Pin A7 */
    PINB0,      /* Pin B0 */
    PINB1,      /* Pin B1 */
    PINB2,      /* Pin B2 */
    PINB3,      /* Pin B3 */
    PINB4,      /* Pin B4 */
    PINB5,      /* Pin B5 */
    PINB6,      /* Pin B6 */
    PINB7,      /* Pin B7 */
    PINC0,      /* Pin C0 */
    PINC1,      /* Pin C1 */
    PINC2,      /* Pin C2 */
    PINC3,      /* Pin C3 */
    PINC4,      /* Pin C4 */
    PINC5,      /* Pin C5 */
    PINC6,      /* Pin C6 */
    PINC7,      /* Pin C7 */
    PIND0,      /* Pin D0 */
    PIND1,      /* Pin D1 */
    PIND2,      /* Pin D2 */
    PIND3,      /* Pin D3 */
    PIND4,      /* Pin D4 */
    PIND5,      /* Pin D5 */
    PIND6,      /* Pin D6 */
    PIND7,      /* Pin D7 */
    TOTAL_PIN   /* Total number of pins */
} DIO_Pin;

/* Function Declarations */

/* Initializes DIO configuration */
STATUS DIO_init(void);

/* Writes voltage level to a specific DIO pin */
STATUS DIO_Write_Pin(DIO_Pin pin, DIO_PNVoltage volt);

/* Writes a value to a specific DIO port */
STATUS DIO_Write_Port(DIO_Port_Type port, u8 value_of_port);

/* Toggles the state of a specific DIO pin */
STATUS DIO_toggle_pin(DIO_Pin pin);

/* Reads the voltage level of a specific DIO pin */
STATUS DIO_read_pin(DIO_Pin pin, u8 *pin_value);

/* Reads the value of a specific DIO port */
STATUS DIO_read_port(DIO_Port_Type port, u8 *port_value);

#endif /* DIO_H_ */
