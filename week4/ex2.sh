#!/bin/bash
gcc ex2.c -o ex2.out
./ex2.out > /dev/null 2>&1 & 

for (( i=0; i < 5; i++ ))
do
pstree bizuki -h
sleep 1
done