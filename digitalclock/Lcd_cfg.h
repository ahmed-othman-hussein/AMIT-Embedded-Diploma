/*
 * Lcd_cfg.h
 *
 *  Created on: Sep 13, 2019
 *      Author: Ahmed othman
 */

#ifndef LCD_CFG_H_
#define LCD_CFG_H_
typedef enum
{
	LCD_4_BIT =0,
	LCD_8_BIT


}Lcd_mode_t;
typedef enum
{
	COMMAND =0,
	DATA

}Byte_type_t;


typedef struct
{
	Dio_Pin_t   Rs;
	Dio_Pin_t   RW;
	Dio_Pin_t   E;

	Dio_Pin_t   DB[8];

	Lcd_mode_t  mode;


}Lcd_cfg_t;

extern const Lcd_cfg_t Lcd_cfg[];

extern const uint8 LcdCount;



#endif /* LCD_CFG_H_ */
