//--------------------FanControl.cpp---------------//
#include "FanControl.h"
#include "SensorRead.h"
#include "RPMCounter.h"
#include <Arduino.h>
#include "GlobalVariables.h"

#define COLD_FAN_PIN 6  // Cold Side Fan
#define HOT_FAN_PIN 9   // Hot Side Fan with RPM Feedback

void initFanControl() {
  pinMode(COLD_FAN_PIN, OUTPUT);
  pinMode(HOT_FAN_PIN, OUTPUT);
}

void controlFan() {
  // Increase Cold Side Fan Speed if Humidity > 60% to prevent condensation
  if (humidity > 60) {
    analogWrite(COLD_FAN_PIN, 200); // Faster Cold Side Fan
  } else {
    analogWrite(COLD_FAN_PIN, 120); // Normal Speed
  }

  // Adjust Hot Side Fan Based on RPM Feedback
  if (rpm > 3000) {
    analogWrite(HOT_FAN_PIN, 80); // Reduce Fan Speed (High Car Speed)
  } else {
    analogWrite(HOT_FAN_PIN, 180); // Increase Fan Speed (Car Stationary)
  }
}
