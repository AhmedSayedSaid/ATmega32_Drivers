
/**
*******************************************
* @file    PWM_Generation.c
* @author  AHMED SAYED SAID
* @version 1.0
* @date    20-7-2023
* @brief   measuring the pwm signal using input capture unit of the atmega32a and the signal is generated from arduino pin 5 .
*          the result is being printed on lcd connected to the atmega32A using port a
* @note    This file is not included in the build process. Copy the content of it to the main to run the test.
* @note    https://github.com/AHMED_SAYED
*******************************************
**/

#include "DIO.h"
#include "Timers.h"

/**
 * @brief ISR for Timer/Counter1 Capture Event
 */
static void (*Timer1_ICU_Fptr) (void)=NULLPTR;

/**
 * @brief setting callback function that will run when the interrupt of icu happen
 */
void Timer1_ICU_SetCallBack(void(*LocalFptr)(void))
{
	Timer1_ICU_Fptr=LocalFptr;
}
/**
 * @brief global varibles to store the values of readings of icu
 */
  volatile u16 t1,t2,t3,flag=0;
  /**
 * @brief fucntion that will run when detecting specified edge using input capture unit.
 */
  void Func_ICU(void)
{
	if (flag==0) //when detect rising
	{
		t1=ICR1; //capture the time
		Timer1_InputCaptureEdge(FALLING); //set the timer falling
		flag=1;
	}
	else if (flag==1)
	{
		t2=ICR1;
		Timer1_InputCaptureEdge(RISING);
		flag=2;
	}
	else if (flag==2)
	{
		t3=ICR1;
		Timer1_ICU_InterruptDisable();
		flag=3;
	}

}

void PWM_Measure(u32* Pfreq,u8* Pduty)
{
	u16 Ton,Toff;
	TCNT1=0;// when i enter make the timer 0 so i don't have to consider the overflow in my
	//calculation down but this will make a problem if there another thing that is using the timer.
	Timer1_ICU_SetCallBack(Func_ICU);//set the call back function when the timer of the icu happen
	Timer1_InputCaptureEdge(RISING); //set the input capture unit to detect rising edge.
	Timer1_ICU_InterruptEnable();
	flag=0;
	while(flag<3);// busy wait until all the t1 and t2 and t3 get their required values. so the calculation of the two down equation is true
	Ton=t2-t1;
	Toff=t3-t2;

	*Pduty=((u32)Ton*100)/((u32)Ton+Toff);
	*Pfreq=(u32)1000000/((u32)Toff+Ton);

}




int main(void)
{
	DIO_init();
	_delay_ms(1);
	LCD_Init();
	u32 freq=0;
	u8 duty=0;
	_delay_ms(20);
	LCD_GoTo(0,0);
	u8 str[]="pwm measurement";
	LCD_WriteString(str);

	_delay_ms(1000);
	LCD_Clear();
	Timer1_Init(TIMER1_NORMAL_MODE,TIMER1_SCALER_8);
	sei();
	while (1)
	{
		PWM_Measure(&freq,&duty);
		LCD_GoTo(0,0);
		LCD_WriteNumber(freq);
		LCD_GoTo(1,0);
		LCD_WriteNumber((u32)duty);
	}

}

/**
 * @brief ISR for Timer/Counter1 Capture Event
 */
ISR(TIMER1_ICU_vect)
{
	if (Timer1_ICU_Fptr != NULLPTR)
	{
		Timer1_ICU_Fptr();
	}
}


/**
 * @brief Test environment and results.
 *
 * The output of this code is measured using the input capture unit of an ATMEGA32a AND THE SIGNAL IS generated using the arduino pin 5 with the code in the same folder.
 *
 * The measured result is after new calibration of arduino code :

the frequency :976hz
duty cycle :25%


 the expected result.
the frequency :976hz
duty cycle :25%



 */
