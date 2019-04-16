#!/bin/bash
# tests permute_array program
FAILURES=0
PROGRAM=./permute_array
INVALID_INPUT_MSG="no input numbers"

if [ ! -x "$PROGRAM" ]; then
	echo "test failed: $PROGRAM is not executable!"
	((FAILURES++))
fi

if ! diff -u <(echo "" | $PROGRAM) <(echo $INVALID_INPUT_MSG); then
	echo "test failed on empty input"
	((FAILURES++))
fi

if ! diff -u <(echo "22 1 -5 5 0 -29 2" | $PROGRAM) <(echo "-5 0 -29 1 2 5 22 "); then
	echo "test failed on 22 1 -5 5 0 -29 2"
	((FAILURES++))
fi

if ! diff -u <(echo "-4 29 74 -21 78 -11" | $PROGRAM) <(echo "-4 -21 -11 29 74 78 "); then
	echo "test failed on -4 29 74 -21 78 -11"
	((FAILURES++))
fi

if ! diff -u <(echo "9 8 3 -3 -5 2 -7" | $PROGRAM) <(echo "-3 -5 -7 2 3 8 9 "); then
	echo "test failed on 9 8 3 -3 -5 2 -7"
	((FAILURES++))
fi

if [ $FAILURES -eq 0 ]; then
	echo "test successful!"
	exit 0
else
	echo "tests detected $FAILURES failures!"
	exit 1
fi