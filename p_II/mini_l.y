%{
// C Declarations
#include <stdlib.h>
#include <stdio.h>
int yylex(void); /* Function prototype */

extern int posy, posx;

extern FILE * yyin;
extern char *yytext;
extern int yyleng;

  //error feu
void yyerror(const char * errmsg) {
  printf("ERROR: at %f symbol %g ", errmsg, yytext);
	printf("Error: On line %d, column %d: %s \n", posy, posx, errmsg);
  }
%} // header file part ends here 
// Yacc/Bison Declarations
%error-verbose          /* telling bison to give me more errors */
%union{ //struct for id/Number values
  char* id_val;
  int no_val;
}
%token <id_val> IDENT // declared token values
%token <no_val> Number
  // list all tokens in specified order of precedence from phase 2 specification:
%token Function BEGIN_PARAMS END_PARAMS BEGIN_LOCALS END_LOCALS BEGIN_BODY END_BODY INTEGER ARRAY OF IF THEN ENDIF ELSE WHILE DO FOR BEGINLOOP ENDLOOP CONTINUE READ WRITE TRUE FALSE RETURN SEMICOLON COLON COMMA
    // 9
%left ASSIGN
%left OR
%left AND
%right NOT
%left LT LTE GT GTE EQ NEQ
%left ADD SUB
%left DIV MULT MOD
    // 0
%nonassoc UMINUS
%token L_SQUARE_BRACKET R_SQUARE_BRACKET
%token L_PAREN R_PAREN

%start Program // here is the program start, bison requires it
/* 
                  GRAMMAR RULES BEGIN, CONVERTED FROM EBNF
*/
%%
Program: %empty	{ printf("Program -> EPSILON\n"); }
		| Function Program { printf("Program -> Function Program\n"); }
;
Function: Function Identifier SEMICOLON	BEGIN_PARAMS Declarations END_PARAMS BEGIN_LOCALS Declarations END_LOCALS BEGIN_BODY Statements END_BODY {printf("Function -> Function Identifier SEMICOLON BEGIN_PARAMS Declarations END_PARAMS BEGIN_LOCALS Declarations END_LOCALS BEGIN_BODY Statements END_BODY\n");}
;
Identifier: IDENT {printf("Identifier -> IDENT %s\n", $1);}
;
Identifiers: Identifier	{printf("Identifiers -> Identifier\n");}
		| Identifier COMMA Identifiers	{printf("Identifiers -> Identifier COMMA Identifiers\n");}
;
Number: Number {printf("Number -> Number %d\n", $1);}
;
Declaration: Identifiers COLON ARRAY L_SQUARE_BRACKET Number R_SQUARE_BRACKET OF INTEGER {printf("Declaration -> Identifiers COLON ARRAY L_SQUARE_BRACKET Number R_SQUARE_BRACKET OF INTEGER\n");}
		| Identifiers COLON INTEGER {printf("Declaration -> Identifiers COLON INTEGER\n");}
;
Declarations: %empty {printf("Declarations -> EPSILON\n");}
		| Declaration SEMICOLON Declarations {printf("Declarations -> Declaration SEMICOLON Declarations\n");}
;
Statements: Statement SEMICOLON Statements {printf("Statements -> Statement SEMICOLON Statements\n");}
		| Statement SEMICOLON {printf("Statements -> Statement SEMICOLON\n");}
;
Statement: var ASSIGN Expression {printf("Statement -> var ASSIGN Expression\n");}
		| IF Bool-Expr THEN Statements ENDIF {printf("Statement -> IF Bool-Expr THEN Statements ENDIF\n");}	
		| IF Bool-Expr THEN Statements ELSE Statements ENDIF {printf("Statement -> IF Bool-Expr THEN Statements ELSE Statements ENDIF\n");}
		| WHILE Bool-Expr BEGINLOOP Statements ENDLOOP {printf("Statement -> WHILE Bool-Expr BEGINLOOP Statements ENDLOOP\n");}
		| DO BEGINLOOP Statements ENDLOOP WHILE Bool-Expr {printf("Statement -> DO BEGINLOOP Statements ENDLOOP WHILE Bool-Expr\n");}
		| FOR var ASSIGN Number SEMICOLON Bool-Expr SEMICOLON var ASSIGN Expression BEGINLOOP Statements ENDLOOP {printf("FOR var ASSIGN Number SEMICOLON Bool-Expr SEMICOLON var ASSIGN Expression BEGINLOOP Statements ENDLOOP\n");}
		| READ varz {printf("Statement -> READ varz\n");}
		| WRITE varz {printf("Statement -> WRITE varz\n");}
		| CONTINUE {printf("Statement -> CONTINUE\n");}
		| RETURN Expression {printf("Statement -> RETURN Expression\n");}
