#ifndef UTIL_H_INCLUDED
#define UTIL_H_INCLUDED

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_RESET   "\x1b[0m"

// possible options for the user to select
const char *OPTIONS[] = {"vec_length(vec)"};

void throw_error(char text[], int code){
  printf(ANSI_COLOR_RED "\n\nError (%d): %s\n" ANSI_COLOR_RESET, code, text);
  printf("Stopping the programm due to an Error. \n");
  exit(code < 255 ? code : 1);
}

void print_options(void){
  printf("The following options are currently available: \n");

  for(int i = 0; i < sizeof(OPTIONS)/sizeof(OPTIONS[0]); i++){
    printf("\t[%d]: %s\n", i+1, OPTIONS[i]);
  }

  printf("Choose an option by providing the coresponding number: ");
}

/*
gets the selection made by the user and returns the selection
*/
int get_selection(void){
  int selection = -1;
  scanf("%d", &selection);

  if(selection == -1 || selection < 1 || selection > sizeof(OPTIONS)/sizeof(OPTIONS[0])){
    // throw_error("Given Index does not match any available selection, please try again.");
    printf("selection with index: %d not found, try again. \n", selection);
    get_selection();
  }

  return selection;
}

void print_help(void){
  printf("Vector helper v0.1\t\nThis program has several helpful methods for working with vectors:\n\t- calculate vector length: vec_length(vec)\n\t- calculate the scalar product: scalar_prd(vec, vec)\n\t- calculate the orthogonal vector: vec_prod(vec, vec)\n\t- calculate the angle between two vectors: calc_angle(vec, vec)\n\t- add two vectors together: vec_add(vec, vec)\n\t- subtract two vectors: vec_sub(vec, vec)\n\t- multiply a vector with an int: vec_mult(vec, int)\nsource: https://github.com/xnacly");
}
#endif
