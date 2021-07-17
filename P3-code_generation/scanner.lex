 %{
      #include <string.h>     /* for strdup                       */
      #include "simple.tab.h" /* for token definitions and yylval */
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
      %%