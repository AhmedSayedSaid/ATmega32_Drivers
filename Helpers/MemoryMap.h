/**
 *******************************************
 * @file    MemoryMap.h
 * @author  AHMED El_SAYED EL_SAID
 * @version 1.0
 * @date    9-7-2023
 * @brief   HEADER file for memory map of the ATMEGA32
 * @note    https://github.com/AHMED_SAYED
 *******************************************
 **/



#ifndef MEMORYMAP_H_
#define MEMORYMAP_H_
/************************************************************************/
/*                            EEPROM                                    */
/************************************************************************/


/**
/* @brief EEPROM address register which s the address to read from or write to the EEPROM .
/*Bits 9..0 – EEAR9..0: EEPROM Address
/*Bits 15..10 – Reserved Bits
*/
#define EEAR (*(volatile unsigned short*)0x3E)


/**
/* @brief EEPROM data register which is the place to write the data to when do you want to write data to the EEPROM
/* or the place to read the coming data after the reading request from the EEPROM
*/

#define EEDR (*(volatile unsigned char*)0x3D)

/**
/* @brief EEPROM control register which is used to control the read and write operation from the EEPROM
*/

#define EECR (*(volatile unsigned char*)0x3C)

#define EERE  0//EEPROM Read Enable
#define EEWE  1//EEPROM Write Enable
#define EEMWE 2//EEPROM Master Write Enable
#define EERIE 3//EEPROM Ready Interrupt Enable
/*
4->7 RESERVIED
*/
/************************************************************************/
/*                        WATCH_DOG                                      */
/************************************************************************/


/**
/* @brief Watch dog timer control register which is used to control the enable and disable the WDT .
*/

#define WDTCR (*(volatile unsigned char*)0x41)

/*Bits [2:0] – WDP2, WDP1, WDP0: Watchdog Timer Prescaler 2, 1, and */
#define WDP0  0
#define WDP1  1
#define WDP2  2

#define WDE   3//WTD enable.
#define WDTOE 4//WDT watch dog turn off enable.

/*
4->7 RESERVIED
*/


/************************************************************************/
/*                        INTERRUPTS                                    */
/************************************************************************/

/* Interrupt vectors */
/* External Interrupt Request 0 */
#define INT0_vect			__vector_1
/* External Interrupt Request 1 */
#define INT1_vect			__vector_2
/* External Interrupt Request 2 */
#define INT2_vect			__vector_3
/* Timer/Counter2 Compare Match */
#define TIMER2_COMP_vect		__vector_4
/* Timer/Counter2 Overflow */
#define TIMER2_OVF_vect			__vector_5
/* Timer/Counter1 Capture Event */
#define TIMER1_ICU_vect		__vector_6
/* Timer/Counter1 Compare Match A */
#define TIMER1_OCA_vect		__vector_7
/* Timer/Counter1 Compare Match B */
#define TIMER1_OCB_vect		__vector_8
/* Timer/Counter1 Overflow */
#define TIMER1_OVF_vect		__vector_9
/* Timer/Counter0 Compare Match */
#define TIMER0_OC_vect		__vector_10
/* Timer/Counter0 Overflow */
#define TIMER0_OVF_vect			__vector_11
/* Serial Transfer Complete */
#define SPI_STC_vect			__vector_12
/* USART, Rx Complete */
#define UART_RX_vect			__vector_13
/* USART Data Register Empty */
#define UART_UDRE_vect			__vector_14
/* USART, Tx Complete */
#define UART_TX_vect			__vector_15
/* ADC Conversion Complete */
#define ADC_vect			   __vector_16
/* EEPROM Ready */
#define EE_RDY_vect			   __vector_17
/* Analog Comparator */
#define ANA_COMP_vect			__vector_18
/* 2-wire Serial Interface */
#define TWI_vect			    __vector_19
/* Store Program Memory Ready */
#define SPM_RDY_vect			__vector_20
/*
* @brief Represents undefined or unhandled interrupts. BAD_vect is a fallback for any interrupt
* vector that doesn't have a specific handler defined. By default, it is defined to
* __vector_default which is the default interrupt vector.
*/
#define BAD_vect __vector_default

