%{
// #include <stdio.h>      /* For I/O                                 */
// #include <stdlib.h>     /* For malloc here and in symbol table     */
// #include <string.h>     /* For strcmp in symbol table              */
// #include "st.h"         /* Symbol Table                            */
// #include "sm.h"         /* Stack Machine                           */
// #include "codegen.h"         /* Code Generator                          */
#define YY_NO_UNPUT
// INCLUDES:
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <sstream>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

void yyerror(char *msg);
int yylex();
int yyparse(); //bison generated parser feu. prototype declared
//global vars
string complex_errors;
extern int num_column;
extern int num_lines;
extern char* yytext; 

// name, index, container
int valprm = 0;
int tmpvar = 0;
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
  int intval;
  string* idv;
}

%start Program
%token FUNCTION BEGIN_PARAMS END_PARAMS BEGIN_LOCALS END_LOCALS BEGIN_BODY END_BODY INTEGER ARRAY OF IF THEN ENDIF ELSE WHILE DO FOR BEGINLOOP ENDLOOP CONTINUE READ WRITE TRUE FALSE SEMICOLON COLON COMMA L_PAREN R_PAREN L_SQUARE_BRACKET R_SQUARE_BRACKET ASSIGN RETURN
// %token FUNCTION BEGIN_PARAMS END_PARAMS BEGIN_LOCALS END_LOCALS BEGIN_BODY END_BODY INTEGER ARRAY OF IF THEN ENDIF ELSE WHILE DO FOR BEGINLOOP ENDLOOP CONTINUE READ WRITE AND OR TRUE FALSE RETURN SEMICOLON COLON COMMA L_PAREN R_PAREN L_SQUARE_BRACKET R_SQUARE_BRACKET ASSIGN UMINUS
// %token SEMICOLON COLON COMMA L_PAREN R_PAREN L_SQUARE_BRACKET R_SQUARE_BRACKET EQ NEQ LT GT LTE GTE SUB ADD MULT DIV MOD NOT ASSIGN UMINUS
%token <intval> NUMBER
%token <idv> IDENTS
%left MULT DIV MOD ADD SUB
%left LT LTE GT GTE EQ NEQ
%right NOT
%left AND OR
%right ASSIGN
// %type<stm> Program FUNCTION

  /* ------------------------------ GRAMMAR START ----------------------------- */
%%
Program: functions
;
functions: // epsilon
        | function functions
        ;
feulabel: FUNCTION IDENTS { feutbl.push_back(*($2));
  cout << "feu " <<*($2) << endl; }
;
function: feulabel SEMICOLON beginparamsa declarations endparam BEGIN_LOCALS declarations END_LOCALS BEGIN_BODY statements END_BODY
{
    for(unsigned int j = 0; j < symtbl.size(); j++ ) {
        if (symtyp.at(j) == "INTEGER") {
            std::cout << "show symtbl at " symtbl.at(j) << std::endl; 
        } else {
            std::cout << "info: " << symtbl.at(j) << "and " << symtyp.at(j) << std::endl;
        }
    } //end for loop
    while (!prmtbl.empty()) {
            std::cout << "param = " << prmtbl.front() << ", value: " << valprm << std::endl;
            prmtbl.erase(prmtbl.begin());
            valprm++;
    } // end while loop
    for (unsigned int i = 0 ; i < irtmp.size(); i++) {
        std::cout << irtmp.at(i) << std::endl;
        }
        std::cout "endfunc" << std::endl;
        // re - initialize before ending loop
        symtbl.clear();
        symtyp.clear();
        prmtbl.clear();
        irtmp.clear();
        valprm = 0;
}
;
beginparamsa: BEGIN_PARAMS { addcheck = true; }
;
endparamsa: END_PARAMS { addcheck = false; }
;

declarations: 
        | declaration SEMICOLON declarations
;
declaration: id COLON ASSIGN
;
id: IDENTS {
    sym_table.push_back("_" +* ($1));
    if(addcheck) {
        prmtbl.push_back("_" +* ($1));
    }
}
    | IDENTS COMMA id {
        symtbl.push_back("_" +* ($1));
        symtyp.push_back("INTEGER");
    }
