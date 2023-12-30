/*
 * DIO_CONFIG.c
 *
 * Created: 7/13/2023 12:48:58 PM
 *  Author: GENIUS 1
 */ 



#include "DIO.h"

const  DIO_PNStatus Pins_Status_Array[TOTAL_PIN]=
{
	INFREE,      /* Port A PN 0 ADC0*/
	OUTPUT,      /* Port A PN 1 ADC1*/
	OUTPUT,      /* Port A PN 2 */
	OUTPUT,      /* Port A PN 3 */
	OUTPUT,      /* Port A PN 4 */
	OUTPUT,      /* Port A PN 5 */
	OUTPUT,      /* Port A PN 6 */
	INFREE,      /* Port A PN 7 ADC7*/
	
	OUTPUT,      /* Port B PN 0   / */
	OUTPUT,      /* Port B PN 1   /*/
	INPULL,      /* Port B PN 2 / INT2*/
	OUTPUT,		 /* Port B PN 3   /OC0*/
	OUTPUT,		 /* Port B PN 4 /ss*/
	OUTPUT,		 /* Port B PN 5 //mosi*/
	INFREE,		 /* Port B PN 6 /miso*/
	OUTPUT,		 /* Port B PN 7 clk*/
	
	OUTPUT,		 /* Port C PN 0 */
	OUTPUT,		 /* Port C PN 1 */
	OUTPUT,		 /* Port C PN 2 */
	OUTPUT,		 /* Port C PN 3 */
	OUTPUT,		 /* Port C PN 4 */
	OUTPUT,		 /* Port C PN 5 */
	OUTPUT,		 /* Port C PN 6 */
	OUTPUT,		 /* Port C PN 7 */
	
	INFREE,		 /* Port D PN 0  RX*/
	OUTPUT,		 /* Port D PN 1 TX */
    INPULL,     /* Port D PN 2 /INT0*/
	INPULL,      /* Port D PN 3 / INT1 */
	OUTPUT,		 /* Port D PN 4  OC1B*/
	OUTPUT,		 /* Port D PN 5 OC1A*/
	INFREE,		 /* Port D PN 6 /   ICP*/
	OUTPUT		 /* Port D PN 7 OC2 */
	};