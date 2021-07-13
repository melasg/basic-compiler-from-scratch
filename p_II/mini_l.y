%{
	// C Declarations
	#include <stdio.h>
	#include <stdlib.h>
	#include "string.h"
	#include "y.tab.h"
	extern const char* yytext;
	//old int counters for position from mini_l.l:
	extern int num_lines;
	extern int num_column;
	//error feu
	void yyerror(const char *msg) {
	printf("Line %d, pos %d:\n Error: %s\n", num_lines, num_column, msg);
	}
	int yylex(); //implicit function declaratioin

	extern FILE *yyin; //just in case lol
%} // header file part ends here 

%union{ //struct for id/number values
  char* id_val;
  int no_val;
}
  // list all tokens in specified order of precedence from phase 2 specification:
%start Program
%token FUNCTION BEGIN_PARAMS END_PARAMS BEGIN_LOCALS END_LOCALS BEGIN_BODY END_BODY
%token INTEGER ARRAY OF IF THEN ENDIF ELSE WHILE DO FOR BEGINLOOP ENDLOOP CONTINUE
%token READ WRITE AND OR TRUE FALSE RETURN
%token SEMICOLON COLON COMMA L_PAREN R_PAREN L_SQUARE_BRACKET R_SQUARE_BRACKET
    // 9
%token IDENT NUMBER
%left EQ NEQ LT GT LTE GTE
%left SUB ADD MULT DIV MOD
%right NOT ASSIGN UMINUS
//%nonassoc UMINUS
    // 0 precedence
%type<id_val> IDENT // declared token values
%type<no_val> NUMBER //this way it doesn't get recast/redefined

%%

Program: prog_to_feu {printf("Program -> prog_to_feu\n");}
	  ;

prog_to_feu: /* ? */ {printf("prog_to_feu -> ?\n");}
	 | function prog_to_feu	{printf("prog_to_feu -> function prog_to_feu\n");}
	 ;

function:   FUNCTION ident SEMICOLON BEGIN_PARAMS declarations END_PARAMS BEGIN_LOCALS declarations END_LOCALS BEGIN_BODY statements END_BODY {
               printf("function -> FUNCTION ident SEMICOLON "); printf("BEGIN_PARAMS declarations END_PARAMS "); printf("BEGIN_LOCALS declarations END_LOCALS "); printf("BEGIN_BODY statements END_BODY\n"); }
            ;
         
declarations:    /* ? */ {printf("declarations -> ?\n");}
        |   declaration SEMICOLON declarations{printf("declarations -> declaration SEMICOLON declarations\n");}
        |   declaration error declarations{yyerrok; yyerror("Syntax error, missing semicolon in declaration."); }
        ;

            

declaration:   identz COLON assignment {printf("declaration -> identz COLON assignment\n");}
            |  identz error assignment {yyerrok; yyerror("Syntax error, invalid declaration, missing colon.");}
               ;
            
statements:   statement SEMICOLON {printf("statements -> statement SEMICOLON\n");}
               | statement error {yyerrok; yyerror("Syntax error, missing semicolon in statement.");}
               | statements statement SEMICOLON { printf("statements -> statements statement SEMICOLON\n");}
               | statements statement error { yyerrok; yyerror("Syntax error, missing semicolon in statement."); }
               ;


assignment: INTEGER {printf("assignment -> INTEGER\n");}
         | ARRAY L_SQUARE_BRACKET NUMBER R_SQUARE_BRACKET OF INTEGER {printf("assignment -> ARRAY L_SQUARE_BRACKET NUMBER %d R_SQUARE_BRACKET OF INTEGER\n", $3);}
         | ARRAY L_SQUARE_BRACKET NUMBER R_SQUARE_BRACKET L_SQUARE_BRACKET NUMBER R_SQUARE_BRACKET OF INTEGER  
                           {printf("assignment -> ARRAY L_SQUARE_BRACKET NUMBER %d R_SQUARE_BRACKET L_SQUARE_BRACKET NUMBER %d R_SQUARE_BRACKET OF INTEGER\n", $3, $6);}
         ;

statement:  var ASSIGN expression {printf("A -> var ASSIGN expression\n");} | var error expression {yyerrok; yyerror("Syntax error, \":=\" expected.");}
         | IF bool_expr THEN statements ENDIF {printf("B -> IF bool_expr THEN statements ENDIF\n");} | IF bool_expr THEN statements ELSE statements ENDIF {printf("B -> IF bool_expr THEN statements ELSE statements ENDIF\n");}
         | WHILE bool_expr BEGINLOOP statements ENDLOOP {printf("C -> WHILE bool_expr BEGINLOOP statements ENDLOOP\n");}
         | DO BEGINLOOP statements ENDLOOP WHILE bool_expr {printf("D -> DO BEGINLOOP statements ENDLOOP WHILE bool_expr");}
         | FOR var ASSIGN NUMBER SEMICOLON bool_expr SEMICOLON var ASSIGN expression BEGINLOOP statements ENDLOOP { printf("E -> FOR var ASSIGN NUMBER %d SEMICOLON bool_expr SEMICOLON var ASSIGN expression BEGINLOOP statements ENDLOOP\n", $4); } | FOR var ASSIGN NUMBER error bool_expr SEMICOLON var ASSIGN expression BEGINLOOP statements ENDLOOP { {yyerrok; yyerror("Syntax error, missing first comma in for loop");} } | FOR var ASSIGN NUMBER SEMICOLON bool_expr error var ASSIGN expression BEGINLOOP statements ENDLOOP { {yyerrok; yyerror("Syntax error, missing second comma in for loop");} }
         | READ varz {printf("F -> READ varz\n");}
         | WRITE varz {printf("G -> WRITE varz\n");}
         | CONTINUE {printf("H -> CONTINUE\n");};
         | RETURN expression {printf("I -> RETURN expression\n");};
         ;



