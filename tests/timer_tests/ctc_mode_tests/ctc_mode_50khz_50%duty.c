/**
*******************************************
* @file    PWM_Generation.c
* @author  AHMED SAYED SAID
* @version 1.0
* @date    20-7-2023
* @brief   Generate a PWM signal with a frequency of 50kHz and a duty cycle of 50% using Timer1.
* @note    This file is not included in the build process. Copy the content of it to the main to run the test.
* @note    https://github.com/AHMED_SAYED
*******************************************
**/

#include "DIO.h"
#include "Timers.h"

int main(void)
{
    /**
     * @brief Initialize DIO and Timer1.
     *
     * The DIO_init function initializes the DIO module. The Timer1_Init function initializes Timer1 in CTC mode with OCR1A as TOP and a prescaler of 8.
	  The OCR1A register is set to 50000 to generate the desired PWM signal.
     */
	DIO_init();
	Timer1_Init(TIMER1_CTC_OCRA_TOP_MODE,TIMER0_SCALER_8);
	OCR1A=10;
	Timer1_OCRA1Mode(OCRA_TOGGLE);
	
	while (1)
	{
	}
}

/**
 * @brief Test environment and results.
 *
 * The output of this code is measured using the input capture unit of an Arduino Uno on pin 8.
  The test environment consists of an oscilloscope connected to the output pin to visualize the PWM signal.
 *
 * The measured result is after new calibration of arduino code :

High time (microseconds): 10.00
Low time (microseconds): 10.00
Cycle time (microseconds): 20.00
Duty cycle (%): 50.00
Frequency (Hz): 50000.00

 *
 * The expected result is:
 * High time (microseconds): 10.0
 * Low time (microseconds): 10.0
 * Cycle time (microseconds): 20.0
 * Duty cycle (%): 50.00%
 * Frequency (kHz): 50khz 
 */
