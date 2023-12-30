
#include "LCD.h"
#include "Common_Includes.h"
#include "USART.h"
int main(void) {
	
	DIO_init();
	LCD_Init();

	
	// Initialize the USART module
	u8 stat=USART_Init(ASYNCHRONOUS, NINE_BITS, PARITY_DISABLED, ONE_BIT, RISING_XCKN_EDGE, 9600);

	while (1) {
		


	u8	stat=USART_Transmit('a');

		DIO_Write_Pin(PINC0,HIGH);
		


		u8 rec;
		USART_Receive(&rec);
		LCD_WriteChar(rec);
			DIO_Write_Pin(PINC2,HIGH);
	}


	return 0;
}
