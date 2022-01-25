#ifndef _VECTOR_H_INCLUDED
#define _VECTOR_H_INCLUDED

#define PI 3.14159265

#include <math.h>

double vec_length(int v[]){
  double s = 0;
  for(int i = 0; i < 3; i++){
    s += pow(v[i], 2);
  }
  return sqrt(s);
}

void vec_add(int v[], int v1[], int result_vector[]){
  for(int i = 0; i < 3; i++){
    result_vector[i] = v[i] + v1[i];
  }
  return;
}

void vec_sub(int v[], int v1[], int result_vector[]){
  for(int i = 0; i < 3; i++){
    result_vector[i] = v[i] - v1[i];
  }
  return;
}

void vec_mult(int v[], int factor, int result_vector[]){
  for(int i = 0; i < 3; i++){
    result_vector[i] = v[i] * factor;
  }
  return;
}

int scalar_prod(int v[], int v1[]){
  int s = 0;
  for(int i = 0; i < 3; i++){
    s += v[i] * v1[i];
  }
  return s;
}

double angle_between(int v[], int v1[]){
  double s = scalar_prod(v, v1);
  double bf = vec_length(v) * vec_length(v1);
  return acos(s / bf) * 180.0 / PI;
}

void vec_prod(int v[], int v1[], int result_vector[]){
  result_vector[0] = v[1] * v1[2] - v[2] * v1[1];
  result_vector[1] = v[2] * v1[0] - v[0] * v1[2];
  result_vector[2] = v[0] * v1[1] - v[1] * v1[0];
  return;
}

#endif
