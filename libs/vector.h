#ifndef VECTOR_H_INCLUDED
#define VECTOR_H_INCLUDED

#include <stdio.h>
#include <math.h>

double vec_length(int vec[]){
  double s = 0;
  for(int i = 0; i < 3; i++){
    s += pow(vec[i], 2);
  }
  return sqrt(s);
}

void vec_add(int vec[], int vec1[], int v[]){
  for(int i = 0; i < 3; i++){
    v[i] = vec[i] + vec1[i];
  }
  return;
}



#endif
