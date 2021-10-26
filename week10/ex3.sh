touch _ex3.txt
rm _ex3.txt
touch _ex3.txt

ls -l _ex3.txt > ex3.txt
chmod a-x _ex3.txt >> ex3.txt
ls -l _ex3.txt >> ex3.txt
chmod u+rwx,o+rwx _ex3.txt >> ex3.txt
ls -l _ex3.txt >> ex3.txt
chmod g=u _ex3.txt >> ex3.txt
ls -l _ex3.txt >> ex3.txt

echo '660 -> user = (110), group = (110), others = (000) -> user has read and write rights, group the same and others doesnt have any rights' >> ex3.txt
echo '775 -> user = (111), group = (111), others = (101) -> user has all rights, group the same and others have read and execute rights' >> ex3.txt
echo '777 -> user = (111), group = (111), others = (111) -> everyone have all rights' >> ex3.txt

 