#include <stdio.h> 
#include <stdlib.h>
#include <string.h>

const int MB = (1 << 20);
int main() {
    int** ptrs = malloc(sizeof(int *) * 10);
    for (int i = 0; i < 10; i++) {
        ptrs[i] = malloc(MB * 10);
        memset(ptrs[i], 0, MB * 10);
        sleep(1);
    }

    for (int i = 0; i < 10; i++) {
        free(ptrs[i]);
    }
    free(ptrs);
}

// Exercise 2
/*
procs -----------memory---------- ---swap-- -----io---- -system-- ------cpu-----
 r  b   swpd   free   buff  cache   si   so    bi    bo   in   cs us sy id wa st
 3  0      0 5628904 138756 7228392    0    0    82   626  357  641  2  1 96  1  0
 0  0      0 5620076 138756 7228664    0    0     0     0 1330 2469  0  0 99  0  0
 0  0      0 5609124 138756 7228920    0    0     0   180 1662 2982  1  1 98  0  0
 0  0      0 5602496 138764 7224308    0    0     0   136 3219 5448  1  0 99  0  0
 0  0      0 5537060 138764 7244248    0    0     0   196 9941 11809  5  2 93  0  0
 0  0      0 5562936 138764 7232312    0    0     0    24 6263 10475  2  1 98  0  0
 0  0      0 5550100 138764 7235164    0    0     0     0 4025 6322  4  1 95  0  0
 0  0      0 5544044 138764 7235592    0    0     0     0 2527 4527  1  1 98  0  0
 0  0      0 5532200 138772 7233544    0    0     0   108 5233 8795  2  0 98  0  0
 1  0      0 5522624 138772 7233272    0    0     0     0 2748 4966  1  0 98  0  0

    As you can see in my programm si and so was always equal to 0, so swap wasn't used at all, so all allocated memory went to RAM,
and weren't swapped (transferred) to ssd (in my case)

*/

// Exercise 3
/*
(Check ex3.txt and ex3_memory.txt)

    Every new iteration of top we can see that amount of used physical memory is growing as well as virtual memory. It is quite obvious because
we allocating (starting to use) more memory every second, so computer giving it to us.

*/
