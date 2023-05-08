#!/bin/bash

assert(){
    expected="$1"
    input="$2"

    ./02_cc "$input" > tmp.s
    # ./02_cc > tmp.s
    cc -o tmp tmp.s
    ./tmp
    actual="$?"

    if [ "$actual" = "$expected" ]; then
        echo "$input => $actual"
    else
        echo "$input => $expected expected, but got $actual"
        exit 1
    fi
}

assert 21 "5+20-4"
assert 41 " 12 + 34 - 5 "
assert 15 "1+2+3+4+5-     10+10"

echo OK
