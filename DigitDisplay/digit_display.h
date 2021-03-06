#pragma once

#include <atomic>
#include <cstdint>
#include <thread>

#include <I2CControl/i2c_control.h>
#include <GPIO/gpio.h>

namespace earthquake_detection_unit {

class DigitDisplay {
public:
    DigitDisplay();
    ~DigitDisplay();

    // Sets the digit to be displayed.
    void SetDigit(unsigned int digit);
    // Returns the currently displaying digit.
    inline unsigned int GetCurrentDigit() { return current_digit; }
    // Quickly flashes the display 5 times.
    void FlashDisplay();

private:

    // Value which we are currently displaying.
    unsigned int current_digit;
    // GPIO objects corresponding to the digit display.
    GPIO left_digit_gpio;
    GPIO right_digit_gpio;

    // I2C manager for the digit display.
    I2CControl *i2c_c;
};

} // earthquake_detection_unit
