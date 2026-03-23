# 👓 Smart Blind Assistance Glasses (ESP32-C3 + VL53L0X)

## 📌 Project Overview

This project is a wearable assistive device designed for visually impaired people. It uses distance sensors to detect obstacles and provides real-time feedback using a buzzer.

The system helps users understand how close objects are by changing the speed of beeping sounds.

---

## 🚀 Features

* 🔍 Dual distance sensing (left & right)
* 🔊 Passive buzzer alert system
* ⚡ Real-time obstacle detection
* 🎯 Distance-based alert intensity
* 👓 Wearable prototype (glasses-mounted)

---

## 🧠 Working Principle

* Two VL53L0X ToF (Time-of-Flight) sensors measure distance.
* ESP32-C3 processes the data.
* The closest object distance is used to control buzzer output.
* Beep speed increases as object gets closer.

---

## 🔌 Components Used

* ESP32-C3 Development Board
* 2 × VL53L0X Distance Sensors
* Passive Buzzer
* Jumper Wires
* Breadboard (for prototype)

---

## ⚙️ Pin Connections

### 📏 Sensors (I2C Shared)

* SDA → GPIO 8
* SCL → GPIO 9
* VCC → 5V
* GND → GND

### 🔘 XSHUT Control

* Left Sensor XSHUT → GPIO 4
* Right Sensor XSHUT → GPIO 5

### 🔊 Buzzer

* Positive → GPIO 2
* Negative → GND

---

## 🔊 Buzzer Logic

| Distance  | Output          |
| --------- | --------------- |
| > 100 cm  | No sound        |
| 60–100 cm | Slow beep       |
| 30–60 cm  | Medium beep     |
| 10–30 cm  | Fast beep       |
| < 10 cm   | Continuous tone |

---

## 💻 Software Requirements

* Arduino IDE
* ESP32 Board Package
* Libraries:

  * Adafruit VL53L0X
  * Adafruit BusIO

---

## 📂 How to Run

1. Install required libraries in Arduino IDE
2. Select board: **ESP32C3 Dev Module**
3. Connect hardware as per diagram
4. Upload the code
5. Power the system and test with obstacles

---

## 🧪 Testing

* Place objects at different distances
* Observe buzzer speed changes
* Cover one sensor to test left/right detection

---

## 📈 Future Improvements

* Add voice feedback (DFPlayer Mini)
* Add vibration motor for silent alerts
* Miniaturize circuit for real-world use
* Add battery + portable casing

---

## 🙌 Author

Hussain

---

## 📜 License

This project is open-source and free to use for educational purposes.
