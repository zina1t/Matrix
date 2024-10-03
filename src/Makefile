CC=gcc
FLAGS=-Wall -Wextra -Werror

MATRIX= main.c s21_create_matrix.c s21_remove_matrix.c fill_matrix.c s21_eq_matrix.c s21_sum_matrix.c s21_sub_matrix.c s21_mult_number.c s21_mult_matrix.c s21_transpose.c
OBJ=$(SRC_DECIMAL:.c=.o)

all: test clean

test:CFLAGS += -coverage

test: $(OBJ) s21_matrix.h
	$(CC) $(FLAGS) $(MATRIX) -o test
	./test


clean: 
	rm -rf  test *.o *.out