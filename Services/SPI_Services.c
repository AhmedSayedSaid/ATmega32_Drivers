/**
 * @file SPI_Services.c
 * @author ahmed elsayed elsaid
 * @date 7/26/2023
 * @brief This file contains definitions for SPI service functions.
 */

#include "SPI_Services.h"
/**
 * @brief Transmits multiple bytes of data over the SPI bus as an SPI master.
 * @param data Pointer to an array of data to transmit.
 * @param length Number of bytes to transmit.
 * @param data Pointer to an array of data to receive from the slave.
 * @return Returns SUCCESS if the transmission was successful, or an error status otherwise.
 */
STATUS SPI_MasterTransmitMulti(const u8 *data, u32 length,u8 *recived_data) {
    // Check for valid parameters
    if (data == NULL) {
        return NULL_PTR_ERROR;
    }

    // Transmit data
    for (u32 i = 0; i < length; i++) {
        // Start transmission
        SPDR = data[i];

        // Wait for transmission complete
        while (!(SPSR & (1 << SPIF)));
		//store the data came from the slave.
		//recived_data[i]=SPDR;
		
    }

    return SUCCESS;
}

/**
 * @brief Receives multiple bytes of data over the SPI bus as an SPI slave.
 * @param data Pointer to an array where the received data will be stored.
 * @param length Number of bytes to receive.
 * @return Returns SUCCESS if the reception was successful, or an error status otherwise.
 */
STATUS SPI_SlaveReceiveMulti(u8 *data, u32 length) {
    // Check for valid parameters
    if (data == NULL) {
        return NULL_PTR_ERROR;
    }

    // Receive data
    for (u32 i = 0; i < length; i++) {
        // Wait for reception complete
        while (!(SPSR & (1 << SPIF)));

        // Store received data
        data[i] = SPDR;
    }

    return SUCCESS;
}
