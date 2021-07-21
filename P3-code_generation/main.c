#include "shared_headers.h"

// defines
#define BTRUE 1
#define BFALSE 0
int yyparse(); //bison generated parser feu. prototype declared
// global var.s
int debug = 0;

// local

int main(int argc, char **argv) {
	if ((argc >1) && (freopen(argv[1], "r", stdin) == NULL)) { //neat way to combine all prereq.s
	cerr << argv[0] << ": File " << argv[1] << " cannot be opened.\n";
	exit(1);
	} 
	yyparse();
	return 0;
}