#include <Arduino.h>
#include <math.h>

#include "config.h"
#include "sensor.h"

namespace {
    float calculateVoltage(uint16_t raw) {
        return (static_cast<float>(raw) / Config::kAdcMax) * Config::kReferenceVoltage;
    }

    float calculateError(float calculated, float measured) {
        if (measured <= 0.0f) {
            return NAN;
        }

        return fabsf(calculated - measured) / measured * 100.0f;
    }
}

namespace Sensor {

    void begin() {
        analogReadResolution(Config::kResolution);
        pinMode(Config::kLdrPin, INPUT);
    }

    SensorReading sample() {
        SensorReading reading{};

        reading.raw = analogRead(Config::kLdrPin);
        reading.calculatedVoltage = calculateVoltage(reading.raw);

        reading.millivolts = analogReadMilliVolts(Config::kLdrPin);

        reading.measuredVoltage = reading.millivolts / 1000.0f;

        reading.errorPercent = calculateError(reading.calculatedVoltage, reading.measuredVoltage);

        return reading;
    }

}
