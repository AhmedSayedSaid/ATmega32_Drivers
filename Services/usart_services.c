/**
 * @file usart_services.c
 * @date 7/30/2023
 * @brief This file contains definitions for USART service helper functions.
 * @contact ahmed.elsayed.elsaid2@gmail.com
 */

#include "usart_services.h"

/**
 * @brief Sends data with CRC over the USART bus.
 * @param data Pointer to the data to send.
 * @param length Length of the data in bytes.
 * @return Returns SUCCESS if the transmission was successful, or an error status otherwise.
 */
STATUS USART_SendDataWithCRC(u8*data, u16 length) {
    // Send data
    for (u16 i = 0; i < length; i++) { // Iterate over each byte of data
        STATUS transmitStatus = USART_Transmit(data[i]); // Transmit the current byte of data using the USART_Transmit function
        if (transmitStatus != SUCCESS) { // If there was an error during transmission
            return FAIL; // Return the error status
        }
    }

    // Calculate and send CRC
    u16 crc;
	  USART_CalculateCRC(data, length,&crc); // Calculate the CRC of the data using the USART_CalculateCRC function
    STATUS transmitStatus = USART_Transmit((crc >> 8) & 0xFF); // Transmit the high byte of the calculated CRC value using the USART_Transmit function
    if (transmitStatus != SUCCESS) { // If there was an error during transmission
        return FAIL; // Return the error status
    }
    transmitStatus = USART_Transmit(crc & 0xFF); // Transmit the low byte of the calculated CRC value using the USART_Transmit function
    if (transmitStatus != SUCCESS) { // If there was an error during transmission
        return FAIL; // Return the error status
    }

    return SUCCESS; // Return SUCCESS to indicate that the transmission was successful
}


/**
 * @brief Receives data with CRC over the USART bus.
 * @param data Pointer to a buffer to store the received data.
 * @param maxLength Maximum length of the data in bytes.
 * @return Returns SUCCESS if the reception was successful, or an error status otherwise.
 */
STATUS USART_ReceiveDataWithCRC(u8*data, u16 maxLength) {
    // Receive data
    for (u16 i = 0; i < maxLength; i++) { // Iterate over each byte of data to receive
        STATUS receiveStatus = USART_Receive(&data[i]); // Receive a byte of data using the USART_Receive function and store it in the buffer
        if (receiveStatus != SUCCESS) { // If there was an error during reception
            return receiveStatus; // Return the error status
        }
    }

    // Receive and check CRC
    u8 crcData[2]; 
    STATUS receiveStatus = USART_Receive(&crcData[0]); // Receive a byte of data using the USART_Receive function and store it in crcData[0]
    if (receiveStatus != SUCCESS) { // If there was an error during reception 
        return receiveStatus; // Return the error status 
    } 
    receiveStatus = USART_Receive(&crcData[1]); 
    if (receiveStatus != SUCCESS) { 
        return receiveStatus;
    }
    
    u16 receivedCRC = ((u16)crcData[0] << 8) | crcData[1]; // Combine the two received bytes to form the received CRC value
    u16 calculatedCRC ;
	USART_CalculateCRC(data, maxLength,&calculatedCRC); // Calculate the CRC of the received data using the USART_CalculateCRC function
   if (receivedCRC != calculatedCRC) { // If the received CRC value does not match the calculated CRC value
	   return FAIL; // Return FAIL to indicate a failure
   }

   return SUCCESS; // Return SUCCESS to indicate that the reception was successful
   }
   

/**
 * @brief Sends a string of data over the USART bus.
 * @param string Pointer to the string to send.
 * @return Returns SUCCESS if the transmission was successful, or an error status otherwise.
 */
STATUS USART_SendString(char *string) {
    while (*string) { // Iterate over each character in the string
        STATUS transmitStatus = USART_Transmit(*string++); // Transmit the current character using the USART_Transmit function
        if (transmitStatus != SUCCESS) { // If there was an error during transmission
            return FAIL; // Return the error status
        }
    }
    return SUCCESS; // Return SUCCESS to indicate that the transmission was successful
}


/**
 * @brief Receives a string of data over the USART bus.
 * @param buffer Pointer to the buffer to store the received string.
 * @param maxLength Maximum length of the string to receive.
 * @return Returns SUCCESS if the reception was successful, or an error status otherwise.
 */
