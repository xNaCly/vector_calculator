#ifndef _TEST_H_INCLUDED
#define _TEST_H_INCLUDED

#include <stdio.h>
#include <string.h>
#include "_util.h"

int TESTS_PASSED = 0;
int TESTS_FAILED = 0;
int VERBOSE = 0;

void print_test_header(char text[]){
  printf("\x1b[1m%s\x1b[0m\n", text);
}

void int_test_feedback(double x, double y, char text[], char status[]){
  printf("%s %s %s %s \n",
    strcmp(status, "Passed") ? ANSI_COLOR_RED : ANSI_COLOR_GREEN,
    status,
    ANSI_COLOR_RESET,
    text);

  if(VERBOSE)
    printf("\t \x1b[3mExpected:\x1b[0m %f\n\t \x1b[3mGot:\x1b[0m %f\n\n", x, y);
}

void vec_test_feedback(int vec[], int vec1[], char text[], char status[]){
  printf("%s %s %s %s \n", strcmp(status, "Passed") ? ANSI_COLOR_RED : ANSI_COLOR_GREEN, status, ANSI_COLOR_RESET, text);
  if(VERBOSE)
  printf("\t \x1b[3mExpected:\x1b[0m {%d, %d, %d}\n\t \x1b[3mGot:\x1b[0m {%d, %d, %d}\n\n",
    vec[0],
    vec[1],
    vec[2],
    vec1[0],
    vec1[1],
    vec1[2]);
}

void check_if_equal_double(double value1, double value2, char text[]){
  if((value1-value2) < 0.1){
    TESTS_PASSED++;
    int_test_feedback(value1, value2, text, "Passed");
    return;
  }

  TESTS_FAILED++;
  int_test_feedback(value1, value2, text, "Failed");
}

void check_if_equal_int(int value1, int value2, char text[]){
  if(value1 == value2){
    TESTS_PASSED++;
    int_test_feedback(value1, value2, text, "Passed");
    return;
  }

  TESTS_FAILED++;
  int_test_feedback(value1, value2, text, "Failed");
}

void check_if_equal_vec(int vec[], int vec1[], char text[]){
  for (int i = 0; i < 3; i++){
    if(vec[i] != vec1[i]) {
      TESTS_FAILED++;
      vec_test_feedback(vec, vec1, text, "Failed");
      return;
    }
  }
  TESTS_PASSED++;
  vec_test_feedback(vec, vec1, text, "Passed");
}

void print_results(double time_elabsed){
    printf("\nTests: %s%d passed%s, %d of %d total\nTime: %.5fsec\n",
      ANSI_COLOR_GREEN_F,
      TESTS_PASSED,
      ANSI_COLOR_RESET,
      TESTS_PASSED,
      TESTS_PASSED+TESTS_FAILED,
      time_elabsed);
}
#endif
