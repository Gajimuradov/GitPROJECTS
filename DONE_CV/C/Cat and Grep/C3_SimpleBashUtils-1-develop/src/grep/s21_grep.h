#define _GNU_SOURCE

#include <getopt.h>
#include <regex.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUF 2048

typedef struct flags {
  int e;
  int i;
  int v;
  int c;
  int l;
  int n;
  int h;
  int s;
  int f;
  int o;
  int e_f;
  char pattern[BUF];
  char f_file[BUF];
  int print_filename;
  int multi_files;
} flg;

int parsing(int argc, char *argv[], flg *flags);
void reader(char *argv[], flg flags);
void parser_e(flg *flags);
void flags_o(char *line_current, regex_t compiled, flg flags, int line_count,
             char *argv[]);
void printer(char *line_current, char *argv[], flg flags, int *match_found,
             int line_count);
void pattern_from_file(flg *flags, char *optarg);
