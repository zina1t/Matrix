#include "../s21_matrix.h"

int s21_determinant(matrix_t *A, double *result) {
  int code = OK;
  if (!valid_matrix(A)) {
    code = ERROR;
  } else if (A->rows != A->columns) {
    code = CALC_ERROR;
  } else if (A->rows == 1) {
    *result = A->matrix[0][0];
  } else if (A->rows == 2) {
    *result =
        A->matrix[0][0] * A->matrix[1][1] - A->matrix[0][1] * A->matrix[1][0];
  } else {
    int error_code = OK;
    *result = 0;
    for (int i = 0; i < A->columns && error_code == OK; i++) {
      matrix_t *minor = minor_matrix(0, i, A);
      if (minor == NULL) {
        error_code = ERROR;
      } else {
        double minor_det = 0;
        error_code = s21_determinant(minor, &minor_det);
        if (!error_code) {
          *result += pow(-1, i) * A->matrix[0][i] * minor_det;
        }
        s21_remove_matrix(minor);
        free(minor);
        minor = NULL;
      }
    }
  }
  return code;
}