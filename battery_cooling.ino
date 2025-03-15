//--------------------main.ino---------------//
#include "GlobalVariables.h"
#include "SensorRead.h"
#include "FanControl.h"
#include "RPMCounter.h"
#include "PeltierControl.h"
#include "DebugPrint.h"


void setup() {
  Serial.begin(9600);    // Start Serial Monitor
  initSensors();         // Initialize sensors (DHT22 & DS18B20)
  initFanControl();      // Initialize fan pins
  attachInterrupt(digitalPinToInterrupt(RPM_PIN), countPulse, FALLING);  // Fan RPM Interrupt
}


void loop() {
  readSensors();     // Sensor Reading (DHT22 + DS18B20)
  controlPeltier(); // Peltier Anti-Freeze Logic
  controlFan();     // Cold & Hot Side Fan Control
  calculateRPM();   // Fan Speed Feedback
  printDebug();     // Debug Data
  delay(500);
}
