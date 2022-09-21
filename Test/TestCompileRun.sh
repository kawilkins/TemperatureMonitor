#!/bin/bash

TESTFILE=tempmonTEST.cpp
SOURCE=../src/tempmon.cpp

if [ -f $TESTFILE ]; then
    g++ $TESTFILE --verbose -o tempmonTEST
    printf "\n\n\xE2\x9C\x94 \e[1;32mExecutable 'tempmonTEST' created . . . \n\n\e[0m"
else
    cp $SOURCE $TESTFILE
    g++ $TESTFILE --verbose -o tempmonTEST
    printf "\n\n\xE2\x9C\x94 \e[1;32mtempmonTEST.cpp created . . . \n\e[0m"
    printf "\xE2\x9C\x94 \e[1;32mExecutable 'tempmonTEST' created . . . \n\n\e[0m"
fi
