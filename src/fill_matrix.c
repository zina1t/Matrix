#include "s21_matrix.h"

void fill_matrix(matrix_t *A) {
    
    double random_value = 0;
    if (A->matrix != NULL) {
        for (int i = 0; i < A->rows; i++) {
            for (int j = 0; j < A->columns; j++) {
                random_value = (double)rand()/RAND_MAX*100.0;
                A->matrix[i][j] = random_value;
            }
        }
    }
}