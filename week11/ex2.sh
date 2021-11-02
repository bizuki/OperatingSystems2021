#!/usr/bin/bash

cp --parents -v /bin/bash lofsdisk > /dev/null 2>&1
for lib in `ldd /bin/bash | awk '{print $3}'` ; do
   if [ -f "$lib" ] ; then
        cp -v --parents "$lib" lofsdisk > /dev/null 2>&1
   fi  
done
cp --parents -v /bin/gcc lofsdisk > /dev/null 2>&1
for lib in `ldd /bin/gcc | awk '{print $3}' ` ; do
   if [ -f "$lib" ] ; then
        cp -v --parents "$lib" lofsdisk > /dev/null 2>&1
   fi  
done

mkdir -p lofsdisk/bin
mkdir -p lofsdisk/lib
mkdir -p lofsdisk/lib64

cp lofsdisk/usr/lib/* lofsdisk/lib > /dev/null 2>&1
cp lofsdisk/usr/lib64/* lofsdisk/lib64 > /dev/null 2>&1

cp ex2.c lofsdisk > /dev/null 2>&1

gcc ex2.c -o lofsdisk/ex2.out
sudo chroot lofsdisk /ex2.out > ex2.txt
lofsdisk/ex2.out >> ex2.txt
