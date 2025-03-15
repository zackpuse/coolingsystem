//--------------------RPMControl.cpp---------------//
#include <Arduino.h>
#include "RPMCounter.h"
#include "GlobalVariables.h"

#define RPM_PIN 2
volatile int pulseCount = 0;
unsigned long lastMillis = 0;


void countPulse() {
  pulseCount++;
}

void calculateRPM() {
  unsigned long currentMillis = millis();
  if (currentMillis - lastMillis >= 1000) {
    noInterrupts();
    int currentPulses = pulseCount;
    pulseCount = 0;
    interrupts();
    rpm = currentPulses * 30; // 60/2 = 30
    lastMillis = currentMillis;
  }
}