;
assign: INTEGER {
    symtyp.push_back("INTEGER");
}
        | ARRAY L_SQUARE_BRACKET NUMBER R_SQUARE_BRACKET OF INTEGER {
            stringstream ssm1;
            ssm1 << $3;
            string s1 = ssm1.str();
            symtyp.push_back(s);
        }
;
statements: statement SEMICOLON statements
    | statement SEMICOLON
;
statement: IDENTS ASSIGN expression {
    string var = "_" +* ($1);
    if (!sym_table(var)) {
        exit(0);
    }
    irtmp.push_back("= " + var + ", " + arop.back());
    arop.pop_back();
    } | IDENTS L_SQUARE_BRACKET expression R_SQUARE_BRACKET ASSIGN expression {
        string var = "_" +* ($1);
        if (!arr_table(var)) {
            exit(0);
        }
        string arr-res-expr = arop.back();
        arop.pop_back();
        string arr-expr = arop.back();
        arop.pop_back();
        irtmp.push_back("[]= _" +* ($1) + ", " + arr-expr + ", " + arr-res-expr);
    }
| ifexpr statements ENDIF {
    irtm.push_back(": " + ifstr.back().at(1));
    ifstr.pop_back();
} | elseif statements ENDIF {
        irtmp.push_back(": " + ifstr.back().at(2));
        ifstr.pop_back();
    } 
| whileexpr statements ENDLOOP {
    irtmp.push_back(":= " + loopstr.back().at(0));
    irtmp.push_back(": " + loopstr.back().at(2));
    loopstr.pop_back();
    }
| doexpr WHILE boolexpr {
    irtmp.push_back("?:= " + loopstr.back().at(0) + ", " + arop.back());
    arop.pop_back();
    loopstr.pop_back();
}
| READ IDENTS readmult {
    string var = "_" +* ($2);
    if (!sym_table(var)) {
        exit(0);
    }
    irtmp.push_back(".< _" +* ($2));
    while(!rseqq.empty()) {
        irtmp.push_back(rseqq.top());
        rseqq.pop();
    }
    } | READ IDENTS L_SQUARE_BRACKET expression R_SQUARE_BRACKET readmult {
        string var = "_" +* ($2);
        if (!arr_table(var)) {
            exit(0);
        }
        ssm.str("");
        ssm.clear();
        ssm << tmpvar;
        tmpvar++;
        string new_tmpvar = 't' + ssm.str();
        symtbl.push_back(new_tmpvar);
        symtyp.push_back("INTEGER");
        irtmp.push_back(".< " + new_tmpvar);
        irtmp.push_back("[]= _" +* ($2) ", " + arop.back() + ", " + new_tmpvar);
        arop.pop_back();
        while(!rseqq.empty()) {
            irtmp.push_back(rseqq.top());
            rseqq.pop();
        }
    }
| WRITE postf commast {
    while(!arop.empty()) {
        string s3 = arop.front();
        arop.erase(arop.begin());
        irtmp.push_back(".> " + s3)
    }
    arop.clear();
    }
| CONTINUE {
    if (!loopstr.empty()) {
        if(loopstr.back().at(0).at(0) == 'd') {
            irtmp.push_back(":= " + loopstr.back().at(1));
        } else {
            irtmp.push_back(":= " + loopstr.back().at(0));
        }
    }
    }
| RETURN expression {
    irtmp.push_back("ret " + arop.back());
    arop.pop_back();
    }
;

