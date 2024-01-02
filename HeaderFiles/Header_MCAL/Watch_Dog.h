/**
 * @file Watch_Dog.h
 * @author Ahmed El Sayed El Said
 * @version 1.0
 * @date 11-7-2023
 * @brief Header file for the Watchdog Timer (WDT) functionalities of ATmega32.
 *
 * This file provides an interface for configuring and using the Watchdog Timer (WDT) 
 * of the ATmega32 microcontroller. The WDT helps in bringing the microcontroller 
 * out of a hang state by providing a system reset feature.
 */

#ifndef WATCH_DOG_H_
#define WATCH_DOG_H_

/* Enumeration for Watchdog Timer Timeouts */
typedef enum {
    timeout_16ms = 0,   /* Timeout period of 16 milliseconds */
    timeout_32ms,       /* Timeout period of 32 milliseconds */
    timeout_65ms,       /* Timeout period of 65 milliseconds */
    timeout_130ms,      /* Timeout period of 130 milliseconds */
    timeout_260ms,      /* Timeout period of 260 milliseconds */
    timeout_520ms,      /* Timeout period of 520 milliseconds */
    timeout_1000ms,     /* Timeout period of 1000 milliseconds */
    timeout_2100ms      /* Timeout period of 2100 milliseconds */
} WDT_TimeOut;

/* Function prototypes for Watchdog Timer control may be added here if needed */

#endif /* WATCH_DOG_H_ */
