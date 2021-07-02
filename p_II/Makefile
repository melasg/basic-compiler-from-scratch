# $(CC) $^ $(CCFLAGS) -lfl -o $@

# LDFLAGS="-L/usr/local/Cellar/flex/*/lib" CPPFLAGS="-I/usr/local/Cellar/flex/*/include" make -f "Makefile"

make: bison -v -d --file-prefix=mini_l mini_l.y flex mini_l.lex g++ -o parser_phase mini_l.tab.c lex.yy.c -lfl 

clean: rm -rf mini_l.o mini_l.tab.* parser