/*
 * Os_Isr.c
 *
 *  Created on: Sep 20, 2019
 *      Author: Ahmed othman
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "Register.h"

#include "Os_Isr.h"

extern void Os_Isr_disableAllInterrupts(void)
{
	CLR_BIT(SREG,SREG_I);
}

extern void Os_Isr_EnableableAllInterrupts(void)
{
	SET_BIT(SREG,SREG_I);
}


extern void Os_Isr_EnableInterrupt(Interrupt_t interrupt)
{

	switch (interrupt)
	{
	case INT0:
		SET_BIT(GICR,GICR_INT0);
		break;
	case INT1:
		SET_BIT(GICR,GICR_INT1);
		break;
	case INT2:
		SET_BIT(GICR,GICR_INT2);
		break;
	case TIMER0_COMP:
		SET_BIT(TIMSK,1);
		break;
	case TIMER1_COMPA:
			SET_BIT(TIMSK,4);
			break;
	default:
		break;
	}

}

extern void Os_Isr_disableInterrupt(Interrupt_t interrupt)
{

	switch (interrupt)
	{
	case INT0:
		CLR_BIT(GICR,GICR_INT0);
		break;
	case INT1:
		CLR_BIT(GICR,GICR_INT1);
		break;
	case INT2:
		CLR_BIT(GICR,GICR_INT2);
		break;
	case TIMER0_COMP:
		CLR_BIT(TIMSK,1);
		break;
	default:
		break;
	}

}


#if E_INT0         == STD_ENABLED
void __vector_1(void) __attribute__((signal,used));
void __vector_1(void)
{
	if(ivt[0].callBackFucntion != NULL_PTR)
	{
		ivt[0].callBackFucntion();

	}
}
#endif
#if E_INT1         == STD_ENABLED
void __vector_2(void) __attribute__((signal,used));
void __vector_2(void)
{
	if(ivt[1].callBackFucntion != NULL_PTR)
	{
		ivt[1].callBackFucntion();
	}
}
#endif
#if E_INT2         == STD_ENABLED
void __vector_3(void) __attribute__((signal,used));
void __vector_3(void)
{
	if(ivt[2].callBackFucntion != NULL_PTR)
	{
		ivt[2].callBackFucntion();
	}
}
#endif
#if E_TIMER2_COMP  == STD_ENABLED
void __vector_4(void) __attribute__((signal,used));
void __vector_4(void)
{
	if(ivt[3].callBackFucntion != NULL_PTR)
	{
		ivt[3].callBackFucntion();
	}
}
#endif
#if E_TIMER2_OVF   == STD_ENABLED
void __vector_5(void) __attribute__((signal,used));
void __vector_5(void)
{
	if(ivt[4].callBackFucntion != NULL_PTR)
	{
		ivt[4].callBackFucntion();
	}
}
#endif
#if E_TIMER1_CAPT  == STD_ENABLED
void __vector_6(void) __attribute__((signal,used));
void __vector_6(void)
{
	if(ivt[5].callBackFucntion != NULL_PTR)
	{
		ivt[5].callBackFucntion();
	}
}
#endif
#if E_TIMER1_COMPA == STD_ENABLED
void __vector_7(void) __attribute__((signal,used));
void __vector_7(void)
{
	if(ivt[6].callBackFucntion != NULL_PTR)
	{
		ivt[6].callBackFucntion();
	}
}
#endif
#if E_TIMER1_COMPB == STD_ENABLED
void __vector_8(void) __attribute__((signal,used));
void __vector_8(void)
{
	if(ivt[7].callBackFucntion != NULL_PTR)
	{
		ivt[7].callBackFucntion();
	}
}
#endif
#if E_TIMER1_OVF   == STD_ENABLED
void __vector_9(void) __attribute__((signal,used));
void __vector_9(void)
{
	if(ivt[8].callBackFucntion != NULL_PTR)
	{
		ivt[8].callBackFucntion();
	}
}
#endif
#if E_TIMER0_COMP  == STD_ENABLED
void __vector_10(void) __attribute__((signal,used));
void __vector_10(void)
{
	if(ivt[9].callBackFucntion != NULL_PTR)
	{
		ivt[9].callBackFucntion();
	}
}
#endif
#if E_TIMER0_OVF   == STD_ENABLED
void __vector_11(void) __attribute__((signal,used));
void __vector_11(void)
{
	if(ivt[10].callBackFucntion != NULL_PTR)
	{
		ivt[10].callBackFucntion();
	}
}
#endif
#if E_SPI_STC      == STD_ENABLED
void __vector_12(void) __attribute__((signal,used));
void __vector_12(void)
{
	if(ivt[11].callBackFucntion != NULL_PTR)
	{
		ivt[11].callBackFucntion();
	}
}
#endif
#if E_USART_RXC    == STD_ENABLED
void __vector_13(void) __attribute__((signal,used));
void __vector_13(void)
{
	if(ivt[12].callBackFucntion != NULL_PTR)
	{
		ivt[12].callBackFucntion();
	}
}
#endif
#if E_USART_UDRE   == STD_ENABLED
void __vector_14(void) __attribute__((signal,used));
void __vector_14(void)
{
	if(ivt[13].callBackFucntion != NULL_PTR)
	{
		ivt[13].callBackFucntion();
	}
}
#endif
#if E_USART_TXC    == STD_ENABLED
void __vector_15(void) __attribute__((signal,used));
void __vector_15(void)
{
	if(ivt[14].callBackFucntion != NULL_PTR)
	{
		ivt[14].callBackFucntion();
	}
}
#endif
#if E_ADC       == STD_ENABLED
void __vector_16(void) __attribute__((signal,used));
void __vector_16(void)
{
	if(ivt[15].callBackFucntion != NULL_PTR)
	{
		ivt[15].callBackFucntion();
	}
}
#endif
#if E_EE_RDY       == STD_ENABLED
void __vector_17(void) __attribute__((signal,used));
void __vector_17(void)
{
	if(ivt[16].callBackFucntion != NULL_PTR)
	{
		ivt[16].callBackFucntion();
	}
}
#endif
#if E_ANA_COMP     == STD_ENABLED
void __vector_18(void) __attribute__((signal,used));
void __vector_18(void)
{
	if(ivt[17].callBackFucntion != NULL_PTR)
	{
		ivt[17].callBackFucntion();
	}
}
#endif
#if E_TWI          == STD_ENABLED
void __vector_19(void) __attribute__((signal,used));
void __vector_19(void)
{
	if(ivt[18].callBackFucntion != NULL_PTR)
	{
		ivt[18].callBackFucntion();
	}
}
#endif
#if E_SPM_RDY      == STD_ENABLED
void __vector_20(void) __attribute__((signal,used));
void __vector_20(void)
{
	if(ivt[19].callBackFucntion != NULL_PTR)
	{
		ivt[19].callBackFucntion();
	}
}
#endif
