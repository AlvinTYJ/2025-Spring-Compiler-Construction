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
#line 4 "compiler.y"

    #include "compiler_common.h"
    // #define YYDEBUG 1
    // int yydebug = 1;

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

    extern int yylineno;
    extern int yylex();
    extern FILE *yyin;

    int yylex_destroy ();
    void yyerror (char const *s)
    {
        printf("error:%d: %s\n", yylineno, s);
    }

    extern int yylineno;
    extern int yylex();
    extern FILE *yyin;

    /* Symbol table function - you can add new functions if needed. */
    /* parameters and return type can be changed */
    static void create_symbol(int scope);
    static void insert_symbol(const char *name, int addr, int scope);
    static void dump_symbol(int scope);
    static void pop_scope(int scope); 
    static void add_symbol(const char *name, int addr, const char *type, int lineno, ExprVal value, int mut);
    static int lookup_address(const char *name);
    static ExprVal get_expr_val(const char *name);
    static int lookup_symbol(const char *name);

#line 124 "y.tab.c"

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

#line 270 "y.tab.c"

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
  YYSYMBOL_3_ = 3,                         /* '>'  */
  YYSYMBOL_4_ = 4,                         /* '<'  */
  YYSYMBOL_5_ = 5,                         /* '+'  */
  YYSYMBOL_6_ = 6,                         /* '-'  */
  YYSYMBOL_7_ = 7,                         /* '*'  */
  YYSYMBOL_8_ = 8,                         /* '/'  */
  YYSYMBOL_9_ = 9,                         /* '%'  */
  YYSYMBOL_10_ = 10,                       /* '!'  */
  YYSYMBOL_UMINUS = 11,                    /* UMINUS  */
  YYSYMBOL_LET = 12,                       /* LET  */
  YYSYMBOL_MUT = 13,                       /* MUT  */
  YYSYMBOL_NEWLINE = 14,                   /* NEWLINE  */
  YYSYMBOL_INT = 15,                       /* INT  */
  YYSYMBOL_FLOAT = 16,                     /* FLOAT  */
  YYSYMBOL_BOOL = 17,                      /* BOOL  */
  YYSYMBOL_STR = 18,                       /* STR  */
  YYSYMBOL_TRUE = 19,                      /* TRUE  */
  YYSYMBOL_FALSE = 20,                     /* FALSE  */
  YYSYMBOL_GEQ = 21,                       /* GEQ  */
  YYSYMBOL_LEQ = 22,                       /* LEQ  */
  YYSYMBOL_EQL = 23,                       /* EQL  */
  YYSYMBOL_NEQ = 24,                       /* NEQ  */
  YYSYMBOL_LOR = 25,                       /* LOR  */
  YYSYMBOL_LAND = 26,                      /* LAND  */
  YYSYMBOL_ADD_ASSIGN = 27,                /* ADD_ASSIGN  */
  YYSYMBOL_SUB_ASSIGN = 28,                /* SUB_ASSIGN  */
  YYSYMBOL_MUL_ASSIGN = 29,                /* MUL_ASSIGN  */
  YYSYMBOL_DIV_ASSIGN = 30,                /* DIV_ASSIGN  */
  YYSYMBOL_REM_ASSIGN = 31,                /* REM_ASSIGN  */
  YYSYMBOL_IF = 32,                        /* IF  */
  YYSYMBOL_ELSE = 33,                      /* ELSE  */
  YYSYMBOL_FOR = 34,                       /* FOR  */
  YYSYMBOL_WHILE = 35,                     /* WHILE  */
  YYSYMBOL_LOOP = 36,                      /* LOOP  */
  YYSYMBOL_PRINT = 37,                     /* PRINT  */
  YYSYMBOL_PRINTLN = 38,                   /* PRINTLN  */
  YYSYMBOL_FUNC = 39,                      /* FUNC  */
  YYSYMBOL_RETURN = 40,                    /* RETURN  */
  YYSYMBOL_BREAK = 41,                     /* BREAK  */
  YYSYMBOL_ARROW = 42,                     /* ARROW  */
  YYSYMBOL_AS = 43,                        /* AS  */
  YYSYMBOL_IN = 44,                        /* IN  */
  YYSYMBOL_DOTDOT = 45,                    /* DOTDOT  */
  YYSYMBOL_RSHIFT = 46,                    /* RSHIFT  */
  YYSYMBOL_LSHIFT = 47,                    /* LSHIFT  */
  YYSYMBOL_INT_LIT = 48,                   /* INT_LIT  */
  YYSYMBOL_FLOAT_LIT = 49,                 /* FLOAT_LIT  */
  YYSYMBOL_STRING_LIT = 50,                /* STRING_LIT  */
  YYSYMBOL_ID = 51,                        /* ID  */
  YYSYMBOL_52_ = 52,                       /* '('  */
  YYSYMBOL_53_ = 53,                       /* ')'  */
  YYSYMBOL_54_ = 54,                       /* '{'  */
  YYSYMBOL_55_ = 55,                       /* '}'  */
  YYSYMBOL_56_ = 56,                       /* '='  */
  YYSYMBOL_57_ = 57,                       /* ';'  */
  YYSYMBOL_58_ = 58,                       /* ':'  */
  YYSYMBOL_59_ = 59,                       /* ','  */
  YYSYMBOL_60_ = 60,                       /* '['  */
  YYSYMBOL_61_ = 61,                       /* ']'  */
  YYSYMBOL_62_ = 62,                       /* '&'  */
  YYSYMBOL_YYACCEPT = 63,                  /* $accept  */
  YYSYMBOL_Program = 64,                   /* Program  */
  YYSYMBOL_65_1 = 65,                      /* $@1  */
  YYSYMBOL_GlobalStatementList = 66,       /* GlobalStatementList  */
  YYSYMBOL_GlobalStatement = 67,           /* GlobalStatement  */
  YYSYMBOL_FunctionDeclStmt = 68,          /* FunctionDeclStmt  */
  YYSYMBOL_69_2 = 69,                      /* $@2  */
  YYSYMBOL_FuncHeader = 70,                /* FuncHeader  */
  YYSYMBOL_Block = 71,                     /* Block  */
  YYSYMBOL_72_3 = 72,                      /* $@3  */
  YYSYMBOL_StatementList = 73,             /* StatementList  */
  YYSYMBOL_IfStmt = 74,                    /* IfStmt  */
  YYSYMBOL_WhileStmt = 75,                 /* WhileStmt  */
  YYSYMBOL_Statement = 76,                 /* Statement  */
  YYSYMBOL_ArrayElems = 77,                /* ArrayElems  */
  YYSYMBOL_ArrayLiteral = 78,              /* ArrayLiteral  */
  YYSYMBOL_Expression = 79,                /* Expression  */
  YYSYMBOL_Type = 80                       /* Type  */
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
#define YYLAST   609

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  63
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  18
/* YYNRULES -- Number of rules.  */
#define YYNRULES  68
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  147

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   298


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
       2,     2,     2,    10,     2,     2,     2,     9,    62,     2,
      52,    53,     7,     5,    59,     6,     2,     8,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    58,    57,
       4,    56,     3,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    60,     2,    61,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    54,     2,    55,     2,     2,     2,     2,
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
       2,     2,     2,     2,     2,     2,     1,     2,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   109,   109,   109,   114,   115,   119,   120,   124,   124,
     130,   138,   137,   149,   150,   154,   155,   159,   163,   164,
     165,   171,   177,   184,   191,   197,   203,   209,   212,   215,
     216,   218,   234,   254,   259,   264,   269,   274,   282,   283,
     287,   294,   304,   308,   312,   316,   320,   324,   337,   347,
     357,   367,   377,   381,   390,   399,   403,   407,   411,   419,
     422,   425,   428,   433,   448,   449,   450,   451,   452
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
  "\"end of file\"", "error", "\"invalid token\"", "'>'", "'<'", "'+'",
  "'-'", "'*'", "'/'", "'%'", "'!'", "UMINUS", "LET", "MUT", "NEWLINE",
  "INT", "FLOAT", "BOOL", "STR", "TRUE", "FALSE", "GEQ", "LEQ", "EQL",
  "NEQ", "LOR", "LAND", "ADD_ASSIGN", "SUB_ASSIGN", "MUL_ASSIGN",
  "DIV_ASSIGN", "REM_ASSIGN", "IF", "ELSE", "FOR", "WHILE", "LOOP",
  "PRINT", "PRINTLN", "FUNC", "RETURN", "BREAK", "ARROW", "AS", "IN",
  "DOTDOT", "RSHIFT", "LSHIFT", "INT_LIT", "FLOAT_LIT", "STRING_LIT", "ID",
  "'('", "')'", "'{'", "'}'", "'='", "';'", "':'", "','", "'['", "']'",
  "'&'", "$accept", "Program", "$@1", "GlobalStatementList",
  "GlobalStatement", "FunctionDeclStmt", "$@2", "FuncHeader", "Block",
  "$@3", "StatementList", "IfStmt", "WhileStmt", "Statement", "ArrayElems",
  "ArrayLiteral", "Expression", "Type", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-51)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -51,     2,    -4,   -51,   -51,   -44,    -4,   -51,   -51,   -16,
     -51,   -51,     7,   -51,    11,   -51,   -51,   -51,   179,    18,
     -51,   557,   557,    15,    24,   208,   -51,   -51,   -51,   -51,
     -51,    26,   -50,   557,   557,   -51,   -51,   -51,   -51,   -51,
     -51,   557,    49,    49,   557,   557,   557,   557,   557,   557,
     557,   557,   557,     3,   557,   -12,    19,    19,    81,   557,
     557,   557,   557,   557,   557,   557,   557,   557,   557,   557,
     -12,   557,    32,    48,   -51,   107,   139,   114,   172,   197,
     242,   267,   312,   337,   557,   -12,   382,   -51,   -51,   -51,
     -12,    64,   -36,   -51,     8,     8,   181,   181,   -42,   -42,
     -42,     8,     8,   523,   535,   -51,   465,    30,    11,    36,
      37,   -51,   -51,   -51,   -51,   -51,   -51,   -51,   407,    14,
     -51,    38,   -51,   542,   -51,   -51,   -51,   -51,   -51,   -51,
     557,   -51,    50,    52,    40,   452,   477,    41,   -51,     5,
     -51,   -51,   -51,   -51,    77,   -51,   -51
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       2,     0,     0,     1,     7,     0,     3,     5,     6,     0,
      10,     4,     0,     8,     0,    11,     9,    14,     0,     0,
      30,     0,     0,     0,     0,     0,    12,    29,    18,    19,
      13,     0,     0,     0,     0,    45,    46,    42,    43,    44,
      41,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    58,    57,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    15,    17,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    64,    65,    66,
       0,     0,     0,    59,    53,    54,    48,    49,    50,    51,
      52,    60,    61,    56,    55,    47,    63,     0,     0,     0,
       0,    33,    34,    35,    36,    37,    32,    31,     0,     0,
      20,     0,    67,     0,    22,    62,    16,    28,    27,    21,
       0,    23,     0,     0,     0,     0,     0,     0,    38,     0,
      24,    25,    26,    68,     0,    40,    39
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -51,   -51,   -51,   -51,   120,   -51,   -51,   -51,    -9,   -51,
     -51,   -51,   -51,   -51,   -51,   -51,   -22,    -7
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     1,     2,     6,     7,     8,    14,     9,    16,    17,
      18,    28,    29,    30,   139,   134,    42,    92
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      43,    70,     3,    87,    88,    89,    54,    10,    55,    27,
       4,    56,    57,    61,    62,    63,    64,    65,    72,    58,
     123,   124,    75,    76,    77,    78,    79,    80,    81,    82,
      83,    31,    86,    73,    74,     5,    12,    94,    95,    96,
      97,    98,    99,   100,   101,   102,   103,   104,    90,   106,
      91,    70,    59,    60,    61,    62,    63,    64,    65,    84,
      13,    85,   118,   105,   144,    15,   145,    44,    72,    32,
     130,   131,    66,    67,    68,    69,    45,    53,   119,    72,
     107,   108,   122,   121,    59,    60,    61,    62,    63,    64,
      65,   125,    70,   127,   128,   132,    71,   140,   137,   126,
     138,   135,   143,    15,    66,    67,    68,    69,   136,    72,
      59,    60,    61,    62,    63,    64,    65,    59,    60,    61,
      62,    63,    64,    65,    70,   146,    11,     0,    71,     0,
      66,    67,    68,    69,    93,     0,     0,    66,    67,    68,
      69,    72,    59,    60,    61,    62,    63,    64,    65,     0,
      70,     0,     0,     0,    71,     0,     0,    70,     0,     0,
     109,    71,    66,    67,    68,    69,     0,    72,     0,     0,
       0,   111,     0,     0,    72,    59,    60,    61,    62,    63,
      64,    65,    70,     0,     0,     0,    71,     0,    63,    64,
      65,    19,   110,    20,     0,    66,    67,    68,    69,    72,
      59,    60,    61,    62,    63,    64,    65,     0,     0,     0,
       0,    21,     0,     0,    22,    70,    23,    24,     0,    71,
      66,    67,    68,    69,    70,     0,     0,     0,     0,   112,
      25,     0,    72,    15,    26,    46,    47,    48,    49,    50,
      70,    72,     0,     0,    71,    59,    60,    61,    62,    63,
      64,    65,     0,     0,   113,    51,     0,    72,     0,     0,
       0,     0,     0,     0,    52,    66,    67,    68,    69,     0,
      59,    60,    61,    62,    63,    64,    65,     0,     0,     0,
       0,     0,     0,     0,     0,    70,     0,     0,     0,    71,
      66,    67,    68,    69,     0,     0,     0,     0,     0,   114,
       0,     0,    72,     0,     0,     0,     0,     0,     0,     0,
      70,     0,     0,     0,    71,    59,    60,    61,    62,    63,
      64,    65,     0,     0,   115,     0,     0,    72,     0,     0,
       0,     0,     0,     0,     0,    66,    67,    68,    69,     0,
      59,    60,    61,    62,    63,    64,    65,     0,     0,     0,
       0,     0,     0,     0,     0,    70,     0,     0,     0,    71,
      66,    67,    68,    69,     0,     0,     0,     0,     0,   116,
       0,     0,    72,     0,     0,     0,     0,     0,     0,     0,
      70,     0,     0,     0,    71,    59,    60,    61,    62,    63,
      64,    65,     0,     0,   117,     0,     0,    72,     0,     0,
       0,     0,     0,     0,     0,    66,    67,    68,    69,     0,
      59,    60,    61,    62,    63,    64,    65,     0,     0,     0,
       0,     0,     0,     0,     0,    70,     0,     0,     0,    71,
      66,    67,    68,    69,     0,     0,     0,     0,     0,   120,
       0,     0,    72,     0,     0,     0,     0,     0,     0,     0,
      70,     0,     0,     0,    71,    59,    60,    61,    62,    63,
      64,    65,     0,     0,   129,     0,     0,    72,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    68,    69,     0,
      59,    60,    61,    62,    63,    64,    65,     0,    66,    67,
      68,    69,     0,     0,     0,    70,     0,     0,     0,    71,
      66,    67,    68,    69,     0,     0,     0,     0,    70,   141,
       0,     0,    72,     0,     0,     0,     0,     0,     0,     0,
      70,     0,     0,     0,    71,    72,    59,    60,    61,    62,
      63,    64,    65,     0,   142,     0,     0,    72,    59,    60,
      61,    62,    63,    64,    65,     0,    66,    67,    33,    69,
       0,     0,    34,     0,     0,     0,     0,     0,    66,    67,
       0,    35,    36,    33,     0,     0,    70,    34,     0,     0,
       0,     0,     0,     0,     0,     0,    35,    36,    70,     0,
       0,     0,     0,    72,     0,     0,     0,     0,     0,     0,
      37,    38,    39,    40,    41,    72,     0,     0,     0,     0,
       0,     0,   133,     0,     0,    37,    38,    39,    40,    41
};

