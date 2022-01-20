#include "../libs/vector.h"
#include "../libs/test.h"


int main(void){
  printf("Running tests...\n\n");
  int vec[] = {1,2,3};
  int vec1[] = {2,2,2};

  print_test_header("Tests 1:");
  double vlen = vec_length(vec);
  double vlen1 = vec_length(vec1);

  check_if_equal_int(3.7, vlen, "Test 1.0: length of the vector");
  check_if_equal_int(3.5, vlen1, "Test 1.1: length of the vector");


  print_test_header("Tests 2:");
  int result_v[] = {0,0,0};
  int expected_v[] = {3,4,5};

  vec_add(vec, vec1, result_v);
  check_if_equal_vec(expected_v, result_v, "Test 2.0: addition of two vectors");

  int expected_v1[] = {4,6,8};
  vec_add(vec, expected_v, result_v);
  check_if_equal_vec(expected_v1, result_v, "Test 2.1: addition of two vectors");

  print_results();
}