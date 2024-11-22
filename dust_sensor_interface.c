#include "header.h"
#include <stdbool.h>

// Dust sensor state
static bool dust_detected = false;

// Set the dust sensor state
void set_dust_sensor(bool state) {
    dust_detected = state;
}

// Get the dust sensor state
bool is_dust_detected() {
    return dust_detected;
}
