#include <stdio.h>
#include <stdbool.h>

int cleaner_command_off = 0;
int cleaner_command_on = 1;
int cleaner_command_up = 2;

bool turn_on(int cleaner_command) {
    if(cleaner_command == 1) {
        printf("turn on\n");
        return true;
    }
    printf("turn off\n");
    return false;
}

void power_up(int cleaner_command, int tick) {
    int time = tick;
    if(cleaner_command == 2) {
        printf("power up\n");
        for(int i=0; i<time; i++) {
            tick--;
        }
        return;
    }
}

void cleaner_interface(bool dust_existence, bool not_move_forward) {
    int tick = 5;
    if(dust_existence && !not_move_forward) {
        power_up(cleaner_command_up, tick);
        dust_existence = false;
    }
    else if(!dust_existence && !not_move_forward) {
        turn_on(cleaner_command_on);
    }
    else if(not_move_forward) {
        turn_on(cleaner_command_off);
    }
}