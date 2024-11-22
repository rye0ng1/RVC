#include <stdbool.h>

//controller.c
void controller();

//motor_interface.c
void motor_interface(int obastacle_location);
void move_forward(int enable_or_disable);
void turn_left(int trigger, int tick);
void turn_right(int trigger, int tick);
void move_backward(int enable_or_disable);

//cleaner_interface.c
void cleaner_interface(int dust_existence);
void turn_on(int cleaner_command);
void power_up(int cleaner_command);

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

