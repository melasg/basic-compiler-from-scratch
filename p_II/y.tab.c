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
     FUNCTION = 258,
     BEGIN_PARAMS = 259,
     END_PARAMS = 260,
     BEGIN_LOCALS = 261,
     END_LOCALS = 262,
     BEGIN_BODY = 263,
     END_BODY = 264,
     INTEGER = 265,
     ARRAY = 266,
     OF = 267,
     IF = 268,
     THEN = 269,
     ENDIF = 270,
     ELSE = 271,
     WHILE = 272,
     DO = 273,
     FOR = 274,
     BEGINLOOP = 275,
     ENDLOOP = 276,
     CONTINUE = 277,
     READ = 278,
     WRITE = 279,
     AND = 280,
     OR = 281,
     TRUE = 282,
     FALSE = 283,
     RETURN = 284,
     SEMICOLON = 285,
     COLON = 286,
     COMMA = 287,
     L_PAREN = 288,
     R_PAREN = 289,
     L_SQUARE_BRACKET = 290,
     R_SQUARE_BRACKET = 291,
     IDENT = 292,
     NUMBER = 293,
     GTE = 294,
     LTE = 295,
     GT = 296,
     LT = 297,
     NEQ = 298,
     EQ = 299,
     MOD = 300,
     DIV = 301,
     MULT = 302,
     ADD = 303,
     SUB = 304,
     UMINUS = 305,
     ASSIGN = 306,
     NOT = 307
   };
#endif
/* Tokens.  */
#define FUNCTION 258
#define BEGIN_PARAMS 259
#define END_PARAMS 260
#define BEGIN_LOCALS 261
#define END_LOCALS 262
#define BEGIN_BODY 263
#define END_BODY 264
#define INTEGER 265
#define ARRAY 266
#define OF 267
#define IF 268
#define THEN 269
#define ENDIF 270
#define ELSE 271
#define WHILE 272
#define DO 273
#define FOR 274
#define BEGINLOOP 275
#define ENDLOOP 276
#define CONTINUE 277
#define READ 278
#define WRITE 279
#define AND 280
#define OR 281
#define TRUE 282
#define FALSE 283
#define RETURN 284
#define SEMICOLON 285
#define COLON 286
#define COMMA 287
#define L_PAREN 288
#define R_PAREN 289
#define L_SQUARE_BRACKET 290
#define R_SQUARE_BRACKET 291
#define IDENT 292
#define NUMBER 293
#define GTE 294
#define LTE 295
#define GT 296
#define LT 297
#define NEQ 298
#define EQ 299
#define MOD 300
#define DIV 301
#define MULT 302
#define ADD 303
#define SUB 304
#define UMINUS 305
#define ASSIGN 306
#define NOT 307




