/**
*******************************************
* @file    PWM_Generation.c
* @author  AHMED SAYED SAID
* @version 1.0
* @date    20-7-2023
* @brief   Generate a PWM signal with a frequency of 1khz and a duty cycle of 20% using Timer1 fast pwm mode as ICR as top.
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
     * The DIO_init function initializes the DIO module. The Timer1_Init function initializes Timer1 in fast pwm mode with icr1 as TOP and a prescaler of 8.

     */
	DIO_init();
	Timer1_Init(TIMER1_FASTPWM_ICR_TOP_MODE,TIMER0_SCALER_8);
	Timer1_OCRA1Mode(OCRA_NON_INVERTING);
	//this is because the toggle happen the cycle after the last cycle
	ICR1=999;
	OCR1A=199;


	while (1)
	{
	}
}

/**
 * @brief Test environment and results.
 *
 * The output of this code is measured using the input capture unit of an Arduino Uno on pin 8.
 *
 * The measured result is after new calibration of arduino code :

High time (microseconds): 199.88
Low time (microseconds): 799.50
Cycle time (microseconds): 999.38
Duty cycle (%): 20.00
Frequency (Hz): 1000.63



 the expected result.
High time (microseconds): 200
Low time (microseconds): 800
Cycle time (microseconds): 1000
Duty cycle (%): 20.00
Frequency (Hz): 1000.00

 */
