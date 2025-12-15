/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 2 "compiler.y"

    #include "compiler_common.h"
    int label_counter = 0;
    int for_counter = 0;
    bool in_loop_context = false;
    bool inside_while_stmt = false;
    bool should_emit_label = false;

    /* Symbol table entry */
    typedef struct {
        char name[64];
        int addr;
        char type[8];
        int lineno;
        int i_val;
        float f_val;
        char *s_val;
        int scope;
        int mut;
    } Symbol;

    /* Global variables */
    bool HAS_ERROR = false;
    int scope = 0;

    /* Symbol table and helpers */
    static Symbol symtab[100];
    static int symtab_sz = 0;
    static int addr_count = 0;
    static int label_count = 0;
    int local_var_index = 1;

    extern int yylineno;
    extern int yylex();
    extern FILE *yyin;
    extern FILE *yyout;

    int yylex_destroy ();
    void yyerror (char const *s)
    {
        printf("[yyerror] %s at line %d\n", s, yylineno);
    }

    int alloc_local_i32(void) {
        return local_var_index++;
    }

    int alloc_local_f32(void) {
        return local_var_index++;
    }

    int alloc_local_ref(void) {
        return local_var_index++;
    }

    /* Symbol table function - you can add new functions if needed. */
    /* parameters and return type can be changed */
    static void create_symbol(int scope);
    static void insert_symbol(const char *name, int addr, int scope);
    static void dump_symbol(int scope);
    static void pop_scope(int scope); 
    static void add_symbol(const char *name, int addr, const char *type, int lineno, ExprVal value, int mut);
    static ExprVal get_expr_val(const char *name);
    static int lookup_symbol(const char *name);
    void dump_all_symbols(void) {
        printf("%-10s%-10s%-10s%-10s%-10s%-10s%-10s\n",
            "Index", "Name", "Mut", "Type", "Addr", "Lineno", "Scope");
        for (int i = 0; i < symtab_sz; i++) {
            printf("%-10d%-10s%-10d%-10s%-10d%-10d%-10d\n",
                i,
                symtab[i].name,
                symtab[i].mut,
                symtab[i].type,
                symtab[i].addr,
                symtab[i].lineno,
                symtab[i].scope);
        }
    }

#line 151 "y.tab.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

/* Use api.header.include to #include this header
   instead of duplicating it here.  */
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

#line 300 "y.tab.c"

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
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_LSHIFT = 3,                     /* LSHIFT  */
  YYSYMBOL_LOR = 4,                        /* LOR  */
  YYSYMBOL_LAND = 5,                       /* LAND  */
  YYSYMBOL_6_ = 6,                         /* '>'  */
  YYSYMBOL_7_ = 7,                         /* '<'  */
  YYSYMBOL_GEQ = 8,                        /* GEQ  */
  YYSYMBOL_LEQ = 9,                        /* LEQ  */
  YYSYMBOL_EQL = 10,                       /* EQL  */
  YYSYMBOL_NEQ = 11,                       /* NEQ  */
  YYSYMBOL_12_ = 12,                       /* '+'  */
  YYSYMBOL_13_ = 13,                       /* '-'  */
  YYSYMBOL_14_ = 14,                       /* '*'  */
  YYSYMBOL_15_ = 15,                       /* '/'  */
  YYSYMBOL_16_ = 16,                       /* '%'  */
  YYSYMBOL_AS = 17,                        /* AS  */
  YYSYMBOL_18_ = 18,                       /* '!'  */
  YYSYMBOL_UMINUS = 19,                    /* UMINUS  */
  YYSYMBOL_ELSE = 20,                      /* ELSE  */
  YYSYMBOL_IF_NO_ELSE = 21,                /* IF_NO_ELSE  */
  YYSYMBOL_LET = 22,                       /* LET  */
  YYSYMBOL_MUT = 23,                       /* MUT  */
  YYSYMBOL_NEWLINE = 24,                   /* NEWLINE  */
  YYSYMBOL_INT = 25,                       /* INT  */
  YYSYMBOL_FLOAT = 26,                     /* FLOAT  */
  YYSYMBOL_BOOL = 27,                      /* BOOL  */
  YYSYMBOL_STR = 28,                       /* STR  */
  YYSYMBOL_TRUE = 29,                      /* TRUE  */
  YYSYMBOL_FALSE = 30,                     /* FALSE  */
  YYSYMBOL_ADD_ASSIGN = 31,                /* ADD_ASSIGN  */
  YYSYMBOL_SUB_ASSIGN = 32,                /* SUB_ASSIGN  */
  YYSYMBOL_MUL_ASSIGN = 33,                /* MUL_ASSIGN  */
  YYSYMBOL_DIV_ASSIGN = 34,                /* DIV_ASSIGN  */
  YYSYMBOL_REM_ASSIGN = 35,                /* REM_ASSIGN  */
  YYSYMBOL_IF = 36,                        /* IF  */
  YYSYMBOL_FOR = 37,                       /* FOR  */
  YYSYMBOL_WHILE = 38,                     /* WHILE  */
  YYSYMBOL_LOOP = 39,                      /* LOOP  */
  YYSYMBOL_PRINT = 40,                     /* PRINT  */
  YYSYMBOL_PRINTLN = 41,                   /* PRINTLN  */
  YYSYMBOL_FUNC = 42,                      /* FUNC  */
  YYSYMBOL_RETURN = 43,                    /* RETURN  */
  YYSYMBOL_BREAK = 44,                     /* BREAK  */
  YYSYMBOL_ARROW = 45,                     /* ARROW  */
  YYSYMBOL_IN = 46,                        /* IN  */
  YYSYMBOL_DOTDOT = 47,                    /* DOTDOT  */
  YYSYMBOL_RSHIFT = 48,                    /* RSHIFT  */
  YYSYMBOL_INT_LIT = 49,                   /* INT_LIT  */
  YYSYMBOL_FLOAT_LIT = 50,                 /* FLOAT_LIT  */
  YYSYMBOL_STRING_LIT = 51,                /* STRING_LIT  */
  YYSYMBOL_ID = 52,                        /* ID  */
  YYSYMBOL_53_ = 53,                       /* '('  */
  YYSYMBOL_54_ = 54,                       /* ')'  */
  YYSYMBOL_55_ = 55,                       /* '{'  */
  YYSYMBOL_56_ = 56,                       /* '}'  */
  YYSYMBOL_57_ = 57,                       /* '='  */
  YYSYMBOL_58_ = 58,                       /* ';'  */
  YYSYMBOL_59_ = 59,                       /* ':'  */
  YYSYMBOL_60_ = 60,                       /* ','  */
  YYSYMBOL_61_ = 61,                       /* '['  */
  YYSYMBOL_62_ = 62,                       /* ']'  */
  YYSYMBOL_63_ = 63,                       /* '&'  */
  YYSYMBOL_YYACCEPT = 64,                  /* $accept  */
  YYSYMBOL_Program = 65,                   /* Program  */
  YYSYMBOL_66_1 = 66,                      /* $@1  */
  YYSYMBOL_GlobalStatementList = 67,       /* GlobalStatementList  */
  YYSYMBOL_GlobalStatement = 68,           /* GlobalStatement  */
  YYSYMBOL_FunctionDeclStmt = 69,          /* FunctionDeclStmt  */
  YYSYMBOL_70_2 = 70,                      /* $@2  */
  YYSYMBOL_FuncHeader = 71,                /* FuncHeader  */
  YYSYMBOL_Block = 72,                     /* Block  */
  YYSYMBOL_73_3 = 73,                      /* $@3  */
  YYSYMBOL_74_4 = 74,                      /* $@4  */
  YYSYMBOL_StatementList = 75,             /* StatementList  */
  YYSYMBOL_Condition = 76,                 /* Condition  */
  YYSYMBOL_StmtBlock = 77,                 /* StmtBlock  */
  YYSYMBOL_78_5 = 78,                      /* $@5  */
  YYSYMBOL_IfStmt = 79,                    /* IfStmt  */
  YYSYMBOL_IfOnlyStmt = 80,                /* IfOnlyStmt  */
  YYSYMBOL_81_6 = 81,                      /* $@6  */
  YYSYMBOL_IfElseStmt = 82,                /* IfElseStmt  */
  YYSYMBOL_83_7 = 83,                      /* $@7  */
  YYSYMBOL_84_8 = 84,                      /* $@8  */
  YYSYMBOL_OptNewline = 85,                /* OptNewline  */
  YYSYMBOL_IfExitLabel = 86,               /* IfExitLabel  */
  YYSYMBOL_IfElseLabels = 87,              /* IfElseLabels  */
  YYSYMBOL_WhileStmt = 88,                 /* WhileStmt  */
  YYSYMBOL_89_9 = 89,                      /* $@9  */
  YYSYMBOL_90_10 = 90,                     /* $@10  */
  YYSYMBOL_Statement = 91,                 /* Statement  */
  YYSYMBOL_92_11 = 92,                     /* $@11  */
  YYSYMBOL_93_12 = 93,                     /* $@12  */
  YYSYMBOL_ArrayElems = 94,                /* ArrayElems  */
  YYSYMBOL_ArrayLiteral = 95,              /* ArrayLiteral  */
  YYSYMBOL_Expression = 96,                /* Expression  */
  YYSYMBOL_Type = 97                       /* Type  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_uint8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if 1

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
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
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
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* 1 */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL \
             && defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
  YYLTYPE yyls_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE) \
             + YYSIZEOF (YYLTYPE)) \
      + 2 * YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  3
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   554

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  64
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  34
/* YYNRULES -- Number of rules.  */
#define YYNRULES  86
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  170

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   299


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    18,     2,     2,     2,    16,    63,     2,
      53,    54,    14,    12,    60,    13,     2,    15,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    59,    58,
       7,    57,     6,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    61,     2,    62,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    55,     2,    56,     2,     2,     2,     2,
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
       5,     8,     9,    10,    11,    17,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   141,   141,   141,   172,   173,   177,   178,   182,   182,
     188,   196,   202,   195,   214,   215,   219,   233,   232,   249,
     250,   255,   254,   268,   275,   267,   289,   290,   294,   298,
     306,   310,   306,   327,   328,   329,   330,   336,   342,   349,
     356,   362,   404,   447,   447,   478,   478,   508,   509,   511,
     544,   564,   588,   612,   636,   668,   695,   696,   700,   707,
     746,   754,   762,   770,   798,   826,   854,   892,   914,   945,
     976,   997,  1014,  1031,  1049,  1052,  1068,  1084,  1094,  1103,
    1109,  1115,  1136,  1137,  1138,  1139,  1140
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if 1
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "LSHIFT", "LOR",
  "LAND", "'>'", "'<'", "GEQ", "LEQ", "EQL", "NEQ", "'+'", "'-'", "'*'",
  "'/'", "'%'", "AS", "'!'", "UMINUS", "ELSE", "IF_NO_ELSE", "LET", "MUT",
  "NEWLINE", "INT", "FLOAT", "BOOL", "STR", "TRUE", "FALSE", "ADD_ASSIGN",
  "SUB_ASSIGN", "MUL_ASSIGN", "DIV_ASSIGN", "REM_ASSIGN", "IF", "FOR",
  "WHILE", "LOOP", "PRINT", "PRINTLN", "FUNC", "RETURN", "BREAK", "ARROW",
  "IN", "DOTDOT", "RSHIFT", "INT_LIT", "FLOAT_LIT", "STRING_LIT", "ID",
  "'('", "')'", "'{'", "'}'", "'='", "';'", "':'", "','", "'['", "']'",
  "'&'", "$accept", "Program", "$@1", "GlobalStatementList",
  "GlobalStatement", "FunctionDeclStmt", "$@2", "FuncHeader", "Block",
  "$@3", "$@4", "StatementList", "Condition", "StmtBlock", "$@5", "IfStmt",
  "IfOnlyStmt", "$@6", "IfElseStmt", "$@7", "$@8", "OptNewline",
  "IfExitLabel", "IfElseLabels", "WhileStmt", "$@9", "$@10", "Statement",
  "$@11", "$@12", "ArrayElems", "ArrayLiteral", "Expression", "Type", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-98)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-28)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -98,    13,   -20,   -98,   -98,   -29,   -20,   -98,   -98,   -25,
     -98,   -98,   -23,   -98,   -10,   -98,   -98,   -98,   499,    69,
     -98,   466,   -98,    -3,    15,    63,   -98,    37,   -17,   -98,
     -98,   -98,   -98,    47,   -33,   466,   466,   -98,   -98,   -98,
     -98,   -98,   -98,   466,   -98,   448,   466,   -98,   -98,   466,
     466,   466,   466,   466,   466,   466,   -98,   -98,    81,   -30,
     466,    97,    42,    42,    48,   -98,   -98,   466,   466,   466,
     466,   466,   466,   466,   466,   466,   466,   466,   466,    97,
      76,   -98,   466,   466,    68,   101,   127,   160,   186,   219,
     245,    64,   466,    97,   278,   -98,   -98,   -98,    97,   108,
      19,   -98,    64,    64,   318,   428,   409,    74,    74,    74,
      74,    -5,    -5,   -15,   -15,   -15,   -98,    83,    64,   304,
     337,   -98,   -98,   -98,   -98,   -98,   -98,   -98,   -98,   -98,
     356,    70,   -98,    88,   -98,   453,   -98,   -98,   123,   -98,
     -98,    90,    91,   -98,   -98,   466,   -98,   102,   103,    92,
     371,   -98,   -98,   -98,   486,   389,    93,   -98,     7,   -98,
     -98,   133,   -98,   -98,   -98,   105,   -98,    64,   -98,   -98
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       2,     0,     0,     1,     7,     0,     3,     5,     6,     0,
      10,     4,     0,     8,     0,    11,     9,    15,    12,     0,
      48,     0,    30,     0,     0,     0,    47,     0,    33,    20,
      19,    35,    14,     0,     0,     0,     0,    79,    80,    60,
      61,    62,    59,     0,    28,    16,     0,    45,    43,     0,
       0,     0,     0,     0,     0,     0,    13,    26,     0,     0,
       0,     0,    73,    72,     0,    21,    23,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    31,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    82,    83,    84,     0,     0,
       0,    74,     0,     0,    78,    71,    70,    68,    69,    75,
      76,    63,    64,    65,    66,    67,    81,     0,     0,     0,
       0,    50,    51,    52,    53,    54,    55,    49,    17,    34,
       0,     0,    36,     0,    85,     0,    38,    22,    27,    77,
      32,     0,     0,    15,    37,     0,    39,     0,     0,     0,
       0,    24,    46,    44,     0,     0,     0,    56,     0,    40,
      41,     0,    18,    42,    86,     0,    58,     0,    57,    25
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -98,   -98,   -98,   -98,   150,   -98,   -98,   -98,   143,   -98,
     -98,    18,   122,   -97,   -98,   -98,   -98,   -98,   -98,   -98,
     -98,    31,   -98,   -98,   -98,   -98,   -98,   -98,   -98,   -98,
     -98,   -98,   -35,   -49
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     1,     2,     6,     7,     8,    14,     9,    26,    17,
      27,    18,    44,   129,   143,    28,    29,   102,    30,   103,
     161,    58,    65,    66,    31,    46,   118,    32,    83,    82,
     158,   149,    45,   100
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      62,    63,    79,   -27,     4,   137,   138,    57,    64,    76,
      77,    78,    79,     3,    84,    85,    86,    87,    88,    89,
      90,   140,     5,    10,    60,    94,    61,    92,    12,    93,
     116,    13,   104,   105,   106,   107,   108,   109,   110,   111,
     112,   113,   114,   115,   131,    15,    80,   119,   120,   133,
      47,    67,    68,    69,    70,    71,    80,   130,    72,    73,
      74,    75,    76,    77,    78,    79,    49,   165,    48,   166,
     169,    67,    68,    69,    70,    71,   135,   136,    72,    73,
      74,    75,    76,    77,    78,    79,    74,    75,    76,    77,
      78,    79,    33,    56,    50,    51,    52,    53,    54,    59,
     150,    91,   101,    80,    67,    68,    69,    70,    71,    80,
     155,    72,    73,    74,    75,    76,    77,    78,    79,   128,
      55,    34,    95,    96,    97,   117,   121,   145,   146,    80,
      67,    68,    69,    70,    71,    80,   134,    72,    73,    74,
      75,    76,    77,    78,    79,   139,   147,    57,   152,   153,
     159,   156,   157,   167,   168,   164,    11,    16,    98,   122,
      99,   154,    80,    67,    68,    69,    70,    71,    81,   151,
      72,    73,    74,    75,    76,    77,    78,    79,     0,     0,
       0,     0,     0,     0,     0,   123,     0,     0,    80,    67,
      68,    69,    70,    71,     0,     0,    72,    73,    74,    75,
      76,    77,    78,    79,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   124,     0,
       0,    80,    67,    68,    69,    70,    71,     0,     0,    72,
      73,    74,    75,    76,    77,    78,    79,     0,     0,     0,
       0,     0,     0,     0,   125,     0,     0,    80,    67,    68,
      69,    70,    71,     0,     0,    72,    73,    74,    75,    76,
      77,    78,    79,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   126,     0,     0,
      80,    67,    68,    69,    70,    71,     0,     0,    72,    73,
      74,    75,    76,    77,    78,    79,     0,     0,     0,     0,
       0,     0,     0,   127,     0,     0,    80,    67,    68,    69,
      70,    71,     0,     0,    72,    73,    74,    75,    76,    77,
      78,    79,    68,    69,    70,    71,     0,     0,    72,    73,
      74,    75,    76,    77,    78,    79,   132,     0,     0,    80,
      67,    68,    69,    70,    71,     0,     0,    72,    73,    74,
      75,    76,    77,    78,    79,     0,     0,     0,   141,    67,
      68,    69,    70,    71,     0,    80,    72,    73,    74,    75,
      76,    77,    78,    79,    67,    68,    69,    70,    71,    80,
       0,    72,    73,    74,    75,    76,    77,    78,    79,     0,
       0,   142,    67,    68,    69,    70,    71,     0,    80,    72,
      73,    74,    75,    76,    77,    78,    79,     0,     0,     0,
       0,     0,     0,     0,   144,    70,    71,    80,     0,    72,
      73,    74,    75,    76,    77,    78,    79,     0,     0,   160,
       0,     0,    80,    69,    70,    71,     0,     0,    72,    73,
      74,    75,    76,    77,    78,    79,     0,   163,     0,     0,
      80,    67,    68,    69,    70,    71,     0,     0,    72,    73,
      74,    75,    76,    77,    78,    79,    35,     0,     0,     0,
      80,    36,     0,     0,     0,     0,     0,     0,     0,    35,
       0,     0,    37,    38,    36,     0,     0,     0,     0,    80,
       0,     0,     0,     0,     0,    37,    38,     0,     0,     0,
       0,     0,    39,    40,    41,    42,    43,     0,    19,    80,
      20,     0,     0,     0,   148,    39,    40,    41,    42,    43,
       0,    19,    21,    20,    22,     0,    23,    24,     0,     0,
       0,     0,     0,     0,     0,    21,     0,    22,    25,    23,
      24,    15,   162,     0,     0,     0,     0,     0,     0,     0,
       0,    25,     0,     0,    15
};

