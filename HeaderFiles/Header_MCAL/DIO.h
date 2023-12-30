/*
 * DIO.h
 *
 * Created: 7/13/2023 12:15:14 PM
 *  Author: GENIUS 1
 */ 


#ifndef DIO_H_
#define DIO_H_

#include "Common_Includes.h"

#define port_pins_total_num 8
typedef enum{
	OUTPUT,
	INFREE,
	INPULL,
	}DIO_PNStatus;
	
typedef enum 
{
	PA=0,
	PB,
	PC,
	PD,
}DIO_Port_Type;

typedef enum{
	LOW=0,
	HIGH,
	}DIO_PNVoltage;

typedef enum{
	PINA0=0,
	PINA1=1,
	PINA2,
	PINA3,
	PINA4,
	PINA5,
	PINA6,
	PINA7,
	PINB0,
	PINB1,
	PINB2,
	PINB3,
	PINB4,
	PINB5,
	PINB6,
	PINB7,
	PINC0, 
	PINC1, 
	PINC2, 
	PINC3, 
	PINC4, 
	PINC5, 
	PINC6, 
	PINC7, 
	PIND0, 
	PIND1, 
	PIND2, 
	PIND3, 
	PIND4, 
	PIND5, 
	PIND6, 
	PIND7, 
	TOTAL_PIN,
	}DIO_Pin;

STATUS DIO_init(void);

STATUS DIO_Write_Pin(DIO_Pin pin,DIO_PNVoltage volt);

STATUS DIO_Write_Port(DIO_Port_Type port,u8 value_of_port);

STATUS DIO_toggle_pin(DIO_Pin pin);

STATUS DIO_read_pin(DIO_Pin pin,u8 *pin_value);

STATUS DIO_read_port(DIO_Port_Type port, u8 *port_value);



#endif /* DIO_H_ */