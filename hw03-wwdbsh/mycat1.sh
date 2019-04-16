#!/bin/bash

while true
do
	if [ $1 ]; then
		cat $1
		shift
	elif [ $2 ]; then
		cat $2
		shift
	else
		break
	fi
done
