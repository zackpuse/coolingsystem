//-------------------------GlobalVariables.h------------------//
#ifndef GLOBALVARIABLES_H
#define GLOBALVARIABLES_H

// Pins
#define RPM_PIN 2          // Interrupt-capable pin
#define DHT_PIN 3
#define DS18B20_PIN 4
#define COLD_FAN_PIN 6
#define HOT_FAN_PIN 9
#define PELTIER_PIN 5

// Thresholds
#define FREEZE_TEMP 5.0
#define OVERHEAT_TEMP 25.0
#define HIGH_HUMIDITY 60
#define RPM_THRESHOLD 3000
#define COLD_FAN_HIGH 200
#define COLD_FAN_NORMAL 120
#define HOT_FAN_LOW 80
#define HOT_FAN_HIGH 180

extern float inflowTemp, humidity, heatsinkTemp;
extern int rpm;

#endif