#! /bin/bash

sort cow | uniq
echo
sort cow | uniq -u | tee newcow
echo
echo
tail -n 5 rose >> rose2
cat rose rose2 >> newrose
cat newrose
echo 
echo "commenting"
sed -i '10,20 s;^;//;g' file.c
cat file.c
