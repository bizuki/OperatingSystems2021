#!/bin/bash

if test -f "ex2.txt"; then 
    rm ex2.txt
fi

touch "ex2.txt"

n="$1"

if (($n % 2)); then
    bash ex2_inc.sh > /dev/null 2>&1 &
    ((n-=1))
fi



for ((i=1;i<=(($1/2));i++))
do
    bash ex2_inc.sh > /dev/null 2>&1 &
	bash ex2_inc.sh > /dev/null 2>&1 &
done