ifexpr: IF boolexpr THEN {
    lblnos++; // incrememnt lables per statement
    vector<string> tmpv;
    ssm.str("");
    ssm.clear();
    ssm << lblnos;
    string tmp1 = "if_condition_true_" + ssm.str(), tmp2 = "if_condition_false_" + ssm.str(), tmp3 = "end_if_" + ssm.str();
    tmpv.push_back(tmp1);
    tmpv.push_back(tmp2);
    tmpv.push_back(tmp3);
    ifstr.push_back(tmpv);
    irtmp.push_back("?:= " + ifstr.back().at(0) + ", " + arop.back());
    arop.pop_back();
    irtmp.push_back(":=" + ifstr.back().at(1));
    irtmp.push_back(": " + ifstr.back().at(0));
}
;
elseif: ifexpr statements ELSE {
    irtmp.push_back(":= " + ifstr.back().at(2));
    irtmp.push_back(": " + ifstr.back().at(1));
}
;
whileru: WHILE {
    lblnos++; // incrememnt lables per statement
    vector<string> tmpv;
    ssm.str("");
    ssm.clear();
    ssm << lblnos;
    string tmp1 = "while_loop_" + ssm.str(), tmp2 = "conditional_true_" + ssm.str(), tmp3 = "conditional_false_" + ssm.str();
    tmpv.push_back(tmp1);
    tmpv.push_back(tmp2);
    tmpv.push_back(tmp3);
    loopstr.push_back(tmpv);
    irtmp.push_back(": " + loopstr.back().at(0));
}
;
whileexpr: whileru boolexpr BEGINLOOP {
    irtmp.push_back("?:= " + loopstr.back().at(1) + ", " + arop.back());
    arop.pop_back();
    irtmp.push_back(":= " + loopstr.back().at(2));
    irtmp.push_back(": " + loopstr.back().at(1));
}
;
doru: DO BEGINLOOP {
    lblnos++; // incrememnt lables per statement
    vector<string> tmpv;
    ssm.str("");
    ssm.clear();
    ssm << lblnos;
    string tmp1 = "do_while_loop_" + ssm.str(), tmp2 = "do_while_conditional_check" + ssm.str();
    tmpv.push_back(tmp1);
    tmpv.push_back(tmp2);
    loopstr.push_back(tmpv);
    irtmp.push_back(": " + tmp1);
}
;
doexpr: doru statements ENDLOOP {
    irtmp.push_back(": " + loopstr.back().at(1));
}
;
readmult: COMMA IDENTS readmult {
    string var = "_" +* ($2);
    if (!sym_table(var)) {
        exit(0);
    }
    rseqq.push(".< _" +* ($2));
    }
    | COMMA IDENTS L_SQUARE_BRACKET expression R_SQUARE_BRACKET readmult {
        string var = "_" +* ($2);
        if (!arr_table(var)) {
            exit(0);
        }
        ssm.str("");
        ssm.clear();
        ssm << tmpvar;
        string new_tmpvar = 't' + ssm.str();
        tmpvar++;
        symtbl.push_back(new_tmpvar);
        symtyp.push_back("INTEGER");
        rseqq.push(".<" + new_tmpvar);
        rseqq.push("[]= _" +* ($2) + "," + arop.back() + ", " + new_tmpvar);
        arop.pop_back();
    }
    |
;
boolexpr: relationexprz
    | boolexpr OR relationexprz { 
        vector<string> tmpv;
        ssm.str("");
        ssm.clear();
        ssm << tmpvar;
        tmpvar++;
        string new_tmpvar = 't' + ssm.str();
        symtbl.push_back(new_tmpvar);
        symtyp.push_back("INTEGER");
        string op_a = arop.back();
        arop.pop_back();
        string op_b = arop.back();
        arop.pop_back();
        irtmp.push_back("|| " + new_tmpvar + ", " + op_a + ", " + op_b);
        arop.push_back(new_tmpvar);
    }
;
relationexprz: relationexpr
        | relationexprz AND relationexpr {
            ssm.str("");
            ssm.clear();
            ssm << tmpvar;
            tmpvar++;
            string new_tmpvar = 't' + ssm.str();
            symtbl.push_back(new_tmpvar);
            symtyp.push_back("INTEGER");
            string op_a = arop.back();
            arop.pop_back();
            string op_b = arop.back();
            arop.pop_back();
            irtmp.push_back("&& " + new_tmpvar + ", " + op_a + ", " + op_b);
            arop.push_back(new_tmpvar); 
        }
