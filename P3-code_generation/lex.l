/*! @file lex.l */
%option yylineno
%{
/*--------------------------------------------------------------------
 * 
 * includes
 * 
 *------------------------------------------------------------------*/
#include "y.tab.h"  /* for token definitions and yylval */
#include <math.h>
#include <string.h>     /* for strdup                       */
#include "parse.tab.h"

// extern "C" int yylex();
extern char * yylval;
int yylex(void);
int yyerror(char *msg);
%}
      int posy = 0; // current line of the program
      int posx = 1; //current position of the character on an x direction of the grid
COMMENT     "##"+.*
UNDERSCORE  "_"
LETTER      [a-zA-Z]
DIGIT       [0-9]
IDENT       {LETTER}({LETTER}|{DIGIT})*

ERR1        {}
ERR2        {}

PLUS        \+
MINUS       \-
MOD         "%"
DIVIDE      \/
ASSIGN      ":="
COMMA       \,
COLON       \:
SEMICOLON   \;
LPAR        \(
RPAR        \)
LBRACE      \[
RBRACE      \]
GRE         \>
GRT         ">="
LES         \<
LST         "<="
NEQ         "<>"
EQ          "=="
WHITESPACE  [ \n\t\r ]
PERIOD      "."
TRUE        "true"
FALSE       "false"
%%
      {DIGIT}+                      { posy += yyleng; yylval.noval = atof(yytext); return NUMBER; }
      {DIGIT}+"."{DIGIT}*           {}
      {ID}                          {}
      {COMMENT}                     { posx = 1; posy += 1; }
      .                             {}
%%
// int main(int argc, char **argv) {
// int tok;
//       if (argc > 1) {
//             yyin = fopen(argv[1], "r");
//             if (yyin == NULL) {
//                   fatal(argv[0], "File can't be opened!");
//             } else {
//                   yyin = stdin;
//             }
//       }
//       while (tok = yylex() ) {
//             switch (tok) {

//             } //switch 
//       } // while
// yylex();
// return 0;
// } 