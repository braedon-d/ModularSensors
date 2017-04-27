/*
 * MaximDS18.h
 * This file is part of the EnviroDIY modular sensors library for Arduino
 *
 * Initial library developement done by Sara Damiano (sdamiano@stroudcenter.org).
 *
 * This file is for the Maxim DS18B20 Temperature sensor.
 * It is dependent on Dallas Temperature library, which itself is dependent on
 * the OneWire library.
 *
 * The resolution of the temperature sensor is user-configurable to
 * 9, 10, 11, or 12 bits, corresponding to increments of
 * 0.5°C, 0.25°C, 0.125°C, and 0.0625°C, respectively.
 * The default resolution at power-up is 12-bit.
*/

#ifndef MaximDS18_h
#define MaximDS18_h

#include <OneWire.h>
#include <DallasTemperature.h>
#include "SensorBase.h"
#include "VariableBase.h"

#define DS18_NUM_MEASUREMENTS 1
#define DS18_TEMP_VAR_NUM 0
#define DS18_TEMP_RESOLUTION 4

// The main class for the DS18
class MaximDS18 : public Sensor
{
public:
    MaximDS18(DeviceAddress OneWireAddress, int powerPin, int dataPin);
    MaximDS18(int powerPin, int dataPin);

    bool update(void) override;

private:
    uint8_t* _OneWireAddress;
    bool _addressKnown;
};


// The class for the Range Variable
class MaximDS18_Temp : public Variable
{
public:
    MaximDS18_Temp(Sensor *parentSense) :
      Variable(parentSense, DS18_TEMP_VAR_NUM,
               F("temperature"), F("degreeCelsius"),
               DS18_TEMP_RESOLUTION, F("DS18Temp"))
    {}
};

#endif
