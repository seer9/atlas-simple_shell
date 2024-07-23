#!/bin/bash bash
gcc -ggdb3 *.c -o testRun -Wall -Wextra -pedantic -std=gnu89
if ! test -f ./testRun
then
  echo "Couldn't compile."
  exit
fi
echo
./testRun
echo
if test -f ./testRun
then
  rm testRun
  exit
fi
