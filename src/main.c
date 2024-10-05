#include "s21_matrix.h"

int main()
{
    srand(time(NULL));
    matrix_t m, res;
    s21_create_matrix(3, 3, &m);
    fill_int_matrix(&m);
    s21_print_matrix(&m);
    printf("\n");
    s21_calc_complements(&m, &res);
    printf("\n");
    s21_print_matrix(&res);
    s21_remove_matrix(&m);
    return 0;
}