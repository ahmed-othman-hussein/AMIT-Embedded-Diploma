#ifndef _AVR_32_REGISTER_H
#define _AVR_32_REGISTER_H

/*********************** DIO registers *****************/
/* Group A REGISTER*/
#define PORTA *((uint8*)0x3B)
#define DDRA *((uint8*)0x3A)
#define PINA *((volatile uint8*)0x39)

/* Group B REGISTER*/
#define PORTB *((uint8*)0x38)
#define DDRB *((uint8*)0x37)
#define PINB *((volatile uint8*)0x36)

/* Group C REGISTER*/
#define PORTC *((uint8*)0x35)
#define DDRC *((uint8*)0x34)
#define PINC *((volatile uint8*)0x33)

/* Group D REGISTER*/
#define PORTD *((uint8*)0x32)
#define DDRD *((uint8*)0x31)
#define PIND *((volatile uint8*)0x30)
/********************************************************/
#define SREG *((volatile uint8*) 0x5F)

#define SREG_I   7
/*******************************************************/

#define MCUCR   *((volatile uint8*) 0x55)
#define MCUCSR  *((volatile uint8 *)0x54)
#define GICR    *((volatile uint8*) 0x5B)
#define GIFR    *((volatile uint8*) 0x5A)

#define MCUR_ISC00  0
#define MCUR_ISC01  1
#define MCUR_ISC10  2
#define MCUR_ISC11  3

#define MCUCSR_ISC2 6

#define GIFR_INTF0  6
#define GIFR_INTF1  7
#define GIFR_INTF2  5

#define GICR_INT0   6
#define GICR_INT1   7
#define GICR_INT2   5



#define TCCR0 *((volatile uint8*)0x53)
/*Timer 0/Counter Register*/
#define TCNT0 *((volatile uint8*)0x52)
/*Timer 0's Output Compare Register*/
#define OCR0 *((volatile uint8*)0x5C)
/*Timer/Counter Interrupt Mask Register*/
#define TIMSK *((volatile uint8*)0x59)
/*Timer/Counter Interrupt Flag Register*/
#define TIFR *((volatile uint8*)0x58)

#define TCCR1B *((volatile uint8*)0x4E)
/*Timer 1/Counter Register*/
#define TCNT1 *((volatile uint8*)0x4D)
/*Timer 0's Output Compare Register*/
#define OCR1A *((volatile uint8*)0x4B)
/*Timer/Counter Interrupt Mask Register*/
#define TIMSK *((volatile uint8*)0x59)
/*Timer/Counter Interrupt Flag Register*/
#define TIFR *((volatile uint8*)0x58)
#define CS12  2
#define CS10  0
#define WGM12  3
#define OCIE1A  4

/*******************************************************/
#define TCCR2 *((volatile uint8*)0x45)
#define TCCR2_WGM20 6
#define TCCR2_WGM21 3
#define TCCR2_CS20  0
#define TCCR2_CS21  1
#define TCCR2_CS22  2
#define TCCR2_COM21  5
#define TCCR2_COM20  4

/*Timer 0/Counter Register*/
#define TCNT2 *((volatile uint8*)0x44)
/*Timer 0's Output Compare Register*/
#define OCR2 *((volatile uint8*)0x43)


#define ADMUX				*((uint8*)0x27)
#define ADMUX_ADLAR          5
#define ADCSRA				*((uint8*)0x26)
#define ADCSRA_ADIE          3
#define ADCSRA_ADATE         5
#define ADCSRA_ADSC          6
#define ADCSRA_ADEN          7
#define SFIOR				*((uint8*)0x50)
#define ADCR				*((uint16*)0x24)
#define ADCH                *((uint8*)0x24)
#define ADCL                *((uint8*)0x25)

/*****************uart********************/
#define UDR   *((volatile uint8*)0x2C)
#define UCSRA *((volatile uint8*)0x2B)
#define UCSRB *((volatile uint8*)0x2A)
#define UCSRC *((volatile uint8*)0x40)
#define UBRRL *((volatile uint8*)0x29)
#define UBRRH *((volatile uint8*)0x40)

#define UDRE 5
#define RXC 7
#define TXC 6
#define RXEN 4
#define TXEN 3
#define RXCIE 7
#define URSEL 7
#define USBS 3
#define UCSZ0 1
#define UCSZ1 2
/****************SPI**************************/
#define SPDR         *((volatile uint8*) 0x2F)
#define SPSR         *((volatile uint8*) 0x2E)
#define SPSR_SPIF    7
#define SPSR_WCOL    6
#define SPSR_SPR2x   0
#define SPCR         *((volatile uint8*) 0x2D)
#define SPCR_SPIE    7
#define SPCR_SPE     6
#define SPCR_DORD    5
#define SPCR_MSTR    4
#define SPCR_CPOL    3
#define SPCR_CPHA    2
#define SPCR_SPR1    1
#define SPCR_SPR0    0








#endif  
