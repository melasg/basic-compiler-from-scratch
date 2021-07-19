#
# makefile for minil_compiler
OBJS += cminil.o mathfeu.o lex.o parse.o

# rules
# bison -vd --file-prefix=y parser.y
%.c: %.y # use gcc to compile first pre-req file of .y and generate output file named for rule matching $@ (=all)
	bison -vd -o $(@:%.o=%.d) $<

# generate one .d dependency file described by a rule ==> for each .o file.
%.c: %.l
	flex -o$(@:%.o=%.d) -i $<
# insert -lfl / -ll flag according to which machine compiles it

# dependencies generated:
cminil: parse.c lex.c parse.h $(OBJS)
	@echo gcc -o cminil $(OBJS)
	@gcc -o cminil $(OBJS)
	@echo ' '

# make source files
cminil.o: cminil.c parse.h cminil.h

mathfeu.o: mathfeu.c parse.h cminil.h

lex.o: lex.c parse.h cminil.h

parse.o: parse.c parse.h cminil.h

parse.c: parse.y

lex.c: lex.l

# clean:
# 		rm -f lex.yy.c y.tab.* y.output *.o *