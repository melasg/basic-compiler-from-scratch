%{
// C declarations
#define YYPRINT(file, type, value)   yyprint (file, type, value)
#include <cstdlib>
#include <stdlib.h>
#include <iostream>
using namespace std;
char ∗progname;
extern FILE* yyin;
int yylex(); 
%} // header file part ends here 
// Yacc/Bison declarations

%%
// Grammar rules
%error-verbose          /* telling bison to give me more errors */
%union {              /* define stack type */
  double val;       /* For returning numbers.                   */
  symrec *tptr;     /* For returning symbol-table pointers      */
  Block* block;
  Stmt* stmt;
  Exp* exp;
  Id* id;
  Oper op;
}
%token <val>  NUM        /* Simple double precision number   */
%token <tptr> VAR FNCT   /* Variable and Function            */
%type  <val>  exp

%right '='
%left '<' '>' '=' NE LE GE 
%left '-' '+'
%left '*' '/'
%left NEG     /* Negation--unary minus */
%right '^'    /* Exponentiation        */

// grammar follows
// program ::= “function” program;
// function ::= FUNCTION ident { SEMICOLON BEGIN_PARAMS dec_list END_PARAMS BEGIN_LOCALS
// dec_list END_LOCALS BEGIN_BODY sta_loop END_BODY }
input:   /* empty */
        | input line
;

line:
          '\n'
        | exp '\n'   { printf ("\t%.10g\n", $1); }
        | error '\n' { yyerrok;                  }
;

exp:      NUM                { $$ = $1;                         }
        | VAR                { $$ = $1->value.var;              }
        | VAR '=' exp        { $$ = $3; $1->value.var = $3;     }
        | FNCT '(' exp ')'   { $$ = (*($1->value.fnctptr))($3); }
        | exp '+' exp        { $$ = $1 + $3;                    }
        | exp '-' exp        { $$ = $1 - $3;                    }
        | exp '*' exp        { $$ = $1 * $3;                    }
        | exp '/' exp        { $$ = $1 / $3;                    }
        | '-' exp  %prec NEG { $$ = -$2;                        }
        | exp '^' exp        { $$ = pow ($1, $3);               }
        | '(' exp ')'        { $$ = $2;                         }
;
/* End of grammar */
%%
// Additional C code
int main(int argc, char** argv)
{
      if (argc >= 2) {
        if (!(yyin = fopen(argv[1],"r"))) {
            cerr << "Could not open input file \"" << argv[1] << "\"!" << endl;
            exit(2);
    } else {
        yylex();
    }
    // return yylex(); //in case all else fails.
}

int yylex(void)
{
  ...
  if (c == EOF)     /* Detect end of file. */
    return 0;
  ...
  if (c == '+' || c == '-')
    return c;      /* Assume token type for `+' is '+'. */
  ...
  return INT;      /* Return the type of the token. */
  ...
//   int yyerror(char * pErrorMsg);
}

yyerror (s)
     char *s;
{
  fprintf (stderr, "%s\n", s);
}

static void
yyprint (file, type, value)
     FILE *file;
     int type;
     YYSTYPE value;
{
  if (type == VAR)
    fprintf (file, " %s", value.tptr->name);
  else if (type == NUM)
    fprintf (file, " %d", value.val);
}


// main( argc, argv )
// char ∗argv[];
// {
//   progname = argv[0];
//   yyparse();
// }

// yyerror( s )
// char ∗s;
// {
//   fprintf( stderr ,"%s: %s\n" , progname , s );
// }

// errmsg1
  // "Expected operand"
  // 
// errmsg2
  // "Unbalanced parentheses (right)"
  // ignore the last ')'
// errmsg3
  // Found the start of subexpression when expecting continuation or end of current subexpression
// errmsg4
  // Found end of expression when expecting continuation operator or end of subexpression (right parenthesis)
