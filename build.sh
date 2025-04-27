#!/bin/bash

# Exit immediately if any command fails
set -e

bison -d Parser.y
flex Lexer.l

gcc -g *.c -o out.exe

./out.exe code.txt
