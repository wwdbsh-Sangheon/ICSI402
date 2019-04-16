#!/bin/bash
# tests rwx2octal program
FAILURES=0
PROGRAM=./rwx2octal
INVALID_INPUT_MSG="invalid permission"

if [ ! -x "$PROGRAM" ]; then
    echo "test failed: $PROGRAM is not executable!"
    ((FAILURES++))
fi

if ! diff -u <(echo "" | $PROGRAM) <(echo $INVALID_INPUT_MSG); then
    echo "test failed on empty input"
    ((FAILURES++))
fi

if ! diff -u <(echo "r-xr-x--x" | $PROGRAM) <(echo 551); then
    echo "test failed on r-xr-x--x"
    ((FAILURES++))
fi

if ! diff -u <(echo "---------" | $PROGRAM) <(echo 000); then
    echo "test failed on r-xr-x--x"
    ((FAILURES++))
fi

if ! diff -u <(echo "----w-r--" | $PROGRAM) <(echo 024); then
    echo "test failed on ----w-r--"
    ((FAILURES++))
fi

if ! diff -u <(echo "rwxrwx" | $PROGRAM) <(echo $INVALID_INPUT_MSG); then
    echo "test failed on rwxrwx"
    ((FAILURES++))
fi

if ! diff -u <(echo "arwxrwxrw" | $PROGRAM) <(echo $INVALID_INPUT_MSG); then
    echo "test failed on arwxrwxrw"
    ((FAILURES++))
fi

if [ $FAILURES -eq 0 ]; then
    echo "test successful!"
    exit 0
else
    echo "tests detected $FAILURES failures!"
    exit 1
fi
