#include "config.h"

const uint8_t dataRate = 0; // SF12

void setup()
{
  if (radio.begin() != RADIOLIB_ERR_NONE)
  {
    while (true)
      ;
  }

  radio.setRfSwitchPins(PA3, PA2);
  node.beginOTAA(joinEUI, devEUI, nwkKey, appKey);

  int16_t state = node.activateOTAA(dataRate);

  if (state != RADIOLIB_ERR_NONE)
  {
    while (true)
      ;
  }

  node.setADR(false);
  node.setDatarate(dataRate);
}

void loop()
{
  uint8_t battLevel = 146;

  node.setDeviceStatus(battLevel);

  uint8_t value1 = radio.random(100);
  uint16_t value2 = radio.random(2000);

  uint8_t uplinkPayload[] = {value1, highByte(value2), lowByte(value2)};

  const uint8_t Port = 64;

  int16_t state = node.sendReceive(uplinkPayload, sizeof(uplinkPayload), Port);

  if (state != RADIOLIB_LORAWAN_NO_DOWNLINK && state != RADIOLIB_ERR_NONE)
  {
    while (true)
      ;
  }

  delay(uplinkIntervalSeconds * 1000UL);
}
