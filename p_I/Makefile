$(CC) $^ $(CCFLAGS) -lfl -o $@

LDFLAGS="-L/usr/local/Cellar/flex/*/lib" CPPFLAGS="-I/usr/local/Cellar/flex/*/include" make -f "Makefile"

make:
	flex mini_l.lex
	gcc -o lexer lex.yy.c -lfl

clean:
	rm lex.yy.c
	rm lexer