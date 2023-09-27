CC = gcc
CFLAGS = -Wall -Werror -Wextra -std=c11 
TEST_LIBS = -lcheck -lm # -lsubunit
SOURCES = $(wildcard s21_*.c)
OBJECTS = $(patsubst %.c, %.o, $(SOURCES))

all: clean s21_string.a test gcov_report

s21_string.a: $(OBJECTS)
	ar rcs s21_string.a $(OBJECTS)

clean:
	rm -rf ./*.o ./*.a ./a.out gcov_test *.html *.css ./GcovReport ./*.gcno ./*.gcda ./report ./*.info ./string_o ./*.dSYM ./test_s21_string

test: s21_string.a
	$(CC) $(CFLAGS) -g ./tests/test_s21_string.c s21_string.a -o test $(TEST_LIBS)

test_code: test
	./test
	rm ./test
	rm ./*.o
	rm ./*.a

gcov_report: s21_string.a 
	$(CC) $(CFLAGS) --coverage ./tests/test_s21_string.c s21_*.c s21_string.a $(TEST_LIBS) -o gcov_test
	chmod +x *
	./gcov_test
	lcov -t "gcov_test" -o gcov_test.info --no-external -c -d .
	genhtml -o report/ gcov_test.info
	open ./report/index.html

check: test
	cppcheck --enable=all --suppress=missingIncludeSystem --inconclusive --check-config *.c *.h
	cp ../materials/linters/.clang-format .clang-format
	clang-format -style=Google *.h *.c ./*/*.c ./*/*.h -i
	rm -rf .clang-format
	make test
	leaks --atExit -- test

valgrind: test
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./test

rebuild: clean all
	open ./report/index.html
