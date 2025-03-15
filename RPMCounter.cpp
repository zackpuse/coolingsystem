//--------------------RPMControl.cpp---------------//
#include <Arduino.h>
#include "RPMCounter.h"
#include "GlobalVariables.h"

volatile int pulseCount = 0;
unsigned long lastMillis = 0;

void countPulse() {
  pulseCount++;
}

void calculateRPM() {
  unsigned long currentMillis = millis();
  if (currentMillis - lastMillis >= 1000) { // Update RPM every second
    noInterrupts();
    int currentPulses = pulseCount;
    pulseCount = 0;
    interrupts();
    rpm = currentPulses * 30; // 60 seconds / 2 pulses per revolution
    lastMillis = currentMillis;
  }
}
