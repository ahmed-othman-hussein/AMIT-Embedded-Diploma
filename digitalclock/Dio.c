#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "Register.h"
#include "Dio.h"

typedef enum 
{
	PortA=0,
	PortB,
	PortC,
	PortD

}Port_t;



void Dio_init(void)
{
	uint8 counter;
	uint8 currentPin ;
	uint8 currentPort;
	for(counter =Pa0; counter <PinCount ; counter++)
	{
		currentPin = counter % 8;
		currentPort = counter /8;
		if(Dio_pin_cfg[counter].pinDirection ==output)
		{
			switch (currentPort)
			{
			case PortA:
				SET_BIT(DDRA,currentPin);
				break;
			case PortB:
				SET_BIT(DDRB,currentPin);
				break;
			case PortC:
				SET_BIT(DDRC,currentPin);
				break;
			case PortD:
				SET_BIT(DDRD,currentPin);
				break;
			}
		}
		else if(Dio_pin_cfg[counter].pinDirection ==input)
		{
			switch (currentPort)
			{
			case PortA:
				CLR_BIT(DDRA,currentPin);
				break;
			case PortB:
				CLR_BIT(DDRB,currentPin);
				break;
			case PortC:
				CLR_BIT(DDRC,currentPin);
				break;
			case PortD:
				CLR_BIT(DDRD,currentPin);
				break;
			}

		}
		else if(Dio_pin_cfg[counter].pinDirection ==inputwithpullup)
		{
			switch (currentPort)
			{
			case PortA:
				CLR_BIT(DDRA,currentPin);
				SET_BIT(PORTA,currentPin);
				break;
			case PortB:
				CLR_BIT(DDRB,currentPin);
				SET_BIT(PORTB,currentPin);

				break;
			case PortC:
				CLR_BIT(DDRC,currentPin);
				SET_BIT(PORTC,currentPin);

				break;
			case PortD:
				CLR_BIT(DDRD,currentPin);
				SET_BIT(PORTD,currentPin);

				break;
			}

		}


	}

}

/*  */
void Dio_setPin(Dio_Pin_t pinNum)
{

	uint8 currentPin ;
	uint8 currentPort;

	currentPin = pinNum % 8;
	currentPort = pinNum /8;
	switch (currentPort)
	{
	case PortA:
		SET_BIT(PORTA,currentPin);
		break;
	case PortB:
		SET_BIT(PORTB,currentPin);
		break;
	case PortC:
		SET_BIT(PORTC,currentPin);
		break;
	case PortD:
		SET_BIT(PORTD,currentPin);
		break;
	}

}


void Dio_clrPin(Dio_Pin_t pinNum)
{
	uint8 currentPin ;
	uint8 currentPort;

	currentPin = pinNum % 8;
	currentPort = pinNum /8;
	switch (currentPort)
	{
	case PortA:
		CLR_BIT(PORTA,currentPin);
		break;
	case PortB:
		CLR_BIT(PORTB,currentPin);
		break;
	case PortC:
		CLR_BIT(PORTC,currentPin);
		break;
	case PortD:
		CLR_BIT(PORTD,currentPin);
		break;
	}



}

Dio_pinState_t Dio_getPin(Dio_Pin_t pinNum)
{
	uint8 currentPin;
	uint8 currentPort;
	uint8 value;
	Dio_pinState_t retValue;
	currentPin = pinNum % 8;
	currentPort = pinNum /8;
	switch(currentPort)
	{
	case PortA:
		value =GET_BIT(PINA,currentPin);
		break;
	case PortB:
		value =GET_BIT(PINB,currentPin);
		break;
	case PortC:
		value =GET_BIT(PINC,currentPin);
		break;
	case PortD:
		value =GET_BIT(PIND,currentPin);
		break;

	}
	if(0 == value)
	{
		retValue= Dio_LOW;
	}


	else if (1 == value)
	{
		retValue= Dio_HIGH;

	}
	else
	{
		/* do nothing*/
	}

	return retValue;
}
