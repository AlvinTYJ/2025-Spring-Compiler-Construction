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
    int yylex();
    extern FILE *yyin;
    extern FILE *yyout;

    int yylex_destroy ();
    void yyerror (char const *s)
    {
        printf("error:%d: %s\n", yylineno, s);
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

#line 150 "compiler.tab.c"

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
    IF_NO_ELSE = 259,              /* IF_NO_ELSE  */
    LET = 260,                     /* LET  */
    MUT = 261,                     /* MUT  */
    NEWLINE = 262,                 /* NEWLINE  */
    INT = 263,                     /* INT  */
    FLOAT = 264,                   /* FLOAT  */
    BOOL = 265,                    /* BOOL  */
    STR = 266,                     /* STR  */
    TRUE = 267,                    /* TRUE  */
    FALSE = 268,                   /* FALSE  */
    GEQ = 269,                     /* GEQ  */
    LEQ = 270,                     /* LEQ  */
    EQL = 271,                     /* EQL  */
    NEQ = 272,                     /* NEQ  */
    LOR = 273,                     /* LOR  */
    LAND = 274,                    /* LAND  */
    ADD_ASSIGN = 275,              /* ADD_ASSIGN  */
    SUB_ASSIGN = 276,              /* SUB_ASSIGN  */
    MUL_ASSIGN = 277,              /* MUL_ASSIGN  */
    DIV_ASSIGN = 278,              /* DIV_ASSIGN  */
    REM_ASSIGN = 279,              /* REM_ASSIGN  */
    IF = 280,                      /* IF  */
    ELSE = 281,                    /* ELSE  */
    FOR = 282,                     /* FOR  */
    WHILE = 283,                   /* WHILE  */
    LOOP = 284,                    /* LOOP  */
    PRINT = 285,                   /* PRINT  */
    PRINTLN = 286,                 /* PRINTLN  */
    FUNC = 287,                    /* FUNC  */
    RETURN = 288,                  /* RETURN  */
    BREAK = 289,                   /* BREAK  */
    ARROW = 290,                   /* ARROW  */
    AS = 291,                      /* AS  */
    IN = 292,                      /* IN  */
    DOTDOT = 293,                  /* DOTDOT  */
    RSHIFT = 294,                  /* RSHIFT  */
    LSHIFT = 295,                  /* LSHIFT  */
    INT_LIT = 296,                 /* INT_LIT  */
    FLOAT_LIT = 297,               /* FLOAT_LIT  */
    STRING_LIT = 298,              /* STRING_LIT  */
    ID = 299                       /* ID  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 99 "compiler.y"

    int i_val;
    float f_val;
    char *s_val;
    ExprVal expr;
    int local_idx;

#line 249 "compiler.tab.c"

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
  YYSYMBOL_IF_NO_ELSE = 12,                /* IF_NO_ELSE  */
  YYSYMBOL_LET = 13,                       /* LET  */
  YYSYMBOL_MUT = 14,                       /* MUT  */
  YYSYMBOL_NEWLINE = 15,                   /* NEWLINE  */
  YYSYMBOL_INT = 16,                       /* INT  */
  YYSYMBOL_FLOAT = 17,                     /* FLOAT  */
  YYSYMBOL_BOOL = 18,                      /* BOOL  */
  YYSYMBOL_STR = 19,                       /* STR  */
  YYSYMBOL_TRUE = 20,                      /* TRUE  */
  YYSYMBOL_FALSE = 21,                     /* FALSE  */
  YYSYMBOL_GEQ = 22,                       /* GEQ  */
  YYSYMBOL_LEQ = 23,                       /* LEQ  */
  YYSYMBOL_EQL = 24,                       /* EQL  */
  YYSYMBOL_NEQ = 25,                       /* NEQ  */
  YYSYMBOL_LOR = 26,                       /* LOR  */
  YYSYMBOL_LAND = 27,                      /* LAND  */
  YYSYMBOL_ADD_ASSIGN = 28,                /* ADD_ASSIGN  */
  YYSYMBOL_SUB_ASSIGN = 29,                /* SUB_ASSIGN  */
  YYSYMBOL_MUL_ASSIGN = 30,                /* MUL_ASSIGN  */
  YYSYMBOL_DIV_ASSIGN = 31,                /* DIV_ASSIGN  */
  YYSYMBOL_REM_ASSIGN = 32,                /* REM_ASSIGN  */
  YYSYMBOL_IF = 33,                        /* IF  */
  YYSYMBOL_ELSE = 34,                      /* ELSE  */
  YYSYMBOL_FOR = 35,                       /* FOR  */
  YYSYMBOL_WHILE = 36,                     /* WHILE  */
  YYSYMBOL_LOOP = 37,                      /* LOOP  */
  YYSYMBOL_PRINT = 38,                     /* PRINT  */
  YYSYMBOL_PRINTLN = 39,                   /* PRINTLN  */
  YYSYMBOL_FUNC = 40,                      /* FUNC  */
  YYSYMBOL_RETURN = 41,                    /* RETURN  */
  YYSYMBOL_BREAK = 42,                     /* BREAK  */
  YYSYMBOL_ARROW = 43,                     /* ARROW  */
  YYSYMBOL_AS = 44,                        /* AS  */
  YYSYMBOL_IN = 45,                        /* IN  */
  YYSYMBOL_DOTDOT = 46,                    /* DOTDOT  */
  YYSYMBOL_RSHIFT = 47,                    /* RSHIFT  */
  YYSYMBOL_LSHIFT = 48,                    /* LSHIFT  */
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
  YYSYMBOL_IfStmt = 76,                    /* IfStmt  */
  YYSYMBOL_IfElseStmt = 77,                /* IfElseStmt  */
  YYSYMBOL_78_5 = 78,                      /* @5  */
  YYSYMBOL_79_6 = 79,                      /* @6  */
  YYSYMBOL_IfOnlyStmt = 80,                /* IfOnlyStmt  */
  YYSYMBOL_81_7 = 81,                      /* @7  */
  YYSYMBOL_WhileStmt = 82,                 /* WhileStmt  */
  YYSYMBOL_Statement = 83,                 /* Statement  */
  YYSYMBOL_84_8 = 84,                      /* $@8  */
  YYSYMBOL_85_9 = 85,                      /* $@9  */
  YYSYMBOL_ArrayElems = 86,                /* ArrayElems  */
  YYSYMBOL_ArrayLiteral = 87,              /* ArrayLiteral  */
  YYSYMBOL_Expression = 88,                /* Expression  */
  YYSYMBOL_Type = 89                       /* Type  */
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
#define YYLAST   660

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  64
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  26
/* YYNRULES -- Number of rules.  */
#define YYNRULES  76
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  156

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
       2,     2,     2,    10,     2,     2,     2,     9,    63,     2,
      53,    54,     7,     5,    60,     6,     2,     8,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    59,    58,
       4,    57,     3,     2,     2,     2,     2,     2,     2,     2,
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
       2,     2,     2,     2,     2,     2,     1,     2,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   137,   137,   137,   168,   169,   173,   174,   178,   178,
     184,   192,   198,   191,   210,   211,   215,   216,   221,   231,
     220,   244,   243,   257,   261,   262,   263,   269,   275,   282,
     289,   295,   337,   380,   380,   411,   411,   441,   442,   444,
     477,   497,   521,   545,   569,   601,   628,   629,   633,   640,
     679,   687,   695,   703,   731,   759,   787,   825,   847,   878,
     909,   930,   947,   964,   982,   985,  1001,  1017,  1027,  1036,
    1042,  1048,  1069,  1070,  1071,  1072,  1073
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
  "'-'", "'*'", "'/'", "'%'", "'!'", "UMINUS", "IF_NO_ELSE", "LET", "MUT",
  "NEWLINE", "INT", "FLOAT", "BOOL", "STR", "TRUE", "FALSE", "GEQ", "LEQ",
  "EQL", "NEQ", "LOR", "LAND", "ADD_ASSIGN", "SUB_ASSIGN", "MUL_ASSIGN",
  "DIV_ASSIGN", "REM_ASSIGN", "IF", "ELSE", "FOR", "WHILE", "LOOP",
  "PRINT", "PRINTLN", "FUNC", "RETURN", "BREAK", "ARROW", "AS", "IN",
  "DOTDOT", "RSHIFT", "LSHIFT", "INT_LIT", "FLOAT_LIT", "STRING_LIT", "ID",
  "'('", "')'", "'{'", "'}'", "'='", "';'", "':'", "','", "'['", "']'",
  "'&'", "$accept", "Program", "$@1", "GlobalStatementList",
  "GlobalStatement", "FunctionDeclStmt", "$@2", "FuncHeader", "Block",
  "$@3", "$@4", "StatementList", "IfStmt", "IfElseStmt", "@5", "@6",
  "IfOnlyStmt", "@7", "WhileStmt", "Statement", "$@8", "$@9", "ArrayElems",
  "ArrayLiteral", "Expression", "Type", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-72)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -72,    14,    -3,   -72,   -72,   -30,    -3,   -72,   -72,   -25,
     -72,   -72,   -14,   -72,     2,   -72,   -72,   -72,   262,   -13,
     -72,   162,   162,   -17,   -12,    49,   -72,    26,   -72,   -72,
     -72,   -72,   -72,   -10,   -52,   162,   162,   -72,   -72,   -72,
     -72,   -72,   -72,   162,   540,    59,   -72,   -72,   162,   162,
     162,   162,   162,   162,   162,   -72,   -51,   162,    -7,    27,
      27,    67,   162,   162,   162,   162,   162,   162,   162,   162,
     162,   162,   162,    -7,   162,    38,     2,     2,   -72,   162,
     162,   126,   133,   192,   199,   258,   265,   324,   162,    -7,
     331,   -72,   -72,   -72,    -7,    70,   -38,   -72,   448,   448,
     110,   110,   -40,   -40,   -40,   448,   448,   565,   599,   -72,
     553,    28,   -72,   -72,   390,   398,   -72,   -72,   -72,   -72,
     -72,   -72,   -72,   423,   -32,   -72,    37,   -72,   360,   -72,
     -72,    62,    40,    41,   -72,   162,   -72,    51,    52,    44,
     469,     2,   -72,   -72,   494,    42,   -72,   -47,   -72,   -72,
     -72,   -72,   -72,    56,   -72,   -72
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       2,     0,     0,     1,     7,     0,     3,     5,     6,     0,
      10,     4,     0,     8,     0,    11,     9,    15,    12,     0,
      38,     0,     0,     0,     0,     0,    37,     0,    24,    16,
      17,    25,    14,     0,     0,     0,     0,    69,    70,    50,
      51,    52,    49,     0,    18,     0,    35,    33,     0,     0,
       0,     0,     0,     0,     0,    13,     0,     0,     0,    63,
      62,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    23,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    72,    73,    74,     0,     0,     0,    64,    58,    59,
      53,    54,    55,    56,    57,    65,    66,    61,    60,    71,
      68,     0,    19,    22,     0,     0,    41,    42,    43,    44,
      45,    40,    39,     0,     0,    26,     0,    75,     0,    28,
      67,     0,     0,     0,    27,     0,    29,     0,     0,     0,
       0,     0,    36,    34,     0,     0,    46,     0,    30,    31,
      20,    32,    76,     0,    48,    47
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -72,   -72,   -72,   -72,   102,   -72,   -72,   -72,   -18,   -72,
     -72,   -72,   -72,   -72,   -72,   -72,   -72,   -72,   -72,   -72,
     -72,   -72,   -72,   -72,   -19,   -71
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     1,     2,     6,     7,     8,    14,     9,    16,    17,
      27,    18,    28,    29,    76,   131,    30,    77,    31,    32,
      80,    79,   147,   139,    44,    96
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      26,    33,   109,    45,    73,    57,    88,    58,    89,    91,
      92,    93,     4,   153,     3,   154,    59,    60,   124,   128,
     129,    75,    10,   126,    61,   135,   136,    78,    12,    81,
      82,    83,    84,    85,    86,    87,    46,     5,    90,    34,
      13,    47,    56,    98,    99,   100,   101,   102,   103,   104,
     105,   106,   107,   108,    94,   110,    95,    15,   112,   113,
     114,   115,    62,    63,    64,    65,    66,    67,    68,   123,
      62,    63,    64,    65,    66,    67,    68,    48,    49,    50,
      51,    52,    55,    69,    70,    71,    72,   111,    75,   127,
     130,    69,    70,    71,    72,   137,   141,    53,   142,   143,
     145,   146,   148,    73,   152,   155,    54,    74,    11,   140,
       0,    73,     0,     0,    15,    74,   144,    66,    67,    68,
      75,    97,     0,   150,     0,     0,     0,     0,    75,    62,
      63,    64,    65,    66,    67,    68,    62,    63,    64,    65,
      66,    67,    68,     0,     0,     0,     0,     0,     0,     0,
      69,    70,    71,    72,    73,     0,     0,    69,    70,    71,
      72,     0,     0,     0,     0,     0,     0,     0,    35,     0,
      73,    75,    36,     0,    74,     0,     0,    73,     0,     0,
       0,    74,    37,    38,   116,     0,     0,    75,     0,     0,
       0,   117,     0,     0,    75,    62,    63,    64,    65,    66,
      67,    68,    62,    63,    64,    65,    66,    67,    68,     0,
       0,    39,    40,    41,    42,    43,    69,    70,    71,    72,
       0,     0,     0,    69,    70,    71,    72,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    73,     0,     0,     0,
      74,     0,     0,    73,     0,     0,     0,    74,     0,     0,
     118,     0,     0,    75,     0,     0,     0,   119,     0,     0,
      75,    62,    63,    64,    65,    66,    67,    68,    62,    63,
      64,    65,    66,    67,    68,    19,     0,    20,     0,     0,
       0,     0,    69,    70,    71,    72,     0,     0,     0,    69,
      70,    71,    72,     0,     0,    21,     0,     0,    22,     0,
      23,    24,    73,     0,     0,     0,    74,     0,     0,    73,
       0,     0,     0,    74,    25,     0,   120,    15,     0,    75,
       0,     0,     0,   121,     0,     0,    75,    62,    63,    64,
      65,    66,    67,    68,    62,    63,    64,    65,    66,    67,
      68,     0,     0,     0,     0,     0,     0,     0,    69,    70,
      71,    72,     0,     0,     0,    69,    70,    71,    72,     0,
       0,     0,     0,     0,     0,     0,    35,     0,    73,     0,
      36,     0,    74,     0,     0,    73,     0,     0,     0,    74,
      37,    38,   122,     0,     0,    75,     0,     0,     0,   125,
       0,     0,    75,    62,    63,    64,    65,    66,    67,    68,
       0,    62,    63,    64,    65,    66,    67,    68,     0,    39,
      40,    41,    42,    43,    69,    70,    71,    72,     0,     0,
       0,   138,    69,    70,    71,    72,    62,    63,    64,    65,
      66,    67,    68,     0,    73,     0,     0,     0,    74,     0,
       0,     0,    73,     0,   132,     0,    74,    69,    70,    71,
      72,    75,   133,    64,    65,    66,    67,    68,     0,    75,
       0,     0,     0,     0,     0,     0,     0,    73,     0,     0,
       0,    74,    62,    63,    64,    65,    66,    67,    68,     0,
       0,   134,     0,     0,    75,     0,     0,     0,     0,     0,
       0,     0,    73,    69,    70,    71,    72,    62,    63,    64,
      65,    66,    67,    68,     0,     0,     0,     0,     0,    75,
       0,     0,     0,    73,     0,     0,     0,    74,    69,    70,
      71,    72,     0,     0,     0,     0,     0,   149,     0,     0,
      75,     0,     0,     0,     0,     0,     0,     0,    73,     0,
       0,     0,    74,    62,    63,    64,    65,    66,    67,    68,
       0,     0,   151,     0,     0,    75,    62,    63,    64,    65,
      66,    67,    68,     0,    69,    70,    71,    72,    62,    63,
      64,    65,    66,    67,    68,     0,     0,    69,    70,    71,
      72,     0,     0,     0,    73,     0,     0,     0,    74,    69,
      70,     0,    72,     0,     0,     0,     0,    73,     0,     0,
       0,    75,    62,    63,    64,    65,    66,    67,    68,    73,
       0,     0,     0,     0,    75,     0,     0,     0,     0,     0,
       0,     0,     0,    69,    70,     0,    75,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    73,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      75
};

