/*
 /lcdcloclk.c
 *
 *  Created on: Oct 14, 2019
 *      Author: othman
 */
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "Register.h"
#include "Dio.h"
#include "Os_Isr.h"
#include "Lcd.h"
#include "Uart.h"
#include <util/delay.h>
#include "App.h"
#include <stdlib.h>


static volatile uint32 check =0;
static volatile uint8 SEC =0;//allocating integer memory for storing seconds
static volatile uint8 MIN =0;// allocating integer memory for storing minutes
static volatile uint8 HOU =0;// allocating integer memory for storing hours
uint8 ALSEC = 0;//alarm seconds storing memory

uint8 ALMIN = 0;//alarm minutes storing memory

uint8 ALHOU = 0;//alarm hours storing memory

uint8 receiveData;

void cloock(void);
void uartrxx(void);

int main(void)
{



	uint8 SHOWSEC [2];//seconds displaying character on LCD

	uint8 SHOWMIN [2];//minutes displaying character on LCD

	uint8 SHOWHOU [2];// hours displaying character on LCD

	uint8 SHOWALSEC [2];//alarm  seconds displaying character on LCD

	uint8 SHOWALMIN [2];// alarm minutes displaying character on LCD

	uint8 SHOWALHOU [2];//alarm hours displaying character on LCD*/


	Dio_init();
	Uart_init();
	Lcd_init();

	//Lcd_writeString(0,"SET THE TIME:",0,0);  // Instructs the user to set the time on LCD

	TCCR1B |=(1<<CS12)|(1<<CS10)|(1<<WGM12);// setting prescale and CTC mode
	OCR1A=15625;
	Os_Isr_EnableInterrupt(TIMER1_COMPA);
	Os_Isr_EnableInterrupt(USART_RXC);
	Os_Isr_EnableableAllInterrupts();
	while(1)

	{

		itoa(HOU/10,SHOWHOU,10);

		Lcd_writeString(0,SHOWHOU,0,0);

		// displaying tens place of hours above

		itoa(HOU%10,SHOWHOU,10);

		Lcd_writeString(0,SHOWHOU,0,1);// send_a_string(SHOWHOU);

		// displaying ones place of hours above

		Lcd_writeString(0,":",0,2);//send_a_string (":");//displaying character



		itoa(MIN/10,SHOWMIN,10);

		Lcd_writeString(0,SHOWMIN,0,3);//send_a_string(SHOWMIN);
		// displaying tens place of minutes above

		itoa(MIN%10,SHOWMIN,10);

		Lcd_writeString(0,SHOWMIN,0,4);//send_a_string(SHOWMIN);

		// displaying ones place of minutes above


		Lcd_writeString(0,":",0,5);//send_a_string (":");

		itoa(SEC/10,SHOWSEC,10);

		Lcd_writeString(0,SHOWSEC,0,6);//send_a_string(SHOWMIN);
		// displaying tens place of minutes above

		itoa(SEC%10,SHOWSEC,10);

		Lcd_writeString(0,SHOWSEC,0,7);//send_a_string(SHOWMIN);

		// displaying ones place of minutes above



		if (Dio_getPin(Pb6)==1)//if alarm pin is high

		{

			Lcd_writeString(0,"ALRM:ON",0,9);//send_a_string(" ALM:ON ");//show alarm is on

			if ((ALHOU==HOU)&(ALMIN==MIN)&(ALSEC==SEC))//alarm minute=min //and alarm hours= time hours and alarm seconds= time seconds

			{

				Dio_setPin(Pa3); //buzzer on

			}

		}

		if (Dio_getPin(Pb6)==0)//if alarm pin is low

		{

			Lcd_writeString(0,"ALM:OFF",0,9);//send_a_string(" ALM:OFF");//show alarm is off

			Dio_clrPin(Pa3);//buzzer off

		}


		Lcd_writeString (0,"ALARM",1,0);//show string of characters


		itoa(ALHOU/10,SHOWALHOU,10);

		Lcd_writeString(0,SHOWALHOU,1,7);

		itoa(ALHOU%10,SHOWALHOU,10);

		Lcd_writeString(0,SHOWALHOU,1,8);


		Lcd_writeString (0,":",1,9);


		// Showing alarm hours above

		itoa(ALMIN/10,SHOWALMIN,10);

		Lcd_writeString(0,SHOWALMIN,1,10);

		itoa(ALMIN%10,SHOWALMIN,10);

		Lcd_writeString(0,SHOWALMIN,1,11);


		Lcd_writeString (0,":",1,12);


		// Showing alarm minutes above

		itoa(ALSEC/10,SHOWALSEC,10);

		Lcd_writeString(0,SHOWALSEC,1,13);

		itoa(ALSEC%10,SHOWALSEC,10);

		Lcd_writeString(0,SHOWALSEC,1,14);




	}
}