static const yytype_int16 yycheck[] =
{
      35,    36,    17,    20,    24,   102,   103,    24,    43,    14,
      15,    16,    17,     0,    49,    50,    51,    52,    53,    54,
      55,   118,    42,    52,    57,    60,    59,    57,    53,    59,
      79,    54,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    93,    55,    61,    82,    83,    98,
      53,     3,     4,     5,     6,     7,    61,    92,    10,    11,
      12,    13,    14,    15,    16,    17,     3,    60,    53,    62,
     167,     3,     4,     5,     6,     7,    57,    58,    10,    11,
      12,    13,    14,    15,    16,    17,    12,    13,    14,    15,
      16,    17,    23,    56,    31,    32,    33,    34,    35,    52,
     135,    20,    54,    61,     3,     4,     5,     6,     7,    61,
     145,    10,    11,    12,    13,    14,    15,    16,    17,    55,
      57,    52,    25,    26,    27,    49,    58,    57,    58,    61,
       3,     4,     5,     6,     7,    61,    28,    10,    11,    12,
      13,    14,    15,    16,    17,    62,    58,    24,    58,    58,
      58,    49,    49,    20,    49,    62,     6,    14,    61,    58,
      63,   143,    61,     3,     4,     5,     6,     7,    46,   138,
      10,    11,    12,    13,    14,    15,    16,    17,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    58,    -1,    -1,    61,     3,
       4,     5,     6,     7,    -1,    -1,    10,    11,    12,    13,
      14,    15,    16,    17,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    58,    -1,
      -1,    61,     3,     4,     5,     6,     7,    -1,    -1,    10,
      11,    12,    13,    14,    15,    16,    17,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    58,    -1,    -1,    61,     3,     4,
       5,     6,     7,    -1,    -1,    10,    11,    12,    13,    14,
      15,    16,    17,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    58,    -1,    -1,
      61,     3,     4,     5,     6,     7,    -1,    -1,    10,    11,
      12,    13,    14,    15,    16,    17,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    58,    -1,    -1,    61,     3,     4,     5,
       6,     7,    -1,    -1,    10,    11,    12,    13,    14,    15,
      16,    17,     4,     5,     6,     7,    -1,    -1,    10,    11,
      12,    13,    14,    15,    16,    17,    58,    -1,    -1,    61,
       3,     4,     5,     6,     7,    -1,    -1,    10,    11,    12,
      13,    14,    15,    16,    17,    -1,    -1,    -1,    54,     3,
       4,     5,     6,     7,    -1,    61,    10,    11,    12,    13,
      14,    15,    16,    17,     3,     4,     5,     6,     7,    61,
      -1,    10,    11,    12,    13,    14,    15,    16,    17,    -1,
      -1,    54,     3,     4,     5,     6,     7,    -1,    61,    10,
      11,    12,    13,    14,    15,    16,    17,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    58,     6,     7,    61,    -1,    10,
      11,    12,    13,    14,    15,    16,    17,    -1,    -1,    58,
      -1,    -1,    61,     5,     6,     7,    -1,    -1,    10,    11,
      12,    13,    14,    15,    16,    17,    -1,    58,    -1,    -1,
      61,     3,     4,     5,     6,     7,    -1,    -1,    10,    11,
      12,    13,    14,    15,    16,    17,    13,    -1,    -1,    -1,
      61,    18,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    13,
      -1,    -1,    29,    30,    18,    -1,    -1,    -1,    -1,    61,
      -1,    -1,    -1,    -1,    -1,    29,    30,    -1,    -1,    -1,
      -1,    -1,    49,    50,    51,    52,    53,    -1,    22,    61,
      24,    -1,    -1,    -1,    61,    49,    50,    51,    52,    53,
      -1,    22,    36,    24,    38,    -1,    40,    41,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    36,    -1,    38,    52,    40,
      41,    55,    56,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    52,    -1,    -1,    55
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    65,    66,     0,    24,    42,    67,    68,    69,    71,
      52,    68,    53,    54,    70,    55,    72,    73,    75,    22,
      24,    36,    38,    40,    41,    52,    72,    74,    79,    80,
      82,    88,    91,    23,    52,    13,    18,    29,    30,    49,
      50,    51,    52,    53,    76,    96,    89,    53,    53,     3,
      31,    32,    33,    34,    35,    57,    56,    24,    85,    52,
      57,    59,    96,    96,    96,    86,    87,     3,     4,     5,
       6,     7,    10,    11,    12,    13,    14,    15,    16,    17,
      61,    76,    93,    92,    96,    96,    96,    96,    96,    96,
      96,    20,    57,    59,    96,    25,    26,    27,    61,    63,
      97,    54,    81,    83,    96,    96,    96,    96,    96,    96,
      96,    96,    96,    96,    96,    96,    97,    49,    90,    96,
      96,    58,    58,    58,    58,    58,    58,    58,    55,    77,
      96,    97,    58,    97,    28,    57,    58,    77,    77,    62,
      77,    54,    54,    78,    58,    57,    58,    58,    61,    95,
      96,    85,    58,    58,    75,    96,    49,    49,    94,    58,
      58,    84,    56,    58,    62,    60,    62,    20,    49,    77
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    64,    66,    65,    67,    67,    68,    68,    70,    69,
      71,    73,    74,    72,    75,    75,    76,    78,    77,    79,
      79,    81,    80,    83,    84,    82,    85,    85,    86,    87,
      89,    90,    88,    91,    91,    91,    91,    91,    91,    91,
      91,    91,    91,    92,    91,    93,    91,    91,    91,    91,
      91,    91,    91,    91,    91,    91,    94,    94,    95,    96,
      96,    96,    96,    96,    96,    96,    96,    96,    96,    96,
      96,    96,    96,    96,    96,    96,    96,    96,    96,    96,
      96,    96,    97,    97,    97,    97,    97
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     0,     2,     2,     1,     1,     1,     0,     5,
       2,     0,     0,     5,     2,     0,     1,     0,     4,     1,
       1,     0,     5,     0,     0,     9,     1,     0,     0,     0,
       0,     0,     5,     1,     4,     1,     5,     6,     5,     6,
       7,     7,     8,     0,     6,     0,     6,     1,     1,     4,
       4,     4,     4,     4,     4,     4,     1,     3,     3,     1,
       1,     1,     1,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     2,     2,     3,     3,     3,     4,     3,     1,
       1,     3,     1,     1,     1,     2,     5
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF

/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)                                \
    do                                                                  \
      if (N)                                                            \
        {                                                               \
          (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;        \
          (Current).first_column = YYRHSLOC (Rhs, 1).first_column;      \
          (Current).last_line    = YYRHSLOC (Rhs, N).last_line;         \
          (Current).last_column  = YYRHSLOC (Rhs, N).last_column;       \
        }                                                               \
      else                                                              \
        {                                                               \
          (Current).first_line   = (Current).last_line   =              \
            YYRHSLOC (Rhs, 0).last_line;                                \
          (Current).first_column = (Current).last_column =              \
            YYRHSLOC (Rhs, 0).last_column;                              \
        }                                                               \
    while (0)
#endif

#define YYRHSLOC(Rhs, K) ((Rhs)[K])


/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)


/* YYLOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

# ifndef YYLOCATION_PRINT

#  if defined YY_LOCATION_PRINT

   /* Temporary convenience wrapper in case some people defined the
      undocumented and private YY_LOCATION_PRINT macros.  */
#   define YYLOCATION_PRINT(File, Loc)  YY_LOCATION_PRINT(File, *(Loc))

#  elif defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL

/* Print *YYLOCP on YYO.  Private, do not rely on its existence. */

YY_ATTRIBUTE_UNUSED
static int
yy_location_print_ (FILE *yyo, YYLTYPE const * const yylocp)
{
  int res = 0;
  int end_col = 0 != yylocp->last_column ? yylocp->last_column - 1 : 0;
  if (0 <= yylocp->first_line)
    {
      res += YYFPRINTF (yyo, "%d", yylocp->first_line);
      if (0 <= yylocp->first_column)
        res += YYFPRINTF (yyo, ".%d", yylocp->first_column);
    }
  if (0 <= yylocp->last_line)
    {
      if (yylocp->first_line < yylocp->last_line)
        {
          res += YYFPRINTF (yyo, "-%d", yylocp->last_line);
          if (0 <= end_col)
            res += YYFPRINTF (yyo, ".%d", end_col);
        }
      else if (0 <= end_col && yylocp->first_column < end_col)
        res += YYFPRINTF (yyo, "-%d", end_col);
    }
  return res;
}

#   define YYLOCATION_PRINT  yy_location_print_

    /* Temporary convenience wrapper in case some people defined the
       undocumented and private YY_LOCATION_PRINT macros.  */
#   define YY_LOCATION_PRINT(File, Loc)  YYLOCATION_PRINT(File, &(Loc))

#  else

#   define YYLOCATION_PRINT(File, Loc) ((void) 0)
    /* Temporary convenience wrapper in case some people defined the
       undocumented and private YY_LOCATION_PRINT macros.  */
#   define YY_LOCATION_PRINT  YYLOCATION_PRINT

#  endif
# endif /* !defined YYLOCATION_PRINT */


# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value, Location); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  YY_USE (yylocationp);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  YYLOCATION_PRINT (yyo, yylocationp);
  YYFPRINTF (yyo, ": ");
  yy_symbol_value_print (yyo, yykind, yyvaluep, yylocationp);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp, YYLTYPE *yylsp,
                 int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)],
                       &(yylsp[(yyi + 1) - (yynrhs)]));
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, yylsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
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


/* Context of a parse error.  */
typedef struct
{
  yy_state_t *yyssp;
  yysymbol_kind_t yytoken;
  YYLTYPE *yylloc;
} yypcontext_t;

/* Put in YYARG at most YYARGN of the expected tokens given the
   current YYCTX, and return the number of tokens stored in YYARG.  If
   YYARG is null, return the number of expected tokens (guaranteed to
   be less than YYNTOKENS).  Return YYENOMEM on memory exhaustion.
   Return 0 if there are more than YYARGN expected tokens, yet fill
   YYARG up to YYARGN. */
static int
yypcontext_expected_tokens (const yypcontext_t *yyctx,
                            yysymbol_kind_t yyarg[], int yyargn)
{
  /* Actual size of YYARG. */
  int yycount = 0;
  int yyn = yypact[+*yyctx->yyssp];
  if (!yypact_value_is_default (yyn))
    {
      /* Start YYX at -YYN if negative to avoid negative indexes in
         YYCHECK.  In other words, skip the first -YYN actions for
         this state because they are default actions.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;
      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yyx;
      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
        if (yycheck[yyx + yyn] == yyx && yyx != YYSYMBOL_YYerror
            && !yytable_value_is_error (yytable[yyx + yyn]))
          {
            if (!yyarg)
              ++yycount;
            else if (yycount == yyargn)
              return 0;
            else
              yyarg[yycount++] = YY_CAST (yysymbol_kind_t, yyx);
          }
    }
  if (yyarg && yycount == 0 && 0 < yyargn)
    yyarg[0] = YYSYMBOL_YYEMPTY;
  return yycount;
}




#ifndef yystrlen
# if defined __GLIBC__ && defined _STRING_H
#  define yystrlen(S) (YY_CAST (YYPTRDIFF_T, strlen (S)))
# else
/* Return the length of YYSTR.  */
static YYPTRDIFF_T
yystrlen (const char *yystr)
{
  YYPTRDIFF_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
# endif
#endif

#ifndef yystpcpy
# if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#  define yystpcpy stpcpy
# else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
# endif
#endif

#ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYPTRDIFF_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYPTRDIFF_T yyn = 0;
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
            else
              goto append;

          append:
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

  if (yyres)
    return yystpcpy (yyres, yystr) - yyres;
  else
    return yystrlen (yystr);
}
#endif


static int
yy_syntax_error_arguments (const yypcontext_t *yyctx,
                           yysymbol_kind_t yyarg[], int yyargn)
{
  /* Actual size of YYARG. */
  int yycount = 0;
  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yyctx->yytoken != YYSYMBOL_YYEMPTY)
    {
      int yyn;
      if (yyarg)
        yyarg[yycount] = yyctx->yytoken;
      ++yycount;
      yyn = yypcontext_expected_tokens (yyctx,
                                        yyarg ? yyarg + 1 : yyarg, yyargn - 1);
      if (yyn == YYENOMEM)
        return YYENOMEM;
      else
        yycount += yyn;
    }
  return yycount;
}

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return -1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return YYENOMEM if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
                const yypcontext_t *yyctx)
{
  enum { YYARGS_MAX = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat: reported tokens (one for the "unexpected",
     one per "expected"). */
  yysymbol_kind_t yyarg[YYARGS_MAX];
  /* Cumulated lengths of YYARG.  */
  YYPTRDIFF_T yysize = 0;

  /* Actual size of YYARG. */
  int yycount = yy_syntax_error_arguments (yyctx, yyarg, YYARGS_MAX);
  if (yycount == YYENOMEM)
    return YYENOMEM;

  switch (yycount)
    {
#define YYCASE_(N, S)                       \
      case N:                               \
        yyformat = S;                       \
        break
    default: /* Avoid compiler warnings. */
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
#undef YYCASE_
    }

  /* Compute error message size.  Don't count the "%s"s, but reserve
     room for the terminator.  */
  yysize = yystrlen (yyformat) - 2 * yycount + 1;
  {
    int yyi;
    for (yyi = 0; yyi < yycount; ++yyi)
      {
        YYPTRDIFF_T yysize1
          = yysize + yytnamerr (YY_NULLPTR, yytname[yyarg[yyi]]);
        if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
          yysize = yysize1;
        else
          return YYENOMEM;
      }
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return -1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yytname[yyarg[yyi++]]);
          yyformat += 2;
        }
      else
        {
          ++yyp;
          ++yyformat;
        }
  }
  return 0;
}


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep, YYLTYPE *yylocationp)
{
  YY_USE (yyvaluep);
  YY_USE (yylocationp);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Location data for the lookahead symbol.  */
YYLTYPE yylloc
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
  = { 1, 1, 1, 1 }
# endif
;
/* Number of syntax errors so far.  */
int yynerrs;




/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

    /* The location stack: array, bottom, top.  */
    YYLTYPE yylsa[YYINITDEPTH];
    YYLTYPE *yyls = yylsa;
    YYLTYPE *yylsp = yyls;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;
  YYLTYPE yyloc;

  /* The locations where the error started and ended.  */
  YYLTYPE yyerror_range[3];

  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYPTRDIFF_T yymsg_alloc = sizeof yymsgbuf;

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N), yylsp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

  yylsp[0] = yylloc;
  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;
        YYLTYPE *yyls1 = yyls;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yyls1, yysize * YYSIZEOF (*yylsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
        yyls = yyls1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
        YYSTACK_RELOCATE (yyls_alloc, yyls);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;
      yylsp = yyls + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */


  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      yyerror_range[1] = yylloc;
      goto yyerrlab1;
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
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END
  *++yylsp = yylloc;

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
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
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];

  /* Default location. */
  YYLLOC_DEFAULT (yyloc, (yylsp - yylen), yylen);
  yyerror_range[1] = yyloc;
  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 2: /* $@1: %empty  */
