%{
// C Declarations
#include <stdlib.h>
#include <stdio.h>

extern char* yytext;
extern FILE * yyin;
extern int yyleng;

int yylex(void); /* function prototype */
void yyerror(const char *msg) {
	extern int num_lines;
	extern int num_column;
	printf("error line: %d column %d, err: %s", num_lines, num_column, msg);
	}
%} // header file part ends here 
%union{ //struct for id/Numberz values
  char* id_val;
  int no_val;
}
%start Program
%token <id_val> IDENT // declared token values
%token <no_val> NUMBER
  // list all tokens in specified order of precedence from phase 2 specification:
%token FUNCTION BEGIN_PARAMS END_PARAMS BEGIN_LOCALS END_LOCALS BEGIN_BODY END_BODY INTEGER ARRAY OF IF THEN ENDIF ELSE WHILE DO FOR BEGINLOOP ENDLOOP CONTINUE READ WRITE TRUE FALSE RETURN SEMICOLON COLON COMMA
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

%%
Program:	{printf("Program -> EPSILON\n");}
		| function Program {printf("Program -> function Program\n");}
;
function: FUNCTION Identifier SEMICOLON	BEGIN_PARAMS Declarations END_PARAMS BEGIN_LOCALS Declarations END_LOCALS BEGIN_BODY Statements END_BODY {printf("function -> FUNCTION Identifier SEMICOLON BEGIN_PARAMS Declarations END_PARAMS BEGIN_LOCALS Declarations END_LOCALS BEGIN_BODY Statements END_BODY\n");}
;
Identifier: IDENT {printf("Identifier -> IDENT %s\n", $1);}
;
Identifiers: Identifier	{printf("Identifiers -> Identifier\n");}
		| Identifier COMMA Identifiers	{printf("Identifiers -> Identifier COMMA Identifiers\n");}
;
numberz: NUMBER {printf("numberz -> NUMBER %d\n", $1);}
;
Declaration: Identifiers COLON ARRAY L_SQUARE_BRACKET numberz R_SQUARE_BRACKET OF INTEGER {printf("Declaration -> Identifiers COLON ARRAY L_SQUARE_BRACKET numberz R_SQUARE_BRACKET OF INTEGER\n");}
		| Identifiers COLON INTEGER {printf("Declaration -> Identifiers COLON INTEGER\n");}
;
Declarations: {printf("Declarations -> EPSILON\n");}
		| Declaration SEMICOLON Declarations {printf("Declarations -> Declaration SEMICOLON Declarations\n");}
;
Statements: Statement SEMICOLON Statements {printf("Statements -> Statement SEMICOLON Statements\n");}
		| Statement SEMICOLON {printf("Statements -> Statement SEMICOLON\n");}
;
Statement: var ASSIGN Expression {printf("Statement -> var ASSIGN Expression\n");}
		| IF BoolExpr THEN Statements ENDIF {printf("Statement -> IF BoolExpr THEN Statements ENDIF\n");}	
		| IF BoolExpr THEN Statements ELSE Statements ENDIF {printf("Statement -> IF BoolExpr THEN Statements ELSE Statements ENDIF\n");}
		| WHILE BoolExpr BEGINLOOP Statements ENDLOOP {printf("Statement -> WHILE BoolExpr BEGINLOOP Statements ENDLOOP\n");}
		| DO BEGINLOOP Statements ENDLOOP WHILE BoolExpr {printf("Statement -> DO BEGINLOOP Statements ENDLOOP WHILE BoolExpr\n");}
		| FOR var ASSIGN numberz SEMICOLON BoolExpr SEMICOLON var ASSIGN Expression BEGINLOOP Statements ENDLOOP {printf("FOR var ASSIGN numberz SEMICOLON BoolExpr SEMICOLON var ASSIGN Expression BEGINLOOP Statements ENDLOOP\n");}
		| READ varz {printf("Statement -> READ varz\n");}
		| WRITE varz {printf("Statement -> WRITE varz\n");}
		| CONTINUE {printf("Statement -> CONTINUE\n");}
		| RETURN Expression {printf("Statement -> RETURN Expression\n");}
