#include <stdio.h>
#include <stdbool.h>
#include "header.h"

// Function to run predefined test cases
void run_predefined_tests() {
    printf("\nRunning predefined test cases...\n");

    int test_cases[16][4] = {
        {0, 0, 0, 0}, {0, 0, 0, 1}, {0, 0, 1, 0}, {0, 0, 1, 1},
        {0, 1, 0, 0}, {0, 1, 0, 1}, {0, 1, 1, 0}, {0, 1, 1, 1},
        {1, 0, 0, 0}, {1, 0, 0, 1}, {1, 0, 1, 0}, {1, 0, 1, 1},
        {1, 1, 0, 0}, {1, 1, 0, 1}, {1, 1, 1, 0}, {1, 1, 1, 1},
    };

    // Loop through each test case
    for (int i = 0; i < 16; i++) {
        printf("\nTEST CASE %02d:\n", i + 1);
        controller(test_cases[i][0], test_cases[i][1], test_cases[i][2], test_cases[i][3]);
    }

    //test_case_17
    printf("TEST CASE 17\n");
    controller(0,0,0,1);
    controller(1,0,1,1);
    //test_case_18
    printf("TEST CASE 18\n");
    controller(0,1,0,1);
    controller(1,0,1,0);
    //test_case_19
    printf("TEST CASE 19\n");
    controller(1,0,0,1);
    controller(1,1,0,0);
    //test_case_20
    printf("TEST CASE 20\n");
    controller(0,0,1,0);
    controller(1,1,1,1);
    //test_case_21
    printf("TEST CASE 21\n");
    controller(1,0,0,0);
    controller(0,1,1,0);
    //test_case_22
    printf("TEST CASE 22\n");
    controller(0,0,1,1);
    controller(0,1,0,0);
    //test_case_23
    printf("TEST CASE 23\n");
    controller(0,1,0,1);
    controller(0,0,0,0);
    //test_case_24
    printf("TEST CASE 24\n");
    controller(0,0,0,1);
    controller(1,1,0,1);
    //test_case_25
    printf("TEST CASE 25\n");
    controller(0,1,0,1);
    controller(0,1,1,0);
    //test_case_26
    printf("TEST CASE 26\n");
    controller(0,0,0,0);
    controller(1,1,1,1);
    //test_case_27
    printf("TEST CASE 27\n");
    controller(0,0,0,1);
    controller(0,1,1,1);
    //test_case_28
    printf("TEST CASE 28\n");
    controller(1,1,1,1);
    controller(1,1,1,0);
    //test_case_29
    printf("TEST CASE 29\n");
    controller(1,1,0,0);
    controller(0,0,0,1);
    //test_case_30
    printf("TEST CASE 30\n");
    controller(0,1,0,1);
    controller(1,0,0,0);
    controller(0,0,1,1);

    printf("\nPredefined test cases completed.\n");
}

// Function for interactive simulation
void run_interactive_simulation() {
    int front, left, right, dust;
    int choice;

    while (1) {
        // Prompt for sensor values
        printf("\nEnter sensor values (1 for True, 0 for False):\n");
        printf("Front sensor: ");
        scanf("%d", &front);

        printf("Left sensor: ");
        scanf("%d", &left);

        printf("Right sensor: ");
        scanf("%d", &right);

        printf("Dust sensor: ");
        scanf("%d", &dust);

        // Call the controller with user inputs
        controller(front, left, right, dust);

        // Ask user if they want to continue
        printf("\nDo you want to enter new values? (1: Yes, 0: No): ");
        scanf("%d", &choice);
        if (choice == 0) {
            break;
        }
    }
}

// Main function with menu
int main() {
    int menu_choice;

    while (1) {
        // Display menu
        printf("\n--- Robot Vacuum Cleaner Menu ---\n");
        printf("1. Run predefined test cases\n");
        printf("2. Run interactive simulation\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &menu_choice);

        // Handle menu choice
        switch (menu_choice) {
            case 1:
                run_predefined_tests();
                break;
            case 2:
                run_interactive_simulation();
                break;
            case 3:
                printf("\nExiting program. Goodbye!\n");
                return 0;
            default:
                printf("\nInvalid choice. Please try again.\n");
                break;
        }
    }
}