/*interrupt functions*/

/*
* @brief Enables global interrupts.
* This function uses the "sei" assembly instruction to set the global interrupt flag,
* allowing the microcontroller to respond to interrupt requests.
*/
#define sei()  __asm__ __volatile__ ("sei" ::)

/*
* @brief Disables global interrupts.
* This function uses the "cli" assembly instruction to clear the global interrupt flag,
* preventing the microcontroller from responding to interrupt requests.
*/
#define cli()  __asm__ __volatile__ ("cli" ::)

/*
* @brief Returns from an interrupt routine.
* This function uses the "reti" assembly instruction to end an interrupt service routine (ISR)
* and restore the program state prior to the interrupt.
*/
#define reti()  __asm__ __volatile__ ("reti" ::)

/*
* @brief Returns from a subroutine.
* This function uses the "ret" assembly instruction to return from a subroutine back to the
* point of call in the main program.
*/
#define ret()  __asm__ __volatile__ ("ret" ::)

/*
* @brief Specifies that an interrupt service routine (ISR) should allow other interrupts to occur
* during its execution.
* This is known as "nested interrupt", a higher priority interrupt can interrupt a lower priority ISR.
*/
#define ISR_NOBLOCK    __attribute__((interrupt))

/*
* @brief Specifies that an ISR should be compiled as "naked", i.e., without any prologue or
* epilogue code. This means that no registers will be saved or restored, and the ISR will not
* return automatically to the interrupted code.
*/
#define ISR_NAKED      __attribute__((naked))


/*
* @brief Macro for defining an interrupt service routine (ISR).
* @param vector The name of the interrupt vector to assign the ISR to.
* @param ... Any additional attributes to assign to the ISR function.
* This macro expands to the function definition of an ISR, with the vector name as the function name.
* Signal attribute indicate that this is interrupt and also used to push and restore system state before and after the ISR
*/

/*
FOR EXAMPLE:
ISR(TIMER0_OVF_vect, __attribute__((naked)))
{
	// ISR code here
}

This would expand to:

void TIMER0_OVF_vect(void) __attribute__((signal, naked));
void TIMER0_OVF_vect(void)
{
	// ISR code here
}
*/
#define ISR(vector,...)            \
void vector (void) __attribute__ ((signal))__VA_ARGS__ ; \
void vector (void)

/************************************************************************/
/*									DIO                                 */
/************************************************************************/

/*
@brief data direction register 
*specify if the pin is output or input 
*/
#define DDRA (*(volatile unsigned char*)0x3A)
#define DDRB (*(volatile unsigned char*)0x37)
#define DDRC (*(volatile unsigned char*)0x34)
#define DDRD (*(volatile unsigned char*)0x31)

/*
@brief inputs pin address registers
*can measure the actual volt on the pin from them
*/
#define PNA (*(volatile unsigned char*)0x39)
#define PNB (*(volatile unsigned char*)0x36)
#define PNC (*(volatile unsigned char*)0x33)
#define PND (*(volatile unsigned char*)0x30)

/*
@brief port register 
*specify the logic on the pin high or low.
*/
#define PORTA (*(volatile unsigned char*)0x3B)
#define PORTB (*(volatile unsigned char*)0x38)
#define PORTC (*(volatile unsigned char*)0x35)
#define PORTD (*(volatile unsigned char*)0x32)


/************************************************************************/
/*							EXTERNAL INTERRUPUT                         */
/************************************************************************/

