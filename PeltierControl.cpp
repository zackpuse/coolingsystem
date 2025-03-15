//--------------------PeltierControl.cpp---------------//
#include <Arduino.h>
#include "PeltierControl.h"
#include "GlobalVariables.h"

void controlPeltier() {
  if (heatsinkTemp < FREEZE_TEMP_THRESHOLD) { // Anti-freeze cutoff
    digitalWrite(PELTIER_PIN, LOW); // Turn OFF Peltier
  } else if (inflowTemp > INFLOW_TEMP_THRESHOLD) {
    digitalWrite(PELTIER_PIN, HIGH); // Turn ON Peltier
  } else {
    digitalWrite(PELTIER_PIN, LOW);// Maintain OFF
  }
}

