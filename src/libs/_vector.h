#ifndef _VECTOR_H_INCLUDED
#define _VECTOR_H_INCLUDED

#define PI 3.14159265

#include <math.h>

double vec_length(int vec[]){
  double s = 0;
  for(int i = 0; i < 3; i++){
    s += pow(vec[i], 2);
  }
  return sqrt(s);
}

void vec_add(int v1[], int v2[], int result_vector[]){
  for(int i = 0; i < 3; i++){
    result_vector[i] = v1[i] + v2[i];
  }
  return;
}

void vec_sub(int v1[], int v2[], int result_vector[]){
  for(int i = 0; i < 3; i++){
    result_vector[i] = v1[i] - v2[i];
  }
  return;
}

void vec_mult(int v1[], int factor, int result_vector[]){
  for(int i = 0; i < 3; i++){
    result_vector[i] = v1[i] * factor;
  }
  return;
}

int scalar_prod(int v1[], int v2[]){
  int s = 0;
  for(int i = 0; i < 3; i++){
    s += v1[i] * v2[i];
  }
  return s;
}

double angle_between(int v1[], int v2[]){
  double s = scalar_prod(v1, v2);
  double bf = vec_length(v1) * vec_length(v2);
  return acos(s / bf) * 180.0 / PI;
}

void vec_prod(int v1[], int v2[], int result_vector[]){
  result_vector[0] = v1[1] * v2[2] - v1[2] * v2[1];
  result_vector[1] = v1[2] * v2[0] - v1[0] * v2[2];
  result_vector[2] = v1[0] * v2[1] - v1[1] * v2[0];
  return;
}

#endif