/*
 * KeypadH_cfg.c

 *
 *  Created on: Oct 5, 2018
 *      Author: Ahmed othman
 */
#include "STD_TYPES.h"
#include "Keypad_cfg.h"

const KeypadH_cfg_t keypadH_cfg[]=
		{
				{{Pa0,Pa0,Pa0,Pa0},{Pa0,Pa0,Pa0,Pa0},KeypadH_Mode_PullUp}
		};

const uint8 KeyPadNum = sizeof(keypadH_cfg)/sizeof(KeypadH_cfg_t);
