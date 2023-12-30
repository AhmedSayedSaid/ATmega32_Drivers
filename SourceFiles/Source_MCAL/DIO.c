/**
 *******************************************
 * @file    DIO.c
 * @author  GENIUS 1
 * @version 1.0
 * @date    13-7-2023
 * @brief   Source file for digital input/output (DIO) operations.
 * @note    https://github.com/GENIUS1
 *******************************************
**/

#include "Common_Includes.h"
#include "DIO.h"
#include "DIO_Private.h"

/**
 * @brief   Initializes the DIO pins according to their defined configurations.
 * @return  enum STATUS indicating success or failure of the operation.
 */
STATUS DIO_init(void)
{
	for (u8 i=PINA0;i<TOTAL_PIN;i++)
	{
		DIO_Port_Type port_type =i/port_pins_total_num;
		u8 pin_num =i%port_pins_total_num;
		switch(port_type)
		{
			case PA:
			if(Pins_Status_Array[i]==INFREE)
			{
				CLR_BIT(PORTA,pin_num);
				CLR_BIT(DDRA,pin_num);
			}
			else if(Pins_Status_Array[i]==INPULL)
			{
				SET_BIT(PORTA,pin_num);
				CLR_BIT(DDRA,pin_num);
			}
			else if(Pins_Status_Array[i]==OUTPUT)
			{
				CLR_BIT(PORTA,pin_num);
				SET_BIT(DDRA,pin_num);
			}
			else{
				return PARAM_ERROR;
			}
			break;
			case PB:
			if(Pins_Status_Array[i]==INFREE)
			{
				CLR_BIT(PORTB,pin_num);
				CLR_BIT(DDRB,pin_num);
			}
			else if(Pins_Status_Array[i]==INPULL)
			{
				SET_BIT(PORTB,pin_num);
				CLR_BIT(DDRB,pin_num);
			}
			else if(Pins_Status_Array[i]==OUTPUT)
			{
				CLR_BIT(PORTB,pin_num);
				SET_BIT(DDRB,pin_num);
			}
			else{
				return PARAM_ERROR;
			}
			break;
			case PC:
			if(Pins_Status_Array[i]==INFREE)
			{
				CLR_BIT(PORTC,pin_num);
				CLR_BIT(DDRC,pin_num);
			}
			else if(Pins_Status_Array[i]==INPULL)
			{
				SET_BIT(PORTC,pin_num);
				CLR_BIT(DDRC,pin_num);
			}
			else if(Pins_Status_Array[i]==OUTPUT)
			{
				CLR_BIT(PORTC,pin_num);
				SET_BIT(DDRC,pin_num);
			}
			else{
				return PARAM_ERROR;
			}
			break;
			case PD:
			if(Pins_Status_Array[i]==INFREE)
			{
				CLR_BIT(PORTD,pin_num);
				CLR_BIT(DDRD,pin_num);
			}
			else if(Pins_Status_Array[i]==INPULL)
			{
				SET_BIT(PORTD,pin_num);
				CLR_BIT(DDRD,pin_num);
			}
			else if(Pins_Status_Array[i]==OUTPUT)
			{
				CLR_BIT(PORTD,pin_num);
				SET_BIT(DDRD,pin_num);
			}
			else{
				return PARAM_ERROR;
			}
			break;
			default:
			return PARAM_ERROR;
			
		}
	}
	return SUCCESS;
}


/**
 * @brief   Writes a HIGH or LOW value to a specified DIO pin.
 * @param[in] pin    The pin to write to.
 * @param[in] volt   The value to write (HIGH or LOW).
 * @return  enum STATUS indicating success or failure of the operation.
 */
