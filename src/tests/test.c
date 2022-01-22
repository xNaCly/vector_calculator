#include "../libs/vector.h"
#include "../libs/test.h"


int main(void){
  printf("Running tests...\n\n");
  int vec[] = {1,2,3};

  print_test_header("Test 1 - Length of vectors:");
  double vlen = vec_length(vec);

  check_if_equal_double(3.7, vlen, "Test 1.0");


  print_test_header("Test 2 - Addition of two vectors: ");
  int vec1[] = {2,2,2};

  int result_v[] = {0,0,0};
  int expected_v[] = {3,4,5};

  vec_add(vec, vec1, result_v);
  check_if_equal_vec(expected_v, result_v, "Test 2.0");

  print_test_header("Test 3 - Multiplication of a vector");
  int result_v1[] = {0,0,0};
  int fac = 2;
  int expected_v2[] = {2,4,6};
  vec_mult(vec, fac, result_v1);
  check_if_equal_vec(expected_v2, result_v1, "Test 3.1");

  print_test_header("Test 4 - Calculate scalar product of two vectors");
  int sp = scalar_prod(vec, vec1);
  check_if_equal_int(12, sp, "Test 4.1");


  print_results();
}
