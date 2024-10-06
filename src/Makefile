CFLAGS = -Wall -Wextra -Werror -std=c11
GCOVFLAGS = -fprofile-arcs -ftest-coverage
HEADERS = s21_matrix.h 
SOURCES_ALL = $(wildcard ./modules/*.c)
OBJ_LIBRARY := $(patsubst %.c, %.o, $(SOURCES_ALL))
OS = $(shell uname)

ifeq ($(OS), Linux)
	LDLIBS = -lcheck_pic -pthread -lrt -lm -lsubunit
else
	LDLIBS = -lcheck
endif

%.o: %.c $(HEADER)
	gcc $(CFLAGS) -c $< $(LDLIBS) -o $@


all: s21_matrix.a test gcov_report

s21_matrix.a: $(OBJ_LIBRARY) $(HEADERS)
	ar rcs s21_matrix.a $(OBJ_LIBRARY)
	ranlib s21_matrix.a
	rm -rf ./*/*.o

test: s21_matrix.a tests/test_matrix.c
	gcc $(CFLAGS) tests/test_matrix.c s21_matrix.a -o test.out $(LDLIBS)
	./test.out

gcov_report: s21_matrix.a tests/test_matrix.c
	gcc $(GCOVFLAGS) tests/test_matrix.c $(SOURCES_ALL) -o report.out $(LDLIBS)
	./report.out
	gcov -f $(SOURCES_ALL)
	lcov -t "gcov_report" -o Coverage_Report.info -c -d .
	genhtml -o ./report Coverage_Report.info
	rm -f *.gcno *.gcda *.info report.out *.gcov
	open ./report/index-sort-f.html

check:
	clang-format -style=Google -n ./*/*.c

rebuild: clean all

clean:
	rm -f *.o *.a tests/*.gcno tests/*.gcda *.info *.out *.gcov tests/*.log
	rm -rf ./report

valgrind_check: test
	@CK_FORK=no valgrind --vgdb=no --leak-check=full \
	--show-leak-kinds=all --track-origins=yes --log-file="valgrind.log" -v --verbose -q --quiet -s tests/$(TEST_TARGET)