#ifndef _CONFIG_H
#define _CONFIG_H

#include <RadioLib.h>

// how often to send an uplink - consider legal & FUP constraints - see notes
const uint32_t uplinkIntervalSeconds = 5UL * 60UL; // minutes x seconds

// joinEUI - previous versions of LoRaWAN called this AppEUI
// for development purposes you can use all zeros - see wiki for details
#define RADIOLIB_LORAWAN_JOIN_EUI 0x0000000000000000

// the Device EUI & two keys can be generated on the TTN console
#ifndef RADIOLIB_LORAWAN_DEV_EUI // Replace with your Device EUI
#define RADIOLIB_LORAWAN_DEV_EUI 0x5E32415EA1686460
#endif
#ifndef RADIOLIB_LORAWAN_APP_KEY // Replace with your App Key
#define RADIOLIB_LORAWAN_APP_KEY 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
#endif
#ifndef RADIOLIB_LORAWAN_NWK_KEY // Put your Nwk Key here
#define RADIOLIB_LORAWAN_NWK_KEY 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
#endif

// for the curious, the #ifndef blocks allow for automated testing &/or you can
// put your EUI & keys in to your platformio.ini - see wiki for more tips

// regional choices: EU868, US915, AU915, AS923, IN865, KR920, CN780, CN500
const LoRaWANBand_t Region = EU868;
const uint8_t subBand = 0; // For US915, change this to 2, otherwise leave on 0

// ============================================================================
// Below is to support the sketch - only make changes if the notes say so ...

// Auto select MCU <-> radio connections
// If you get an error message when compiling, it may be that the
// pinmap could not be determined - see the notes for more info

// SX1262  pin order: Module(NSS/CS, DIO1, RESET, BUSY);
SX1262 radio = new Module(PA4, PA0, PC4, PC5);

// copy over the EUI's & keys in to the something that will not compile if incorrectly formatted
uint64_t joinEUI = RADIOLIB_LORAWAN_JOIN_EUI;
uint64_t devEUI = RADIOLIB_LORAWAN_DEV_EUI;
uint8_t appKey[] = {RADIOLIB_LORAWAN_APP_KEY};
uint8_t nwkKey[] = {RADIOLIB_LORAWAN_NWK_KEY};

// create the LoRaWAN node
LoRaWANNode node(&radio, &Region, subBand);

#endif