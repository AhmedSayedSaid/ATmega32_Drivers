/**
 * @file SPI_Services.c
 * @author ahmed elsayed elsaid
 * @date 7/26/2023
 * @brief This file contains definitions for SPI functions.
 * @contact ahmed.elsayed.elsaid2@gmail.com
 */

#include "SPI.h"
#include "DIO.h"
/**
 * @brief Initializes the SPI module as a master or slave and sets the SPI speed.
 * @param MS_STATE Specifies whether the SPI module should be configured as a master or slave.
 * @param speed Specifies the desired SPI speed.
 * @return Returns SUCCESS if the initialization was successful, or an error status otherwise.
 */
STATUS SPI_MasterInit(SPI_MasterSlave MS_STATE, SPI_Speed speed) {
    // Check for valid parameters
    if (MS_STATE != SLAVE && MS_STATE != MASTER) {
        return PARAM_ERROR;
    }
    if (speed < fosc_4 || speed > fosc_6) {
        return PARAM_ERROR;
    }

    // Set the SPI clock rate
    if (READ_BIT(speed, 0)) {
        SET_BIT(SPCR, SPR0);
    } else {
        CLR_BIT(SPCR, SPR0);
    }

    if (READ_BIT(speed, 1)) {
        SET_BIT(SPCR, SPR1);
    } else {
        CLR_BIT(SPCR, SPR1);
    }

    // Set the double speed mode
    if (READ_BIT(speed, 2)) {
        SET_BIT(SPSR, SPI2X);
    } else {
        CLR_BIT(SPSR, SPI2X);
    }

    // Set the master/slave mode
    if (MS_STATE == MASTER) {
        SET_BIT(SPCR, MSTR);
    } else {
        CLR_BIT(SPCR, MSTR);
    }
	
		//enable
		SET_BIT(SPCR,SPE);
    return SUCCESS;
}

/**
 * @brief Transmits a byte of data over the SPI bus and receives a byte of data.
 * @param cData The byte of data to transmit.
 * @param recived Pointer to a variable where the received data will be stored.
 * @return Returns SUCCESS if the transmission was successful, or an error status otherwise.
 */
u8 SPI_MasterTransmit(u8 cData) {


    // Start transmission
    SPDR = cData;
	
    // Wait for transmission complete
   while (!(SPSR & (1 << SPIF)));
	


    return SPDR;
}


/**
 * @brief Receives a byte of data over the SPI bus as an SPI slave.
 * @param data Pointer to a variable where the received data will be stored.
 * @return Returns SUCCESS if the reception was successful, or an error status otherwise.
 */
STATUS SPI_SlaveReceive(u8 *data) {
    // Check for valid parameters
    if (data == NULL) {
        return NULL_PTR_ERROR;
    }

    // Wait for reception complete
    while (!(SPSR & (1 << SPIF)));

    // Store received data
    *data = SPDR;

    return SPDR;
}


u8 SPI_SendReceive(u8 data)
{
	SPDR=data;
	
	while(!READ_BIT(SPSR,SPIF));
	
	return SPDR;
}