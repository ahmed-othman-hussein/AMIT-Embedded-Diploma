/*
 * KeypadH.h
 *
 *  Created on: Feb 26, 2018
 *      Author: Ahmed othman
 */

#ifndef KEYPADH_H_
#define KEYPADH_H_

#include "Keypad_cfg.h"

/********************************************************************/
/*   this fun is used to initialize the keypad                      */
/********************************************************************/
extern void KEYPADH_Init(void);

/********************************************************************/
/*   this fun updates the  status of the buttons on the keypad 	    */
/*               as values from 0~16                                */
/********************************************************************/
extern void KEYPADH_Task(void);

/********************************************************************/
/*   this fun is used to return  the pressed button value           */
/*                values are 0~F                                    */
/********************************************************************/
extern uint8 KEYPADH_GetValue(uint8 keypadNum);




/********************************************************************/
/*   this fun is used to return  1 if there's button pressed        */
/********************************************************************/
extern uint8 KEYPADH_keypressed(uint8 KeypadNum);






#endif /* KEYPADH_H_ */

