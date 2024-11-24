#include <stdio.h>
#include <stdbool.h>
#include "header.h"

int cleaner_command_off = 0;
int cleaner_command_on = 1;
int cleaner_command_up = 2;

char* turn_on(int cleaner_command) {
    if(cleaner_command == 1) {
        return "turn on\n";
    }
    return "turn off\n";
}

char* power_up(int cleaner_command, int tick) {
    int time = tick;
    if(cleaner_command == 2) {
        for(int i=0; i<time; i++) {
            tick--;
        }
        return "power up\n";
    }
    else {
        return "failed power up\n";
    }
}

void cleaner_interface(bool dust_existence, bool not_move_forward) {
    int tick = 5;
    if(dust_existence && !not_move_forward) {
        printf("%s", power_up(cleaner_command_up, tick));
        dust_existence = false;
    }
    else if(!dust_existence && !not_move_forward) {
        printf("%s", turn_on(cleaner_command_on));
    }
    else if(not_move_forward) {
        printf("%s", turn_on(cleaner_command_off));
    }
}