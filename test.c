#include <CUnit/CUnit.h>
#include <CUnit/Basic.h>
#include "header.h"
#include <stdio.h>
#include <string.h>
#include <stdarg.h>

// Mocking output for validation
static char output_buffer[1024];
static int output_index = 0;

void mock_output(const char *format, ...) {
    va_list args;
    va_start(args, format);
    output_index += vsnprintf(output_buffer + output_index, sizeof(output_buffer) - output_index, format, args);
    va_end(args);
}

void reset_output() {
    output_index = 0;
    output_buffer[0] = '\0';
}

// Define debug output to use original printf via vfprintf
void debug_output(const char *format, ...) {
    va_list args;
    va_start(args, format);
    vfprintf(stdout, format, args);  // Send output directly to the terminal
    va_end(args);
}

// !!test case 작성!!
void test_case_1() {
    reset_output();

    // controller(1, 0, 0, 0) 실행
    controller(1, 0, 0, 0);

    // 예상 결과 출력
    const char *expected_output = 
        "turn off\n"
        "disable move forward\n"
        "trigger turn left\n"
        "enable move forward\n";

    // 실제 결과와 예상 결과 비교
    CU_ASSERT_STRING_EQUAL(output_buffer, expected_output);
}








int main() {
    // Initialize CUnit test registry
    if (CU_initialize_registry() != CUE_SUCCESS) {
        return CU_get_error();
    }

    // Add a suite for the test
    CU_pSuite suite = CU_add_suite("Controller Test Suite", NULL, NULL);
    if (!suite) {
        CU_cleanup_registry();
        return CU_get_error();
    }

    // Add test case to the suite
    if (CU_add_test(suite, "Test Case 1: controller(1, 0, 0, 0)", test_case_1) == NULL) {
        CU_cleanup_registry();
        return CU_get_error();
    }

    // Run all tests
    CU_basic_set_mode(CU_BRM_VERBOSE);
    CU_basic_run_tests();

    // Cleanup registry
    CU_cleanup_registry();
    return 0;
}