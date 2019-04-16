#!/bin/bash

# Function for displaying usage.
display_usage(){
	echo "Usage: mycat3 [-u|-l|-t] FILE ..."
	echo "Description: concatenates FILE(s) to standard output."
} 

if [[ -e $1 || -n $1 ]]; then
	while true
        do
                if [ $1 ]; then
			if [[ -e $1 ]]; then # Printing natural contents of input file when option is not provided.
				echo $(cat $1)
				shift
			else

				if [[ $1 = "-u" ]]; then # converts inputs to uppercase
					shift
					if [[ -e $1 ]]; then
						echo $(echo $(cat $1) | tr 'a-z' 'A-Z')
					else
						display_usage
					fi	
				fi

				if [[ $1 = "-l" ]]; then # converts inputs to lowercase
					shift
					if [[ -e $1 ]]; then
						echo $(echo $(cat $1) | tr 'A-Z' 'a-z')
					else
						display_usage
					fi
				fi

				if [[ $1 = "-t" ]]; then # converts inputs to initial caps
					shift
					if [[ -e $1 ]]; then
						echo $(echo $(cat $1) | gsed 's/\b\(.\)/\u\1/g')
					else
						display_usage
					fi
				fi
			shift
	 		fi	
		 else
                        break
                fi
       	done
else
	display_usage
fi
