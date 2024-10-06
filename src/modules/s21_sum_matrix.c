#include "../s21_matrix.h"

int s21_sum_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  int status = 0;
  if (!(valid_matrix(A) && valid_matrix(B))) {
    return ERROR;
  }
  if (A->rows != B->rows || A->columns != B->columns) {
    return CALC_ERROR;
  }
  if (status == 0) {
    if ((status = s21_create_matrix(A->rows, A->columns, result)) == 0) {
      for (int x = 0; x < A->rows; x += 1) {
        for (int y = 0; y < A->columns; y += 1) {
          result->matrix[x][y] = A->matrix[x][y] + B->matrix[x][y];
        }
      }
    }
  }

  return status;
}