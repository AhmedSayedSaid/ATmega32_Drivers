/**
 * @file SPI_Services.h
 * @author ahmed elsayed elsaid
 * @date 7/26/2023
 * @brief This file contains declarations for SPI service functions.
 */

#ifndef SPI_SERVICES_H_
#define SPI_SERVICES_H_

#include "Common_Includes.h"

/**
 * @brief Transmits multiple bytes of data over the SPI bus as an SPI master.
 * @param data Pointer to an array of data to transmit.
 * @param length Number of bytes to transmit.
  * @param data Pointer to an array of data to receive from the slave.
 * @return Returns SUCCESS if the transmission was successful, or an error status otherwise.
 */
STATUS SPI_MasterTransmitMulti(const u8 *data, u32 length,u8 *recived_data) ;

/**
 * @brief Receives multiple bytes of data over the SPI bus as an SPI slave.
 * @param data Pointer to an array where the received data will be stored.
 * @param length Number of bytes to receive.
 * @return Returns SUCCESS if the reception was successful, or an error status otherwise.
 */
STATUS SPI_SlaveReceiveMulti(u8 *data, u32 length);

#endif /* SPI_SERVICES_H_ */
