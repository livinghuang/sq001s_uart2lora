#include "uart.h"
#include "sq_queue.h"

// Define the serial port
HardwareSerial uartSerial(1); // Using Serial1 (hardware serial)

// Buffer to hold incoming data
String receivedData = "";

void uart_init()
{
  // Initialize Serial1 with custom RX (19) and TX (18) pins, and baud rate of 115200
  uartSerial.begin(115200, SERIAL_8N1, RX1, TX1); // Parameters: baud rate, config, RX pin, TX pin
  Serial.println("ESP32 uartSerial communication started at 115200 baud.");
}

bool uart_loop(struct data_struct *received)
{
  received->timestamp = millis();
  memset(received->data, 0, MAX_DATA_SIZE);
  uartSerial.setRxTimeout(100);
  int len = uartSerial.readBytesUntil('\n', &record.data[0], MAX_DATA_SIZE);
  if (len < 2)
    return false;
  // print_data(received);
  return true;
}