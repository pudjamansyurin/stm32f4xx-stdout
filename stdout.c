/*
 * stdout.c
 *
 *  Created on: May 5, 2022
 *      Author: pujak
 */
#include "stdout.h"

/* Private variables */
static stdout_writer_t hwriter;

/* Public function definitions */
void stdout_init(stdout_writer_t writer)
{
  hwriter = writer;

  /* disable stdio buffering */
  setvbuf(stdout, NULL, _IONBF, 0);
}

/* Replace weak syscalls routines */
int __io_putchar(int ch)
{
  if (NULL != hwriter)
    hwriter((char*) &ch, 1);
  return (ch);
}

int _write(int file, char *ptr, int len)
{
  if (NULL != hwriter)
    hwriter(ptr, len);
  return len;
}
