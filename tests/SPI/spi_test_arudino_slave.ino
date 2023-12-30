/**
 * @file spi_test_arudino_slave.ino
 * @brief This file contains an example of an Arduino slave using SPI communication.
 *
 * This code demonstrates how to use the SPI library to communicate between an Arduino slave and a master device.
 * The slave sends a dummy byte before starting the data exchange to account for the lag in response from the slave.
 * The transmitted data are 0x00 (dummy data), 0x55, 0x66, 0x77, and 0x88.
 * The received data are 0x00, 0xAA, 0xBB, 0xCC, and 0xDD.
 * the pins of the connection with atmega32 are :
  ATmega32A MOSI (pin PB5) to Arduino Uno MOSI (pin 11)
  ATmega32A MISO (pin PB6) to Arduino Uno MISO (pin 12)
  ATmega32A SCK (pin PB7) to Arduino Uno SCK (pin 13)
  ATmega32A SS (pin PB4) to Arduino Uno SS (pin 10)
 * @author Ahmed Elsayd Elsaid
 * @date  7/27/2023
 * @contact ahmed.elsayed.elsaid2@gmail.com
 */

#include <SPI.h>

#define DATA_LENGTH 5 ///< The length of the data to transmit.

/**
 * @brief Set up the Arduino slave.
 *
 * This function sets up the Arduino slave by configuring the MISO pin as output,
 * enabling SPI as a slave, and initializing serial communication.
 */
void setup()
{
    // Set MISO output, all others input
    pinMode(MISO, OUTPUT);

    // Enable SPI as slave
    SPCR |= _BV(SPE);

    // Initialize serial communication
    Serial.begin(9600);
}

/**
 * @brief Main loop of the Arduino slave.
 *
 * This function contains the main loop of the Arduino slave. In each iteration of the loop,
 * the slave sends a dummy byte followed by four bytes of data to the master. The slave also
 * receives and prints five bytes of data from the master.
 */
void loop()
{
    // Data to transmit
    uint8_t data[DATA_LENGTH] = {0x55, 0x66, 0x77, 0x88};

    // Send dummy byte to account for lag in response from slave
    SPDR = 0x00;

    // Receive data from master
    for (int i = 0; i < DATA_LENGTH; i++)
    {
        // Wait for reception of a byte
        while (!(SPSR & _BV(SPIF)))
            ;

        // Read received byte
        uint8_t received_byte = SPDR;

        // Print received byte to serial monitor
        Serial.print("Received byte: ");
        Serial.println(received_byte, HEX);

        // Send response byte
        SPDR = data[i];
    }

    // Print current state to serial monitor
    Serial.println("Data transmission complete");
}
