#ifndef S21_MATRIX_H
#define S21_MATRIX_H

#include <math.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct matrix_struct {
  double **matrix;
  int rows;
  int columns;
} matrix_t;

#define OK 0
#define ERROR 1
#define CALC_ERROR 2

int s21_create_matrix(int rows, int columns, matrix_t *result);
void s21_print_matrix(matrix_t *A);

void s21_remove_matrix(matrix_t *A);

#define SUCCESS 1
#define FAILURE 0

int s21_eq_matrix(matrix_t *A, matrix_t *B);

int s21_sum_matrix(matrix_t *A, matrix_t *B, matrix_t *result);
int s21_sub_matrix(matrix_t *A, matrix_t *B, matrix_t *result);

int s21_mult_number(matrix_t *A, double number, matrix_t *result);
int s21_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result);

int s21_transpose(matrix_t *A, matrix_t *result);

int s21_calc_complements(matrix_t *A, matrix_t *result);

int s21_determinant(matrix_t *A, double *result);

int s21_inverse_matrix(matrix_t *A, matrix_t *result);

int valid_matrix(matrix_t *A);
void s21_initialize_matrix(matrix_t *A, double start_value,
                           double iteration_step);
matrix_t *minor_matrix(int excluded_row, int excluded_column, matrix_t *A);
#endif