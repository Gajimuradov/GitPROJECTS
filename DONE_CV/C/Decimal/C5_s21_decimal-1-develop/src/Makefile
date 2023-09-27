CFLAGS =-Wall -Werror -Wextra
LFLAGS = -lcheck #-lm -lsubunit
GCOV_FLAGS=-lgcov --coverage
CC = gcc

.PHONY: clean all rebuild

all: s21_decimal.a

test: s21_decimal.a tests.o
	$(CC) tests.o $(LFLAGS) -L. s21_decimal.a  -o $@

gcov_report: s21_decimal.c tests.c s21_decimal.a
	$(CC) $(CFLAGS) $^ $(LFLAGS) $(GCOV_FLAGS)
	./a.out
	lcov --capture --directory . --output-file coverage.info
	genhtml coverage.info --output-directory gcov_report

tests.o: tests.c
	$(CC) -c $(CFLAGS) $^

s21_decimal.a: s21_decimal.o helpers.o s21_big_decimal.o convertations.o
	ar -rcs $@ $^

s21_decimal.o: s21_decimal.c
	$(CC) -c $(CFLAGS) $^

s21_big_decimal.o: s21_big_decimal.c
	$(CC) -c $(CFLAGS) $^

helpers.o: helpers.c
	$(CC) -c $(CFLAGS) $^

convertations.o: convertations.c
	$(CC) -c $(CFLAGS) $^

clean:
	rm -rf *.o test gcov_report *.gcda *.gcno coverage.info *.a a.out

rebuild: clean all
