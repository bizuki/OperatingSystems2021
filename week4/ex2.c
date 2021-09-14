#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    int n = 1;

    for (int i = 0; i < n; i++) {
        fork();
    }

    sleep(5);
}
/*
This result from n=5:
              │             │                 │      ├─code─┬─code─┬─bash───bash─┬─ex2.out─┬─ex2.out─┬─ex2.out─┬─ex2.out─┬─ex2.out───ex2.out
              │             │                 │      │      │      │             │         │         │         │         └─ex2.out
              │             │                 │      │      │      │             │         │         │         ├─ex2.out───ex2.out
              │             │                 │      │      │      │             │         │         │         └─ex2.out
              │             │                 │      │      │      │             │         │         ├─ex2.out─┬─ex2.out───ex2.out
              │             │                 │      │      │      │             │         │         │         └─ex2.out
              │             │                 │      │      │      │             │         │         ├─ex2.out───ex2.out
              │             │                 │      │      │      │             │         │         └─ex2.out
              │             │                 │      │      │      │             │         ├─ex2.out─┬─ex2.out─┬─ex2.out───ex2.out
              │             │                 │      │      │      │             │         │         │         └─ex2.out
              │             │                 │      │      │      │             │         │         ├─ex2.out───ex2.out
              │             │                 │      │      │      │             │         │         └─ex2.out
              │             │                 │      │      │      │             │         ├─ex2.out─┬─ex2.out───ex2.out
              │             │                 │      │      │      │             │         │         └─ex2.out
              │             │                 │      │      │      │             │         ├─ex2.out───ex2.out
              │             │                 │      │      │      │             │         └─ex2.out
This result from n=3:
              │             │                 │      ├─code─┬─code─┬─bash───bash─┬─ex2.out─┬─ex2.out─┬─ex2.out───ex2.out
              │             │                 │      │      │      │             │         │         └─ex2.out
              │             │                 │      │      │      │             │         ├─ex2.out───ex2.out
              │             │                 │      │      │      │             │         └─ex2.out
Yes result is different (it will be strange if it will be the same), in case n=3, our initial process creating 3 child processes with i increasing i, and this process is repeting on deeper levels
I think we can compare it with recursion.

*/