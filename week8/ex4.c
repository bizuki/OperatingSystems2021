#include <stdio.h> 
#include <stdlib.h>
#include <sys/resource.h>

const int MB = (1 << 20);
int main() {
    int** ptrs = malloc(sizeof(int *) * 10);
    for (int i = 0; i < 10; i++) {
        ptrs[i] = malloc(MB * 10);
        memset(ptrs[i], 0, MB * 10);
        struct rusage usage;

        getrusage(RUSAGE_SELF, &usage);
        printf("maximum resident set size = %d\n", usage.ru_maxrss);
        printf("integral shared memory size = %d\n", usage.ru_ixrss);
        printf("integral unshared data size = %d\n", usage.ru_idrss);
        printf("integral unshared stack size = %d\n", usage.ru_isrss);
        printf("soft page faults = %d\n", usage.ru_minflt);
        printf("hard page faults = %d\n", usage.ru_majflt);
        printf("swaps = %d\n", usage.ru_nswap);
        printf("bi operations = %d\n", usage.ru_inblock);
        printf("bo operations = %d\n", usage.ru_oublock);

        printf("\n");
        sleep(1);
    }

    for (int i = 0; i < 10; i++) {
        free(ptrs[i]);
    }
    free(ptrs);
}