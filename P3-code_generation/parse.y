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
//global vars
string complex_errors;
extern int num_column;
extern int num_lines;
extern char* yytext; 

// name, index, container
int valprm = 0;
int tmpvar = 0; we 
int lblnos = 0;
//locals
string tmps;
bool addcheck = false; 
stringstream ssm;
// two approaches, stripping underscores from label putting each character in to_string temp count then setting up a set of two strings for feu/vars, but i'd have to create new var.s
// last attempt here, will go with first/easier approach of simple stack/vector<string> of everything by hand LOL
// vector<string> fwords = { "FUNCTION", "BEGIN_PARAMS", "END_PARAMS", "BEGIN_LOCALS", "END_LOCALS", "BEGIN_BODY","END_BODY","INTEGER","ARRAY","OF","IF","THEN", "ENDIF,"ELSE","WHILE", "DO","FOR","BEGINLOOP","ENDLOOP","CONTINUE", "READ", "WRITE", "AND", "OR", "TRUE", "FALSE", "RETURN", "SEMICOLON", "COLON", "COMMA", "L_PAREN", "R_PAREN", "L_SQUARE_BRACKET", "R_SQUARE_BRACKET", "IDENT", "NUMBER", "EQ", "NEQ", "LT", "GT, "LTE", "GTE", "SUB", "ADD", "MULT", "DIV", "MOD", "NOT", "ASSIGN", "UMINUS" };
//vector by hand:
stack <string> fparamsq, rseqq;
vector<string> feutbl, prmtbl, symtbl, symtyp, arop, irtmp;
vector<vector> <string> > if_store, loops_store;

%}
%union{
  int noval;
  string* opval;
  // struct semval_exp{
  //   char *r_index, *arr_size, *arr_name, *arr_chk;
  //   bool arr_code;
  // } exp;
  // use multiple structures to hold different tokens
  // struct semval_cmp{
  //   char *op_ptr;
  // } cmp;
  // struct semval_stmt{
  //   char *r_index, *arr_size, *arr_name, *arr_chk;
  //   bool arr_code;
  // } stm;
}

%start Program
%token FUNCTION BEGIN_PARAMS END_PARAMS BEGIN_LOCALS END_LOCALS BEGIN_BODY END_BODY INTEGER ARRAY OF IF THEN ENDIF ELSE WHILE DO FOR BEGINLOOP ENDLOOP CONTINUE READ WRITE AND OR TRUE FALSE RETURN SEMICOLON COLON COMMA L_PAREN R_PAREN L_SQUARE_BRACKET R_SQUARE_BRACKET ASSIGN UMINUS
// %token SEMICOLON COLON COMMA L_PAREN R_PAREN L_SQUARE_BRACKET R_SQUARE_BRACKET EQ NEQ LT GT LTE GTE SUB ADD MULT DIV MOD NOT ASSIGN UMINUS
%token<noval> NUMBER
%token<opval> IDENT
%left MULT DIV MOD ADD SUB
%left LT LTE GT GTE EQ NEQ
%right NOT
%left AND OR
%right ASSIGN
// %type<stm> Program FUNCTION

  /* ------------------------------ GRAMMAR START ----------------------------- */
%%

%%
void yyerror(char* msg){
   printf("error: %s found \'%s\' was found at line #d, column #d\n", msg, yytext, num_lines, num_column);
 }

// void yyerror(char *msg) {
//   return yyerror(string(s));
// }

bool feu_table(string){
  extern int num_column, num_lines;
  for (unsigned int i = 0; i < feutbl.size(); i++) {
    if (feutbl.at(i) == var) {
      return true;
    }
  }
  cerr << "semantic error";
  return false;
}

bool arr_table(string){
  extern int num_lines, num_column;
  for (unsigned int i = 0; i < symtbl.size(); i++) {
    if (symtbl.at(i) == var) {
      if (symtyp.at(i) == "INTEGER" ) {
        // @TODO: print out error message for datatype, too lazy to add this because it's cosmetic rn
        return false;
      } // inner if
      else {
        return true; // check passed go on
      }
    } // outer iff
  } //for
  // @TODO: print out error for undeclared variable of length substring
  return false; 
}

bool sym_table(string){
  extern int num_column, num_lines;
  for (unsigned int i = 0; i < symtbl.size(); i++) {
    if(symtbl.at(i) == var) {
      if (symtyp.at(i) == "INTEGER" ) {
        return true;
      } // inner if
      else {
        // @TODO: print error for incompatible datatype, return substring/length of var
        return false; 
      }
    } // outer iff
  } // end for
  // @TODO: semantic error message
  return false;
}