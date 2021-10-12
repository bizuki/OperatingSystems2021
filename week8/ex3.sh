#!/bin/bash

gcc ex2.c -o ex2 > /dev/null 2>&1 &

./ex2 &
top -b -d 1 -n 10 > ex3.txt
cat ex3.txt | grep -E 'MiB Swap:|MiB Mem :' > ex3_memory.txt