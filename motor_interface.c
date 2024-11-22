#include <stdio.h>
#include <stdbool.h>

typedef struct motor_interface
{
    bool forward;
    bool left;
    bool right;
    bool backward;
}Motor_Inf;

int move_forward(bool enable_or_disable) {
    if(enable_or_disable) {
        printf("move forward\n");
        return 1;
    }
    return 0;
}

int turn_left(int trigger, int tick) {
    int time = tick;
    if(trigger) {
        printf("turn left\n");
        for(int i=0; i<time; i++) {
            tick--;
        }
        trigger = false;
        return 1;
    }
    return 0;
}

int turn_right(int trigger, int tick) {
    int time = tick;
    if(trigger) {
        printf("turn right\n");
        for(int i=0; i<time; i++) {
            tick--;
        }
        trigger = false;
        return 1;
    }
    return 0;
}

int move_backward(bool enable_or_disable) {
    if(enable_or_disable) {
        printf("move backward\n");
        return 1;
    }
    return 0;
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
        move_forward(enable);
    }
    else if(motor.forward && !motor.left) { //F&&!L이 막힌 상황 -> turn left
        move_forward(disable);
        turn_left(trigger, tick);
        move_forward(enable);
    }
    else if(motor.forward && motor.left && !motor.right) { //F&&L&&!R이 막힌 상황 -> turn right
        move_forward(disable);
        turn_right(trigger, tick);
        move_forward(enable);
    }
    else if(motor.forward && motor.left && motor.right) { //F&&L&&R이 막힌 상황 -> move backward
        move_forward(disable);
        move_backward(enable);
    }
}