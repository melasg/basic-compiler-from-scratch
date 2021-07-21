#
# makefile for minil_compiler
CC	 	  = g++ -std=c++11
CFLAGS 	  = -g -Wall -pedantic -ansi -Wno-write-strings -Wconflicts-sr
OBJS 	 += parse.o lex.o minil.o
# rules
# parse -vd --file-prefix=y parser.y
%.c: %.y # use gcc to compile first pre-req file of .y and generate output file named for rule matching $@ (=all)
	bison -vd -o $(@:%.o=%.d) $<

# generate one .d dependency file described by a rule ==> for each .o file.
%.c: %.l
	flex -o$(@:%.o=%.d) -i $<
# insert -lfl / -ll flag according to which machine compiles it

# dependencies generated:
minil: parse.c lex.c parse.h $(OBJS)
	@echo gcc -o minil $(OBJS) -lfl
	@gcc -o minil $(CFLAGS) $(OBJS) -lfl
	@echo ' '

# make source files
minil.o: minil.c parse.h minil.h

lex.o: lex.c parse.h minil.h

parse.o: parse.c parse.h minil.h
parse.c: parse.y

lex.c: lex.l
# cp minil.tab.h parse.h

clean:
	rm lex.yy.c parse.c minil.tab.c minil.tab.h minil.output minil lex.c *.o *~