#include <math.h>
#include "util.h"

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