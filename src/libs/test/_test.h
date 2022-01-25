#ifndef _TEST_H_INCLUDED
#define _TEST_H_INCLUDED

#include <stdio.h>
#include <string.h>
#include "../util/_util.h"

extern int TESTS_PASSED;
extern int TESTS_FAILED;
extern int VERBOSE;

void print_test_help(void);
void print_test_header(char text[]);
void int_test_feedback(double x, double y, char text[], char status[]);
void vec_test_feedback(int vec[], int vec1[], char text[], char status[]);
void check_if_equal_double(double value1, double value2, char text[]);
void check_if_equal_int(int value1, int value2, char text[]);
void check_if_equal_vec(int vec[], int vec1[], char text[]);
void print_results(double time_elabsed);

#endif
