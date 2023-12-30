
#include "LCD.h"

#if LCD_MODE==_8_BIT

static void LCD_WriteCommand(u8 command)
{
	DIO_Write_Pin(RS,LOW);
	DIO_Write_Port(LCD_PORT,command);
	DIO_Write_Pin(EN,HIGH);
	_delay_ms(1);
	DIO_Write_Pin(EN,LOW);
	_delay_ms(1);
	
}
static void LCD_WriteData(u8 data)
{
	DIO_Write_Pin(RS,HIGH);
	DIO_Write_Port(LCD_PORT,data);
	DIO_Write_Pin(EN,HIGH);
	_delay_ms(1);
	DIO_Write_Pin(EN,LOW);
	_delay_ms(1);
}


void LCD_Init(void)
{
	_delay_ms(50);
	LCD_WriteCommand(0x38);//  2 line,5*7;
	LCD_WriteCommand(0x0c);//  cursor , 0x0f,  0x0e;
	LCD_WriteCommand(0x01);//  clear screen
	_delay_ms(1);
	LCD_WriteCommand(0x06);//  increase ddram address , no shift
}

#elif LCD_MODE==_4_BIT
static void LCD_WriteCommand(u8 command)
{
	DIO_Write_Pin(RS,LOW);
	DIO_Write_Pin(D7,READ_BIT(command,7));
	DIO_Write_Pin(D6,READ_BIT(command,6));
	DIO_Write_Pin(D5,READ_BIT(command,5));
	DIO_Write_Pin(D4,READ_BIT(command,4));
	DIO_Write_Pin(EN,HIGH);
	_delay_ms(1);
	DIO_Write_Pin(EN,LOW);
	_delay_ms(1);
	DIO_Write_Pin(D7,READ_BIT(command,3));
	DIO_Write_Pin(D6,READ_BIT(command,2));
	DIO_Write_Pin(D5,READ_BIT(command,1));
	DIO_Write_Pin(D4,READ_BIT(command,0));
	DIO_Write_Pin(EN,HIGH);
	_delay_ms(1);
	DIO_Write_Pin(EN,LOW);
	_delay_ms(1);
	
}
static void LCD_WriteData(u8 data)
{
	DIO_Write_Pin(RS,HIGH);
	
	DIO_Write_Pin(D7,READ_BIT(data,7));
	DIO_Write_Pin(D6,READ_BIT(data,6));
	DIO_Write_Pin(D5,READ_BIT(data,5));
	DIO_Write_Pin(D4,READ_BIT(data,4));
	DIO_Write_Pin(EN,HIGH);
	_delay_ms(1);
	DIO_Write_Pin(EN,LOW);
	_delay_ms(1);
	DIO_Write_Pin(D7,READ_BIT(data,3));
	DIO_Write_Pin(D6,READ_BIT(data,2));
	DIO_Write_Pin(D5,READ_BIT(data,1));
	DIO_Write_Pin(D4,READ_BIT(data,0));
	DIO_Write_Pin(EN,HIGH);
	_delay_ms(1);
	DIO_Write_Pin(EN,LOW);
	_delay_ms(1);
}


void LCD_Init(void)
{
	_delay_ms(50);
	LCD_WriteCommand(0x02);
	LCD_WriteCommand(0x28);//  2 line,5*7;
	LCD_WriteCommand(0x0c);//  cursor , 0x0f,  0x0e;
	LCD_WriteCommand(0x01);//  clear screen
	_delay_ms(1);
	LCD_WriteCommand(0x06);//  increase ddram address , no shift
}
#endif


/*************************************************************************************/

void LCD_WriteChar(u8 ch)
{
	LCD_WriteData(ch);
}

void LCD_WriteString(u8*str)
{
	u8 i;
	for (i=0;str[i];i++)
	{
		LCD_WriteChar((u8*)str[i]);
	}
}


void LCD_WriteNumber(s32 num)//-2503
{
	u8 str[20];
	u8 rem,i=0;
	if (num==0)
	{
		LCD_WriteChar('0');
		return;
	}
	if (num<0)
	{
		num=num*-1;
		LCD_WriteChar('-');
	}
	while(num>0)
	{
		rem=num%10;
		str[i]=rem+'0';
		num=num/10;
		i++;
	}
	for (s8 j=i-1;j>=0;j--)
	{
		LCD_WriteChar(str[j]);
	}
	
	
}



void LCD_WriteBinary(u8 num)//00000101
{
	s8 i,flag=0;
	for (i=7;i>=0;i--)
	{
		if ((num>>i)&1)
		{
			LCD_WriteChar('1');
			flag=1;
		}
		else
		{
			if (flag==1)
			{
				LCD_WriteChar('0');
			}
			
		}
	}

}

//u8 HexArray[]={'0','1','A'};

void LCD_WriteHex(u8 num)//0xfe
{
	u8 Hnibble=num>>4;//0f
	u8 Lnibble =num&0x0f;//0e
	if (Hnibble<=9)
	{
		LCD_WriteChar(Hnibble+'0');
	}
	else
	{
		LCD_WriteChar(Hnibble-10+'A');
	}
	if (Lnibble<=9)
	{
		LCD_WriteChar(Lnibble+'0');
	}
	else
	{
		LCD_WriteChar(Lnibble-10+'A');
	}
	
	//LCD_WriteChar(HexArray[Lnibble]);
	
	
	
}
void LCD_WriteNumber_4D(u16 num)//14542
{
	LCD_WriteChar(((num%10000)/1000)+'0');
	LCD_WriteChar(((num%1000)/100)+'0');
	LCD_WriteChar(((num%100)/10)+'0');
	LCD_WriteChar(((num%10)/1)+'0');
}

void LCD_GoTo(u8 line ,u8 cell)
{
	if (line==0)
	{
		LCD_WriteCommand(0x80+cell);
	}
	else if (line==1)
	{
		LCD_WriteCommand(0x80+0x40+cell);
	}
	
}

void LCD_Clear(void)
{
	LCD_WriteCommand(0x01);
}

void LCD_GoToClear(u8 line ,u8 cell,u8 numOfCells)
{
	u8 i;
	LCD_GoTo(line,cell);
	for (i=0;i<numOfCells;i++)
	{
		LCD_WriteChar(' ');
	}
	
}

void LCD_GoToWriteString(u8 line,u8 cell,u8*str)
{
	LCD_GoTo(line,cell);
	LCD_WriteString(str);
}
void LCD_Create_Character(u8 *Pattern,u8 Location) {

	u8 iLoop=0;

	LCD_WriteCommand(0x40+(Location*8)); //Send the Address of CGRAM
	for(iLoop=0;iLoop<8;iLoop++)
	LCD_WriteData(Pattern[iLoop]); //Pass the bytes of pattern on LCD
	LCD_WriteCommand(0x80);
}