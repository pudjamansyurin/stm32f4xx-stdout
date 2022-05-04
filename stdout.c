/*
 * stdout.c
 *
 *  Created on: May 5, 2022
 *      Author: pujak
 */
#include "stdout.h"

/* Private variables */
static stdout_t hstdout;

/* Private function definitions */
static void transmit(char *str, int len)
{
  if (NULL != hstdout.lock)
    hstdout.lock(ENABLE);

  HAL_UART_Transmit(hstdout.huart, (uint8_t*) str, len, HAL_MAX_DELAY);

  if (NULL != hstdout.lock)
    hstdout.lock(DISABLE);
}

/* Public function definitions */
void stdout_init(UART_HandleTypeDef *uart, stdout_lock lock)
{
  hstdout.huart = uart;
  hstdout.lock = lock;

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
