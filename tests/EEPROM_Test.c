/**
 *******************************************
 * @file    EEPROM_test.c
 * @author  AHMED SAYED SAID
 * @version 1.0
 * @date    10-7-2023
 * @brief   test the EEPROM with the led array on port c ,to make it work copy this file content in the main file and remove the multiline comment from the code below
 * @note this file is not included in the build process.
 * @note    https://github.com/AHMED_SAYED
 *******************************************
**/




/*
#define F_CPU 8000000 
#include <util/delay.h>

#include "Common_Includes.h"



void writeTestDataToEEPROM()
{
    // Test values to be stored in EEPROM
    // Each test value is the binary representation of its index
    u16 testAddr = 0;
    
    for(int i = 0; i < 8; i++)
    {
        EEPROM_WRITE(testAddr, i);
        testAddr++;
    }
}

void displayEEPROMData()
{
    // Number of test values
    u8 testValuesCount = 8;
    u16 testAddr = 0;
    u8 readData;

    for(int i = 0; i < testValuesCount; i++)
    {
        EEPROM_READ(testAddr, &readData);
        PORTC = readData;
        _delay_ms(2000);  // 2-second delay
        testAddr++;
    }
}

int main()
{
    // Set Port C as output
    DDRC = 0xFF;

    // Comment out the next line after first run, before power cycle
   // writeTestDataToEEPROM();

    // Uncomment the next line after power cycle to test EEPROM data persistence
    displayEEPROMData();
    
    while(1) {};  // Endless loop
    return 0;
}
*/