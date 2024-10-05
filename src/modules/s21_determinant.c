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
    matrix_t com;
    s21_create_matrix(A->rows - 1, A->columns - 1, &com);
    s21_calc_complements(A, &com);
    *result = 0;

    for (int i = 0; i < A->rows; i++) {
      *result += A->matrix[i][0] * com.matrix[i][0];
    }

    s21_remove_matrix(&com);
  }
  return code;
}
