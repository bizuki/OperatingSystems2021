#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int n = 0, m = 0;

int * E,* A,** C, ** R;

void parse() {
    FILE* in = fopen("ex1.in", "r");
    int x;
    char c;
    E = NULL;
    A = NULL;

    while (fscanf(in, "%d%c", &x, &c)) {
        E = realloc(E, sizeof(int) * (m + 1));
        E[m++] = x;
        if (c == '\n') {
            break;
        }
    }

    A = malloc(sizeof(int) * m);

    while (fscanf(in, "%d%c", &x, &c)) {
        A[m] = x;
        if (c == '\n') {
            break;
        }
    }

    int* inputs = NULL;

    int size = 0;

    while (fscanf(in, "%d", &x) != EOF) {
        inputs = realloc(inputs, sizeof(int) * (size + 1));
        inputs[size++] = x;
       
    }


    if (size % (2 * m) != 0) {
        printf("invalid input\n");
    }

    n = (size) / (2 * m);

    C = malloc(sizeof(int*) * n);
    R = malloc(sizeof(int*) * n);

    for (int i = 0; i < n; i++) {
        C[i] = malloc(sizeof(int) * m);
        R[i] = malloc(sizeof(int) * m);
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0;j < m; j++) {
           C[i][j] = inputs[i * m + j];
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0;j < m; j++) {
           R[i][j] = inputs[i * m + j + n*m];
        }
    }

}

void add_arrays(int *a, int* b, int n) {
    for (int i = 0; i < n; i++) {
        a[i] += b[i];
    }
}

bool is_array_leq(int *a, int* b, int n) { //leq = less or eq
    for (int i = 0; i < n; i++) {
        if (b[i] < a[i]) {
            return false;
        }
    }
    return true;
}

int main() {
    parse();

    bool* finished = calloc(m, sizeof(bool*));

    while (true) {
        bool is_someone_finished = false;

        for (int i = 0; i < n; i++) {
            if (finished[i]) {
                continue;
            }
            // if we can satisfy resources for process we just give resources to process and wait to retrieve them back
            if (is_array_leq(R[i], A, m)) {
                add_arrays(A, C[i], m); // retrive all resources
                finished[i] = true;
                is_someone_finished = true;
            }
            
        }
        
        if (!is_someone_finished) {
            break;
        }
    }
    for (int i = 0; i < n; i++) {
        if (!finished[i]) {
            printf("State is unsafe, deadlock detected\n");
            return 0;
        }
    }
     printf("State is safe\n");
}