/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C

   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin Street, Fifth Floor,
   Boston, MA 02110-1301, USA.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "2.3"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     IDENT = 258,
     NUMBER = 259,
     FUNCTION = 260,
     BEGIN_PARAMS = 261,
     END_PARAMS = 262,
     BEGIN_LOCALS = 263,
     END_LOCALS = 264,
     BEGIN_BODY = 265,
     END_BODY = 266,
     INTEGER = 267,
     ARRAY = 268,
     OF = 269,
     IF = 270,
     THEN = 271,
     ENDIF = 272,
     ELSE = 273,
     WHILE = 274,
     DO = 275,
     FOR = 276,
     BEGINLOOP = 277,
     ENDLOOP = 278,
     CONTINUE = 279,
     READ = 280,
     WRITE = 281,
     TRUE = 282,
     FALSE = 283,
     RETURN = 284,
     SEMICOLON = 285,
     COLON = 286,
     COMMA = 287,
     ASSIGN = 288,
     OR = 289,
     AND = 290,
     NOT = 291,
     NEQ = 292,
     EQ = 293,
     GTE = 294,
     GT = 295,
     LTE = 296,
     LT = 297,
     SUB = 298,
     ADD = 299,
     MOD = 300,
     MULT = 301,
     DIV = 302,
     UMINUS = 303,
     L_SQUARE_BRACKET = 304,
     R_SQUARE_BRACKET = 305,
     L_PAREN = 306,
     R_PAREN = 307
   };
#endif
/* Tokens.  */
#define IDENT 258
#define NUMBER 259
#define FUNCTION 260
#define BEGIN_PARAMS 261
#define END_PARAMS 262
#define BEGIN_LOCALS 263
#define END_LOCALS 264
#define BEGIN_BODY 265
#define END_BODY 266
#define INTEGER 267
#define ARRAY 268
#define OF 269
#define IF 270
#define THEN 271
#define ENDIF 272
#define ELSE 273
#define WHILE 274
#define DO 275
#define FOR 276
#define BEGINLOOP 277
#define ENDLOOP 278
#define CONTINUE 279
#define READ 280
#define WRITE 281
#define TRUE 282
#define FALSE 283
#define RETURN 284
#define SEMICOLON 285
#define COLON 286
#define COMMA 287
#define ASSIGN 288
#define OR 289
#define AND 290
#define NOT 291
#define NEQ 292
#define EQ 293
#define GTE 294
#define GT 295
#define LTE 296
#define LT 297
#define SUB 298
#define ADD 299
#define MOD 300
#define MULT 301
#define DIV 302
#define UMINUS 303
#define L_SQUARE_BRACKET 304
#define R_SQUARE_BRACKET 305
#define L_PAREN 306
#define R_PAREN 307




/* Copy the first part of user declarations.  */
#line 1 "mini_l.y"

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


/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif

#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 17 "mini_l.y"
{ //struct for id/Numberz values
  char* id_val;
  int no_val;
}
/* Line 193 of yacc.c.  */
#line 222 "y.tab.c"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 235 "y.tab.c"

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int i)
#else
static int
YYID (i)
    int i;
#endif
{
  return i;
}
#endif