#line 141 "compiler.y"
      {
        /* Generate the basic Jasmin template here */
        CODEGEN(".source Main.j");
        CODEGEN(".class public Main");
        CODEGEN(".super java/lang/Object");
        CODEGEN("");
        
        // Add default constructor here
        CODEGEN(".method public <init>()V");
        CODEGEN("aload_0");
        CODEGEN("invokespecial java/lang/Object/<init>()V");
        CODEGEN("return");
        CODEGEN(".end method");
        CODEGEN("");
        
        // Then continue with main method
        CODEGEN(".method public static main([Ljava/lang/String;)V");
        CODEGEN(".limit stack 100");
        CODEGEN(".limit locals 100");
        create_symbol ( scope++ ); 
      }
#line 1987 "y.tab.c"
    break;

  case 3: /* Program: $@1 GlobalStatementList  */
#line 163 "compiler.y"
    { 
        /* This is the end of the main method */
        CODEGEN("return");
        CODEGEN(".end method");
        dump_symbol(0); 
    }
#line 1998 "y.tab.c"
    break;

  case 8: /* $@2: %empty  */
#line 182 "compiler.y"
                         {
        insert_symbol((yyvsp[-2].s_val), -1, 0);
    }
#line 2006 "y.tab.c"
    break;

  case 10: /* FuncHeader: FUNC ID  */
#line 188 "compiler.y"
              {
        (yyval.s_val) = (yyvsp[0].s_val);
        printf ( "func: %s\n", (yyval.s_val) );
    }
#line 2015 "y.tab.c"
    break;

  case 11: /* $@3: %empty  */
#line 196 "compiler.y"
      {
          printf(">>> ENTERING BLOCK (scope level %d)\n", scope);
          create_symbol(scope);
          scope++;
      }
#line 2025 "y.tab.c"
    break;

  case 12: /* $@4: %empty  */
#line 202 "compiler.y"
      {
          int closed = --scope;
          printf("<<< EXITING BLOCK (scope level %d)\n", closed);
          dump_symbol(closed);
          pop_scope(closed);
          printf("--- AFTER POP (remaining symbols):\n");
          dump_all_symbols();
      }
#line 2038 "y.tab.c"
    break;

  case 16: /* Condition: Expression  */
#line 220 "compiler.y"
      {
          /* semantic-check */
          if (strcmp((yyvsp[0].expr).type, "bool") != 0) {
              printf("error:%d: non-bool (type %s) used as for condition\n",
                     yylineno + 1, (yyvsp[0].expr).type);
          }
          /* pass the slot number up so IfStmt knows where to iload */
          (yyval.local_idx) = (yyvsp[0].expr).local_idx;
      }
#line 2052 "y.tab.c"
    break;

  case 17: /* $@5: %empty  */
#line 233 "compiler.y"
      {
          printf(">>> ENTERING BLOCK (scope level %d)\n", scope);
          create_symbol(scope);
          scope++;
      }
#line 2062 "y.tab.c"
    break;

  case 18: /* StmtBlock: '{' $@5 StatementList '}'  */
#line 240 "compiler.y"
      {
          int closed = --scope;
          printf("<<< EXITING BLOCK (scope level %d)\n", closed);
          dump_symbol(closed);
          pop_scope(closed);
      }
#line 2073 "y.tab.c"
    break;

  case 21: /* $@6: %empty  */
#line 255 "compiler.y"
    {
        printf("[parser] matched IfOnlyStmt (no else)\n");
        CODEGEN("iload %d", (yyvsp[-1].local_idx));
        CODEGEN("ifeq Exit_%d", (yyvsp[0].i_val));
    }
#line 2083 "y.tab.c"
    break;

  case 22: /* IfOnlyStmt: IF Condition IfExitLabel $@6 StmtBlock  */
#line 261 "compiler.y"
    {
        CODEGEN("Exit_%d:", (yyvsp[-2].i_val));
    }
#line 2091 "y.tab.c"
    break;

  case 23: /* $@7: %empty  */
#line 268 "compiler.y"
    {
        printf("[parser] matched IfElseStmt (with else)\n");
        int else_lbl = ((yyvsp[0].i_val) >> 16) & 0xFFFF;
        CODEGEN("iload %d", (yyvsp[-1].local_idx));
        CODEGEN("ifeq Else_%d", else_lbl);
    }
#line 2102 "y.tab.c"
    break;

  case 24: /* $@8: %empty  */
#line 275 "compiler.y"
    {
        int else_lbl = ((yyvsp[-3].i_val) >> 16) & 0xFFFF;
        int exit_lbl = ((yyvsp[-3].i_val)      ) & 0xFFFF;
        CODEGEN("goto Exit_%d", exit_lbl);
        CODEGEN("Else_%d:", else_lbl);
    }
#line 2113 "y.tab.c"
    break;

  case 25: /* IfElseStmt: IF Condition IfElseLabels $@7 StmtBlock OptNewline $@8 ELSE StmtBlock  */
#line 282 "compiler.y"
    {
        int exit_lbl = ((yyvsp[-6].i_val)) & 0xFFFF;
        CODEGEN("Exit_%d:", exit_lbl);
    }
#line 2122 "y.tab.c"
    break;

  case 26: /* OptNewline: NEWLINE  */
#line 289 "compiler.y"
              { printf("[parser] consumed optional NEWLINE\n"); }
#line 2128 "y.tab.c"
    break;

  case 28: /* IfExitLabel: %empty  */
#line 294 "compiler.y"
                  { (yyval.i_val) = label_counter++; }
#line 2134 "y.tab.c"
    break;

  case 29: /* IfElseLabels: %empty  */
#line 298 "compiler.y"
                  {
        int else_lbl = label_counter++;
        int exit_lbl = label_counter++;
        (yyval.i_val) = (else_lbl << 16) | exit_lbl;  // pack into one int
    }
#line 2144 "y.tab.c"
    break;

  case 30: /* $@9: %empty  */
#line 306 "compiler.y"
            {
        int loop_id = for_counter++;
        CODEGEN("For_%d:", loop_id);
    }
#line 2153 "y.tab.c"
    break;

  case 31: /* $@10: %empty  */
#line 310 "compiler.y"
              {
        int exit_id = label_count++;
        CODEGEN("iload %d", (yyvsp[0].local_idx));
        CODEGEN("ifeq Exit_%d", exit_id);
        // Save exit_id in a local variable for use later
        yylval.i_val = exit_id;
        inside_while_stmt = true;
    }
#line 2166 "y.tab.c"
    break;

  case 32: /* WhileStmt: WHILE $@9 Condition $@10 StmtBlock  */
#line 318 "compiler.y"
              {
        int loop_id = for_counter - 1;
        int exit_id = yylval.i_val;
        CODEGEN("goto For_%d", loop_id);
        CODEGEN("Exit_%d:", exit_id);
        inside_while_stmt = false;
    }
#line 2178 "y.tab.c"
    break;

  case 36: /* Statement: LET ID '=' Expression ';'  */
#line 331 "compiler.y"
        {
            int loc = (yyvsp[-1].expr).local_idx;
            insert_symbol((yyvsp[-3].s_val), loc, scope - 1);
            add_symbol ((yyvsp[-3].s_val), loc, (yyvsp[-1].expr).type, yylineno, (yyvsp[-1].expr), /*mut=*/0);
        }
#line 2188 "y.tab.c"
    break;

  case 37: /* Statement: LET MUT ID '=' Expression ';'  */
#line 337 "compiler.y"
        {
            int loc = (yyvsp[-1].expr).local_idx;
            insert_symbol((yyvsp[-3].s_val), loc, scope - 1);
            add_symbol ((yyvsp[-3].s_val), loc, (yyvsp[-1].expr).type, yylineno, (yyvsp[-1].expr), /*mut=*/1);
        }
#line 2198 "y.tab.c"
    break;

  case 38: /* Statement: LET ID ':' Type ';'  */
#line 343 "compiler.y"
        {
            insert_symbol((yyvsp[-3].s_val), addr_count, scope-1);
            ExprVal zero = { .type = strdup((yyvsp[-1].s_val)), .i_val = 0, .f_val = 0.0, .s_val = NULL };
            add_symbol((yyvsp[-3].s_val), addr_count, (yyvsp[-1].s_val), yylineno, zero, 0);
            addr_count++;
        }
#line 2209 "y.tab.c"
    break;

  case 39: /* Statement: LET MUT ID ':' Type ';'  */
#line 350 "compiler.y"
        {
            insert_symbol((yyvsp[-3].s_val), addr_count, scope-1);
            ExprVal zero = { .type = strdup((yyvsp[-1].s_val)), .i_val = 0, .f_val = 0.0, .s_val = NULL };
            add_symbol((yyvsp[-3].s_val), addr_count, (yyvsp[-1].s_val), yylineno, zero, 1);
            addr_count++;
        }
#line 2220 "y.tab.c"
    break;

  case 40: /* Statement: LET ID ':' Type '=' ArrayLiteral ';'  */
#line 357 "compiler.y"
        {
            insert_symbol((yyvsp[-5].s_val), addr_count, scope-1);
            add_symbol((yyvsp[-5].s_val), addr_count, "array", yylineno, (yyvsp[-1].expr), 0);
            addr_count++;
        }
#line 2230 "y.tab.c"
    break;

  case 41: /* Statement: LET ID ':' Type '=' Expression ';'  */
#line 363 "compiler.y"
        {
            int loc;

            if (strcmp((yyvsp[-3].s_val), "i32") == 0) {
                loc = alloc_local_i32();
                CODEGEN("iload %d", (yyvsp[-1].expr).local_idx);
                CODEGEN("istore %d", loc);
            } else if (strcmp((yyvsp[-3].s_val), "f32") == 0) {
                loc = alloc_local_f32();
                CODEGEN("fload %d", (yyvsp[-1].expr).local_idx);
                CODEGEN("fstore %d", loc);
            } else if (strcmp((yyvsp[-3].s_val), "str") == 0) {
                loc = alloc_local_ref();
                CODEGEN("aload %d", (yyvsp[-1].expr).local_idx);
                CODEGEN("astore %d", loc);
            } else if (strcmp((yyvsp[-3].s_val), "bool") == 0) {
                loc = alloc_local_i32();
                CODEGEN("iload %d", (yyvsp[-1].expr).local_idx);
                CODEGEN("istore %d", loc);
            } else {
                printf("error:%d: unsupported let-binding type: %s\n", yylineno, (yyvsp[-3].s_val));
                loc = -1;
            }

            ExprVal new_val = {
                .type = strdup((yyvsp[-3].s_val)),
                .local_idx = loc
            };
            if (strcmp((yyvsp[-3].s_val), "i32") == 0) {
                new_val.i_val = (yyvsp[-1].expr).i_val;
            } else if (strcmp((yyvsp[-3].s_val), "f32") == 0) {
                new_val.f_val = (yyvsp[-1].expr).f_val;
            } else if (strcmp((yyvsp[-3].s_val), "str") == 0) {
                new_val.s_val = (yyvsp[-1].expr).s_val;
            } else if (strcmp((yyvsp[-3].s_val), "bool") == 0) {
                new_val.i_val = (yyvsp[-1].expr).i_val;
            }

            insert_symbol((yyvsp[-5].s_val), loc, scope - 1);
            add_symbol((yyvsp[-5].s_val), loc, (yyvsp[-3].s_val), yylineno, new_val, /*mut=*/0);
        }
