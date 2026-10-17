#pragma once

#include <Arduino.h>

namespace Config {
    constexpr uint32_t kBaud = 115200; // Швидкість Serial Monitor
    constexpr uint32_t kSamplePeriodMs = 100; // Інтервал між вимірюваннями
    constexpr uint32_t kResolution = 12; // Роздільна здатність АЦП

    constexpr uint8_t kLdrPin = 4; // GPIO4

    constexpr uint16_t kAdcMax = 4095; // Максимальне значення 12-бітного АЦП
    constexpr float kReferenceVoltage = 3.1f; // Напруга для формули за умовою завдання
}
