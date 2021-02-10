/*
 * Lcd.h
 *
 *  Created on: Sep 13, 2019
 *      Author: Ahmed othman
 */

#ifndef LCD_H_
#define LCD_H_
#include "Lcd_cfg.h"

extern void Lcd_init(void);

extern void Lcd_writeChar(uint8 LcdID, uint8 data , uint8 row , uint8 col);

extern void Lcd_writeString(uint8 LcdID, uint8 * data , uint8 row , uint8 col);
extern void writeByte(uint8 LcdID ,Byte_type_t type , uint8 byte);
#endif /* LCD_H_ */
