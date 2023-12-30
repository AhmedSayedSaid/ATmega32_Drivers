/**
 *******************************************
 * @file    EXT_INTERRUPT_test.c
 * @author  AHMED SAYED SAID
 * @version 1.0
 * @date    12-7-2023
 * @brief   Test the external interrupt by toggling the LED array on port C on each interrupt
 * @note    This file is not included in the build process.
 * @note    https://github.com/AHMED_SAYED
 *******************************************
**/
/*
#define F_CPU 8000000 
#include <util/delay.h>

#include "Common_Includes.h"
#include "EXT_INTERRUPT.h"
#include "DIO.h"

// Callbacks for each interrupt pin
void INT0_callback()
{
    DIO_Write_Pin(PINC0,HIGH); // Toggle the first LED on Port C
}

void INT1_callback()
{
    DIO_Write_Pin(PINC1,HIGH); // Toggle the second LED on Port C
}

// void INT2_callback()
// {
//     DIO_Write_Pin(PINC2,HIGH); // Toggle the third LED on Port C
// }

void setup_interrupts()
{
    // Setup callback for each interrupt pin
    EXT_interrupt_set_callback(INT0_pin, INT0_callback);
    EXT_interrupt_set_callback(INT1_pin, INT1_callback);
 //   EXT_interrupt_set_callback(INT2_pin, INT2_callback);

    // Enable each interrupt pin
    EXT_enable_interrupt(INT0_pin);
    EXT_enable_interrupt(INT1_pin);
  //  EXT_enable_interrupt(INT2_pin);

    // Set the interrupt logic for each interrupt pin
    EXT_interrupt_logic_set(INT0_pin, Logic_change);
    EXT_interrupt_logic_set(INT1_pin, Logic_change);
   // EXT_interrupt_logic_set(INT2_pin, Rising_edge);
}

int main()
{
    // Set Port C pins as output
    DIO_init(); // Assuming DIO_init configures PINC0, PINC1 and PINC2 as outputs
	
    setup_interrupts();
	_delay_ms(10);
	sei();
    while(1) {};  // Endless loop
    return 0;
}
*/