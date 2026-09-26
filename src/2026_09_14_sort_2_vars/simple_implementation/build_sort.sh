!#bin/bash

MAIN="main.cpp"
EXE="simple_sort_implementation"

if [ -f "$EXE" ]; then
    rm "$EXE"
fi

g++ -finput-charset=UTF-8 "$MAIN" -o "$EXE"

./"$EXE"
