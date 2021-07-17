parser:
		scanner.l
		bison -vd --file-prefix=y parser.y
		flex scanner.l
		g++ -o ccompiler -x c++ y.tab.c lex.yy.c -lfl
clean:
		rm -f lex.yy.c y.tab.* y.output *.o ccompiler *.mil