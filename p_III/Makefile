make: bison -v -d --file-prefix=mini_l mini_l.y flex mini_l.l g++ -std=c++11 -g -o mini_l_compiler lex.yy.c mini_l.tab.c -lfl

clean: rm -rf mini_l.o mini_l.tab.* mini_l_compiler lex.yy.c input.txt