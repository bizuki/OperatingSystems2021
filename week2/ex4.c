#include <stdio.h>

void swap(int *a, int *b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

int main (void) {
    printf("Please input 2 integers\n");
    fflush(stdout);

    int a, b;
    scanf("%d %d", &a, &b);
    
    swap(&a, &b);
    
    printf("Your swapped integers - %d, %d", a, b);
}
