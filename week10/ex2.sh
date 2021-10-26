echo 'content' > ../week1/file.txt
link ../week1/file.txt _ex2.txt > ex2.txt
find ../ -inum 13763227 >> ex2.txt
find ../ -inum 13763227 -exec rm {} \; >> ex2.txt