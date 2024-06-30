#include <Wire.h>
#include "config.h"

float temperature, pressure, humidity;

SX1262 *radio = nullptr;
LoRaWANNode *node = nullptr;

void setup()
{
  Wire.begin();

  radio = new SX1262(new Module(PA4, PA0, PC4, PC5));

  node = new LoRaWANNode(radio, &Region, subBand);

  radio->begin();
  radio->setRfSwitchPins(PA3, PA2);

  node->beginOTAA(joinEUI, devEUI, nwkKey, appKey);
  node->activateOTAA();
}

void loop()
{
  delay(500);
}

void cleanup()
{
  delete node;
  delete radio;
}