static const yytype_int16 yycheck[] =
{
      22,    43,     0,    15,    16,    17,    56,    51,    58,    18,
      14,    33,    34,     5,     6,     7,     8,     9,    60,    41,
      56,    57,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    13,    54,    42,    43,    39,    52,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,    69,    60,    71,
      62,    43,     3,     4,     5,     6,     7,     8,     9,    56,
      53,    58,    84,    70,    59,    54,    61,    52,    60,    51,
      56,    57,    23,    24,    25,    26,    52,    51,    85,    60,
      48,    33,    18,    90,     3,     4,     5,     6,     7,     8,
       9,    61,    43,    57,    57,    57,    47,    57,    48,   108,
      48,   123,    61,    54,    23,    24,    25,    26,   130,    60,
       3,     4,     5,     6,     7,     8,     9,     3,     4,     5,
       6,     7,     8,     9,    43,    48,     6,    -1,    47,    -1,
      23,    24,    25,    26,    53,    -1,    -1,    23,    24,    25,
      26,    60,     3,     4,     5,     6,     7,     8,     9,    -1,
      43,    -1,    -1,    -1,    47,    -1,    -1,    43,    -1,    -1,
      53,    47,    23,    24,    25,    26,    -1,    60,    -1,    -1,
      -1,    57,    -1,    -1,    60,     3,     4,     5,     6,     7,
       8,     9,    43,    -1,    -1,    -1,    47,    -1,     7,     8,
       9,    12,    53,    14,    -1,    23,    24,    25,    26,    60,
       3,     4,     5,     6,     7,     8,     9,    -1,    -1,    -1,
      -1,    32,    -1,    -1,    35,    43,    37,    38,    -1,    47,
      23,    24,    25,    26,    43,    -1,    -1,    -1,    -1,    57,
      51,    -1,    60,    54,    55,    27,    28,    29,    30,    31,
      43,    60,    -1,    -1,    47,     3,     4,     5,     6,     7,
       8,     9,    -1,    -1,    57,    47,    -1,    60,    -1,    -1,
      -1,    -1,    -1,    -1,    56,    23,    24,    25,    26,    -1,
       3,     4,     5,     6,     7,     8,     9,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    43,    -1,    -1,    -1,    47,
      23,    24,    25,    26,    -1,    -1,    -1,    -1,    -1,    57,
      -1,    -1,    60,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      43,    -1,    -1,    -1,    47,     3,     4,     5,     6,     7,
       8,     9,    -1,    -1,    57,    -1,    -1,    60,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    23,    24,    25,    26,    -1,
       3,     4,     5,     6,     7,     8,     9,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    43,    -1,    -1,    -1,    47,
      23,    24,    25,    26,    -1,    -1,    -1,    -1,    -1,    57,
      -1,    -1,    60,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      43,    -1,    -1,    -1,    47,     3,     4,     5,     6,     7,
       8,     9,    -1,    -1,    57,    -1,    -1,    60,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    23,    24,    25,    26,    -1,
       3,     4,     5,     6,     7,     8,     9,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    43,    -1,    -1,    -1,    47,
      23,    24,    25,    26,    -1,    -1,    -1,    -1,    -1,    57,
      -1,    -1,    60,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      43,    -1,    -1,    -1,    47,     3,     4,     5,     6,     7,
       8,     9,    -1,    -1,    57,    -1,    -1,    60,     3,     4,
       5,     6,     7,     8,     9,    23,    24,    25,    26,    -1,
       3,     4,     5,     6,     7,     8,     9,    -1,    23,    24,
      25,    26,    -1,    -1,    -1,    43,    -1,    -1,    -1,    47,
      23,    24,    25,    26,    -1,    -1,    -1,    -1,    43,    57,
      -1,    -1,    60,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      43,    -1,    -1,    -1,    47,    60,     3,     4,     5,     6,
       7,     8,     9,    -1,    57,    -1,    -1,    60,     3,     4,
       5,     6,     7,     8,     9,    -1,    23,    24,     6,    26,
      -1,    -1,    10,    -1,    -1,    -1,    -1,    -1,    23,    24,
      -1,    19,    20,     6,    -1,    -1,    43,    10,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    19,    20,    43,    -1,
      -1,    -1,    -1,    60,    -1,    -1,    -1,    -1,    -1,    -1,
      48,    49,    50,    51,    52,    60,    -1,    -1,    -1,    -1,
      -1,    -1,    60,    -1,    -1,    48,    49,    50,    51,    52
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    64,    65,     0,    14,    39,    66,    67,    68,    70,
      51,    67,    52,    53,    69,    54,    71,    72,    73,    12,
      14,    32,    35,    37,    38,    51,    55,    71,    74,    75,
      76,    13,    51,     6,    10,    19,    20,    48,    49,    50,
      51,    52,    79,    79,    52,    52,    27,    28,    29,    30,
      31,    47,    56,    51,    56,    58,    79,    79,    79,     3,
       4,     5,     6,     7,     8,     9,    23,    24,    25,    26,
      43,    47,    60,    71,    71,    79,    79,    79,    79,    79,
      79,    79,    79,    79,    56,    58,    79,    15,    16,    17,
      60,    62,    80,    53,    79,    79,    79,    79,    79,    79,
      79,    79,    79,    79,    79,    80,    79,    48,    33,    53,
      53,    57,    57,    57,    57,    57,    57,    57,    79,    80,
      57,    80,    18,    56,    57,    61,    71,    57,    57,    57,
      56,    57,    57,    60,    78,    79,    79,    48,    48,    77,
      57,    57,    57,    61,    59,    61,    48
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    63,    65,    64,    66,    66,    67,    67,    69,    68,
      70,    72,    71,    73,    73,    74,    74,    75,    76,    76,
      76,    76,    76,    76,    76,    76,    76,    76,    76,    76,
      76,    76,    76,    76,    76,    76,    76,    76,    77,    77,
      78,    79,    79,    79,    79,    79,    79,    79,    79,    79,
      79,    79,    79,    79,    79,    79,    79,    79,    79,    79,
      79,    79,    79,    79,    80,    80,    80,    80,    80
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     0,     2,     2,     1,     1,     1,     0,     5,
       2,     0,     4,     2,     0,     3,     5,     3,     1,     1,
       5,     6,     5,     6,     7,     7,     8,     5,     5,     1,
       1,     4,     4,     4,     4,     4,     4,     4,     1,     3,
       3,     1,     1,     1,     1,     1,     1,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     2,     2,     3,
       3,     3,     4,     3,     1,     1,     1,     2,     5
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
#line 109 "compiler.y"
      { create_symbol ( scope++ ); }
#line 1912 "y.tab.c"
    break;

  case 3: /* Program: $@1 GlobalStatementList  */
#line 110 "compiler.y"
    { dump_symbol(0); }
#line 1918 "y.tab.c"
    break;

  case 8: /* $@2: %empty  */
#line 124 "compiler.y"
                         {
        insert_symbol((yyvsp[-2].s_val), -1, 0);
    }
#line 1926 "y.tab.c"
    break;

  case 10: /* FuncHeader: FUNC ID  */
#line 130 "compiler.y"
              {
        (yyval.s_val) = (yyvsp[0].s_val);
        printf ( "func: %s\n", (yyval.s_val) );
    }
#line 1935 "y.tab.c"
    break;

  case 11: /* $@3: %empty  */
#line 138 "compiler.y"
      { create_symbol(scope); scope++; }
#line 1941 "y.tab.c"
    break;

  case 12: /* Block: '{' $@3 StatementList '}'  */
#line 141 "compiler.y"
      {
          int closed = --scope;
          dump_symbol(closed);
          pop_scope(closed);
      }
#line 1951 "y.tab.c"
    break;

  case 20: /* Statement: LET ID '=' Expression ';'  */
#line 166 "compiler.y"
        {
            insert_symbol((yyvsp[-3].s_val), addr_count, scope - 1);
            add_symbol((yyvsp[-3].s_val), addr_count, (yyvsp[-1].expr).type, yylineno, (yyvsp[-1].expr), 0);
            addr_count++;
        }
#line 1961 "y.tab.c"
    break;

  case 21: /* Statement: LET MUT ID '=' Expression ';'  */
#line 172 "compiler.y"
        {
            insert_symbol((yyvsp[-3].s_val), addr_count, scope - 1);
            add_symbol((yyvsp[-3].s_val), addr_count, (yyvsp[-1].expr).type, yylineno, (yyvsp[-1].expr), 1);
            addr_count++;
        }
#line 1971 "y.tab.c"
    break;

  case 22: /* Statement: LET ID ':' Type ';'  */
#line 178 "compiler.y"
        {
            insert_symbol((yyvsp[-3].s_val), addr_count, scope-1);
            ExprVal zero = { .type = strdup((yyvsp[-1].s_val)), .i_val = 0, .f_val = 0.0, .s_val = NULL };
            add_symbol((yyvsp[-3].s_val), addr_count, (yyvsp[-1].s_val), yylineno, zero, 0);
            addr_count++;
        }
#line 1982 "y.tab.c"
    break;

  case 23: /* Statement: LET MUT ID ':' Type ';'  */
#line 185 "compiler.y"
        {
            insert_symbol((yyvsp[-3].s_val), addr_count, scope-1);
            ExprVal zero = { .type = strdup((yyvsp[-1].s_val)), .i_val = 0, .f_val = 0.0, .s_val = NULL };
            add_symbol((yyvsp[-3].s_val), addr_count, (yyvsp[-1].s_val), yylineno, zero, 1);
            addr_count++;
        }
#line 1993 "y.tab.c"
    break;

  case 24: /* Statement: LET ID ':' Type '=' ArrayLiteral ';'  */
#line 192 "compiler.y"
        {
            insert_symbol((yyvsp[-5].s_val), addr_count, scope-1);
            add_symbol((yyvsp[-5].s_val), addr_count, "array", yylineno, (yyvsp[-1].expr), 0);
            addr_count++;
        }
#line 2003 "y.tab.c"
    break;

  case 25: /* Statement: LET ID ':' Type '=' Expression ';'  */
#line 198 "compiler.y"
        {
            insert_symbol((yyvsp[-5].s_val), addr_count, scope - 1);
            add_symbol((yyvsp[-5].s_val), addr_count, (yyvsp[-3].s_val), yylineno, (yyvsp[-1].expr), 0);
            addr_count++;
        }
#line 2013 "y.tab.c"
    break;

  case 26: /* Statement: LET MUT ID ':' Type '=' Expression ';'  */
#line 204 "compiler.y"
        {
            insert_symbol((yyvsp[-5].s_val), addr_count, scope - 1);
            add_symbol((yyvsp[-5].s_val), addr_count, (yyvsp[-3].s_val), yylineno, (yyvsp[-1].expr), 1);
            addr_count++;
        }
#line 2023 "y.tab.c"
    break;

  case 27: /* Statement: PRINTLN '(' Expression ')' ';'  */
#line 209 "compiler.y"
                                     {
        printf("PRINTLN %s\n", (yyvsp[-2].expr).type);
    }
#line 2031 "y.tab.c"
    break;

  case 28: /* Statement: PRINT '(' Expression ')' ';'  */
#line 212 "compiler.y"
                                   {
        printf("PRINT %s\n", (yyvsp[-2].expr).type);
    }
#line 2039 "y.tab.c"
    break;

  case 31: /* Statement: ID '=' Expression ';'  */
#line 219 "compiler.y"
        {
        int sym_i = lookup_symbol((yyvsp[-3].s_val));
        if (sym_i < 0) {
            /* undefined names get only an error, no ASSIGN line */
            printf("error:%d: undefined: %s\n", yylineno, (yyvsp[-3].s_val));
        } else {
            /* valid LHS → do the assignment */
            printf("ASSIGN\n");
            if (! symtab[sym_i].mut) {
                printf("error:%d: cannot borrow immutable borrowed content `%s` as mutable\n",
                    yylineno, (yyvsp[-3].s_val));
            }
        }
    }
#line 2058 "y.tab.c"
    break;

  case 32: /* Statement: ID LSHIFT Expression ';'  */
#line 235 "compiler.y"
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
#line 2081 "y.tab.c"
    break;

  case 33: /* Statement: ID ADD_ASSIGN Expression ';'  */
#line 255 "compiler.y"
        {
            printf("ADD_ASSIGN\n");
        }
#line 2089 "y.tab.c"
    break;

  case 34: /* Statement: ID SUB_ASSIGN Expression ';'  */
#line 260 "compiler.y"
        {
            printf("SUB_ASSIGN\n");
        }
#line 2097 "y.tab.c"
    break;

  case 35: /* Statement: ID MUL_ASSIGN Expression ';'  */
#line 265 "compiler.y"
        {
            printf("MUL_ASSIGN\n");
        }
#line 2105 "y.tab.c"
    break;

  case 36: /* Statement: ID DIV_ASSIGN Expression ';'  */
#line 270 "compiler.y"
        {
            printf("DIV_ASSIGN\n");
        }
#line 2113 "y.tab.c"
    break;

  case 37: /* Statement: ID REM_ASSIGN Expression ';'  */
#line 275 "compiler.y"
        {
            printf("REM_ASSIGN\n");
        }
#line 2121 "y.tab.c"
    break;

  case 38: /* ArrayElems: INT_LIT  */
#line 282 "compiler.y"
                             { printf("INT_LIT %d\n", (yyvsp[0].i_val)); }
#line 2127 "y.tab.c"
    break;

  case 39: /* ArrayElems: ArrayElems ',' INT_LIT  */
#line 283 "compiler.y"
                             { printf("INT_LIT %d\n", (yyvsp[0].i_val)); }
#line 2133 "y.tab.c"
    break;

  case 40: /* ArrayLiteral: '[' ArrayElems ']'  */
#line 288 "compiler.y"
        {
            (yyval.expr) = (ExprVal){ .type = strdup("array") };
        }
#line 2141 "y.tab.c"
    break;

  case 41: /* Expression: ID  */
#line 294 "compiler.y"
         {
        int addr = lookup_address((yyvsp[0].s_val));
        if (addr < 0) {
            printf("error:%d: undefined: %s\n", yylineno, (yyvsp[0].s_val));
            (yyval.expr) = (ExprVal){ .type = strdup("undefined") };
        } else {
            printf("IDENT (name=%s, address=%d)\n", (yyvsp[0].s_val), addr);
            (yyval.expr) = get_expr_val((yyvsp[0].s_val));
        }
    }
#line 2156 "y.tab.c"
    break;

  case 42: /* Expression: INT_LIT  */
#line 304 "compiler.y"
              {
        printf("INT_LIT %d\n", (yyvsp[0].i_val));
        (yyval.expr) = (ExprVal){ .type = strdup("i32"), .i_val = (yyvsp[0].i_val) };
    }
#line 2165 "y.tab.c"
    break;

  case 43: /* Expression: FLOAT_LIT  */
#line 308 "compiler.y"
                {
        printf("FLOAT_LIT %f\n", (yyvsp[0].f_val));
        (yyval.expr) = (ExprVal){ .type = strdup("f32"), .f_val = (yyvsp[0].f_val) };
    }
#line 2174 "y.tab.c"
    break;

  case 44: /* Expression: STRING_LIT  */
#line 312 "compiler.y"
                 {
        printf("STRING_LIT %s\n", (yyvsp[0].s_val));
        (yyval.expr) = (ExprVal){ .type = strdup("str"), .s_val = (yyvsp[0].s_val) };
    }
#line 2183 "y.tab.c"
    break;

  case 45: /* Expression: TRUE  */
#line 316 "compiler.y"
           {
        printf("bool TRUE\n");
        (yyval.expr) = (ExprVal){ .type = strdup("bool") };
    }
#line 2192 "y.tab.c"
    break;

  case 46: /* Expression: FALSE  */
#line 320 "compiler.y"
            {
        printf("bool FALSE\n");
        (yyval.expr) = (ExprVal){ .type = strdup("bool") };
    }
#line 2201 "y.tab.c"
    break;

  case 47: /* Expression: Expression AS Type  */
#line 325 "compiler.y"
    {
        if (strcmp((yyvsp[-2].expr).type, "f32") == 0 && strcmp((yyvsp[0].s_val), "i32") == 0) {
            printf("f2i\n");
            (yyval.expr).type = strdup("i32");
            (yyval.expr).i_val = (int)(yyvsp[-2].expr).f_val;
        }
        else if (strcmp((yyvsp[-2].expr).type, "i32") == 0 && strcmp((yyvsp[0].s_val), "f32") == 0) {
            printf("i2f\n");
            (yyval.expr).type = strdup("f32");
            (yyval.expr).f_val = (float)(yyvsp[-2].expr).i_val;
        }
    }
#line 2218 "y.tab.c"
    break;

  case 48: /* Expression: Expression '+' Expression  */
#line 337 "compiler.y"
                                {
        printf("ADD\n");
        (yyval.expr) = (ExprVal){ .type = strdup("i32") };
        if (strcmp((yyvsp[-2].expr).type, "f32") == 0 || strcmp((yyvsp[0].expr).type, "f32") == 0) {
            (yyval.expr).type = strdup("f32");
            (yyval.expr).f_val = (yyvsp[-2].expr).f_val + (yyvsp[0].expr).f_val;
        } else {
            (yyval.expr).i_val = (yyvsp[-2].expr).i_val + (yyvsp[0].expr).i_val;
        }
    }
#line 2233 "y.tab.c"
    break;

  case 49: /* Expression: Expression '-' Expression  */
#line 347 "compiler.y"
                                {
        printf("SUB\n");
        (yyval.expr) = (ExprVal){ .type = strdup("i32") };
        if (strcmp((yyvsp[-2].expr).type, "f32") == 0 || strcmp((yyvsp[0].expr).type, "f32") == 0) {
            (yyval.expr).type = strdup("f32");
            (yyval.expr).f_val = (yyvsp[-2].expr).f_val - (yyvsp[0].expr).f_val;
        } else {
            (yyval.expr).i_val = (yyvsp[-2].expr).i_val - (yyvsp[0].expr).i_val;
        }
    }
#line 2248 "y.tab.c"
    break;

  case 50: /* Expression: Expression '*' Expression  */
#line 357 "compiler.y"
                                {
        printf("MUL\n");
        (yyval.expr) = (ExprVal){ .type = strdup("i32") };
        if (strcmp((yyvsp[-2].expr).type, "f32") == 0 || strcmp((yyvsp[0].expr).type, "f32") == 0) {
            (yyval.expr).type = strdup("f32");
            (yyval.expr).f_val = (yyvsp[-2].expr).f_val * (yyvsp[0].expr).f_val;
        } else {
            (yyval.expr).i_val = (yyvsp[-2].expr).i_val * (yyvsp[0].expr).i_val;
        }
    }
#line 2263 "y.tab.c"
    break;

  case 51: /* Expression: Expression '/' Expression  */
#line 367 "compiler.y"
                                {
        printf("DIV\n");
        (yyval.expr) = (ExprVal){ .type = strdup("i32") };
        if (strcmp((yyvsp[-2].expr).type, "f32") == 0 || strcmp((yyvsp[0].expr).type, "f32") == 0) {
            (yyval.expr).type = strdup("f32");
            (yyval.expr).f_val = (yyvsp[-2].expr).f_val / (yyvsp[0].expr).f_val;
        } else {
            (yyval.expr).i_val = (yyvsp[-2].expr).i_val / (yyvsp[0].expr).i_val;
        }
    }
#line 2278 "y.tab.c"
    break;

  case 52: /* Expression: Expression '%' Expression  */
#line 377 "compiler.y"
                                {
        printf("REM\n");
        (yyval.expr) = (ExprVal){ .type = strdup("i32"), .i_val = (yyvsp[-2].expr).i_val % (yyvsp[0].expr).i_val };
    }
#line 2287 "y.tab.c"
    break;

  case 53: /* Expression: Expression '>' Expression  */
#line 381 "compiler.y"
                                {
        if (strcmp((yyvsp[-2].expr).type, (yyvsp[0].expr).type) != 0)
        {
            printf("error:%d: invalid operation: GTR (mismatched types %s and %s)\n",
                   yylineno, (yyvsp[-2].expr).type, (yyvsp[0].expr).type);
        }
        printf("GTR\n");
        (yyval.expr) = (ExprVal){ .type = strdup("bool") };
    }
#line 2301 "y.tab.c"
    break;

  case 54: /* Expression: Expression '<' Expression  */
#line 390 "compiler.y"
                                {
        if (strcmp((yyvsp[-2].expr).type, (yyvsp[0].expr).type) != 0)
        {
            printf("error:%d: invalid operation: LSS (mismatched types %s and %s)\n",
                   yylineno, (yyvsp[-2].expr).type, (yyvsp[0].expr).type);
        }
        printf("LSS\n");
        (yyval.expr) = (ExprVal){ .type = strdup("bool") };
    }
#line 2315 "y.tab.c"
    break;

  case 55: /* Expression: Expression LAND Expression  */
#line 399 "compiler.y"
                                 {
        printf("LAND\n");
        (yyval.expr) = (ExprVal){ .type = strdup("bool") };
    }
#line 2324 "y.tab.c"
    break;

  case 56: /* Expression: Expression LOR Expression  */
#line 403 "compiler.y"
                                {
        printf("LOR\n");
        (yyval.expr) = (ExprVal){ .type = strdup("bool") };
    }
#line 2333 "y.tab.c"
    break;

  case 57: /* Expression: '!' Expression  */
#line 407 "compiler.y"
                     {
        printf("NOT\n");
        (yyval.expr) = (ExprVal){ .type = strdup("bool") };
    }
#line 2342 "y.tab.c"
    break;

  case 58: /* Expression: '-' Expression  */
#line 411 "compiler.y"
                                  {
        printf("NEG\n");
        (yyval.expr) = (yyvsp[0].expr);
        if (strcmp((yyval.expr).type, "i32") == 0)
            (yyval.expr).i_val = -(yyval.expr).i_val;
        else if (strcmp((yyval.expr).type, "f32") == 0)
            (yyval.expr).f_val = -(yyval.expr).f_val;
    }
#line 2355 "y.tab.c"
    break;

  case 59: /* Expression: '(' Expression ')'  */
#line 419 "compiler.y"
                         {
        (yyval.expr) = (yyvsp[-1].expr);
    }
#line 2363 "y.tab.c"
    break;

  case 60: /* Expression: Expression EQL Expression  */
#line 423 "compiler.y"
        { printf("EQL\n");  (yyval.expr).type = strdup("bool"); }
#line 2369 "y.tab.c"
    break;

  case 61: /* Expression: Expression NEQ Expression  */
#line 426 "compiler.y"
        { printf("NEQ\n");  (yyval.expr).type = strdup("bool"); }
#line 2375 "y.tab.c"
    break;

  case 62: /* Expression: Expression '[' INT_LIT ']'  */
#line 429 "compiler.y"
    {
        printf("INT_LIT %d\n", (yyvsp[-1].i_val));
        (yyval.expr) = (ExprVal){ .type = strdup("array") };
    }
#line 2384 "y.tab.c"
    break;

  case 63: /* Expression: Expression LSHIFT Expression  */
#line 434 "compiler.y"
        {
            if (strcmp((yyvsp[-2].expr).type, "undefined") != 0 &&
                strcmp((yyvsp[0].expr).type, "undefined") != 0 &&
                strcmp((yyvsp[-2].expr).type, (yyvsp[0].expr).type) != 0)
            {
                printf("error:%d: invalid operation: LSHIFT (mismatched types %s and %s)\n",
                       yylineno, (yyvsp[-2].expr).type, (yyvsp[0].expr).type);
            }
            printf("LSHIFT\n");
            (yyval.expr) = (ExprVal){ .type = strdup((yyvsp[-2].expr).type) };
        }
#line 2400 "y.tab.c"
    break;

  case 64: /* Type: INT  */
#line 448 "compiler.y"
          { (yyval.s_val) = "i32"; }
#line 2406 "y.tab.c"
    break;

  case 65: /* Type: FLOAT  */
#line 449 "compiler.y"
            { (yyval.s_val) = "f32"; }
#line 2412 "y.tab.c"
    break;

  case 66: /* Type: BOOL  */
#line 450 "compiler.y"
           { (yyval.s_val) = "bool"; }
#line 2418 "y.tab.c"
    break;

  case 67: /* Type: '&' STR  */
#line 451 "compiler.y"
              { (yyval.s_val) = "str"; }
#line 2424 "y.tab.c"
    break;

  case 68: /* Type: '[' Type ';' INT_LIT ']'  */
#line 453 "compiler.y"
    {
        printf("INT_LIT %d\n", (yyvsp[-1].i_val));
        (yyval.s_val) = "array";
    }
#line 2433 "y.tab.c"
    break;


#line 2437 "y.tab.c"

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

#line 458 "compiler.y"


/* C code section */
int main(int argc, char *argv[])
{
    if (argc == 2) {
        yyin = fopen(argv[1], "r");
    } else {
        yyin = stdin;
    }

    yylineno = 1;
    yyparse();

	printf("Total lines: %d\n", yylineno-1);
    fclose(yyin);
    return 0;
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

static int lookup_address(const char *name) {
    for (int i = symtab_sz - 1; i >= 0; i--) {
        if (strcmp(symtab[i].name, name) == 0)
            return symtab[i].addr;
    }
    return -1;
}

static ExprVal get_expr_val(const char *name) {
    for (int i = symtab_sz - 1; i >= 0; i--) {
        if (strcmp(symtab[i].name, name) == 0) {
            ExprVal ev;
            ev.type = strdup(symtab[i].type);
            if (!strcmp(symtab[i].type, "i32"))
                ev.i_val = symtab[i].i_val;
            else if (!strcmp(symtab[i].type, "f32"))
                ev.f_val = symtab[i].f_val;
            else if (!strcmp(symtab[i].type, "str"))
                ev.s_val = symtab[i].s_val;
            return ev;
        }
    }
    ExprVal empty = {0};
    empty.type = strdup("undefined");   /* never NULL */
    return empty;
}

static int lookup_symbol(const char *name) {
    for (int i = symtab_sz - 1; i >= 0; --i)
        if (strcmp(symtab[i].name, name) == 0)
            return i;
    return -1;
}
