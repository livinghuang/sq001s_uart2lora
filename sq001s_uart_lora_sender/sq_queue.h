#ifndef UART_QUEUE_H
#define UART_QUEUE_H
#include "global.h"

void queue_example();
void uartQ_enqueue(struct data_struct *data);
struct data_struct uartQ_dequeue();
bool uartQ_is_empty();
bool uartQ_is_full();
int uartQ_size();
#endif
