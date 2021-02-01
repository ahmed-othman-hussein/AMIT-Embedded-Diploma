/*
 * KeypadH.c
 *
 *  Created on: Feb 26, 2018
 *      Author: Ahmed othman
 */




#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "Keypad.h"
#include "Dio.h"

static	uint16 uint16ResultLocl[10];
const uint8 uint8OperationArr[16]={'1','4','7','*','2','5','8','0','3','6','9','#','A','B','C','D'};
static void SetSWResult(uint8 numCfg,uint8 uint8ComlumnCpy);


/********************************************************************/
/*   this fun is used to initialize the keypad                      */
/********************************************************************/
void KEYPADH_Init(void){}

/********************************************************************/
/*   this fun updates the  status of the buttons on the keypad 	    */
/*               as values from 0~16                                */
/********************************************************************/
void KEYPADH_Task(void)
{


	uint8 i;
	for(i=0;i<KeyPadNum;i++)
	{
		/*clear prev status*/
		uint16ResultLocl[i]=0;
		if(keypadH_cfg[i].keypad_Mode==KeypadH_Mode_PullUp)
		{
			/*phase one */
			Dio_clrPin(keypadH_cfg[i].KeypadOutpuPins[0]);
			Dio_setPin(keypadH_cfg[i].KeypadOutpuPins[1]);
			Dio_setPin(keypadH_cfg[i].KeypadOutpuPins[2]);
			Dio_setPin(keypadH_cfg[i].KeypadOutpuPins[3]);
			SetSWResult(i,0);
			/*phase two */
			Dio_setPin(keypadH_cfg[i].KeypadOutpuPins[0]);
			Dio_clrPin(keypadH_cfg[i].KeypadOutpuPins[1]);
			Dio_setPin(keypadH_cfg[i].KeypadOutpuPins[2]);
			Dio_setPin(keypadH_cfg[i].KeypadOutpuPins[3]);
			SetSWResult(i,1);
			/*phase three */
			Dio_setPin(keypadH_cfg[i].KeypadOutpuPins[0]);
			Dio_setPin(keypadH_cfg[i].KeypadOutpuPins[1]);
			Dio_clrPin(keypadH_cfg[i].KeypadOutpuPins[2]);
			Dio_setPin(keypadH_cfg[i].KeypadOutpuPins[3]);
			SetSWResult(i,2);
			/*phase four */
			Dio_setPin(keypadH_cfg[i].KeypadOutpuPins[0]);
			Dio_setPin(keypadH_cfg[i].KeypadOutpuPins[1]);
			Dio_setPin(keypadH_cfg[i].KeypadOutpuPins[2]);
			Dio_clrPin(keypadH_cfg[i].KeypadOutpuPins[3]);
			SetSWResult(i,3);
		}
		else
		{

		}

	}











}

/********************************************************************/
/*   this fun is used to return  the pressed button value            */
/*                values are 0~F                                    */
/********************************************************************/
extern uint8 KEYPADH_GetValue(uint8 keypadNum)
{

	uint8 i;
	uint8 res=16;

	for(i=0;i<16;i++)
	{
		if(GET_BIT(uint16ResultLocl[keypadNum],i))
		{
			res=i;
			break;
		}
	}


	return uint8OperationArr[res];




}



static void SetSWResult(uint8 numCfg,uint8 uint8ComlumnCpy)
{



	if(keypadH_cfg[numCfg].keypad_Mode==KeypadH_Mode_PullUp)
	{
		if(Dio_LOW==Dio_getPin(keypadH_cfg[numCfg].KeypadInputPins[0]))
		{
			SET_BIT(uint16ResultLocl[numCfg],(uint8ComlumnCpy));
		}

		if(Dio_LOW==Dio_getPin(keypadH_cfg[numCfg].KeypadInputPins[1]))
		{
			SET_BIT(uint16ResultLocl[numCfg],(uint8ComlumnCpy+4));
		}
		if(Dio_LOW==Dio_getPin(keypadH_cfg[numCfg].KeypadInputPins[2]))
		{
			SET_BIT(uint16ResultLocl[numCfg],(uint8ComlumnCpy+8));
		}
		if(Dio_LOW==Dio_getPin(keypadH_cfg[numCfg].KeypadInputPins[3]))
		{
			SET_BIT(uint16ResultLocl[numCfg],(uint8ComlumnCpy+12));
		}
	}
	else
	{

	}

}

/********************************************************************/
/*   this fun is used to return  1 if there's button pressed         */
/********************************************************************/
extern uint8 KEYPADH_keypressed(uint8 KeypadNum)
{

	uint8 res;

	if(uint16ResultLocl[KeypadNum]==0)
	{
		res=0;
	}
	else
	{
		res =1;
	}

	return res;
}


