/**
 * @file USART.c
 * @date 7/29/2023
 * @brief This file contains definitions for USART functions.
 * @contact ahmed.elsayed.elsaid2@gmail.com
 */

#include "USART.h"

#include "Common_Includes.h"

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
STATUS USART_Init(USART_Mode mode, USART_CharSize charSize, USART_ParityMode parityMode, USART_StopBit stopBit, USART_ClockPolarity clockPolarity, u16 baudRate) {
    // Check for valid parameters
    if (mode != ASYNCHRONOUS && mode != SYNCHRONOUS) {
        return PARAM_ERROR;
    }
    if (charSize < FIVE_BITS || charSize > NINE_BITS) {
        return PARAM_ERROR;
    }
    if (parityMode < PARITY_DISABLED || parityMode > ODD_PARITY) {
        return PARAM_ERROR;
    }
    if (stopBit != ONE_BIT && stopBit != TWO_BITS) {
        return PARAM_ERROR;
    }
    if (clockPolarity != RISING_XCKN_EDGE && clockPolarity != FALLING_XCKN_EDGE) {
        return PARAM_ERROR;
    }
    if (baudRate <= 0) {
        return PARAM_ERROR;
    }

    // Set baud rate
    u16 ubrr = F_CPU/16/baudRate-1;
    UBRRH = (u8)(ubrr>>8);
    UBRRL = (u8)ubrr;

	// normal speed
	CLR_BIT(UCSRA,U2X);
    // Set USART mode
    if (mode == SYNCHRONOUS) {
        SET_BIT(UCSRC, UMSEL);
    } else {
        CLR_BIT(UCSRC, UMSEL);
    }

// Set character size
if (charSize == NINE_BITS) {
	SET_BIT(UCSRB, UCSZ2);
	} else {
	CLR_BIT(UCSRB, UCSZ2);
}
UCSRC = (UCSRC & ~(0x06)) | ((charSize & 0x03) << UCSZ0);


    // Set parity mode
    UCSRC = (UCSRC & ~(0x30)) | (parityMode << UPM0);

    // Set stop bit
    if (stopBit == TWO_BITS) {
        SET_BIT(UCSRC, USBS);
    } else {
        CLR_BIT(UCSRC, USBS);
    }

    // Set clock polarity
    if (clockPolarity == FALLING_XCKN_EDGE) {
        SET_BIT(UCSRC, UCPOL);
    } else {
        CLR_BIT(UCSRC, UCPOL);
    }

    // Enable receiver and transmitter
    SET_BIT(UCSRB, RXEN);
    SET_BIT(UCSRB, TXEN);

    return SUCCESS;
}



/**
 * @brief Transmits a byte of data over the USART bus.
 * @param data The byte of data to transmit.
 * @return Returns SUCCESS if the transmission was successful;
 */
STATUS USART_Transmit(u8 data) {
	
	
    // Wait for empty transmit buffer
    while (!(UCSRA & (1<<UDRE)));
    
    
    // Put data into buffer, sends the data
    UDR = data;
    
    return SUCCESS;
}

/**
 * @brief Receives a byte of data over the USART bus.
 * @param [out] pointer to variable to store the received data.
 * @return Returns the error status.
 */
STATUS USART_Receive(u8 *recive) {
    
     // Check for errors
     if ((UCSRA & ((1<<FE)|(1<<DOR)|(1<<UPE))) != 0) {
         return FAIL;
     }
     
     // Wait for data to be received
     while (!(UCSRA & (1<<RXC)));
     
     // Get and return received data from buffer
     *recive=UDR;
	 return SUCCESS;
}

/**
 * @brief Flushes the USART data register.
 */
STATUS USART_Flush(void){
     u8 dummy;
     while (UCSRA & (1<<RXC)) dummy = UDR;
	 
	 return SUCCESS;
}
