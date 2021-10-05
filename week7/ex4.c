#include <stdlib.h>
#include <stdio.h>
#include <malloc.h>
#include <string.h>

size_t min(size_t a, size_t b) {
    if (a > b)
        return b;
    return a;
}

void* my_realloc(void* ptr, size_t new_size) {
    if (ptr == NULL) {
        return malloc(new_size);
    }

    if (new_size == 0) {
        free(ptr);
        return NULL;
    }

    size_t old_size = malloc_usable_size(ptr);

    void* new_ptr = malloc(new_size);

    memcpy(new_ptr, ptr, min(old_size, new_size));

    free(ptr);

    return new_ptr;
}


int main(){
    int n = 10;
    int* array = calloc(n, sizeof(int));
    for (int i = 0;i < 10; i++) {
        array[i] = i + 1;
        printf("%d ", array[i]);
    }

    printf("\n");
    n = 11;
    array = my_realloc(array, n * sizeof(int));

    for (int i = 0;i < 11; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
    
    n = 7;
    array = my_realloc(array, n * sizeof(int));

    for (int i = 0;i < 11; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
    
    n = 10;
    array = my_realloc(array, n * sizeof(int));
    for (int i = 0;i < 11; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}