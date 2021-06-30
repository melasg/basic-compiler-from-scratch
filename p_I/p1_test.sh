#!/bin/bash
flex mini_l.lex
gcc -o lexer lex.yy.c -lfl
./a.out
cat fibonacci.min | lexer