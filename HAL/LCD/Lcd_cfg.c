/*
 * Lcd_cfg.c
 *
 *  Created on: Sep 13, 2019
 *      Author: Ahmed othman
 */
#include "STD_TYPES.h"
#include "Dio.h"
#include "Lcd_cfg.h"

 const Lcd_cfg_t Lcd_cfg[]=
 {
	/*LcdID   RS   RW  E    DB0 DB1  DB2  DB3  DB4  DB5  DB6  DB7  MODE */
	/*  0*/	 {Pb1,Pb2,Pb3,{NULL,NULL,NULL,NULL,Pa4, Pa5, Pa6, Pa7},LCD_4_BIT},
	/*  1*/	 {Pb4,Pb5,Pb6,{Pd0, Pd1, Pd2, Pd3, Pd4, Pd5, Pd6, Pd7},LCD_8_BIT}

 };

 const uint8 LcdCount = sizeof(Lcd_cfg)/sizeof(Lcd_cfg_t);
