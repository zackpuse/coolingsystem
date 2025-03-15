//--------------------DebugPrint.cpp---------------//
#include <Arduino.h>
#include "GlobalVariables.h"

void printDebug() {
  Serial.print("Inflow Temp: ");
  Serial.print(inflowTemp);
  Serial.print(", Humidity: ");
  Serial.print(humidity);
  Serial.print(", Heatsink Temp: ");
  Serial.print(heatsinkTemp);
  Serial.print(", RPM: ");
  Serial.println(rpm);
}

