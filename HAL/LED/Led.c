/*
 * Led.c
 *
 *  Created on: Sep 7, 2019
 *      Author: Ahmed othman
 */
#include "STD_TYPES.h"
#include "Dio.h"
#include "Led.h"
void Led_On(uint8 LedID)
{
	if(Led_cfg[LedID].mode ==Led_Active_High)
	{
		Dio_setPin(Led_cfg[LedID].pin);
	}
	else
	{
		Dio_clrPin(Led_cfg[LedID].pin);

	}

}

void Led_Off(uint8 LedID)
{
	if(Led_cfg[LedID].mode ==Led_Active_High)
	{
		Dio_clrPin(Led_cfg[LedID].pin);
	}
	else
	{
		Dio_setPin(Led_cfg[LedID].pin);

	}


}

