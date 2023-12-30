/**
 *******************************************
 * @file    Watch dog timer test file.c
 * @author  AHMED SAYED SAID
 * @version 1.0
 * @date    11-7-2023
 * @brief   test the WDT function file uncomment the code section and put the code in the main file .
 * @note    https://github.com/AHMED_SAYED
 *******************************************
**/
/*
#include "Watch_Dog.h"
#include "Common_Includes.h"
#define F_CPU 8000000
// This line defines the frequency of the CPU. This is necessary for delay functions,
// as delay times are calculated based on the CPU frequency.

#include <util/delay.h>
// This is a utility library that provides functions for creating time delays,
// such as _delay_ms() which is used in the code below.

#include "Common_Includes.h"
// common includes that has helper definitions and macros

#define LED_DELAY_MS 150
// This line defines a constant for the amount of time that each LED should be turned on.
// This constant is used in the delay functions in the code below.



//this should not reset the MC because all the leds will take 1.5 s to turn on .
void sequence_leds_with_wdt_no_reset()
{
	
	// This function turns on each LED in sequence, using the watchdog timer to ensure
	// that the microcontroller does not reset during the sequence.

	WDT_Enable(timeout_2100ms);
	// This line enables the watchdog timer with a timeout of 2100 milliseconds.
	// If the watchdog timer is not reset within this time, it will cause the microcontroller to reset.

	for(u8 i = 0; i < 8; i++)
	{
		// This for loop runs eight times, once for each LED.
		
		SET_BIT(PORTC,i);
		// This line turns on the LED at the current index by setting the corresponding bit in PORTC.

		_delay_ms(LED_DELAY_MS);
		// This line creates a delay for the defined amount of time.
		// During this delay, the LED at the current index remains on.
	}

	WDT_Disable();
	// This line disables the watchdog timer after the sequence has completed.
	// This prevents the watchdog timer from causing the microcontroller to reset after the sequence is over.
}

//this should  reset the MC after the third led is on .
void sequence_leds_with_wdt_reset()
{
	// This function is similar to the previous one,
	// but the watchdog timer timeout is set to a shorter duration (1000 milliseconds),
	// so that the micro controller resets before the LED sequence is complete.
	
	WDT_Enable(timeout_520ms);
	// This line enables the watchdog timer with a timeout of 1000 milliseconds.

	for(u8 i = 0; i < 8; i++)
	{
		// This for loop runs eight times, once for each LED.

		SET_BIT(PORTC,i);
		// This line turns on the LED at the current index by setting the corresponding bit in PORTC.

		_delay_ms(LED_DELAY_MS);
		// This line creates a delay for the defined amount of time.
		// During this delay, the LED at the current index remains on.
	}

	WDT_Disable();
	// This line disables the watchdog timer.
	// If the micro controller has not reset due to the watchdog timer, this line prevents it from doing so after the sequence.
}







int main()
{
    // Set Port C as output
    DDRC = 0xFF;
	//uncomment this to test the not reset sequence 
	sequence_leds_with_wdt_no_reset();
	//uncomment this and disable the other function to test the reset function.
	 sequence_leds_with_wdt_reset();
    
    while(1) {};  // Endless loop
    return 0;
}
*/