#!/bin/bash
flex mini_l.lex
gcc -o lexer lex.yy.c -lfl
# For OSX use:
# sudo gcc -o lexer lex.yy.c -ll
# add -v, sudo bc of my horrible threat modeling permission issues
./a.out
cat fibonacci.min | lexer