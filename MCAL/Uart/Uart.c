/*
 * Uart.c
 *
 *  Created on: Oct 11, 2019
 *      Author: Ahmed othman
 */




#define UART_PARITY_clr_msk                 0b11001111
#define UART_PARITY_MODE_DISABLE            0b00000000
#define UART_PARITY_MODE_EVEN               0b00100000
#define UART_PARITY_MODE_ODD                0b00110000

#define UART_STOP_BIT_clr_msk				0b11110111
#define UART_STOP_BIT_1   					0b00000000
#define UART_STOP_BIT_2   					0b00001000

#define UART_UCSRC_ACCESS_msk				0b10000000

#define  UART_8BitSelector                  0b00000110

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "Register.h"
#include "Uart.h"

void Uart_init(void)
{
	uint8 UBRR_Value = 103; // 2400 baud rate

		UBRRH = (uint8) (UBRR_Value >> 8);

		UBRRL = (uint8) UBRR_Value;

		UCSRB = ((1<<TXEN)|(1<<RXEN) | (1<<RXCIE));
		UCSRC = (1 << URSEL) | (1 << UCSZ0)|(1 << UCSZ1);

	/****************/
	/*UCSRC = UART_UCSRC_ACCESS_msk |
			PARITY_Selector |
			STOP_BIT_Selector|
			UART_8BitSelector;

	UBRRL  = BaudRate;

	SET_BIT(UCSRB,TXEN);
	SET_BIT(UCSRB,RXEN);*/


}

uint8 BusyFlag =0;
uint8 SentBuff[100];
uint8 SentSize =0;

uint8 SentBuffCurrentLocation;
uint8 RecieveBuffCurrentLocation;

uint8 RecieveSize =0;
uint8 * RecieveBuff;
uint8 recieveBusyFlag =0;

void Uart_send(uint8 * sentBuffer, uint8 size )
{
	uint8 i;
	if(BusyFlag ==0)
	{
		for(i=0;i<size;i++)
		{
			SentBuff[i]=sentBuffer[i];
		}
		SentSize = size;
		SentBuffCurrentLocation=0;
		UDR = SentBuff[SentBuffCurrentLocation];
		BusyFlag = 1;
	}
	else
	{
	}
}
extern void UartTXISR(void)
{


	SentBuffCurrentLocation++;
	if(SentBuffCurrentLocation<SentSize)
	{
		UDR = SentBuff[SentBuffCurrentLocation];
	}
	else if(SentBuffCurrentLocation >= SentSize)
	{
		BusyFlag = 0;
	}


}


void Uart_recieve(uint8 * RecieveBuffer, uint8 size )
{

  RecieveBuff = RecieveBuffer;
  RecieveSize = size;
  recieveBusyFlag = 1;
  RecieveBuffCurrentLocation=0;


}
extern void UartRXISR(void)
{
	if(recieveBusyFlag == 1)
	{
		RecieveBuff[RecieveBuffCurrentLocation] = UDR;
		RecieveBuffCurrentLocation++;
		if(RecieveBuffCurrentLocation>= RecieveSize )
		{
			recieveBusyFlag=0;
		}
	}




}
