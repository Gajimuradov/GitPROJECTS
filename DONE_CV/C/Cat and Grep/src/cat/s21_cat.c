#include "s21_cat.h"

int main(int argc, char *argv[]) {  // argc - счетчик, char *argv[] - указатель
                                    // на нулевой индекс каждого аргумента
  opt options = {0};  // присваиваем 0 всем значениям структуры

  parser(argc, argv, &options);
  for (int i = optind; i < argc; i++) {
    reader(argv[i], &options);
  }
}

void parser(int argc, char *argv[], opt *options) {
  int opt;

  struct option long_options[] = {{"number-nonblank", 0, 0, 'b'},
                                  {"number", 0, 0, 'n'},
                                  {"squeeze-blank", 0, 0, 's'},
                                  {"help", 0, 0, 'h'},
                                  {0, 0, 0, 0}};

  while ((opt = getopt_long(argc, argv, "+benstvTE", long_options, NULL)) !=
         -1) {  // + нужен для того, чтобы обработка опций прерывалась на первом
                // аргументе, не являющемся опцией
    switch (opt) {
      case 'b':
        options->b = 1;
        break;
      case 'e':
        options->e = 1;
        options->v = 1;
        break;
      case 'n':
        options->n = 1;
        break;
      case 's':
        options->s = 1;
        break;
      case 't':
        options->t = 1;
        options->v = 1;
        break;
      case 'v':
        options->v = 1;
        break;
      case 'T':
        options->t = 1;
        break;
      case 'E':
        options->e = 1;
        break;
      case 'h':
        cat_help();
        break;

      default:
        fprintf(stderr, "Use --help for disply help message\n");
        exit(1);
    }
  }
}

void cat_help() {
  printf(HELP);
  exit(0);
}

void reader(char *argv, opt *options) {  // чтение файла и обработка флагов
  FILE *stream = fopen(
      argv, "r");  // мы объявили указатель на переменную типа FILE, потому что
                   // fopen возвращает указатель на структкру FILE

  if (stream != NULL) {
    int str_count = 1;
    int flag_s = 0;
    char c = '\0';

    for (char prev = '\n'; !feof(stream); prev = c) {
      c = getc(stream);

      if (options->s && c == '\n' && prev == '\n') {
        flag_s++;
        if (flag_s > 1) continue;
      } else {
        flag_s = 0;
      }

      if (options->b && prev == '\n' && c != '\n') printf("%6d\t", str_count++);

      if (options->n && !options->b && prev == '\n' && c != EOF)
        printf("%6d\t", str_count++);

      if (options->e && c == '\n') printf("$");

      if (options->t) {
        if (c == 9) {
          putchar('^');
          c = 'I';
        }
      }

      if (options->v) {
        if ((c >= 0 && c < 9) || (c > 10 && c < 32)) {
          putchar('^');
          c += 64;
        }
        if (c == 127) {
          putchar('^');
          c = '?';
        }
      }
      if (c != EOF) printf("%c", c);
    }
    fclose(stream);
  }

  else
    fprintf(stderr, "s21_cat: %s: No such file or directory\n", argv);
}
