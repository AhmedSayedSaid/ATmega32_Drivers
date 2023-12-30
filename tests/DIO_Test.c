/**
 *******************************************
 * @file    DIO_test.c
 * @author  AHMED SAYED SAID
 * @version 1.0
 * @date    13-7-2023
 * @brief   Test the DIO driver.
 * @note    This file is not included in the build process remove 
 the comment from the code and put it in the main file to start the test 
 *
 * The LEDs on port C are used to indicate test failures:
 * - LED 0 (PC0): Test failure in testDIOInit().
 * - LED 1 (PC1): Test failure in testDIOWritePinInvalidInputs().
 * - LED 2 (PC2): Test failure in testDIOReadPinInvalidInputs().
 * - LED 3 (PC3): Test failure in testDIOTogglePinInvalidInputs().
 * - LED 4 (PC4): Test failure in testDIOWriteReadPin().
 * - LED 5 (PC5): Test failure in testDIOTogglePin().
 * - LED 6 (PC6): Test failure in testDIOWritePortInvalidInputs().
 * - LED 7 (PC7): Test failure in testDIOWriteReadPort().
 *******************************************
 **/
/*
#define F_CPU 8000000 
#include <util/delay.h>

#include "Common_Includes.h"
#include "DIO.h"

#define TEST_ASSERT_EQUAL_INT(expected, actual, led) \
do { \
	if((expected) != (actual)) { \
		DIO_Write_Pin(led, HIGH); \
		while(1); \
	} \
} while(0)

#define TEST_ASSERT_NOT_NULL(ptr, led) \


void testDIOInit() {
    STATUS init_status = DIO_init();
    TEST_ASSERT_EQUAL_INT(SUCCESS, init_status, PINC0);
}

void testDIOWritePinInvalidInputs() {
    STATUS invalid_input_status = DIO_Write_Pin(TOTAL_PIN, HIGH);
    TEST_ASSERT_EQUAL_INT(PARAM_ERROR, invalid_input_status, PINC1);
}

void testDIOReadPinInvalidInputs() {
    DIO_PNVoltage pin_value;
    STATUS invalid_input_status = DIO_read_pin(TOTAL_PIN, &pin_value);
    TEST_ASSERT_EQUAL_INT(PARAM_ERROR, invalid_input_status, PINC2);
}

void testDIOTogglePinInvalidInputs() {
    STATUS invalid_input_status = DIO_toggle_pin(TOTAL_PIN);
    TEST_ASSERT_EQUAL_INT(PARAM_ERROR, invalid_input_status, PINC3);
}

void testDIOWriteReadPin() {
    DIO_PNVoltage pin_value;
    DIO_Write_Pin(PINA0, HIGH);
    DIO_read_pin(PINA0, &pin_value);
    TEST_ASSERT_EQUAL_INT(HIGH, pin_value, PINC4);
}

void testDIOTogglePin() {
    DIO_PNVoltage pin_value;
    DIO_Write_Pin(PINA0, HIGH);
    DIO_toggle_pin(PINA0);
    DIO_read_pin(PINA0, &pin_value);
    TEST_ASSERT_EQUAL_INT(LOW, pin_value, PINC5);
}

void testDIOWritePortInvalidInputs() {
    STATUS invalid_input_status = DIO_Write_Port(5, 0xFF); // 5 is invalid as there are only 4 ports (0 to 3)
    TEST_ASSERT_EQUAL_INT(PARAM_ERROR, invalid_input_status, PINC6);
}
void testDIOWriteReadPort() {
	u8 port_value;
	DIO_Write_Port(PA, 0xFF);
	_delay_ms(10);
	DIO_read_port(PA, &port_value);
	TEST_ASSERT_EQUAL_INT(0xFF, port_value, PINC7);
}

int main() {



	
	testDIOInit();
	
		// Set Port C as output
		DIO_Write_Port(PC, 0x00);
	testDIOWritePinInvalidInputs();

	testDIOReadPinInvalidInputs();

	testDIOTogglePinInvalidInputs();

	testDIOWriteReadPin();

	testDIOTogglePin();

	testDIOWritePortInvalidInputs();

	testDIOWriteReadPort();
	

	// If we reach here, all tests passed
	while(1);
	return 0;
}

*/