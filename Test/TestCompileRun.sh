#!/bin/bash

TESTFILE=tempmonTEST.cpp
SOURCE=../src/tempmon.cpp

cp $SOURCE tempmonTEST.cpp

if [ -f $TESTFILE ]; then
    g++ $TESTFILE --verbose -o tempmonTEST
    printf "\n\n\e[1;32mtempmonTEST.cpp created . . . \n\e[0m"
else
    printf "\n\e[1;31mtempmonTEST.cpp does not exist.\e[0m"
    printf "\nPlease try again.\n\n"
fi
