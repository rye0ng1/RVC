#include "header.h"
#include <stdbool.h>

// Right sensor state
static bool right_obstacle = false;

// Set the right sensor state
void set_right_sensor(bool state) {
    right_obstacle = state;
}

// Get the right sensor state
bool is_right_obstacle() {
    return right_obstacle;
}
