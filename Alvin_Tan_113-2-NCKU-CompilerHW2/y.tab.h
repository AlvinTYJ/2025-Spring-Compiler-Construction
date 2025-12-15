/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    UMINUS = 258,                  /* UMINUS  */
    LET = 259,                     /* LET  */
    MUT = 260,                     /* MUT  */
    NEWLINE = 261,                 /* NEWLINE  */
    INT = 262,                     /* INT  */
    FLOAT = 263,                   /* FLOAT  */
    BOOL = 264,                    /* BOOL  */
    STR = 265,                     /* STR  */
    TRUE = 266,                    /* TRUE  */
    FALSE = 267,                   /* FALSE  */
    GEQ = 268,                     /* GEQ  */
    LEQ = 269,                     /* LEQ  */
    EQL = 270,                     /* EQL  */
    NEQ = 271,                     /* NEQ  */
    LOR = 272,                     /* LOR  */
    LAND = 273,                    /* LAND  */
    ADD_ASSIGN = 274,              /* ADD_ASSIGN  */
    SUB_ASSIGN = 275,              /* SUB_ASSIGN  */
    MUL_ASSIGN = 276,              /* MUL_ASSIGN  */
    DIV_ASSIGN = 277,              /* DIV_ASSIGN  */
    REM_ASSIGN = 278,              /* REM_ASSIGN  */
    IF = 279,                      /* IF  */
    ELSE = 280,                    /* ELSE  */
    FOR = 281,                     /* FOR  */
    WHILE = 282,                   /* WHILE  */
    LOOP = 283,                    /* LOOP  */
    PRINT = 284,                   /* PRINT  */
    PRINTLN = 285,                 /* PRINTLN  */
    FUNC = 286,                    /* FUNC  */
    RETURN = 287,                  /* RETURN  */
    BREAK = 288,                   /* BREAK  */
    ARROW = 289,                   /* ARROW  */
    AS = 290,                      /* AS  */
    IN = 291,                      /* IN  */
    DOTDOT = 292,                  /* DOTDOT  */
    RSHIFT = 293,                  /* RSHIFT  */
    LSHIFT = 294,                  /* LSHIFT  */
    INT_LIT = 295,                 /* INT_LIT  */
    FLOAT_LIT = 296,               /* FLOAT_LIT  */
    STRING_LIT = 297,              /* STRING_LIT  */
    ID = 298                       /* ID  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif
/* Token kinds.  */
#define YYEMPTY -2
#define YYEOF 0
#define YYerror 256
#define YYUNDEF 257
#define UMINUS 258
#define LET 259
#define MUT 260
#define NEWLINE 261
#define INT 262
#define FLOAT 263
#define BOOL 264
#define STR 265
#define TRUE 266
#define FALSE 267
#define GEQ 268
#define LEQ 269
#define EQL 270
#define NEQ 271
#define LOR 272
#define LAND 273
#define ADD_ASSIGN 274
#define SUB_ASSIGN 275
#define MUL_ASSIGN 276
#define DIV_ASSIGN 277
#define REM_ASSIGN 278
#define IF 279
#define ELSE 280
#define FOR 281
#define WHILE 282
#define LOOP 283
#define PRINT 284
#define PRINTLN 285
#define FUNC 286
#define RETURN 287
#define BREAK 288
#define ARROW 289
#define AS 290
#define IN 291
#define DOTDOT 292
#define RSHIFT 293
#define LSHIFT 294
#define INT_LIT 295
#define FLOAT_LIT 296
#define STRING_LIT 297
#define ID 298

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 73 "compiler.y"

    int i_val;
    float f_val;
    char *s_val;
    ExprVal expr;

#line 160 "y.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif

/* Location type.  */
#if ! defined YYLTYPE && ! defined YYLTYPE_IS_DECLARED
typedef struct YYLTYPE YYLTYPE;
struct YYLTYPE
{
  int first_line;
  int first_column;
  int last_line;
  int last_column;
};
# define YYLTYPE_IS_DECLARED 1
# define YYLTYPE_IS_TRIVIAL 1
#endif


extern YYSTYPE yylval;
extern YYLTYPE yylloc;

int yyparse (void);


#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
