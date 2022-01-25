#ifndef _UTIL_H_INCLUDED
#define _UTIL_H_INCLUDED

#include <stdio.h> // printf()
#include <string.h> //strcmp()
#include <stdlib.h> // scanf()
#include "_consts.h"


void throw_error(char text[], int code){
  printf(ANSI_COLOR_RED "\n\nError (%d): %s\n" ANSI_RESET, code, text);
  printf("Stopping the programm due to an Error. \n");
  exit(code < 255 ? code : 1);
}

void print_options(void){
  printf("The following options are currently available: \n");

  for(int i = 0; i < (int) (sizeof(OPTIONS)/sizeof(OPTIONS[0])); i++){
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

  if(selection == -1 || selection < 1 || selection > (int) (sizeof(OPTIONS)/sizeof(OPTIONS[0]))){
    // throw_error("Given Index does not match any available selection, please try again.");
    printf("selection with index: %d not found, try again. \n", selection);
    get_selection();
  }

  return selection;
}

void print_help(void){
  printf("Vector helper v0.1\nThis program has several helpful methods for working with vectors:\n");

  for(int i = 0; i < (int) (sizeof(OPTIONS)/sizeof(OPTIONS[0])); i++){
    printf("\t[%d]: %s%s%s%s\n\t\t%s%s%s\n\n",
      i+1,
      ANSI_STYLE_BOLD,
      ANSI_COLOR_WHITE,
      OPTIONS[i],
      ANSI_RESET,
      ANSI_STYLE_ITALIC,
      OPTIONS_DESC[i],
      ANSI_RESET
      );
  }

  printf("source: https://github.com/xnacly/vector_calculator\n");
}
#endif
