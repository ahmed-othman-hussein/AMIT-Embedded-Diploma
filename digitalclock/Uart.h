/*
 * Uart.h
 *
 *  Created on: Oct 11, 2019
 *      Author: Ahmed othman
 */

#ifndef BSW_MCAL_UART_UART_H_
#define BSW_MCAL_UART_UART_H_
#include "Uart_cfg.h"

extern void Uart_init(void);

extern void Uart_send(uint8 * sentBuffer, uint8 size );

extern void Uart_recieve(uint8 * RecieveBuffer, uint8 size );

extern void UartRXISR(void);
extern void UartTXISR(void);

#endif /* BSW_MCAL_UART_UART_H_ */
