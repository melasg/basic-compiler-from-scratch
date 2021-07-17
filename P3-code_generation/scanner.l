 %{
#include "y.tab.h"  /* for token definitions and yylval */
#include <string.h>     /* for strdup                       */
extern char * yylval;
int x=0;
%}
      DIGIT    [0-9]
      ID       [a-z][a-z0-9]*
%%
      {DIGIT}+ { yylval.intval = atoi( yytext );
                 return(INT);      }
      ...
      {ID}     { yylval.id = (char *) strdup(yytext);
                 return(IDENT);    }
      [ \t\n]+ /* eat up whitespace */
      .        { return(yytext[0]);}
"int" {x++;return INT;}
"float" {x++;return FLOAT;}
"char" {x++; return CHAR;}
"double" {x++;return DOUBLE;}
[a-z]+ {yylval=yytext;if(x>0) {return ID;} return 0;}
"," return C;
[n] return NL;
";" {x--;return SE;}
%%