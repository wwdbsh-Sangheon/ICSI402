#!/bin/bash

while true
do
	if [ $1 ]; then
		echo $(cat $1) # Printing contents of inputfile
		shift # shfting $1
	else
		break
	fi
done









