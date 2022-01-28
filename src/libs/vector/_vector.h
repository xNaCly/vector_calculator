#ifndef _VECTOR_H_INCLUDED
#define _VECTOR_H_INCLUDED

#include <math.h>

#define PI 3.14159265

//returns len of the given vector
double vec_length(int v[]);

// adds two vectors, stored in result_vector
void vec_add(int v[], int v1[], int result_vector[]);

// subtracts two vectors, stored in result_vector
void vec_sub(int v[], int v1[], int result_vector[]);

// multiplies a vector with an int, stored in result_vector
void vec_fac(int v[], int factor, int result_vector[]);

// returns the scalar product of two vectors
int scalar_prod(int v[], int v1[]);

// returns the angle between two vectors
double angle_between(int v[], int v1[]);

// calculates the vector product, stored in result_vector
void vec_prod(int v[], int v1[], int result_vector[]);

// calculates the triple prod of three vectors
int triple_prod(int v[], int v1[], int v2[]);

#endif
