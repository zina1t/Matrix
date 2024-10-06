#include "../s21_matrix.h"

int s21_sub_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  int code = OK;
  if (!(valid_matrix(A) && valid_matrix(B))) {
    return ERROR;
  }
  if ((A->rows == B->rows) && (A->columns == B->columns)) {
    s21_create_matrix(A->rows, A->columns, result);
    for (int i = 0; i < A->rows; i++) {
      for (int j = 0; j < A->columns; j++) {
        result->matrix[i][j] = A->matrix[i][j] - B->matrix[i][j];
      }
    }
  } else {
    code = CALC_ERROR;
  }
  return code;
}