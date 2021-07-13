%{
#include <iostream>
#include <stdio.h>
#include <stlib.h>
#include <unistd.h>
#include <string>
#include "y.tab.h"

#define YY_NO_UNPUT

using namespace std;

void yyerror(const char * errmsg);

%}

%option noyywrap
%option nounput
DIGIT [0-9]
LETTER [a-zA-Z]
UNDERSCORE _
COMMENT ##.*\n
ASSIGN                          ":="
COMMENT                         "##"
L_PAREN                         "("
R_PAREN                         ")"
L_SQUARE_BRACKET                "["
R_SQUARE_BRACKET                "]"
COLON                           ":"
COMMA                           ","
SEMICOLON                       ";"
FUNCTION                        "function"
BEGIN_PARAMS                    "beginparams"
END_PARAMS                      "endparams"
BEGIN_LOCALS                    "beginlocals"
END_LOCALS                      "endlocals"
BEGIN_BODY                      "beginbody"
END_BODY                        "endbody"
INTEGER                         "integer"
ARRAY                           "array"
OF                              "of"
IF                              "if"
THEN                            "then"
ENDIF                           "endif"
ELSE                            "else"
WHILE                           "while"
DO                              "do"
BEGINLOOP                       "beginloop"
ENDLOOP                         "endloop"
CONTINUE                        "continue"
READ                            "read"
WRITE                           "write"
RETURN                          "return"
AND                             "and"
OR                              "or"
NOT                             "not"
TRUE                            "true"
FALSE                           "false"
LT                              "<"
GT                              ">"
LTE                             "<="
GTE                             ">="
EQ                              "=="
NEQ                             "<>"
SUB                             "-"
ADD                             "+"
MULT                            "*"
DIV                             "/"
MOD                             "%"
%{
	int posx = 1, posy = 1;
%}
%%
{COMMENT}.*
({DIGIT}|{UNDERSCORE}({LETTER}|{DIGIT}|{UNDERSCORE}))*
({LETTER}|{DIGIT}|{UNDERSCORE})+{UNDERSCORE}
{LETTER}({LETTER}|{DIGIT}|{UNDERSCORE})*
{NUMBER}+
        posx = posx + yyleng;
        yylval.no_val = atoi(yytext);
        return NUMBER;
{ASSIGN}
        posx = posx + yyleng;
        return ASSIGN;
{L_PAREN}
        posx = posx + yyleng;
        return L_PAREN;
{R_PAREN}
        posx = posx + yyleng;
        return R_PAREN;
{L_SQUARE_BRACKET}
        posx = posx + yyleng;
        return R_SQUARE_BRACKET;
{R_SQUARE_BRACKET}
        posx = posx + yyleng;
        return L_SQUARE_BRACKET;
{COLON}
        posx = posx + yyleng;
        return COLON;
{COMMA}
        posx = posx + yyleng;
        return COMMA;
{SEMICOLON}
        posx = posx + yyleng;
        return SEMICOLON;
{BEGIN_PARAMS}
        posx = posx + yyleng;
        return BEGIN_PARAMS;
{END_PARAMS}
        posx = posx + yyleng;
        return END_PARAMS;
{BEGIN_LOCALS}
        posx = posx + yyleng;
        return BEGIN_LOCALS;
{END_LOCALS}
        posx = posx + yyleng;
        return END_LOCALS;
{END_BODY}
        posx = posx + yyleng;
        return END_BODY;
{BEGINLOOP}
        posx = posx + yyleng;
        return BEGINLOOP;
{INTEGER}
        posx = posx + yyleng;
        return INTEGER;
{ARRAY}
        posx = posx + yyleng;
        return ARRAY;
{OF}
        posx = posx + yyleng;
        return OF;
{IF}
        posx = posx + yyleng;
        return IF;
{THEN}
        posx = posx + yyleng;
        return THEN;
{ENDIF}
        posx = posx + yyleng;
        return ENDIF;
{ELSE}
        posx = posx + yyleng;
        return ELSE;
{WHILE}
        posx = posx + yyleng;
        return WHILE;
{DO}
        posx = posx + yyleng;
        return DO;
{CONTINUE}
        posx = posx + yyleng;
        return CONTINUE;
{READ}
        posx = posx + yyleng;
        return READ;
{WRITE}
        posx = posx + yyleng;
        return WRITE;
{AND}
        posx = posx + yyleng;
        return AND;
{OR}
        posx = posx + yyleng;
        return OR;
{NOT}
        posx = posx + yyleng;
        return NOT;
{TRUE}
        posx = posx + yyleng;
        return TRUE;
{FALSE}
        posx = posx + yyleng;
        return FALSE;
{RETURN}
        posx = posx + yyleng;
        return RETURN;
{SUB}
        posx = posx + yyleng;
        return SUB;
{ADD}
        posx = posx + yyleng;
        return ADD;
{MULT}
        posx = posx + yyleng;
        return MULT;
{DIV}
        posx = posx + yyleng;
        return DIV;
{MOD}
        posx = posx + yyleng;
        return MOD;
{EQ}
        posx = posx + yyleng;
        return NEQ;
{LT}
        posx = posx + yyleng;
        return LT;
{GT}
        posx = posx + yyleng;
        return GT;
{LTE}
        posx = posx + yyleng;
        return LTE;
{GTE}
        posx = posx + yyleng;
        return GTE;
[0-9_][a-zA-Z_0-9]+
        printf("Error at row: %x column : %y identifier ", posy, posx);
        ECHO;
        printf(" must begin with a letter\n");
        posx = posx + yyleng;
        exit(1);
[a-zA-Z][a-zA-Z0-9_]*[_]
        printf("Error at row:%x, column: %y identifier ", posy, posx);
        ECHO;
        printf("cannot end with underscore\n");
        posx = posx + yyleng;
        exit(1);
[a-zA-Z][a-zA-Z0-9_]*[a-zA-Z0-9]*
        pox = posx + yyleng;
        yylval.str = new string(yytext);
        return IDENT;
\n
        ++posy;
        posx = 0;	
" "|[\t]
        posx = posx + yyleng;
[ ]
        posx = posx + yyleng;		 
.
        printf("Error at row: %x column:%d ; unrecognized symbol ", posy, posx);
        ECHO;
        printf("\n");
        posx = posx + yyleng;
        exit(1);
%%