bool_expr: relation_and_expr bool_exprz {printf("bool_expr -> relation_and_expr bool_exprz\n");}
   ;
bool_exprz:   /* ? */ {printf("bool_exprz -> ?\n");}
               | bool_exprz OR relation_and_expr {printf("bool_exprz -> bool_exprz OR relation_and_expr\n");}
               ;

relation_and_expr: relation_expr r_a_ez {printf("relation_and_expr -> relation_expr r_a_ez\n");}
   ;
r_a_ez:   /* ? */ {printf("r_a_ez -> ?\n");}
               | r_a_ez AND relation_expr {printf("r_a_ez -> r_a_ez AND relation_expr\n");}
               ;

relation_expr: relations {printf("relation_expr -> relations\n");}
            | NOT relations {printf("relation_expr -> NOT relations\n");}
            ;
relations:  expression comp expression {printf("relations -> expression comp expression\n");}
         |  TRUE {printf("relations -> TRUE\n");}
         |  FALSE {printf("relations -> FALSE\n");}
         |  L_PAREN bool_expr R_PAREN {printf("relations -> L_PAREN bool_expr R_PAREN\n");}
         ;

comp: EQ {printf("comp -> EQ\n");}
   |  NEQ {printf("comp -> NEQ\n");}
   |  LT {printf("comp -> LT\n");}
   |  GT {printf("comp -> GT\n");}
   |  LTE {printf("comp -> LTE\n");}
   |  GTE {printf("comp -> GTE\n");}
   ;

expression: multiplicative_expr expressions {printf("expression -> multiplicative_expr expressions\n");}
         ;
expressions:  /* ? */ {printf("expressions -> ?\n");}
               |  expressions ADD multiplicative_expr {printf("expressions ->  expressions ADD multiplicative_expr\n");}
               |  expressions SUB multiplicative_expr {printf("expressions -> expressions SUB multiplicative_expr\n");}
               ;

multiplicative_expr: term multiplicative_group {printf("multiplicative_expr -> term multiplicative_group\n");}
                  ;
multiplicative_group: /* ? */ {printf("multiplicative_group -> ?\n");}
         |  multiplicative_group MULT term {printf("multiplicative_group -> multiplicative_group MULT term\n");}
         |  multiplicative_group DIV term {printf("multiplicative_group -> multiplicative_group DIV term\n");}
         |  multiplicative_group MOD term  {printf("multiplicative_group -> multiplicative_group MOD term\n");}
         ;

term: precedence {printf("term -> precedence\n");}
   |  SUB precedence %prec UMINUS {printf("term -> SUB precedence\n");}
   |  ident L_PAREN term_comma_err R_PAREN {printf("term_expression -> L_PAREN term_comma_err R_PAREN\n");}
               | L_PAREN R_PAREN {printf("term_expression -> L_PAREN R_PAREN\n");}
   ;

term_comma_err:   expression {printf("term_comma_err -> expression\n");}
         |  expression COMMA term_comma_err {printf("term_comma_err -> expression COMMA term_comma_err");}
         |  expression error term_comma_err {yyerrok; yyerror("Syntax error, missing comma between expressions.");}
         ;

precedence: var {printf("precedence -> var\n");}
      |  NUMBER {printf("precedence -> NUMBER %d\n", $1);}
      |  L_PAREN expression R_PAREN {printf("precedence -> L_PAREN expression R_PAREN\n");}
      ;


varz:  var {printf("varz -> var\n");}
         | var COMMA varz {printf("varz -> var COMMA varz \n");}
         | var varz {printf("Syntax error at line %d position %d: Missing comma in variable list.\n", num_lines, num_column);}
         ;

var:  ident {printf("var -> ident\n");}
   |  ident L_SQUARE_BRACKET expression R_SQUARE_BRACKET {printf("var -> ident L_SQUARE_BRACKET expression R_SQUARE_BRACKET\n");}
   |  ident L_SQUARE_BRACKET expression R_SQUARE_BRACKET L_SQUARE_BRACKET expression R_SQUARE_BRACKET { printf("var -> ident L_SQUARE_BRACKET expression R_SQUARE_BRACKET L_SQUARE_BRACKET expression R_SQUARE_BRACKET\n"); }
   ;

identz: ident {printf("identz -> ident\n");}
      | identz COMMA ident {printf("identz -> identz COMMA ident\n");}
      | identz error ident {yyerrok; yyerror("Syntax error, missing comma.");}
      ;

ident: IDENT {printf("ident -> IDENT %s\n", yytext);}
      ;

%%
                            /* End of grammar */
// Additional C code
int main(int argc, char **argv) {
   if (argc > 1) {
      yyin = fopen(argv[1], "r");
      if (yyin == NULL){
         printf("syntax: %s filename\n", argv[0]);
    } // else {
	// 	  yyin == stdin;
	//   }
   }
   yyparse(); // Calls yylex() for tokens.
   return 0;
}