#line 2276 "y.tab.c"
    break;

  case 42: /* Statement: LET MUT ID ':' Type '=' Expression ';'  */
#line 405 "compiler.y"
        {
            int loc;

            if (strcmp((yyvsp[-3].s_val), "i32") == 0) {
                loc = alloc_local_i32();
                CODEGEN("iload %d", (yyvsp[-1].expr).local_idx);
                CODEGEN("istore %d", loc);
            } else if (strcmp((yyvsp[-3].s_val), "f32") == 0) {
                loc = alloc_local_f32();
                CODEGEN("fload %d", (yyvsp[-1].expr).local_idx);
                CODEGEN("fstore %d", loc);
            } else if (strcmp((yyvsp[-3].s_val), "str") == 0) {
                loc = alloc_local_ref();
                CODEGEN("aload %d", (yyvsp[-1].expr).local_idx);
                CODEGEN("astore %d", loc);
            } else if (strcmp((yyvsp[-3].s_val), "bool") == 0) {
                loc = alloc_local_i32();
                CODEGEN("iload %d", (yyvsp[-1].expr).local_idx);
                CODEGEN("istore %d", loc);
            } else {
                printf("error:%d: unsupported let-binding type: %s\n", yylineno, (yyvsp[-3].s_val));
                loc = -1;
            }

            ExprVal new_val = {
                .type = strdup((yyvsp[-3].s_val)),
                .local_idx = loc
            };

            if (strcmp((yyvsp[-3].s_val), "i32") == 0) {
                new_val.i_val = (yyvsp[-1].expr).i_val;
            } else if (strcmp((yyvsp[-3].s_val), "f32") == 0) {
                new_val.f_val = (yyvsp[-1].expr).f_val;
            } else if (strcmp((yyvsp[-3].s_val), "str") == 0) {
                new_val.s_val = (yyvsp[-1].expr).s_val;
            } else if (strcmp((yyvsp[-3].s_val), "bool") == 0) {
                new_val.i_val = (yyvsp[-1].expr).i_val;
            }

            insert_symbol((yyvsp[-5].s_val), loc, scope - 1);
            add_symbol((yyvsp[-5].s_val), loc, (yyvsp[-3].s_val), yylineno, new_val, /*mut=*/1);
        }
#line 2323 "y.tab.c"
    break;

  case 43: /* $@11: %empty  */
#line 447 "compiler.y"
                  {
        CODEGEN("getstatic java/lang/System/out Ljava/io/PrintStream;");
    }
#line 2331 "y.tab.c"
    break;

  case 44: /* Statement: PRINTLN '(' $@11 Expression ')' ';'  */
#line 450 "compiler.y"
                       {
        ExprVal expr = (yyvsp[-2].expr);
        if (strcmp(expr.type, "i32") == 0) {
            CODEGEN("iload %d", expr.local_idx);
            CODEGEN("invokevirtual java/io/PrintStream/println(I)V");
        } else if (strcmp(expr.type, "f32") == 0) {
            CODEGEN("fload %d", expr.local_idx);
            CODEGEN("invokevirtual java/io/PrintStream/println(F)V");
        } else if (strcmp(expr.type, "str") == 0) {
            CODEGEN("aload %d", expr.local_idx);
            CODEGEN("invokevirtual java/io/PrintStream/println(Ljava/lang/String;)V");
        } else if (strcmp(expr.type, "bool") == 0) {
            int trueLabel = label_count++;
            int endLabel = label_count++;
            CODEGEN("iload %d", expr.local_idx);
            CODEGEN("ifeq Lfalse%d", trueLabel);
            // if value ≠ 0 → true
            CODEGEN("ldc \"true\"");
            CODEGEN("goto Lend%d", endLabel);
            CODEGEN("Lfalse%d:", trueLabel);
            CODEGEN("ldc \"false\"");
            CODEGEN("Lend%d:", endLabel);
            CODEGEN("invokevirtual java/io/PrintStream/println(Ljava/lang/String;)V");
        } else {
            printf("error:%d: unsupported type for println: %s\n", yylineno, expr.type);
            HAS_ERROR = true;
        }
    }
#line 2364 "y.tab.c"
    break;

  case 45: /* $@12: %empty  */
#line 478 "compiler.y"
                {
    CODEGEN("getstatic java/lang/System/out Ljava/io/PrintStream;");
    }
#line 2372 "y.tab.c"
    break;

  case 46: /* Statement: PRINT '(' $@12 Expression ')' ';'  */
#line 481 "compiler.y"
                       {
        ExprVal expr = (yyvsp[-2].expr);
        if (strcmp(expr.type, "i32") == 0) {
            CODEGEN("iload %d", expr.local_idx);
            CODEGEN("invokevirtual java/io/PrintStream/println(I)V");
        } else if (strcmp(expr.type, "f32") == 0) {
            CODEGEN("fload %d", expr.local_idx);
            CODEGEN("invokevirtual java/io/PrintStream/println(F)V");
        } else if (strcmp(expr.type, "str") == 0) {
            CODEGEN("aload %d", expr.local_idx);
            CODEGEN("invokevirtual java/io/PrintStream/println(Ljava/lang/String;)V");
        } else if (strcmp(expr.type, "bool") == 0) {
            int trueLabel = label_count++;
            int endLabel = label_count++;
            CODEGEN("iload %d", expr.local_idx);
            CODEGEN("ifeq Lfalse%d", trueLabel);
            CODEGEN("ldc \"true\"");
            CODEGEN("goto Lend%d", endLabel);
            CODEGEN("Lfalse%d:", trueLabel);
            CODEGEN("ldc \"false\"");
            CODEGEN("Lend%d:", endLabel);
            CODEGEN("invokevirtual java/io/PrintStream/println(Ljava/lang/String;)V");
        } else {
            fprintf(stderr, "Unsupported type for print: %s\n", expr.type);
            exit(1);
        }
    }
#line 2404 "y.tab.c"
    break;

  case 49: /* Statement: ID '=' Expression ';'  */
#line 512 "compiler.y"
    {
        int sym_i = lookup_symbol((yyvsp[-3].s_val));
        if (sym_i < 0) {
            printf("error:%d: undefined: %s\n", yylineno, (yyvsp[-3].s_val));
        } else {
            if (! symtab[sym_i].mut) {
                printf("error:%d: cannot assign to immutable variable `%s`\n", yylineno, (yyvsp[-3].s_val));
            } else {
                int dest = symtab[sym_i].addr;
                const char* type = symtab[sym_i].type;

                if (strcmp(type, (yyvsp[-1].expr).type) != 0) {
                    printf("error:%d: type mismatch in assignment to `%s`\n", yylineno, (yyvsp[-3].s_val));
                } else if (strcmp(type, "i32") == 0) {
                    CODEGEN("iload %d", (yyvsp[-1].expr).local_idx);
                    CODEGEN("istore %d", dest);
                } else if (strcmp(type, "f32") == 0) {
                    CODEGEN("fload %d", (yyvsp[-1].expr).local_idx);
                    CODEGEN("fstore %d", dest);
                } else if (strcmp(type, "str") == 0) {
                    CODEGEN("aload %d", (yyvsp[-1].expr).local_idx);
                    CODEGEN("astore %d", dest);
                } else if (strcmp(type, "bool") == 0) {
                    CODEGEN("iload %d", (yyvsp[-1].expr).local_idx);
                    CODEGEN("istore %d", dest);
                } else {
                    printf("error:%d: unsupported type for assignment to `%s`\n", yylineno, (yyvsp[-3].s_val));
                }
            }
        }
    }
#line 2440 "y.tab.c"
    break;

  case 50: /* Statement: ID LSHIFT Expression ';'  */
#line 545 "compiler.y"
        {
            int sym_i = lookup_symbol((yyvsp[-3].s_val));
            ExprVal rhs = (yyvsp[-1].expr);
            if (sym_i < 0) {
                printf("error:%d: undefined: %s\n", (yylsp[-3]).first_line, (yyvsp[-3].s_val));
            }
            else {
                ExprVal lhs = get_expr_val((yyvsp[-3].s_val));
                if (strcmp(lhs.type, "undefined") != 0 &&
                    strcmp(rhs.type, "undefined") != 0 &&
                    strcmp(lhs.type, rhs.type) != 0)
                {
                    printf("error:%d: invalid operation: LSHIFT (mismatched types %s and %s)\n",
                           yylineno, lhs.type, rhs.type);
                }
            }
            printf("LSHIFT\n");
        }
#line 2463 "y.tab.c"
    break;

  case 51: /* Statement: ID ADD_ASSIGN Expression ';'  */
#line 564 "compiler.y"
                                   {
        int sym_i = lookup_symbol((yyvsp[-3].s_val));
        if (sym_i < 0) {
            printf("error:%d: undefined: %s\n", yylineno, (yyvsp[-3].s_val));
        } else if (!symtab[sym_i].mut) {
            printf("error:%d: cannot assign to immutable variable `%s`\n", yylineno, (yyvsp[-3].s_val));
        } else if (strcmp(symtab[sym_i].type, (yyvsp[-1].expr).type) != 0) {
            printf("error:%d: type mismatch in += assignment for `%s`\n", yylineno, (yyvsp[-3].s_val));
        } else {
            int loc = symtab[sym_i].addr;
            if (strcmp((yyvsp[-1].expr).type, "i32") == 0) {
                CODEGEN("iload %d", loc);
                CODEGEN("iload %d", (yyvsp[-1].expr).local_idx);
                CODEGEN("iadd");
                CODEGEN("istore %d", loc);
            } else if (strcmp((yyvsp[-1].expr).type, "f32") == 0) {
                CODEGEN("fload %d", loc);
                CODEGEN("fload %d", (yyvsp[-1].expr).local_idx);
                CODEGEN("fadd");
                CODEGEN("fstore %d", loc);
            }
        }
    }
#line 2491 "y.tab.c"
    break;

  case 52: /* Statement: ID SUB_ASSIGN Expression ';'  */
#line 588 "compiler.y"
                                   {
        int sym_i = lookup_symbol((yyvsp[-3].s_val));
        if (sym_i < 0) {
            printf("error:%d: undefined: %s\n", yylineno, (yyvsp[-3].s_val));
        } else if (!symtab[sym_i].mut) {
            printf("error:%d: cannot assign to immutable variable `%s`\n", yylineno, (yyvsp[-3].s_val));
        } else if (strcmp(symtab[sym_i].type, (yyvsp[-1].expr).type) != 0) {
            printf("error:%d: type mismatch in -= assignment for `%s`\n", yylineno, (yyvsp[-3].s_val));
        } else {
            int loc = symtab[sym_i].addr;
            if (strcmp((yyvsp[-1].expr).type, "i32") == 0) {
                CODEGEN("iload %d", loc);
                CODEGEN("iload %d", (yyvsp[-1].expr).local_idx);
                CODEGEN("isub");
                CODEGEN("istore %d", loc);
            } else if (strcmp((yyvsp[-1].expr).type, "f32") == 0) {
                CODEGEN("fload %d", loc);
                CODEGEN("fload %d", (yyvsp[-1].expr).local_idx);
                CODEGEN("fsub");
                CODEGEN("fstore %d", loc);
            }
        }
    }
#line 2519 "y.tab.c"
    break;

  case 53: /* Statement: ID MUL_ASSIGN Expression ';'  */
