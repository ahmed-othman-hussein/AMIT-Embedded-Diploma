/*
 * Led_cfg.h
 *
 *  Created on: Sep 7, 2019
 *      Author: Ahmed othman
 */

#ifndef LED_CFG_H_
#define LED_CFG_H_

typedef enum
{
	Led_Active_High =0,
	Led_Active_Low

}Led_Mode_t;


typedef struct
{
	Dio_Pin_t  pin;
	Led_Mode_t mode;

}Led_cfg_t;

extern const Led_cfg_t Led_cfg[];
extern const uint8     LedCount;
#endif /* LED_CFG_H_ */
