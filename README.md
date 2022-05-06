# STM32F4xx standard output using UART (Blocking Mode)


#### **`main.c`**
```c
#include "stm32f4xx-stdout/stdout.h"

/* Entry Point */
int main(void)
{
  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* Configure the system clock */
  SystemClock_Config();

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_USART2_UART_Init();
  
  /* Initialize serial layer, without custom lock */  
  stdout_init(&huart2, NULL);

  /* Super loop */
  while(1) {
    printf("Hello World\n");
    HAL_Delay(100);
  }
}
```
