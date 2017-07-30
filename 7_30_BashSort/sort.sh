#########################################################################
# File Name: sort.sh
# Author: haohaosong
# mail: haohaosong@yeah.net
# Created Time: Sun 30 Jul 2017 08:31:48 PM CST
#########################################################################
#!/bin/bash

function insertSort(){
	local n=$2
	for (( i=1; i<n; ++i)); 
	do
		end=i
		let end--
		tmp=${arr[$i]}
		while [ $end -ge 0 ];
		do
			if [ $tmp -ge ${arr[$end]} ]; then
				break
			fi
			arr[$end+1]=${arr[$end]}
			let end--
		done

		arr[$end+1]=$tmp
	done
}

function shellSort(){
	local gap=$2
	local n=$2
	while [ $gap -gt 1 ];
	do
		gap=$(($gap/3+1))
		for (( i=gap; i<n; ++i)) 
		do
			local end=$((i-gap))
			local tmp=${arr[$i]}
			while [ $end -ge 0 ]
			do
				if [ ${arr[$end]} -le $tmp ];then
					break
				fi
				arr[$(($end+$gap))]=${arr[$end]}
				end=$(($end-$gap))
			done
			arr[$(($end+$gap))]=$tmp
		done
	done
}

arr=(1 3 5 7 9 2 4 6 8 0)

function PrintArr(){
	for (( i=0; i<${#arr[@]};++i))
	do 
		echo -e "${arr[$i]} \c"
	done
	echo "" 
}

shellSort arr 10
PrintArr arr 10