/*General interrupt control register
*@brief The General Interrupt Control Register controls the placement of the Interrupt Vector table and the enabling or disabling the external interrupt bins 
*/
#define GICR (*(volatile unsigned char*)0x5B)
#define IVSEL   1    //When the IVSEL bit is cleared (zero), the Interrupt Vectors are placed at the start of the Flash memory. When this bit is set (one), the interrupt vectors are moved to the beginning of the Boot Loader section of the Flash.
#define INT2   5    //enable or disable the interrupt of this bin
#define INT0   6    //enable or disable the interrupt of this bin
#define INT1   7    //enable or disable the interrupt of this bin

/*MCU Control Register
*@brief The MCU Control Register contains control bits for interrupt sense control and general MCU functions.
*/
#define MCUCR (*(volatile unsigned char*)0x55)
#define ISC00   0    //lower bit to control the INT0 trigger logic
#define ISC01   1    //lower bit to control the INT0 trigger logic
#define ISC10   2    //lower bit to control the INT1 trigger logic
#define ISC11   3   //higher bit to control the INT1 trigger logic

/*MCU Control Register
*@brief The MCU Control Register contains control bits for interrupt sense control and general MCU functions.
*/
#define MCUCSR (*(volatile unsigned char*)0x54)
#define ISC2   6    //write this bit to zero to make the interrupt on INT2 trigger on falling edge and write it to one 


/*General interrupt flag register
*@brief The General interrupt flag register have only the bits that are set when logic change  on the pin of the external interrupt and the corresponding bit are cleard when 
*the ISR executed and this should toggle when logic change on the pin happened even if the global or the corresponding bit of the interrupt on this bin is not enabled.
*and the bits can be cleared manually by writing one to it .
*/
#define GIFR (*(volatile unsigned char*)0x5A)
#define INTF2   5    //enable or disable the interrupt of this bin
#define INTF0   6    //enable or disable the interrupt of this bin
#define INTF1   7    //enable or disable the interrupt of this bin


/************************************************************************/
/*							TIMERS										*/
/************************************************************************/

//TIMER 0
/*Timer/Counter Control
Register – TCCR0
*@brief contain the configuration bits of the clock source or the prescaler and the (0:2) and the mode of the timer (3,6) and the behavior of the OC pin when compare 
*match happen in any timer mode (4,5) and a bit to force the compare match behavior on the bin (7) .
*/
#define TCCR0 (*(volatile unsigned char*)0x53) 
#define CS00   0    //clock select first bit those bits used to select Whether to disable the timer or choose from all the available prescaler values or external clock on tn pin .
#define CS01   1    //clock select second bit
#define CS02   2    //clock select third bit

#define WGM01   3    //wave form generator first bit and this is used to control the mode of the timer .
#define COM00   4    //compare match output mode first bit These bits control the Output Compare pin (OC0) behavior
#define COM01   5    //compare match output mode second 
#define  WGM00   6    //wave form generator second bit 
#define FOC0   7    //Force output compare bit
 
 /*Timer/Counter Register – TCNT0
 *@brief the register the contain the current value of the timer while counting and can be read or written while the timer working or not working .
 */
 #define TCNT0 (*(volatile unsigned char*)0x52) 
 
  /*Output Compare Register – OCR0
 *@brief The Output Compare Register contains an 8-bit value that is continuously compared with the
 counter value (TCNT0). A match can be used to generate an output compare interrupt, or to
 generate a waveform output on the OC0 pin
 */
 #define  OCR0 (*(volatile unsigned char*)0x5C) 
 
  /*Timer/Counter Interrupt Mask Register – TIMSK
 *@brief contain the bits the enable the interrupts of the overflow and the compare match or timer 0
 */
//  #define TIMSK (*(volatile unsigned char*)0x59) 
 #define TOIE0   0    //Timer/Counter0 Overflow Interrupt Enable
 #define OCIE0   1    //Timer/Counter0 Output Compare Match Interrupt Enable
