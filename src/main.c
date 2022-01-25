#include "libs/_util.h"
#include "string.h" // strcmp()

int main(int argc, char *argv[]){
  const int help = argc > 1 ? strcmp("--help", argv[1]) == 0 || strcmp("-h", argv[1]) == 0: 0;
  if(help){
    print_help();
    exit(0);
  }

  print_options();
  // const int sel = get_selection();
  return 0;
}
