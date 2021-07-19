%{
/*--------------------------------------------------------------------
 * 
 * Includes
 * 
 *------------------------------------------------------------------*/
#include <stdio.h>      /* For I/O                                 */
#include <stdlib.h>     /* For malloc here and in symbol table     */
#include <string.h>     /* For strcmp in symbol table              */
#include "st.h"         /* Symbol Table                            */
#include "sm.h"         /* Stack Machine                           */
#include "codegen.h"         /* Code Generator                          */

struct lbs {            /* For labels: if and while                */
  int for_goto;
  int for_jmp_false;
};
int err_no=0,fl=0,i=0,j=0,type[100];
char symbol[100][100],temp[100];

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
/*--------------------------------------------------------------------
 * 
 * definitions
 * 
 *------------------------------------------------------------------*/
#define  YYDEBUG 1      /* For Debugging                           */
#define YERROR_VERBOSE 1
// int yydebug=0;
void free(void *ptr);
void yyerror(char *msg);
int yylex(void);
/*--------------------------------------------------------------------
 * 
 * global variables
 * 
 *------------------------------------------------------------------*/
int errors;     /* count of error incremented in codegen.h */
static Variable *var;
%}

%defines

%union {
    double value;
    char *string;
}
%union semrec {          /* The Semantic Records */
 int     intval;        /* Integer values */
 char    *id;           /* Identifiers */
 struct  lbs *lbls      /* For backpatching */
}

// %token <intval>  NUMBER
// %token <id>      IDENTIFIER
%token <lbls>    IF WHILE
// %token SKIP THEN ELSE FI DO END
// %token INTEGER READ WRITE LET IN
// %token ASSGNOP
// %left ’-’ ’+’
// %left ’*’ ’/’

// %token ID NL SE C INT FLOAT CHAR DOUBLE
/*--------------------------------------------------------------------
 *
 * terminal-symbols
 *
 *------------------------------------------------------------------*/
%token <string>   IDENTIFIER
%token <value>    VALUE
%type <value>     expression

%token LBRACE
%token RBRACE
%token SEMICOLON
%token ASSIGN

/*
 * operator-precedence
 * top-0: -
 *     1: * /
 *     2: + -
 */
%left ADD SUB
%left MULT DIV
%left NEG

/*------------------------------------------------------------------------------
 *
 * start of grammar
 *
 *----------------------------------------------------------------------------*/
%start program
%%
/* Grammar Rules and Actions */
program
    : statement SEMICOLON program
    | statement SEMICOLON
    | statement error SEMICOLON program
      {
      yyerrok;
      }
    ;
statement
    : IDENTIFIER 
      { 
        var = VarGet($1, &@1);
      }
      ASSIGN expression
      {
        VarSetValue(var, $4);
      }
    | expression
    ;
expression
    : LBRACE expression RBRACE
      {
        $$ = $2;
      }
    | SUB expression %prec NEG
      {
        $$ = - $2;
      }
    | expression ADD expression
      {
        $$ = ReduceAdd($1, $3, &@3);
        if (  debug  )
          printf("reduce %lf + %lf => %lf\n", $1, $3, $$);
      }
    | expression SUB expression
      {
        $$ = ReduceSub($1, $3, &@3);
        if (  debug  )
          printf("reduce %lf - %lf => %lf\n", $1, $3, $$);
      }
    | expression MULT expression
      {
        $$ = ReduceMult($1, $3, &@3);
        if (  debug  )
          printf("reduce %lf * %lf => %lf\n", $1, $3, $$);
      }
    | expression DIV expression
      {
        $$ = ReduceDiv($1, $3, &@3);
        if (  debug  )
          printf("reduce %lf / %lf => %lf\n", $1, $3, $$);
      }
    | VALUE
      {
        $$ = $1;
      }
    | IDENTIFIER
      {
        $$ = VarGetValue($1, &@1);
        if (  debug  )
          printf("identifier %s => %lf\n", $1, $$);
      }
    ;

// program : LET
//             declarations
//                 IN           { gen_code( DATA, sym_table->offset );            }
//                    commands
//                 END          { gen_code( HALT, 0 ); YYACCEPT;                  }
//       ;
//       declarations : /* empty */
//          | INTEGER id_seq IDENTIFIER ’.’ { install( $3 );                      }
//       ;
//       id_seq : /* empty */
//          | id_seq IDENTIFIER ’,’  { install( $2 );                             }
// ;

// commands : /* empty */
//          | commands command ’;’
//       ;
//       command : SKIP
//          | READ IDENTIFIER   { context_check( READ_INT, $2 );                  }
//          | WRITE exp         { gen_code( WRITE_INT, 0 );                       }
//          | IDENTIFIER ASSGNOP exp { context_check( STORE, $1 );                }
// ;


%%
/* C subroutines */
extern
void yyerror(char *msg) {
    // in case sophisticated print error feu. does not work, uncomment this simpler one:
    // printf("Error '%s'\n", msg);
    PrintError(msg)
}

int yywrap(){return 1;}
main()
{
yyparse();
if(err_no==0)
{
for(j=0;j<i;j++)
{
if(type[j]==0) printf("INT-");
if(type[j]==1) printf("FLOAT-");
if(type[j]==2) printf("CHAR-");
if(type[j]==3) printf("DOUBLE-");
printf("%sn",symbol[j]);
}
}
}
void insert(int type1)
{
fl=0;
 for(j=0;j<i;j++)
if(strcmp(temp,symbol[j])==0)
{
if(type[i]==type1) printf("Redeclaration of variable");
else {printf("Multiple Declaration of Variable");err_no=1;}
fl=1;
}
if(fl==0)
{
type[i]=type1;
strcpy(symbol[i],temp);
i++;
}
}