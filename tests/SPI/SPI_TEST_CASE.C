/**
 * @file
 * @brief This file contains an example of an ATmega32A master using SPI communication.
 *
 * This code demonstrates how to use the SPI library to communicate between an ATmega32A master and an Arduino slave.
 * The master sends five requests to the slave, including a dummy request to account for the lag in response from the slave.
 * The transmitted data are 0x00 (dummy data), 0xAA, 0xBB, 0xCC, and 0xDD.
 * The received data are 0x00 (dummy data), 0x55, 0x66, 0x77, and 0x88.
 *
 * The pins of the connection with ATmega32 are:
 * - ATmega32A MOSI (pin PB5) to Arduino Uno MOSI (pin 11)
 * - ATmega32A MISO (pin PB6) to Arduino Uno MISO (pin 12)
 * - ATmega32A SCK (pin PB7) to Arduino Uno SCK (pin 13)
 * - ATmega32A SS (pin PB4) to Arduino Uno SS (pin 10)
 *
 * @author Ahmed Elsayd Elsaid
 * @date  7/27/2023
 * @contact ahmed.elsayed.elsaid2@gmail.com
 */

#include <string.h>
#include "spi.h"

#define DATA_LENGTH 5 ///< The length of the data to transmit.

/**
 * @brief Main function of the ATmega32A master.
 *
 * This function contains the main loop of the ATmega32A master. In each iteration of the loop,
 * the master sends five requests to the slave, including a dummy request. The master also
 * receives and prints five bytes of data from the slave.
 */
int main(void)
{
	DIO_init();
	LCD_Init();
	// Initialize the SPI module as a master with a speed of fosc/16
	SPI_MasterInit(MASTER, fosc_128);

	// Data to transmit
	u8 data[DATA_LENGTH] = {0x00,0xAA, 0xBB, 0xCC, 0xDD};
	u8 received_data[DATA_LENGTH];

	u8 received;
received=	SPI_MasterTransmit(data[0]);
			LCD_WriteHex(received);
			LCD_WriteChar(" ");
received=	SPI_MasterTransmit(data[1]);
			LCD_WriteHex(received);
			LCD_WriteChar(" ");
received=	SPI_MasterTransmit(data[2]);
				LCD_WriteHex(received);
				LCD_WriteChar(" ");
received=	SPI_MasterTransmit(data[3]);
	LCD_GoTo(1,0);
				LCD_WriteHex(received);
				LCD_WriteChar(" ");
received=	SPI_MasterTransmit(data[4]);
				LCD_WriteHex(received);
				LCD_WriteChar(" ");



	// Verify received data
	u8 expected_data[DATA_LENGTH] = {0x55, 0x66, 0x77, 0x88};
	if (memcmp(received_data, expected_data, DATA_LENGTH) != 0)
	{
		// Handle reception error
	}

	while (1)
	{
		// Main loop
	}
}
