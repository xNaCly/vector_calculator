#include "../libs/vector.h"
#include "../libs/test.h"


int main(void){
  double vec[] = {1,2,3};
  double vec1[] = {2,2,2};

  double vlen = vec_length(vec);
  double vlen1 = vec_length(vec1);
  check_if_pass_int(3.8, vlen, "Test 1.0: length of the vector");
  check_if_pass_int(3.5, vlen1, "Test 1.1: length of the vector");

  double v[] = {0,0,0};
  double v_[] = {3,4,5};
  vec_add(vec, vec1, v);
  check_if_pass_vec(v_, v, "Test 2.0: addition of two vectors");

}