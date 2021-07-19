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
/*--------------------------------------------------------------------
 * 
 * global variables
 * 
 *------------------------------------------------------------------*/
// extern "C" int yylex();
extern char * yylval;
int posy = 0; // current line of the program
int posx = 1; //current position of the character on an x direction of the grid
/*--------------------------------------------------------------------
 * 
 * defines
 * 
 *------------------------------------------------------------------*/
 void fatal(char *, char * );
 void error(char *, char * );
 #define YY_INPUT(buf, result, max_size) {
      result = GetNextChar(buf, max_size);
      if (result <= 0)
            result = YY_NULL;
}
%}
COMMENT     "(##).*"
LETTER      [a-zA-Z]
DIGIT       [0-9]
IDENT       {LETTER}({LETTER}|{DIGIT})*
UINT        {DIGIT}{DIGIT}*
ERROR       {UINT}{IDENT}+
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

%%
      {DIGIT}+                      {
                                    BeginToken(yytext);
                                    yylval.value = atof(yytext);
                                    return VALUE;
      }
      {DIGIT}+"."{DIGIT}*          {
                                    BeginToken(yytext);
                                    yylval.value = atof(yytext);
                                    return VALUE;
      }
      {ID}                          {
                                    BeginToken(yytext);
                                    yylval.string = malloc(strlen(yytext)+1);
                                    return IDENTIFIER;
      }
      {COMMENT}                     {posx = 1;}
      // "+"                           { BeginToken(yytext); return ADD; }
      // "-"                           { BeginToken(yytext); return SUB; }
      // "*"                           { BeginToken(yytext); return MULT; }
      // "/"                           { BeginToken(yytext); return DIV; }
      // "%"                           { BeginToken(yytext); return MOD; }
      // "("                           { BeginToken(yytext); return LPAR; }
      // ")"                           { BeginToken(yytext); return RPAR; }
      // "["                           { BeginToken(yytext); return LBRACE; }
      // "]"                           { BeginToken(yytext); return RBRACE; }
      // ";"                           { BeginToken(yytext); return SEMICOLON; }
      // ":="                          { BeginToken(yytext); return ASSIGN; }
      // [ \t\r\n ]+                   { BeginToken(yytext); }
      // .                             { 
      //                               BeginToken(yytext);
      //                               return(yytext[0]); 
      }
%%
int yywrap(void) {
      return 1;
}

int main(int argc, char **argv) {
int tok;
      if (argc > 1) {
            yyin = fopen(argv[1], "r");
            if (yyin == NULL) {
                  fatal(argv[0], "File can't be opened!");
            } else {
                  yyin = stdin;
            }
      }
      while (tok = yylex() ) {
            switch (tok) {

            } //switch 
      } // while
yylex();
return 0;
}