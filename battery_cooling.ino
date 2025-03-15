//--------------------main.ino---------------//
#include "GlobalVariables.h"
#include "SensorRead.h"
#include "FanControl.h"
#include "RPMCounter.h"
#include "PeltierControl.h"
#include "DebugPrint.h"

void setup() {
  Serial.begin(9600); // Start Serial Monitor
  initSensors();      // Initialize sensors
  initFanControl();   // Initialize fan control
  pinMode(PELTIER_PIN, OUTPUT); 
  attachInterrupt(digitalPinToInterrupt(EXTERNAL_FAN_RPM_PIN), countPulse, FALLING); // RPM interrupt
}

void loop() {
  readSensors();     // Read sensor data
  controlPeltier();  // Control Peltier device
  controlFan();      // Control fans
  calculateRPM();    // Calculate external fan RPM
  printDebug();      // Print debug data
  delay(500);        // Loop delay
}