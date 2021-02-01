/*
 * App.c
 *
 *  Created on: Sep 21, 2019
 *      Author: Ahmed othman
 */
/*#include "STD_TYPES.h"
#include "Dio.h"
#include "Led.h"
#include "Lcd.h"
#include "App.h"
 uint8 i=0;
 uint8 Y=0;*/
 /*void cloock(void) {  //loop to be executed on counter compare match

	static volatile uint32 check =0;
	static volatile uint32 SEC =0;//allocating integer memory for storing seconds
	static volatile uint32 MIN =0;// allocating integer memory for storing minutes
	static volatile uint32 HOU =0;// allocating integer memory for storing hours

  check++;

  if(check==1000)
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
 	}*/


/*void LedAnimation(void)
{

	i++;
	if(i%2==1)
	{
		Led_On(0);
	}
	else
	{
		Led_Off(0);

	}





}
void calllBack(void)
{
	static uint32 counter=0;
	counter++;
	if(counter%1000 ==0)
	{

		i=(i+1)%10;
		Lcd_writeChar(0,i+'0',0,0);
	}


}*/
/*void callBack(void)
	{
	 volatile uint8 SEC =0;//allocating integer memory for storing seconds

		 volatile uint8 MIN =0;// allocating integer memory for storing minutes

		 volatile uint8 HOU =0;// allocating integer memory for storing hours

char SHOWSEC [2];//seconds displaying character on LCD

	char SHOWMIN [2];//minutes displaying character on LCD

	char SHOWHOU [2];// hours displaying character on LCD
	uint8 ALSEC = 0;//alarm seconds storing memory

	uint8 ALMIN = 0;//alarm minutes storing memory

	uint8 ALHOU = 0;//alarm hours storing memory

	char SHOWALSEC [2];//alarm  seconds displaying character on LCD

	char SHOWALMIN [2];// alarm minutes displaying character on LCD

	char SHOWALHOU [2];//alarm hours displaying character on LCD

/*
	 /*send_a_command(0x01); //Clear Screen 0x01 = 00000001

	_delay_ms(50);
	send_a_command(0x38);//telling lcd we are using 8bit command /data mode

	_delay_ms(50);

	send_a_command(0b00001111);//LCD SCREEN ON and courser blinking*/

/*	while(1)

	{

	itoa(HOU/10,SHOWHOU,10); //command for putting variable number in LCD(variable number, in which character to replace, which base is variable(ten here as we are counting number in base10))

	Lcd_writeString(0,SHOWHOU,0,0);//send_a_string(SHOWHOU);// telling the display to show character(replaced by variable number) of first person after positioning the courser on LCD

	// displaying tens place of hours above
	// displaying tens place of hours above

	itoa(HOU%10,SHOWHOU,10);

	Lcd_writeString(0,SHOWHOU,0,1);// send_a_string(SHOWHOU);

	// displaying ones place of hours above

	Lcd_writeString(0,":",0,2);//send_a_string (":");//displaying character

	writeByte(0,0 , 0x80 + 3);//send_a_command(0x80 + 3);// shifting cursor  to 4th shell


	itoa(MIN/10,SHOWMIN,10);///as integer cannot store decimal values, when MIN=9, we have MIN/10 = 0.9(actual), = 0 for CPU(as integer cannot store decimal values)

	Lcd_writeString(0,SHOWMIN,0,3);//send_a_string(SHOWMIN);
	// displaying tens place of minutes above

	itoa(MIN%10,SHOWMIN,10);

	Lcd_writeString(0,SHOWMIN,0,4);//send_a_string(SHOWMIN);

	// displaying ones place of minutes above

	writeByte(0,0 , 0x80 + 5);//send_a_command(0x80 + 5);// shifting cursor  to 6th shell

	Lcd_writeString(0,":",0,5);//send_a_string (":");

	writeByte(0,0 , 0x80 + 6);//send_a_command(0x80 + 6);// shifting cursor  to 7th shell
	itoa(SEC/10,SHOWSEC,10);///as integer cannot store decimal values, when MIN=9, we have MIN/10 = 0.9(actual), = 0 for CPU(as integer cannot store decimal values)

		Lcd_writeString(0,SHOWSEC,0,6);//send_a_string(SHOWMIN);
		// displaying tens place of minutes above

		itoa(SEC%10,SHOWSEC,10);

		Lcd_writeString(0,SHOWSEC,0,7);//send_a_string(SHOWMIN);

		// displaying ones place of minutes above

		writeByte(0,0 , 0x80 + 8);//send_a_command(0x80 + 5);// shifting cursor  to 6th shell

		Lcd_writeString(0,":",0,8);//send_a_string (":");

		writeByte(0,0 , 0x80 + 9);//send_a_command(0x80 + 6);// shifting cursor  to 7th shell

		void clock(void);


	}
	}/**/

