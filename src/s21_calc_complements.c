#include "s21_matrix.h"

int s21_calc_complements(matrix_t *A, matrix_t *result) {
    int code = OK;
    if (valid_matrix(A)) {
        if (A->columns != 1 && A->rows != 1) {
            s21_create_matrix(A->columns, A->rows, result);
            if (valid_matrix(result)) {
                for (int i = 0; i < A->rows; i++) {
                    for (int j = 0; j < A->columns; j++) {
                        matrix_t *minor = minor_matrix(i, j, A);
                        if (valid_matrix(minor)) {
                            double det = 0;
                            s21_determinant(minor, &det);
                            result->matrix[i][j] = pow(-1, i+j) * det;
                        }   
                        else {
                            code = ERROR;
                        }
                        s21_remove_matrix(minor);
                        minor = NULL;
                    }
                }
            }
            else {
                code = ERROR;
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

