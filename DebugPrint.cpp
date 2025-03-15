//--------------------DebugPrint.cpp---------------//
#include <Arduino.h>
#include "GlobalVariables.h"

void printDebug() {
  Serial.print("Inflow Temp: ");
  Serial.print(inflowTemp);
  Serial.print(" °C, Heatsink Temp: ");
  Serial.print(heatsinkTemp);
  Serial.print(" °C, External Fan RPM: ");
  Serial.println(rpm);
} 
