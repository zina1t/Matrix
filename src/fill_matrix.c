#include "s21_matrix.h"

void fill_matrix(matrix_t *A) {  
    double random_value = 0;
    if (A->matrix != NULL) {
        for (int i = 0; i < A->rows; i++) {
            for (int j = 0; j < A->columns; j++) {
                random_value = (double)rand()/RAND_MAX*10;
                A->matrix[i][j] = random_value;
            }
        }
    }
}

void fill_int_matrix(matrix_t *A) {
    int random_value = 0;
    if (A->matrix != NULL) {
        for (int i = 0; i < A->rows; i++) {
            for (int j = 0; j < A->columns; j++) {
                random_value = rand() % 100;
                A->matrix[i][j] = random_value;
            }
        }
    }
}

int valid_matrix(matrix_t *A) {
    int code;
    if (A != NULL && A->matrix != NULL && A->rows > 0 && A->columns > 0)
        code = OK;
    return code;
  }

matrix_t *minor_matrix(int excluded_row, int excluded_column, matrix_t *A) {
    int code = OK;
    if (!valid_matrix(A)) {
        code = ERROR;
    }

    matrix_t *minor = calloc(1, sizeof(matrix_t));
    if (minor == NULL) {
        code = ERROR;
    }

    if (s21_create_matrix(A->rows - 1, A->columns - 1, minor) != OK) {
        free(minor);
        code = ERROR;
    }
    if (code != ERROR) {
        for (int i = 0, minor_row = 0; i < A->rows; i++) {
            if (i == excluded_row) continue;
            for (int j = 0, minor_column = 0; j < A->columns; j++) {
            if (j == excluded_column) continue;
            minor->matrix[minor_row][minor_column] = A->matrix[i][j];
            minor_column++;
            }
            minor_row++;
        }
    }
    return minor;
}