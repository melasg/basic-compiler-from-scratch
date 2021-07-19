// includes :
#include <stdio.h>
#include "cminil.h"

// defines
#define BTRUE 1
#define BFALSE 0

// global var.s
int debug = 0;

// local
static FILE *file;
static int eof = 0;
static int nrow = 0;
static int ncol = 0;
static int nbuf = 0;
static int lbuf = 0;
static int tok_start = 0;
static int tok_len = 0;
static int maxbuf = 255;
static char *buffer;


extern
int main (int argc, char *argv[])
{
//   init_table ();
int i;
debug = 0;
char *infile = NULL;
printf("     === CS152 SUMMER 2021 ===     \n");
  printf("  ===  MINI-L Lang. Compiler ===  \n");
  printf("           *** Melody Asghari & Shawn Rahlwes ***           \n");
  printf("  \n");
  for (i = 1; i < argc; i++) {
	  if (strcmp(argv[i], "-debug") == 0) {
		  printf("debugging turned on!\n")
		  debug = 1;
	  } else {
		  infile = argv[i];
	  }
  }
  if (infile == NULL) {
	  infile = "fibonacci.min"
  }
  printf("reading file '%s'\n", infile);
  file = fopen(infile,"r");
  if (file == NULL) {
	  printf("input file cannot be opened\n")
	  return 12;
  }
  buffer = malloc(maxbuf);
  if (buffer == NULL) {
	  printf("cannot allocate %d bytes of memory\n", maxbuf);
	  fclose(file);
	  return 12;
  }
  DumpRow();
  if (getNextLine() == 0) {
	  yyparse();
  }
  free(buffer);
  fclose(file);
  printf("final content of variables\n");
  DumpVariables(" ");
  return 0;
} //main.c

yyerror (s)  /* Called by yyparse on error */
     char *s;
{
  printf ("%s\n", s);
}

struct init
{
  char *fname;
  double (*fnct)();
};

struct init arith_fncts[]
  = {
      "sin", sin,
      "cos", cos,
      "atan", atan,
      "ln", log,
      "exp", exp,
      "sqrt", sqrt,
      0, 0
    };

/* The symbol table: a chain of `struct symrec'.  */
symrec *sym_table = (symrec *)0;

init_table ()  /* puts arithmetic functions in table. */
{
  int i;
  symrec *ptr;
  for (i = 0; arith_fncts[i].fname != 0; i++)
    {
      ptr = putsym (arith_fncts[i].fname, FNCT);
      ptr->value.fnctptr = arith_fncts[i].fnct;
    }
}

symrec *
putsym (sym_name,sym_type)
     char *sym_name;
     int sym_type;
{
  symrec *ptr;
  ptr = (symrec *) malloc (sizeof (symrec));
  ptr->name = (char *) malloc (strlen (sym_name) + 1);
  strcpy (ptr->name,sym_name);
  ptr->type = sym_type;
  ptr->value.var = 0; /* set value to 0 even if fctn.  */
  ptr->next = (struct symrec *)sym_table;
  sym_table = ptr;
  return ptr;
}

symrec *
getsym (sym_name)
     char *sym_name;
{
  symrec *ptr;
  for (ptr = sym_table; ptr != (symrec *) 0;
       ptr = (symrec *)ptr->next)
    if (strcmp (ptr->name,sym_name) == 0)
      return ptr;
  return 0;
}

#include <ctype.h>
yylex ()
{
  int c;

  /* Ignore whitespace, get first nonwhite character.  */
  while ((c = getchar ()) == ' ' || c == '\t');

  if (c == EOF)
    return 0;

  /* Char starts a number => parse the number.         */
  if (c == '.' || isdigit (c))
    {
      ungetc (c, stdin);
      scanf ("%lf", &yylval.val);
      return NUM;
    }

  /* Char starts an identifier => read the name.       */
  if (isalpha (c))
    {
      symrec *s;
      static char *symbuf = 0;
      static int length = 0;
      int i;

      /* Initially make the buffer long enough
         for a 40-character symbol name.  */
      if (length == 0)
        length = 40, symbuf = (char *)malloc (length + 1);

      i = 0;
      do
        {
          /* If buffer is full, make it bigger.        */
          if (i == length)
            {
              length *= 2;
              symbuf = (char *)realloc (symbuf, length + 1);
            }
          /* Add this character to the buffer.         */
          symbuf[i++] = c;
          /* Get another character.                    */
          c = getchar ();
        }
      while (c != EOF && isalnum (c));

      ungetc (c, stdin);
      symbuf[i] = '\0';

      s = getsym (symbuf);
      if (s == 0)
        s = putsym (symbuf, VAR);
      yylval.tptr = s;
      return s->type;
    }

  /* Any other character is a token by itself.        */
  return c;
}

