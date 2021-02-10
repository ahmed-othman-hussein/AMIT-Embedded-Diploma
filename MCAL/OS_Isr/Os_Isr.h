/*
 * Os_Isr.h
 *
 *  Created on: Sep 20, 2019
 *      Author: Ahmed othman
 */

#ifndef OS_ISR_H_
#define OS_ISR_H_
#include "Os_Isr_cfg.h"
typedef enum
{

	INT0        =0,
	INT1          ,
	INT2          ,
	TIMER2_COMP   ,
	TIMER2_OVF    ,
	TIMER1_CAPT   ,
	TIMER1_COMPA  ,
	TIMER1_COMPB  ,
	TIMER1_OVF    ,
	TIMER0_COMP   ,
	TIMER0_OVF    ,
	SPI_STC       ,
	USART_RXC     ,
	USART_UDRE    ,
	USART_TXC     ,
	ADC           ,
	EE_RDY        ,
	ANA_COMP      ,
	TWI           ,
	SPM_RDY       ,


}Interrupt_t;



extern void Os_Isr_disableAllInterrupts(void);

extern void Os_Isr_EnableableAllInterrupts(void);


extern void Os_Isr_EnableInterrupt(Interrupt_t interrupt);

extern void Os_Isr_disableInterrupt(Interrupt_t interrupt);


#endif /* OS_ISR_H_ */
