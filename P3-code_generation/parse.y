%{
// #include <stdio.h>      /* For I/O                                 */
// #include <stdlib.h>     /* For malloc here and in symbol table     */
// #include <string.h>     /* For strcmp in symbol table              */
// #include "st.h"         /* Symbol Table                            */
// #include "sm.h"         /* Stack Machine                           */
// #include "codegen.h"         /* Code Generator                          */
#include "shared_headers.h"

int yyerror(char* msg);
int yylex(void);

string errors;
extern int num_column;
extern int num_lines;
extern char* yytext; 

// name, index, container
int valprm = 0;
int tmpvar = 0;
int lblnos = 0;
string tmps;
bool addcheck = false; 
stringstream sm;

vector<string> fwords = { "FUNCTION", "BEGIN_PARAMS", "END_PARAMS", "BEGIN_LOCALS", "END_LOCALS", "BEGIN_BODY","END_BODY","INTEGER","ARRAY","OF","IF","THEN", "ENDIF,"ELSE","WHILE", "DO","FOR","BEGINLOOP","ENDLOOP","CONTINUE", "READ", "WRITE", "AND", "OR", "TRUE", "FALSE", "RETURN", "SEMICOLON", "COLON", "COMMA", "L_PAREN", "R_PAREN", "L_SQUARE_BRACKET", "R_SQUARE_BRACKET", "IDENT", "NUMBER", "EQ", "NEQ", "LT", "GT, "LTE", "GTE", "SUB", "ADD", "MULT", "DIV", "MOD", "NOT", "ASSIGN", "UMINUS" };
set<string> functions;
set<string> variables;
%}
%union{
  int noval;
  char* opval;
  struct semval_exp{
    char *r_index, *arr_size, *arr_name, *arr_chk;
    bool arr_code;
  } exp;
  struct semval_cmp{
    char *op_ptr;
  } cmp;
  struct semval_stmt{
    char *r_index, *arr_size, *arr_name, *arr_chk;
    bool arr_code;
  } stm;
}

%start Program
%token SEMICOLON COLON COMMA L_PAREN R_PAREN L_SQUARE_BRACKET R_SQUARE_BRACKET EQ NEQ LT GT LTE GTE SUB ADD MULT DIV MOD NOT ASSIGN UMINUS
%token FUNCTION BEGIN_PARAMS END_PARAMS BEGIN_LOCALS END_LOCALS BEGIN_BODY END_BODY INTEGER ARRAY OF IF THEN ENDIF ELSE WHILE DO FOR BEGINLOOP ENDLOOP CONTINUE READ WRITE AND OR TRUE FALSE RETURN
%token<noval> NUMBER
%token<opval> IDENT
%type<exp>
%type<cmp>
%type<stm> Program FUNCTION
%%

%%
 void yyerror(char* msg){
   printf("error: %s found \'%s\' was found at line #d, column #d\n", msg, yytext, num_lines, num_column);
 }