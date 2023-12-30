/**
*******************************************
* @file    PWM_Generation.c
* @author  AHMED SAYED SAID
* @version 1.0
* @date    12-7-2023
* @brief   Generate a PWM signal with a frequency of 5kHz and a duty cycle of 30% using Timer0.
* @note    This file is not included in the build process.
* @note    https://github.com/AHMED_SAYED
*******************************************
**/

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
	static u8 flag=0;

	if(flag==0)
	{
		DIO_Write_Pin(PINB3,HIGH);
		flag=1;
		TCNT0=196;
	}
	else if(flag==1)
	{
		DIO_Write_Pin(PINB3,LOW);
		flag=0;
		TCNT0=116;
	}
}

int main()
{
    /**
     * @brief Initialize DIO and Timer0.
     *
     * The DIO_init function initializes the DIO module. The TIMER0_Init function initializes Timer0 in normal mode with a prescaler
	  of 8. The initial value of TCNT0 is set to 116 to generate the desired PWM signal.
     */
	DIO_init();
	TIMER0_Init(TIMER0_NORMAL_MODE,TIMER0_SCALER_8);
	TCNT0=116;
	TIMER0_OV_InterruptEnable();
	sei();
	while(1) {
	};  // Endless loop
	return 0;
}

/**
 * @brief Test environment and results.
 *
 * The output of this code is measured using the input capture unit of an Arduino Uno on pin 8 .
 * with the help of the code of the arduino provided on the file pwm_measure_arduino.ino .
 *
 * The measured result is which is displayed on serial monitor (there is a percentage of error due to context switch of the interrupts:
 * High time (microseconds): 72.81
 * Low time (microseconds): 152.06
 * Cycle time (microseconds): 224.88
 * Duty cycle (%): 32.38
 * Frequency (Hz): 4446.91
 *
 * The expected result is:
 * High time (microseconds): 60
 * Low time (microseconds): 140
 * Cycle time (microseconds): 200
 * Duty cycle (%): 30
 * Frequency (Hz): 5000
 */
