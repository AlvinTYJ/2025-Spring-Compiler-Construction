/* Please feel free to modify any content */

/* Definition section */
%{
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
%}

%define parse.error verbose
//%error-verbose

%left LSHIFT
%left LOR
%left LAND
%left '>' '<' GEQ LEQ EQL NEQ
%left '+' '-'
%left '*' '/' '%'
%right AS
%right '!' UMINUS

/* Use variable or self-defined structure to represent
 * nonterminal and token type
 *  - you can add new fields if needed.
 */
%union {
    int i_val;
    float f_val;
    char *s_val;
    ExprVal expr;
}

/* Token without return */
%token LET MUT NEWLINE
%token INT FLOAT BOOL STR
%token TRUE FALSE
%token GEQ LEQ EQL NEQ LOR LAND
%token ADD_ASSIGN SUB_ASSIGN MUL_ASSIGN DIV_ASSIGN REM_ASSIGN
%token IF ELSE FOR WHILE LOOP
%token PRINT PRINTLN
%token FUNC RETURN BREAK
%token ARROW AS IN DOTDOT RSHIFT LSHIFT

/* Token with return, which need to sepcify type */
%token <i_val> INT_LIT
%token <f_val> FLOAT_LIT
%token <s_val> STRING_LIT
%token <s_val> ID

/* Nonterminal with return, which need to sepcify type */
%type <s_val> Type
%type <s_val> FuncHeader
%type <expr> Expression
%type <expr> ArrayLiteral

/* Yacc will start at this nonterminal */
%start Program

/* Grammar section */
%%
Program
    : { create_symbol ( scope++ ); } GlobalStatementList
    { dump_symbol(0); }
;

GlobalStatementList 
    : GlobalStatementList GlobalStatement
    | GlobalStatement
;

GlobalStatement
    : FunctionDeclStmt
    | NEWLINE
;

FunctionDeclStmt
    : FuncHeader '(' ')' {
        insert_symbol($1, -1, 0);
    } Block
;

FuncHeader
    : FUNC ID {
        $$ = $<s_val>2;
        printf ( "func: %s\n", $$ );
    }
;

Block
    : '{'
      { create_symbol(scope); scope++; }
      StatementList
      '}'
      {
          int closed = --scope;
          dump_symbol(closed);
          pop_scope(closed);
      }
;

StatementList
    : StatementList Statement
    | /* empty */
;

IfStmt
    : IF Expression Block
    | IF Expression Block ELSE Block
    ;

WhileStmt
    : WHILE Expression Block
    ;

