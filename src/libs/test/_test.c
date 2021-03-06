#include "_test.h"

int TESTS_PASSED = 0;
int TESTS_FAILED = 0;
int VERBOSE = 1;

void print_test_help(void)
{
  printf("Usage:\n  test --help | -h\n  test --silent | -s\n\nOptions:\n  -h --help\t Show this screen\n  -s --silent\t Minify Output\n");
}

void print_test_header(char text[])
{
  printf("%s%s%s\n", ANSI_STYLE_BOLD, text, ANSI_RESET);
}

void int_test_feedback(double x, double y, char text[], char status[])
{
  printf("%s%s %s %s %s \n",
         strcmp(status, "PASS") == 0 ? ANSI_COLOR_BLACK : ANSI_COLOR_WHITE,
         strcmp(status, "PASS") == 0 ? ANSI_COLOR_GREEN_BG : ANSI_COLOR_RED_BG,
         status,
         ANSI_RESET,
         text);

  if (VERBOSE)
    printf("%s\tExpected: %f%s\n\t%sGot:%f%s \n\n",
           ANSI_STYLE_ITALIC,
           x,
           ANSI_RESET,
           ANSI_STYLE_ITALIC,
           y,
           ANSI_RESET);
}

void vec_test_feedback(int vec[], int vec1[], char text[], char status[])
{
  printf("%s%s %s %s %s \n",
         strcmp(status, "PASS") == 0 ? ANSI_COLOR_BLACK : ANSI_COLOR_WHITE,
         strcmp(status, "PASS") == 0 ? ANSI_COLOR_GREEN_BG : ANSI_COLOR_RED_BG,
         status,
         ANSI_RESET,
         text);
  if (VERBOSE)
    printf("\t%sExpected: {%d, %d, %d}%s\n\t%sGot: {%d, %d, %d}%s\n\n",
           ANSI_STYLE_ITALIC,
           vec[0],
           vec[1],
           vec[2],
           ANSI_RESET,
           ANSI_STYLE_ITALIC,
           vec1[0],
           vec1[1],
           vec1[2],
           ANSI_RESET);
}

void check_if_equal_double(double value1, double value2, char text[])
{
  if ((value1 - value2) < 0.1)
  {
    TESTS_PASSED++;
    int_test_feedback(value1, value2, text, "PASS");
    return;
  }

  TESTS_FAILED++;
  int_test_feedback(value1, value2, text, "FAIL");
}

void check_if_equal_int(int value1, int value2, char text[])
{
  if (value1 == value2)
  {
    TESTS_PASSED++;
    int_test_feedback(value1, value2, text, "PASS");
    return;
  }

  TESTS_FAILED++;
  int_test_feedback(value1, value2, text, "FAIL");
}

void check_if_equal_vec(int vec[], int vec1[], char text[])
{
  for (int i = 0; i < 3; i++)
  {
    if (vec[i] != vec1[i])
    {
      TESTS_FAILED++;
      vec_test_feedback(vec, vec1, text, "FAIL");
      return;
    }
  }
  TESTS_PASSED++;
  vec_test_feedback(vec, vec1, text, "PASS");
}

void print_results(double time_elabsed)
{
  printf("\nTests: %s%d passed%s, %d of %d total\nTime: %.5fsec\n",
         ANSI_COLOR_GREEN,
         TESTS_PASSED,
         ANSI_RESET,
         TESTS_PASSED,
         TESTS_PASSED + TESTS_FAILED,
         time_elabsed);
}