;
relationexpr: rexpr
    | NOT rexpr {
        ssm.str("");
        ssm.clear();
        ssm << tmpvar;
        tmpvar++;
        string new_tmpvar = 't' + ssm.str();
        symtbl.push_back(new_tmpvar);
        symtyp.push_back("INTEGER");
        string op_a = arop.back();
        arop.pop_back();
        irtmp.push_back("! " + new_tmpvar + ", " + op_a);
        arop.push_back(new_tmpvar);
    }
;
rexpr: expression EQ expression {
    ssm.str("");
    ssm.clear();
    ssm << tmpvar;
    tmpvar++;
    string new_tmpvar = 't' + ssm.str();
    symtbl.push_back(new_tmpvar);
    symtyp.push_back("INTEGER");
    string op_a = arop.back();
    arop.pop_back();
    string op_b = arop.back();
    arop.pop_back();
    irtmp.push_back("== " + new_tmpvar + ", " + op_a + ", " + op_b);
    arop.push_back(new_tmpvar);
    }
    | expression NEQ expression {
        ssm.str("");
        ssm.clear();
        ssm << tmpvar;
        tmpvar++;
        string new_tmpvar = 't' + ssm.str();
        symtbl.push_back(new_tmpvar);
        symtyp.push_back("INTEGER");
        string op_a = arop.back();
        arop.pop_back();
        string op_b = arop.back();
        arop.pop_back();
        irtmp.push_back("!= " + new_tmpvar + ", " + op_a + ", " + op_b);
        arop.push_back(new_tmpvar);
    }
    | expression LT expression {
        ssm.str("");
        ssm.clear();
        ssm << tmpvar;
        tmpvar++;
        string new_tmpvar = 't' + ssm.str();
        symtbl.push_back(new_tmpvar);
        symtyp.push_back("INTEGER");
        string op_a = arop.back();
        arop.pop_back();
        string op_b = arop.back();
        arop.pop_back();
        irtmp.push_back("< " + new_tmpvar + ", " + op_a + ", " + op_b);
        arop.push_back(new_tmpvar);
    }
    | expression GT expression {
        ssm.str("");
        ssm.clear();
        ssm << tmpvar;
        tmpvar++;
        string new_tmpvar = 't' + ssm.str();
        symtbl.push_back(new_tmpvar);
        symtyp.push_back("INTEGER");
        string op_a = arop.back();
        arop.pop_back();
        string op_b = arop.back();
        arop.pop_back();
        irtmp.push_back("> " _ new_tmpvar + ", " + op_a + ", " + op_b);
        arop.push_back(new_tmpvar);
    }
    | expression LTE expression {
        ssm.str("");
        ssm.clear();
        ssm << tmpvar;
        tmpvar++;
        string new_tmpvar = 't' + ssm.str();
        symtbl.push_back(new_tmpvar);
        symtyp.push_back("INTEGER");
        string op_a = arop.back();
        arop.pop_back();
        string op_b = arop.back();
        arop.pop_back();
        irtmp.push_back("<= " + new_tmpvar + ", " + op_a + ", " + op_b);
        arop.push_back(new_tmpvar);
    }
    | expression GTE expression {
        ssm.str("");
        ssm.clear();
        ssm << tmpvar;
        tmpvar++;
        string new_tmpvar = 't' + ssm.str();
        symtbl.push_back(new_tmpvar);
        symtyp.push_back("INTEGER");
        string op_a = arop.back();
        arop.pop_back();
        string op_b = arop.back();
        arop.pop_back();
        irtmp.push_back(">= " + new_tmpvar + ", " + op_a + ", " + op_b);
        arop.push_back(new_tmpvar);
    }
    | TRUE {
        ssm.str("");
        ssm.clear();
        ssm << tmpvar;
        tmpvar++;
        string new_tmpvar = 't' + ssm.str();
        symtbl.push_back(new_tmpvar);
        symtyp.push_back("INTEGER");
        irtmp.push_back("= " + new_tmpvar + ", 1");
        arop.push_back(new_tmpvar);
    }
    | FALSE {
        ssm.str("");
        ssm.clear();
        ssm << tmpvar;
        tmpvar++;
        string new_tmpvar = 't' + ssm.str();
        symtbl.push_back(new_tmpvar);
        symtyp.push_back("INTEGER");
        irtmp.push_back("= " + new_tmpvar + ", 0");
        arop.push_back(new_tmpvar);
    }
    | L_PAREN boolexpr R_PAREN
