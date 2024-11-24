#include <stdio.h>
#include "header.h"

int main() {
    int front_state;
    int left_state;
    int right_state;
    int dust_detected;

    controller(front_state, left_state, right_state, dust_detected);

    // controller();

    return 0;
}