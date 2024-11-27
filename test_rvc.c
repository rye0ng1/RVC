#include <CUnit/CUnit.h>
#include <CUnit/Basic.h>
#include "header.h"

// Mock functions for the interfaces used by the controller
void mock_motor_interface(bool obstacle_location[3]) {
    printf("Motor Interface called with obstacle location: Front=%d, Left=%d, Right=%d\n",
           obstacle_location[0], obstacle_location[1], obstacle_location[2]);
}

void mock_cleaner_interface(bool dust_existence, bool not_move_forward) {
    printf("Cleaner Interface called with dust existence: %d, Not move forward: %d\n",
           dust_existence, not_move_forward);
}

// Test 1: All sensors clear, no dust
void test_controller_case_01() {
    set_front_sensor(0);
    set_left_sensor(0);
    set_right_sensor(0);
    set_dust_sensor(0);
    controller(0, 0, 0, 0);
    CU_ASSERT_FALSE(is_front_obstacle());
    CU_ASSERT_FALSE(is_left_obstacle());
    CU_ASSERT_FALSE(is_right_obstacle());
    CU_ASSERT_FALSE(is_dust_detected());
}

// Test 2: All sensors clear, dust detected
void test_controller_case_02() {
    set_front_sensor(0);
    set_left_sensor(0);
    set_right_sensor(0);
    set_dust_sensor(1);
    controller(0, 0, 0, 1);
    CU_ASSERT_FALSE(is_front_obstacle());
    CU_ASSERT_FALSE(is_left_obstacle());
    CU_ASSERT_FALSE(is_right_obstacle());
    CU_ASSERT_TRUE(is_dust_detected());
}

// Test 3: Right obstacle only
void test_controller_case_03() {
    set_front_sensor(0);
    set_left_sensor(0);
    set_right_sensor(1);
    set_dust_sensor(0);
    controller(0, 0, 1, 0);
    CU_ASSERT_FALSE(is_front_obstacle());
    CU_ASSERT_FALSE(is_left_obstacle());
    CU_ASSERT_TRUE(is_right_obstacle());
}

// Test 4: Front obstacle only
void test_controller_case_04() {
    set_front_sensor(1);
    set_left_sensor(0);
    set_right_sensor(0);
    set_dust_sensor(0);
    controller(1, 0, 0, 0);
    CU_ASSERT_TRUE(is_front_obstacle());
    CU_ASSERT_FALSE(is_left_obstacle());
    CU_ASSERT_FALSE(is_right_obstacle());
}

// Test 5: All obstacles present, no dust
void test_controller_case_05() {
    set_front_sensor(1);
    set_left_sensor(1);
    set_right_sensor(1);
    set_dust_sensor(0);
    controller(1, 1, 1, 0);
    CU_ASSERT_TRUE(is_front_obstacle());
    CU_ASSERT_TRUE(is_left_obstacle());
    CU_ASSERT_TRUE(is_right_obstacle());
}

// Test 6: All obstacles present, dust detected
void test_controller_case_06() {
    set_front_sensor(1);
    set_left_sensor(1);
    set_right_sensor(1);
    set_dust_sensor(1);
    controller(1, 1, 1, 1);
    CU_ASSERT_TRUE(is_front_obstacle());
    CU_ASSERT_TRUE(is_left_obstacle());
    CU_ASSERT_TRUE(is_right_obstacle());
    CU_ASSERT_TRUE(is_dust_detected());
}

// Test 7: Left obstacle only
void test_controller_case_07() {
    set_front_sensor(0);
    set_left_sensor(1);
    set_right_sensor(0);
    set_dust_sensor(0);
    controller(0, 1, 0, 0);
    CU_ASSERT_FALSE(is_front_obstacle());
    CU_ASSERT_TRUE(is_left_obstacle());
    CU_ASSERT_FALSE(is_right_obstacle());
}

// Test 8: Front and right obstacles
void test_controller_case_08() {
    set_front_sensor(1);
    set_left_sensor(0);
    set_right_sensor(1);
    set_dust_sensor(0);
    controller(1, 0, 1, 0);
    CU_ASSERT_TRUE(is_front_obstacle());
    CU_ASSERT_FALSE(is_left_obstacle());
    CU_ASSERT_TRUE(is_right_obstacle());
}

// Test 9: Front and left obstacles
void test_controller_case_09() {
    set_front_sensor(1);
    set_left_sensor(1);
    set_right_sensor(0);
    set_dust_sensor(0);
    controller(1, 1, 0, 0);
    CU_ASSERT_TRUE(is_front_obstacle());
    CU_ASSERT_TRUE(is_left_obstacle());
    CU_ASSERT_FALSE(is_right_obstacle());
}

// Test 10: Only dust detected
void test_controller_case_10() {
    set_front_sensor(0);
    set_left_sensor(0);
    set_right_sensor(0);
    set_dust_sensor(1);
    controller(0, 0, 0, 1);
    CU_ASSERT_TRUE(is_dust_detected());
}

// Test 11: Front and dust detected
void test_controller_case_11() {
    set_front_sensor(1);
    set_left_sensor(0);
    set_right_sensor(0);
    set_dust_sensor(1);
    controller(1, 0, 0, 1);
    CU_ASSERT_TRUE(is_front_obstacle());
    CU_ASSERT_TRUE(is_dust_detected());
}

