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

void vec_test_feedback(double vec[], double vec1[], char text[], char status[]){
  printf("\t[%s%s%s] %s \n\t\t \e[3mExpected:\e[0m {%f, %f, %f}\n\t\t \e[3mGot:\e[0m {%f, %f, %f}\n\n", strcmp(status, "Passed") ? ANSI_COLOR_RED : ANSI_COLOR_GREEN, status, ANSI_COLOR_RESET, text, vec[0], vec[1], vec[2], vec1[0], vec1[1], vec1[2]);
}

void check_if_equal_int(double value1, double value2, char text[]){
  if((value1-value2) < 0.1)
    tests_passed++;
    return int_test_feedback(value1, value2, text, "Passed");

  tests_failed++;
  int_test_feedback(value1, value2, text, "Failed");
}

void check_if_equal_vec(double vec[], double vec1[], char text[]){
  int status = 0;
  for (int i = 0; i < 3; i++){
    if(vec[i] == vec1[i] && (vec[i]-vec1[i]) < 0.01) {
      status = 1;
    } else
      status = 0;
      break;
  }
  if(status == 1){
    tests_passed++;
    vec_test_feedback(vec, vec1, text, "Passed");
    return;
  } else
    tests_failed++;
    vec_test_feedback(vec, vec1, text, "Failed");

}

void print_results(void){
  printf("\nTest suite results:\n");
  printf("\t%sPassed%s Tests: %d\n\t%sFailed%s Tests: %d\n", ANSI_COLOR_GREEN, ANSI_COLOR_RESET, tests_passed,  ANSI_COLOR_RED, ANSI_COLOR_RESET, tests_failed);
}
#endif