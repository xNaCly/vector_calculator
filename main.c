#include <math.h>
#include "util.h"

/*
*****************************************************************
Vector helper v0.1

This program has several helpful methods for working with vectors:
- calculate vector length: vec_length(vec)
- calculate the scalar product: scalar_prd(vec, vec)
- calculate the orthogonal vector: vec_prod(vec, vec)
- calculate the angle between two vectors: calc_angle(vec, vec)
- add two vectors together: vec_add(vec, vec)
- subtract two vectors: vec_sub(vec, vec)
- multiply a vector with an int: vec_mult(vec, int)


source: https://github.com/xnacly
******************************************************************
*/

double vec_length(double vec[]){
  double s;
  for(int i = 0; i < 3; i++){
    s += pow(vec[i], 2);
  }
  return sqrt(s);
}

int main(void){
  print_options();
  int selection = get_selection();
  print_help();

  return 0;
}