/*! @file lex.l */
%option yylineno
%{
#include <math.h>
#include <string.h>     /* for strdup                       */
#include "y.tab.h"  /* for token definitions and yylval */

// extern "C" int yylex();
extern char * yylval;
int yylex(void);
int yyerror(char *msg);
int num_lines = 1;
int num_column = 1;
%}

%option noyywrap
		// definitions!
DIGIT   [0-9]
LETTER [a-zA-Z]
ID      [a-zA-Z][a-zA-Z0-9_]*[a-zA-Z0-9]
UNDERSCORE [_]
IDENTIFIER {LETTER}+(({LETTER}|{DIGIT}|{UNDERSCORE})*({LETTER}|{DIGIT})+)*
%%
		/* misc. operators */
":="            {return ASSIGN; num_column = num_column + strlen(yytext);}
";"             {return SEMICOLON; num_column = num_column + strlen(yytext);}
":"             {return COLON; num_column = num_column + strlen(yytext);}
","             {return COMMA; num_column = num_column + strlen(yytext);}
"("             { return L_PAREN; num_column = num_column + strlen(yytext); }
")"             { return R_PAREN; num_column = num_column + strlen(yytext); }
"["             { return L_SQUARE_BRACKET; num_column = num_column + strlen(yytext); }
"]"             {return R_SQUARE_BRACKET; num_column = num_column + strlen(yytext);}
			/* idents */
"function"        {return FUNCTION; num_column = num_column + strlen(yytext);}
"beginparams"     {return BEGIN_PARAMS; num_column = num_column + strlen(yytext);}
"endparams"       {return END_PARAMS; num_column = num_column + strlen(yytext);}
"beginlocals"     {return BEGIN_LOCALS; num_column = num_column + strlen(yytext);}
"endlocals"       {return END_LOCALS; num_column = num_column + strlen(yytext);}
"beginbody"       {return BEGIN_BODY; num_column = num_column + strlen(yytext);}
"endbody"         {return END_BODY; num_column = num_column + strlen(yytext);}
"integer"         {return INTEGER; num_column = num_column + strlen(yytext);}
"array"           {return ARRAY; num_column = num_column + strlen(yytext);}
"of"              {return OF; num_column = num_column + strlen(yytext);}
"if"              {return IF; num_column = num_column + strlen(yytext);}
"then"            {return THEN; num_column = num_column + strlen(yytext);}
"endif"           {return ENDIF; num_column = num_column + strlen(yytext);}
"else"            {return ELSE; num_column = num_column + strlen(yytext);}
"while"           {return WHILE; num_column = num_column + strlen(yytext);}
"do"              {return DO; num_column = num_column + strlen(yytext);}
"for"             {return FOR; num_column = num_column + strlen(yytext);}
"beginloop"       {return BEGINLOOP; num_column = num_column + strlen(yytext);}
"endloop"         {return ENDLOOP; num_column = num_column + strlen(yytext);}
"continue"        {return CONTINUE; num_column = num_column + strlen(yytext);}
"read"            {return READ; num_column = num_column + strlen(yytext);}
"write"           {return WRITE; num_column = num_column + strlen(yytext);}
"true"            {return TRUE; num_column = num_column + strlen(yytext);}
"false"           {return FALSE; num_column = num_column + strlen(yytext);}
"and"             {return AND; num_column = num_column + strlen(yytext);}
"or"              {return OR; num_column = num_column + strlen(yytext);}
"not"             {return NOT; num_column = num_column + strlen(yytext);}
			/* comp operators */
"=="            {return EQ; num_column = num_column + strlen(yytext);}
"<>"            {return NEQ; num_column = num_column + strlen(yytext);}
"<"             {return LT; num_column = num_column + strlen(yytext);}
">"             {return GT; num_column = num_column + strlen(yytext);}
"<="            {return LTE; num_column = num_column + strlen(yytext);}
">="            {return GTE; num_column = num_column + strlen(yytext);}
		/* math stuff */
"-"             {return SUB; num_column = num_column + strlen(yytext);}
"+"             {return ADD; num_column = num_column + strlen(yytext);}
"*"             {return MULT; num_column = num_column + strlen(yytext);}
"/"             {return DIV; num_column = num_column + strlen(yytext);}
"%"             {return MOD; num_column = num_column + strlen(yytext);}
("##").*\n		{ num_lines++; num_column = 1; } // now we have comments
[ \t]+			{num_column = num_column + strlen(yytext); } //whitespace/trailing junk is ignored
"\n"			{num_lines++; num_column = 1; } //newline
{DIGIT}+		{ num_column = num_column + strlen(yytext); yylval.no_val = atoi(yytext); return NUMBER;} //externally defined, no_val is going to be called in struct
{IDENTIFIER}	{ num_column = num_column + strlen(yytext); return IDENT; }
({DIGIT}|{UNDERSCORE})+{IDENTIFIER}        { printf("Error at line %d, column %d: identifier \"%s\" must begin with a letter\n", num_lines, num_column, yytext); exit(-1); } //formerly ED_1

{IDENTIFIER}({UNDERSCORE})+        { printf("returnError at line %d, column %d: identifier \"%s\" cannot end with an underscore\n", num_lines, num_column, yytext); exit(-1); } //formerly ED_2
      .                             { printf("unrecognized symbols causing a lexical error at (x, y): (%d, %d) of symbol: %s\n", num_lines, num_column, yytext); num_column = num_column + strlen(yytext); exit(1); }
%%