//  
 
   /*Timer/Counter Interrupt Flag Register TIFR
 *@brief contain flags that one of them is set when over flow or compare match happen those bits can be cleared by writing one to them or 
 *they will be cleared using hardware when entering the ISR .
 */
 //#define TIFR (*(volatile unsigned char*)0x58) 
 #define TOV0   0  // Timer/Counter0 Overflow Flag can 
 #define OCF0   1     //  Output Compare Flag 0
 
 
 /**************************************************************TIMER 1*******************************************************/
  
   //Special Function IORegister – SFIOR

 #define SFIOR (*(volatile unsigned char*)0x50) 
 #define PSR10   0  //  Prescaler Reset Timer/Counter1 and Timer/Counter0

/*Timer/Counter1 Control Register A –TCCR1A
 *@brief This register contains control bits for 
 the operation of Timer/Counter1. The COM bits control the
  output compare behavior, the FOC bits force an output compare,
  and the WGM bits control the waveform generation mode.
 */
#define TCCR1A (*(volatile unsigned char*)0x4F) 
#define WGM10 0 //Waveform Generation Mode
#define WGM11 1 //Waveform Generation Mode
#define FOC1B 2 //Force Output Compare for Channel B
#define FOC1A 3 //Force Output Compare for Channel A
#define COM1B0 4 //Compare Output Mode for Channel B
#define COM1B1 5 //Compare Output Mode for Channel B
#define COM1A0 6 //Compare Output Mode for Channel A
#define COM1A1 7 //Compare Output Mode for Channel A

/*Timer/Counter1 Control Register B –TCCR1B
 *@brief This register contains control bits for the operation of Timer/Counter1. The ICNC1 bit activates the Input Capture Noise Canceler, the ICES1 bit selects the Input Capture Edge, the WGM bits control the waveform generation mode, and the CS bits select the clock source.
 */
#define TCCR1B (*(volatile unsigned char*)0x4E) 
#define CS10 0 //Clock Select: Selects clock source for Timer/Counter1
#define CS11 1 //Clock Select: Selects clock source for Timer/Counter1
#define CS12 2 //Clock Select: Selects clock source for Timer/Counter1
#define WGM12 3 //Waveform Generation Mode: Controls the waveform generation mode of Timer/Counter1
#define WGM13 4 //Waveform Generation Mode: Controls the waveform generation mode of Timer/Counter1
#define ICES1 6 //Input Capture Edge Select: Selects which edge on the Input Capture pin (ICP1) is used to trigger a capture event
#define ICNC1 7 //Input Capture Noise Canceler: Activates the Input Capture Noise Canceler

 

/* Timer/Counter1 – TCNT1H and TCNT1L (16-bit register)
 * @brief This register holds the current count value of Timer/Counter1.
 */
#define TCNT1 (*(volatile unsigned short*)0x4C)

/* Output Compare Register 1 A – OCR1AH and OCR1ALv
 * @brief This register holds the value to be compared with the count value in TCNT1 for output compare match A.
 */
#define OCR1A (*(volatile unsigned short*)0x4A)


/* Output Compare Register 1 B – OCR1BH and OCR1BL  (16-bit register)
 * @brief This register holds the value to be compared with the count value in TCNT1 for output compare match B.
 */
#define OCR1B (*(volatile unsigned short*)0x48)


/* Input Capture Register 1 – ICR1H and ICR1L  (16-bit register)
 * @brief This register holds the value captured from the Input Capture pin (ICP1) when an input capture event occurs.
 */
#define ICR1 (*(volatile unsigned short*)0x46)


/* Timer/Counter Interrupt Mask Register – TIMSK
 * @brief This register contains bits that enable or disable various interrupt sources for Timer/Counter0, Timer/Counter1, and Timer/Counter2.
 */
// #define TIMSK (*(volatile unsigned char*)0x59)
#define TOIE1 2 //Timer/Counter Overflow Interrupt Enable: Enables overflow interrupt for Timer/Counter1
#define OCIE1B 3 //Timer/Counter Output Compare Match Interrupt Enable: Enables output compare match interrupt for Timer/Counter1, channel B
#define OCIE1A 4 //Timer/Counter Output Compare Match Interrupt Enable: Enables output compare match interrupt for Timer/Counter1, channel A
#define TICIE1 5 //Timer/Counter Input Capture Interrupt Enable: Enables input capture interrupt for Timer/Counter1


