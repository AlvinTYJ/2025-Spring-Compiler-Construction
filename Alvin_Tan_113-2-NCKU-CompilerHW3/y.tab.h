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
    LSHIFT = 258,                  /* LSHIFT  */
    LOR = 259,                     /* LOR  */
    LAND = 260,                    /* LAND  */
    GEQ = 261,                     /* GEQ  */
    LEQ = 262,                     /* LEQ  */
    EQL = 263,                     /* EQL  */
    NEQ = 264,                     /* NEQ  */
    AS = 265,                      /* AS  */
    UMINUS = 266,                  /* UMINUS  */
    ELSE = 267,                    /* ELSE  */
    IF_NO_ELSE = 268,              /* IF_NO_ELSE  */
    LET = 269,                     /* LET  */
    MUT = 270,                     /* MUT  */
    NEWLINE = 271,                 /* NEWLINE  */
    INT = 272,                     /* INT  */
    FLOAT = 273,                   /* FLOAT  */
    BOOL = 274,                    /* BOOL  */
    STR = 275,                     /* STR  */
    TRUE = 276,                    /* TRUE  */
    FALSE = 277,                   /* FALSE  */
    ADD_ASSIGN = 278,              /* ADD_ASSIGN  */
    SUB_ASSIGN = 279,              /* SUB_ASSIGN  */
    MUL_ASSIGN = 280,              /* MUL_ASSIGN  */
    DIV_ASSIGN = 281,              /* DIV_ASSIGN  */
    REM_ASSIGN = 282,              /* REM_ASSIGN  */
    IF = 283,                      /* IF  */
    FOR = 284,                     /* FOR  */
    WHILE = 285,                   /* WHILE  */
    LOOP = 286,                    /* LOOP  */
    PRINT = 287,                   /* PRINT  */
    PRINTLN = 288,                 /* PRINTLN  */
    FUNC = 289,                    /* FUNC  */
    RETURN = 290,                  /* RETURN  */
    BREAK = 291,                   /* BREAK  */
    ARROW = 292,                   /* ARROW  */
    IN = 293,                      /* IN  */
    DOTDOT = 294,                  /* DOTDOT  */
    RSHIFT = 295,                  /* RSHIFT  */
    INT_LIT = 296,                 /* INT_LIT  */
    FLOAT_LIT = 297,               /* FLOAT_LIT  */
    STRING_LIT = 298,              /* STRING_LIT  */
    ID = 299                       /* ID  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif
/* Token kinds.  */
#define YYEMPTY -2
#define YYEOF 0
#define YYerror 256
#define YYUNDEF 257
#define LSHIFT 258
#define LOR 259
#define LAND 260
#define GEQ 261
#define LEQ 262
#define EQL 263
#define NEQ 264
#define AS 265
#define UMINUS 266
#define ELSE 267
#define IF_NO_ELSE 268
#define LET 269
#define MUT 270
#define NEWLINE 271
#define INT 272
#define FLOAT 273
#define BOOL 274
#define STR 275
#define TRUE 276
#define FALSE 277
#define ADD_ASSIGN 278
#define SUB_ASSIGN 279
#define MUL_ASSIGN 280
#define DIV_ASSIGN 281
#define REM_ASSIGN 282
#define IF 283
#define FOR 284
#define WHILE 285
#define LOOP 286
#define PRINT 287
#define PRINTLN 288
#define FUNC 289
#define RETURN 290
#define BREAK 291
#define ARROW 292
#define IN 293
#define DOTDOT 294
#define RSHIFT 295
#define INT_LIT 296
#define FLOAT_LIT 297
#define STRING_LIT 298
#define ID 299

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 100 "compiler.y"

    int i_val;
    float f_val;
    char *s_val;
    ExprVal expr;
    int local_idx;

#line 163 "y.tab.h"

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
