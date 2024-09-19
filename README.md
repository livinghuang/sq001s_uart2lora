---

# SQ001S_UART2LORA Project

The **SQ001S_UART2LORA** project is designed to send and receive UART messages via LoRa communication using the **SQ001S PCB board**. It is built on the Arduino platform and comprises two primary components: the **sender** and the **receiver**.

## Project Overview

- **Platform:** Arduino
- **Hardware Base:** SQ001S PCB board
- **Communication Protocol:** LoRa for wireless transmission
- **UART Interface:** Used for data input on the sender

### Sender: `sq001s_uart_lora_sender`

The sender module is responsible for:
- Receiving messages via the UART interface
- Transmitting these messages over LoRa to the receiver module

### Receiver: `sq001s_uart_lora_receiver`

The receiver module is responsible for:
- Listening for incoming LoRa messages
- Outputting the received messages via the UART interface

## Components

- **SQ001S PCB Board:** Hardware base for the project
- **LoRa Module:** Handles wireless communication between the sender and receiver
- **UART Interface:** For serial communication on both sender and receiver

## Installation and Setup

1. Clone the repository containing the two Arduino projects:
   - `sq001s_uart_lora_sender`
   - `sq001s_uart_lora_receiver`

2. Open the respective Arduino project files in the Arduino IDE.

3. Upload the sender sketch to the Arduino board connected to the **sender** module.

4. Upload the receiver sketch to the Arduino board connected to the **receiver** module.

5. Connect the UART interfaces to your devices for message input (sender) and output (receiver).

## How It Works

1. **Sender**: The UART interface of the sender module reads incoming messages, then these messages are wirelessly transmitted via LoRa.

2. **Receiver**: The receiver listens for incoming LoRa messages and forwards them to its UART interface for output.

## Usage

- Connect the sender module to the source of UART messages.
- Connect the receiver module to the target device to receive and process the messages.
- Ensure both modules are powered and within range for LoRa communication.

---
# SQ001S_UART2LORA 專案

**SQ001S_UART2LORA** 專案設計目的是透過 LoRa 通訊傳送和接收 UART 訊息，使用 **SQ001S PCB 板** 作為硬體基礎。本專案基於 Arduino 平台，由兩個主要模組組成：**發送端** 和 **接收端**。

## 專案概述

- **平台：** Arduino
- **硬體基礎：** SQ001S PCB 板
- **通訊協議：** LoRa 用於無線傳輸
- **UART 介面：** 用於發送端的數據輸入

### 發送端：`sq001s_uart_lora_sender`

發送端模組的功能：
- 透過 UART 介面接收訊息
- 通過 LoRa 將訊息傳送給接收端模組

### 接收端：`sq001s_uart_lora_receiver`

接收端模組的功能：
- 監聽來自 LoRa 的訊息
- 透過 UART 介面輸出接收到的訊息

## 元件

- **SQ001S PCB 板：** 專案硬體基礎
- **LoRa 模組：** 負責發送端與接收端之間的無線通訊
- **UART 介面：** 用於發送端和接收端的串行通訊

## 安裝與設置

1. 複製包含兩個 Arduino 專案的程式庫：
   - `sq001s_uart_lora_sender`
   - `sq001s_uart_lora_receiver`

2. 在 Arduino IDE 中打開相應的 Arduino 專案文件。

3. 將發送端程式上傳到與**發送端**模組連接的 Arduino 板。

4. 將接收端程式上傳到與**接收端**模組連接的 Arduino 板。

5. 將 UART 介面分別連接到您的設備以進行訊息輸入（發送端）和輸出（接收端）。

## 運作方式

1. **發送端**：發送端模組的 UART 介面讀取傳入訊息，然後透過 LoRa 將這些訊息無線傳輸。
2. **接收端**：接收端接收來自 LoRa 的訊息，並透過其 UART 介面將訊息輸出。

## 使用方法

- 將發送端模組連接到 UART 訊息的來源。
- 將接收端模組連接到目標設備以接收和處理訊息。
- 確保兩個模組都已供電且位於 LoRa 通訊範圍內。
---