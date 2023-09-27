#ifndef FLAGS

#include <getopt.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define HELP \
  "Usage: cat [OPTION]... [FILE]...\n\
Concatenate FILE(s) to standard output.\n\n\
With no FILE, or when FILE is -, read standard input.\n\n\
  -A, --show-all           equivalent to -vET\n\
  -b, --number-nonblank    number nonempty output lines, overrides -n\n\
  -e                       equivalent to -vE\n\
  -E, --show-ends          display $ at end of each line\n\
  -n, --number             number all output lines\n\
  -s, --squeeze-blank      suppress repeated empty output lines\n\
  -t                       equivalent to -vT\n\
  -T, --show-tabs          display TAB characters as ^I\n\
  -u                       (ignored)\n\
  -v, --show-nonprinting   use ^ and M- notation, except for LFD and TAB\n\
      --help     display this help and exit\n\n\
Examples:\n\
  cat f - g  Output f's contents, then standard input, then g's contents.\n\
  cat        Copy standard input to standard output.\n"

#define FLAGS

typedef struct options {
  int b;
  int e;
  int n;
  int s;
  int t;
  int v;
} opt;

void parser(int argc, char *argv[], opt *options);
void reader(char *argv, opt *options);
void cat_help();

#endif