#line 612 "compiler.y"
                                   {
        int sym_i = lookup_symbol((yyvsp[-3].s_val));
        if (sym_i < 0) {
            printf("error:%d: undefined: %s\n", yylineno, (yyvsp[-3].s_val));
        } else if (!symtab[sym_i].mut) {
            printf("error:%d: cannot assign to immutable variable `%s`\n", yylineno, (yyvsp[-3].s_val));
        } else if (strcmp(symtab[sym_i].type, (yyvsp[-1].expr).type) != 0) {
            printf("error:%d: type mismatch in *= assignment for `%s`\n", yylineno, (yyvsp[-3].s_val));
        } else {
            int loc = symtab[sym_i].addr;
            if (strcmp((yyvsp[-1].expr).type, "i32") == 0) {
                CODEGEN("iload %d", loc);
                CODEGEN("iload %d", (yyvsp[-1].expr).local_idx);
                CODEGEN("imul");
                CODEGEN("istore %d", loc);
            } else if (strcmp((yyvsp[-1].expr).type, "f32") == 0) {
                CODEGEN("fload %d", loc);
                CODEGEN("fload %d", (yyvsp[-1].expr).local_idx);
                CODEGEN("fmul");
                CODEGEN("fstore %d", loc);
            }
        }
    }
#line 2547 "y.tab.c"
    break;

  case 54: /* Statement: ID DIV_ASSIGN Expression ';'  */
#line 636 "compiler.y"
                                   {
        int sym_i = lookup_symbol((yyvsp[-3].s_val));
        if (sym_i < 0) {
            printf("error:%d: undefined: %s\n", yylineno, (yyvsp[-3].s_val));
        } else if (!symtab[sym_i].mut) {
            printf("error:%d: cannot assign to immutable variable `%s`\n", yylineno, (yyvsp[-3].s_val));
        } else if (strcmp(symtab[sym_i].type, (yyvsp[-1].expr).type) != 0) {
            printf("error:%d: type mismatch in /= assignment for `%s`\n", yylineno, (yyvsp[-3].s_val));
        } else {
            int loc = symtab[sym_i].addr;
            if (strcmp((yyvsp[-1].expr).type, "i32") == 0) {
                if ((yyvsp[-1].expr).i_val == 0) {
                    printf("error:%d: division by zero\n", yylineno);
                } else {
                    CODEGEN("iload %d", loc);
                    CODEGEN("iload %d", (yyvsp[-1].expr).local_idx);
                    CODEGEN("idiv");
                    CODEGEN("istore %d", loc);
                }
            } else if (strcmp((yyvsp[-1].expr).type, "f32") == 0) {
                if ((yyvsp[-1].expr).f_val == 0.0f) {
                    printf("error:%d: division by zero\n", yylineno);
                } else {
                    CODEGEN("fload %d", loc);
                    CODEGEN("fload %d", (yyvsp[-1].expr).local_idx);
                    CODEGEN("fdiv");
                    CODEGEN("fstore %d", loc);
                }
            }
        }
    }
#line 2583 "y.tab.c"
    break;

  case 55: /* Statement: ID REM_ASSIGN Expression ';'  */
#line 668 "compiler.y"
                                   {
        int sym_i = lookup_symbol((yyvsp[-3].s_val));
        if (sym_i < 0) {
            printf("error:%d: undefined: %s\n", yylineno, (yyvsp[-3].s_val));
        } else if (!symtab[sym_i].mut) {
            printf("error:%d: cannot assign to immutable variable `%s`\n", yylineno, (yyvsp[-3].s_val));
        } else if (strcmp(symtab[sym_i].type, (yyvsp[-1].expr).type) != 0) {
            printf("error:%d: type mismatch in %%= assignment for `%s`\n", yylineno, (yyvsp[-3].s_val));
        } else {
            int loc = symtab[sym_i].addr;
            if (strcmp((yyvsp[-1].expr).type, "i32") == 0) {
                if ((yyvsp[-1].expr).i_val == 0) {
                    printf("error:%d: division by zero\n", yylineno);
                } else {
                    CODEGEN("iload %d", loc);
                    CODEGEN("iload %d", (yyvsp[-1].expr).local_idx);
                    CODEGEN("irem");
                    CODEGEN("istore %d", loc);
                }
            } else {
                printf("error:%d: unsupported type for %%=\n", yylineno);
            }
        }
    }
#line 2612 "y.tab.c"
    break;

  case 56: /* ArrayElems: INT_LIT  */
#line 695 "compiler.y"
                             { printf("INT_LIT %d\n", (yyvsp[0].i_val)); }
#line 2618 "y.tab.c"
    break;

  case 57: /* ArrayElems: ArrayElems ',' INT_LIT  */
#line 696 "compiler.y"
                             { printf("INT_LIT %d\n", (yyvsp[0].i_val)); }
#line 2624 "y.tab.c"
    break;

  case 58: /* ArrayLiteral: '[' ArrayElems ']'  */
#line 701 "compiler.y"
        {
            (yyval.expr) = (ExprVal){ .type = strdup("array") };
        }
#line 2632 "y.tab.c"
    break;

  case 59: /* Expression: ID  */
#line 708 "compiler.y"
    {
        int idx = lookup_symbol((yyvsp[0].s_val));
        if (idx < 0) {
            printf("error:%d: undefined variable: %s\n", yylineno, (yyvsp[0].s_val));
            (yyval.expr) = (ExprVal){ .type = strdup("undefined"), .local_idx = -1 };
        } else {
            int slot = symtab[idx].addr;  /* JVM local-var index */

            if (strcmp(symtab[idx].type, "i32") == 0) {
                (yyval.expr) = (ExprVal){
                    .type      = strdup("i32"),
                    .local_idx = slot,
                    .i_val     = symtab[idx].i_val
                };
            } else if (strcmp(symtab[idx].type, "f32") == 0) {
                (yyval.expr) = (ExprVal){
                    .type      = strdup("f32"),
                    .local_idx = slot,
                    .f_val     = symtab[idx].f_val
                };
            } else if (strcmp(symtab[idx].type, "str") == 0) {
                (yyval.expr) = (ExprVal){
                    .type      = strdup("str"),
                    .local_idx = slot,
                    .s_val     = symtab[idx].s_val
                };
            } else if (strcmp(symtab[idx].type, "bool") == 0) {
                (yyval.expr) = (ExprVal){
                    .type      = strdup("bool"),
                    .local_idx = slot,
                    .i_val     = symtab[idx].i_val
                };
            } else {
                printf("error:%d: unknown variable type for %s\n", yylineno, (yyvsp[0].s_val));
                (yyval.expr) = (ExprVal){ .type = strdup("undefined"), .local_idx = -1 };
            }
        }
    }
#line 2675 "y.tab.c"
    break;

  case 60: /* Expression: INT_LIT  */
#line 746 "compiler.y"
              {
        int idx = alloc_local_i32();
        CODEGEN("ldc %d", (yyvsp[0].i_val));
        CODEGEN("istore %d", idx);
        (yyval.expr).type = strdup("i32");
        (yyval.expr).i_val = (yyvsp[0].i_val);
        (yyval.expr).local_idx = idx;
    }
#line 2688 "y.tab.c"
    break;

  case 61: /* Expression: FLOAT_LIT  */
#line 754 "compiler.y"
                {
        int idx = alloc_local_f32();
        CODEGEN("ldc %f", (yyvsp[0].f_val));
        CODEGEN("fstore %d", idx);
        (yyval.expr).type = strdup("f32");
        (yyval.expr).f_val = (yyvsp[0].f_val);
        (yyval.expr).local_idx = idx;
    }
#line 2701 "y.tab.c"
    break;

  case 62: /* Expression: STRING_LIT  */
#line 762 "compiler.y"
                 {
        int idx = alloc_local_ref();
        CODEGEN("ldc %s", (yyvsp[0].s_val));
        CODEGEN("astore %d", idx);
        (yyval.expr).type = strdup("str");
        (yyval.expr).s_val = strdup((yyvsp[0].s_val));
        (yyval.expr).local_idx = idx;
    }
#line 2714 "y.tab.c"
    break;

  case 63: /* Expression: Expression '+' Expression  */
#line 770 "compiler.y"
                                {
        if (strcmp((yyvsp[-2].expr).type, "i32") == 0 && strcmp((yyvsp[0].expr).type, "i32") == 0) {
            int idx = alloc_local_i32();
            CODEGEN("iload %d", (yyvsp[-2].expr).local_idx);
            CODEGEN("iload %d", (yyvsp[0].expr).local_idx);
            CODEGEN("iadd");
            CODEGEN("istore %d", idx);
            (yyval.expr) = (ExprVal){
                .type = strdup("i32"),
                .local_idx = idx,
                .i_val = (yyvsp[-2].expr).i_val + (yyvsp[0].expr).i_val
            };
        } else if (strcmp((yyvsp[-2].expr).type, "f32") == 0 && strcmp((yyvsp[0].expr).type, "f32") == 0) {
            int idx = alloc_local_f32();
            CODEGEN("fload %d", (yyvsp[-2].expr).local_idx);
            CODEGEN("fload %d", (yyvsp[0].expr).local_idx);
            CODEGEN("fadd");
            CODEGEN("fstore %d", idx);
            (yyval.expr) = (ExprVal){
                .type = strdup("f32"),
                .local_idx = idx,
                .f_val = (yyvsp[-2].expr).f_val + (yyvsp[0].expr).f_val
            };
        } else {
            fprintf(stderr, "error:%d: type mismatch in '+'\n", yylineno);
            (yyval.expr) = (ExprVal){ .type = strdup("undefined"), .local_idx = -1 };
        }
    }
#line 2747 "y.tab.c"
    break;

  case 64: /* Expression: Expression '-' Expression  */
#line 798 "compiler.y"
                                {
        if (strcmp((yyvsp[-2].expr).type, "i32") == 0 && strcmp((yyvsp[0].expr).type, "i32") == 0) {
            int idx = alloc_local_i32();
            CODEGEN("iload %d", (yyvsp[-2].expr).local_idx);
            CODEGEN("iload %d", (yyvsp[0].expr).local_idx);
            CODEGEN("isub");
            CODEGEN("istore %d", idx);
            (yyval.expr) = (ExprVal){
                .type = strdup("i32"),
                .local_idx = idx,
                .i_val = (yyvsp[-2].expr).i_val - (yyvsp[0].expr).i_val
            };
        } else if (strcmp((yyvsp[-2].expr).type, "f32") == 0 && strcmp((yyvsp[0].expr).type, "f32") == 0) {
            int idx = alloc_local_f32();
            CODEGEN("fload %d", (yyvsp[-2].expr).local_idx);
            CODEGEN("fload %d", (yyvsp[0].expr).local_idx);
            CODEGEN("fsub");
            CODEGEN("fstore %d", idx);
            (yyval.expr) = (ExprVal){
                .type = strdup("f32"),
                .local_idx = idx,
                .f_val = (yyvsp[-2].expr).f_val - (yyvsp[0].expr).f_val
            };
        } else {
            fprintf(stderr, "error:%d: type mismatch in '-'\n", yylineno);
            (yyval.expr) = (ExprVal){ .type = strdup("undefined"), .local_idx = -1 };
        }
    }
#line 2780 "y.tab.c"
    break;

  case 65: /* Expression: Expression '*' Expression  */
