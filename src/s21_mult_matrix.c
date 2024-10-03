#include "s21_matrix.h"

int s21_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
    int code = OK;
    if ((A->matrix != NULL) && (B->matrix != NULL)) {
        if (A->columns == B->rows) {
            s21_create_matrix(A->rows, B->columns, result);
            for (int i = 0; i < A->rows; i++) {
                for (int j = 0; j < B->columns; j++) {
                    result->matrix[i][j] = 0;
                    for (int k = 0; k < A->columns; k++) {                  
                        result->matrix[i][j] += A->matrix[i][k] * B->matrix[k][j];
                    }
                    printf("res %f ", result->matrix[i][j]);
                }
            }
        }
        else {
            code = FAILURE;
        }
    }
    else {
        code = ERROR;
    }
    printf("\n");
    return code;
}