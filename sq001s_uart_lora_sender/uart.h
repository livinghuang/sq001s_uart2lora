#ifndef UART_H
#define UART_H
#include "global.h"
void uart_init();
bool uart_loop(struct data_struct *received);
#endif