;
BoolExpr: RelationAndExpr {printf("BoolExpr -> RelationAndExpr\n");}
		| RelationAndExpr OR BoolExpr {printf("BoolExpr -> RelationAndExpr OR BoolExpr\n");}
;
RelationAndExpr: RelationExpr {printf("RelationAndExpr -> RelationExpr\n");}
		| RelationExpr AND RelationAndExpr {printf("RelationAndExpr -> RelationExpr AND RelationAndExpr\n");}
;
RelationExpr: Expression Comp Expression {printf("RelationExpr -> Expression Comp Expression\n");}
		| TRUE { printf("RelationExpr -> TRUE\n"); }
		| FALSE {printf("RelationExpr -> FALSE\n");}
		| L_PAREN BoolExpr R_PAREN {printf("RelationExpr -> L_PAREN BoolExpr R_PAREN\n");}
		| NOT Expression Comp Expression {printf("RelationExpr -> NOT Expression Comp Expression\n");}
		| NOT TRUE {printf("RelationExpr -> NOT TRUE\n");}
		| NOT FALSE {printf("RelationExpr -> NOT FALSE\n");}
		| NOT L_PAREN BoolExpr R_PAREN {printf("RelationExpr -> NOT L_PAREN BoolExpr R_PAREN\n");}
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
Expression: MultiplicativeExpr {printf("Expression -> MultiplicativeExpr\n");}
		| MultiplicativeExpr ADD Expression {printf("Expression -> MultiplicativeExpr ADD Expression\n");}
		| MultiplicativeExpr SUB Expression {printf("Expression -> MultiplicativeExpr SUB Expression \n");}
;
MultiplicativeExpr: Term {printf("MultiplicativeExpr -> Term\n");}
		| Term MULT MultiplicativeExpr {printf("MultiplicativeExpr -> Term MULT MultiplicativeExpr\n");}
		| Term DIV MultiplicativeExpr {printf("MultiplicativeExpr -> Term DIV MultiplicativeExpr\n");}
		| Term MOD MultiplicativeExpr {printf("MultiplicativeExpr -> Term MOD MultiplicativeExpr\n");}
;
Term: var {printf("Term -> var\n");}
		| numberz {printf("Term -> numberz\n");}
		| L_PAREN Expression R_PAREN {printf("Term -> L_PAREN Expression R_PAREN\n");}
		| SUB var %prec UMINUS {printf("Term -> SUB var\n");}
		| SUB numberz %prec UMINUS {printf("Term -> SUB numberz\n");}
		| SUB L_PAREN Expression R_PAREN %prec UMINUS {printf("Term -> SUB L_PAREN Expression R_PAREN\n");}
		| Identifier L_PAREN Expressions R_PAREN {printf("Term -> Identifier L_PAREN Expressions R_PAREN\n");}
		| Identifier L_PAREN R_PAREN {printf("Term -> Identifier L_PAREN R_PAREN\n");}
;
varz: var {printf("varz -> var\n");}
		|var COMMA varz {printf("varz -> var COMMA varz\n");}
;
var: Identifier {printf("var -> Identifier\n");}
		| Identifier L_SQUARE_BRACKET Expression R_SQUARE_BRACKET {printf("var '\045'> Identifier L_SQUARE_BRACKET Expression R_SQUARE_BRACKET\n");}

;
%%
                            /* End of grammar */
// Additional C code
int main(int argc, char **argv) {
	++argv, --argc;  /* skip over program name */
	if (argc > 1){
		yyin = fopen(argv[1], "r");
		if (yyin == NULL){
			printf("syntax: %s filename\n", argv[0]);
			}
			else {
				yyin=stdin;
				}
			}
	yyparse(); //call yylex for tokens
	return 0;
}