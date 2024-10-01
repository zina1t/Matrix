#include "s21_matrix.h"

int s21_create_matrix(int rows, int columns, matrix_t *result) {
    int code = OK;
    if (rows <= 0 || columns <= 0) {
        code = ERROR;
    }
    result->rows = rows;
    result->columns = columns;
    result->matrix = (double**)malloc(rows * sizeof(double*));
    if (result->matrix == NULL) {
        code = ERROR;
    }
    for (int i = 0; i < rows; i++) {
        result->matrix[i] = (double*)malloc(columns * sizeof(double));
        if (result->matrix[i] == NULL) {
            for (int j = 0; j < i; j++) {
                free(result->matrix[j]);
            }
            free(result->matrix);
            code = ERROR;
        }
    }
    return code;
}

void s21_print_matrix(matrix_t *A) {
    for (int i = 0; i < A->rows; i++) {
        for (int j = 0; j < A->columns; j++) {
            printf("%lf ", A->matrix[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    int a;
    matrix_t m;
    a = s21_create_matrix(3, 3, &m);
    if (a == OK) {
        printf("Matrix created\n");
    } else {
        printf("Error creating matrix\n");
    }
    s21_print_matrix(&m);
    return 0;
}
