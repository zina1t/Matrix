#include "s21_matrix.h"

int main()
{
    int a;
    matrix_t m, k;
    a = s21_create_matrix(3, 3, &m);
    if ((a == OK)) {
        printf("Matrix created\n");
    } else {
        printf("Error creating matrix\n");
    }
    fill_matrix(&m);
    s21_print_matrix(&m);

    srand(time(NULL));

    printf("\n");
    int res;
    res = s21_mult_number(&m, -1, &k);
    printf("\n");
    s21_print_matrix(&k);

    printf("sum: %d\n", res);

    s21_remove_matrix(&m);
    s21_remove_matrix(&k);  
    return 0;
}