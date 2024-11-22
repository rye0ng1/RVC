#include <stdbool.h>

//controller.c
void controller();

//motor_interface.c
void motor_interface(bool obastacle_location[3]);
int move_forward(bool enable_or_disable);
int turn_left(int trigger, int tick);
int turn_right(int trigger, int tick);
int move_backward(bool enable_or_disable);

//cleaner_interface.c
void cleaner_interface(bool dust_existence, bool move_forward);
bool turn_on(int cleaner_command);
void power_up(int cleaner_command, int tick);

//front_sensor_interface.c
void set_front_sensor(bool state);
bool is_front_obstacle();

//left_sensor_interface.c
void set_left_sensor(bool state);
bool is_left_obstacle();

//right_sensor_interface.c
void set_right_sensor(bool state);
bool is_right_obstacle();

//dust_sensor_interface.c
void set_dust_sensor(bool state);
bool is_dust_detected();

