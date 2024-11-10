#include <stdint.h>  // or <inttypes.h>

#ifndef SIGNALSTATE_H
#define SIGNALSTATE_H

#define MAX_SIGNALS 10

struct SignalState {
    int16_t pin;             // The pin associated with the signal (determines the color)
    int16_t id;
    bool isFlashing;        // Whether the signal is flashing
    bool isOn;               // Whether the signal is currently on
    unsigned long lastFlashTime;  // Last time the signal changed state
    unsigned long flashInterval;  // Interval at which the signal flashes (in milliseconds)
};

#endif // SIGNALSTATE_H
