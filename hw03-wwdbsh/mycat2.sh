#!/bin/bash

# Function for displaying usage.
display_usage() {
	echo "Usage: mycat2.sh FILE . . ."
	echo "Description: concatenates FILE(s) to standard output."
	}

if [[ -e $1 ]]; then # If statement for deciding whether executing display_usage function or not
	while true
	do
        	if [ $1 ]; then
                	echo $(cat $1)
                	shift
        	else
                	break
        	fi
	done

else
	display_usage # Executing function
fi
