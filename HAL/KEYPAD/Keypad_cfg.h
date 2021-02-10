/*
 * KeypadH_cfg.h
 *
 *  Created on: Oct 5, 2018
 *      Author: Ahmed othman
 */

#ifndef ECUAL_KEYPADH_KEYPADH_CFG_H_
#define ECUAL_KEYPADH_KEYPADH_CFG_H_
#include "Dio.h"
typedef enum
{
	KeypadH_Mode_PullUp=0,
	keypadH_Mode_PullDown
}KeypadH_ResistorPullMode_t;

typedef struct
{
	Dio_Pin_t KeypadInputPins[4];
	Dio_Pin_t KeypadOutpuPins[4];
	KeypadH_ResistorPullMode_t  keypad_Mode;
}KeypadH_cfg_t;

extern const KeypadH_cfg_t keypadH_cfg[];

extern const uint8 KeyPadNum;

#endif /* ECUAL_KEYPADH_KEYPADH_CFG_H_ */
