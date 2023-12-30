/**
 * @file usart_services.h
 * @date 7/30/2023
 * @brief This file contains declarations for USART service helper functions.
 * @contact ahmed.elsayed.elsaid2@gmail.com
 */

#ifndef USART_SERVICES_H_
#define USART_SERVICES_H_

#include "USART.h"

/**
 * @brief Calculates the CRC-16 of the given data.
 * @param data Pointer to the data.
 * @param length Length of the data in bytes.
 * @param crc Pointer to a variable to store the calculated CRC-16.
 * @return Returns SUCCESS if the calculation was successful, or an error status otherwise.
 */
STATUS USART_CalculateCRC(u8 *data, u16 length, u16 *crc) ;

/**
 * @brief Sends a string of data over the USART bus.
 * @param string Pointer to the string to send.
 * @return Returns SUCCESS if the transmission was successful, or an error status otherwise.
 */
STATUS USART_SendString(char *string);

/**
 * @brief Receives a string of data over the USART bus.
 * @param buffer Pointer to the buffer to store the received string.
 * @param maxLength Maximum length of the string to receive.
 * @return Returns SUCCESS if the reception was successful, or an error status otherwise.
 */
STATUS USART_ReceiveString(char *buffer, u16 maxLength);

/**
 * @brief Sends a number over the USART bus.
 * @param number The number to send.
 * @return Returns SUCCESS if the transmission was successful, or an error status otherwise.
 */
STATUS USART_SendNumber(u32 number);

/**
 * @brief Receives a number over the USART bus.
 * @param number Pointer to a variable to store the received number.
 * @return Returns SUCCESS if the reception was successful, or an error status otherwise.
 */
STATUS USART_ReceiveNumber(u32*number);

/**
 * @brief Sends data with CRC over the USART bus.
 * @param data Pointer to the data to send.
 * @param length Length of the data in bytes.
 * @return Returns SUCCESS if the transmission was successful, or an error status otherwise.
 */
STATUS USART_SendDataWithCRC(u8*data, u16 length);

/**
 * @brief Receives data with CRC over the USART bus.
 * @param data Pointer to a buffer to store the received data.
 * @param maxLength Maximum length of the data in bytes.
 * @return Returns SUCCESS if the reception was successful, or an error status otherwise.
 */
STATUS USART_ReceiveDataWithCRC(u8*data, u16 maxLength);

#endif /* USART_SERVICES_H_ */