STATUS USART_ReceiveString(char *buffer, u16 maxLength) {
    u8 receivedByte;
    u16 i;
    for (i = 0; i < maxLength - 1; i++) { // Iterate over each character in the string to receive
        STATUS receiveStatus = USART_Receive(&receivedByte); // Receive a byte of data using the USART_Receive function and store it in receivedByte
        if (receiveStatus != SUCCESS) { // If there was an error during reception
            buffer[i] = '\0'; // Terminate the received string with a null character
            return receiveStatus; // Return the error status
        }
        buffer[i] = receivedByte; // Store the received byte in the buffer
        if (receivedByte == '\0') { // If the received byte is a null character (indicating the end of the string)
            break; // Break out of the loop
        }
    }
    buffer[i] = '\0'; // Terminate the received string with a null character
    return SUCCESS; // Return SUCCESS to indicate that the reception was successful
}

/**
 * @brief Sends a number over the USART bus.
 * @param number The number to send.
 * @param status Pointer to a variable to store the status of the function.
 */
STATUS USART_SendNumber(u32 number) {
    u8 data[4];
    data[0] = (number >> 24) & 0xFF; // Extract and store the most significant byte of the number in data[0]
    data[1] = (number >> 16) & 0xFF; // Extract and store the second most significant byte of the number in data[1]
    data[2] = (number >> 8) & 0xFF; // Extract and store the third most significant byte of the number in data[2]
    data[3] = number & 0xFF; // Extract and store the least significant byte of the number in data[3]
    for (u8 i = 0; i < 4; i++) { // Iterate over each byte in data[]
        STATUS transmitStatus = USART_Transmit(data[i]); // Transmit the current byte using the USART_Transmit function
        if (transmitStatus != SUCCESS) { // If there was an error during transmission
             
            return FAIL; 
        }
    }
    return SUCCESS;
}

/**
 * @brief Receives a number over the USART bus.
 * @param number Pointer to a variable to store the received number.
 * @param status Pointer to a variable to store the status of the function.
 */
STATUS USART_ReceiveNumber(u32*number) {
    u8 data[4]; // Create an array of 4 bytes to store the received data
    for (u8 i = 0; i < 4; i++) { // Iterate over each byte in data[]
        STATUS receiveStatus = USART_Receive(&data[i]); // Receive a byte of data using the USART_Receive function and store it in data[i]
        if (receiveStatus != SUCCESS) { // If there was an error during reception
            return FAIL;
        }
    }
    *number = ((u32)data[0] << 24) | ((u32)data[1] << 16) | ((u32)data[2] << 8) | data[3]; // Combine the four received bytes to form the received number and store it in the variable pointed to by number
    return SUCCESS; // Set the status to indicate success
}



/**
 * @brief Calculates the CRC-16 of the given data.
 * @param data Pointer to the data.
 * @param length Length of the data in bytes.
 * @param crc Pointer to a variable to store the calculated CRC-16.
 * @return Returns SUCCESS if the calculation was successful, or an error status otherwise.
 */
STATUS USART_CalculateCRC(u8 *data, u16 length, u16 *crc) {
    if (data == NULL || crc == NULL) { // Check for valid parameters
        return PARAM_ERROR;
    }
    u16 calculatedCRC = 0xFFFF; // Initialize the CRC value
    for (u16 i = 0; i < length; i++) { // Iterate over each byte of data
        calculatedCRC ^= data[i]; // XOR the current byte of data with the current CRC value
        for (u8 j = 0; j < 8; j++) { // Iterate over each bit of the current byte
            if (calculatedCRC & 1) { // If the least significant bit of the current CRC value is 1
                calculatedCRC = (calculatedCRC >> 1) ^ 0xA001; // Shift the CRC value to the right by one bit and XOR it with the polynomial 0xA001
            } else { // If the least significant bit of the current CRC value is 0
                calculatedCRC = calculatedCRC >> 1; // Shift the CRC value to the right by one bit
            }
        }
    }
    *crc = calculatedCRC; // Store the calculated CRC value in the variable pointed to by crc
    return SUCCESS; // Return SUCCESS to indicate that the calculation was successful
}
