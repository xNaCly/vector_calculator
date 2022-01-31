#ifndef _UTIL_H_INCLUDED
#define _UTIL_H_INCLUDED

#include <stdio.h>  // printf()
#include <string.h> //strcmp()
#include <stdlib.h> // scanf()

#define VERSION "0.1"

#define ANSI_COLOR_RED "\x1b[91m"
#define ANSI_COLOR_GREEN "\x1b[92m"
#define ANSI_COLOR_WHITE "\x1b[97m"
#define ANSI_COLOR_BLACK "\x1b[30m"
#define ANSI_COLOR_GREY_BG "\x1b[100m"
#define ANSI_COLOR_RED_BG "\x1b[101m"
#define ANSI_COLOR_GREEN_BG "\x1b[102m"
#define ANSI_COLOR_WHITE_BG "\x1b[107m"
#define ANSI_STYLE_BOLD "\x1b[1m"
#define ANSI_STYLE_ITALIC "\x1b[3m"
#define ANSI_RESET "\x1b[0m"

extern const char *OPTIONS[];
extern const char *OPTIONS_DESC[];

// prints error, exits with given code
void throw_error(char text[], int code);

// gets the selection made by the user and returns the selection, checks if selection is available
int get_selection(void);

// prints the manual, consisting of the available method and its description
void print_manual(void);

// parses arguments and returns contents based on them
void handle_arguments(int argc, char *argv[]);

// handles argument parser call
void init_main(int argc, char *argv[]);

// printing of the manual + a prompt
void helper_init_main(void);

#endif
