#!/bin/bash
# tests sum.c program
# Student: Sean Clarkin
FAILURES=0
PROGRAM=./sum
INVALID_INPUT_MSG="no input numbers"

if [ ! -x "$PROGRAM" ]; then
    echo "test failed: $PROGRAM is not executable!"
    ((FAILURES++))
fi

if ! diff -u <(echo "" | xargs $PROGRAM) <(echo $INVALID_INPUT_MSG); then
    echo "no input numbers"
    ((FAILURES++))
fi

if ! diff -u <(echo "1 2 5" | xargs $PROGRAM) <(echo 8); then
    echo "test failed on 1 2 5"
    ((FAILURES++))
fi

if ! diff -u <(echo "-1 -117 15 -21 -8 0" | xargs $PROGRAM) <(echo -132); then
    echo "test failed on -1 -117 15 -21 -8 0"
    ((FAILURES++))
fi

if ! diff -u <(echo "71 13 -17 11 3 -10 19 75 41 -143 79" | xargs $PROGRAM) <(echo 142); then
    echo "test failed on 71 13 -17 11 3 -10 19 75 41 -143 79"
    ((FAILURES++))
fi

if ! diff -u <(echo "29 74 -21 78 0" | xargs $PROGRAM) <(echo 160); then
    echo "test failed on 29 74 -21 78 0"
    ((FAILURES++))
fi

if [ $FAILURES -eq 0 ]; then
    echo "test successful!"
    exit 0
else
    echo "tests detected $FAILURES failures!"
    exit 1
fi