/*These are global variables*/

/* The look-ahead symbol.  */
int yychar;

/* The semantic value of the look-ahead symbol.  */
YYSTYPE yylval;

int 
yyparse()
{
	int yystate; 	/* current state */
	int yyn;	/* This is an all purpose variable! One time it may represent a state, the next time, it might be a rule! */
	
	int yyresult;	/* Result of parse to be returned to the called */
	
	int yytoken=0;	/* current token */
	
	/* The state stack: This parser does not shift symbols on to the stack. Only a stack of states is maintained. */	
	
	 int yyssa[YYINITDEPTH];	/*YYINITDEPTH is 200 */
	 int *yyss = yyssa	/* Bottom of state stack */
	 int *yyssp;	/* Top of state stack */
	 
	 /* The semantic value stack: This stack grows parallel to the state stack. At each reduction, semantic values are popped 
	  * off this stack and the semantic action is executed
	  */
	  YYSTYPE yyvsa[YYINITDEPTH];
	  YYSTYPE *yyvs = yyvsa;	/* Bottom of semantic stack */
	  YYSTYPE *yyvsp;	/* Top of semantic stack */
	
	  /* POP the state and semantic stacks by N symbols - useful for reduce actions */
	  #define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))
	  
	  
	  int yylen = 0;	/* This variable is used in reduce actions to store the length of RHS of a rule; */
	  
	  /* Ok done declaring variables. Set the ball rolling */
	  
	  yystate = 0;	/* Initial state */
	  yychar = YYEMPTY /* YYEMPTY is -2 */
	  
	  yyssp = yyss; 	/* Top = bottom for state stack */
	  yyvsp = yyvs;	/* Same for semantic stack */
	  
	  goto yysetstate; 	/* Well, gotos are used for extracting maximum performance. */
	  
	  
	  /* Each label can be thought of as a function */
	  
	  yynewstate:  /* Push a new state on the stack */
	  
	  		yyssp ++;	/*Just increment the stack top; actual 'pushing' will happen in yysetstate */
	  		
	  		
	  yysetstate:
	  		
	  		*yyssp = yystate;	/* Ok pushed state on state stack top */
	  		
	  		goto yybackup;	/* This is where you will find some action */
	  		
	  		
	  yybackup:	/* The main parsing code starts here */
	  	
	  		yyn = yypact[yystate];	/* Refer to what yypact is saying about the current state */
	  		
	  		if ( yyn == YYPACT_NINF) 	/* If negative infinity its time for a default reduction */
	  		
	  			goto yydefault;	/* This label implements default reductions; see below */
	  			
	  		
	  		/* Check if we have a look-ahead token ready. This is LALR(1) parsing */
	  		
	  		if (yychar == YYEMPTY)
	  			
	  			yychar = YYLEX; /* Macro YYLEX is defined as yylex() */
	  				
	  		if (yychar <= YYEOF) 	/* YYEOF is 0 - the token returned by lexer at end of input */
	  			
	  			yychar = yytoken = YYEOF; /* set all to EOF */
	  				
	  		else
	  		
	  			yytoken = yytranslate[yychar];	/* Translate the lexer token into internal symbol number */
	  				
	  		
	  		/* Now we have a look-ahead token. Let the party begin ! */
	  		
	  		
	  		yyn = yyn + yytoken;	/* This is yypact[yystate] + yytoken */
	  		
	  		
	  		/* Observe this check carefully. We are checking that yyn is within the bounds of yytable
	  		 * and also if yycheck contains the current token number.
	  		 */
	  		if ( yyn < 0 || YYLAST < yyn  || yycheck[yyn] != yytoken )	/* YYLAST is the highest index in yytable */
	  			  			 
	  			goto yydefault; 	/* Its time for a default reduction */
	  				
	  		/* Ok, yyn is within bounds of yytable */
	  		
	  		yyn = yytable[yyn];	/* This is yytable[ yypact[yystate] + yytoken ] */
	  		
	  		if (yyn <= 0)	/* If yytable happens to contain a -ve value, its not a shift - its a reduce */
	  		{
	  			if (yyn == 0 || yyn == YYTABLE_NINF)	/* But check for out of bounds condition*/
	  				goto yyerrlab;	/* Label to handle errors */
	  		
	  			/* Other wise reduce with rule # -yyn */
	  			
	  			yyn = -yyn;
	  			goto yyreduce; 	/* Label to implement reductions */
	  		}
	  		
	  		/* Last check: See if we reached final state! */
	  		if (yyn == YYFINAL)	/* YYFINAL is 8 in our case */
	  			YYACCEPT;	/* macro deined as 'goto acceptlab - a label to finish up */
	  			
	  		/* That completes all checks; If we reached here, there is no other option but to shift */
	  		
	  		yystate = yyn;	/* Now, yyn (= yytable[ yypact[yystate] + yytoken ]) is a state that has to be pushed */
	  		
	  		*++yyvsp = yylval; /* Push the semantic value of the symbol on the semantic stack */
	  		
	  		goto yynewstate;	/* This will increment state stack top and the following yysetstate that will do the pushing */
	  		
	  
	  yydefault:	/* A label to implement default reductions */
	  	
	  		yyn = yydefact[yystate];	/* Get the default reduction rule for this state */
	  		
	  		if ( yyn == 0 )	/* This state has no default reduction. Something is wrong */
	  		
	  			goto yyerrlab;
	  			
	  		goto yyreduce;	/* Ok, got the default reduction rule # in yyn; go ahead and reduce the stack */
	  		
	  	
	  
	  yyreduce:	/* A lablel that implements reductions on stack. */
	  	
	  		/* By the time we are here, yyn contains the rule# to use for reducing the stack. */
	  		
	  		/* Steps for reduction:
	  		 * 1. Find the length of RHS of rule #yyn
	  		 * 2. Execute any semantic actions by taking the values from the semantic stack
	  		 * 3. POP 'length' symbols from the state stack and 'length' values from semantic stack
	  		 * 4. Find the LHS of rule #yyn
	  		 * 5. Find the GOTO of state currently on top of stack on LHS symbol
	  		 * 6. Push that state on top of stack
	  		 * 
	  		 */
	  		 
	  		 yylen = yyr2[yyn];	/* Get length of RHS */
	  		 
	  		 /* Default semantic action - $$=$1 */
	  		 yyval = yyvsp[1-yylen];
	  		 
	  		 /* Execute semantic actions */
	  		 switch ( yyn )	/* Each rule has its own semantic action */
	  		 {
	  		 
	  		 	default:	break;	/* We didn't have any semantic actions in the grammar.*/
	  		 	
	  		 }
	  		 
	  		 YYPOPSTACK (yylen);	/* This will pop both state and semantic stacks. See definition of this macro above */
	  		 
	  		 yylen = 0;	/* re-initialize yylen */
	  		 
	  		 *++yyvsp  = yyval;	/* Push the result of semantic evaluation on top of semantic stack */
	  		 
	  		 
	  		 /* Now shift the result of reduction (steps 4 - 6) */
	  		 
	  		 yyn = yyr1[yyn];	/* Reuse yyn at every opportunity.  For now, yyn is the LHS symbol (number) of the rule */
	  		 
			 /* First check for anomalous GOTOs, otherwise use Default GOTO (YYDEFGOTO)
			  * 
			  * Observe that if we subtract no. of terminals (YYNTOKENS) from symbol number of a nonterminal, we get
			  * an index into yypgoto or yydefgoto for that non-terminal.
			  */
			  
	  		 yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
	  		 
	  		 /* A couple of checks are needed before we know this is not a default GOTO
	  		  * 1. yystate must be within bounds of yytable. ( 0 to YYLAST )
	  		  * 2. yycheck must contain the state currently on top of the stack
	  		  */	  		 
	  		 if ( 0 <= yystate && yystate <= YYLAST && yycheck[yystate] = *yyssp)
	  		 
	  		 	yystate = yytable[yystate];	/* Take the GOTO from yytable */
	  		 	
	  		 else
	  		 	
	  		 	yystate = yydefgoto[yyn - YYNTOKENS];	/* Otherwise use the default GOTO */
	  		 	
	  		 goto yynewstate;	/* Simply push the newly found state on top of stack and continue */
	  		 
}	/* End of yyparse() */

/* under GNU Free Documentation License
*/