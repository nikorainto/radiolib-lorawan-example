#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BME280.h>
#include "config.h"

// -- This is not working. Stuck in Reset_Handler: / Infinite_Loop:
Adafruit_BME280 bme;

float temperature, pressure, altitude, humidity;

void setup()
{
  Wire.begin();
  bme.begin(0x76);

  radio.begin();
  radio.setRfSwitchPins(PA3, PA2);

  node.beginOTAA(joinEUI, devEUI, nwkKey, appKey);
  int16_t state = node.activateOTAA();
}

void loop()
{
  temperature = bme.readTemperature();
  pressure = bme.readPressure() / 100.0F;
  humidity = bme.readHumidity();

  delay(2000);
}

// -- This is able to show values from BME280
/*
Adafruit_BME280 bme;

float temperature, pressure, altitude, humidity;

void setup()
{
  Wire.begin();
  bme.begin(0x76);

  radio.begin();
  radio.setRfSwitchPins(PA3, PA2);

  node.beginOTAA(joinEUI, devEUI, nwkKey, appKey);
}

void loop()
{
  temperature = bme.readTemperature();
  pressure = bme.readPressure() / 100.0F;
  humidity = bme.readHumidity();

  delay(2000);
}
*/

// -- This is able to connect to LoRaWAN
/*
Adafruit_BME280 bme;

float temperature, pressure, altitude, humidity;

void setup()
{
  radio.begin();
  radio.setRfSwitchPins(PA3, PA2);

  node.beginOTAA(joinEUI, devEUI, nwkKey, appKey);
  int16_t state = node.activateOTAA();
}

void loop()
{
  delay(2000);
}
*/