#line 826 "compiler.y"
                                {
        if (strcmp((yyvsp[-2].expr).type, "i32") == 0 && strcmp((yyvsp[0].expr).type, "i32") == 0) {
            int idx = alloc_local_i32();
            CODEGEN("iload %d", (yyvsp[-2].expr).local_idx);
            CODEGEN("iload %d", (yyvsp[0].expr).local_idx);
            CODEGEN("imul");
            CODEGEN("istore %d", idx);
            (yyval.expr) = (ExprVal){
                .type = strdup("i32"),
                .local_idx = idx,
                .i_val = (yyvsp[-2].expr).i_val * (yyvsp[0].expr).i_val
            };
        } else if (strcmp((yyvsp[-2].expr).type, "f32") == 0 && strcmp((yyvsp[0].expr).type, "f32") == 0) {
            int idx = alloc_local_f32();
            CODEGEN("fload %d", (yyvsp[-2].expr).local_idx);
            CODEGEN("fload %d", (yyvsp[0].expr).local_idx);
            CODEGEN("fmul");
            CODEGEN("fstore %d", idx);
            (yyval.expr) = (ExprVal){
                .type = strdup("f32"),
                .local_idx = idx,
                .f_val = (yyvsp[-2].expr).f_val * (yyvsp[0].expr).f_val
            };
        } else {
            fprintf(stderr, "error:%d: type mismatch in '*'\n", yylineno);
            (yyval.expr) = (ExprVal){ .type = strdup("undefined"), .local_idx = -1 };
        }
    }
#line 2813 "y.tab.c"
    break;

  case 66: /* Expression: Expression '/' Expression  */
#line 854 "compiler.y"
                                {
        if (strcmp((yyvsp[-2].expr).type, "i32") == 0 && strcmp((yyvsp[0].expr).type, "i32") == 0) {
            if ((yyvsp[0].expr).i_val == 0) {
                fprintf(stderr, "error:%d: division by zero\n", yylineno);
                (yyval.expr) = (ExprVal){ .type = strdup("undefined"), .local_idx = -1 };
            } else {
                int idx = alloc_local_i32();
                CODEGEN("iload %d", (yyvsp[-2].expr).local_idx);
                CODEGEN("iload %d", (yyvsp[0].expr).local_idx);
                CODEGEN("idiv");
                CODEGEN("istore %d", idx);
                (yyval.expr) = (ExprVal){
                    .type = strdup("i32"),
                    .local_idx = idx,
                    .i_val = (yyvsp[-2].expr).i_val / (yyvsp[0].expr).i_val
                };
            }
        } else if (strcmp((yyvsp[-2].expr).type, "f32") == 0 && strcmp((yyvsp[0].expr).type, "f32") == 0) {
            if ((yyvsp[0].expr).f_val == 0.0f) {
                fprintf(stderr, "error:%d: division by zero\n", yylineno);
                (yyval.expr) = (ExprVal){ .type = strdup("undefined"), .local_idx = -1 };
            } else {
                int idx = alloc_local_f32();
                CODEGEN("fload %d", (yyvsp[-2].expr).local_idx);
                CODEGEN("fload %d", (yyvsp[0].expr).local_idx);
                CODEGEN("fdiv");
                CODEGEN("fstore %d", idx);
                (yyval.expr) = (ExprVal){
                    .type = strdup("f32"),
                    .local_idx = idx,
                    .f_val = (yyvsp[-2].expr).f_val / (yyvsp[0].expr).f_val
                };
            }
        } else {
            fprintf(stderr, "error:%d: type mismatch in '/'\n", yylineno);
            (yyval.expr) = (ExprVal){ .type = strdup("undefined"), .local_idx = -1 };
        }
    }
#line 2856 "y.tab.c"
    break;

  case 67: /* Expression: Expression '%' Expression  */
#line 892 "compiler.y"
                                {
        if (strcmp((yyvsp[-2].expr).type, "i32") == 0 && strcmp((yyvsp[0].expr).type, "i32") == 0) {
            if ((yyvsp[0].expr).i_val == 0) {
                fprintf(stderr, "error:%d: division by zero in modulus\n", yylineno);
                (yyval.expr) = (ExprVal){ .type = strdup("undefined"), .local_idx = -1 };
            } else {
                int idx = alloc_local_i32();
                CODEGEN("iload %d", (yyvsp[-2].expr).local_idx);
                CODEGEN("iload %d", (yyvsp[0].expr).local_idx);
                CODEGEN("irem");
                CODEGEN("istore %d", idx);
                (yyval.expr) = (ExprVal){
                    .type = strdup("i32"),
                    .local_idx = idx,
                    .i_val = (yyvsp[-2].expr).i_val % (yyvsp[0].expr).i_val
                };
            }
        } else {
            fprintf(stderr, "error:%d: unsupported type for modulus (only i32 allowed)\n", yylineno);
            (yyval.expr) = (ExprVal){ .type = strdup("undefined"), .local_idx = -1 };
        }
    }
#line 2883 "y.tab.c"
    break;

  case 68: /* Expression: Expression '>' Expression  */
#line 914 "compiler.y"
                                {
        if (strcmp((yyvsp[-2].expr).type, (yyvsp[0].expr).type) != 0)
            printf("error:%d: invalid operation: GTR (mismatched types)\n", yylineno);

        int idx = alloc_local_i32();

        if (strcmp((yyvsp[-2].expr).type, "i32") == 0) {
            CODEGEN("iload %d", (yyvsp[-2].expr).local_idx);
            CODEGEN("iload %d", (yyvsp[0].expr).local_idx);
            CODEGEN("if_icmpgt Ltrue%d", label_count);
        } else if (strcmp((yyvsp[-2].expr).type, "f32") == 0) {
            CODEGEN("fload %d", (yyvsp[-2].expr).local_idx);
            CODEGEN("fload %d", (yyvsp[0].expr).local_idx);
            CODEGEN("fcmpg");
            CODEGEN("iconst_0");
            CODEGEN("if_icmpgt Ltrue%d", label_count);
        } else {
            printf("error:%d: '>' not supported for type %s\n", yylineno, (yyvsp[-2].expr).type);
        }

        CODEGEN("iconst_0");
        CODEGEN("goto Lend%d",  label_count);
        CODEGEN("Ltrue%d:",     label_count);
        CODEGEN("iconst_1");
        CODEGEN("Lend%d:",      label_count);

        CODEGEN("istore %d", idx);
        (yyval.expr) = (ExprVal){ .type = "bool", .local_idx = idx };
        label_count++;
    }
#line 2918 "y.tab.c"
    break;

  case 69: /* Expression: Expression '<' Expression  */
#line 946 "compiler.y"
    {
        if (strcmp((yyvsp[-2].expr).type, (yyvsp[0].expr).type) != 0)
            printf("error:%d: invalid operation: LSS (mismatched types)\n", yylineno);

        if (strcmp((yyvsp[-2].expr).type, "i32") == 0) {
            CODEGEN("iload %d", (yyvsp[-2].expr).local_idx);
            CODEGEN("iload %d", (yyvsp[0].expr).local_idx);
            CODEGEN("if_icmplt Ltrue%d", label_count);
        } else if (strcmp((yyvsp[-2].expr).type, "f32") == 0) {
            CODEGEN("fload %d", (yyvsp[-2].expr).local_idx);
            CODEGEN("fload %d", (yyvsp[0].expr).local_idx);
            CODEGEN("fcmpg");
            CODEGEN("iconst_0");
            CODEGEN("if_icmplt Ltrue%d", label_count);
        } else {
            printf("error:%d: '<' not supported for %s\n", yylineno, (yyvsp[-2].expr).type);
        }

        CODEGEN("iconst_0");
        CODEGEN("goto Lend%d",  label_count);
        CODEGEN("Ltrue%d:",     label_count);
        CODEGEN("iconst_1");
        CODEGEN("Lend%d:",      label_count);

        int idx = alloc_local_i32();
        CODEGEN("istore %d", idx);
        (yyval.expr) = (ExprVal){ .type = "bool", .local_idx = idx };
        label_count++;
    }
#line 2952 "y.tab.c"
    break;

  case 70: /* Expression: Expression LAND Expression  */
#line 976 "compiler.y"
                                 {
        int result = alloc_local_i32();
        int false_label = label_count++;
        int end_label = label_count++;
        // if left operand is false → short-circuit false
        CODEGEN("iload %d", (yyvsp[-2].expr).local_idx);
        CODEGEN("ifeq Lfalse%d", false_label);
        // else evaluate right
        CODEGEN("iload %d", (yyvsp[0].expr).local_idx);
        CODEGEN("ifeq Lfalse%d", false_label);
        // both true
        CODEGEN("iconst_1");
        CODEGEN("goto Lend%d", end_label);
        // any false → short-circuit
        CODEGEN("Lfalse%d:", false_label);
        CODEGEN("iconst_0");
        // store result
        CODEGEN("Lend%d:", end_label);
        CODEGEN("istore %d", result);
        (yyval.expr) = (ExprVal){ .type = "bool", .local_idx = result };
    }
#line 2978 "y.tab.c"
    break;

  case 71: /* Expression: Expression LOR Expression  */
#line 997 "compiler.y"
                                {
        int result = alloc_local_i32();
        int true_label = label_count++;
        int end_label = label_count++;

        CODEGEN("iload %d", (yyvsp[-2].expr).local_idx);
        CODEGEN("ifne Ltrue%d", true_label);  // if left is true, short-circuit
        CODEGEN("iload %d", (yyvsp[0].expr).local_idx);    // evaluate right
        CODEGEN("ifne Ltrue%d", true_label);
        CODEGEN("iconst_0");
        CODEGEN("goto Lend%d", end_label);
        CODEGEN("Ltrue%d:", true_label);
        CODEGEN("iconst_1");
        CODEGEN("Lend%d:", end_label);
        CODEGEN("istore %d", result);
        (yyval.expr) = (ExprVal){ .type = "bool", .local_idx = result };
    }
#line 3000 "y.tab.c"
    break;

  case 72: /* Expression: '!' Expression  */
#line 1014 "compiler.y"
                     {
        int result = alloc_local_i32();
        int true_label = label_count++;
        int end_label = label_count++;

        CODEGEN("iload %d", (yyvsp[0].expr).local_idx);
        CODEGEN("ifeq Ltrue%d", true_label);
        CODEGEN("iconst_0");
        CODEGEN("goto Lend%d", end_label);
        CODEGEN("Ltrue%d:", true_label);
        CODEGEN("iconst_1");
        CODEGEN("Lend%d:", end_label);
        CODEGEN("istore %d", result);

        (yyval.expr) = (ExprVal){ .type = "bool", .local_idx = result };
        label_count++;
    }
#line 3022 "y.tab.c"
    break;

  case 73: /* Expression: '-' Expression  */
#line 1031 "compiler.y"
                                  {
        if (strcmp((yyvsp[0].expr).type, "i32") == 0) {
            CODEGEN("iload %d", (yyvsp[0].expr).local_idx);
            CODEGEN("ineg");
            int idx = alloc_local_i32();
            CODEGEN("istore %d", idx);
            (yyval.expr) = (ExprVal){ .type = "i32", .i_val = -(yyvsp[0].expr).i_val, .local_idx = idx };
        } else if (strcmp((yyvsp[0].expr).type, "f32") == 0) {
            CODEGEN("fload %d", (yyvsp[0].expr).local_idx);
            CODEGEN("fneg");
            int idx = alloc_local_f32();
            CODEGEN("fstore %d", idx);
            (yyval.expr) = (ExprVal){ .type = "f32", .f_val = -(yyvsp[0].expr).f_val, .local_idx = idx };
        } else {
            fprintf(stderr, "error:%d: unary minus on unsupported type\n", yylineno);
            (yyval.expr) = (ExprVal){ .type = "undefined" };
        }
    }
#line 3045 "y.tab.c"
    break;

  case 74: /* Expression: '(' Expression ')'  */
#line 1049 "compiler.y"
                         {
        (yyval.expr) = (yyvsp[-1].expr);
    }
