/*
 * stdout.c
 *
 *  Created on: May 5, 2022
 *      Author: pujak
 */
#include "stdout.h"

/* Private variables */
static UART_HandleTypeDef *huart;

/* Private function definitions */
static void transmit(char *str, int len)
{
  HAL_UART_Transmit(huart, (uint8_t*) str, len, HAL_MAX_DELAY);
}

/* Public function definitions */
void stdout_init(UART_HandleTypeDef *uart)
{
  huart = uart;

  /* disable stdio buffering */
  setvbuf(stdout, NULL, _IONBF, 0);
}

/* Replace weak syscalls routines */
int __io_putchar(int ch)
{
  transmit((char*) &ch, 1);
  return (ch);
}

int _write(int file, char *ptr, int len)
{
  transmit(ptr, len);
  return len;
}
