/*
 * Os_Isr_cfg.c
 *
 *  Created on: Sep 20, 2019
 *      Author: Ahmed othman
 */

#include "STD_TYPES.h"
#include "Os_Isr_cfg.h"
#include "Uart.h"
#include "App.h"



const interrupt_vector_t  ivt[]=
{
		/* INT0         */   { NULL_PTR },
		/* INT1         */   { NULL_PTR },
		/* INT2         */   { NULL_PTR },
		/* TIMER2_COMP  */   { NULL_PTR },
		/* TIMER2_OVF   */   { NULL_PTR },
		/* TIMER1_CAPT  */   { NULL_PTR },
		/* TIMER1_COMPA */   { cloock},
		/* TIMER1_COMPB */   { NULL_PTR },
		/* TIMER1_OVF   */   { NULL_PTR },
		/* TIMER0_COMP  */   { NULL_PTR },
		/* TIMER0_OVF   */   { NULL_PTR },
		/* SPI_STC      */   { NULL_PTR },
		/* USART_RXC    */   { uartrxx },
		/* USART_UDRE   */   { NULL_PTR },
		/* USART_TXC    */   { NULL_PTR },
		/* ADC          */   { NULL_PTR },
		/* EE_RDY       */   { NULL_PTR },
		/* ANA_COMP     */   { NULL_PTR },
		/* TWI          */   { NULL_PTR },
		/* SPM_RDY      */   { NULL_PTR },

};