#line 3053 "y.tab.c"
    break;

  case 75: /* Expression: Expression EQL Expression  */
#line 1052 "compiler.y"
                                {
        CODEGEN("iload %d", (yyvsp[-2].expr).local_idx);
        CODEGEN("iload %d", (yyvsp[0].expr).local_idx);

        CODEGEN("if_icmpeq Ltrue%d", label_count);
        CODEGEN("iconst_0");
        CODEGEN("goto Lend%d",  label_count);
        CODEGEN("Ltrue%d:",     label_count);
        CODEGEN("iconst_1");
        CODEGEN("Lend%d:",      label_count);

        int idx = alloc_local_i32();
        CODEGEN("istore %d", idx);
        (yyval.expr) = (ExprVal){ .type = "bool", .local_idx = idx };
        label_count++;
    }
#line 3074 "y.tab.c"
    break;

  case 76: /* Expression: Expression NEQ Expression  */
#line 1068 "compiler.y"
                                {
        CODEGEN("iload %d", (yyvsp[-2].expr).local_idx);
        CODEGEN("iload %d", (yyvsp[0].expr).local_idx);

        CODEGEN("if_icmpne Ltrue%d", label_count);
        CODEGEN("iconst_0");
        CODEGEN("goto Lend%d",  label_count);
        CODEGEN("Ltrue%d:",     label_count);
        CODEGEN("iconst_1");
        CODEGEN("Lend%d:",      label_count);

        int idx = alloc_local_i32();
        CODEGEN("istore %d", idx);
        (yyval.expr) = (ExprVal){ .type = "bool", .local_idx = idx };
        label_count++;
    }
#line 3095 "y.tab.c"
    break;

  case 77: /* Expression: Expression '[' INT_LIT ']'  */
#line 1084 "compiler.y"
                                 {
        if (strcmp((yyvsp[-3].expr).type, "array") != 0) {
            printf("error:%d: trying to index a non-array\n", yylineno);
            (yyval.expr) = (ExprVal){ .type = "undefined" };
        } else {
            CODEGEN("ldc %d", (yyvsp[-1].i_val));
            CODEGEN("aaload");
            (yyval.expr) = (ExprVal){ .type = "i32" };
        }
    }
#line 3110 "y.tab.c"
    break;

  case 78: /* Expression: Expression LSHIFT Expression  */
#line 1094 "compiler.y"
                                   {
        if (strcmp((yyvsp[-2].expr).type, "undefined") != 0 && strcmp((yyvsp[0].expr).type, "undefined") != 0 && strcmp((yyvsp[-2].expr).type, (yyvsp[0].expr).type) != 0) {
            printf("error:%d: invalid operation: LSHIFT (mismatched types)\n", yylineno);
            (yyval.expr) = (ExprVal){ .type = "undefined" };
        } else {
            CODEGEN("ishl");
            (yyval.expr) = (ExprVal){ .type = (yyvsp[-2].expr).type };
        }
    }
#line 3124 "y.tab.c"
    break;

  case 79: /* Expression: TRUE  */
#line 1103 "compiler.y"
           {
        int idx = alloc_local_i32();
        CODEGEN("iconst_1");
        CODEGEN("istore %d", idx);
        (yyval.expr) = (ExprVal){ .type = "bool", .local_idx = idx, .i_val = 1 };
    }
#line 3135 "y.tab.c"
    break;

  case 80: /* Expression: FALSE  */
#line 1109 "compiler.y"
            {
        int idx = alloc_local_i32();
        CODEGEN("iconst_0");
        CODEGEN("istore %d", idx);
        (yyval.expr) = (ExprVal){ .type = "bool", .local_idx = idx, .i_val = 0 };
    }
#line 3146 "y.tab.c"
    break;

  case 81: /* Expression: Expression AS Type  */
#line 1115 "compiler.y"
                         {
        if (strcmp((yyvsp[0].s_val), "i32") == 0 && strcmp((yyvsp[-2].expr).type, "f32") == 0) {
            int idx = alloc_local_i32();
            CODEGEN("fload %d", (yyvsp[-2].expr).local_idx);
            CODEGEN("f2i");
            CODEGEN("istore %d", idx);
            (yyval.expr) = (ExprVal){ .type = "i32", .local_idx = idx };
        } else if (strcmp((yyvsp[0].s_val), "f32") == 0 && strcmp((yyvsp[-2].expr).type, "i32") == 0) {
            int idx = alloc_local_f32();
            CODEGEN("iload %d", (yyvsp[-2].expr).local_idx);
            CODEGEN("i2f");
            CODEGEN("fstore %d", idx);
            (yyval.expr) = (ExprVal){ .type = "f32", .local_idx = idx };
        } else {
            fprintf(stderr, "error:%d: invalid cast from %s to %s\n", yylineno, (yyvsp[-2].expr).type, (yyvsp[0].s_val));
            (yyval.expr) = (ExprVal){ .type = strdup("undefined"), .local_idx = -1 };
        }
    }
#line 3169 "y.tab.c"
    break;

  case 82: /* Type: INT  */
#line 1136 "compiler.y"
            { (yyval.s_val) = "i32"; }
#line 3175 "y.tab.c"
    break;

  case 83: /* Type: FLOAT  */
#line 1137 "compiler.y"
            { (yyval.s_val) = "f32"; }
#line 3181 "y.tab.c"
    break;

  case 84: /* Type: BOOL  */
#line 1138 "compiler.y"
            { (yyval.s_val) = "bool"; }
#line 3187 "y.tab.c"
    break;

  case 85: /* Type: '&' STR  */
#line 1139 "compiler.y"
              { (yyval.s_val) = "str"; }
#line 3193 "y.tab.c"
    break;

  case 86: /* Type: '[' Type ';' INT_LIT ']'  */
#line 1140 "compiler.y"
                               { (yyval.s_val) = "array"; }
#line 3199 "y.tab.c"
    break;


#line 3203 "y.tab.c"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;
  *++yylsp = yyloc;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      {
        yypcontext_t yyctx
          = {yyssp, yytoken, &yylloc};
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = yysyntax_error (&yymsg_alloc, &yymsg, &yyctx);
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == -1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = YY_CAST (char *,
                             YYSTACK_ALLOC (YY_CAST (YYSIZE_T, yymsg_alloc)));
            if (yymsg)
              {
                yysyntax_error_status
                  = yysyntax_error (&yymsg_alloc, &yymsg, &yyctx);
                yymsgp = yymsg;
              }
            else
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = YYENOMEM;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == YYENOMEM)
          YYNOMEM;
      }
    }

  yyerror_range[1] = yylloc;
  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
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
                      yytoken, &yylval, &yylloc);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;
  ++yynerrs;

  /* Do not reclaim the symbols of the rule whose action triggered
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
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;

      yyerror_range[1] = *yylsp;
      yydestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (yystate), yyvsp, yylsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  yyerror_range[2] = yylloc;
  ++yylsp;
  YYLLOC_DEFAULT (*yylsp, yyerror_range, 2);

  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval, &yylloc);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp, yylsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
  return yyresult;
}

#line 1142 "compiler.y"


/* C code section */
int main(int argc, char *argv[])
{
    if (argc == 2) {
        yyin = fopen(argv[1], "r");
        // Open the output file for Jasmin code
        yyout = fopen("hw3.j", "w"); // Assuming Main.j is the output file
        if (!yyout) {
            perror("Error opening output file hw3.j");
            return 1;
        }
    } else {
        yyin = stdin;
        // If no input file, still open Main.j for output
        yyout = fopen("hw3.j", "w");
        if (!yyout) {
            perror("Error opening output file hw3.j");
            return 1;
        }
    }

    yylineno = 1;
    yyparse();

    printf("Total lines: %d\n", yylineno-1);
    fclose(yyin);
    fclose(yyout); // Close the output file
    return 0;
}

void CODEGEN(const char *format, ...) {
    va_list args;
    va_start(args, format);
    vfprintf(yyout, format, args);
    fprintf(yyout, "\n"); // Add a newline after each generated line
    va_end(args);
}

static void create_symbol(int scope) {
    printf("> Create symbol table (scope level %d)\n", scope);
}

static void insert_symbol(const char *name, int addr, int scope) {
    printf("> Insert `%s` (addr: %d) to scope level %d\n", name, addr, scope);
}

static void dump_symbol(int scope) {
    printf("\n> Dump symbol table (scope level: %d)\n", scope);
    printf("%-10s%-10s%-10s%-10s%-10s%-10s%-10s\n",
           "Index", "Name", "Mut", "Type", "Addr", "Lineno", "Func_sig");

    if (scope == 0) {
        printf("%-10d%-10s%-10s%-10s%-10d%-10d%-10s\n",
               0, "main", "-1", "func", -1, 1, "(V)V");
    } else {
        int local_index = 0;  // <--- Start from 0
        for (int i = 0; i < symtab_sz; i++) {
            if (symtab[i].scope == scope) {
                printf("%-10d%-10s%-10d%-10s%-10d%-10d%-10s\n",
                    local_index++,
                        symtab[i].name,
                        symtab[i].mut,
                        symtab[i].type,
                        symtab[i].addr,
                        symtab[i].lineno,
                        "-");
            }
        }
    }
}

static void pop_scope(int scope) {
    while (symtab_sz > 0 && symtab[symtab_sz - 1].scope == scope) {
        symtab_sz--;
    }
}

static void add_symbol(const char *name, int addr, const char *type, int lineno, ExprVal value, int mut) {
    strcpy(symtab[symtab_sz].name, name);
    symtab[symtab_sz].addr = addr;
    strcpy(symtab[symtab_sz].type, type);
    symtab[symtab_sz].lineno = lineno;
    symtab[symtab_sz].mut = mut;
    symtab[symtab_sz].scope = scope - 1;

    if (!strcmp(type, "i32")) {
        symtab[symtab_sz].i_val = value.i_val;
    } else if (!strcmp(type, "f32")) {
        symtab[symtab_sz].f_val = value.f_val;
    } else if (!strcmp(type, "str")) {
        symtab[symtab_sz].s_val = value.s_val;
    }
    symtab_sz++;
}

static ExprVal get_expr_val(const char *name) {
    for (int i = symtab_sz - 1; i >= 0; i--) {
        if (strcmp(symtab[i].name, name) == 0) {
            ExprVal ev;
            ev.type = strdup(symtab[i].type);
            ev.local_idx = symtab[i].addr;
            
            if (!strcmp(symtab[i].type, "i32"))
                ev.i_val = symtab[i].i_val;
            else if (!strcmp(symtab[i].type, "f32"))
                ev.f_val = symtab[i].f_val;
            else if (!strcmp(symtab[i].type, "str"))
                ev.s_val = symtab[i].s_val;
            else if (!strcmp(symtab[i].type, "bool"))
                ev.i_val = symtab[i].i_val;
            return ev;
        }
    }
    ExprVal empty = {0};
    empty.type = strdup("undefined");
    return empty;
}

/* static int lookup_symbol(const char *name) {
    for (int i = symtab_sz - 1; i >= 0; --i)
        if (strcmp(symtab[i].name, name) == 0)
            return i;
    return -1;
} */

static int lookup_symbol(const char *name) {
    for (int i = symtab_sz - 1; i >= 0; --i) {
        if (strcmp(symtab[i].name, name) == 0) {
            printf("[lookup] found `%s` in scope %d at addr %d\n",
                   name, symtab[i].scope, symtab[i].addr);
            return i;
        }
    }
    printf("[lookup] `%s` not found\n", name);
    return -1;
}
