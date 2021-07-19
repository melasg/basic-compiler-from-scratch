#ifndef MINICALC_H_
#define MINICALC_H_
// INCLUDES:
#include <stdio.h>
#include <math.h>
#include <ctype.h>
#include <string.h>
#include <memory.h>
#include <stdlib.h>
#include <stdarg.h>
#include "parse.h"
// global var. declarations:
extern int debug;
// lex & parse feu.'s
extern int yylex(void);
extern int yyparse(void);
extern void yyerror(char*);

// mini_lcalc.c
extern void DumpRow(void);
extern int GetNextChar(char *b, int maxbuf);
extern void BeginToken(char*);
extern void PrintError(char *s, ...);

//cmath.c
typedef struct _Variable {
    char *name;
    double value;
} Variable;
extern double ReduceAdd(double, double, YYLTYPE*);
extern double ReduceSub(double, double, YYLTYPE*);
extern double ReduceMult(double, double, YYLTYPE*);
extern double ReduceDiv(double, double, YYLTYPE*);
extern Variable *VarGet(char*, YYLTYPE);
extern void VarSetValue(Variable*, double);
extern double VarGetValue(char*, YYLTYPE*);
extern void DumpVariables(char *prefix);
#endif  /* MINICALC_H_ */