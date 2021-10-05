#include <stdio.h> 
#include <stdlib.h>

int main() {
    printf("Please enter N\n");
    int n;
    scanf("%d", &n);

    int* array = calloc(n, sizeof(int));

    for (int i = 0; i < n; i++) {
        array[i] = i;
        printf("array[%d] = %d\n", i, array[i]);
    }

    free(array);
}