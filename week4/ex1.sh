#!/bin/bash
gcc ex1.c -o ex1.out

for (( i=0; i < 10; i++ ))
do
./ex1.out
done