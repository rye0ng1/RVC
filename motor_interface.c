#include <stdio.h>
#include <stdbool.h>
#include "header.h"

typedef struct motor_interface
{
    bool forward;
    bool left;
    bool right;
    bool backward;
}Motor_Inf;

char* move_forward(bool enable_or_disable) {
    if(enable_or_disable) {
        return "enable move forward\n";
    }
    return "disable move forward\n";
}

char* turn_left(int trigger, int tick) {
    int time = tick;
    if(trigger) {
        for(int i=0; i<time; i++) {
            tick--;
        }
        trigger = false;
        return "trigger turn left\n";
    }
    return "failed turn left\n";
}

char* turn_right(int trigger, int tick) {
    int time = tick;
    if(trigger) {
        for(int i=0; i<time; i++) {
            tick--;
        }
        trigger = false;
        return "trigger turn right\n";
    }
    return "failed turn right\n";
}

char* move_backward(bool enable_or_disable) {
    if(enable_or_disable) {
        return "enable move backward\n";
    }
    return "disable move backward\n";
}

void motor_interface(bool obastacle_location[3]) {
    Motor_Inf motor;
    const bool enable = true;
    const bool disable = false;
    bool trigger = true;
    int tick = 5;

    motor.forward = obastacle_location[0];
    motor.left = obastacle_location[1];
    motor.right = obastacle_location[2];

    if(!motor.forward) {
        printf("%s", move_forward(enable));
    }
    else if(motor.forward && !motor.left) { //F&&!L이 막힌 상황 -> turn left
        printf("%s", move_forward(disable));
        printf("%s", turn_left(trigger, tick));
        printf("%s", move_forward(enable));
    }
    else if(motor.forward && motor.left && !motor.right) { //F&&L&&!R이 막힌 상황 -> turn right
        printf("%s", move_forward(disable));
        printf("%s", turn_right(trigger, tick));
        printf("%s", move_forward(enable));
    }
    else if(motor.forward && motor.left && motor.right) { //F&&L&&R이 막힌 상황 -> move backward
        printf("%s", move_forward(disable));
        printf("%s", move_backward(enable));
    }
}