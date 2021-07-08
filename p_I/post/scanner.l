    %{
        static int chars, words, lines;
    %}
    %option noyywrap
    DIGIT [0-9]
    %%
    "+"                  { return PLUS;       }
    "-"                  { return MINUS;      }
    "*"                  { return TIMES;      }
    "/"                  { return SLASH;      }
    "("                  { return LPAREN;     }
    ")"                  { return RPAREN;     }
    ";"                  { return SEMICOLON;  }
    ","                  { return COMMA;      }
    "."                  { return PERIOD;     }
    ":="                 { return BECOMES;    }
    "="                  { return EQL;        }
    "<>"                 { return NEQ;        }
    "<"                  { return LSS;        }
    ">"                  { return GTR;        }
    "<="                 { return LEQ;        }
    ">="                 { return GEQ;        }
    {digit}+             { yylval.num = atoi(yytext);
                       return NUMBER;     }
    [ \t\n\r]            /* skip whitespace */                  
    \n                   { ++chars; ++lines; }
    .                    { ++chars; }
    %%
    int main()
    {
        chars = words = lines = 0;
        yylex();
        printf("\t%d\t%d\t%d\n",lines,words,chars);
        exit(0);
    }
    int yywrap(void){return 1;}