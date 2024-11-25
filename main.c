#include <stdio.h>
#include <stdbool.h>
#include "header.h"

// Function to run predefined test cases
void run_predefined_tests() {
    printf("\nRunning predefined test cases...\n");

    int test_cases[30][4] = {
        {0, 0, 0, 0}, {0, 0, 0, 1}, {0, 0, 1, 0}, {0, 0, 1, 1},
        {0, 1, 0, 0}, {0, 1, 0, 1}, {0, 1, 1, 0}, {0, 1, 1, 1},
        {1, 0, 0, 0}, {1, 0, 0, 1}, {1, 0, 1, 0}, {1, 0, 1, 1},
        {1, 1, 0, 0}, {1, 1, 0, 1}, {1, 1, 1, 0}, {1, 1, 1, 1},
        {0, 0, 0, 1}, {1, 0, 1, 1}, {0, 1, 0, 1}, {1, 0, 1, 0},
        {1, 0, 0, 1}, {1, 1, 0, 0}, {0, 0, 1, 0}, {1, 1, 1, 1},
        {1, 0, 0, 0}, {0, 1, 1, 0}, {0, 0, 1, 1}, {0, 1, 0, 0},
        {0, 1, 0, 1}, {1, 0, 0, 0}
    };

    for (int i = 0; i < 30; i++) {
        printf("\nTEST CASE %d:\n", i + 1);
        controller(test_cases[i][0], test_cases[i][1], test_cases[i][2], test_cases[i][3]);
    }

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
