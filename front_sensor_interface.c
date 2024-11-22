#include "header.h"
#include <stdbool.h>

// Front sensor state
static bool front_obstacle = false;

// Set the front sensor state
void set_front_sensor(bool state) {
    front_obstacle = state;
}

// Get the front sensor state
bool is_front_obstacle() {
    return front_obstacle;
}