;
Bool-Expr: Relation-And-Expr {printf("Bool-Expr -> Relation-And-Expr\n");}
		| Relation-And-Expr OR Bool-Expr {printf("Bool-Expr -> Relation-And-Expr OR Bool-Expr\n");}
;
Relation-And-Expr: Relation-Expr {printf("Relation-And-Expr -> Relation-Expr\n");}
		| Relation-Expr AND Relation-And-Expr {printf("Relation-And-Expr -> Relation-Expr AND Relation-And-Expr\n");}
;
Relation-Expr: Expression Comp Expression {printf("Relation-Expr -> Expression Comp Expression\n");}
		| TRUE { printf("Relation-Expr -> TRUE\n"); }
		| FALSE {printf("Relation-Expr -> FALSE\n");}
		| L_PAREN Bool-Expr R_PAREN {printf("Relation-Expr -> L_PAREN Bool-Expr R_PAREN\n");}
		| NOT Expression Comp Expression {printf("Relation-Expr -> NOT Expression Comp Expression\n");}
		| NOT TRUE {printf("Relation-Expr -> NOT TRUE\n");}
		| NOT FALSE {printf("Relation-Expr -> NOT FALSE\n");}
		| NOT L_PAREN Bool-Expr R_PAREN {printf("Relation-Expr -> NOT L_PAREN Bool-Expr R_PAREN\n");}
;
Comp: EQ { printf("Comp -> EQ\n"); }
		| NEQ { printf("Comp -> NEQ\n"); }
		| LT { printf("Comp -> LT\n"); }
		| GT { printf("Comp -> GT\n"); }
		| LTE { printf("Comp -> LTE\n"); }
		| GTE { printf("Comp -> GTE\n"); }
;
Expressions: Expression {printf("Expressions -> Expression\n");}
		| Expression COMMA Expressions {printf("Expressions -> Expression COMMA Expressions\n");}
;
Expression: Multiplicative-Expr {printf("Expression -> Multiplicative-Expr\n");}
		| Multiplicative-Expr ADD Expression {printf("Expression -> Multiplicative-Expr ADD Expression\n");}
		| Multiplicative-Expr SUB Expression {printf("Expression -> Multiplicative-Expr SUB Expression \n");}
;
Multiplicative-Expr: Term {printf("Multiplicative-Expr -> Term\n");}
		| Term MULT Multiplicative-Expr {printf("Multiplicative-Expr -> Term MULT Multiplicative-Expr\n");}
		| Term DIV Multiplicative-Expr {printf("Multiplicative-Expr -> Term DIV Multiplicative-Expr\n");}
		| Term MOD Multiplicative-Expr {printf("Multiplicative-Expr -> Term MOD Multiplicative-Expr\n");}
;
Term: var {printf("Term -> var\n");}
		| Number {printf("Term -> Number\n");}
		| L_PAREN Expression R_PAREN {printf("Term -> L_PAREN Expression R_PAREN\n");}
		| SUB var %prec UMINUS {printf("Term -> SUB var\n");}
		| SUB Number %prec UMINUS {printf("Term -> SUB Number\n");}
		| SUB L_PAREN Expression R_PAREN %prec UMINUS {printf("Term -> SUB L_PAREN Expression R_PAREN\n");}
		| Identifier L_PAREN Expressions R_PAREN {printf("Term -> Identifier L_PAREN Expressions R_PAREN\n");}
		| Identifier L_PAREN R_PAREN {printf("Term -> Identifier L_PAREN R_PAREN\n");}
;
varz: var {printf("varz -> var\n");}
		|var COMMA varz {printf("varz -> var COMMA varz\n");}
;
var: Identifier {printf("var -> Identifier\n");}
		| Identifier L_SQUARE_BRACKET Expression R_SQUARE_BRACKET {printf("var -> Identifier L_SQUARE_BRACKET Expression R_SQUARE_BRACKET\n");}

;
%%
                            /* End of grammar */
// Additional C code
int main(int argc, char **argv) {
 if (argc > 1){
   yyin = fopen(argv[1], "r");
   if (yyin == NULL){
     printf("syntax: %s filename\n", argv[0]);
   }
 }
 if (argc!=2){
   fprintf(stderr,"usage: a.out filename\n");
   exit(1);
   }
   else {
     yyin = stdin;
     }
     yyparse(argv[1]);
     return 0;
}