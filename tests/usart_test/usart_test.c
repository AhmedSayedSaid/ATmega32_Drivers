// #include "usart_services.h"
// #include "LCD.h"
// 
// int main(void) {
// 	
// 	DIO_init();
// 	LCD_Init();
// 
// 	char TEST_STRING[] = "i am from atmega32";
// 	u32 TEST_NUMBER = 12345;
// 	
// 	// Initialize the USART module
// 	USART_Init(ASYNCHRONOUS, EIGHT_BITS, PARITY_DISABLED, ONE_BIT, RISING_XCKN_EDGE, 9600);
// 
// 	while (1) {
// 		// Test case: Send a string from the ATmega32 to the Arduino Uno
// 		// Expected result: The Arduino Uno receives the string "i am from arduino"
// 		// Actual result:
// 		USART_SendString(TEST_STRING);
// 		
// 		_delay_ms(10);
// 
// 		// Test case: Receive a string on the ATmega32 from the Arduino Uno
// 		// Expected result: The ATmega32 receives a string from the Arduino Uno
// 		// Actual result:
// 		char received_string[20];
// 		USART_ReceiveString(received_string, 20);
// 		
// 		LCD_Clear();
// 		LCD_WriteString(received_string);
// 
// 		// Test case: Send a number from the ATmega32 to the Arduino Uno
// 		// Expected result: The Arduino Uno receives the number 12345
// 		// Actual result:
// 		/*	USART_SendNumber(TEST_NUMBER);*/
// 
// 		// Test case: Receive a number on the ATmega32 from the Arduino Uno
// 		// Expected result: The ATmega32 receives a number from the Arduino Uno
// 		// Actual result:
// 		u32 received_number;
// 		USART_ReceiveNumber(&received_number);
// 
// 		// Test case: Send data with CRC from the ATmega32 to the Arduino Uno
// 		// Expected result: The Arduino Uno receives the data with CRC and verifies its integrity
// 		// Actual result:
// 		u8 data[] = {1, 2, 3, 4, 5};
// 		USART_SendDataWithCRC(data, sizeof(data));
// 
// 		// Test case: Receive data with CRC on the ATmega32 from the Arduino Uno
// 		// Expected result: The ATmega32 receives the data with CRC from the Arduino Uno and verifies its integrity
// 		// Actual result:
// 		u8 received_data[10];
// 		USART_ReceiveDataWithCRC(received_data, sizeof(received_data));
// 		
// 		TEST_NUMBER++;
// 		
// 		for (int i = 0; i < sizeof(TEST_STRING) - 1; i++) {
// 			TEST_STRING[i]++;
// 			if (TEST_STRING[i] > 'z') {
// 				TEST_STRING[i] = 'a';
// 			}
// 		}
// 		
// 		_delay_ms(1000);
// 	}
// 
// 	return 0;
// }
