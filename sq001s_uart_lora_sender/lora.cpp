#include "lora.h"
#include "global.h"

#define RF_FREQUENCY 920000000 // Hz

#define TX_OUTPUT_POWER 20 // dBm

#define LORA_BANDWIDTH 0         // [0: 125 kHz,
                                 //  1: 250 kHz,
                                 //  2: 500 kHz,
                                 //  3: Reserved]
#define LORA_SPREADING_FACTOR 12 // [SF7..SF12]
#define LORA_CODINGRATE 1        // [1: 4/5,
                                 //  2: 4/6,
                                 //  3: 4/7,
                                 //  4: 4/8]
#define LORA_PREAMBLE_LENGTH 8   // Same for Tx and Rx
#define LORA_SYMBOL_TIMEOUT 0    // Symbols
#define LORA_FIX_LENGTH_PAYLOAD_ON false
#define LORA_IQ_INVERSION_ON false

#define RX_TIMEOUT_VALUE 1000
#define BUFFER_SIZE 30 // Define the payload size here

char txpacket[BUFFER_SIZE];
char rxpacket[BUFFER_SIZE];

double txNumber;

bool lora_idle = true;

static RadioEvents_t RadioEvents;
void OnTxDone(void);
void OnTxTimeout(void);

void lora_init()
{
  txNumber = 0;

  RadioEvents.TxDone = OnTxDone;
  RadioEvents.TxTimeout = OnTxTimeout;

  Radio.Init(&RadioEvents);
  Radio.SetChannel(RF_FREQUENCY);
  Radio.SetTxConfig(MODEM_LORA, TX_OUTPUT_POWER, 0, LORA_BANDWIDTH,
                    LORA_SPREADING_FACTOR, LORA_CODINGRATE,
                    LORA_PREAMBLE_LENGTH, LORA_FIX_LENGTH_PAYLOAD_ON,
                    true, 0, 0, LORA_IQ_INVERSION_ON, 3000);
}

void lora_loop()
{
  if ((lora_idle == true) && (!uartQ_is_empty()))
  {

    struct data_struct recorded = uartQ_dequeue();
    // print_data(&recorded);
    // strlen(recorded.data);
    // appDataSize = sizeof(record.timestamp) + strnlen(recorded.data, 45);
    Serial.println("queue size:" + (String)uartQ_size());
    memcpy(appData, &recorded, appDataSize);

    // delay(1000);
    // txNumber += 0.01;

    sprintf(txpacket, "B:%.2f,%ld:%s", getBatteryVoltage(), recorded.timestamp, recorded.data); // start a package

    Serial.printf("\r\nsending packet \"%s\" , length %d\r\n", txpacket, strlen(txpacket));

    Radio.Send((uint8_t *)txpacket, strlen(txpacket)); // send the package out
    lora_idle = false;
  }
  Radio.IrqProcess();
}

void OnTxDone(void)
{
  Serial.println("TX done......");
  lora_idle = true;
}

void OnTxTimeout(void)
{
  Radio.Sleep();
  Serial.println("TX Timeout......");
  lora_idle = true;
}
