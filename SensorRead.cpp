//--------------------SensorRead.cpp---------------//
#include "SensorRead.h"
#include <DHT.h>
#include <OneWire.h>
#include <DallasTemperature.h>
#include <Arduino.h>
#include "GlobalVariables.h"

#define DHT_PIN 2
#define DS18B20_PIN 3

DHT dht(DHT_PIN, DHT22);
OneWire oneWire(DS18B20_PIN);
DallasTemperature sensors(&oneWire);



void initSensors() {
  dht.begin();
  sensors.begin();
}

void readSensors() {
  // DHT22 Reading
  inflowTemp = dht.readTemperature();
  humidity = dht.readHumidity();

  // DS18B20 Reading
  sensors.requestTemperatures();
  heatsinkTemp = sensors.getTempCByIndex(0);
}

