#include "s21_grep.h"

int main(int argc, char *argv[]) {
  if (argc > 2) {
    flg flags = {0};
    if (!parsing(argc, argv, &flags)) {
      if (flags.e_f == 0) {
        sprintf(flags.pattern, "%s", argv[optind]);
        optind++;
      }
      if (argc - optind > 1) flags.multi_files = 1;
      if (flags.multi_files && !flags.h) flags.print_filename = 1;
      while (optind < argc) {
        reader(argv, flags);
        optind++;
      }
    }
  }
  return 0;
}

int parsing(int argc, char *argv[], flg *flags) {
  int opt = 0, error = 0;

  const char *short_opt = "e:ivclnhsf:o";
  while ((opt = getopt_long(argc, argv, short_opt, 0, 0)) != -1) {
    switch (opt) {
      case 'e':
        flags->e = 1;
        parser_e(flags);
        flags->e_f = 1;
        break;
      case 'i':
        flags->i = 1;
        break;
      case 'v':
        flags->v = 1;
        break;
      case 'c':
        flags->c = 1;
        break;
      case 'l':
        flags->l = 1;
        break;
      case 'n':
        flags->n = 1;
        break;
      case 'h':
        flags->h = 1;
        break;
      case 's':
        flags->s = 1;
        break;
      case 'f':
        flags->f = 1;
        pattern_from_file(flags, optarg);
        flags->e_f = 1;
        break;
      case 'o':
        flags->o = 1;
        break;

      default:
        error = 1;
        fprintf(stderr, "usage: grep [flags] template [file_name]\n");
        break;
    }
  }
  if (flags->v || flags->c || flags->l) flags->o = 0;
  return error;
}

void reader(char *argv[], flg flags) {
  FILE *stream = fopen(argv[optind], "r");
  if (stream) {
    int reg_flags = REG_EXTENDED;
    regex_t compiled;
    if (flags.i) reg_flags = REG_ICASE | REG_EXTENDED;
    if (regcomp(&compiled, flags.pattern, reg_flags) == 0) {
      char *line_current = NULL;
      size_t line_size = 0;
      int line_count = 0, line_found = 1, match_found = 0;
      while (getline(&line_current, &line_size, stream) != EOF) {
        line_count++;
        if (flags.o) {
          flags_o(line_current, compiled, flags, line_count, argv);
        } else {
          if (line_current)
            line_found = regexec(&compiled, line_current, 0, 0, 0);
          if (!flags.v && !line_found) {
            printer(line_current, argv, flags, &match_found, line_count);
          } else if (flags.v && line_found) {
            printer(line_current, argv, flags, &match_found, line_count);
          }
        }
      }

      if (flags.c) {
        if (flags.print_filename) printf("%s:", argv[optind]);
        if (flags.l && match_found) match_found = 1;  // -lc
        printf("%d\n", match_found);
      }

      if (flags.l && match_found) printf("%s\n", argv[optind]);

      if (line_current != NULL) free(line_current);
      regfree(&compiled);
    }
    fclose(stream);
  } else if (!flags.s) {
    fprintf(stderr, "s21_grep: %s: No such file or directory\n", argv[optind]);
  }
}

void parser_e(flg *flags) {
  if ((strlen(flags->pattern) + strlen(optarg)) < (BUF - 2)) {
    if (flags->e_f) strcat(flags->pattern, "|");
    if (strlen(optarg) == 0)
      strcat(flags->pattern, ".");
    else
      strcat(flags->pattern, optarg);
  }
}
void flags_o(char *line_current, regex_t compiled, flg flags, int line_count,
             char *argv[]) {
  regmatch_t pmatch = {0};
  int opener = 1;
  while (regexec(&compiled, line_current, 1, &pmatch, 0) != REG_NOMATCH) {
    if (opener) {
      if (flags.print_filename) printf("%s", argv[optind]);
      if (flags.n) printf("%d:", line_count);
    }
    opener++;
    for (int i = pmatch.rm_so; i < pmatch.rm_eo; i++)
      printf("%c", line_current[i]);
    printf("\n");
    line_current += pmatch.rm_eo;
  }
}

void printer(char *line_current, char *argv[], flg flags, int *match_found,
             int line_count) {
  if (!flags.l && !flags.c) {
    if (flags.print_filename) printf("%s:", argv[optind]);
    if (flags.n) printf("%d:", line_count);
    char *temp = strchr(line_current, '\n');
    if (temp) *temp = '\0';
    printf("%s\n", line_current);
  }
  (*match_found)++;
}

void pattern_from_file(flg *flags, char *optarg) {
  FILE *stream = NULL;
  stream = fopen(optarg, "r");
  if (stream) {
    char line_current[1] = {'\0'};
    char current = '\0', prev = '\n';
    while ((current = fgetc(stream)) != EOF) {
      if (strlen(flags->pattern) < (BUF - 2)) {
        if (flags->e_f && (prev == '\n')) {
          strcat(flags->pattern, "|");
        }
        if (current != '\n') {
          line_current[0] = current;
          strcat(flags->pattern, line_current);
        }
        if (current == '\n' && prev == '\n') {
          strcat(flags->pattern, ".");
        }
        if (current == '\n') flags->e_f = 1;
        prev = current;
      }
    }
    fclose(stream);
  } else if (!flags->s) {
    fprintf(stderr, "s21_grep: %s: No such file or directory\n", flags->f_file);
  }
}