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

// options for the user to select
extern const char *OPTIONS[];
extern const char *OPTIONS_DESC[];

void throw_error(char text[], int code);
int get_selection(void);
void print_manual(void);
void handle_arguments(int argc, char *argv[]);

#endif
