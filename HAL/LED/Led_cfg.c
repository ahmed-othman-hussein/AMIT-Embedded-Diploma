/*
 * Led_cfg.c
 *
 *  Created on: Sep 7, 2019
 *      Author: Ahmed othman
 */
#include "STD_TYPES.h"
#include "Dio.h"
#include "Led_cfg.h"

const Led_cfg_t Led_cfg[]=

{	/*LED ID*/
	/*0*/	     {Pd3, Led_Active_High},
	/*1*/	     {Pc7, Led_Active_High},
	/*2*/	     {Pc2, Led_Active_High}

};
const uint8 LedCount= sizeof(Led_cfg)/ sizeof(Led_cfg_t);
