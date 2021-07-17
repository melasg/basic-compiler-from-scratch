%{
#include <stdio.h>      /* For I/O                                 */
#include <stdlib.h>     /* For malloc here and in symbol table     */
#include <string.h>     /* For strcmp in symbol table              */
#include "ST.h"         /* Symbol Table                            */
#include "SM.h"         /* Stack Machine                           */
#include "CG.h"         /* Code Generator                          */
#define  YYDEBUG 1      /* For Debugging                           */
int  errors;            /* Error Count-incremented in CG, ckd here */
struct lbs {            /* For labels: if and while                */
  int for_goto;
  int for_jmp_false;
};

struct lbs * newlblrec() { /* Allocate space for the labels           */ 
    return  (struct lbs *) malloc(sizeof(struct lbs));
}

install ( char *sym_name ) {
    symrec *s;
    s = getsym (sym_name);
    if (s == 0)
        s = putsym (sym_name);
    else { 
        errors++;
        printf( "%s is already defined\n", sym_name );
    }
}
context_check( enum code_ops operation, char *sym_name ) { 
    symrec *identifier;
    identifier = getsym( sym_name );
    if ( identifier == 0 ) { 
        errors++;
        printf( "%s", sym_name );
        printf( "%s\n", " is an undeclared identifier"  );
        } 
        else gen_code( operation, identifier->offset );
}

%}
%union semrec {          /* The Semantic Records */
 int     intval;        /* Integer values */
 char    *id;           /* Identifiers */
 struct  lbs *lbls      /* For backpatching */
}
%start program
%token <intval>  NUMBER
%token <id>      IDENTIFIER
%token <lbls>    IF WHILE
%token SKIP THEN ELSE FI DO END
%token INTEGER READ WRITE LET IN
%token ASSGNOP
%left ’-’ ’+’
%left ’*’ ’/’
%right ’^’
%%
/* Grammar Rules and Actions */
program : LET
            declarations
                IN           { gen_code( DATA, sym_table->offset );            }
                   commands
                END          { gen_code( HALT, 0 ); YYACCEPT;                  }
      ;
      declarations : /* empty */
         | INTEGER id_seq IDENTIFIER ’.’ { install( $3 );                      }
      ;
      id_seq : /* empty */
         | id_seq IDENTIFIER ’,’  { install( $2 );                             }
;

commands : /* empty */
         | commands command ’;’
      ;
      command : SKIP
         | READ IDENTIFIER   { context_check( READ_INT, $2 );                  }
         | WRITE exp         { gen_code( WRITE_INT, 0 );                       }
         | IDENTIFIER ASSGNOP exp { context_check( STORE, $1 );                }
;


%%
/* C subroutines */