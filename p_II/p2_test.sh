#!/bin/bash
bison -v -d --file-prefix=y mini_l.y
flex mini_l.lex
# For OSX use:
# sudo gcc -o parser y.tab.c lex.yy.c -ll -v
gcc -o parser y.tab.c lex.yy.c -lfl
cat fibonacci.min | parser
# output cat fibonacci.min processed through parser into a specific output like shown in the project phase page on the website
# cat fibonacci.min | parser < fibonacci.parse
# cat fibonacci.parse