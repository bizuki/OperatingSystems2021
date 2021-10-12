#!/bin/bash

gcc ex2.c -o ex2 > dev/null 2>&1 &

./ex2 &
vmstat 1 10