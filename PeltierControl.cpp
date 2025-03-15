//--------------------PeltierControl.cpp---------------//
#include "PeltierControl.h"
#include "SensorRead.h"
#include <Arduino.h>
#include "GlobalVariables.h"

#define PELTIER_PIN 5

void controlPeltier() {
  if (heatsinkTemp < 5.0) { // Freeze Warning
    digitalWrite(PELTIER_PIN, LOW); // Turn OFF Peltier
  } 
  else if (inflowTemp > 25.0) { 
    digitalWrite(PELTIER_PIN, HIGH); // Turn ON Peltier
  } 
  else {
    digitalWrite(PELTIER_PIN, LOW); // Maintain Condition
  }
}