// Test 12: Left and dust detected
void test_controller_case_12() {
    set_front_sensor(0);
    set_left_sensor(1);
    set_right_sensor(0);
    set_dust_sensor(1);
    controller(0, 1, 0, 1);
    CU_ASSERT_TRUE(is_left_obstacle());
    CU_ASSERT_TRUE(is_dust_detected());
}

// Test 13: Right and dust detected
void test_controller_case_13() {
    set_front_sensor(0);
    set_left_sensor(0);
    set_right_sensor(1);
    set_dust_sensor(1);
    controller(0, 0, 1, 1);
    CU_ASSERT_TRUE(is_right_obstacle());
    CU_ASSERT_TRUE(is_dust_detected());
}

// Test 14: Front and left obstacles, dust detected
void test_controller_case_14() {
    set_front_sensor(1);
    set_left_sensor(1);
    set_right_sensor(0);
    set_dust_sensor(1);
    controller(1, 1, 0, 1);
    CU_ASSERT_TRUE(is_front_obstacle());
    CU_ASSERT_TRUE(is_left_obstacle());
    CU_ASSERT_TRUE(is_dust_detected());
}

// Test 15: Front and right obstacles, dust detected
void test_controller_case_15() {
    set_front_sensor(1);
    set_left_sensor(0);
    set_right_sensor(1);
    set_dust_sensor(1);
    controller(1, 0, 1, 1);
    CU_ASSERT_TRUE(is_front_obstacle());
    CU_ASSERT_TRUE(is_right_obstacle());
    CU_ASSERT_TRUE(is_dust_detected());
}

// Test 16: All obstacles and dust detected
void test_controller_case_16() {
    set_front_sensor(1);
    set_left_sensor(1);
    set_right_sensor(1);
    set_dust_sensor(1);
    controller(1, 1, 1, 1);
    CU_ASSERT_TRUE(is_front_obstacle());
    CU_ASSERT_TRUE(is_left_obstacle());
    CU_ASSERT_TRUE(is_right_obstacle());
    CU_ASSERT_TRUE(is_dust_detected());
}

// Test case 17: Multiple calls in one test
void test_controller_case_17() {
    printf("TEST CASE 17\n");
    controller(0, 0, 0, 1);  // Step 1
    controller(1, 0, 1, 1);  // Step 2 
    CU_ASSERT_TRUE(is_dust_detected());  // Check if dust was detected in first call
    CU_ASSERT_TRUE(is_front_obstacle);  // Check if front obstacle was detected in step 2
}

// Test case 18: Multiple calls in one test
void test_controller_case_18() {
    printf("TEST CASE 18\n");
    controller(0, 1, 0, 1);  // Step 1
    controller(1, 0, 1, 0);  // Step 2
    CU_ASSERT_TRUE(is_left_obstacle());  // Check if left obstacle was detected in step 1
    CU_ASSERT_FALSE(is_right_obstacle());  // Check if right obstacle is detected in step 2
}

// Test case 19: Multiple calls in one test
void test_controller_case_19() {
    printf("TEST CASE 19\n");
    controller(1, 0, 0, 1);  // Step 1
    controller(1, 1, 0, 0);  // Step 2
    CU_ASSERT_TRUE(is_front_obstacle());  // Check front obstacle in step 1
    CU_ASSERT_TRUE(is_left_obstacle());  // Check left obstacle in step 2
}

// Test case 20: Multiple calls in one test
void test_controller_case_20() {
    printf("TEST CASE 20\n");
    controller(0, 0, 1, 0);  // Step 1
    controller(1, 1, 1, 1);  // Step 2
    CU_ASSERT_TRUE(is_right_obstacle());  // Check right obstacle in step 1
    CU_ASSERT_TRUE(is_front_obstacle());  // Check front obstacle in step 2
    CU_ASSERT_TRUE(is_left_obstacle());  // Check left obstacle in step 2
    CU_ASSERT_TRUE(is_dust_detected());  // Check dust in step 2
}

void (*test_functions[20])() = {
    test_controller_case_01, test_controller_case_02, test_controller_case_03,
    test_controller_case_04, test_controller_case_05, test_controller_case_06,
    test_controller_case_07, test_controller_case_08, test_controller_case_09,
    test_controller_case_10, test_controller_case_11, test_controller_case_12,
    test_controller_case_13, test_controller_case_14, test_controller_case_15,
    test_controller_case_16, test_controller_case_17, test_controller_case_18,
    test_controller_case_19, test_controller_case_20
};

// Main function to run tests
int main() {
    // Initialize CUnit test registry
    if (CUE_SUCCESS != CU_initialize_registry()) {
        return CU_get_error();
    }

    // Create a test suite
    CU_pSuite suite = CU_add_suite("RVC Controller Test Suite", NULL, NULL);
    if (suite == NULL) {
        CU_cleanup_registry();
        return CU_get_error();
    }

    // Automatically add all test cases
    for (int i = 0; i < 20; i++) {
        char test_name[50];
        sprintf(test_name, "Test Case %02d", i + 1);
        CU_add_test(suite, test_name, test_functions[i]);
    }

    // Run tests using the Basic interface
    CU_basic_set_mode(CU_BRM_VERBOSE);
    CU_basic_run_tests();

    // Cleanup CUnit registry
    CU_cleanup_registry();
    return CU_get_error();
}