#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef _STDLIB_H
#      define _STDLIB_H 1
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined _STDLIB_H \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef _STDLIB_H
#    define _STDLIB_H 1
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
	 || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss;
  YYSTYPE yyvs;
  };

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack)					\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack, Stack, yysize);				\
	Stack = &yyptr->Stack;						\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  6
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   179

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  53
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  20
/* YYNRULES -- Number of rules.  */
#define YYNRULES  63
/* YYNRULES -- Number of states.  */
#define YYNSTATES  147

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   307

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint8 yyprhs[] =
{
       0,     0,     3,     4,     7,    20,    22,    24,    28,    30,
      39,    43,    44,    48,    52,    55,    59,    65,    73,    79,
      86,   100,   103,   106,   108,   111,   113,   117,   119,   123,
     127,   129,   131,   135,   140,   143,   146,   151,   153,   155,
     157,   159,   161,   163,   165,   169,   171,   175,   179,   181,
     185,   189,   193,   195,   197,   201,   204,   207,   212,   217,
     221,   223,   227,   229
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      54,     0,    -1,    -1,    55,    54,    -1,     5,    56,    30,
       6,    60,     7,     8,    60,     9,    10,    61,    11,    -1,
       3,    -1,    56,    -1,    56,    32,    57,    -1,     4,    -1,
      57,    31,    13,    49,    58,    50,    14,    12,    -1,    57,
      31,    12,    -1,    -1,    59,    30,    60,    -1,    62,    30,
      61,    -1,    62,    30,    -1,    72,    33,    68,    -1,    15,
      63,    16,    61,    17,    -1,    15,    63,    16,    61,    18,
      61,    17,    -1,    19,    63,    22,    61,    23,    -1,    20,
      22,    61,    23,    19,    63,    -1,    21,    72,    33,    58,
      30,    63,    30,    72,    33,    68,    22,    61,    23,    -1,
      25,    71,    -1,    26,    71,    -1,    24,    -1,    29,    68,
      -1,    64,    -1,    64,    34,    63,    -1,    65,    -1,    65,
      35,    64,    -1,    68,    66,    68,    -1,    27,    -1,    28,
      -1,    51,    63,    52,    -1,    36,    68,    66,    68,    -1,
      36,    27,    -1,    36,    28,    -1,    36,    51,    63,    52,
      -1,    38,    -1,    37,    -1,    42,    -1,    40,    -1,    41,
      -1,    39,    -1,    68,    -1,    68,    32,    67,    -1,    69,
      -1,    69,    44,    68,    -1,    69,    43,    68,    -1,    70,
      -1,    70,    46,    69,    -1,    70,    47,    69,    -1,    70,
      45,    69,    -1,    72,    -1,    58,    -1,    51,    68,    52,
      -1,    43,    72,    -1,    43,    58,    -1,    43,    51,    68,
      52,    -1,    56,    51,    67,    52,    -1,    56,    51,    52,
      -1,    72,    -1,    72,    32,    71,    -1,    56,    -1,    56,
      49,    68,    50,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    40,    40,    41,    43,    45,    47,    48,    50,    52,
      53,    55,    56,    58,    59,    61,    62,    63,    64,    65,
      66,    67,    68,    69,    70,    72,    73,    75,    76,    78,
      79,    80,    81,    82,    83,    84,    85,    87,    88,    89,
      90,    91,    92,    94,    95,    97,    98,    99,   101,   102,
     103,   104,   106,   107,   108,   109,   110,   111,   112,   113,
     115,   116,   118,   119
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "IDENT", "NUMBER", "FUNCTION",
  "BEGIN_PARAMS", "END_PARAMS", "BEGIN_LOCALS", "END_LOCALS", "BEGIN_BODY",
  "END_BODY", "INTEGER", "ARRAY", "OF", "IF", "THEN", "ENDIF", "ELSE",
  "WHILE", "DO", "FOR", "BEGINLOOP", "ENDLOOP", "CONTINUE", "READ",
  "WRITE", "TRUE", "FALSE", "RETURN", "SEMICOLON", "COLON", "COMMA",
  "ASSIGN", "OR", "AND", "NOT", "NEQ", "EQ", "GTE", "GT", "LTE", "LT",
  "SUB", "ADD", "MOD", "MULT", "DIV", "UMINUS", "L_SQUARE_BRACKET",
  "R_SQUARE_BRACKET", "L_PAREN", "R_PAREN", "$accept", "Program",
  "function", "Identifier", "Identifiers", "numberz", "Declaration",
  "Declarations", "Statements", "Statement", "BoolExpr", "RelationAndExpr",
  "RelationExpr", "Comp", "Expressions", "Expression",
  "MultiplicativeExpr", "Term", "varz", "var", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    53,    54,    54,    55,    56,    57,    57,    58,    59,
      59,    60,    60,    61,    61,    62,    62,    62,    62,    62,
      62,    62,    62,    62,    62,    63,    63,    64,    64,    65,
      65,    65,    65,    65,    65,    65,    65,    66,    66,    66,
      66,    66,    66,    67,    67,    68,    68,    68,    69,    69,
      69,    69,    70,    70,    70,    70,    70,    70,    70,    70,
      71,    71,    72,    72
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     0,     2,    12,     1,     1,     3,     1,     8,
       3,     0,     3,     3,     2,     3,     5,     7,     5,     6,
      13,     2,     2,     1,     2,     1,     3,     1,     3,     3,
       1,     1,     3,     4,     2,     2,     4,     1,     1,     1,
       1,     1,     1,     1,     3,     1,     3,     3,     1,     3,
       3,     3,     1,     1,     3,     2,     2,     4,     4,     3,
       1,     3,     1,     4
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       2,     0,     0,     2,     5,     0,     1,     3,     0,    11,
       6,     0,     0,     0,     0,     0,    11,     0,     7,    10,
       0,    12,    11,     0,     0,     8,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    23,     0,     0,     0,    62,
       0,     0,     0,     9,    30,    31,     0,     0,     0,    62,
      53,     0,    25,    27,     0,    45,    48,    52,     0,     0,
       0,    21,    60,    22,     0,    24,     0,     4,    14,     0,
      34,    35,     0,     0,     0,    56,    55,     0,     0,     0,
       0,     0,     0,    38,    37,    42,    40,    41,    39,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    13,    15,     0,     0,     0,    32,    54,    59,     0,
      43,     0,    26,    28,    29,    47,    46,    51,    49,    50,
       0,     0,     0,    61,    63,    36,    33,    57,    58,     0,
      16,     0,    18,     0,     0,    44,     0,    19,     0,    17,
       0,     0,     0,     0,     0,     0,    20
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     2,     3,    49,    11,    50,    12,    13,    40,    41,
      51,    52,    53,    89,   109,    54,    55,    56,    61,    57
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -45
static const yytype_int16 yypact[] =
{
       6,    11,    19,     6,   -45,     4,   -45,   -45,    36,    11,
      37,    52,    42,    78,    11,    10,    11,    81,   -45,   -45,
      47,   -45,    11,    82,    89,   -45,    40,    83,    77,   125,
      87,    73,    73,    80,    11,   -45,    11,    11,    41,    54,
      94,    76,    74,   -45,   -45,   -45,    84,    27,    73,     5,
     -45,    92,    85,    79,   124,   -17,   -29,   -45,    93,   125,
      88,   -45,    86,   -45,    41,   -45,    41,   -45,   125,    41,
     -45,   -45,    73,   124,    41,   -45,   -45,    70,   118,     0,
     125,    73,    73,   -45,   -45,   -45,   -45,   -45,   -45,    41,
      41,    41,    41,    41,    41,   125,   106,    82,    11,    90,
      91,   -45,   -45,    95,    41,    96,   -45,   -45,   -45,   100,
      99,    44,   -45,   -45,   -45,   -45,   -45,   -45,   -45,   -45,
     109,   115,   107,   -45,   -45,   -45,   -45,   -45,   -45,    41,
     -45,   125,   -45,    73,    73,   -45,   119,   -45,   108,   -45,
      11,   120,    41,   145,   125,   146,   -45
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -45,   165,   -45,    -1,   157,   -22,   -45,   -10,   -21,   -45,
      -8,    97,   -45,   101,    43,    -9,   -44,   -45,   -32,   -27
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint8 yytable[] =
{
       5,    26,    42,     4,    25,    63,    21,    60,    10,    62,
      62,     1,    24,    10,     4,    10,    92,    93,    94,     6,
      76,    10,    19,    20,    58,    75,    90,    91,    39,    65,
       4,    25,    42,    39,     8,    39,    39,    73,    96,    78,
      77,    42,     9,    47,     4,    25,    39,   101,   117,   118,
     119,    64,   108,    42,    66,    99,    79,   100,    39,   111,
     102,   130,   131,    78,   103,   105,   123,    39,    42,    14,
     110,    62,    16,   112,   120,   122,     4,    25,    74,    39,
     114,   115,   116,    15,    47,    17,    25,     4,    25,    22,
      28,    30,    64,    29,    39,   126,    23,    39,    27,    43,
      44,    45,    59,    66,    42,    67,    68,    69,    80,    46,
     136,    70,    71,   141,    82,    95,    47,    42,    98,    81,
     110,    97,   106,   145,    48,   137,   138,    47,     4,   121,
      39,   129,   132,   143,   133,    72,   139,   134,   140,    39,
      31,   124,   107,    39,    32,    33,    34,   125,   127,    35,
      36,    37,   128,   142,    38,    83,    84,    85,    86,    87,
      88,    83,    84,    85,    86,    87,    88,   144,     7,   146,
     107,    18,   135,     0,   104,     0,     0,     0,     0,   113
};

static const yytype_int16 yycheck[] =
{
       1,    23,    29,     3,     4,    37,    16,    34,     9,    36,
      37,     5,    22,    14,     3,    16,    45,    46,    47,     0,
      47,    22,    12,    13,    32,    47,    43,    44,    29,    38,
       3,     4,    59,    34,    30,    36,    37,    46,    59,    48,
      48,    68,     6,    43,     3,     4,    47,    68,    92,    93,
      94,    51,    52,    80,    49,    64,    51,    66,    59,    80,
      69,    17,    18,    72,    72,    74,    98,    68,    95,    32,
      79,    98,    30,    81,    95,    97,     3,     4,    51,    80,
      89,    90,    91,    31,    43,     7,     4,     3,     4,     8,
      50,    14,    51,    10,    95,   104,    49,    98,     9,    12,
      27,    28,    22,    49,   131,    11,    30,    33,    16,    36,
     131,    27,    28,   140,    35,    22,    43,   144,    32,    34,
     129,    33,    52,   144,    51,   133,   134,    43,     3,    23,
     131,    32,    23,   142,    19,    51,    17,    30,    30,   140,
      15,    50,    52,   144,    19,    20,    21,    52,    52,    24,
      25,    26,    52,    33,    29,    37,    38,    39,    40,    41,
      42,    37,    38,    39,    40,    41,    42,    22,     3,    23,
      52,    14,   129,    -1,    73,    -1,    -1,    -1,    -1,    82
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     5,    54,    55,     3,    56,     0,    54,    30,     6,
      56,    57,    59,    60,    32,    31,    30,     7,    57,    12,
      13,    60,     8,    49,    60,     4,    58,     9,    50,    10,
      14,    15,    19,    20,    21,    24,    25,    26,    29,    56,
      61,    62,    72,    12,    27,    28,    36,    43,    51,    56,
      58,    63,    64,    65,    68,    69,    70,    72,    63,    22,
      72,    71,    72,    71,    51,    68,    49,    11,    30,    33,
      27,    28,    51,    68,    51,    58,    72,    63,    68,    51,
      16,    34,    35,    37,    38,    39,    40,    41,    42,    66,
      43,    44,    45,    46,    47,    22,    61,    33,    32,    68,
      68,    61,    68,    63,    66,    68,    52,    52,    52,    67,
      68,    61,    63,    64,    68,    68,    68,    69,    69,    69,
      61,    23,    58,    71,    50,    52,    68,    52,    52,    32,
      17,    18,    23,    19,    30,    67,    61,    63,    63,    17,
      30,    72,    33,    68,    22,    61,    23
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto yyerrlab

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
	      (Loc).first_line, (Loc).first_column,	\
	      (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *bottom, yytype_int16 *top)
#else
static void
yy_stack_print (bottom, top)
    yytype_int16 *bottom;
    yytype_int16 *top;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; bottom <= top; ++bottom)
    YYFPRINTF (stderr, " %d", *bottom);
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      fprintf (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      fprintf (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef	YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif



#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
	switch (*++yyp)
	  {
	  case '\'':
	  case ',':
	    goto do_not_strip_quotes;

	  case '\\':
	    if (*++yyp != '\\')
	      goto do_not_strip_quotes;
	    /* Fall through.  */
	  default:
	    if (yyres)
	      yyres[yyn] = *yyp;
	    yyn++;
	    break;

	  case '"':
	    if (yyres)
	      yyres[yyn] = '\0';
	    return yyn;
	  }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into YYRESULT an error message about the unexpected token
   YYCHAR while in state YYSTATE.  Return the number of bytes copied,
   including the terminating null byte.  If YYRESULT is null, do not
   copy anything; just return the number of bytes that would be
   copied.  As a special case, return 0 if an ordinary "syntax error"
   message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
   size calculation.  */
static YYSIZE_T
yysyntax_error (char *yyresult, int yystate, int yychar)
{
  int yyn = yypact[yystate];

  if (! (YYPACT_NINF < yyn && yyn <= YYLAST))
    return 0;
  else
    {
      int yytype = YYTRANSLATE (yychar);
      YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
      YYSIZE_T yysize = yysize0;
      YYSIZE_T yysize1;
      int yysize_overflow = 0;
      enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
      char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
      int yyx;

# if 0
      /* This is so xgettext sees the translatable formats that are
	 constructed on the fly.  */
      YY_("syntax error, unexpected %s");
      YY_("syntax error, unexpected %s, expecting %s");
      YY_("syntax error, unexpected %s, expecting %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
# endif
      char *yyfmt;
      char const *yyf;
      static char const yyunexpected[] = "syntax error, unexpected %s";
      static char const yyexpecting[] = ", expecting %s";
      static char const yyor[] = " or %s";
      char yyformat[sizeof yyunexpected
		    + sizeof yyexpecting - 1
		    + ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
		       * (sizeof yyor - 1))];
      char const *yyprefix = yyexpecting;

      /* Start YYX at -YYN if negative to avoid negative indexes in
	 YYCHECK.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;

      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yycount = 1;

      yyarg[0] = yytname[yytype];
      yyfmt = yystpcpy (yyformat, yyunexpected);

      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	  {
	    if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
	      {
		yycount = 1;
		yysize = yysize0;
		yyformat[sizeof yyunexpected - 1] = '\0';
		break;
	      }
	    yyarg[yycount++] = yytname[yyx];
	    yysize1 = yysize + yytnamerr (0, yytname[yyx]);
	    yysize_overflow |= (yysize1 < yysize);
	    yysize = yysize1;
	    yyfmt = yystpcpy (yyfmt, yyprefix);
	    yyprefix = yyor;
	  }

      yyf = YY_(yyformat);
      yysize1 = yysize + yystrlen (yyf);
      yysize_overflow |= (yysize1 < yysize);
      yysize = yysize1;

      if (yysize_overflow)
	return YYSIZE_MAXIMUM;

      if (yyresult)
	{
	  /* Avoid sprintf, as that infringes on the user's name space.
	     Don't have undefined behavior even if the translation
	     produced a string with the wrong number of "%s"s.  */
	  char *yyp = yyresult;
	  int yyi = 0;
	  while ((*yyp = *yyf) != '\0')
	    {
	      if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		{
		  yyp += yytnamerr (yyp, yyarg[yyi++]);
		  yyf += 2;
		}
	      else
		{
		  yyp++;
		  yyf++;
		}
	    }
	}
      return yysize;
    }
}
#endif /* YYERROR_VERBOSE */


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
	break;
    }
}


/* Prevent warnings from -Wmissing-prototypes.  */

#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */



/* The look-ahead symbol.  */
int yychar;

/* The semantic value of the look-ahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*----------.
| yyparse.  |
`----------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{
  
  int yystate;
  int yyn;
  int yyresult;
  /* Number of tokens to shift before error messages enabled.  */
  int yyerrstatus;
  /* Look-ahead token as an internal (translated) token number.  */
  int yytoken = 0;
#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

  /* Three stacks and their tools:
     `yyss': related to states,
     `yyvs': related to semantic values,
     `yyls': related to locations.

     Refer to the stacks thru separate pointers, to allow yyoverflow
     to reallocate them elsewhere.  */

  /* The state stack.  */
  yytype_int16 yyssa[YYINITDEPTH];
  yytype_int16 *yyss = yyssa;
  yytype_int16 *yyssp;

  /* The semantic value stack.  */
  YYSTYPE yyvsa[YYINITDEPTH];
  YYSTYPE *yyvs = yyvsa;
  YYSTYPE *yyvsp;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  YYSIZE_T yystacksize = YYINITDEPTH;

  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;


  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY;		/* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */

  yyssp = yyss;
  yyvsp = yyvs;

  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
	/* Give user a chance to reallocate the stack.  Use copies of
	   these so that the &'s don't force the real ones into
	   memory.  */
	YYSTYPE *yyvs1 = yyvs;
	yytype_int16 *yyss1 = yyss;


	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow (YY_("memory exhausted"),
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),

		    &yystacksize);

	yyss = yyss1;
	yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
	goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
	yystacksize = YYMAXDEPTH;

      {
	yytype_int16 *yyss1 = yyss;
	union yyalloc *yyptr =
	  (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
	if (! yyptr)
	  goto yyexhaustedlab;
	YYSTACK_RELOCATE (yyss);
	YYSTACK_RELOCATE (yyvs);

#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;


      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
		  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
	YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     look-ahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to look-ahead token.  */
  yyn = yypact[yystate];
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a look-ahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid look-ahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yyn == 0 || yyn == YYTABLE_NINF)
	goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the look-ahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token unless it is eof.  */
  if (yychar != YYEOF)
    yychar = YYEMPTY;

  yystate = yyn;
  *++yyvsp = yylval;

  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
#line 40 "mini_l.y"
    {printf("Program -> EPSILON\n");;}
    break;

  case 3:
#line 41 "mini_l.y"
    {printf("Program -> function Program\n");;}
    break;

  case 4:
#line 43 "mini_l.y"
    {printf("function -> FUNCTION Identifier SEMICOLON BEGIN_PARAMS Declarations END_PARAMS BEGIN_LOCALS Declarations END_LOCALS BEGIN_BODY Statements END_BODY\n");;}
    break;

  case 5:
#line 45 "mini_l.y"
    {printf("Identifier -> IDENT %s\n", (yyvsp[(1) - (1)].id_val));;}
    break;

  case 6:
#line 47 "mini_l.y"
    {printf("Identifiers -> Identifier\n");;}
    break;

  case 7:
#line 48 "mini_l.y"
    {printf("Identifiers -> Identifier COMMA Identifiers\n");;}
    break;

  case 8:
#line 50 "mini_l.y"
    {printf("numberz -> NUMBER %d\n", (yyvsp[(1) - (1)].no_val));;}
    break;

  case 9:
#line 52 "mini_l.y"
    {printf("Declaration -> Identifiers COLON ARRAY L_SQUARE_BRACKET numberz R_SQUARE_BRACKET OF INTEGER\n");;}
    break;

  case 10:
#line 53 "mini_l.y"
    {printf("Declaration -> Identifiers COLON INTEGER\n");;}
    break;

  case 11:
#line 55 "mini_l.y"
    {printf("Declarations -> EPSILON\n");;}
    break;

  case 12:
#line 56 "mini_l.y"
    {printf("Declarations -> Declaration SEMICOLON Declarations\n");;}
    break;

  case 13:
#line 58 "mini_l.y"
    {printf("Statements -> Statement SEMICOLON Statements\n");;}
    break;

  case 14:
#line 59 "mini_l.y"
    {printf("Statements -> Statement SEMICOLON\n");;}
    break;

  case 15:
#line 61 "mini_l.y"
    {printf("Statement -> var ASSIGN Expression\n");;}
    break;

  case 16:
#line 62 "mini_l.y"
    {printf("Statement -> IF BoolExpr THEN Statements ENDIF\n");;}
    break;

  case 17:
#line 63 "mini_l.y"
    {printf("Statement -> IF BoolExpr THEN Statements ELSE Statements ENDIF\n");;}
    break;

  case 18:
#line 64 "mini_l.y"
    {printf("Statement -> WHILE BoolExpr BEGINLOOP Statements ENDLOOP\n");;}
    break;

  case 19:
#line 65 "mini_l.y"
    {printf("Statement -> DO BEGINLOOP Statements ENDLOOP WHILE BoolExpr\n");;}
    break;

  case 20:
#line 66 "mini_l.y"
    {printf("FOR var ASSIGN numberz SEMICOLON BoolExpr SEMICOLON var ASSIGN Expression BEGINLOOP Statements ENDLOOP\n");;}
    break;

  case 21:
#line 67 "mini_l.y"
    {printf("Statement -> READ varz\n");;}
    break;

  case 22:
#line 68 "mini_l.y"
    {printf("Statement -> WRITE varz\n");;}
    break;

  case 23:
#line 69 "mini_l.y"
    {printf("Statement -> CONTINUE\n");;}
    break;

  case 24:
#line 70 "mini_l.y"
    {printf("Statement -> RETURN Expression\n");;}
    break;

  case 25:
#line 72 "mini_l.y"
    {printf("BoolExpr -> RelationAndExpr\n");;}
    break;

  case 26:
#line 73 "mini_l.y"
    {printf("BoolExpr -> RelationAndExpr OR BoolExpr\n");;}
    break;

  case 27:
#line 75 "mini_l.y"
    {printf("RelationAndExpr -> RelationExpr\n");;}
    break;

  case 28:
#line 76 "mini_l.y"
    {printf("RelationAndExpr -> RelationExpr AND RelationAndExpr\n");;}
    break;

  case 29:
#line 78 "mini_l.y"
    {printf("RelationExpr -> Expression Comp Expression\n");;}
    break;

  case 30:
#line 79 "mini_l.y"
    { printf("RelationExpr -> TRUE\n"); ;}
    break;

  case 31:
#line 80 "mini_l.y"
    {printf("RelationExpr -> FALSE\n");;}
    break;

  case 32:
#line 81 "mini_l.y"
    {printf("RelationExpr -> L_PAREN BoolExpr R_PAREN\n");;}
    break;

  case 33:
#line 82 "mini_l.y"
    {printf("RelationExpr -> NOT Expression Comp Expression\n");;}
    break;

  case 34:
#line 83 "mini_l.y"
    {printf("RelationExpr -> NOT TRUE\n");;}
    break;

  case 35:
#line 84 "mini_l.y"
    {printf("RelationExpr -> NOT FALSE\n");;}
    break;

  case 36:
#line 85 "mini_l.y"
    {printf("RelationExpr -> NOT L_PAREN BoolExpr R_PAREN\n");;}
    break;

  case 37:
#line 87 "mini_l.y"
    { printf("Comp -> EQ\n"); ;}
    break;

  case 38:
#line 88 "mini_l.y"
    { printf("Comp -> NEQ\n"); ;}
    break;

  case 39:
#line 89 "mini_l.y"
    { printf("Comp -> LT\n"); ;}
    break;

  case 40:
#line 90 "mini_l.y"
    { printf("Comp -> GT\n"); ;}
    break;

  case 41:
#line 91 "mini_l.y"
    { printf("Comp -> LTE\n"); ;}
    break;

  case 42:
#line 92 "mini_l.y"
    { printf("Comp -> GTE\n"); ;}
    break;

  case 43:
#line 94 "mini_l.y"
    {printf("Expressions -> Expression\n");;}
    break;

  case 44:
#line 95 "mini_l.y"
    {printf("Expressions -> Expression COMMA Expressions\n");;}
    break;

  case 45:
#line 97 "mini_l.y"
    {printf("Expression -> MultiplicativeExpr\n");;}
    break;

  case 46:
#line 98 "mini_l.y"
    {printf("Expression -> MultiplicativeExpr ADD Expression\n");;}
    break;

  case 47:
#line 99 "mini_l.y"
    {printf("Expression -> MultiplicativeExpr SUB Expression \n");;}
    break;

  case 48:
#line 101 "mini_l.y"
    {printf("MultiplicativeExpr -> Term\n");;}
    break;

  case 49:
#line 102 "mini_l.y"
    {printf("MultiplicativeExpr -> Term MULT MultiplicativeExpr\n");;}
    break;

  case 50:
#line 103 "mini_l.y"
    {printf("MultiplicativeExpr -> Term DIV MultiplicativeExpr\n");;}
    break;

  case 51:
#line 104 "mini_l.y"
    {printf("MultiplicativeExpr -> Term MOD MultiplicativeExpr\n");;}
    break;

  case 52:
#line 106 "mini_l.y"
    {printf("Term -> var\n");;}
    break;

  case 53:
#line 107 "mini_l.y"
    {printf("Term -> numberz\n");;}
    break;

  case 54:
#line 108 "mini_l.y"
    {printf("Term -> L_PAREN Expression R_PAREN\n");;}
    break;

  case 55:
#line 109 "mini_l.y"
    {printf("Term -> SUB var\n");;}
    break;

  case 56:
#line 110 "mini_l.y"
    {printf("Term -> SUB numberz\n");;}
    break;

  case 57:
#line 111 "mini_l.y"
    {printf("Term -> SUB L_PAREN Expression R_PAREN\n");;}
    break;

  case 58:
#line 112 "mini_l.y"
    {printf("Term -> Identifier L_PAREN Expressions R_PAREN\n");;}
    break;

  case 59:
#line 113 "mini_l.y"
    {printf("Term -> Identifier L_PAREN R_PAREN\n");;}
    break;

  case 60:
#line 115 "mini_l.y"
    {printf("varz -> var\n");;}
    break;

  case 61:
#line 116 "mini_l.y"
    {printf("varz -> var COMMA varz\n");;}
    break;

  case 62:
#line 118 "mini_l.y"
    {printf("var -> Identifier\n");;}
    break;

  case 63:
#line 119 "mini_l.y"
    {printf("var -> Identifier L_SQUARE_BRACKET Expression R_SQUARE_BRACKET\n");;}
    break;


/* Line 1267 of yacc.c.  */
#line 1869 "y.tab.c"
      default: break;
    }
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;


  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
      {
	YYSIZE_T yysize = yysyntax_error (0, yystate, yychar);
	if (yymsg_alloc < yysize && yymsg_alloc < YYSTACK_ALLOC_MAXIMUM)
	  {
	    YYSIZE_T yyalloc = 2 * yysize;
	    if (! (yysize <= yyalloc && yyalloc <= YYSTACK_ALLOC_MAXIMUM))
	      yyalloc = YYSTACK_ALLOC_MAXIMUM;
	    if (yymsg != yymsgbuf)
	      YYSTACK_FREE (yymsg);
	    yymsg = (char *) YYSTACK_ALLOC (yyalloc);
	    if (yymsg)
	      yymsg_alloc = yyalloc;
	    else
	      {
		yymsg = yymsgbuf;
		yymsg_alloc = sizeof yymsgbuf;
	      }
	  }

	if (0 < yysize && yysize <= yymsg_alloc)
	  {
	    (void) yysyntax_error (yymsg, yystate, yychar);
	    yyerror (yymsg);
	  }
	else
	  {
	    yyerror (YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse look-ahead token after an
	 error, discard it.  */

      if (yychar <= YYEOF)
	{
	  /* Return failure if at end of input.  */
	  if (yychar == YYEOF)
	    YYABORT;
	}
      else
	{
	  yydestruct ("Error: discarding",
		      yytoken, &yylval);
	  yychar = YYEMPTY;
	}
    }

  /* Else will try to reuse look-ahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule which action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (yyn != YYPACT_NINF)
	{
	  yyn += YYTERROR;
	  if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
	    {
	      yyn = yytable[yyn];
	      if (0 < yyn)
		break;
	    }
	}

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
	YYABORT;


      yydestruct ("Error: popping",
		  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  *++yyvsp = yylval;


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#ifndef yyoverflow
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEOF && yychar != YYEMPTY)
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval);
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}


#line 122 "mini_l.y"

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
