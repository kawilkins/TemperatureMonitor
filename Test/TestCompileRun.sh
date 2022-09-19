#!/bin/bash

FILE=tempmonTEST.cpp

cp ../src/tempmon.cpp tempmonTEST.cpp

if [ -f $FILE ]; then
    printf "\n\e[1;32mtempmonTEST.cpp created . . . \n\e[0m"
    g++ -o tempmonTEST $FILE
    printf "\n\n"
else
    printf "\n\e[1;33mtempmonTEST.cpp does not exist.\e[0m"
    printf "\nPlease try again.\n\n"
fi
