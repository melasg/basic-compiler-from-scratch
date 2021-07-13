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
	//old int counters for position from mini_l.l:
	extern int num_lines;
	extern int num_column;
	//error feu
	void yyerror(const char *msg) {
	printf("Line %d, pos %d:\n Error: %s\n", num_lines, num_column, msg);
	}
	int yylex(); //implicit function declaratioin

	extern FILE *yyin; //just in case lol


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
#line 20 "mini_l.y"
{ //struct for id/number values
  char* id_val;
  int no_val;
}
/* Line 193 of yacc.c.  */
#line 224 "y.tab.c"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 237 "y.tab.c"

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
#define YYLAST   378

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  53
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  27
/* YYNRULES -- Number of rules.  */
#define YYNRULES  77
/* YYNRULES -- Number of states.  */
#define YYNSTATES  181

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
      35,    39,    42,    45,    49,    53,    55,    62,    72,    76,
      80,    86,    94,   100,   107,   121,   135,   149,   152,   155,
     157,   160,   163,   164,   168,   171,   172,   176,   178,   181,
     185,   187,   189,   193,   195,   197,   199,   201,   203,   205,
     208,   209,   213,   217,   220,   221,   225,   229,   233,   235,
     238,   243,   246,   248,   252,   256,   258,   260,   264,   266,
     270,   273,   275,   280,   288,   290,   294,   298
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      54,     0,    -1,    55,    -1,    -1,    56,    55,    -1,     3,
      79,    30,     4,    57,     5,     6,    57,     7,     8,    59,
       9,    -1,    -1,    58,    30,    57,    -1,    58,     1,    57,
      -1,    78,    31,    60,    -1,    78,     1,    60,    -1,    61,
      30,    -1,    61,     1,    -1,    59,    61,    30,    -1,    59,
      61,     1,    -1,    10,    -1,    11,    35,    38,    36,    12,
      10,    -1,    11,    35,    38,    36,    35,    38,    36,    12,
      10,    -1,    77,    51,    69,    -1,    77,     1,    69,    -1,
      13,    62,    14,    59,    15,    -1,    13,    62,    14,    59,
      16,    59,    15,    -1,    17,    62,    20,    59,    21,    -1,
      18,    20,    59,    21,    17,    62,    -1,    19,    77,    51,
      38,    30,    62,    30,    77,    51,    69,    20,    59,    21,
      -1,    19,    77,    51,    38,     1,    62,    30,    77,    51,
      69,    20,    59,    21,    -1,    19,    77,    51,    38,    30,
      62,     1,    77,    51,    69,    20,    59,    21,    -1,    23,
      76,    -1,    24,    76,    -1,    22,    -1,    29,    69,    -1,
      64,    63,    -1,    -1,    63,    26,    64,    -1,    66,    65,
      -1,    -1,    65,    25,    66,    -1,    67,    -1,    52,    67,
      -1,    69,    68,    69,    -1,    27,    -1,    28,    -1,    33,
      62,    34,    -1,    44,    -1,    43,    -1,    42,    -1,    41,
      -1,    40,    -1,    39,    -1,    71,    70,    -1,    -1,    70,
      48,    71,    -1,    70,    49,    71,    -1,    73,    72,    -1,
      -1,    72,    47,    73,    -1,    72,    46,    73,    -1,    72,
      45,    73,    -1,    75,    -1,    49,    75,    -1,    79,    33,
      74,    34,    -1,    33,    34,    -1,    69,    -1,    69,    32,
      74,    -1,    69,     1,    74,    -1,    77,    -1,    38,    -1,
      33,    69,    34,    -1,    77,    -1,    77,    32,    76,    -1,
      77,    76,    -1,    79,    -1,    79,    35,    69,    36,    -1,
      79,    35,    69,    36,    35,    69,    36,    -1,    79,    -1,
      78,    32,    79,    -1,    78,     1,    79,    -1,    37,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    42,    42,    45,    46,    49,    53,    54,    55,    60,
      61,    64,    65,    66,    67,    71,    72,    73,    77,    77,
      78,    78,    79,    80,    81,    81,    81,    82,    83,    84,
      85,    90,    92,    93,    96,    98,    99,   102,   103,   105,
     106,   107,   108,   111,   112,   113,   114,   115,   116,   119,
     121,   122,   123,   126,   128,   129,   130,   131,   134,   135,
     136,   137,   140,   141,   142,   145,   146,   147,   151,   152,
     153,   156,   157,   158,   161,   162,   163,   166
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
  "ASSIGN", "NOT", "$accept", "Program", "prog_to_feu", "function",
  "declarations", "declaration", "statements", "assignment", "statement",
  "bool_expr", "bool_exprz", "relation_and_expr", "r_a_ez",
  "relation_expr", "relations", "comp", "expression", "expressions",
  "multiplicative_expr", "multiplicative_group", "term", "term_comma_err",
  "precedence", "varz", "var", "identz", "ident", 0
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
      58,    59,    59,    59,    59,    60,    60,    60,    61,    61,
      61,    61,    61,    61,    61,    61,    61,    61,    61,    61,
      61,    62,    63,    63,    64,    65,    65,    66,    66,    67,
      67,    67,    67,    68,    68,    68,    68,    68,    68,    69,
      70,    70,    70,    71,    72,    72,    72,    72,    73,    73,
      73,    73,    74,    74,    74,    75,    75,    75,    76,    76,
      76,    77,    77,    77,    78,    78,    78,    79
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     0,     2,    12,     0,     3,     3,     3,
       3,     2,     2,     3,     3,     1,     6,     9,     3,     3,
       5,     7,     5,     6,    13,    13,    13,     2,     2,     1,
       2,     2,     0,     3,     2,     0,     3,     1,     2,     3,
       1,     1,     3,     1,     1,     1,     1,     1,     1,     2,
       0,     3,     3,     2,     0,     3,     3,     3,     1,     2,
       4,     2,     1,     3,     3,     1,     1,     3,     1,     3,
       2,     1,     4,     7,     1,     3,     3,     1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       3,     0,     0,     2,     3,    77,     0,     1,     4,     0,
       6,     0,     0,     0,    74,     0,     6,     6,     0,     0,
       0,     6,     8,     7,    15,     0,    10,    76,     9,    75,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      29,     0,     0,     0,     0,     0,     0,    71,     0,     0,
      40,    41,     0,    66,     0,     0,     0,    32,    35,    37,
       0,    50,    54,    58,    65,    71,     0,     0,     0,    27,
      68,    28,     0,    30,     5,     0,    12,    11,     0,     0,
       0,    16,     0,    61,     0,     0,     0,    59,    38,     0,
      31,    34,    48,    47,    46,    45,    44,    43,     0,    49,
      53,     0,     0,     0,     0,     0,    70,     0,    14,    13,
      19,    18,     0,     0,    42,    67,     0,     0,     0,    39,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      69,    72,     0,    20,     0,    33,    36,    51,    52,    57,
      56,    55,     0,     0,    60,    22,     0,     0,     0,     0,
      17,     0,    64,    63,    23,     0,     0,     0,    21,     0,
       0,     0,    73,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    25,    26,
      24
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     2,     3,     4,    11,    12,    44,    26,    45,    56,
      90,    57,    91,    58,    59,    98,    60,    99,    61,   100,
      62,   126,    63,    69,    64,    13,    65
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -78
static const yytype_int16 yypact[] =
{
       9,   -11,    37,   -78,     9,   -78,     2,   -78,   -78,    55,
     -11,    63,     1,    17,   -78,    80,   -11,   -11,    13,    51,
     -11,   -11,   -78,   -78,   -78,    74,   -78,   -78,   -78,   -78,
      90,    76,   104,    83,   331,    32,   174,   174,   103,   -11,
     -78,   -11,   -11,    56,   168,     4,     0,    89,   115,    93,
     -78,   -78,   161,   -78,    -8,   329,   118,   -78,   -78,   -78,
     330,   -78,   -78,   -78,   -78,    40,   119,   331,    87,   -78,
      33,   -78,   114,   -78,   -78,     5,   -78,   -78,    56,    56,
      56,   -78,    98,   -78,   106,   175,    56,   -78,   -78,   331,
     123,   128,   -78,   -78,   -78,   -78,   -78,   -78,    56,    73,
      61,    56,   331,   229,   124,   -11,   -78,   122,   -78,   -78,
     -78,   -78,   121,   152,   -78,   -78,   212,   174,   174,   -78,
      56,    56,    56,    56,    56,    20,   134,   246,   153,    26,
     -78,   147,   159,   -78,   331,   -78,   -78,   -78,   -78,   -78,
     -78,   -78,    56,    56,   -78,   -78,   174,   174,   174,    56,
     -78,   263,   -78,   -78,   -78,   154,    27,   157,   -78,   -11,
     -11,   -11,   -78,   132,   145,   149,    56,    56,    56,   183,
     184,   186,   331,   331,   331,   280,   297,   314,   -78,   -78,
     -78
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -78,   -78,   204,   -78,    62,   -78,    -7,   201,   -40,   -30,
     -78,   105,   -78,   120,   166,   -78,    12,   -78,   -21,   -78,
     -77,   -62,   170,   -28,   -31,   -78,    -1
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -63
static const yytype_int16 yytable[] =
{
       6,    78,    16,    46,    75,    76,   108,    66,    68,    14,
      70,    70,     1,    46,    71,    14,    14,    27,    18,    29,
      14,   142,    84,    24,    25,    86,     5,   147,   160,     5,
      53,    17,     9,    47,    77,   109,    46,     7,    47,    70,
      47,    47,   106,    47,    48,   139,   140,   141,    19,    20,
       5,    79,   143,    47,   -62,    73,   148,   161,    46,    10,
     103,    24,    25,    75,    85,   105,    47,    49,    15,    47,
       5,    46,    46,   101,    70,    80,    75,   130,    22,    23,
     152,   153,   116,    30,   107,    46,    21,    75,    47,    72,
     110,   111,   112,     5,    53,   127,    46,    32,   107,   137,
     138,    47,    47,    46,    47,    54,   122,   123,   124,    31,
     119,    75,    34,   125,    33,    47,   154,   155,   156,    35,
      46,   120,   121,    67,    80,    81,    47,   151,   163,   164,
     165,    82,    89,    47,   113,    75,    75,    75,   104,   102,
     114,    46,    46,    46,    46,    46,    46,    72,    83,   117,
      47,     5,    53,   118,   125,   125,   115,   131,    47,    47,
      47,   157,   129,    54,   132,   175,   176,   177,   144,   150,
     146,    47,    47,    47,    47,    47,    47,    74,   169,   170,
     171,    36,   149,   166,   159,    37,    38,    39,    50,    51,
      40,    41,    42,   162,    52,    83,   167,    43,     5,    53,
     168,    50,    51,   172,   173,     5,   174,    52,     8,   115,
      54,     5,    53,    55,    92,    93,    94,    95,    96,    97,
      28,    88,   135,    54,    87,    36,    55,   133,   134,    37,
      38,    39,     0,     0,    40,    41,    42,     0,   136,     0,
       0,    43,    36,     0,     0,     0,    37,    38,    39,     5,
     128,    40,    41,    42,     0,     0,     0,     0,    43,    36,
       0,     0,     0,    37,    38,    39,     5,   145,    40,    41,
      42,     0,     0,     0,     0,    43,    36,     0,   158,     0,
      37,    38,    39,     5,     0,    40,    41,    42,     0,     0,
       0,     0,    43,    36,     0,     0,     0,    37,    38,    39,
       5,   178,    40,    41,    42,     0,     0,     0,     0,    43,
      36,     0,     0,     0,    37,    38,    39,     5,   179,    40,
      41,    42,     0,     0,     0,     0,    43,    36,     0,     0,
       0,    37,    38,    39,     5,   180,    40,    41,    42,     0,
       0,     0,     0,    43,    36,     0,     0,     0,    37,    38,
      39,     5,     0,    40,    41,    42,    50,    51,     0,     0,
      43,     0,    52,     0,     0,     0,     5,    53,     5,    92,
      93,    94,    95,    96,    97,     0,     0,     0,    54
};

static const yytype_int16 yycheck[] =
{
       1,     1,     1,    34,    44,     1,     1,    37,    39,    10,
      41,    42,     3,    44,    42,    16,    17,    18,     1,    20,
      21,     1,    52,    10,    11,    33,    37,     1,     1,    37,
      38,    30,    30,    34,    30,    30,    67,     0,    39,    70,
      41,    42,    70,    44,    12,   122,   123,   124,    31,    32,
      37,    51,    32,    54,    34,    43,    30,    30,    89,     4,
      67,    10,    11,   103,    52,    32,    67,    35,     5,    70,
      37,   102,   103,    33,   105,    35,   116,   105,    16,    17,
     142,   143,    89,    21,    72,   116,     6,   127,    89,    33,
      78,    79,    80,    37,    38,   102,   127,     7,    86,   120,
     121,   102,   103,   134,   105,    49,    45,    46,    47,    35,
      98,   151,     8,   101,    38,   116,   146,   147,   148,    36,
     151,    48,    49,    20,    35,    10,   127,   134,   159,   160,
     161,    38,    14,   134,    36,   175,   176,   177,    51,    20,
      34,   172,   173,   174,   175,   176,   177,    33,    34,    26,
     151,    37,    38,    25,   142,   143,    34,    36,   159,   160,
     161,   149,    38,    49,    12,   172,   173,   174,    34,    10,
      17,   172,   173,   174,   175,   176,   177,     9,   166,   167,
     168,    13,    35,    51,    30,    17,    18,    19,    27,    28,
      22,    23,    24,    36,    33,    34,    51,    29,    37,    38,
      51,    27,    28,    20,    20,    37,    20,    33,     4,    34,
      49,    37,    38,    52,    39,    40,    41,    42,    43,    44,
      19,    55,   117,    49,    54,    13,    52,    15,    16,    17,
      18,    19,    -1,    -1,    22,    23,    24,    -1,   118,    -1,
      -1,    29,    13,    -1,    -1,    -1,    17,    18,    19,    37,
      21,    22,    23,    24,    -1,    -1,    -1,    -1,    29,    13,
      -1,    -1,    -1,    17,    18,    19,    37,    21,    22,    23,
      24,    -1,    -1,    -1,    -1,    29,    13,    -1,    15,    -1,
      17,    18,    19,    37,    -1,    22,    23,    24,    -1,    -1,
      -1,    -1,    29,    13,    -1,    -1,    -1,    17,    18,    19,
      37,    21,    22,    23,    24,    -1,    -1,    -1,    -1,    29,
      13,    -1,    -1,    -1,    17,    18,    19,    37,    21,    22,
      23,    24,    -1,    -1,    -1,    -1,    29,    13,    -1,    -1,
      -1,    17,    18,    19,    37,    21,    22,    23,    24,    -1,
      -1,    -1,    -1,    29,    13,    -1,    -1,    -1,    17,    18,
      19,    37,    -1,    22,    23,    24,    27,    28,    -1,    -1,
      29,    -1,    33,    -1,    -1,    -1,    37,    38,    37,    39,
      40,    41,    42,    43,    44,    -1,    -1,    -1,    49
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,    54,    55,    56,    37,    79,     0,    55,    30,
       4,    57,    58,    78,    79,     5,     1,    30,     1,    31,
      32,     6,    57,    57,    10,    11,    60,    79,    60,    79,
      57,    35,     7,    38,     8,    36,    13,    17,    18,    19,
      22,    23,    24,    29,    59,    61,    77,    79,    12,    35,
      27,    28,    33,    38,    49,    52,    62,    64,    66,    67,
      69,    71,    73,    75,    77,    79,    62,    20,    77,    76,
      77,    76,    33,    69,     9,    61,     1,    30,     1,    51,
      35,    10,    38,    34,    62,    69,    33,    75,    67,    14,
      63,    65,    39,    40,    41,    42,    43,    44,    68,    70,
      72,    33,    20,    59,    51,    32,    76,    69,     1,    30,
      69,    69,    69,    36,    34,    34,    59,    26,    25,    69,
      48,    49,    45,    46,    47,    69,    74,    59,    21,    38,
      76,    36,    12,    15,    16,    64,    66,    71,    71,    73,
      73,    73,     1,    32,    34,    21,    17,     1,    30,    35,
      10,    59,    74,    74,    62,    62,    62,    69,    15,    30,
       1,    30,    36,    77,    77,    77,    51,    51,    51,    69,
      69,    69,    20,    20,    20,    59,    59,    59,    21,    21,
      21
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
#line 42 "mini_l.y"
    {printf("Program -> prog_to_feu\n");;}
    break;

  case 3:
#line 45 "mini_l.y"
    {printf("prog_to_feu -> ?\n");;}
    break;

  case 4:
#line 46 "mini_l.y"
    {printf("prog_to_feu -> function prog_to_feu\n");;}
    break;

  case 5:
#line 49 "mini_l.y"
    {
               printf("function -> FUNCTION ident SEMICOLON "); printf("BEGIN_PARAMS declarations END_PARAMS "); printf("BEGIN_LOCALS declarations END_LOCALS "); printf("BEGIN_BODY statements END_BODY\n"); ;}
    break;

  case 6:
#line 53 "mini_l.y"
    {printf("declarations -> ?\n");;}
    break;

  case 7:
#line 54 "mini_l.y"
    {printf("declarations -> declaration SEMICOLON declarations\n");;}
    break;

  case 8:
#line 55 "mini_l.y"
    {yyerrok; yyerror("Syntax error, missing semicolon in declaration."); ;}
    break;

  case 9:
#line 60 "mini_l.y"
    {printf("declaration -> identz COLON assignment\n");;}
    break;

  case 10:
#line 61 "mini_l.y"
    {yyerrok; yyerror("Syntax error, invalid declaration, missing colon.");;}
    break;

  case 11:
#line 64 "mini_l.y"
    {printf("statements -> statement SEMICOLON\n");;}
    break;

  case 12:
#line 65 "mini_l.y"
    {yyerrok; yyerror("Syntax error, missing semicolon in statement.");;}
    break;

  case 13:
#line 66 "mini_l.y"
    { printf("statements -> statements statement SEMICOLON\n");;}
    break;

  case 14:
#line 67 "mini_l.y"
    { yyerrok; yyerror("Syntax error, missing semicolon in statement."); ;}
    break;

  case 15:
#line 71 "mini_l.y"
    {printf("assignment -> INTEGER\n");;}
    break;

  case 16:
#line 72 "mini_l.y"
    {printf("assignment -> ARRAY L_SQUARE_BRACKET NUMBER %d R_SQUARE_BRACKET OF INTEGER\n", (yyvsp[(3) - (6)].no_val));;}
    break;

  case 17:
#line 74 "mini_l.y"
    {printf("assignment -> ARRAY L_SQUARE_BRACKET NUMBER %d R_SQUARE_BRACKET L_SQUARE_BRACKET NUMBER %d R_SQUARE_BRACKET OF INTEGER\n", (yyvsp[(3) - (9)].no_val), (yyvsp[(6) - (9)].no_val));;}
    break;

  case 18:
#line 77 "mini_l.y"
    {printf("A -> var ASSIGN expression\n");;}
    break;

  case 19:
#line 77 "mini_l.y"
    {yyerrok; yyerror("Syntax error, \":=\" expected.");;}
    break;

  case 20:
#line 78 "mini_l.y"
    {printf("B -> IF bool_expr THEN statements ENDIF\n");;}
    break;

  case 21:
#line 78 "mini_l.y"
    {printf("B -> IF bool_expr THEN statements ELSE statements ENDIF\n");;}
    break;

  case 22:
#line 79 "mini_l.y"
    {printf("C -> WHILE bool_expr BEGINLOOP statements ENDLOOP\n");;}
    break;

  case 23:
#line 80 "mini_l.y"
    {printf("D -> DO BEGINLOOP statements ENDLOOP WHILE bool_expr");;}
    break;

  case 24:
#line 81 "mini_l.y"
    { printf("E -> FOR var ASSIGN NUMBER %d SEMICOLON bool_expr SEMICOLON var ASSIGN expression BEGINLOOP statements ENDLOOP\n", (yyvsp[(4) - (13)].no_val)); ;}
    break;

  case 25:
#line 81 "mini_l.y"
    { {yyerrok; yyerror("Syntax error, missing first comma in for loop");} ;}
    break;

  case 26:
#line 81 "mini_l.y"
    { {yyerrok; yyerror("Syntax error, missing second comma in for loop");} ;}
    break;

  case 27:
#line 82 "mini_l.y"
    {printf("F -> READ varz\n");;}
    break;

  case 28:
#line 83 "mini_l.y"
    {printf("G -> WRITE varz\n");;}
    break;

  case 29:
#line 84 "mini_l.y"
    {printf("H -> CONTINUE\n");;}
    break;

  case 30:
#line 85 "mini_l.y"
    {printf("I -> RETURN expression\n");;}
    break;

  case 31:
#line 90 "mini_l.y"
    {printf("bool_expr -> relation_and_expr bool_exprz\n");;}
    break;

  case 32:
#line 92 "mini_l.y"
    {printf("bool_exprz -> ?\n");;}
    break;

  case 33:
#line 93 "mini_l.y"
    {printf("bool_exprz -> bool_exprz OR relation_and_expr\n");;}
    break;

  case 34:
#line 96 "mini_l.y"
    {printf("relation_and_expr -> relation_expr r_a_ez\n");;}
    break;

  case 35:
#line 98 "mini_l.y"
    {printf("r_a_ez -> ?\n");;}
    break;

  case 36:
#line 99 "mini_l.y"
    {printf("r_a_ez -> r_a_ez AND relation_expr\n");;}
    break;

  case 37:
#line 102 "mini_l.y"
    {printf("relation_expr -> relations\n");;}
    break;

  case 38:
#line 103 "mini_l.y"
    {printf("relation_expr -> NOT relations\n");;}
    break;

  case 39:
#line 105 "mini_l.y"
    {printf("relations -> expression comp expression\n");;}
    break;

  case 40:
#line 106 "mini_l.y"
    {printf("relations -> TRUE\n");;}
    break;

  case 41:
#line 107 "mini_l.y"
    {printf("relations -> FALSE\n");;}
    break;

  case 42:
#line 108 "mini_l.y"
    {printf("relations -> L_PAREN bool_expr R_PAREN\n");;}
    break;

  case 43:
#line 111 "mini_l.y"
    {printf("comp -> EQ\n");;}
    break;

  case 44:
#line 112 "mini_l.y"
    {printf("comp -> NEQ\n");;}
    break;

  case 45:
#line 113 "mini_l.y"
    {printf("comp -> LT\n");;}
    break;

  case 46:
#line 114 "mini_l.y"
    {printf("comp -> GT\n");;}
    break;

  case 47:
#line 115 "mini_l.y"
    {printf("comp -> LTE\n");;}
    break;

  case 48:
#line 116 "mini_l.y"
    {printf("comp -> GTE\n");;}
    break;

  case 49:
#line 119 "mini_l.y"
    {printf("expression -> multiplicative_expr expressions\n");;}
    break;

  case 50:
#line 121 "mini_l.y"
    {printf("expressions -> ?\n");;}
    break;

  case 51:
#line 122 "mini_l.y"
    {printf("expressions ->  expressions ADD multiplicative_expr\n");;}
    break;

  case 52:
#line 123 "mini_l.y"
    {printf("expressions -> expressions SUB multiplicative_expr\n");;}
    break;

  case 53:
#line 126 "mini_l.y"
    {printf("multiplicative_expr -> term multiplicative_group\n");;}
    break;

  case 54:
#line 128 "mini_l.y"
    {printf("multiplicative_group -> ?\n");;}
    break;

  case 55:
#line 129 "mini_l.y"
    {printf("multiplicative_group -> multiplicative_group MULT term\n");;}
    break;

  case 56:
#line 130 "mini_l.y"
    {printf("multiplicative_group -> multiplicative_group DIV term\n");;}
    break;

  case 57:
#line 131 "mini_l.y"
    {printf("multiplicative_group -> multiplicative_group MOD term\n");;}
    break;

  case 58:
#line 134 "mini_l.y"
    {printf("term -> precedence\n");;}
    break;

  case 59:
#line 135 "mini_l.y"
    {printf("term -> SUB precedence\n");;}
    break;

  case 60:
#line 136 "mini_l.y"
    {printf("term_expression -> L_PAREN term_comma_err R_PAREN\n");;}
    break;

  case 61:
#line 137 "mini_l.y"
    {printf("term_expression -> L_PAREN R_PAREN\n");;}
    break;

  case 62:
#line 140 "mini_l.y"
    {printf("term_comma_err -> expression\n");;}
    break;

  case 63:
#line 141 "mini_l.y"
    {printf("term_comma_err -> expression COMMA term_comma_err");;}
    break;

  case 64:
#line 142 "mini_l.y"
    {yyerrok; yyerror("Syntax error, missing comma between expressions.");;}
    break;

  case 65:
#line 145 "mini_l.y"
    {printf("precedence -> var\n");;}
    break;

  case 66:
#line 146 "mini_l.y"
    {printf("precedence -> NUMBER %d\n", (yyvsp[(1) - (1)].no_val));;}
    break;

  case 67:
#line 147 "mini_l.y"
    {printf("precedence -> L_PAREN expression R_PAREN\n");;}
    break;

  case 68:
#line 151 "mini_l.y"
    {printf("varz -> var\n");;}
    break;

  case 69:
#line 152 "mini_l.y"
    {printf("varz -> var COMMA varz \n");;}
    break;

  case 70:
#line 153 "mini_l.y"
    {printf("Syntax error at line %d position %d: Missing comma in variable list.\n", num_lines, num_column);;}
    break;

  case 71:
#line 156 "mini_l.y"
    {printf("var -> ident\n");;}
    break;

  case 72:
#line 157 "mini_l.y"
    {printf("var -> ident L_SQUARE_BRACKET expression R_SQUARE_BRACKET\n");;}
    break;

  case 73:
#line 158 "mini_l.y"
    { printf("var -> ident L_SQUARE_BRACKET expression R_SQUARE_BRACKET L_SQUARE_BRACKET expression R_SQUARE_BRACKET\n"); ;}
    break;

  case 74:
#line 161 "mini_l.y"
    {printf("identz -> ident\n");;}
    break;

  case 75:
#line 162 "mini_l.y"
    {printf("identz -> identz COMMA ident\n");;}
    break;

  case 76:
#line 163 "mini_l.y"
    {yyerrok; yyerror("Syntax error, missing comma.");;}
    break;

  case 77:
#line 166 "mini_l.y"
    {printf("ident -> IDENT %s\n", yytext);;}
    break;


/* Line 1267 of yacc.c.  */
#line 2007 "y.tab.c"
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


#line 169 "mini_l.y"

                            /* End of grammar */
// Additional C code
int main(int argc, char **argv) {
   if (argc > 1) {
      yyin = fopen(argv[1], "r");
      if (yyin == NULL){
         printf("syntax: %s filename\n", argv[0]);
    } // else {
	// 	  yyin == stdin;
	//   }
   }
   yyparse(); // Calls yylex() for tokens.
   return 0;
}
