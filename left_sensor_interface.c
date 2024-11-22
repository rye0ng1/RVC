#include "header.h"
#include <stdbool.h>

// Left sensor state
static bool left_obstacle = false;

// Set the left sensor state
void set_left_sensor(bool state) {
    left_obstacle = state;
}

// Get the left sensor state
bool is_left_obstacle() {
    return left_obstacle;
}
