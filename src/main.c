#include "s21_matrix.h"

int main()
{
    int a, b;
    matrix_t m, n, k;
    a = s21_create_matrix(3, 3, &m);
    b = s21_create_matrix(3, 3, &n);
    if ((a == OK) && (b == OK)) {
        printf("Matrix created\n");
    } else {
        printf("Error creating matrix\n");
    }
    fill_matrix(&m);
    s21_print_matrix(&m);

    srand(time(NULL));

    fill_matrix(&n);
    printf("\n");

    s21_print_matrix(&n);
    
    int res;
    res = s21_sub_matrix(&m, &n, &k);
    printf("\n");
    s21_print_matrix(&k);

    printf("sum: %d\n", res);

    s21_remove_matrix(&m);
    s21_remove_matrix(&n);
    s21_remove_matrix(&k);  
    return 0;
}