/**
 * @file LCD.h
 * @author Ahmed Sayed
 * @date 9-7-2023
 * @brief Header file for interfacing with an LCD display in 4-bit or 8-bit mode.
 *
 * This file provides the interface for controlling an LCD display connected to an ATmega32 microcontroller.
 * It supports both 4-bit and 8-bit modes for communication with the LCD.
 */

#ifndef LCD_H_
#define LCD_H_

#include <util/delay.h>
#include "StdTypes.h"
#include "DIO.h"

/* LCD Mode Configuration */
#define LCD_MODE   _4_BIT  /* Set the mode to either _4_BIT or _8_BIT */

/* LCD Pin Configuration */
#define RS          PINA1  /* Register Select pin */
#define EN          PINA2  /* Enable pin */
/* Data pins for 4-bit mode */
#define D4          PINA3  
#define D5          PINA4
#define D6          PINA5
#define D7          PINA6

/**
 * @brief Initializes the LCD display.
 * 
 * Sets up the LCD for either 4-bit or 8-bit mode, depending on the configuration.
 * Initializes the display to its default state.
 */
void LCD_Init(void);

/**
 * @brief Clears the LCD display.
 * 
 * Clears the content on the LCD and sets the cursor to the home position.
 */
void LCD_Clear(void);

/**
 * @brief Writes a single character to the LCD.
 * 
 * @param ch Character to be displayed on the LCD.
 */
void LCD_WriteChar(u8 ch);

/**
 * @brief Writes a string to the LCD.
 * 
 * @param str Pointer to the string to be displayed.
 */
void LCD_WriteString(u8 *str);

/**
 * @brief Writes a signed integer number to the LCD.
 * 
 * @param num The signed integer number to display.
 */
void LCD_WriteNumber(s32 num);

/**
 * @brief Writes a binary number to the LCD.
 * 
 * @param num The binary number (as byte) to display.
 */
void LCD_WriteBinary(u8 num);

/**
 * @brief Writes a hexadecimal number to the LCD.
 * 
 * @param num The hexadecimal number (as byte) to display.
 */
void LCD_WriteHex(u8 num);

/**
 * @brief Moves the LCD cursor to a specified position.
 * 
 * @param line Line number (0 or 1 for 16x2 LCD).
 * @param cell Cell number (0 to 15 for 16x2 LCD).
 */
void LCD_GoTo(u8 line, u8 cell);

/**
 * @brief Clears a specific part of the LCD display.
 * 
 * @param line Line number (0 or 1 for 16x2 LCD).
 * @param cell Starting cell number for clearing.
 * @param numOfCells Number of cells to clear.
 */
void LCD_GoToClear(u8 line, u8 cell, u8 numOfCells);

/**
 * @brief Writes a string to a specified position on the LCD.
 * 
 * @param line Line number (0 or 1 for 16x2 LCD).
 * @param cell Cell number to start writing the string.
 * @param str Pointer to the string to be displayed.
 */
void LCD_GoToWriteString(u8 line, u8 cell, u8 *str);

/**
 * @brief Creates and displays a custom character.
 * 
 * @param pattern Array representing the bitmap of the custom character.
 * @param location Memory location to store the character (0 to 7).
 */
void LCD_Create_Character(u8 *pattern, u8 location);

#endif /* LCD_H_ */
