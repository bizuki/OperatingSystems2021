
#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
    int n = 123;

    if (fork() == 0) {
        printf("Hello from Child [%d - %d]\n", getpid(), n);
    } else {
        printf("Hello from Parent [%d - %d]\n", getpid(), n);
    }
}

/*
Surprisingly on first try i got perfect result:
    Hello from Parent [10359 - 123]
    Hello from Child [10360 - 123]
    Hello from Parent [10361 - 123]
    Hello from Child [10362 - 123]
    Hello from Parent [10363 - 123]
    Hello from Child [10364 - 123]
    Hello from Parent [10365 - 123]
    Hello from Child [10366 - 123]
    Hello from Parent [10367 - 123]
    Hello from Child [10368 - 123]
    Hello from Parent [10369 - 123]
    Hello from Child [10370 - 123]
    Hello from Parent [10371 - 123]
    Hello from Child [10372 - 123]
    Hello from Parent [10373 - 123]
    Hello from Child [10374 - 123]
    Hello from Parent [10375 - 123]
    Hello from Child [10376 - 123]
    Hello from Parent [10377 - 123]
    Hello from Child [10378 - 123]
But on second try i got this result:
    Hello from Parent [10418 - 123]
    Hello from Child [10419 - 123]
    Hello from Parent [10420 - 123]
    Hello from Child [10421 - 123]
    Hello from Child [10423 - 123]
    Hello from Parent [10422 - 123]
    Hello from Parent [10424 - 123]
    Hello from Child [10425 - 123]
    Hello from Parent [10426 - 123]
    Hello from Child [10427 - 123]
    Hello from Parent [10428 - 123]
    Hello from Child [10429 - 123]
    Hello from Child [10431 - 123]
    Hello from Parent [10430 - 123]
    Hello from Parent [10432 - 123]
    Hello from Child [10433 - 123]
    Hello from Parent [10434 - 123]
    Hello from Child [10435 - 123]
    Hello from Parent [10436 - 123]
    Hello from Child [10437 - 123]
So i can conclude that the oreder of executting of forked processes is random
*/