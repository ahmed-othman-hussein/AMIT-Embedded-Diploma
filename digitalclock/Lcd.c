/*
 * Lcd.c
 *
 *  Created on: Sep 13, 2019
 *      Author: Ahmed othman
 */
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include <util/delay.h>
#include "Dio.h"
#include "Lcd.h"
#include "Lcd_cfg.h"



 void writeByte(uint8 LcdID ,Byte_type_t type , uint8 byte)
{
	uint8 counter;

	if (type == COMMAND)
	{
		Dio_clrPin(Lcd_cfg[LcdID].Rs);
	}
	else if (type == DATA)
	{
		Dio_setPin(Lcd_cfg[LcdID].Rs);

	}


	Dio_clrPin(Lcd_cfg[LcdID].RW);

	if(Lcd_cfg[LcdID].mode == LCD_4_BIT)
	{

		/******writing the high 4 bits*******/

		for(counter=4;counter <=7; counter ++)
		{
			if(GET_BIT(byte,counter)==1)
			{
				Dio_setPin(Lcd_cfg[LcdID].DB[counter]);
			}
			else if(GET_BIT(byte,counter)==0)

			{
				Dio_clrPin(Lcd_cfg[LcdID].DB[counter]);

			}

		}

		Dio_setPin(Lcd_cfg[LcdID].E);
		_delay_ms(1);
		Dio_clrPin(Lcd_cfg[LcdID].E);
		/*******writing the low 4 bit *********/
		for(counter=0;counter <=3; counter ++)
		{
			if(GET_BIT(byte,counter)==1)
			{
				Dio_setPin(Lcd_cfg[LcdID].DB[counter+4]);
			}
			else if(GET_BIT(byte,counter)==0)

			{
				Dio_clrPin(Lcd_cfg[LcdID].DB[counter+4]);

			}

		}

		Dio_setPin(Lcd_cfg[LcdID].E);
		_delay_ms(1);
		Dio_clrPin(Lcd_cfg[LcdID].E);
		_delay_ms(1);





	}
	else if(Lcd_cfg[LcdID].mode == LCD_8_BIT)
	{
		for(counter=0;counter <=7; counter ++)
		{
			if(GET_BIT(byte,counter)==1)
			{
				Dio_setPin(Lcd_cfg[LcdID].DB[counter]);
			}
			else if(GET_BIT(byte,counter)==0)

			{
				Dio_clrPin(Lcd_cfg[LcdID].DB[counter]);

			}

		}

		Dio_setPin(Lcd_cfg[LcdID].E);
		_delay_ms(1);
		Dio_clrPin(Lcd_cfg[LcdID].E);
		_delay_ms(1);





	}

}


void Lcd_init(void)
{
	uint8 counter;
	for(counter =0 ; counter < LcdCount ;counter++)
	{
		/* Function set */
		if(Lcd_cfg[counter].mode == LCD_4_BIT)
		{
			writeByte(counter,COMMAND, 0x23);
			writeByte(counter,COMMAND, 0x22);
			writeByte(counter,COMMAND, 0x28);

		}
		else if(Lcd_cfg[counter].mode == LCD_8_BIT)
		{
			writeByte(counter,COMMAND, 0x38);

		}
		_delay_us(40);
		/* Display on*/
		writeByte(counter,COMMAND,0x0E);
		_delay_us(40);

		/* clear*/
		writeByte(counter, COMMAND , 0x01);
		_delay_us(40);
		/* Cursor blinking*/
	//	writeByte(counter,COMMAND, 0b00001111);
		//_delay_us(40);




	}



}

void Lcd_writeChar(uint8 LcdID, uint8 data , uint8 row , uint8 col)
{
	writeByte(LcdID, COMMAND, 0x80+(row * 0x40) + col);

	writeByte(LcdID, DATA, data);


}


void Lcd_writeString(uint8 LcdID, uint8 * data , uint8 row , uint8 col)
{
	uint8 counter = 0;
	writeByte(LcdID, COMMAND, 0x80+(row * 0x40) + col);

	while (data[counter]!= '\0')
	{

		writeByte(LcdID, DATA, data[counter]);
		counter++;
	}


}




