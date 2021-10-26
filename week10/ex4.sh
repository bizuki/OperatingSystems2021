rm -rf tmp

mkdir tmp
touch tmp/file1
touch tmp/file2
ln tmp/file1 tmp/link1

gcc ex4.c 

./a.out > ex4.txt