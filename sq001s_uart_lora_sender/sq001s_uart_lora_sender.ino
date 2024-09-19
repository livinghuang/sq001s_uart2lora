/* Heltec Automation send communication test example
 *
 * Function:
 * 1. Send data from a esp32 device over hardware
 *
 * Description:
 *
 * HelTec AutoMation, Chengdu, China
 * 成都惠利特自动化科技有限公司
 * www.heltec.org
 *
 * this project also realess in GitHub:
 * https://github.com/Heltec-Aaron-Lee/WiFi_Kit_series
 * */
#include "global.h"

TaskHandle_t uart_task;
struct data_struct record;
bool awake = false;
void uart_rx_interrupt()
{
  if (!awake)
  {
    awake = true;
  }
}
void uart_task_func(void *pvParameters)
{
  uart_init();
  while (1)
  {
    if (uart_loop(&record))
    {
      uartQ_enqueue(&record);
    }
  }
}
void setup()
{
  Serial.begin(115200);
  Mcu.begin(HELTEC_BOARD, SLOW_CLK_TPYE);
  lora_init();
  attachInterrupt(RX1, uart_rx_interrupt, CHANGE);
  xTaskCreate(
      uart_task_func, // Task function
      "uart_task",    // Name of the task
      1000,           // Stack size for the task
      NULL,           // Task input parameter
      1,              // Priority of the task
      &uart_task);    // Task handle
}

void loop()
{
  lora_loop();
}
