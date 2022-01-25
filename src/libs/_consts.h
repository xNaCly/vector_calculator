#ifndef _CONSTS_H_INCLUDED
  #define _CONSTS_H_INCLUDED

  int TESTS_PASSED = 0;
  int TESTS_FAILED = 0;
  int VERBOSE = 1;


  #define ANSI_COLOR_RED      "\x1b[91m"
  #define ANSI_COLOR_GREEN    "\x1b[92m"
  #define ANSI_COLOR_WHITE    "\x1b[97m"
  #define ANSI_COLOR_BLACK    "\x1b[30m"
  #define ANSI_COLOR_GREY_BG  "\x1b[100m"
  #define ANSI_COLOR_RED_BG   "\x1b[101m"
  #define ANSI_COLOR_GREEN_BG "\x1b[102m"
  #define ANSI_COLOR_WHITE_BG "\x1b[107m"
  #define ANSI_STYLE_BOLD     "\x1b[1m"
  #define ANSI_STYLE_ITALIC   "\x1b[3m"
  #define ANSI_RESET          "\x1b[0m"

  // options for the user to select
  const char *OPTIONS[] = {
    "double vec_length(int v[])",
    "void vec_add(int v[], int v1[], int result_vector[])",
    "void vec_sub(int v[], int v1[], int result_vector[])",
    "void vec_mult(int v[], int factor, int result_vector[])",
    "int scalar_prod(int v[], int v1[])",
    "double angle_between(int v[], int v1[])",
    "void vec_prod(int v[], int v1[], int result_vector[])"
  };

  const char *OPTIONS_DESC[] = {
    "returns len of the given vector",
    "adds two vectors, stored in result_vector",
    "subtracts two vectors, stored in result_vector",
    "multiplies a vector, stored in result_vector",
    "returns the scalar product of two vectors",
    "returns the angle between two vectors",
    "calculates the vector product, stored in result_vector"
  };


#endif