#include <stdio.h>
#include <stdbool.h>
#include "header.h"

typedef struct OBSTACLE_LOCATION {
    bool forward_obstacle;
    bool left_obstacle;
    bool right_obstacle;
}Obs_Loc;

typedef struct DUST_EXISTENCE {
    bool dust_existence;
}Dust_Ex;

typedef struct RVC {
    Obs_Loc obsLoc;
    Dust_Ex dustEx;
}RVC;

void controller(int front_state, int left_state, int right_state, int dust_detected) {
    RVC rvc;

    // int front_state;
    // int left_state;
    // int right_state;
    // int dust_detected;


    // //센서 input에 대한 테스트 케이스 추가해야 됨
    // printf("front sensor : ");
    // scanf("%d", &front_state);
    
    // printf("left sensor : ");
    // scanf("%d", &left_state);
    
    // printf("right sensor : ");
    // scanf("%d", &right_state);
    
    // printf("dust sensor : ");
    // scanf("%d", &dust_detected);

    set_front_sensor(front_state);
    set_left_sensor(left_state);
    set_right_sensor(right_state);
    set_dust_sensor(dust_detected);

    rvc.obsLoc.forward_obstacle = is_front_obstacle();
    rvc.obsLoc.left_obstacle = is_left_obstacle();
    rvc.obsLoc.right_obstacle = is_right_obstacle();
    bool obastacle_location[3] = {rvc.obsLoc.forward_obstacle, rvc.obsLoc.left_obstacle, rvc.obsLoc.right_obstacle};
    rvc.dustEx.dust_existence = is_dust_detected();

    
    cleaner_interface(rvc.dustEx.dust_existence, rvc.obsLoc.forward_obstacle);
    motor_interface(obastacle_location);

    return;
}