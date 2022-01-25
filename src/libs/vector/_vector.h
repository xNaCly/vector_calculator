#ifndef _VECTOR_H_INCLUDED
#define _VECTOR_H_INCLUDED

#include <math.h>

#define PI 3.14159265

double vec_length(int v[]);
void vec_add(int v[], int v1[], int result_vector[]);
void vec_sub(int v[], int v1[], int result_vector[]);
void vec_mult(int v[], int factor, int result_vector[]);
int scalar_prod(int v[], int v1[]);
double angle_between(int v[], int v1[]);
void vec_prod(int v[], int v1[], int result_vector[]);

#endif