static const yytype_int16 yycheck[] =
{
      18,    14,    73,    22,    44,    57,    57,    59,    59,    16,
      17,    18,    15,    60,     0,    62,    35,    36,    89,    57,
      58,    61,    52,    94,    43,    57,    58,    45,    53,    48,
      49,    50,    51,    52,    53,    54,    53,    40,    57,    52,
      54,    53,    52,    62,    63,    64,    65,    66,    67,    68,
      69,    70,    71,    72,    61,    74,    63,    55,    76,    77,
      79,    80,     3,     4,     5,     6,     7,     8,     9,    88,
       3,     4,     5,     6,     7,     8,     9,    28,    29,    30,
      31,    32,    56,    24,    25,    26,    27,    49,    61,    19,
      62,    24,    25,    26,    27,    58,    34,    48,    58,    58,
      49,    49,    58,    44,    62,    49,    57,    48,     6,   128,
      -1,    44,    -1,    -1,    55,    48,   135,     7,     8,     9,
      61,    54,    -1,   141,    -1,    -1,    -1,    -1,    61,     3,
       4,     5,     6,     7,     8,     9,     3,     4,     5,     6,
       7,     8,     9,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      24,    25,    26,    27,    44,    -1,    -1,    24,    25,    26,
      27,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     6,    -1,
      44,    61,    10,    -1,    48,    -1,    -1,    44,    -1,    -1,
      -1,    48,    20,    21,    58,    -1,    -1,    61,    -1,    -1,
      -1,    58,    -1,    -1,    61,     3,     4,     5,     6,     7,
       8,     9,     3,     4,     5,     6,     7,     8,     9,    -1,
      -1,    49,    50,    51,    52,    53,    24,    25,    26,    27,
      -1,    -1,    -1,    24,    25,    26,    27,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    44,    -1,    -1,    -1,
      48,    -1,    -1,    44,    -1,    -1,    -1,    48,    -1,    -1,
      58,    -1,    -1,    61,    -1,    -1,    -1,    58,    -1,    -1,
      61,     3,     4,     5,     6,     7,     8,     9,     3,     4,
       5,     6,     7,     8,     9,    13,    -1,    15,    -1,    -1,
      -1,    -1,    24,    25,    26,    27,    -1,    -1,    -1,    24,
      25,    26,    27,    -1,    -1,    33,    -1,    -1,    36,    -1,
      38,    39,    44,    -1,    -1,    -1,    48,    -1,    -1,    44,
      -1,    -1,    -1,    48,    52,    -1,    58,    55,    -1,    61,
      -1,    -1,    -1,    58,    -1,    -1,    61,     3,     4,     5,
       6,     7,     8,     9,     3,     4,     5,     6,     7,     8,
       9,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    24,    25,
      26,    27,    -1,    -1,    -1,    24,    25,    26,    27,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,     6,    -1,    44,    -1,
      10,    -1,    48,    -1,    -1,    44,    -1,    -1,    -1,    48,
      20,    21,    58,    -1,    -1,    61,    -1,    -1,    -1,    58,
      -1,    -1,    61,     3,     4,     5,     6,     7,     8,     9,
      -1,     3,     4,     5,     6,     7,     8,     9,    -1,    49,
      50,    51,    52,    53,    24,    25,    26,    27,    -1,    -1,
      -1,    61,    24,    25,    26,    27,     3,     4,     5,     6,
       7,     8,     9,    -1,    44,    -1,    -1,    -1,    48,    -1,
      -1,    -1,    44,    -1,    54,    -1,    48,    24,    25,    26,
      27,    61,    54,     5,     6,     7,     8,     9,    -1,    61,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    44,    -1,    -1,
      -1,    48,     3,     4,     5,     6,     7,     8,     9,    -1,
      -1,    58,    -1,    -1,    61,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    44,    24,    25,    26,    27,     3,     4,     5,
       6,     7,     8,     9,    -1,    -1,    -1,    -1,    -1,    61,
      -1,    -1,    -1,    44,    -1,    -1,    -1,    48,    24,    25,
      26,    27,    -1,    -1,    -1,    -1,    -1,    58,    -1,    -1,
      61,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    44,    -1,
      -1,    -1,    48,     3,     4,     5,     6,     7,     8,     9,
      -1,    -1,    58,    -1,    -1,    61,     3,     4,     5,     6,
       7,     8,     9,    -1,    24,    25,    26,    27,     3,     4,
       5,     6,     7,     8,     9,    -1,    -1,    24,    25,    26,
      27,    -1,    -1,    -1,    44,    -1,    -1,    -1,    48,    24,
      25,    -1,    27,    -1,    -1,    -1,    -1,    44,    -1,    -1,
      -1,    61,     3,     4,     5,     6,     7,     8,     9,    44,
      -1,    -1,    -1,    -1,    61,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    24,    25,    -1,    61,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    44,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      61
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    65,    66,     0,    15,    40,    67,    68,    69,    71,
      52,    68,    53,    54,    70,    55,    72,    73,    75,    13,
      15,    33,    36,    38,    39,    52,    72,    74,    76,    77,
      80,    82,    83,    14,    52,     6,    10,    20,    21,    49,
      50,    51,    52,    53,    88,    88,    53,    53,    28,    29,
      30,    31,    32,    48,    57,    56,    52,    57,    59,    88,
      88,    88,     3,     4,     5,     6,     7,     8,     9,    24,
      25,    26,    27,    44,    48,    61,    78,    81,    72,    85,
      84,    88,    88,    88,    88,    88,    88,    88,    57,    59,
      88,    16,    17,    18,    61,    63,    89,    54,    88,    88,
      88,    88,    88,    88,    88,    88,    88,    88,    88,    89,
      88,    49,    72,    72,    88,    88,    58,    58,    58,    58,
      58,    58,    58,    88,    89,    58,    89,    19,    57,    58,
      62,    79,    54,    54,    58,    57,    58,    58,    61,    87,
      88,    34,    58,    58,    88,    49,    49,    86,    58,    58,
      72,    58,    62,    60,    62,    49
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    64,    66,    65,    67,    67,    68,    68,    70,    69,
      71,    73,    74,    72,    75,    75,    76,    76,    78,    79,
      77,    81,    80,    82,    83,    83,    83,    83,    83,    83,
      83,    83,    83,    84,    83,    85,    83,    83,    83,    83,
      83,    83,    83,    83,    83,    83,    86,    86,    87,    88,
      88,    88,    88,    88,    88,    88,    88,    88,    88,    88,
      88,    88,    88,    88,    88,    88,    88,    88,    88,    88,
      88,    88,    89,    89,    89,    89,    89
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     0,     2,     2,     1,     1,     1,     0,     5,
       2,     0,     0,     5,     2,     0,     1,     1,     0,     0,
       7,     0,     4,     3,     1,     1,     5,     6,     5,     6,
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
#line 137 "compiler.y"
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
#line 1941 "compiler.tab.c"
    break;

  case 3: /* Program: $@1 GlobalStatementList  */
#line 159 "compiler.y"
    { 
        /* This is the end of the main method */
        CODEGEN("return");
        CODEGEN(".end method");
        dump_symbol(0); 
    }
#line 1952 "compiler.tab.c"
    break;

  case 8: /* $@2: %empty  */
#line 178 "compiler.y"
                         {
        insert_symbol((yyvsp[-2].s_val), -1, 0);
    }
#line 1960 "compiler.tab.c"
    break;

  case 10: /* FuncHeader: FUNC ID  */
#line 184 "compiler.y"
              {
        (yyval.s_val) = (yyvsp[0].s_val);
        printf ( "func: %s\n", (yyval.s_val) );
    }
#line 1969 "compiler.tab.c"
    break;

  case 11: /* $@3: %empty  */
#line 192 "compiler.y"
      {
          printf(">>> ENTERING BLOCK (scope level %d)\n", scope);
          create_symbol(scope);
          scope++;
      }
#line 1979 "compiler.tab.c"
    break;

  case 12: /* $@4: %empty  */
#line 198 "compiler.y"
      {
          int closed = --scope;
          printf("<<< EXITING BLOCK (scope level %d)\n", closed);
          dump_symbol(closed);
          pop_scope(closed);
          printf("--- AFTER POP (remaining symbols):\n");
          dump_all_symbols();
      }
#line 1992 "compiler.tab.c"
    break;

  case 18: /* @5: %empty  */
#line 221 "compiler.y"
      {
          int elseLabel = label_count++;
          int endLabel  = label_count++;
          (yyval.i_val)      = elseLabel;
          (yyval.local_idx)  = endLabel;

          CODEGEN("iload %d", (yyvsp[0].expr).local_idx);
          CODEGEN("ifeq Lelse%d", elseLabel);
      }
#line 2006 "compiler.tab.c"
    break;

  case 19: /* @6: %empty  */
#line 231 "compiler.y"
      {
          CODEGEN("goto Lend%d", (yyvsp[0].local_idx));
          CODEGEN("Lelse%d:", (yyvsp[-1].i_val));
      }
#line 2015 "compiler.tab.c"
    break;

  case 20: /* IfElseStmt: IF Expression @5 Block @6 ELSE Block  */
#line 237 "compiler.y"
      {
          CODEGEN("Lend%d:", (yyvsp[-2].local_idx));
      }
#line 2023 "compiler.tab.c"
    break;

  case 21: /* @7: %empty  */
#line 244 "compiler.y"
      {
          int endLabel = label_count++;
          CODEGEN("iload %d", (yyvsp[0].expr).local_idx);
          CODEGEN("ifeq Lend%d", endLabel);
          (yyval.i_val) = endLabel;
      }
#line 2034 "compiler.tab.c"
    break;

  case 22: /* IfOnlyStmt: IF Expression @7 Block  */
#line 251 "compiler.y"
      {
          CODEGEN("Lend%d:", (yyvsp[-1].i_val));
      }
#line 2042 "compiler.tab.c"
    break;

  case 26: /* Statement: LET ID '=' Expression ';'  */
#line 264 "compiler.y"
        {
            int loc = (yyvsp[-1].expr).local_idx;
            insert_symbol((yyvsp[-3].s_val), loc, scope - 1);
            add_symbol ((yyvsp[-3].s_val), loc, (yyvsp[-1].expr).type, yylineno, (yyvsp[-1].expr), /*mut=*/0);
        }
#line 2052 "compiler.tab.c"
    break;

  case 27: /* Statement: LET MUT ID '=' Expression ';'  */
#line 270 "compiler.y"
        {
            int loc = (yyvsp[-1].expr).local_idx;
            insert_symbol((yyvsp[-3].s_val), loc, scope - 1);
            add_symbol ((yyvsp[-3].s_val), loc, (yyvsp[-1].expr).type, yylineno, (yyvsp[-1].expr), /*mut=*/1);
        }
#line 2062 "compiler.tab.c"
    break;

  case 28: /* Statement: LET ID ':' Type ';'  */
#line 276 "compiler.y"
        {
            insert_symbol((yyvsp[-3].s_val), addr_count, scope-1);
            ExprVal zero = { .type = strdup((yyvsp[-1].s_val)), .i_val = 0, .f_val = 0.0, .s_val = NULL };
            add_symbol((yyvsp[-3].s_val), addr_count, (yyvsp[-1].s_val), yylineno, zero, 0);
            addr_count++;
        }
#line 2073 "compiler.tab.c"
    break;

  case 29: /* Statement: LET MUT ID ':' Type ';'  */
#line 283 "compiler.y"
        {
            insert_symbol((yyvsp[-3].s_val), addr_count, scope-1);
            ExprVal zero = { .type = strdup((yyvsp[-1].s_val)), .i_val = 0, .f_val = 0.0, .s_val = NULL };
            add_symbol((yyvsp[-3].s_val), addr_count, (yyvsp[-1].s_val), yylineno, zero, 1);
            addr_count++;
        }
#line 2084 "compiler.tab.c"
    break;

  case 30: /* Statement: LET ID ':' Type '=' ArrayLiteral ';'  */
#line 290 "compiler.y"
        {
            insert_symbol((yyvsp[-5].s_val), addr_count, scope-1);
            add_symbol((yyvsp[-5].s_val), addr_count, "array", yylineno, (yyvsp[-1].expr), 0);
            addr_count++;
        }
#line 2094 "compiler.tab.c"
    break;

  case 31: /* Statement: LET ID ':' Type '=' Expression ';'  */
#line 296 "compiler.y"
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
#line 2140 "compiler.tab.c"
    break;

  case 32: /* Statement: LET MUT ID ':' Type '=' Expression ';'  */
#line 338 "compiler.y"
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
#line 2187 "compiler.tab.c"
    break;

  case 33: /* $@8: %empty  */
#line 380 "compiler.y"
                  {
        CODEGEN("getstatic java/lang/System/out Ljava/io/PrintStream;");
    }
#line 2195 "compiler.tab.c"
    break;

  case 34: /* Statement: PRINTLN '(' $@8 Expression ')' ';'  */
#line 383 "compiler.y"
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
#line 2228 "compiler.tab.c"
    break;

  case 35: /* $@9: %empty  */
#line 411 "compiler.y"
                {
    CODEGEN("getstatic java/lang/System/out Ljava/io/PrintStream;");
    }
#line 2236 "compiler.tab.c"
    break;

  case 36: /* Statement: PRINT '(' $@9 Expression ')' ';'  */
#line 414 "compiler.y"
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
#line 2268 "compiler.tab.c"
    break;

  case 39: /* Statement: ID '=' Expression ';'  */
#line 445 "compiler.y"
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
#line 2304 "compiler.tab.c"
    break;

  case 40: /* Statement: ID LSHIFT Expression ';'  */
#line 478 "compiler.y"
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
#line 2327 "compiler.tab.c"
    break;

  case 41: /* Statement: ID ADD_ASSIGN Expression ';'  */
#line 497 "compiler.y"
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
#line 2355 "compiler.tab.c"
    break;

  case 42: /* Statement: ID SUB_ASSIGN Expression ';'  */
#line 521 "compiler.y"
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
#line 2383 "compiler.tab.c"
    break;

  case 43: /* Statement: ID MUL_ASSIGN Expression ';'  */
#line 545 "compiler.y"
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
#line 2411 "compiler.tab.c"
    break;

  case 44: /* Statement: ID DIV_ASSIGN Expression ';'  */
#line 569 "compiler.y"
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
#line 2447 "compiler.tab.c"
    break;

  case 45: /* Statement: ID REM_ASSIGN Expression ';'  */
#line 601 "compiler.y"
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
#line 2476 "compiler.tab.c"
    break;

  case 46: /* ArrayElems: INT_LIT  */
#line 628 "compiler.y"
                             { printf("INT_LIT %d\n", (yyvsp[0].i_val)); }
#line 2482 "compiler.tab.c"
    break;

  case 47: /* ArrayElems: ArrayElems ',' INT_LIT  */
#line 629 "compiler.y"
                             { printf("INT_LIT %d\n", (yyvsp[0].i_val)); }
#line 2488 "compiler.tab.c"
    break;

  case 48: /* ArrayLiteral: '[' ArrayElems ']'  */
#line 634 "compiler.y"
        {
            (yyval.expr) = (ExprVal){ .type = strdup("array") };
        }
#line 2496 "compiler.tab.c"
    break;

  case 49: /* Expression: ID  */
#line 641 "compiler.y"
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
#line 2539 "compiler.tab.c"
    break;

  case 50: /* Expression: INT_LIT  */
#line 679 "compiler.y"
              {
        int idx = alloc_local_i32();
        CODEGEN("ldc %d", (yyvsp[0].i_val));
        CODEGEN("istore %d", idx);
        (yyval.expr).type = strdup("i32");
        (yyval.expr).i_val = (yyvsp[0].i_val);
        (yyval.expr).local_idx = idx;
    }
#line 2552 "compiler.tab.c"
    break;

  case 51: /* Expression: FLOAT_LIT  */
#line 687 "compiler.y"
                {
        int idx = alloc_local_f32();
        CODEGEN("ldc %f", (yyvsp[0].f_val));
        CODEGEN("fstore %d", idx);
        (yyval.expr).type = strdup("f32");
        (yyval.expr).f_val = (yyvsp[0].f_val);
        (yyval.expr).local_idx = idx;
    }
#line 2565 "compiler.tab.c"
    break;

  case 52: /* Expression: STRING_LIT  */
#line 695 "compiler.y"
                 {
        int idx = alloc_local_ref();
        CODEGEN("ldc %s", (yyvsp[0].s_val));
        CODEGEN("astore %d", idx);
        (yyval.expr).type = strdup("str");
        (yyval.expr).s_val = strdup((yyvsp[0].s_val));
        (yyval.expr).local_idx = idx;
    }
#line 2578 "compiler.tab.c"
    break;

  case 53: /* Expression: Expression '+' Expression  */
#line 703 "compiler.y"
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
#line 2611 "compiler.tab.c"
    break;

  case 54: /* Expression: Expression '-' Expression  */
#line 731 "compiler.y"
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
#line 2644 "compiler.tab.c"
    break;

  case 55: /* Expression: Expression '*' Expression  */
#line 759 "compiler.y"
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
#line 2677 "compiler.tab.c"
    break;

  case 56: /* Expression: Expression '/' Expression  */
#line 787 "compiler.y"
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
#line 2720 "compiler.tab.c"
    break;

  case 57: /* Expression: Expression '%' Expression  */
#line 825 "compiler.y"
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
#line 2747 "compiler.tab.c"
    break;

  case 58: /* Expression: Expression '>' Expression  */
#line 847 "compiler.y"
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
#line 2782 "compiler.tab.c"
    break;

  case 59: /* Expression: Expression '<' Expression  */
#line 879 "compiler.y"
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
#line 2816 "compiler.tab.c"
    break;

  case 60: /* Expression: Expression LAND Expression  */
#line 909 "compiler.y"
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
#line 2842 "compiler.tab.c"
    break;

  case 61: /* Expression: Expression LOR Expression  */
#line 930 "compiler.y"
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
#line 2864 "compiler.tab.c"
    break;

  case 62: /* Expression: '!' Expression  */
#line 947 "compiler.y"
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
#line 2886 "compiler.tab.c"
    break;

  case 63: /* Expression: '-' Expression  */
#line 964 "compiler.y"
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
#line 2909 "compiler.tab.c"
    break;

  case 64: /* Expression: '(' Expression ')'  */
#line 982 "compiler.y"
                         {
        (yyval.expr) = (yyvsp[-1].expr);
    }
#line 2917 "compiler.tab.c"
    break;

  case 65: /* Expression: Expression EQL Expression  */
#line 985 "compiler.y"
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
#line 2938 "compiler.tab.c"
    break;

  case 66: /* Expression: Expression NEQ Expression  */
#line 1001 "compiler.y"
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
#line 2959 "compiler.tab.c"
    break;

  case 67: /* Expression: Expression '[' INT_LIT ']'  */
#line 1017 "compiler.y"
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
#line 2974 "compiler.tab.c"
    break;

  case 68: /* Expression: Expression LSHIFT Expression  */
#line 1027 "compiler.y"
                                   {
        if (strcmp((yyvsp[-2].expr).type, "undefined") != 0 && strcmp((yyvsp[0].expr).type, "undefined") != 0 && strcmp((yyvsp[-2].expr).type, (yyvsp[0].expr).type) != 0) {
            printf("error:%d: invalid operation: LSHIFT (mismatched types)\n", yylineno);
            (yyval.expr) = (ExprVal){ .type = "undefined" };
        } else {
            CODEGEN("ishl");
            (yyval.expr) = (ExprVal){ .type = (yyvsp[-2].expr).type };
        }
    }
#line 2988 "compiler.tab.c"
    break;

  case 69: /* Expression: TRUE  */
#line 1036 "compiler.y"
           {
        int idx = alloc_local_i32();
        CODEGEN("iconst_1");
        CODEGEN("istore %d", idx);
        (yyval.expr) = (ExprVal){ .type = "bool", .local_idx = idx, .i_val = 1 };
    }
#line 2999 "compiler.tab.c"
    break;

  case 70: /* Expression: FALSE  */
#line 1042 "compiler.y"
            {
        int idx = alloc_local_i32();
        CODEGEN("iconst_0");
        CODEGEN("istore %d", idx);
        (yyval.expr) = (ExprVal){ .type = "bool", .local_idx = idx, .i_val = 0 };
    }
#line 3010 "compiler.tab.c"
    break;

  case 71: /* Expression: Expression AS Type  */
#line 1048 "compiler.y"
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
#line 3033 "compiler.tab.c"
    break;

  case 72: /* Type: INT  */
#line 1069 "compiler.y"
            { (yyval.s_val) = "i32"; }
#line 3039 "compiler.tab.c"
    break;

  case 73: /* Type: FLOAT  */
#line 1070 "compiler.y"
            { (yyval.s_val) = "f32"; }
#line 3045 "compiler.tab.c"
    break;

  case 74: /* Type: BOOL  */
#line 1071 "compiler.y"
            { (yyval.s_val) = "bool"; }
#line 3051 "compiler.tab.c"
    break;

  case 75: /* Type: '&' STR  */
#line 1072 "compiler.y"
              { (yyval.s_val) = "str"; }
#line 3057 "compiler.tab.c"
    break;

  case 76: /* Type: '[' Type ';' INT_LIT ']'  */
#line 1073 "compiler.y"
                               { (yyval.s_val) = "array"; }
#line 3063 "compiler.tab.c"
    break;


#line 3067 "compiler.tab.c"

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

#line 1075 "compiler.y"


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
