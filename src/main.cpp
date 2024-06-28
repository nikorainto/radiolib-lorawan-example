#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BME280.h>
#include "config.h"

Adafruit_BME280 bme;

SX1262 *radio = nullptr;
LoRaWANNode *node = nullptr;

void setup()
{
  Wire.begin();

  if (!bme.begin(0x76))
  {
    while (1)
      ;
  }

  radio = new SX1262(new Module(PA4, PA0, PC4, PC5));

  node = new LoRaWANNode(radio, &Region, subBand);

  radio->begin();
  radio->setRfSwitchPins(PA3, PA2);

  node->beginOTAA(joinEUI, devEUI, nwkKey, appKey);
  node->activateOTAA();
}

void loop()
{
  float temperature = bme.readTemperature();
  float pressure = bme.readPressure() / 100.0F;
  float humidity = bme.readHumidity();

  delay(2000);
}

// Clean up dynamically allocated memory
void cleanup()
{
  delete node;
  delete radio;
}
