parse: mini_l.lex mini_l.y
	bison -vd --file-prefix=y mini_l.y
	flex mini_l.lex
	g++ -std=c++11 -g -o parser y.tab.cc lex.yy.c -lfl
clean:
	rm -f lex.yy.c y.tab.* y.output *.o parser