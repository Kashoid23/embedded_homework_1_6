#include <Arduino.h>

#include "config.h"
#include "sensor.h"

void setup() {
    Serial.begin(Config::kBaud);
    Sensor::begin();

    Serial.println("LDR voltage measurement - ESP32-S3");
    Serial.println("raw:\tcalc_mV:\tmeasured_mV:\terror_pct:");
}

void loop() {
    static uint32_t lastSampleMs = 0;

    const uint32_t nowMs = millis();
    if (nowMs - lastSampleMs < Config::kSamplePeriodMs) {
        return;
    }

    lastSampleMs = nowMs;

    const SensorReading reading = Sensor::sample();

    Serial.printf(
        "RAW:%u\tCalculated mV:%.1f\tMeasured mV:%lu\tError:",
        static_cast<unsigned>(reading.raw),
        reading.calculatedVoltage * 1000.0f,
        static_cast<unsigned long>(reading.millivolts)
    );

    if (isnan(reading.errorPercent)) {
        Serial.println("N/A");
    } else {
        Serial.printf("%.2f%%\n", reading.errorPercent);
    }
}