/* Timer/Counter Interrupt Flag Register – TIFR
 * @brief This register contains flags that are set when various interrupt events occur in Timer/Counter0, Timer/Counter1, and Timer/Counter2.
 */
// #define TIFR (*(volatile unsigned char*)0x58)
#define TOV1 2 //Timer/Counter Overflow Flag: Set when an overflow occurs in Timer/Counter1
#define OCF1B 3 //Timer/Counter Output Compare Flag: Set when a compare match occurs in Timer/Counter1, channel B
#define OCF1A 4 //Timer/Counter Output Compare Flag: Set when a compare match occurs in Timer/Counter1, channel A
#define ICF1 5 //Timer/Counter Input Capture Flag: Set when an input capture event occurs in Timer/Counter1

/********************************************************************TIMER2*****************************************************/

// Timer/Counter2 Control Register –TCCR2
/* Timer/Counter2 Control Register – TCCR2
 * @brief This register contains control bits for the operation of Timer/Counter2. The WGM bits control the waveform generation mode, the COM bits control the output compare behavior, and the CS bits select the clock source.
 */
#define TCCR2 (*(volatile unsigned char*)0x45)
#define CS20 0 //Clock Select: Selects clock source for Timer/Counter2
#define CS21 1 //Clock Select: Selects clock source for Timer/Counter2
#define CS22 2 //Clock Select: Selects clock source for Timer/Counter2
#define WGM21 3 //Waveform Generation Mode: Controls the waveform generation mode of Timer/Counter2
#define COM20 4 //Compare Output Mode: Controls the output compare behavior of Timer/Counter2
#define COM21 5 //Compare Output Mode: Controls the output compare behavior of Timer/Counter2
#define WGM20 6 //Waveform Generation Mode: Controls the waveform generation mode of Timer/Counter2
#define FOC2 7 //Force Output Compare: Forces an output compare match in Timer/Counter2

// Counter Register –TCNT2
/* Counter Register – TCNT2
 * @brief This register holds the current count value of Timer/Counter2.
 */
#define TCNT2 (*(volatile unsigned char*)0x44)

// Output Compare Register –OCR2
/* Output Compare Register – OCR2
 * @brief This register holds the value to be compared with the count value in TCNT2 for output compare match.
 */
#define OCR2 (*(volatile unsigned char*)0x43)

// Asynchronous Status Register –ASSR
/* Asynchronous Status Register – ASSR
 * @brief This register contains status bits for asynchronous operation of Timer/Counter2.
 */
#define ASSR (*(volatile unsigned char*)0x42)
#define TCR2UB 0 //Timer/Counter Control Register Update Busy: Indicates that TCCR2 is being updated asynchronously
#define OCR2UB 1 //Output Compare Register Update Busy: Indicates that OCR2 is being updated asynchronously
#define TCN2UB 2 //Timer/Counter Update Busy: Indicates that TCNT2 is being updated asynchronously
#define AS2 3 //Asynchronous Timer/Counter: Enables asynchronous operation of Timer/Counter2

// Timer/Counter Interrupt Mask Register –TIMSK
/* Timer/Counter Interrupt Mask Register – TIMSK
 * @brief This register contains bits that enable or disable various interrupt sources for Timer/Counter0, Timer/Counter1, and Timer/Counter2.
 */
#define TIMSK (*(volatile unsigned char*)0x59)

#define TOIE2 6 //Timer/Counter Overflow Interrupt Enable: Enables overflow interrupt for Timer/Counter2
#define OCIE2 7 //Timer/Counter Output Compare Match Interrupt Enable: Enables output compare match interrupt for Timer/Counter2

// Timer/Counter Interrupt Flag Register –TIFR
/* Timer/Counter Interrupt Flag Register – TIFR
 * @brief This register contains flags that are set when various interrupt events occur in Timer/Counter0, Timer/Counter1, and Timer/Counter2.
 */
