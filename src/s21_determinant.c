#include "s21_matrix.h"
int s21_determinant(matrix_t *A, double *result) {
    int code = SUCCESS;
    if (valid_matrix(A)) {
        if (A->columns == A->rows) {
            *result = 0;
            for (int i = 0; i < A->columns; i++) {
                matrix_t *minor = s21_minor_matrix(0, i, A);
                double minor_det = 0;
                code = s21_determinant(minor, &minor_det);
                if (!code) {
                *result += pow(-1, i) * A->matrix[0][i] * minor_det;
                }
                s21_remove_matrix(minor);
                free(minor);
                minor = NULL;
                }
        }
        else {
            code = CALC_ERROR;
        }
    }
    else {
        code = ERROR;
    }
    return code;
}