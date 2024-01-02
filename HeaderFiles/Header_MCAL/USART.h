/**
 * @file USART.h
 * @date 7/29/2023
 * @brief This file contains declarations for USART service functions.

 */

#ifndef USART_H_
#define USART_H_


#include "Common_Includes.h"

typedef enum{
    ASYNCHRONOUS=0,
    SYNCHRONOUS,
}USART_Mode;

typedef enum{
    FIVE_BITS=0,
    SIX_BITS,
    SEVEN_BITS,
    EIGHT_BITS,
    NINE_BITS,
}USART_CharSize;

typedef enum{
    PARITY_DISABLED=0,
    RESERVED,
    EVEN_PARITY,
    ODD_PARITY,
}USART_ParityMode;

typedef enum{
    ONE_BIT=0,
    TWO_BITS,
}USART_StopBit;

typedef enum{
    RISING_XCKN_EDGE=0,
    FALLING_XCKN_EDGE,
}USART_ClockPolarity;

/**
 * @brief Initializes the USART module with the specified settings.
 * @param mode The USART mode (asynchronous or synchronous).
 * @param charSize The character size (5 to 9 bits).
 * @param parityMode The parity mode (disabled, even, or odd).
 * @param stopBit The number of stop bits (1 or 2).
 * @param clockPolarity The clock polarity (rising XCKn edge or falling XCKn edge).
 * @param baudRate The baud rate.
 * @return Returns SUCCESS if the initialization was successful, or an error status otherwise.
 */
STATUS USART_Init(USART_Mode mode, USART_CharSize charSize, USART_ParityMode parityMode, USART_StopBit stopBit, USART_ClockPolarity clockPolarity, u16 baudRate);

/**
 * @brief Transmits a byte of data over the USART bus.
 * @param data The byte of data to transmit.
 * @return Returns SUCCESS if the transmission was successful, or an error status otherwise.
 */
STATUS USART_Transmit(u8 data);

/**
 * @brief Receives a byte of data over the USART bus.
 * @return Returns the received byte of data.
 */
STATUS USART_Receive(u8 *recive);

/**
 * @brief Flushes the USART data register.
 */
STATUS USART_Flush(void);
#endif /* USART_H_ */
