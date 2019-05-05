#! /bin/bash

echo "Program 2"
declare -A category            
IFS=';'
while read empnum cate price ; do
   category[$cate]=$((category[$cate] + 1))
done < list.txt

sum=0
for cate in ${!category[@]}; do    
  printf "Total number in %s: %d\n" $cate ${category[$cate]}
  ((sum+=${category[$cate]}))
done

printf "Total number of all departments: %d\n" $sum
echo
echo

declare -A category2                 
IFS=';'
while read name cate price ; do
  ((category2[$name]+=price))
done < list.txt

sum=0
for cate in ${!category2[@]}; do     
  printf "%s: %d\n" $cate ${category2[$cate]}
  ((sum+=${category2[$cate]}))
done

printf "Total of all departments: %d\n" $sum
