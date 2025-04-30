# 🚨 Alcohol Detection and Alert System using MQ-3 and Arduino

A real-time alcohol monitoring and alert system built with **Arduino**, **MQ-3 gas sensor**, **I2C LCD**, **buzzer**, and **LED**. This system detects the presence of alcohol in the air and issues visual and audio warnings when levels exceed a defined safety threshold.

---
![Image](https://github.com/user-attachments/assets/c01be09c-0506-4ceb-b595-9b00e2c47e24)

---

## 🛠️ Features

- 🔍 **Alcohol Sensing**: Uses MQ-3 to detect alcohol vapor in real time.
- 📟 **LCD Display**: 16x2 I2C LCD for displaying current alcohol level and status.
- 🚨 **Alerts**: Buzzer and LED activate when alcohol levels are high.
- 💻 **Serial Monitoring**: Output readings and status to Serial Monitor.
- 🔒 **Safety Application**: Ideal for vehicle ignition lock systems, driver checks, or industrial safety.

---

## ⚙️ Components Used

| Component             | Quantity |
|----------------------|----------|
| Arduino Uno/Nano     | 1        |
| MQ-3 Alcohol Sensor  | 1        |
| I2C 16x2 LCD Display | 1        |
| Buzzer               | 1        |
| LED                  | 1        |
| Resistors (220Ω)     | 1        |
| Jumper Wires         | -        |
| Breadboard           | 1        |

---

## 🔌 Circuit Diagram

> *(Insert Fritzing or wiring diagram here if available)*

- **MQ-3 Sensor**  
  - VCC → 5V  
  - GND → GND  
  - AOUT → A0  

- **LCD (I2C)**  
  - SDA → A4 (on Uno)  
  - SCL → A5 (on Uno)  

- **Buzzer** → Pin 9  
- **LED** → Pin 8 (with resistor)

---

## 📋 Installation & Upload

1. Connect all hardware components as per the circuit diagram.
2. Install the `LiquidCrystal_I2C` library in Arduino IDE.
3. Upload the code from `alcohol_monitor.ino` to your Arduino board.
4. Open Serial Monitor (9600 baud) to see readings.

---

## 📄 Code Overview

```cpp
int alcoholLevel = analogRead(mq3Pin);
if (alcoholLevel > threshold) {
  // Alert with buzzer and LED
}
