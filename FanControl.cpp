//--------------------FanControl.cpp---------------//
#include <Arduino.h>
#include "FanControl.h"
#include "GlobalVariables.h"

void initFanControl() {
  pinMode(INFLOW_FAN_PIN, OUTPUT);
  pinMode(OUTFLOW_FAN_PIN, OUTPUT);
  pinMode(EXTERNAL_FAN_PIN, OUTPUT);
  pinMode(EXTERNAL_FAN_RPM_PIN, INPUT);
}

void controlFan() {
  // Control Inflow Fan (3-pin, PWM)
  if (inflowTemp > INFLOW_TEMP_THRESHOLD) {
    analogWrite(INFLOW_FAN_PIN, INFLOW_FAN_HIGH);
  } else {
    analogWrite(INFLOW_FAN_PIN, INFLOW_FAN_LOW);
  }

  // Control Outflow Fan (3-pin, PWM)
  if (heatsinkTemp > HEATSINK_TEMP_THRESHOLD) {
    analogWrite(OUTFLOW_FAN_PIN, OUTFLOW_FAN_HIGH);
  } else {
    analogWrite(OUTFLOW_FAN_PIN, OUTFLOW_FAN_LOW);
  }

  // Control External Fan (4-pin, RPM feedback)
  if (rpm > EXTERNAL_FAN_RPM_THRESHOLD) {
    analogWrite(EXTERNAL_FAN_PIN, EXTERNAL_FAN_MEDIUM);
  } else {
    analogWrite(EXTERNAL_FAN_PIN, EXTERNAL_FAN_HIGH);
  }
}