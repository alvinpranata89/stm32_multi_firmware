#include <stdio.h>
#include "stm32f4xx.h"
#include "fpu.h"
#include "uart.h"
#include "timebase.h"
#include "bsp.h"

/*Modules:
 * FPU
 * UART
 * TIMEBASE
 * GPIO (BSP)
 * ADC
 * */




#define VECT_TAB_BASE_ADDRESS		FLASH_BASE
#define VECT_TAB_OFFSET				0xC000

#define  GPIOAEN		(1U<<0)
#define  PIN5			(1U<<5)
#define  LED_PIN		PIN5

bool btn_state;
int main()
{
	/*Enable FPU*/
	enable_fpu();

	/*Initialize debug UART*/
	sys_uart_init();

	/*Initialize timebase*/
	timebase_init();

	/*Initialize LED*/
	led_init();

	/*Initialize Push button*/

	button_init();
	while(1)
	{
		printf("Factory APP is running......\n\r");
		GPIOA->ODR ^= LED_PIN;
		delay(400);
	}
}


void SystemInit(void)
{
	SCB->VTOR = VECT_TAB_BASE_ADDRESS | VECT_TAB_OFFSET;
}
