%{
        #include <stdio.h>
        #include "y.tab.h"
        int num_column = 1;
        extern double yylval;
        extern int num_lines;
%}1
DIGIT   [0-9]   yylval=atoi(yytext); 
ID      [a-zA-Z][a-zA-Z0-9_]*[a-zA-Z0-9]
CHAR    [a-zA-Z]
E_ID_1  [0-9_][a-zA-Z0-9_]* //[^{DIGIT}{ID}+\-/*()= \t\n\f\r]
E_ID_2  [a-zA-Z][a-zA-Z0-9_]*[_]
%option noyywrap
%%
{DIGIT}+        { sscanf( yytext, "%lf", &yylval ); return NUMBER ; }
function         return FUNCTION;
beginparams      return BEGIN_PARAMS;
endparams        return END_PARAMS;
beginlocals      return BEGIN_LOCALS;
endlocals        return END_LOCALS;
beginbody        return BEGIN_BODY;
endbody          return END_BODY;
integer          return INTEGER;
array            return ARRAY;
of               return OF;
if               return IF;
then             return THEN;
endif            return ENDIF;
else             return ELSE;
while            return WHILE;
do               return DO;
for              return FOR;
beginloop        return BEGINLOOP;
endloop          return ENDLOOP;
continue         return CONTINUE;
read             return READ;
write            return WRITE;
and              return AND;
or               return OR;
not              return NOT;
true             return TRUE;
false            return FALSE;
{ID}             
{CHAR}           
"=="             return EQ;
"<>"             return NEQ;
"<="             return LTS;
">="             return GTE;
":="             return ASSIGN;
"-"              return SUB;
"+"              return ADD;
"*"              return MULT;
"/"              return DIV;
"%"              return MOD;
"<"              return LT;
">"              return GT;
";"              return SEMICOLON;
":"              return COLON;
","              return COMMA;
"("              return L_PAREN;
")"             return R_PAREN;
"["              return L_SQUARE_BRACKET;
"]"             return R_SQUARE_BRACKET;
"##"[^\n]*"\n"  
[ \t\f\r ]      ; //ignore whitespace stuffs
\n              return EOLN; num_lines++;
.         { BEGIN(ERROR); yymore(); }
<<EOF>>         exit(0);
{E_ID_1}        { printf("Error at line %d, column %d: identifier \"%s\" must begin with a letter\n", num_lines, num_column, yytext); yymore(); exit(-1);}
{E_ID_2}        {yyless(yyleng-1); printf("Error at line %d, column %d: identifier \"%s\" cannot end with an underscore\n", num_lines, num_column, yytext); exit(-1);}

{ID} { return(IDENTIFIER); }
[ \t\n]+ /* blank, tab, new line: eat up whitespace */ . { return(yytext[0]); }
id { yylval.id = (char *) strdup(yytext);
                 return(IDENTIFIER);}
                  {DIGIT}+ { yylval.intval = atoi( yytext );
                 return(INT);      }
      ...
      {ID}     { yylval.id = (char *) strdup(yytext);
                 return(IDENT);    }
%%
#include <stdio.h>
#include <ctype.h>
char ∗progname;
double yylval;

main( argc, argv )
char ∗argv[];
{
  progname = argv[0];
  yyparse();
}

yyerror( s )
char ∗s;
{
    fprintf( stderr ,"%s: %s\n" , progname , s );
}
yywrap() {
       return(1);
}