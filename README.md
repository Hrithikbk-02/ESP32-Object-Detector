This project demonstrates real-time object detection using an **IR sensor** and **ESP32**, with status updates displayed on an **HTTP web server**. The web page automatically refreshes every 2 seconds to show the latest detection status.

## Features
- Detects objects using an **IR sensor**
- Sends real-time status updates to a **web server**
- Displays object detection status on a **web page**
- Auto-refreshing web page every **2 seconds**
- **WiFi reconnect mechanism** to ensure stability

## Components Required
- **ESP32**
- **IR Sensor (Digital Output)**
- **Jumper Wires**
- **Breadboard (optional)**

## Circuit Diagram
- Connect the **VCC** of the IR sensor to **3.3V** or **5V** (as per your sensor specifications)
- Connect the **GND** of the IR sensor to **GND** of the ESP32
- Connect the **OUT** of the IR sensor to **GPIO 15** of the ESP32

## Installation & Usage
### 1. Install Required Software
- Install **Arduino IDE** (or **PlatformIO** if preferred)
- Install **ESP32 Board Package** in Arduino IDE
- Install the required libraries:
  - `WiFi.h`
  - `WebServer.h`

### 2. Upload the Code
- Open the **Arduino IDE** and select the correct **ESP32 board** and **COM port**
- Modify the WiFi credentials in the code:
  ```cpp
  const char* ssid = "Your_SSID";
  const char* password = "Your_PASSWORD";
  ```
- Upload the code to your ESP32

### 3. Connect to the Web Server

- Open the **Serial Monitor (115200 baud rate)** to check the ESP32's IP address
- Enter the displayed IP address in any web browser
- The webpage will show the object detection status
