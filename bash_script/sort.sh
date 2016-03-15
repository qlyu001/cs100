#!/bin/sh

nos=(4 -1 2 66 10)

echo "Original Numbers in array:"
for ((i = 0; i <=4; i++))
do
	echo ${nos[$i]}
done

for((i = 0; i <= 4; i++))
do
	for  ((j = $i; j<= 4;j++))
	do
		if [ ${nos[$i]} -gt ${nos[$j]} ]; then
			t=${nos[$i]}
			nos[$i]=${nos[$j]}
			nos[$j]=$t
		fi
	done
done

echo -e "\nSorted Numbers in Ascending Order:"
for ((i=0; i <= 4; i++ ))
do
	echo ${nos[$i]}
done
