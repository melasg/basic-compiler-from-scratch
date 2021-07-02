#!/bin/bash
bison -v -d --file-prefix=y mini_l.y
flex mini_l.lex
# For OSX use:
# sudo gcc -o parser y.tab.c lex.yy.c -ll -v
gcc -o parser y.tab.c lex.yy.c -lfl
cat fibonacci.min | parser