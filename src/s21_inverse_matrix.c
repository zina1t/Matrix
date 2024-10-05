#include "s21_matrix.h"

int s21_inverse_matrix(matrix_t *A, matrix_t *result) {
    int code = 0;
    if (valid_matrix(A)) {
        double det = 0;
        int func_code = s21_determinant(A, &det);
        if (det != 0 && A->columns == A->rows) {
            matrix_t compls, transposed_compls;
            int calc_code = s21_calc_complements(A, &compls);
            if (calc_code == OK) {
                int transpose_code = s21_transpose(&compls, &transposed_compls);
                if (transpose_code == OK) {
                    int mult_code = s21_mult_number(&transposed_compls, 1 / det, result);
                }
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