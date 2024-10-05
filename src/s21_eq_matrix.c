#include "s21_matrix.h"

int s21_eq_matrix(matrix_t *A, matrix_t *B) {
    int code = SUCCESS;
    if (valid_matrix(A) && valid_matrix(B)) {
        if ((A->rows == B->rows) && (A->columns == B->columns)) {
            for (int i = 0; i < A->rows; i++) {
                for (int j = 0; j < A->columns; j++) {
                    if (fabs(A->matrix[i][j] - B->matrix[i][j]) > 1e-07) {
                        code = FAILURE;
                    }
                }
            }
        }
        else {
            code = FAILURE;
        }
    }
    else {
        code = FAILURE;
    }
    return code;
}