STATUS DIO_Write_Pin(DIO_Pin pin,DIO_PNVoltage volt)
{
	if(pin>=TOTAL_PIN||volt>HIGH||volt<LOW)
	{
		return PARAM_ERROR;
	}
	else
	{
		DIO_Port_Type port=pin/port_pins_total_num;
		u8 pin_num=pin%port_pins_total_num;
		if(volt==HIGH)
		{
			switch(port)
			{
				case PA:
				SET_BIT(PORTA,pin_num);
				break;
				case PB:
				SET_BIT(PORTB,pin_num);
				break;
				case PC:
				SET_BIT(PORTC,pin_num);
				break;
				case PD:
				SET_BIT(PORTD,pin_num);
				break;
				default:
				return FAIL;
			}
			
		}else if (volt ==LOW)
		{
			
			switch(port)
			{
				case PA:
				CLR_BIT(PORTA,pin_num);
				break;
				case PB:
				CLR_BIT(PORTB,pin_num);
				break;
				case PC:
				CLR_BIT(PORTC,pin_num);
				break;
				case PD:
				CLR_BIT(PORTD,pin_num);
				break;
				default:
				return FAIL;
			}

		}
		return SUCCESS;
	}
}

/**
 * @brief   Writes an 8-bit value to a specified DIO port.
 * @param[in] port           The port to write to.
 * @param[in] value_of_port  The 8-bit value to write to the port.
 * @return  enum STATUS indicating success or failure of the operation.
 */
STATUS DIO_Write_Port(DIO_Port_Type port,u8 value_of_port)
{

	switch(port)
	{
		case PA:
		PORTA=value_of_port;
		break;
		case PB:
		PORTB=value_of_port;
		break;
		case PC:
		PORTC=value_of_port;
		break;
		case PD:
		PORTD=value_of_port;
		break;
		default:
		return PARAM_ERROR;
	}
	_delay_ms(1);
	return SUCCESS;
}

/**
 * @brief   Toggles the value of a specified DIO pin.
 * @param[in] pin    The pin to toggle.
 * @return  enum STATUS indicating success or failure of the operation.
 */
STATUS DIO_toggle_pin(DIO_Pin pin)
{
	if(pin>TOTAL_PIN)
	{
		return PARAM_ERROR;
	}
	else
	{
		DIO_Port_Type port=pin/port_pins_total_num;
		u8 pin_num=pin%port_pins_total_num;
		switch(port)
		{
			case PA:
			TOG_BIT(PORTA,pin_num);
			break;
			case PB:
			TOG_BIT(PORTB,pin_num);
			break;
			case PC:
			TOG_BIT(PORTC,pin_num);
			break;
			case PD:
			TOG_BIT(PORTD,pin_num);
			break;
			default:
			return PARAM_ERROR;
		}
	}
	return SUCCESS;
}

/**
 * @brief   Reads the value of a specified DIO pin.
 * @param[in] pin       The pin to read from.
 * @param[out] pin_value  Pointer to store the value of the pin.
 * @return  enum STATUS indicating success or failure of the operation.
 */
STATUS DIO_read_pin(DIO_Pin pin,DIO_PNVoltage *pin_value)
{
	if(pin_value==NULL)
	{
		return NULL_PTR_ERROR;
	}
	else if(pin>=TOTAL_PIN)
	{
		return PARAM_ERROR;
	}
	else
	{
		DIO_Port_Type port=pin/port_pins_total_num;
		u8 pin_num =pin%port_pins_total_num;
		switch(port)
		{
			case PA:
			*pin_value=READ_BIT(PNA,pin_num);
			break;
			case PB:
			*pin_value=READ_BIT(PNB,pin_num);
			break;
			case PC:
			*pin_value=READ_BIT(PNC,pin_num);
			break;
			case PD:
			*pin_value=READ_BIT(PND,pin_num);
			break;
			default:
			return PARAM_ERROR;
		}
	}
	return SUCCESS;
}

/**
 * @brief   Reads the value of a specified DIO port.
 * @param[in] port        The port to read from.
 * @param[out] port_value  Pointer to store the value of the port.
 * @return  enum STATUS indicating success or failure of the operation.
 */
STATUS DIO_read_port(DIO_Port_Type port, u8 *port_value)
{
	if(port_value==NULL)
	{
		return NULL_PTR_ERROR;
	}
	else if(port>PD)
	{
		return PARAM_ERROR;
	}
	else
	{
		switch(port)
		{
			case PA:
			*port_value= PNA;
			break;
			case PB:
			*port_value= PNB;
			break;
			case PC:
			*port_value= PNC;
			break;
			case PD:
			*port_value= PND;
			break;
			default:
			return PARAM_ERROR;
		}
		
	}
	return SUCCESS;
}