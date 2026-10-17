#pragma once

#include <Arduino.h>

struct SensorReading {
    uint16_t raw; // початковий цифровий результат analogRead()
    uint32_t millivolts; // результат analogReadMilliVolts() у мілівольтах
    float calculatedVoltage; // напруга, розрахована з RAW
    float measuredVoltage; // виміряна напруга у вольтах
    float errorPercent; // відносна похибка у відсотках
};

namespace Sensor {
    void begin(); // налаштовує датчик
    SensorReading sample(); // виконує вимірювання та повертає структуру SensorReading
}