;
expression: mulexpr expradd
;
expradd: 
    | ADD mulexpr expradd {
        ssm.str("");
        ssm.clear();
        ssm << tmpvar;
        tmpvar++;
        string new_tmpvar = 't' + ssm.str();
        symtbl.push_back(new_tmpvar);
        symtyp.push_back("INTEGER");
        string op_a = arop.back();
        arop.pop_back();
        string op_b = arop.back();
        arop.pop_back();
        irtmp.push_back("+ " + new_tmpvar + ", " + op_a + ", " + op_b);
        arop.push_back(new_tmpvar);
    }
    | SUB mulexpr expradd {
        ssm.str("");
        ssm.clear();
        ssm << tmpvar;
        tmpvar++;
        string new_tmpvar = 't' + ssm.str();
        symtbl.push_back(new_tmpvar);
        symtyp.push_back("INTEGER");
        string op_a = arop.back();
        arop.pop_back();
        string op_b = arop.back();
        arop.pop_back();
        irtmp.push_back("- " + new_tmpvar + ", " + op_a + ", " + op_b);
        arop.push_back(new_tmpvar);
    }
;
mulexpr: term multtermz
;
multtermz: 
        | MULT term multtermz {
            ssm.str("");
            ssm.clear();
            ssm << tmpvar;
            tmpvar++;
            string new_tmpvar = 't' + ssm.str();
            symtbl.push_back(new_tmpvar);
            symtyp.push_back("INTEGER");
            string op_a = arop.back();
            arop.pop_back();
            string op_b = arop.back();
            arop.pop_back();
            irtmp.push_back("* " + new_tmpvar + ", " + op_a + ", " + op_b);
            arop.push_back(new_tmpvar);
        }
        | DIV term multtermz {
            ssm.str("");
            ssm.clear();
            ssm << tmpvar;
            tmpvar++;
            string new_tmpvar = 't' + ssm.str();
            symtbl.push_back(new_tmpvar);
            symtyp.push_back("INTEGER");
            string op_a = arop.back();
            arop.pop_back();
            string op_b = arop.back();
            arop.pop_back();
            irtmp.push_back("/ " + new_tmpvar + ", " + op_a + ", " + op_b);
            arop.push_back(new_tmpvar);
        }
        | MOD term multtermz { 
            ssm.str("");
            ssm.clear();
            ssm << tmpvar;
            tmpvar++;
            string new_tmpvar = 't' + ssm.str();
            symtbl.push_back(new_tmpvar);
            symtyp.push_back("INTEGER");
            string op_a = arop.back();
            arop.pop_back();
            string op_b = arop.back();
            arop.pop_back();
            irtmp.push_back("% " + new_tmpvar + ", " + op_a + ", " + op_b);
            arop.push_back(new_tmpvar);
        }
;
term: postf { }
    | SUB postf {
        ssm.str("");
        ssm.clear();
        ssm << tmpvar;
        tmpvar++;
        string new_tmpvar = 't' + ssm.str();
        symtbl.push_back(new_tmpvar);
        symtyp.push_back("INTEGER");
        irtmp.push_back("- " + new_tmpvar + ", 0 " + arop.back() );
        arop.pop_back();
        arop.push_back(new_tmpvar)
    }
    | IDENTS termident {
        ssm.str("");
        ssm.clear();
        ssm << tmpvar;
        tmpvar++;
        string new_tmpvar = 't' + ssm.str();
        symtbl.push_back(new_tmpvar);
        symtyp.push_back("INTEGER");
        if (!feu_table(*($1))) {
            exit(0);
        }
        irtmp.push_back("call " +* ($1) + ", " + new_tmpvar);
        arop.push_back(new_tmpvar);
    }
