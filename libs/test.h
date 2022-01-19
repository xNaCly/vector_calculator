#ifndef TEST_H_INCLUDED
#define TEST_H_INCLUDED

#include <stdio.h>
#include "util.h"

void int_test_feedback(double x, double y, char text[], char status[]){
  printf("[%s] %s \n\tExpected: %f\n\tGot: %f\n", status, text, x, y);
}

void vec_test_feedback(double vec[], double vec1[], char text[], char status[]){
  printf("[%s] %s \n\tExpected: {%f, %f, %f}\n\tGot: {%f, %f, %f}\n", status, text, vec[0], vec[1], vec[2], vec1[0], vec1[1], vec1[2]);
}

void check_if_pass_int(double value1, double value2, char text[]){
  if((value1-value2) < 0.1)
    return int_test_feedback(value1, value2, text, "Passed");

  int_test_feedback(value1, value2, text, "Failed");
}

void check_if_pass_vec(double vec[], double vec1[], char text[]){
  int status = 0;
  for (int i = 0; i < 3; i++){
    if(vec[i] == vec1[i] && (vec[i]-vec1[i]) < 0.01) {
      status = 1;
    } else
      break;
  }
  if(status == 1)
    vec_test_feedback(vec, vec1, text, "Passed");
  else
    vec_test_feedback(vec, vec1, text, "Failed");

}
#endif