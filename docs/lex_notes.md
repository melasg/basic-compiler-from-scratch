Notes on LEX

EXAMPLE: 
   given program lex.l      
   compile with: flex lex.l
   creates lex.yy.c to be compiled with cc or gcc
   cc lex.yy.c -o a.out

                             --------------
lex source (some.l)  ------>|lex translator|---------> lex.yy.c
                             --------------
                             ----------
lex.yy.c ------------------>|c compiler|-------------> a.out
                             ----------
                              -----
input stream --------------->|a.out|--------------> tokens
                              -----
that is, execute a.out on some data file creates tokens as output.



CONTENTS OF lex.l (or any file to be used as input to lex)

declarations
%%
translation rules
%%
auxiliary procedures


declarations - declarations of variables, identifiers that
     represent constants, and regular definitions

translation rules - 
     p1   {action1}
p's are regular expressions representing patterns
actions are written in C and indicate the "action" to be taken 
      when the "pattern" is recognized.

auxiliary procedures - those procedures needed by the lexical
      analyzer, they will be in the form of C functions.


yytext is set to hold the lexeme
yyleng is an integer telling how long the lexeme is.
yylval is a code set to return to the parser.

- denotes a range
+ 1 or more occurrences of 
* 0 or more occurrences of 
? 0 or 1 occurrences of
. all characters except new line
^ at the beginning of a pattern represents the beginning of 
      an input line.  The pattern is recognized only if it 
      appears at the beginning of the line.  Also used as a 
      negative in character class
[] represents a character class, i.e. Brackets match any of 
      the characters enclosed in the brackets. If the first 
      character following the bracket is an up arrow (^), any 
      character except the ones specified is matched. Only six 
      characters have special meaning inside a character class:
	 { Start of macro name
	 } End of macro name
	 - range of characters
	 ^ negative character class
	 " takes away special meaning of characters up to next 
               quote mark
	 \ takes away special meaning of next character
         Use \], \-, \\ and so forth, to put these into a class. 
             Since other metacharacters such as *, ?, and + are 
             not special here, the expression [*?+] matches a 
             star, question mark, or plus sign. Also, a negative 
             character class doesn't match a newline character 
             - [^a-z] actually matches anything except a lower-case 
             character or a newline. Use ([^a-z]|[\r\n]) to match
             the new line, too. Note that a negative character 
             class must match a character - ^[^a-z]$ does not 
             match an empty line. The line must have at
             least one character on it, but that character may 
             not be a lower-case letter.
$ at the end of a pattern represents the end of an input line 
      (but not the line feed character itself)


Given multiple rules, lex will match only the rule that produces the
longest match. If two rules match the same set of characters, the rule
specified first will be applied.

Do not add spaces in the pattern for ease of reading, they are taken as
part of the pattern in the regular expression.

----------------------------------------------------------------

Notes on BISON
                                 ----------------
bison source (some.y)   ------->|bison translator|-------> some.tab.c
example: given program yc.y      ----------------

compile with: bison yc.y
creates yc.tab.c to be compiled with cc or gcc

                    ----------
yc.tab.c --------->|c compiler|--------------> a.out
                    ----------

Example: cc yc.tab.c  -o a.out

                    -----
input stream ----->|a.out|--------------> message
                    -----

CONTENTS OF yc.y (or any file to be used as input to yacc)

declarations
%%
translation rules
%%
auxiliary procedures


declarations - declarations of variables, grammar rules, and
   anything that should be copied into y.tab.c exactly (those
   items in %{ ... followed by %}. This can be empty.

   If the first rule is not the start of the grammar, a start
   command indicating the start of the grammar.

   The next item is declaration of the tokens.

translation rules - 
   these are modified BNF rules with actions to be executed when
   the grammar rule is recognized.

auxiliary procedures - those procedures needed by the the parser
   they are in the form of C functions.


