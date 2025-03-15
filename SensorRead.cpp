//--------------------SensorRead.cpp---------------//
#include "SensorRead.h"
#include "GlobalVariables.h"

#define DHT_TYPE DHT22

DHT dht(DHT_PIN, DHT_TYPE);

void initSensors() {
  dht.begin();
}

void readSensors() {
  // Read DHT22 (inflow temperature and humidity)
  inflowTemp = dht.readTemperature();
  humidity = dht.readHumidity();

  // Simulate heatsink temperature (replace with actual sensor reading)
  heatsinkTemp = inflowTemp - 5.0; // Example: heatsink is 5°C cooler
}