
/**
*******************************************
* @file    PWM_Generation.c
* @author  AHMED SAYED SAID
* @version 1.0
* @date    20-7-2023
* @brief   Generate a PWM signal with a frequency of 1953Hz and a duty cycle of 40% using Timer1 phase correct pwm mode .
* @note    This file is not included in the build process. Copy the content of it to the main to run the test.
* @note    https://github.com/AHMED_SAYED
*******************************************
**/

#include "DIO.h"
#include "Timers.h"

int main(void)
{
    /**
     * @brief Initialize DIO and Timer0.
     *
     * The DIO_init function initializes the DIO module. The Timer0_Init function initializes Timer0 in phase correct and a prescaler of 8.

     */
	DIO_init();
	TIMER0_Init(TIMER0_PHASECORRECT_MODE,TIMER0_SCALER_8);
	//the result is different from the first test although the same ocr0 because non inverting
	TIMER0_OC0Mode(OC0_NON_INVERTING);
	//this is because the toggle happen the cycle after the last cycle
	OCR0=99;


	while (1)
	{
	}
}

/**
 * @brief Test environment and results.
 *
 * The output of this code is measured using the input capture unit of an Arduino Uno on pin 8.
 *
 * The measured result :

High time (microseconds): 197.88
Low time (microseconds): 311.81
Cycle time (microseconds): 509.69
Duty cycle (%): 38.82
Frequency (Hz): 1961.99






 the expected result.
High time (microseconds): 200
Low time (microseconds): 312
Cycle time (microseconds): 512
Duty cycle (%): 40
Frequency (Hz): 1953.125





 */
