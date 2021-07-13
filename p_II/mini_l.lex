%{
#include "y.tab.h"
	int num_lines = 1;
	int num_column = 1;
%}

%option noyywrap

DIGIT   [0-9]
LETTER [a-zA-Z]
ID      [a-zA-Z][a-zA-Z0-9_]*[a-zA-Z0-9]
UNDERSCORE [_]
IDENTIFIER {LETTER}+(({LETTER}|{DIGIT}|{UNDERSCORE})*({LETTER}|{DIGIT})+)*
%%
"function"        {return FUNCTION; num_column += yyleng;}
"beginparams"     {return BEGIN_PARAMS; num_column += yyleng;}
"endparams"       {return END_PARAMS; num_column += yyleng;}
"beginlocals"     {return BEGIN_LOCALS; num_column += yyleng;}
"endlocals"       {return END_LOCALS; num_column += yyleng;}
"beginbody"       {return BEGIN_BODY; num_column += yyleng;}
"endbody"         {return END_BODY; num_column += yyleng;}
"integer"         {return INTEGER; num_column += yyleng;}
"array"           {return ARRAY; num_column += yyleng;}
"of"              {return OF; num_column += yyleng;}
"if"              {return IF; num_column += yyleng;}
"then"            {return THEN; num_column += yyleng;}
"endif"           {return ENDIF; num_column += yyleng;}
"else"            {return ELSE; num_column += yyleng;}
"while"           {return WHILE; num_column += yyleng;}
"do"              {return DO; num_column += yyleng;}
"for"             {return FOR; num_column += yyleng;}
"beginloop"       {return BEGINLOOP; num_column += yyleng;}
"endloop"         {return ENDLOOP; num_column += yyleng;}
"continue"        {return CONTINUE; num_column += yyleng;}
"read"            {return READ; num_column += yyleng;}
"write"           {return WRITE; num_column += yyleng;}
"and"             {return AND; num_column += yyleng;}
"or"              {return OR; num_column += yyleng;}
"not"             {return NOT; num_column += yyleng;}
"true"            {return TRUE; num_column += yyleng;}
"false"           {return FALSE; num_column += yyleng;}
"=="            {return EQ; num_column += yyleng;}
"<>"            {return NEQ; num_column += yyleng;}
"<="            {return LTE; num_column += yyleng;}
">="            {return GTE; num_column += yyleng;}
":="            {return ASSIGN; num_column += yyleng;}
"-"             {return SUB; num_column += yyleng;}
"+"             {return ADD; num_column += yyleng;}
"*"             {return MULT; num_column += yyleng;}
"/"             {return DIV; num_column += yyleng;}
"%"             {return MOD; num_column += yyleng;}
"<"             {return LT; num_column += yyleng;}
">"             {return GT; num_column += yyleng;}
";"             {return SEMICOLON; num_column += yyleng;}
":"             {return COLON; num_column += yyleng;}
","             {return COMMA; num_column += yyleng;}
"("             { return L_PAREN; num_column += yyleng; }
")"             { return R_PAREN; num_column += yyleng; }
"["             { return L_SQUARE_BRACKET; num_column += yyleng; }
"]"             {return R_SQUARE_BRACKET; num_column += yyleng;}
("##").*\n		{ num_lines++; num_column = 1; }
[ \t]+			{num_column += yyleng; }
"\n"			{num_lines++; num_column = 1; }
{IDENTIFIER}	{ num_column += yyleng; return IDENT; }
{DIGIT}+		{ num_column += yyleng; yylval.no_val = atoi(yytext); return NUMBER;}
({DIGIT}|{UNDERSCORE})+{IDENTIFIER}        { printf("Error at line %d, column %d: identifier \"%s\" must begin with a letter\n", num_lines, num_column, yytext); exit(-1);}
{IDENTIFIER}({UNDERSCORE})+        {printf("returnError at line %d, column %d: identifier \"%s\" cannot end with an underscore\n", num_lines, num_column, yytext); exit(-1);}
.
%%
