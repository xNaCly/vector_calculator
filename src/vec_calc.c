#include "libs/_util.h"
#include "string.h" // strcmp()

void init_f(int argc, char *argv[]){
  handle_arguments(argc, argv);
  print_manual();
  printf("Choose an option by providing the coresponding number: ");
}

int main(int argc, char *argv[]){
  init_f(argc, argv);
  return 0;
}
