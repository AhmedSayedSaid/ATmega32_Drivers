/**
 * @file SPI_Services.H
 * @author ahmed elsayed elsaid
 * @date 7/26/2023
 * @brief This file contains declarations for SPI service functions.
 */


#ifndef SPI_H_
#define SPI_H_


#include "Common_Includes.h"

typedef enum{
	SLAVE=0,
	MASTER,
}SPI_MasterSlave;

typedef enum{
	fosc_4=0,
	fosc_16,
	fosc_64,
	fosc_128,
	fosc_2,
	fosc_8,
	fosc_32,
	fosc_6,
}SPI_Speed;

u8 SPI_SendReceive(u8 data);

/**
 * @brief Initializes the SPI module as a master or slave and sets the SPI speed.
 * @param MS_STATE Specifies whether the SPI module should be configured as a master or slave.
 * @param speed Specifies the desired SPI speed.
 * @return Returns SUCCESS if the initialization was successful, or an error status otherwise.
 */
STATUS SPI_MasterInit(SPI_MasterSlave MS_STATE, SPI_Speed speed);
/**
 * @brief Transmits a byte of data over the SPI bus and receives a byte of data.
 * @param cData The byte of data to transmit.
 * @param recived Pointer to a variable where the received data will be stored.
 * @return Returns SUCCESS if the transmission was successful, or an error status otherwise.
 */
u8 SPI_MasterTransmit(u8 cData) ;



/**
 * @brief Receives a byte of data over the SPI bus as an SPI slave.
 * @param data Pointer to a variable where the received data will be stored.
 * @return Returns SUCCESS if the reception was successful, or an error status otherwise.
 */
STATUS SPI_SlaveReceive(u8 *data);



#endif /* SPI_H_ */