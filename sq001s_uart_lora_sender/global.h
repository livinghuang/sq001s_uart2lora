#ifndef GLOBAL_H
#define GLOBAL_H

#include "Arduino.h"
#include "esp_system.h"
#include "LoRaWan_APP.h"
#include "Wire.h"
#include "esp_sleep.h"
#include <esp_timer.h>
#include <mbedtls/sha256.h>

#include "bsp.h"
#include "uart.h"
#include "sq_queue.h"
#include "lora.h"
#include "bat.h"

extern RTC_DATA_ATTR int bootCount; // 增加发送的数据包编号

#define MAX_DATA_SIZE 45

struct data_struct
{
  uint32_t timestamp;
  char data[MAX_DATA_SIZE];
};
typedef struct data_struct data_struct;
extern struct data_struct record;
void printHex(byte *data, int length);
void run_with_time_escape(uint64_t escape_period_ms, void (*callback)(), void (*stop_callback)());
esp_sleep_wakeup_cause_t print_wakeup_reason();
uint64_t get_chip_id();
void print_data(struct data_struct *data);
void generate_lorawan_settings_by_chip_id();
void print_bytes(uint8_t *data, int length);
void print_bytes_reverse(uint8_t *data, int length);
#endif