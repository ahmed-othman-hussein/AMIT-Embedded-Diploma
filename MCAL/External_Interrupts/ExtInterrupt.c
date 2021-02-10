/*
 * ExtInterrupt.c
 *
 *  Created on: Sep 21, 2019
 *      Author: Ahmed othman
 */
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "Register.h"
#include "ExtInterrupt.h"
#include "ExtInterrupt_cfg.h"

void ExtInterrupt_init(void)
{

#if EXT_INT0_MODE == MODE_RISING_EDGE
	SET_BIT(MCUCR,MCUR_ISC00);
	SET_BIT(MCUCR,MCUR_ISC01);
#elif  EXT_INT0_MODE == MODE_FALLING_EDGE
	CLR_BIT(MCUCR,MCUR_ISC00);
	SET_BIT(MCUCR,MCUR_ISC01);

#else
	CLR_BIT(MCUCR,MCUR_ISC01);
	SET_BIT(MCUCR,MCUR_ISC00);
#endif


}