/* Copy the first part of user declarations.  */
#line 1 "mini_l.y"

	// C Declarations
	#include <stdio.h>
	#include <stdlib.h>
	#include "string.h"
	#include "y.tab.h"
	extern const char* yytext;
	extern int num_lines;
	extern int num_column;
	
	void yyerror(const char *msg);
	int yylex();

	extern FILE *yyin;


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
#line 221 "y.tab.c"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 234 "y.tab.c"

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
#define YYFINAL  7
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   357

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  53
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  37
/* YYNRULES -- Number of rules.  */
#define YYNRULES  87
/* YYNRULES -- Number of states.  */
#define YYNSTATES  190

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
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     5,     6,     9,    22,    23,    27,    31,
      34,    37,    41,    45,    49,    53,    55,    59,    63,    65,
      72,    82,    84,    86,    88,    90,    92,    94,    96,    98,
     100,   104,   108,   114,   122,   128,   135,   149,   163,   177,
     180,   183,   185,   189,   192,   194,   197,   200,   201,   205,
     208,   209,   213,   215,   218,   222,   224,   226,   230,   232,
     234,   236,   238,   240,   242,   245,   246,   250,   254,   257,
     258,   262,   266,   270,   272,   275,   278,   280,   282,   286,
     290,   293,   295,   299,   303,   305,   310,   318
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      54,     0,    -1,    55,    -1,    -1,    56,    55,    -1,     3,
      89,    30,     4,    57,     5,     6,    57,     7,     8,    58,
       9,    -1,    -1,    59,    30,    57,    -1,    59,     1,    57,
      -1,    62,    30,    -1,    62,     1,    -1,    58,    62,    30,
      -1,    58,    62,     1,    -1,    60,    31,    61,    -1,    60,
       1,    61,    -1,    89,    -1,    60,    32,    89,    -1,    60,
       1,    89,    -1,    10,    -1,    11,    35,    38,    36,    12,
      10,    -1,    11,    35,    38,    36,    35,    38,    36,    12,
      10,    -1,    63,    -1,    64,    -1,    65,    -1,    66,    -1,
      67,    -1,    68,    -1,    69,    -1,    71,    -1,    72,    -1,
      88,    51,    80,    -1,    88,     1,    80,    -1,    13,    73,
      14,    58,    15,    -1,    13,    73,    14,    58,    16,    58,
      15,    -1,    17,    73,    20,    58,    21,    -1,    18,    20,
      58,    21,    17,    73,    -1,    19,    88,    51,    38,    30,
      73,    30,    88,    51,    80,    20,    58,    21,    -1,    19,
      88,    51,    38,     1,    73,    30,    88,    51,    80,    20,
      58,    21,    -1,    19,    88,    51,    38,    30,    73,     1,
      88,    51,    80,    20,    58,    21,    -1,    23,    70,    -1,
      24,    70,    -1,    88,    -1,    88,    32,    70,    -1,    88,
      70,    -1,    22,    -1,    29,    80,    -1,    75,    74,    -1,
      -1,    74,    26,    75,    -1,    77,    76,    -1,    -1,    76,
      25,    77,    -1,    78,    -1,    52,    78,    -1,    80,    79,
      80,    -1,    27,    -1,    28,    -1,    33,    73,    34,    -1,
      44,    -1,    43,    -1,    42,    -1,    41,    -1,    40,    -1,
      39,    -1,    82,    81,    -1,    -1,    81,    48,    82,    -1,
      81,    49,    82,    -1,    84,    83,    -1,    -1,    83,    47,
      84,    -1,    83,    46,    84,    -1,    83,    45,    84,    -1,
      85,    -1,    49,    85,    -1,    89,    86,    -1,    88,    -1,
      38,    -1,    33,    80,    34,    -1,    33,    87,    34,    -1,
      33,    34,    -1,    80,    -1,    80,    32,    87,    -1,    80,
       1,    87,    -1,    89,    -1,    89,    35,    80,    36,    -1,
      89,    35,    80,    36,    35,    80,    36,    -1,    37,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    38,    38,    41,    42,    45,    57,    58,    59,    62,
      63,    64,    65,    69,    70,    73,    74,    75,    78,    79,
      80,    84,    85,    86,    87,    88,    89,    90,    91,    92,
      95,    96,    99,   100,   103,   106,   109,   113,   117,   123,
     126,   129,   130,   131,   134,   136,   138,   140,   141,   144,
     146,   147,   150,   151,   153,   154,   155,   156,   159,   160,
     161,   162,   163,   164,   167,   169,   170,   171,   174,   176,
     177,   178,   179,   182,   183,   184,   186,   187,   188,   190,
     191,   193,   194,   195,   198,   199,   200,   206
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "FUNCTION", "BEGIN_PARAMS", "END_PARAMS",
  "BEGIN_LOCALS", "END_LOCALS", "BEGIN_BODY", "END_BODY", "INTEGER",
  "ARRAY", "OF", "IF", "THEN", "ENDIF", "ELSE", "WHILE", "DO", "FOR",
  "BEGINLOOP", "ENDLOOP", "CONTINUE", "READ", "WRITE", "AND", "OR", "TRUE",
  "FALSE", "RETURN", "SEMICOLON", "COLON", "COMMA", "L_PAREN", "R_PAREN",
  "L_SQUARE_BRACKET", "R_SQUARE_BRACKET", "IDENT", "NUMBER", "GTE", "LTE",
  "GT", "LT", "NEQ", "EQ", "MOD", "DIV", "MULT", "ADD", "SUB", "UMINUS",
  "ASSIGN", "NOT", "$accept", "Program", "functions", "function",
  "dec_loop", "statement_loop", "declaration", "id_loop", "assignment",
  "statement", "A", "B", "C", "D", "E", "F", "G", "var_loop", "H", "I",
  "bool_expr", "bool_expr_loop", "relation_and_expr",
  "relation_and_expr_loop", "relation_expr", "relations", "comp",
  "expression", "expression_loop", "multiplicative_expr", "multi_loop",
  "term", "term_top", "term_expression", "term_exp", "var", "ident", 0
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
       0,    53,    54,    55,    55,    56,    57,    57,    57,    58,
      58,    58,    58,    59,    59,    60,    60,    60,    61,    61,
      61,    62,    62,    62,    62,    62,    62,    62,    62,    62,
      63,    63,    64,    64,    65,    66,    67,    67,    67,    68,
      69,    70,    70,    70,    71,    72,    73,    74,    74,    75,
      76,    76,    77,    77,    78,    78,    78,    78,    79,    79,
      79,    79,    79,    79,    80,    81,    81,    81,    82,    83,
      83,    83,    83,    84,    84,    84,    85,    85,    85,    86,
      86,    87,    87,    87,    88,    88,    88,    89
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     0,     2,    12,     0,     3,     3,     2,
       2,     3,     3,     3,     3,     1,     3,     3,     1,     6,
       9,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       3,     3,     5,     7,     5,     6,    13,    13,    13,     2,
       2,     1,     3,     2,     1,     2,     2,     0,     3,     2,
       0,     3,     1,     2,     3,     1,     1,     3,     1,     1,
       1,     1,     1,     1,     2,     0,     3,     3,     2,     0,
       3,     3,     3,     1,     2,     2,     1,     1,     3,     3,
       2,     1,     3,     3,     1,     4,     7,     1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       3,     0,     0,     2,     3,    87,     0,     1,     4,     0,
       6,     0,     0,     0,    15,     0,     6,     6,     0,     0,
       0,     6,     8,     7,    18,     0,    14,    17,    13,    16,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      44,     0,     0,     0,     0,     0,    21,    22,    23,    24,
      25,    26,    27,    28,    29,     0,    84,     0,     0,    55,
      56,     0,    77,     0,     0,     0,    47,    50,    52,     0,
      65,    69,    73,    76,    84,     0,     0,     0,    39,    41,
      40,     0,    45,     5,     0,    10,     9,     0,     0,     0,
      19,     0,     0,     0,    74,    53,     0,    46,    49,    63,
      62,    61,    60,    59,    58,     0,    64,    68,     0,    75,
       0,     0,     0,     0,    43,     0,    12,    11,    31,    30,
       0,     0,    57,    78,     0,     0,     0,    54,     0,     0,
       0,     0,     0,    80,     0,     0,     0,     0,     0,    42,
      85,     0,    32,     0,    48,    51,    66,    67,    72,    71,
      70,     0,     0,    79,    34,     0,     0,     0,     0,    20,
       0,    83,    82,    35,     0,     0,     0,    33,     0,     0,
       0,    86,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    37,    38,    36
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,     4,    11,    44,    12,    13,    26,    45,
      46,    47,    48,    49,    50,    51,    52,    78,    53,    54,
      65,    97,    66,    98,    67,    68,   105,    69,   106,    70,
     107,    71,    72,   109,   135,    73,    74
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -52
static const yytype_int16 yypact[] =
{
       5,   -26,    24,   -52,     5,   -52,    -8,   -52,   -52,    56,
     -26,    59,     1,    17,   -52,    41,   -26,   -26,    18,    43,
     -26,   -26,   -52,   -52,   -52,    35,   -52,   -52,   -52,   -52,
      66,    49,    72,    57,   314,    -9,    30,    30,    85,   -26,
     -52,   -26,   -26,    28,   178,     6,   -52,   -52,   -52,   -52,
     -52,   -52,   -52,   -52,   -52,     0,    76,   103,    78,   -52,
     -52,    30,   -52,    48,   100,   108,   -52,   -52,   -52,   313,
     -52,   -52,   -52,   -52,   -21,   114,   314,    90,   -52,    51,
     -52,    28,   -52,   -52,     9,   -52,   -52,    28,    28,    28,
     -52,   107,   113,   305,   -52,   -52,   314,   122,   127,   -52,
     -52,   -52,   -52,   -52,   -52,    28,    42,    52,   117,   -52,
     314,   212,   132,   -26,   -52,   126,   -52,   -52,   -52,   -52,
     136,   161,   -52,   -52,   195,    30,    30,   -52,    28,    28,
      28,    28,    28,   -52,    12,   152,   229,   175,    20,   -52,
     158,   184,   -52,   314,   -52,   -52,   -52,   -52,   -52,   -52,
     -52,    28,    28,   -52,   -52,    30,    30,    30,    28,   -52,
     246,   -52,   -52,   -52,   168,    22,   163,   -52,   -26,   -26,
     -26,   -52,   153,   154,   155,    28,    28,    28,   183,   189,
     196,   314,   314,   314,   263,   280,   297,   -52,   -52,   -52
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -52,   -52,   216,   -52,    98,   -51,   -52,   -52,   202,   -40,
     -52,   -52,   -52,   -52,   -52,   -52,   -52,   -37,   -52,   -52,
     -31,   -52,    97,   -52,   101,   159,   -52,    13,   -52,    11,
     -52,    26,   165,   -52,   -44,    -7,    -1
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -82
static const yytype_int16 yytable[] =
{
       6,    87,    16,    57,    84,    80,    75,    85,     1,    14,
     116,     5,   108,   151,    89,    14,    14,    27,    18,    29,
      14,   156,     9,   169,     7,   111,    58,    55,    24,    25,
      92,    17,    77,    56,    79,    79,    86,    55,    56,   117,
      56,    56,   114,    56,   152,   124,   -81,    21,    19,    20,
     157,    88,   170,    24,    25,     5,    82,    59,    60,   136,
      10,    81,    56,    61,    15,     5,    62,     5,    62,    55,
      31,    84,    79,    32,    93,    56,   139,    63,    56,    63,
      34,    81,    64,   113,    84,     5,    62,    33,     5,    55,
     128,   129,   160,    35,   115,    56,    84,   130,   131,   132,
     118,   119,   120,    55,    55,    76,    79,   161,   162,    56,
      56,    89,    56,    90,    22,    23,    91,    55,   127,    30,
      84,   134,    96,    56,   163,   164,   165,    59,    60,    55,
     184,   185,   186,    61,   110,    56,    55,     5,    62,   146,
     147,   112,    56,   121,    84,    84,    84,   122,   125,    63,
      81,   133,   126,    55,     5,    62,   148,   149,   150,    56,
     123,   172,   173,   174,   134,   134,    63,    56,    56,    56,
     138,   166,   140,   141,    55,    55,    55,    55,    55,    55,
      56,    56,    56,    56,    56,    56,   153,    83,   178,   179,
     180,    36,   155,   158,   159,    37,    38,    39,   168,   171,
      40,    41,    42,   181,   175,   176,   177,    43,    36,   182,
     142,   143,    37,    38,    39,     5,   183,    40,    41,    42,
       8,    28,   144,    95,    43,    36,     0,   145,    94,    37,
      38,    39,     5,   137,    40,    41,    42,     0,     0,     0,
       0,    43,    36,     0,     0,     0,    37,    38,    39,     5,
     154,    40,    41,    42,     0,     0,     0,     0,    43,    36,
       0,   167,     0,    37,    38,    39,     5,     0,    40,    41,
      42,     0,     0,     0,     0,    43,    36,     0,     0,     0,
      37,    38,    39,     5,   187,    40,    41,    42,     0,     0,
       0,     0,    43,    36,     0,     0,     0,    37,    38,    39,
       5,   188,    40,    41,    42,     0,     0,     0,     0,    43,
      36,     0,     0,     0,    37,    38,    39,     5,   189,    40,
      41,    42,     0,     0,     0,     0,    43,    36,     0,     0,
       0,    37,    38,    39,     5,     0,    40,    41,    42,   123,
       0,     0,     0,    43,    99,   100,   101,   102,   103,   104,
       0,     5,    99,   100,   101,   102,   103,   104
};

static const yytype_int16 yycheck[] =
{
       1,     1,     1,    12,    44,    42,    37,     1,     3,    10,
       1,    37,    33,     1,    35,    16,    17,    18,     1,    20,
      21,     1,    30,     1,     0,    76,    35,    34,    10,    11,
      61,    30,    39,    34,    41,    42,    30,    44,    39,    30,
      41,    42,    79,    44,    32,    96,    34,     6,    31,    32,
      30,    51,    30,    10,    11,    37,    43,    27,    28,   110,
       4,    33,    63,    33,     5,    37,    38,    37,    38,    76,
      35,   111,    79,     7,    61,    76,   113,    49,    79,    49,
       8,    33,    52,    32,   124,    37,    38,    38,    37,    96,
      48,    49,   143,    36,    81,    96,   136,    45,    46,    47,
      87,    88,    89,   110,   111,    20,   113,   151,   152,   110,
     111,    35,   113,    10,    16,    17,    38,   124,   105,    21,
     160,   108,    14,   124,   155,   156,   157,    27,    28,   136,
     181,   182,   183,    33,    20,   136,   143,    37,    38,   128,
     129,    51,   143,    36,   184,   185,   186,    34,    26,    49,
      33,    34,    25,   160,    37,    38,   130,   131,   132,   160,
      34,   168,   169,   170,   151,   152,    49,   168,   169,   170,
      38,   158,    36,    12,   181,   182,   183,   184,   185,   186,
     181,   182,   183,   184,   185,   186,    34,     9,   175,   176,
     177,    13,    17,    35,    10,    17,    18,    19,    30,    36,
      22,    23,    24,    20,    51,    51,    51,    29,    13,    20,
      15,    16,    17,    18,    19,    37,    20,    22,    23,    24,
       4,    19,   125,    64,    29,    13,    -1,   126,    63,    17,
      18,    19,    37,    21,    22,    23,    24,    -1,    -1,    -1,
      -1,    29,    13,    -1,    -1,    -1,    17,    18,    19,    37,
      21,    22,    23,    24,    -1,    -1,    -1,    -1,    29,    13,
      -1,    15,    -1,    17,    18,    19,    37,    -1,    22,    23,
      24,    -1,    -1,    -1,    -1,    29,    13,    -1,    -1,    -1,
      17,    18,    19,    37,    21,    22,    23,    24,    -1,    -1,
      -1,    -1,    29,    13,    -1,    -1,    -1,    17,    18,    19,
      37,    21,    22,    23,    24,    -1,    -1,    -1,    -1,    29,
      13,    -1,    -1,    -1,    17,    18,    19,    37,    21,    22,
      23,    24,    -1,    -1,    -1,    -1,    29,    13,    -1,    -1,
      -1,    17,    18,    19,    37,    -1,    22,    23,    24,    34,
      -1,    -1,    -1,    29,    39,    40,    41,    42,    43,    44,
      -1,    37,    39,    40,    41,    42,    43,    44
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,    54,    55,    56,    37,    89,     0,    55,    30,
       4,    57,    59,    60,    89,     5,     1,    30,     1,    31,
      32,     6,    57,    57,    10,    11,    61,    89,    61,    89,
      57,    35,     7,    38,     8,    36,    13,    17,    18,    19,
      22,    23,    24,    29,    58,    62,    63,    64,    65,    66,
      67,    68,    69,    71,    72,    88,    89,    12,    35,    27,
      28,    33,    38,    49,    52,    73,    75,    77,    78,    80,
      82,    84,    85,    88,    89,    73,    20,    88,    70,    88,
      70,    33,    80,     9,    62,     1,    30,     1,    51,    35,
      10,    38,    73,    80,    85,    78,    14,    74,    76,    39,
      40,    41,    42,    43,    44,    79,    81,    83,    33,    86,
      20,    58,    51,    32,    70,    80,     1,    30,    80,    80,
      80,    36,    34,    34,    58,    26,    25,    80,    48,    49,
      45,    46,    47,    34,    80,    87,    58,    21,    38,    70,
      36,    12,    15,    16,    75,    77,    82,    82,    84,    84,
      84,     1,    32,    34,    21,    17,     1,    30,    35,    10,
      58,    87,    87,    73,    73,    73,    80,    15,    30,     1,
      30,    36,    88,    88,    88,    51,    51,    51,    80,    80,
      80,    20,    20,    20,    58,    58,    58,    21,    21,    21
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
#line 38 "mini_l.y"
    {printf("Program -> functions\n");;}
    break;

  case 3:
#line 41 "mini_l.y"
    {printf("functions -> epsilon\n");;}
    break;

  case 4:
#line 42 "mini_l.y"
    {printf("functions -> function functions\n");;}
    break;

  case 5:
#line 49 "mini_l.y"
    {
               printf("function -> FUNCTION ident SEMICOLON ");
               printf("BEGIN_PARAMS dec_loop END_PARAMS ");
               printf("BEGIN_LOCALS dec_loop END_LOCALS ");
               printf("BEGIN_BODY statement_loop END_BODY\n");
            ;}
    break;

  case 6:
#line 57 "mini_l.y"
    {printf("dec_loop -> epsilon\n");;}
    break;

  case 7:
#line 58 "mini_l.y"
    {printf("dec_loop -> declaration SEMICOLON dec_loop\n");;}
    break;

  case 8:
#line 59 "mini_l.y"
    {yyerrok; yyerror("Syntax error, missing semicolon in declaration.");;}
    break;

  case 9:
#line 62 "mini_l.y"
    {printf("statement_loop -> statement SEMICOLON\n");;}
    break;

  case 10:
#line 63 "mini_l.y"
    {yyerrok; yyerror("Syntax error, missing semicolon in statement.");;}
    break;

  case 11:
#line 64 "mini_l.y"
    {printf("statement_loop -> statement_loop statement SEMICOLON\n");;}
    break;

  case 12:
#line 65 "mini_l.y"
    {yyerrok; yyerror("Syntax error, missing semicolon in statement.");;}
    break;

  case 13:
#line 69 "mini_l.y"
    {printf("declaration -> id_loop COLON assignment\n");;}
    break;

  case 14:
#line 70 "mini_l.y"
    {yyerrok; yyerror("Syntax error, invalid declaration, missing colon.");;}
    break;

  case 15:
#line 73 "mini_l.y"
    {printf("id_loop -> ident\n");;}
    break;

  case 16:
#line 74 "mini_l.y"
    {printf("id_loop -> id_loop COMMA ident\n");;}
    break;

  case 17:
#line 75 "mini_l.y"
    {yyerrok; yyerror("Syntax error, missing comma inbetween identifiers.");;}
    break;

  case 18:
#line 78 "mini_l.y"
    {printf("assignment -> INTEGER\n");;}
    break;

  case 19:
#line 79 "mini_l.y"
    {printf("assignment -> ARRAY L_SQUARE_BRACKET NUMBER %d R_SQUARE_BRACKET OF INTEGER\n", (yyvsp[(3) - (6)].no_val));;}
    break;

  case 20:
#line 81 "mini_l.y"
    {printf("assignment -> ARRAY L_SQUARE_BRACKET NUMBER %d R_SQUARE_BRACKET L_SQUARE_BRACKET NUMBER %d R_SQUARE_BRACKET OF INTEGER\n", (yyvsp[(3) - (9)].no_val), (yyvsp[(6) - (9)].no_val));;}
    break;

  case 21:
#line 84 "mini_l.y"
    {printf("statement -> A\n");;}
    break;

  case 22:
#line 85 "mini_l.y"
    {printf("statement -> B\n");;}
    break;

  case 23:
#line 86 "mini_l.y"
    {printf("statement -> C\n");;}
    break;

  case 24:
#line 87 "mini_l.y"
    {printf("statement -> D\n");;}
    break;

  case 25:
#line 88 "mini_l.y"
    {printf("statement -> E\n");;}
    break;

  case 26:
#line 89 "mini_l.y"
    {printf("statement -> F\n");;}
    break;

  case 27:
#line 90 "mini_l.y"
    {printf("statement -> G\n");;}
    break;

  case 28:
#line 91 "mini_l.y"
    {printf("statement -> H\n");;}
    break;

  case 29:
#line 92 "mini_l.y"
    {printf("statement -> I\n");;}
    break;

  case 30:
#line 95 "mini_l.y"
    {printf("A -> var ASSIGN expression\n");;}
    break;

  case 31:
#line 96 "mini_l.y"
    {yyerrok; yyerror("Syntax error, \":=\" expected.");;}
    break;

  case 32:
#line 99 "mini_l.y"
    {printf("B -> IF bool_expr THEN statement_loop ENDIF\n");;}
    break;

  case 33:
#line 100 "mini_l.y"
    {printf("B -> IF bool_expr THEN statement_loop ELSE statement_loop ENDIF\n");;}
    break;

  case 34:
#line 103 "mini_l.y"
    {printf("C -> WHILE bool_expr BEGINLOOP statement_loop ENDLOOP\n");;}
    break;

  case 35:
#line 106 "mini_l.y"
    {printf("D -> DO BEGINLOOP statement_loop ENDLOOP WHILE bool_expr");;}
    break;

  case 36:
#line 110 "mini_l.y"
    {
      printf("E -> FOR var ASSIGN NUMBER %d SEMICOLON bool_expr SEMICOLON var ASSIGN expression BEGINLOOP statement_loop ENDLOOP\n", (yyvsp[(4) - (13)].no_val));
   ;}
    break;

  case 37:
#line 114 "mini_l.y"
    {
      {yyerrok; yyerror("Syntax error, missing first comma in for loop");}
   ;}
    break;

  case 38:
#line 118 "mini_l.y"
    {
      {yyerrok; yyerror("Syntax error, missing second comma in for loop");}
   ;}
    break;

  case 39:
#line 123 "mini_l.y"
    {printf("F -> READ var_loop\n");;}
    break;

  case 40:
#line 126 "mini_l.y"
    {printf("G -> WRITE var_loop\n");;}
    break;

  case 41:
#line 129 "mini_l.y"
    {printf("var_loop -> var\n");;}
    break;

  case 42:
#line 130 "mini_l.y"
    {printf("var_loop -> var COMMA var_loop \n");;}
    break;

  case 43:
#line 131 "mini_l.y"
    {printf("Syntax error at line %d position %d: Missing comma in variable list.\n", num_lines, num_column);;}
    break;

  case 44:
#line 134 "mini_l.y"
    {printf("H -> CONTINUE\n");;}
    break;

  case 45:
#line 136 "mini_l.y"
    {printf("I -> RETURN expression\n");;}
    break;

  case 46:
#line 138 "mini_l.y"
    {printf("bool_expr -> relation_and_expr bool_expr_loop\n");;}
    break;

  case 47:
#line 140 "mini_l.y"
    {printf("bool_expr_loop -> epsilon\n");;}
    break;

  case 48:
#line 141 "mini_l.y"
    {printf("bool_expr_loop -> bool_expr_loop OR relation_and_expr\n");;}
    break;

  case 49:
#line 144 "mini_l.y"
    {printf("relation_and_expr -> relation_expr relation_and_expr_loop\n");;}
    break;

  case 50:
#line 146 "mini_l.y"
    {printf("relation_and_expr_loop -> epsilon\n");;}
    break;

  case 51:
#line 147 "mini_l.y"
    {printf("relation_and_expr_loop -> relation_and_expr_loop AND relation_expr\n");;}
    break;

  case 52:
#line 150 "mini_l.y"
    {printf("relation_expr -> relations\n");;}
    break;

  case 53:
#line 151 "mini_l.y"
    {printf("relation_expr -> NOT relations\n");;}
    break;

  case 54:
#line 153 "mini_l.y"
    {printf("relations -> expression comp expression\n");;}
    break;

  case 55:
#line 154 "mini_l.y"
    {printf("relations -> TRUE\n");;}
    break;

  case 56:
#line 155 "mini_l.y"
    {printf("relations -> FALSE\n");;}
    break;

  case 57:
#line 156 "mini_l.y"
    {printf("relations -> L_PAREN bool_expr R_PAREN\n");;}
    break;

  case 58:
#line 159 "mini_l.y"
    {printf("comp -> EQ\n");;}
    break;

  case 59:
#line 160 "mini_l.y"
    {printf("comp -> NEQ\n");;}
    break;

  case 60:
#line 161 "mini_l.y"
    {printf("comp -> LT\n");;}
    break;

  case 61:
#line 162 "mini_l.y"
    {printf("comp -> GT\n");;}
    break;

  case 62:
#line 163 "mini_l.y"
    {printf("comp -> LTE\n");;}
    break;

  case 63:
#line 164 "mini_l.y"
    {printf("comp -> GTE\n");;}
    break;

  case 64:
#line 167 "mini_l.y"
    {printf("expression -> multiplicative_expr expression_loop\n");;}
    break;

  case 65:
#line 169 "mini_l.y"
    {printf("expression_loop -> EPSILON\n");;}
    break;

  case 66:
#line 170 "mini_l.y"
    {printf("expression_loop ->  expression_loop ADD multiplicative_expr\n");;}
    break;

  case 67:
#line 171 "mini_l.y"
    {printf("expression_loop -> expression_loop SUB multiplicative_expr\n");;}
    break;

  case 68:
#line 174 "mini_l.y"
    {printf("multiplicative_expr -> term multi_loop\n");;}
    break;

  case 69:
#line 176 "mini_l.y"
    {printf("multi_loop -> EPSILON\n");;}
    break;

  case 70:
#line 177 "mini_l.y"
    {printf("multi_loop -> multi_loop MULT term\n");;}
    break;

  case 71:
#line 178 "mini_l.y"
    {printf("multi_loop -> multi_loop DIV term\n");;}
    break;

  case 72:
#line 179 "mini_l.y"
    {printf("multi_loop -> multi_loop MOD term\n");;}
    break;

  case 73:
#line 182 "mini_l.y"
    {printf("term -> term_top\n");;}
    break;

  case 74:
#line 183 "mini_l.y"
    {printf("term -> SUB term_top\n");;}
    break;

  case 75:
#line 184 "mini_l.y"
    {printf("term -> ident term_expression\n");;}
    break;

  case 76:
#line 186 "mini_l.y"
    {printf("term_top -> var\n");;}
    break;

  case 77:
#line 187 "mini_l.y"
    {printf("term_top -> NUMBER %d\n", (yyvsp[(1) - (1)].no_val));;}
    break;

  case 78:
#line 188 "mini_l.y"
    {printf("term_top -> L_PAREN expression R_PAREN\n");;}
    break;

  case 79:
#line 190 "mini_l.y"
    {printf("term_expression -> L_PAREN term_exp R_PAREN\n");;}
    break;

  case 80:
#line 191 "mini_l.y"
    {printf("term_expression -> L_PAREN R_PAREN\n");;}
    break;

  case 81:
#line 193 "mini_l.y"
    {printf("term_exp -> expression\n");;}
    break;

  case 82:
#line 194 "mini_l.y"
    {printf("term_exp -> expression COMMA term_exp");;}
    break;

  case 83:
#line 195 "mini_l.y"
    {yyerrok; yyerror("Syntax error, missing comma inbetween expressions.");;}
    break;

  case 84:
#line 198 "mini_l.y"
    {printf("var -> ident\n");;}
    break;

  case 85:
#line 199 "mini_l.y"
    {printf("var -> ident L_SQUARE_BRACKET expression R_SQUARE_BRACKET\n");;}
    break;

  case 86:
#line 201 "mini_l.y"
    {
         printf("var -> ident L_SQUARE_BRACKET expression R_SQUARE_BRACKET L_SQUARE_BRACKET expression R_SQUARE_BRACKET\n");
      ;}
    break;

  case 87:
#line 206 "mini_l.y"
    {printf("ident -> IDENT %s\n", yytext);;}
    break;


/* Line 1267 of yacc.c.  */
#line 2071 "y.tab.c"
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


#line 209 "mini_l.y"

                            /* End of grammar */
// Additional C code
int main(int argc, char **argv) {
   if (argc > 1) {
      yyin = fopen(argv[1], "r");
      if (yyin == NULL){
         printf("syntax: %s filename\n", argv[0]);
      }//end if
   }//end if
   yyparse(); // Calls yylex() for tokens.
   return 0;
}

void yyerror(const char *msg) {
	printf("Line %d, pos %d:\n Error: %s\n", num_lines, num_column, msg);
}
