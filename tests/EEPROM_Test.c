/**
 * @file    EEPROM_test.c
 * @author  AHMED SAYED SAID
 * @version 1.0
 * @date    10-7-2023
 * @brief   Test for EEPROM with LED array on port C.
 *          To run this test, copy the contents of this file into the main file.
 */

#define F_CPU 8000000UL 
#include <util/delay.h>
#include "Common_Includes.h"

/**
 * @brief Writes test data to EEPROM.
 * 
 * Each test value written is the binary representation of its index.
 */
void writeTestDataToEEPROM(void)
{
    u16 testAddr = 0u;
    
    for(u8 i = 0u; i < 8u; i++)
    {
        EEPROM_WRITE(testAddr, i);
        testAddr++;
    }
}

/**
 * @brief Displays EEPROM data on LED array.
 * 
 * Reads test values from EEPROM and displays them on Port C LEDs with a 2-second delay.
 */
void displayEEPROMData(void)
{
    const u8 testValuesCount = 8u;
    u16 testAddr = 0u;
    u8 readData = 0u;

    for(u8 i = 0u; i < testValuesCount; i++)
    {
        EEPROM_READ(testAddr, &readData);
        PORTC = readData;
        _delay_ms(2000u);  // 2-second delay
        testAddr++;
    }
}

/**
 * @brief Main function to execute EEPROM test.
 * 
 * @return int Returns 0 upon successful execution.
 */
int main(void)
{
    // Set Port C as output
    DDRC = 0xFFu;

    // Uncomment the next line for initial EEPROM writing, comment out after first run
    // writeTestDataToEEPROM();

    // Uncomment the next line for testing EEPROM data persistence after a power cycle
    displayEEPROMData();
    
    while(1) {};  // Endless loop
    return 0;
}