;
postf: var { 
    ssm.str("");
    ssm.clear();
    ssm << tmpvar;
    tmpvar++;
    string new_tmpvar = 't' + ssm.str();
    symtbl.push_back(new_tmpvar);
    symtyp.push_back("INTEGER");
    string op_a = arop.back();
    if (op_a.at(0) == '[' ) {
        irtmp.push_back("=[] " + new_tmpvar + ", " + op_a.substr(3, op_a.length()-3));
    } else {
        irtmp.push_back("= " + new_tmpvar + ", " + arop.back());
    }
    arop.pop_back();
    arop.push_back(new_tmpvar);
    }
    | NUMBERS {
        ssm.str("");
        ssm.clear();
        ssm << tmpvar;
        tmpvar++;
        string new_tmpvar = 't' + ssm.str();
        symtbl.push_back(new_tmpvar);
        symtyp.push_back("INTEGER");
        stringstream ssn;
        ssn << $1;
        irtmp.push_back("= " + new_tmpvar + ", " + ssn.str());
        arop.push_back(new_tmpvar);
    }
    | L_PAREN expression R_PAREN
;
termident: L_PAREN termexpr R_PAREN {
    while (!fparamsq.empty()) { 
        irtmp.push_back("param " + fparamsq.top());
        fparamsq.pop();
    }
    }
| L_PAREN R_PAREN { }
;
termexpr: expression { 
    fparamsq.push(arop.back());
    arop.pop_back();
}
    | expression COMMA termexpr {
        fparamsq.push(arop.back());
        arop.pop_back();
    }
;
var: IDENTS {
    string var = "_" +* ($1);
    if (!sym_table(var)) {
        exit(0);
    }
    arop.push_back(var);
    }
    | IDENTS L_SQUARE_BRACKET expression R_SQUARE_BRACKET {
        string op_a = arop.back();
        arop.pop_back();
        string var = "_" +* ($1);
        if (!arr_table(var)) {
            exit(0);
        }
        arop.push_back("[] " + var + ", " + op_a);
    }
;
commast: 
    | COMMA postf commast
;
%%

void yyerror(string s) {

}
void yyerror(char* msg){
   printf("error: %s found \'%s\' was found at line #d, column #d\n", msg, yytext, num_lines, num_column);
 }

// void yyerror(char *msg) {
//   return yyerror(string(s));
// }

bool feu_table(string){
  for (unsigned int i = 0; i < feutbl.size(); i++) {
    if (feutbl.at(i) == var) {
      return true;
    }
  }
  cerr << "semantic error5: line ( " << num_lines << "), char (" << num_column << ") : undeclared function of " << var.substr(1, var.length()-1) << endl;
  return false;
}

bool arr_table(string){
  for (unsigned int i = 0; i < symtbl.size(); i++) {
    if (symtbl.at(i) == var) {
      if (symtyp.at(i) == "INTEGER" ) {
        cout << "semantic error3: line ( " << num_lines << "), char (" << num_column << ") : incompatible datatype of " << var.substr(1, var.length()-1) << endl;
        return false;
      } // inner if
      else {
        return true; // check passed go on
      }
    } // outer iff
  } //for
  << "semantic error4: line ( " << num_lines << "), char (" << num_column << ") : undeclared variable of " << var.substr(1, var.length()-1) << endl;
  return false; 
}

bool sym_table(string){
  for (unsigned int i = 0; i < symtbl.size(); i++) {
    if(symtbl.at(i) == var) {
      if (symtyp.at(i) == "INTEGER" ) {
        return true;
      } // inner if
      else {
        cout << "semantic error1: line ( " << num_lines << "), char (" << num_column << ") : incompatible datatype of " << var.substr(1, var.length()-1) << endl;
        return false; 
      }
    } // outer iff
  } // end for
    cerr << "semantic error2: line ( " << num_lines << "), char (" << num_column << ") : incompatible datatype of " << var.substr(1, var.length()-1) << endl;
  return false;
}

int main(int argc, char **argv) {
	if ((argc >1) && (freopen(argv[1], "r", stdin) == NULL)) { //neat way to combine all prereq.s
	cerr << argv[0] << ": File " << argv[1] << " cannot be opened.\n";
	exit(1);
	} 
	yyparse();
	return 0;
}