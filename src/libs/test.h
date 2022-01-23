#ifndef TEST_H_INCLUDED
#define TEST_H_INCLUDED

#include <stdio.h>
#include <string.h>
#include "util.h"

int tests_passed = 0;
int tests_failed = 0;

void print_test_header(char text[]){
  printf("\e[1m%s\e[0m\n", text);
}

void int_test_feedback(double x, double y, char text[], char status[]){
  printf("\t[%s%s%s] %s \n\t\t \e[3mExpected:\e[0m %f\n\t\t \e[3mGot:\e[0m %f\n\n", strcmp(status, "Passed") ? ANSI_COLOR_RED : ANSI_COLOR_GREEN, status, ANSI_COLOR_RESET, text, x, y);
}

void vec_test_feedback(int vec[], int vec1[], char text[], char status[]){
  printf("\t[%s%s%s] %s \n\t\t \e[3mExpected:\e[0m {%d, %d, %d}\n\t\t \e[3mGot:\e[0m {%d, %d, %d}\n\n", strcmp(status, "Passed") ? ANSI_COLOR_RED : ANSI_COLOR_GREEN, status, ANSI_COLOR_RESET, text, vec[0], vec[1], vec[2], vec1[0], vec1[1], vec1[2]);
}

void check_if_equal_double(double value1, double value2, char text[]){
  if((value1-value2) < 0.1){
    tests_passed++;
    return int_test_feedback(value1, value2, text, "Passed");
  }

  tests_failed++;
  int_test_feedback(value1, value2, text, "Failed");
}

void check_if_equal_int(int value1, int value2, char text[]){
  if(value1 == value2){
    tests_passed++;
    return int_test_feedback(value1, value2, text, "Passed");
  }

  tests_failed++;
  int_test_feedback(value1, value2, text, "Failed");
}

void check_if_equal_vec(int vec[], int vec1[], char text[]){
  for (int i = 0; i < 3; i++){
    if(vec[i] != vec1[i]) {
      tests_failed++;
      vec_test_feedback(vec, vec1, text, "Failed");
      return;
    }
  }
  tests_passed++;
  vec_test_feedback(vec, vec1, text, "Passed");
}

void print_results(void){
  printf("\nTest suite results:\n");
  printf("\tPassed Tests: %s%d%s\n\tFailed Tests: %s%d%s\n", ANSI_COLOR_GREEN, tests_passed, ANSI_COLOR_RESET,   ANSI_COLOR_RED, tests_failed, ANSI_COLOR_RESET);
}
#endif