#define TIFR (*(volatile unsigned char*)0x58)
#define TOV2 6 //Timer/Counter Overflow Flag: Set when an overflow occurs in Timer/Counter2
#define OCF2 7 //Timer/Counter Output Compare Flag: Set when a compare match occurs in Timer/Counter2


/************************************************************************/
/*							SPI  										*/
/************************************************************************/

/* SPI Control Register –
 * @brief This register contains status bits for contoling the state of spi .
 */
#define SPCR (*(volatile unsigned char*)0x2D)
#define  SPR0 0// the 0,1 bits used to specifiy the speed of the clock of spi
#define SPR1 1 
#define CPHA 2 // choose where to collect the coming data on the rising edge of the falling edge of the pulse on the clock 
#define CPOL 3 // choose weither the high state of the clock pin is the the idle of the low state
#define MSTR 4 // choose to operate as master or slave
#define DORD 5 //data order lsb or msb
#define SPE   6 //spi enable 
#define  SPIE 7 // spi interrupt enable bit 

/* SPI STATUS REGISTER 
 * @brief also contains bits to configure the spi
 */
#define SPSR (*(volatile unsigned char*)0x2E)
#define SPI2X 0 //enable of disable the double speed spi
#define WCOL 6 //if this is sit means that the data register was tried to be written when transdering data
#define  SPIF 7 //when set means that the serial trnasfer is compelete

/* spi data register 
 * @brief This register contains the data to be sent or the data recived . 
 */
#define SPDR (*(volatile unsigned char*)0x2F)
/************************************************************************/
/*							USART										*/
/************************************************************************/

/* USART Control and Status Register A – UCSRA
 * @brief This register contains status bits for controlling the state of USART.
 */
#define UCSRA (*(volatile unsigned char*)0x2B)
#define MPCM 0 // Multi-processor Communication Mode
#define U2X 1 // Double the USART Transmission Speed
#define UPE 2 // USART Parity Error
#define DOR 3 // Data OverRun
#define FE 4 // Frame Error
#define UDRE 5 // USART Data Register Empty
#define TXC 6 // USART Transmit Complete
#define RXC 7 // USART Receive Complete

/* USART Control and Status Register B – UCSRB
 * @brief This register contains control bits for the operation of USART.
 */
#define UCSRB (*(volatile unsigned char*)0x2A)
#define TXB8 0 // Transmit Data Bit 8
#define RXB8 1 // Receive Data Bit 8
#define UCSZ2 2 // Character Size
#define TXEN 3 // Transmitter Enable
#define RXEN 4 // Receiver Enable
#define UDRIE 5 // USART Data Register Empty Interrupt Enable
#define TXCIE 6 // TX Complete Interrupt Enable
#define RXCIE 7 // RX Complete Interrupt Enable

/* USART Control and Status Register C – UCSRC
 * @brief This register contains control bits for the operation of USART.
 */
#define UCSRC (*(volatile unsigned char*)0x40)
#define UCPOL 0 // Clock Polarity
#define UCSZ0 1 // Character Size
#define UCSZ1 2 // Character Size
#define USBS 3 // Stop Bit Select
#define UPM0 4 // Parity Mode Bit 0
#define UPM1 5 // Parity Mode Bit 1
#define UMSEL 6 // USART Mode Select
#define URSEL 7 // Register Select

/* USART Baud Rate Register – UBRRL and UBRRH
 * @brief These registers hold the USART baud rate.
 */
#define UBRRL (*(volatile unsigned char*)0x29) // USART Baud Rate Register Low Byte
#define UBRRH (*(volatile unsigned char*)0x40) // USART Baud Rate Register High Byte

/* USART Data Register – UDR
 * @brief This register contains the data to be transmitted or received.
 */
#define UDR (*(volatile unsigned char*)0x2C)


#endif /* MEMORYMAP_H_ */


