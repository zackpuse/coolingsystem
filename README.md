# 🚗 Battery Cooling System with Peltier and Fan Control for EV

This project is an **Arduino-based Battery Cooling System** for **Electric Vehicle (EV) applications**, utilizing **Peltier modules, fan control, and RPM feedback** to **prevent overheating and condensation**.

---

## 🎯 **Project Overview**
This system monitors **temperature, humidity, and fan RPM** using **DHT22**, **DS18B20**, and an **RPM sensor**. The **Peltier module and fans** are controlled based on real-time sensor data to **maintain optimal battery temperature** and **prevent condensation**.

---

## ✅ **Features**
- 🌡️ Temperature monitoring (Inflow Air and Heatsink Temp)
- 💧 Humidity monitoring
- 🔥 Peltier Anti-Freeze Control
- 🌀 Fan Speed Control (Cold & Hot Side)
- ⚡ Real-time RPM feedback
- 📡 Serial Debugging for performance monitoring

---

## 🛠️ **Hardware Components**
| Component               | Function                         |
|----------------|----------------------------|
| Arduino UNO/Nano | Microcontroller |
| DHT22 Sensor        | Temperature & Humidity Sensor |
| DS18B20 Sensor   | Heatsink Temperature Sensor |
| Peltier Module (TEC12706) | Cooling and Heating |
| MOSFET Module       | Peltier Power Control |
| 12V Fan with RPM Sensor | Cold Side & Hot Side Fan |
| Power Supply (12V/5A) | Power Source |

---

## 🛸 **System Architecture**
```
       +--------------------+
       |   Arduino UNO      |
       +--------------------+
                |
                |---> DHT22 (Temp & Humidity)
                |
                |---> DS18B20 (Heatsink Temp)
                |
                |---> Peltier Control (via MOSFET)
                |
                |---> Cold Fan Control (PWM)
                |
                |---> Hot Fan Control (PWM + RPM Sensor)
```

---

## 📂 **File Structure**
```
BatteryCoolingSystem/
│
├── main.ino
│
├── GlobalVariables.h
├── GlobalVariables.cpp
│
├── SensorRead.h
├── SensorRead.cpp
│
├── PeltierControl.h
├── PeltierControl.cpp
│
├── FanControl.h
├── FanControl.cpp
│
├── RPMCounter.h
├── RPMCounter.cpp
│
├── DebugPrint.h
└── DebugPrint.cpp
```

---

## 🛠️ **Pin Configuration**
| Sensor/Module     | Pin |
|-----------------|-----|
| DHT22                 | D2 |
| DS18B20            | D3 |
| Peltier Module    | D5 |
| Cold Fan            | D6 (PWM) |
| Hot Fan               | D9 (PWM + RPM Feedback) |
| RPM Sensor         | D2 (Interrupt Pin) |

---

## 📝 **How It Works**
### 🌡️ Sensor Reading (`SensorRead.cpp`)
- DHT22 reads **inflow temperature and humidity**.
- DS18B20 reads **heatsink temperature**.

### 🔥 Peltier Anti-Freeze Logic (`PeltierControl.cpp`)
- Turns **OFF Peltier when heatsink temp < 5°C** (prevent freezing).
- Turns **ON Peltier when inflow temp > 25°C** (prevent overheating).

### 🌀 Fan Speed Control (`FanControl.cpp`)
- **Cold fan increases speed** if humidity > 60% (prevent condensation).
- **Hot fan adjusts speed based on RPM feedback**.

### ⚡ RPM Calculation (`RPMCounter.cpp`)
- Counts fan pulses to calculate RPM every second.

---

## 📈 **Serial Monitor Output**
```
Inflow Temp: 27.5°C, Humidity: 62.0%, Heatsink Temp: 32.1°C, RPM: 2400
Inflow Temp: 28.1°C, Humidity: 58.3%, Heatsink Temp: 33.5°C, RPM: 2600
Inflow Temp: 28.5°C, Humidity: 55.2%, Heatsink Temp: 34.2°C, RPM: 3000
```

---

## 🚀 **Control Logic**
| Condition                 | Action |
|-----------------|----------------------------|
| Heatsink < 5°C        | Turn OFF Peltier |
| Inflow Temp > 25°C | Turn ON Peltier |
| Humidity > 60%      | Increase Cold Fan Speed |
| RPM > 3000             | Reduce Hot Fan Speed |

---

## 📌 **Next Improvement Plan**
✅ Upgrade to **ESP32** for wireless monitoring  
✅ Add **Battery Temperature Logging to SD Card**  
✅ Integrate with **BMS (Battery Management System)**  

---

## 📎 **References**
- Arduino Official Documentation  
- DS18B20 Datasheet  
- DHT22 Sensor Documentation  

---

## 🛸 **Contributors**
| Name                   | Role                         |
|----------------|-------------------|
| Fadli                  | Hardware Design | | Control Algorithm |


---

## 📥 **Download Project**
```
git clone https://github.com/your-username/Battery-Cooling-System-EV.git
```

---

## 📃 **License**
MIT License  

---
