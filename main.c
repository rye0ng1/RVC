#include <stdio.h>
#include "header.h"

int main() {
    //test_case_1
    printf("TEST CASE 01\n");
    controller(0,0,0,0);
    //test_case_2
    printf("TEST CASE 02\n");
    controller(0,0,0,1);
    //test_case_3
    printf("TEST CASE 03\n");
    controller(0,0,1,0);
    //test_case_4
    printf("TEST CASE 04\n");
    controller(0,0,1,1);
    //test_case_5
    printf("TEST CASE 05\n");
    controller(0,1,0,0);
    //test_case_6
    printf("TEST CASE 06\n");
    controller(0,1,0,1);
    //test_case_7
    printf("TEST CASE 07\n");
    controller(0,1,1,0);
    //test_case_8
    printf("TEST CASE 08\n");
    controller(0,1,1,1);
    //test_case_9
    printf("TEST CASE 09\n");
    controller(1,0,0,0);
    //test_case_10
    printf("TEST CASE 10\n");
    controller(1,0,0,1);
    //test_case_11
    printf("TEST CASE 11\n");
    controller(1,0,1,0);
    //test_case_12
    printf("TEST CASE 12\n");
    controller(1,0,1,1);
    //test_case_13
    printf("TEST CASE 13\n");
    controller(1,1,0,0);
    //test_case_14
    printf("TEST CASE 14\n");
    controller(1,1,0,1);
    //test_case_15
    printf("TEST CASE 15\n");
    controller(1,1,1,0);
    //test_case_16
    printf("TEST CASE 16\n");
    controller(1,1,1,1);
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

    return 0;
}