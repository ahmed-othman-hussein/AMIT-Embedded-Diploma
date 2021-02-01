/*
 * Os_Isr_cfg.h
 *
 *  Created on: Sep 20, 2019
 *      Author: Ahmed othman
 */

#ifndef OS_ISR_CFG_H_
#define OS_ISR_CFG_H_

typedef struct
{


	ptrFunction  callBackFucntion;

}interrupt_vector_t;


extern const interrupt_vector_t  ivt[];

#define E_INT0         STD_DISABLED
#define E_INT1         STD_DISABLED
#define E_INT2         STD_DISABLED
#define E_TIMER2_COMP  STD_DISABLED
#define E_TIMER2_OVF   STD_DISABLED
#define E_TIMER1_CAPT  STD_DISABLED
#define E_TIMER1_COMPA STD_ENABLED
#define E_TIMER1_COMPB STD_DISABLED
#define E_TIMER1_OVF   STD_DISABLED
#define E_TIMER0_COMP  STD_DISABLED
#define E_TIMER0_OVF   STD_DISABLED
#define E_SPI_STC      STD_DISABLED
#define E_USART_RXC    STD_ENABLED
#define E_USART_UDRE   STD_DISABLED
#define E_USART_TXC    STD_DISABLED
#define E_ADC          STD_DISABLED
#define E_EE_RDY       STD_DISABLED
#define E_ANA_COMP     STD_DISABLED
#define E_TWI          STD_DISABLED
#define E_SPM_RDY      STD_DISABLED

#endif /* OS_ISR_CFG_H_ */
