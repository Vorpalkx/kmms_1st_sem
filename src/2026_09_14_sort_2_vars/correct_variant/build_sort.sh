#!/bin/bash

CPP_FILES="io.cpp sortings.cpp main.cpp"
EXE="correct_gnome_sort"
CHARSET="-finput-charset=UTF-8"

if [ -f "$EXE" ]; then
    rm "$EXE"
fi

g++ "$CHARSET" $CPP_FILES -o "$EXE"

./"$EXE"
