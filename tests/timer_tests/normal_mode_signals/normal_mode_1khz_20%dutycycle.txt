/**
*******************************************
* @file    PWM_Generation.c
* @author  AHMED SAYED SAID
* @version 1.0
* @date    20-7-2023
* @brief   Generate a PWM signal with a frequency of 1khz and a duty cycle of 20% using Timer0.
* @note    This file is not included in the build process copy the content of it to the main to run the test .
* @note    https://github.com/AHMED_SAYED
*******************************************
**/


/**
 * @brief Test environment and results.
 *
 * The output of this code is measured using the input capture unit of an Arduino Uno on pin 8 .
 * with the help of the code of the arduino provided on the file pwm_measure_arduino.ino .
 *
 * The measured result is which is displayed on serial monitor of arduino (there is a percentage of error due to context switch of the interrupts):
	High time (microseconds): 206.00
	Low time (microseconds): 818.50
	Cycle time (microseconds): 1024.50
	Duty cycle (%): 20.11
	Frequency (Hz): 976.09

 *
 * The expected result is:
 * High time (microseconds): 200
 * Low time (microseconds): 800
 * Cycle time (microseconds): 1000
 * Duty cycle (%): 20
 * Frequency (Hz): 1khz
 */

#include "Common_Includes.h"
#include "DIO.h"
#include "Timers.h"

/**
 * @brief Interrupt Service Routine for Timer0 overflow interrupt.
 *
 * This ISR is called when Timer0 overflows. It toggles the output pin and sets the value of TCNT0 to generate a PWM signal with the desired frequency and duty cycle.
 */


ISR(TIMER0_OVF_vect)
{
	TCNT0=56;
	// 	if (Timer0_OVF_Fptr != NULLPTR)
	// 	{
	// 		Timer0_OVF_Fptr();
	// 	}
	static c1=0;
	c1++;
	if(c1==4)
	{
		DIO_toggle_pin(PINB3);
	}
	if(c1==5)
	{
		DIO_toggle_pin(PINB3);
		c1=0;
	}
}

int main()
{
    /**
     * @brief Initialize DIO and Timer0.
     *
     * The DIO_init function initializes the DIO module. The TIMER0_Init function initializes Timer0 in normal mode with a prescaler
	  of 8. .
     */
	DIO_init();
	TIMER0_Init(TIMER0_NORMAL_MODE,TIMER0_SCALER_8);
	TIMER0_OV_InterruptEnable();
	sei();
	while(1) {
	};  // Endless loop
	return 0;
}