/*****************Transmitter***************/

/*if (Dio_getPin(Pd6)==input) // if switch is set to adjust TIME

{

	if ((Dio_getPin(Pb0)==input)) //button 1 is pressed

	{


		while (! (UCSRA & (1 << UDRE)) );

		{

			UDR = 1;//once transmitter is ready sent eight bit data

		}



		// Get that data outa here!



		_delay_ms(220);

	}





	if ((Dio_getPin(Pb4)==input))

		{


	while (! (UCSRA & (1 << UDRE)) );

	{

		UDR = 10;//once transmitter is ready sent eight bit data


	}


	// Get that data outa here!



	_delay_ms(220);



}

if ((Dio_getPin(Pd2)==input))

{



	while (! (UCSRA & (1 << UDRE)) );


	{
		UDR = 3;//once transmitter is ready sent eight bit data



	}

	// Get that data outa here!



	_delay_ms(220);


}




if ((Dio_getPin(Pb6)==input))

{


	while (! (UCSRA & (1 << UDRE)) );


	{
		UDR = 4;//once transmitter is ready sent eight bit data

	}



	// Get that data outa here!



	_delay_ms(220);

}
}












if (Dio_getPin(Pb7)==input)//if alarm adjust is set

{

	if (Dio_getPin(Pb0)==input)

	{

		while (! (UCSRA & (1 << UDRE)) );


		{
			UDR = 8;//once transmitter is ready sent eight bit data

		}



		// Get that data outa here!



		_delay_ms(220);


	}

	if (Dio_getPin(Pb4)==input)

	{
		while (! (UCSRA & (1 << UDRE)) );


		{
			UDR = 2;//once transmitter is ready sent eight bit data

		}



		// Get that data outa here!



		_delay_ms(220);


	}

	if (Dio_getPin(Pd2)==input)

	{
		while (! (UCSRA & (1 << UDRE)) );


		{
			UDR = 9;//once transmitter is ready sent eight bit data

		}



		// Get that data outa here!



		_delay_ms(220);



	}

	if (Dio_getPin(Pb6)==input)

	{
		while (! (UCSRA & (1 << UDRE)) );


		{
			UDR = 11;//once transmitter is ready sent eight bit data

		}



		// Get that data outa here!



		_delay_ms(220);

	}

}
}

}*/




void cloock(void) {  //loop to be executed on counter compare match


	check++;

	if(check==15625)
	{
		check=0;
		SEC++;


		if(SEC>59)
		{
			SEC=0;
			MIN++;


			if(MIN>59)
			{
				MIN=0;
				HOU++;


				if (HOU==24)
				{
					HOU=0;
				}
			}
		}
	}
}

/***********Receiver************/

void uartrxx(void){
	Os_Isr_disableAllInterrupts();
	while (! (UCSRA & (1 << RXC)) ){};


	receiveData = UDR;


	if ((receiveData == 1))

	{
		if(MIN==60){
			MIN=0;
			_delay_ms(220);

		}
		else{
			MIN++;
		}


		_delay_ms(220);
	}

	else if ((receiveData == 10)&&(MIN>0))

	{
		MIN--;

		_delay_ms(220);
	}

	else if ((receiveData == 3))

	{
		if(HOU==24){
			HOU=0;
			_delay_ms(220);

		}
		else{
			HOU++;
		}


		_delay_ms(220);
	}

	else if ((receiveData == 4)&&(HOU>0))

	{
		HOU--;


		_delay_ms(220);
	}

	else if (receiveData == 8)

	{
		if(ALMIN==60){
			ALMIN=0;
			_delay_ms(220);

		}
		else{
			ALMIN++;
		}

		_delay_ms(220);
	}

	else if ((receiveData == 2)&&(ALMIN>0))

	{
		ALMIN--;


		_delay_ms(220);
	}
	else if (receiveData == 9)

	{
		if(ALHOU==24){
			ALHOU=0;
			_delay_ms(220);

		}
		else{
			ALHOU++;
		}


		_delay_ms(220);
	}
	else if ((receiveData == 11)&&(ALHOU>0))

	{
		ALHOU--;


		_delay_ms(220);

	}
}

