#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef double (*math_func_ptr)(double);

void input_array_elements(double arr[], int size) {
    printf("Введіть %d елементів масиву:\n", size);
    for (int i = 0; i < size; i++) {
        printf("Елемент [%d]: ", i);
        scanf("%lf", &arr[i]);
    }
}

double calculate_generic_value(double arr[], int size, math_func_ptr f1, math_func_ptr f2) {
    double sum_part1 = 0.0;
    double sum_part2 = 0.0;
    for (int i = 0; i < size; i++) {
        sum_part1 += arr[i] * f1(arr[i]);
        sum_part2 += arr[i] * arr[i] * f2(arr[i]);
    }
    return sum_part1 + sum_part2;
}

int main() {
    int nx, ny, nz, nq;

    printf("Введіть кількість елементів для масиву X (nx): ");
    scanf("%d", &nx);
    double x_array[nx];
    input_array_elements(x_array, nx);

    printf("Введіть кількість елементів для масиву Y (ny): ");
    scanf("%d", &ny);
    double y_array[ny];
    input_array_elements(y_array, ny);

    printf("Введіть кількість елементів для масиву Z (nz): ");
    scanf("%d", &nz);
    double z_array[nz];
    input_array_elements(z_array, nz);

    printf("Введіть кількість елементів для масиву Q (nq): ");
    scanf("%d", &nq);
    double q_array[nq];
    input_array_elements(q_array, nq);

    double val_A = calculate_generic_value(x_array, nx, sin, cos);
    double val_B = calculate_generic_value(y_array, ny, cos, sin);
    double val_C = calculate_generic_value(z_array, nz, sin, sin);
    double val_D = calculate_generic_value(q_array, nq, cos, cos);

    printf("\nРезультати обчислень:\n");
    printf("A = %.4f\n", val_A);
    printf("B = %.4f\n", val_B);
    printf("C = %.4f\n", val_C);
    printf("D = %.4f\n", val_D);

    return 0;
}