#!/bin/bash

# waiting for other process to finish
while ! ln "ex2.txt" "ex2.txt.lock"
do
    sleep 0.01
done
#obtaining last number
current_num="$(tail -n 1 ex2.txt)"

let "current_num+=1"

echo $current_num >> ex2.txt

# releasing our file
rm ex2.txt.lock