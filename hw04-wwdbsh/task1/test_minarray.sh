#!/bin/bash
# tests minarray program
FAILURES=0
PROGRAM=./minarray
INVALID_INPUT_MSG="no input numbers"

if [ ! -x "$PROGRAM" ]; then
    echo "test failed: $PROGRAM is not executable!"
    ((FAILURES++))
fi

if ! diff -u <(echo "" | $PROGRAM) <(echo $INVALID_INPUT_MSG); then
    echo "test failed on empty input"
    ((FAILURES++))
fi

if ! diff -u <(echo "1 2 5" | $PROGRAM) <(echo 1); then
    echo "test failed on 1 2 5"
    ((FAILURES++))
fi

if ! diff -u <(echo "29 74 -21 78 0" | $PROGRAM) <(echo -21); then
    echo "test failed on 29 74 -21 78 0"
    ((FAILURES++))
fi

if ! diff -u <(echo "12 12" | $PROGRAM) <(echo 12); then
    echo "test failed on 12 12"
    ((FAILURES++))
fi

if [ $FAILURES -eq 0 ]; then
    echo "test successful!"
    exit 0
else
    echo "tests detected $FAILURES failures!"
    exit 1
fi