Statement
    : IfStmt
    | WhileStmt
    | LET ID '=' Expression ';'
        {
            insert_symbol($2, addr_count, scope - 1);
            add_symbol($2, addr_count, $4.type, yylineno, $4, 0);
            addr_count++;
        }
    | LET MUT ID '=' Expression ';'
        {
            insert_symbol($3, addr_count, scope - 1);
            add_symbol($3, addr_count, $5.type, yylineno, $5, 1);
            addr_count++;
        }
    | LET ID ':' Type ';'
        {
            insert_symbol($2, addr_count, scope-1);
            ExprVal zero = { .type = strdup($4), .i_val = 0, .f_val = 0.0, .s_val = NULL };
            add_symbol($2, addr_count, $4, yylineno, zero, 0);
            addr_count++;
        }
    | LET MUT ID ':' Type ';'
        {
            insert_symbol($3, addr_count, scope-1);
            ExprVal zero = { .type = strdup($5), .i_val = 0, .f_val = 0.0, .s_val = NULL };
            add_symbol($3, addr_count, $5, yylineno, zero, 1);
            addr_count++;
        }
    | LET ID ':' Type '=' ArrayLiteral ';'
        {
            insert_symbol($2, addr_count, scope-1);
            add_symbol($2, addr_count, "array", yylineno, $6, 0);
            addr_count++;
        }
    | LET ID ':' Type '=' Expression ';'
        {
            insert_symbol($2, addr_count, scope - 1);
            add_symbol($2, addr_count, $4, yylineno, $6, 0);
            addr_count++;
        }
    | LET MUT ID ':' Type '=' Expression ';'
        {
            insert_symbol($3, addr_count, scope - 1);
            add_symbol($3, addr_count, $5, yylineno, $7, 1);
            addr_count++;
        }
    | PRINTLN '(' Expression ')' ';' {
        printf("PRINTLN %s\n", $3.type);
    }
    | PRINT '(' Expression ')' ';' {
        printf("PRINT %s\n", $3.type);
    }
    | Block
    | NEWLINE

    | ID '=' Expression ';'
        {
        int sym_i = lookup_symbol($1);
        if (sym_i < 0) {
            /* undefined names get only an error, no ASSIGN line */
            printf("error:%d: undefined: %s\n", yylineno, $1);
        } else {
            /* valid LHS → do the assignment */
            printf("ASSIGN\n");
            if (! symtab[sym_i].mut) {
                printf("error:%d: cannot borrow immutable borrowed content `%s` as mutable\n",
                    yylineno, $1);
            }
        }
    }

    | ID LSHIFT Expression ';'
        {
            int sym_i = lookup_symbol($1);
            ExprVal rhs = $3;
            if (sym_i < 0) {
                printf("error:%d: undefined: %s\n", @1.first_line, $1);
            }
            else {
                ExprVal lhs = get_expr_val($1);
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

    | ID ADD_ASSIGN Expression ';'
        {
            printf("ADD_ASSIGN\n");
        }

    | ID SUB_ASSIGN Expression ';'
        {
            printf("SUB_ASSIGN\n");
        }

    | ID MUL_ASSIGN Expression ';'
        {
            printf("MUL_ASSIGN\n");
        }

    | ID DIV_ASSIGN Expression ';'
        {
            printf("DIV_ASSIGN\n");
        }

    | ID REM_ASSIGN Expression ';'
        {
            printf("REM_ASSIGN\n");
        }
  ;
;

ArrayElems
    : INT_LIT                { printf("INT_LIT %d\n", $1); }
    | ArrayElems ',' INT_LIT { printf("INT_LIT %d\n", $3); }
    ;

ArrayLiteral
    : '[' ArrayElems ']'
        {
            $$ = (ExprVal){ .type = strdup("array") };
        }
    ;

Expression
    : ID {
        int addr = lookup_address($1);
        if (addr < 0) {
            printf("error:%d: undefined: %s\n", yylineno, $1);
            $$ = (ExprVal){ .type = strdup("undefined") };
        } else {
            printf("IDENT (name=%s, address=%d)\n", $1, addr);
            $$ = get_expr_val($1);
        }
    }
    | INT_LIT {
        printf("INT_LIT %d\n", $1);
        $$ = (ExprVal){ .type = strdup("i32"), .i_val = $1 };
    }
    | FLOAT_LIT {
        printf("FLOAT_LIT %f\n", $1);
        $$ = (ExprVal){ .type = strdup("f32"), .f_val = $1 };
    }
    | STRING_LIT {
        printf("STRING_LIT %s\n", $1);
        $$ = (ExprVal){ .type = strdup("str"), .s_val = $1 };
    }
    | TRUE {
        printf("bool TRUE\n");
        $$ = (ExprVal){ .type = strdup("bool") };
    }
    | FALSE {
        printf("bool FALSE\n");
        $$ = (ExprVal){ .type = strdup("bool") };
    }
    | Expression AS Type
    {
        if (strcmp($1.type, "f32") == 0 && strcmp($3, "i32") == 0) {
            printf("f2i\n");
            $$.type = strdup("i32");
            $$.i_val = (int)$1.f_val;
        }
        else if (strcmp($1.type, "i32") == 0 && strcmp($3, "f32") == 0) {
            printf("i2f\n");
            $$.type = strdup("f32");
            $$.f_val = (float)$1.i_val;
        }
    }
    | Expression '+' Expression {
        printf("ADD\n");
        $$ = (ExprVal){ .type = strdup("i32") };
        if (strcmp($1.type, "f32") == 0 || strcmp($3.type, "f32") == 0) {
            $$.type = strdup("f32");
            $$.f_val = $1.f_val + $3.f_val;
        } else {
            $$.i_val = $1.i_val + $3.i_val;
        }
    }
    | Expression '-' Expression {
        printf("SUB\n");
        $$ = (ExprVal){ .type = strdup("i32") };
        if (strcmp($1.type, "f32") == 0 || strcmp($3.type, "f32") == 0) {
            $$.type = strdup("f32");
            $$.f_val = $1.f_val - $3.f_val;
        } else {
            $$.i_val = $1.i_val - $3.i_val;
        }
    }
    | Expression '*' Expression {
        printf("MUL\n");
        $$ = (ExprVal){ .type = strdup("i32") };
        if (strcmp($1.type, "f32") == 0 || strcmp($3.type, "f32") == 0) {
            $$.type = strdup("f32");
            $$.f_val = $1.f_val * $3.f_val;
        } else {
            $$.i_val = $1.i_val * $3.i_val;
        }
    }
    | Expression '/' Expression {
        printf("DIV\n");
        $$ = (ExprVal){ .type = strdup("i32") };
        if (strcmp($1.type, "f32") == 0 || strcmp($3.type, "f32") == 0) {
            $$.type = strdup("f32");
            $$.f_val = $1.f_val / $3.f_val;
        } else {
            $$.i_val = $1.i_val / $3.i_val;
        }
    }
    | Expression '%' Expression {
        printf("REM\n");
        $$ = (ExprVal){ .type = strdup("i32"), .i_val = $1.i_val % $3.i_val };
    }
    | Expression '>' Expression {
        if (strcmp($1.type, $3.type) != 0)
        {
            printf("error:%d: invalid operation: GTR (mismatched types %s and %s)\n",
                   yylineno, $1.type, $3.type);
        }
        printf("GTR\n");
        $$ = (ExprVal){ .type = strdup("bool") };
    }
    | Expression '<' Expression {
        if (strcmp($1.type, $3.type) != 0)
        {
            printf("error:%d: invalid operation: LSS (mismatched types %s and %s)\n",
                   yylineno, $1.type, $3.type);
        }
        printf("LSS\n");
        $$ = (ExprVal){ .type = strdup("bool") };
    }
    | Expression LAND Expression {
        printf("LAND\n");
        $$ = (ExprVal){ .type = strdup("bool") };
    }
    | Expression LOR Expression {
        printf("LOR\n");
        $$ = (ExprVal){ .type = strdup("bool") };
    }
    | '!' Expression {
        printf("NOT\n");
        $$ = (ExprVal){ .type = strdup("bool") };
    }
    | '-' Expression %prec UMINUS {
        printf("NEG\n");
        $$ = $2;
        if (strcmp($$.type, "i32") == 0)
            $$.i_val = -$$.i_val;
        else if (strcmp($$.type, "f32") == 0)
            $$.f_val = -$$.f_val;
    }
    | '(' Expression ')' {
        $$ = $2;
    }
    | Expression EQL Expression
        { printf("EQL\n");  $$.type = strdup("bool"); }

    | Expression NEQ Expression
        { printf("NEQ\n");  $$.type = strdup("bool"); }

    | Expression '[' INT_LIT ']'
    {
        printf("INT_LIT %d\n", $3);
        $$ = (ExprVal){ .type = strdup("array") };
    }
    | Expression LSHIFT Expression
        {
            if (strcmp($1.type, "undefined") != 0 &&
                strcmp($3.type, "undefined") != 0 &&
                strcmp($1.type, $3.type) != 0)
            {
                printf("error:%d: invalid operation: LSHIFT (mismatched types %s and %s)\n",
                       yylineno, $1.type, $3.type);
            }
            printf("LSHIFT\n");
            $$ = (ExprVal){ .type = strdup($1.type) };
        }
;

Type
    : INT { $$ = "i32"; }
    | FLOAT { $$ = "f32"; }
    | BOOL { $$ = "bool"; }
    | '&' STR { $$ = "str"; }
    | '[' Type ';' INT_LIT ']'
    {
        printf("INT_LIT %d\n", $4);
        $$ = "array";
    }
;
%%

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
