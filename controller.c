#include <stdio.h>
#include "header.h"

typedef struct RVC {
    Obs_Loc obsLoc;
    Dust_Ex dustEx;
}RVC;

typedef struct OBSTACLE_LOCATION {
    int forward_obstacle;
    int left_obstacle;
    int right_obstacle;
}Obs_Loc;

typedef struct DUST_EXISTENCE {
    int dust_existence;
}Dust_Ex;


void controller() {
    printf("hello rvc");

}