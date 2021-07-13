/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton interface for Bison's Yacc-like parsers in C

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




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 17 "mini_l.y"
{ //struct for id/Numberz values
  char* id_val;
  int no_val;
}
/* Line 1529 of yacc.c.  */
#line 158 "y.tab.h"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE yylval;

