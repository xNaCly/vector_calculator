#ifndef _UTIL_H_INCLUDED
#define _UTIL_H_INCLUDED

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define ANSI_COLOR_RED      "\x1b[91m"
#define ANSI_COLOR_GREEN    "\x1b[92m"
#define ANSI_COLOR_RED_BG   "\x1b[101m"
#define ANSI_COLOR_GREEN_BG "\x1b[102m"
#define ANSI_COLOR_WHITE_BG "\x1b[40m"
#define ANSI_STYLE_BOLD     "\x1b[1m"
#define ANSI_STYLE_ITALIC   "\x1b[3m"
#define ANSI_RESET          "\x1b[0m"

// possible options for the user to select
const char *OPTIONS[] = {"double vec_length(int vec[])"};
const char *OPTIONS_DESC[] = {"returns the length of the given vector"};

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
  printf("Vector helper v0.1\t\nThis program has several helpful methods for working with vectors:\n\t");

  for(int i = 0; i < (int) (sizeof(OPTIONS)/sizeof(OPTIONS[0])); i++){
    printf("\t[%d]: %s%s%s -> %s\n", i+1, ANSI_COLOR_WHITE_BG, OPTIONS[i], ANSI_RESET, OPTIONS_DESC[i]);
  }

  printf("source: https://github.com/xnacly");
}
#endif
