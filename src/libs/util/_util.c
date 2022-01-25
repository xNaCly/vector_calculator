#include "_util.h"

const char *OPTIONS[] = {
    "double vec_length(int v[])",
    "void vec_add(int v[], int v1[], int result_vector[])",
    "void vec_sub(int v[], int v1[], int result_vector[])",
    "void vec_mult(int v[], int factor, int result_vector[])",
    "int scalar_prod(int v[], int v1[])",
    "double angle_between(int v[], int v1[])",
    "void vec_prod(int v[], int v1[], int result_vector[])"};

const char *OPTIONS_DESC[] = {
    "returns len of the given vector",
    "adds two vectors, stored in result_vector",
    "subtracts two vectors, stored in result_vector",
    "multiplies a vector, stored in result_vector",
    "returns the scalar product of two vectors",
    "returns the angle between two vectors",
    "calculates the vector product, stored in result_vector"};

void throw_error(char text[], int code)
{
  printf(ANSI_COLOR_RED "\n\nError (%d): %s\n" ANSI_RESET, code, text);
  printf("Stopping the programm due to an Error. \n");
  exit(code < 255 ? code : 1);
}

// gets the selection made by the user and returns the selection, checks if selection is available
int get_selection(void)
{
  int selection = -1;
  scanf("%d", &selection);

  if (selection == -1 || selection < 1 || selection > (int)(sizeof(OPTIONS) / sizeof(OPTIONS[0])))
  {
    // throw_error("Given Index does not match any available selection, please try again.");
    printf("selection with index: %d not found, try again. \n", selection);
    get_selection();
  }

  return selection;
}

// prints the manual, consisting of the available method and its description
void print_manual(void)
{
  printf("Vector calculator %s:\n", VERSION);

  for (int i = 0; i < (int)(sizeof(OPTIONS) / sizeof(OPTIONS[0])); i++)
  {
    printf("\t[%d]: %s%s%s%s\n\t\t%s%s%s\n\n",
           i + 1,
           ANSI_STYLE_BOLD,
           ANSI_COLOR_WHITE,
           OPTIONS[i],
           ANSI_RESET,
           ANSI_STYLE_ITALIC,
           OPTIONS_DESC[i],
           ANSI_RESET);
  }
}

void handle_arguments(int argc, char *argv[])
{
  if (argc > 1)
  {
    if (strcmp("--help", argv[1]) == 0 || strcmp("-h", argv[1]) == 0)
    {
      printf("Usage:\n  vec_calc --help | -h\n  vec_calc --version | -v\n\nOptions:\n  -h --help \t Show this screen\n  -v --version \t Show version\n");
      exit(0);
    }
    else if (strcmp("-v", argv[1]) == 0 || strcmp("-v", argv[1]) == 0)
    {
      printf("Current Version: %s\n", VERSION);
      exit(0);
    }
  }
}