#include <stdio.h>

int swap(int *a, int *b) {
    int c = *b;
    *b = *a;
    *a = c;
}

void bubble_sort(int *array, int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (array[j] > array[j + 1]) {
                swap(&array[j], &array[j + 1]);
            }
        }
    }
}

int main() {
    int array[] = {5, 2, 3, 1, 8, 3};
    int n = sizeof(array) / sizeof(*array);
    printf("Array before sort:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");

    bubble_sort(array, n);

    printf("Array after sort:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");

}