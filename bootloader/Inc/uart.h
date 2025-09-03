#ifndef UART_H_
#define UART_H_

#include "stm32f4xx.h"
#define SR_RXNE					(1U<<5)

void sys_uart_init(void);


#endif
