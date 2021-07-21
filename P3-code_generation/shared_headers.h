#ifndef SHARED_HEADERS_H_
#define SHARED_HEADERS_H_
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
#include <map>
#include <fstream>

#include <list>
#include <functional>
#include <regex>
#include <set>  

#include "y.tab.h"
#include "parser.tab.hh"

using namespace std;

void yyerror(char *msg);
// int yylex(void);

// all stack/semantic functions declare here to organize new code gen + checking
bool sym_table(string);
bool arr_table(string);
bool feu_table(string);

#endif // SHARED_HEADERS_H_