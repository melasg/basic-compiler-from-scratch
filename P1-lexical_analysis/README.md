> ## **PHASE 1 QUICK COMMANDS**
> 1. `flex mini_l.lex`
> 2. `gcc -o lexer lex.yy.c -lfl`
> 3. ` cat fibonacci.min | lexer `

### phase I
### detailed requirements
- Write the specification for a `flex` lexical analyzer for the MINI-L language. For this phase of the project, your lexical analyzer need only output the list of tokens identified from an inputted MINI-L program.
-   Example: write the `flex` specification in a file named `mini_l.lex`.
- Run `flex` to generate the lexical analyzer for MINI-L using your specification.
  - Example: execute the command `flex mini_l.lex`. This will create a file called `lex.yy.c`in the current directory.
- Compile your MINI-L lexical analyzer. This will require the `-lfl` flag for `gcc`.
  - Example: compile your lexical analyzer into the executable lexer with the following command: `gcc -o lexer lex.yy.c -lfl`. The program lexer should now be able to convert an inputted MINI-L program into the corresponding list of tokens. 

#### Example Usage
 Suppose your lexical analyzer is in the executable named `lexer`.
 Then for the MINI-L program `fibonacci.min`, your lexical analyzer should be invoked as follows:
```shell
cat fibonacci.min | lexer
```
 The list of tokens outputted by your lexical analyzer should then appear as they do here.
 The tokens can be printed to the screen (standard out). 

# Journey to a more efficient lexical analyzer
## (no hate to @srahlwes i just want to see if i can improve his code!)
Token = lexeme
## Lexical Errors
* Misspelling of identifiers, operators, keywords, etc
* Appearance of some illegal character at beginning of token

      A character token type (or literal token) is written in the grammar using the same syntax used in C for character constants
      A terminal symbol that stands for a particular keyword in the language should be named after that keyword converted to upper case.
      All the usual escape sequences used in character literals in C can be used in Yacc/Bison as well, but you must not use the null character as a character literal because its ASCII code, zero, is the code yylex returns for end-of- input.
      Nonterminal symbols must be declared if you need to specify which data type to use for the semantic value.
      expr: expr’+’expr{$$=$1+$3;} ;
       #define YYSTYPE double

       the grammar is such that a declaration can be distinguished from a state- ment by the first token (which is true in C), then one solution which does work is to put the action after the open-brace, like this:

%token NUMBER SPACE MOD RIGHTSHIFT LEFTSHIFT SEMICOLON SIN EOLN PIVAL
%token PLUS MINUS DIV MUL POW OPENBRACKET CLOSEBRACKET UNARYMINUS
%token COS TAN ASIN ACOS ATAN FACT INC DEC LAND OR COMPLEMENT
%token NOT XOR ASSIGN IOR AND OPENREG CLOSEREG REGA ANS FIX SCI ENG
%token CONST
%left PLUS MINUS
%left MUL DIV
%left UNARYMINUS
%left LAND OR XOR NOT AND IOR
....
set_format: function_call
        | FIX OPENBRACKET expr CLOSEBRACKET
              { sprintf(format,"
.%df\n",(int)$3); $$=0; }
        | FIX { sprintf(format,"
f\n"); $$=0; }
        | SCI OPENBRACKET expr CLOSEBRACKET
              { sprintf(format,"
.%dg\n",(int)$3); $$=0; }
        | SCI { sprintf(format,"
g\n"); $$=0; }
        | ENG OPENBRACKET expr CLOSEBRACKET
              { sprintf(format,"
.%de\n",(int)$3); $$=0; }
        | ENG { sprintf(format,"
e\n"); $$=0; }
        ;
        

        ==
compound : ’{’ { prepare for local variables (); } declarations statements ’}’
| ’{’ statements ’}’
;


Another solution is to bury the action inside a nonterminal symbol which serves as a subroutine:
subroutine : /* empty */
{ prepare for local variables (); }
;
compound : subroutine
’{’ declarations statements ’}’ | subroutine
’{’ statements ’}’
;


No.
	
     [0-9]+        yylval = atoi( yytext ); return TOK_NUMBER;
     #include <ctype.h>
yylex ()
{ int c;
  /* skip white space  */
  while ((c = getchar ()) == ’ ’ || c == ’\t’)
    ;
  /* process numbers   */
  if (c == ’.’ || isdigit (c))
    {
      ungetc (c, stdin);
      scanf ("%lf", &yylval);
      return NUM;
    }
  /* return end-of-file  */
  if (c == EOF)
    return 0;
  /* return single chars */
  return c;
}
main ()     /* The ‘‘Main’’ function to make this stand-alone  */
{
yyparse (); }
#include <stdio.h>
yyerror (s)  /* Called by yyparse on error */
char *s; {
  printf ("%s\n", s);
}

PRODUCTION
SEMANTIC RULE
L \rightarrow E\textrm{ }\vdash
print(E.val)
E \rightarrow E1 + T
E.val:=E1 + T.val
E \rightarrow T
E.val:=T.val
T \rightarrow T1 * F
T.val:=T1.val * F.val
T \rightarrow F
T.val:=F.val
F \rightarrow (E)
F.val:=E.val
F \rightarrow \textrm{digit}
F.val:= digit.lexval
\vdash represents <end of line> here (usually <end of input>).