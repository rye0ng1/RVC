#include <stdbool.h>

#ifdef TEST_ENV
void mock_output(const char *format, ...);
#define printf mock_output
#endif
 

//controller.c
void controller(int front_state, int left_state, int right_state, int dust_detected);

//motor_interface.c
void motor_interface(bool obastacle_location[3]);
char* move_forward(bool enable_or_disable);
char* turn_left(int trigger, int tick);
char* turn_right(int trigger, int tick);
char* move_backward(bool enable_or_disable);

//cleaner_interface.c
void cleaner_interface(bool dust_existence, bool move_forward);
char* turn_on(int cleaner_command);
char* power_up(int cleaner_command, int tick);

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

