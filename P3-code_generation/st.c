// includes
#include <stdio.h>
#include <string.h>
#include <search.h>
#include <stdlib.h>

/* Data type for links in the chain of symbols.      */
struct symrec
{
  char *name;  /* name of symbol                     */
  int offset; /* data offset */
  int type;    /* type of symbol: either VAR or FNCT */
  union {
    double var;           /* value of a VAR          */
    double (*fnctptr)();  /* value of a FNCT         */
  } value;
  struct symrec *next;    /* link field              */
};
typedef struct symrec symrec;
symrec *root = NULL;
/* The symbol table: a chain of `struct symrec'.     */
extern symrec *sym_table;

symrec *putsym();
symrec *getsym();

int symrec_compare(const void *exp1, const void *exp2) {
  return strcmp(((symrec*)exp1)->name, ((symrec*)exp2)->name);
}
void printin(const void *node, VISIT v, int level) {
  symrec *exp = (*(symrec **)node);
  if (v == postfix || v == leaf) {
    printf("Level: %d, %s: %d\n", leve, exp->name, exp->val);
  }
}

void insert(char *key, int value) {
  symrec *n_symrec;
  symrec **found;
  n_symrec = (symrec*) malloc(sizeof(symrec));
  n_symrec->name = strdup(key);
  n_symrec->val = value;
  
  printf("Inserting %s ...\n", key);
  fflush(stdout);
  found = (symrec**) tsearch(n_symrec, (void**)&root, symrec_compare);
}

symrec *insert(char *key) {
  symrec *n_symrec;
  syumrec **found;

}

symrec *lookup(char *key) {
  symrec *n_symrec;
  symrec **found;

  
}

int main() {
  
  return 0;
}