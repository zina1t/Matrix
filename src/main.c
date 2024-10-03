#include "s21_matrix.h"

int main()
{
    srand(time(NULL));
    matrix_t m, res;
    s21_create_matrix(8, 4, &m);
    fill_int_matrix(&m);
    s21_print_matrix(&m);
    printf("\n");
    s21_transpose(&m, &res);
    printf("\n");
    s21_print_matrix(&res);
    s21_remove_matrix(&m);
    return 0;
}