#include "../libs/vector.h"
#include "../libs/test.h"
#include <string.h>
#include <time.h>


int main(int argc, char *argv[]){
  clock_t begin = clock();
  VERBOSE = argc > 1 ? !(strcmp("--silent", argv[1]) || strcmp("-s", argv[1])) : 1;

  if(VERBOSE)
    printf("Running tests...\n\n");
  int vec[] = {1,2,3};

  if(VERBOSE)
    print_test_header("Test 1 - Length of vectors:");
  double vlen = vec_length(vec);
  check_if_equal_double(3.7, vlen, "Test 1.0");

  if(VERBOSE)
    print_test_header("Test 2 - Addition of two vectors: ");
  int vec1[] = {2,2,2};

  int result_v[] = {0,0,0};
  int expected_v[] = {3,4,5};

  vec_add(vec, vec1, result_v);
  check_if_equal_vec(expected_v, result_v, "Test 2.0");

  if(VERBOSE)
    print_test_header("Test 3 - Subtraction of two vectors: ");
  int result_v1[] = {0,0,0};
  int expected_v1[] = {1,0,-1};

  vec_sub(vec1, vec, result_v1);
  check_if_equal_vec(expected_v1, result_v1, "Test 3.0");

  if(VERBOSE)
    print_test_header("Test 4 - Multiplication of a vector");
  int result_v2[] = {0,0,0};
  int fac = 2;
  int expected_v2[] = {2,4,6};
  vec_mult(vec, fac, result_v2);
  check_if_equal_vec(expected_v2, result_v2, "Test 4.0");

  if(VERBOSE)
    print_test_header("Test 5 - Calculate scalar product of two vectors");
  int sp = scalar_prod(vec, vec1);
  check_if_equal_int(12, sp, "Test 5.0");

  if(VERBOSE)
    print_test_header("Test 6 - Calculate the angle between two vectors");
  int vec2[] = {2,2,1};
  int vec3[] = {-1,-1,1};
  double a = angle_between(vec2, vec3);
  check_if_equal_double(125.264390, a, "Test 6.0");

  clock_t end = clock();
  double time_elabsed = (double)(end - begin) / CLOCKS_PER_SEC;
  print_results(time_elabsed);
}
