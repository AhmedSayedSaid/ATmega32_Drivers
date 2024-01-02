/**
 * @file DIO_test.c
 * @author Ahmed Sayed Said
 * @version 1.0
 * @date 13-7-2023
 * @brief Test suite for the DIO driver.
 * @note :you should comment the whole code of all the test cases in order for the project to compile normally .
 *
 * This file contains test cases to validate the functionality of the DIO driver.
 * It is designed to test each function in the DIO driver and indicate any failures 
 * using LEDs connected to Port C of the ATmega32. Each LED corresponds to a specific 
 * test case, and it will light up if the test fails.
 *
 * LED Indications on Port C:
 * - LED 0 (PC0): Failure in testDIOInit().
 * - LED 1 (PC1): Failure in testDIOWritePinInvalidInputs().
 * - LED 2 (PC2): Failure in testDIOReadPinInvalidInputs().
 * - LED 3 (PC3): Failure in testDIOTogglePinInvalidInputs().
 * - LED 4 (PC4): Failure in testDIOWriteReadPin().
 * - LED 5 (PC5): Failure in testDIOTogglePin().
 * - LED 6 (PC6): Failure in testDIOWritePortInvalidInputs().
 * - LED 7 (PC7): Failure in testDIOWriteReadPort().
 */


#define F_CPU 8000000UL
#include <util/delay.h>

#include "Common_Includes.h"
#include "DIO.h"

/* Macro Definitions for Test Assertions */
#define TEST_ASSERT_EQUAL_INT(expected, actual, led) do { \
    if ((expected) != (actual)) { \
        DIO_Write_Pin(led, HIGH); \
        while (1); \
    } \
} while (0)

/* Test Cases Prototypes */
static void testDIOInit(void);
static void testDIOWritePinInvalidInputs(void);
static void testDIOReadPinInvalidInputs(void);
static void testDIOTogglePinInvalidInputs(void);
static void testDIOWriteReadPin(void);
static void testDIOTogglePin(void);
static void testDIOWritePortInvalidInputs(void);
static void testDIOWriteReadPort(void);

/* Main program to run the test cases */
int main(void) {
    DIO_Write_Port(PC, 0x00);  // Set Port C as output for LED indications

    testDIOInit();
    testDIOWritePinInvalidInputs();
    testDIOReadPinInvalidInputs();
    testDIOTogglePinInvalidInputs();
    testDIOWriteReadPin();
    testDIOTogglePin();
    testDIOWritePortInvalidInputs();
    testDIOWriteReadPort();

    // All tests passed if execution reaches here
    while (1);
    return 0;
}

/* Implementation of Test Cases */

static void testDIOInit(void) {
    STATUS init_status = DIO_init();
    TEST_ASSERT_EQUAL_INT(SUCCESS, init_status, PINC0);
}

static void testDIOWritePinInvalidInputs(void) {
    STATUS invalid_input_status = DIO_Write_Pin(TOTAL_PIN, HIGH);
    TEST_ASSERT_EQUAL_INT(PARAM_ERROR, invalid_input_status, PINC1);
}

static void testDIOReadPinInvalidInputs(void) {
    DIO_PNVoltage pin_value;
    STATUS invalid_input_status = DIO_read_pin(TOTAL_PIN, &pin_value);
    TEST_ASSERT_EQUAL_INT(PARAM_ERROR, invalid_input_status, PINC2);
}

static void testDIOTogglePinInvalidInputs(void) {
    STATUS invalid_input_status = DIO_toggle_pin(TOTAL_PIN);
    TEST_ASSERT_EQUAL_INT(PARAM_ERROR, invalid_input_status, PINC3);
}

static void testDIOWriteReadPin(void) {
    DIO_PNVoltage pin_value;
    DIO_Write_Pin(PINA0, HIGH);
    DIO_read_pin(PINA0, &pin_value);
    TEST_ASSERT_EQUAL_INT(HIGH, pin_value, PINC4);
}

static void testDIOTogglePin(void) {
    DIO_PNVoltage pin_value;
    DIO_Write_Pin(PINA0, HIGH);
    DIO_toggle_pin(PINA0);
    DIO_read_pin(PINA0, &pin_value);
    TEST_ASSERT_EQUAL_INT(LOW, pin_value, PINC5);
}

static void testDIOWritePortInvalidInputs(void) {
    STATUS invalid_input_status = DIO_Write_Port(5, 0xFF); // 5 is invalid as there are only 4 ports (0 to 3)
    TEST_ASSERT_EQUAL_INT(PARAM_ERROR, invalid_input_status, PINC6);
}

static void testDIOWriteReadPort(void) {
    u8 port_value;
    DIO_Write_Port(PA, 0xFF);
    _delay_ms(10);
    DIO_read_port(PA, &port_value);
    TEST_ASSERT_EQUAL_INT(0xFF, port_value, PINC7);
}
