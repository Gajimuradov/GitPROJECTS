CFLAGS = -Wall -Werror -Wextra -std=c11
FNAME = s21_cat

all: s21_cat linter

linter:
	cp ../../materials/linters/.clang-format ..
	clang-format -i *.c *.h 
	clang-format -n *.c *.h 
	rm -rf ../.clang-format

s21_cat: clean
	gcc $(CFLAGS) $(FNAME).c -o $(FNAME)

clean:
	rm -rf $(FNAME) s21_cat

rebuild:
	clean build