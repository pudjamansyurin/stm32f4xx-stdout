/*
 * stdout.h
 *
 *  Created on: May 5, 2022
 *      Author: pujak
 */

#ifndef STM32F4XX_TINYSH_STM32F4XX_STDOUT_STDOUT_H_
#define STM32F4XX_TINYSH_STM32F4XX_STDOUT_STDOUT_H_

#include "stm32f4xx_hal.h"
#include <stdio.h>

/* Exported types
 * --------------------------------------------*/
typedef void (*stdout_lock)(FunctionalState lock);

typedef struct {
  UART_HandleTypeDef *huart;
  stdout_lock lock;
} stdout_t;

/* Public function declarations */
void stdout_init(UART_HandleTypeDef *uart, stdout_lock lock);

#endif /* STM32F4XX_TINYSH_STM32F4XX_STDOUT_STDOUT_H_ */
