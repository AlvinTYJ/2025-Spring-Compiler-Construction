/* Definition section */
%{
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
%nonassoc ELSE

/* Use variable or self-defined structure to represent
 * nonterminal and token type
 *  - you can add new fields if needed.
 */
%union {
    int i_val;
    float f_val;
    char *s_val;
    ExprVal expr;
    int local_idx;
}

/* Token without return */
%token LET MUT NEWLINE
%token INT FLOAT BOOL STR
%token TRUE FALSE
%token ADD_ASSIGN SUB_ASSIGN MUL_ASSIGN DIV_ASSIGN REM_ASSIGN
%token IF FOR WHILE LOOP
%token PRINT PRINTLN
%token FUNC RETURN BREAK
%token ARROW IN DOTDOT RSHIFT

/* Token with return, which need to sepcify type */
%token <i_val> INT_LIT
%token <f_val> FLOAT_LIT
%token <s_val> STRING_LIT
%token <s_val> ID

/* Nonterminal with return, which need to sepcify type */
%type <s_val>  Type
%type <s_val>  FuncHeader
%type <expr>   Expression
%type <expr>   ArrayLiteral
%type <local_idx> Condition
%type <i_val> IfExitLabel IfElseLabels
%type <i_val> IfStmt
%type IfOnlyStmt IfElseStmt

/* Yacc will start at this nonterminal */
%start Program

/* Grammar section */
%%
Program
    : {
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
      GlobalStatementList
    { 
        /* This is the end of the main method */
        CODEGEN("return");
        CODEGEN(".end method");
        dump_symbol(0); 
    }
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
      {
          printf(">>> ENTERING BLOCK (scope level %d)\n", scope);
          create_symbol(scope);
          scope++;
      }
      StatementList
      {
          int closed = --scope;
          printf("<<< EXITING BLOCK (scope level %d)\n", closed);
          dump_symbol(closed);
          pop_scope(closed);
          printf("--- AFTER POP (remaining symbols):\n");
          dump_all_symbols();
      }
      '}'
;

StatementList
    : StatementList Statement
    | /* empty */
;

Condition
    : Expression
      {
          /* semantic-check */
          if (strcmp($1.type, "bool") != 0) {
              printf("error:%d: non-bool (type %s) used as for condition\n",
                     yylineno + 1, $1.type);
          }
          /* pass the slot number up so IfStmt knows where to iload */
          $$ = $1.local_idx;
      }
;

StmtBlock
    : '{'
      {
          printf(">>> ENTERING BLOCK (scope level %d)\n", scope);
          create_symbol(scope);
          scope++;
      }
      StatementList
      '}'
      {
          int closed = --scope;
          printf("<<< EXITING BLOCK (scope level %d)\n", closed);
          dump_symbol(closed);
          pop_scope(closed);
      }
;

IfStmt
    : IF Condition IfExitLabel
      {
        printf("[parser] matched IfOnlyStmt (maybe else follows later)\n");
        CODEGEN("iload %d", $2);
        CODEGEN("ifeq Else_%d", $3);  // rename Exit_ → Else_ for consistency
      }
      StmtBlock
      {
        $$ = $3;  // Pass up the label for ELSE to use
      }
;

OptNewline
    : NEWLINE { printf("[parser] consumed optional NEWLINE\n"); }
    | /* empty */
;

IfExitLabel
    : /* empty */ { $$ = label_counter++; }
;

IfElseLabels
    : /* empty */ {
        int else_lbl = label_counter++;
        int exit_lbl = label_counter++;
        $$ = (else_lbl << 16) | exit_lbl;  // pack into one int
    }
;

WhileStmt
    : WHILE {
        should_emit_label = true;
        CODEGEN("For_%d:\n", for_counter);
    } Condition {
        should_emit_label = false;
        CODEGEN("Label_%d:\n", label_counter);
        inside_while_stmt = true;
    } StmtBlock {
        CODEGEN("\tiinc 0 1\n");
        CODEGEN("\tgoto For_%d\n", for_counter++);
        CODEGEN("Exit_%d:\n", label_counter++);
        inside_while_stmt = false;
    }
;

Statement
    : IfStmt
    | IfStmt OptNewline ELSE {
        // prepare the else label
        int else_lbl = $1;
        int exit_lbl = label_counter++;
        CODEGEN("goto Exit_%d", exit_lbl);  // jump over else
        CODEGEN("Else_%d:", else_lbl);      // emit else label before else block
        $$ = exit_lbl;                      // pass up for Exit label
    } StmtBlock {
        // Now end the if-else
        CODEGEN("Exit_%d:", $<i_val>4);     // use exit_lbl saved earlier
    }
    | WhileStmt
    | LET ID '=' Expression ';'
        {
            int loc = $4.local_idx;
            insert_symbol($2, loc, scope - 1);
            add_symbol ($2, loc, $4.type, yylineno, $4, /*mut=*/0);
        }
    | LET MUT ID '=' Expression ';'
        {
            int loc = $5.local_idx;
            insert_symbol($3, loc, scope - 1);
            add_symbol ($3, loc, $5.type, yylineno, $5, /*mut=*/1);
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
            int loc;

            if (strcmp($4, "i32") == 0) {
                loc = alloc_local_i32();
                CODEGEN("iload %d", $6.local_idx);
                CODEGEN("istore %d", loc);
            } else if (strcmp($4, "f32") == 0) {
                loc = alloc_local_f32();
                CODEGEN("fload %d", $6.local_idx);
                CODEGEN("fstore %d", loc);
            } else if (strcmp($4, "str") == 0) {
                loc = alloc_local_ref();
                CODEGEN("aload %d", $6.local_idx);
                CODEGEN("astore %d", loc);
            } else if (strcmp($4, "bool") == 0) {
                loc = alloc_local_i32();
                CODEGEN("iload %d", $6.local_idx);
                CODEGEN("istore %d", loc);
            } else {
                printf("error:%d: unsupported let-binding type: %s\n", yylineno, $4);
                loc = -1;
            }

            ExprVal new_val = {
                .type = strdup($4),
                .local_idx = loc
            };
            if (strcmp($4, "i32") == 0) {
                new_val.i_val = $6.i_val;
            } else if (strcmp($4, "f32") == 0) {
                new_val.f_val = $6.f_val;
            } else if (strcmp($4, "str") == 0) {
                new_val.s_val = $6.s_val;
            } else if (strcmp($4, "bool") == 0) {
                new_val.i_val = $6.i_val;
            }

            insert_symbol($2, loc, scope - 1);
            add_symbol($2, loc, $4, yylineno, new_val, /*mut=*/0);
        }
    | LET MUT ID ':' Type '=' Expression ';'
        {
            int loc;

            if (strcmp($5, "i32") == 0) {
                loc = alloc_local_i32();
                CODEGEN("iload %d", $7.local_idx);
                CODEGEN("istore %d", loc);
            } else if (strcmp($5, "f32") == 0) {
                loc = alloc_local_f32();
                CODEGEN("fload %d", $7.local_idx);
                CODEGEN("fstore %d", loc);
            } else if (strcmp($5, "str") == 0) {
                loc = alloc_local_ref();
                CODEGEN("aload %d", $7.local_idx);
                CODEGEN("astore %d", loc);
            } else if (strcmp($5, "bool") == 0) {
                loc = alloc_local_i32();
                CODEGEN("iload %d", $7.local_idx);
                CODEGEN("istore %d", loc);
            } else {
                printf("error:%d: unsupported let-binding type: %s\n", yylineno, $5);
                loc = -1;
            }

            ExprVal new_val = {
                .type = strdup($5),
                .local_idx = loc
            };

            if (strcmp($5, "i32") == 0) {
                new_val.i_val = $7.i_val;
            } else if (strcmp($5, "f32") == 0) {
                new_val.f_val = $7.f_val;
            } else if (strcmp($5, "str") == 0) {
                new_val.s_val = $7.s_val;
            } else if (strcmp($5, "bool") == 0) {
                new_val.i_val = $7.i_val;
            }

            insert_symbol($3, loc, scope - 1);
            add_symbol($3, loc, $5, yylineno, new_val, /*mut=*/1);
        }
    | PRINTLN '(' {
        CODEGEN("getstatic java/lang/System/out Ljava/io/PrintStream;");
    }
    Expression ')' ';' {
        ExprVal expr = $4;
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
    | PRINT '(' {
    CODEGEN("getstatic java/lang/System/out Ljava/io/PrintStream;");
    }
    Expression ')' ';' {
        ExprVal expr = $4;
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
    | Block
    | NEWLINE

    | ID '=' Expression ';'
    {
        int sym_i = lookup_symbol($1);
        if (sym_i < 0) {
            printf("error:%d: undefined: %s\n", yylineno, $1);
        } else {
            if (! symtab[sym_i].mut) {
                printf("error:%d: cannot assign to immutable variable `%s`\n", yylineno, $1);
            } else {
                int dest = symtab[sym_i].addr;
                const char* type = symtab[sym_i].type;

                if (strcmp(type, $3.type) != 0) {
                    printf("error:%d: type mismatch in assignment to `%s`\n", yylineno, $1);
                } else if (strcmp(type, "i32") == 0) {
                    CODEGEN("iload %d", $3.local_idx);
                    CODEGEN("istore %d", dest);
                } else if (strcmp(type, "f32") == 0) {
                    CODEGEN("fload %d", $3.local_idx);
                    CODEGEN("fstore %d", dest);
                } else if (strcmp(type, "str") == 0) {
                    CODEGEN("aload %d", $3.local_idx);
                    CODEGEN("astore %d", dest);
                } else if (strcmp(type, "bool") == 0) {
                    CODEGEN("iload %d", $3.local_idx);
                    CODEGEN("istore %d", dest);
                } else {
                    printf("error:%d: unsupported type for assignment to `%s`\n", yylineno, $1);
                }
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

    | ID ADD_ASSIGN Expression ';' {
        int sym_i = lookup_symbol($1);
        if (sym_i < 0) {
            printf("error:%d: undefined: %s\n", yylineno, $1);
        } else if (!symtab[sym_i].mut) {
            printf("error:%d: cannot assign to immutable variable `%s`\n", yylineno, $1);
        } else if (strcmp(symtab[sym_i].type, $3.type) != 0) {
            printf("error:%d: type mismatch in += assignment for `%s`\n", yylineno, $1);
        } else {
            int loc = symtab[sym_i].addr;
            if (strcmp($3.type, "i32") == 0) {
                CODEGEN("iload %d", loc);
                CODEGEN("iload %d", $3.local_idx);
                CODEGEN("iadd");
                CODEGEN("istore %d", loc);
            } else if (strcmp($3.type, "f32") == 0) {
                CODEGEN("fload %d", loc);
                CODEGEN("fload %d", $3.local_idx);
                CODEGEN("fadd");
                CODEGEN("fstore %d", loc);
            }
        }
    }

    | ID SUB_ASSIGN Expression ';' {
        int sym_i = lookup_symbol($1);
        if (sym_i < 0) {
            printf("error:%d: undefined: %s\n", yylineno, $1);
        } else if (!symtab[sym_i].mut) {
            printf("error:%d: cannot assign to immutable variable `%s`\n", yylineno, $1);
        } else if (strcmp(symtab[sym_i].type, $3.type) != 0) {
            printf("error:%d: type mismatch in -= assignment for `%s`\n", yylineno, $1);
        } else {
            int loc = symtab[sym_i].addr;
            if (strcmp($3.type, "i32") == 0) {
                CODEGEN("iload %d", loc);
                CODEGEN("iload %d", $3.local_idx);
                CODEGEN("isub");
                CODEGEN("istore %d", loc);
            } else if (strcmp($3.type, "f32") == 0) {
                CODEGEN("fload %d", loc);
                CODEGEN("fload %d", $3.local_idx);
                CODEGEN("fsub");
                CODEGEN("fstore %d", loc);
            }
        }
    }

    | ID MUL_ASSIGN Expression ';' {
        int sym_i = lookup_symbol($1);
        if (sym_i < 0) {
            printf("error:%d: undefined: %s\n", yylineno, $1);
        } else if (!symtab[sym_i].mut) {
            printf("error:%d: cannot assign to immutable variable `%s`\n", yylineno, $1);
        } else if (strcmp(symtab[sym_i].type, $3.type) != 0) {
            printf("error:%d: type mismatch in *= assignment for `%s`\n", yylineno, $1);
        } else {
            int loc = symtab[sym_i].addr;
            if (strcmp($3.type, "i32") == 0) {
                CODEGEN("iload %d", loc);
                CODEGEN("iload %d", $3.local_idx);
                CODEGEN("imul");
                CODEGEN("istore %d", loc);
            } else if (strcmp($3.type, "f32") == 0) {
                CODEGEN("fload %d", loc);
                CODEGEN("fload %d", $3.local_idx);
                CODEGEN("fmul");
                CODEGEN("fstore %d", loc);
            }
        }
    }

    | ID DIV_ASSIGN Expression ';' {
        int sym_i = lookup_symbol($1);
        if (sym_i < 0) {
            printf("error:%d: undefined: %s\n", yylineno, $1);
        } else if (!symtab[sym_i].mut) {
            printf("error:%d: cannot assign to immutable variable `%s`\n", yylineno, $1);
        } else if (strcmp(symtab[sym_i].type, $3.type) != 0) {
            printf("error:%d: type mismatch in /= assignment for `%s`\n", yylineno, $1);
        } else {
            int loc = symtab[sym_i].addr;
            if (strcmp($3.type, "i32") == 0) {
                if ($3.i_val == 0) {
                    printf("error:%d: division by zero\n", yylineno);
                } else {
                    CODEGEN("iload %d", loc);
                    CODEGEN("iload %d", $3.local_idx);
                    CODEGEN("idiv");
                    CODEGEN("istore %d", loc);
                }
            } else if (strcmp($3.type, "f32") == 0) {
                if ($3.f_val == 0.0f) {
                    printf("error:%d: division by zero\n", yylineno);
                } else {
                    CODEGEN("fload %d", loc);
                    CODEGEN("fload %d", $3.local_idx);
                    CODEGEN("fdiv");
                    CODEGEN("fstore %d", loc);
                }
            }
        }
    }

    | ID REM_ASSIGN Expression ';' {
        int sym_i = lookup_symbol($1);
        if (sym_i < 0) {
            printf("error:%d: undefined: %s\n", yylineno, $1);
        } else if (!symtab[sym_i].mut) {
            printf("error:%d: cannot assign to immutable variable `%s`\n", yylineno, $1);
        } else if (strcmp(symtab[sym_i].type, $3.type) != 0) {
            printf("error:%d: type mismatch in %%= assignment for `%s`\n", yylineno, $1);
        } else {
            int loc = symtab[sym_i].addr;
            if (strcmp($3.type, "i32") == 0) {
                if ($3.i_val == 0) {
                    printf("error:%d: division by zero\n", yylineno);
                } else {
                    CODEGEN("iload %d", loc);
                    CODEGEN("iload %d", $3.local_idx);
                    CODEGEN("irem");
                    CODEGEN("istore %d", loc);
                }
            } else {
                printf("error:%d: unsupported type for %%=\n", yylineno);
            }
        }
    }
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
    : ID
    {
        int idx = lookup_symbol($1);
        if (idx < 0) {
            printf("error:%d: undefined variable: %s\n", yylineno, $1);
            $$ = (ExprVal){ .type = strdup("undefined"), .local_idx = -1 };
        } else {
            int slot = symtab[idx].addr;  /* JVM local-var index */

            if (strcmp(symtab[idx].type, "i32") == 0) {
                $$ = (ExprVal){
                    .type      = strdup("i32"),
                    .local_idx = slot,
                    .i_val     = symtab[idx].i_val
                };
            } else if (strcmp(symtab[idx].type, "f32") == 0) {
                $$ = (ExprVal){
                    .type      = strdup("f32"),
                    .local_idx = slot,
                    .f_val     = symtab[idx].f_val
                };
            } else if (strcmp(symtab[idx].type, "str") == 0) {
                $$ = (ExprVal){
                    .type      = strdup("str"),
                    .local_idx = slot,
                    .s_val     = symtab[idx].s_val
                };
            } else if (strcmp(symtab[idx].type, "bool") == 0) {
                $$ = (ExprVal){
                    .type      = strdup("bool"),
                    .local_idx = slot,
                    .i_val     = symtab[idx].i_val
                };
            } else {
                printf("error:%d: unknown variable type for %s\n", yylineno, $1);
                $$ = (ExprVal){ .type = strdup("undefined"), .local_idx = -1 };
            }
        }
    }
    | INT_LIT {
        int idx = alloc_local_i32();
        CODEGEN("ldc %d", $1);
        CODEGEN("istore %d", idx);
        $$.type = strdup("i32");
        $$.i_val = $1;
        $$.local_idx = idx;
    }
    | FLOAT_LIT {
        int idx = alloc_local_f32();
        CODEGEN("ldc %f", $1);
        CODEGEN("fstore %d", idx);
        $$.type = strdup("f32");
        $$.f_val = $1;
        $$.local_idx = idx;
    }
    | STRING_LIT {
        int idx = alloc_local_ref();
        CODEGEN("ldc %s", $1);
        CODEGEN("astore %d", idx);
        $$.type = strdup("str");
        $$.s_val = strdup($1);
        $$.local_idx = idx;
    }
    | Expression '+' Expression {
        if (strcmp($1.type, "i32") == 0 && strcmp($3.type, "i32") == 0) {
            int idx = alloc_local_i32();
            CODEGEN("iload %d", $1.local_idx);
            CODEGEN("iload %d", $3.local_idx);
            CODEGEN("iadd");
            CODEGEN("istore %d", idx);
            $$ = (ExprVal){
                .type = strdup("i32"),
                .local_idx = idx,
                .i_val = $1.i_val + $3.i_val
            };
        } else if (strcmp($1.type, "f32") == 0 && strcmp($3.type, "f32") == 0) {
            int idx = alloc_local_f32();
            CODEGEN("fload %d", $1.local_idx);
            CODEGEN("fload %d", $3.local_idx);
            CODEGEN("fadd");
            CODEGEN("fstore %d", idx);
            $$ = (ExprVal){
                .type = strdup("f32"),
                .local_idx = idx,
                .f_val = $1.f_val + $3.f_val
            };
        } else {
            fprintf(stderr, "error:%d: type mismatch in '+'\n", yylineno);
            $$ = (ExprVal){ .type = strdup("undefined"), .local_idx = -1 };
        }
    }
    | Expression '-' Expression {
        if (strcmp($1.type, "i32") == 0 && strcmp($3.type, "i32") == 0) {
            int idx = alloc_local_i32();
            CODEGEN("iload %d", $1.local_idx);
            CODEGEN("iload %d", $3.local_idx);
            CODEGEN("isub");
            CODEGEN("istore %d", idx);
            $$ = (ExprVal){
                .type = strdup("i32"),
                .local_idx = idx,
                .i_val = $1.i_val - $3.i_val
            };
        } else if (strcmp($1.type, "f32") == 0 && strcmp($3.type, "f32") == 0) {
            int idx = alloc_local_f32();
            CODEGEN("fload %d", $1.local_idx);
            CODEGEN("fload %d", $3.local_idx);
            CODEGEN("fsub");
            CODEGEN("fstore %d", idx);
            $$ = (ExprVal){
                .type = strdup("f32"),
                .local_idx = idx,
                .f_val = $1.f_val - $3.f_val
            };
        } else {
            fprintf(stderr, "error:%d: type mismatch in '-'\n", yylineno);
            $$ = (ExprVal){ .type = strdup("undefined"), .local_idx = -1 };
        }
    }
    | Expression '*' Expression {
        if (strcmp($1.type, "i32") == 0 && strcmp($3.type, "i32") == 0) {
            int idx = alloc_local_i32();
            CODEGEN("iload %d", $1.local_idx);
            CODEGEN("iload %d", $3.local_idx);
            CODEGEN("imul");
            CODEGEN("istore %d", idx);
            $$ = (ExprVal){
                .type = strdup("i32"),
                .local_idx = idx,
                .i_val = $1.i_val * $3.i_val
            };
        } else if (strcmp($1.type, "f32") == 0 && strcmp($3.type, "f32") == 0) {
            int idx = alloc_local_f32();
            CODEGEN("fload %d", $1.local_idx);
            CODEGEN("fload %d", $3.local_idx);
            CODEGEN("fmul");
            CODEGEN("fstore %d", idx);
            $$ = (ExprVal){
                .type = strdup("f32"),
                .local_idx = idx,
                .f_val = $1.f_val * $3.f_val
            };
        } else {
            fprintf(stderr, "error:%d: type mismatch in '*'\n", yylineno);
            $$ = (ExprVal){ .type = strdup("undefined"), .local_idx = -1 };
        }
    }
    | Expression '/' Expression {
        if (strcmp($1.type, "i32") == 0 && strcmp($3.type, "i32") == 0) {
            if ($3.i_val == 0) {
                fprintf(stderr, "error:%d: division by zero\n", yylineno);
                $$ = (ExprVal){ .type = strdup("undefined"), .local_idx = -1 };
            } else {
                int idx = alloc_local_i32();
                CODEGEN("iload %d", $1.local_idx);
                CODEGEN("iload %d", $3.local_idx);
                CODEGEN("idiv");
                CODEGEN("istore %d", idx);
                $$ = (ExprVal){
                    .type = strdup("i32"),
                    .local_idx = idx,
                    .i_val = $1.i_val / $3.i_val
                };
            }
        } else if (strcmp($1.type, "f32") == 0 && strcmp($3.type, "f32") == 0) {
            if ($3.f_val == 0.0f) {
                fprintf(stderr, "error:%d: division by zero\n", yylineno);
                $$ = (ExprVal){ .type = strdup("undefined"), .local_idx = -1 };
            } else {
                int idx = alloc_local_f32();
                CODEGEN("fload %d", $1.local_idx);
                CODEGEN("fload %d", $3.local_idx);
                CODEGEN("fdiv");
                CODEGEN("fstore %d", idx);
                $$ = (ExprVal){
                    .type = strdup("f32"),
                    .local_idx = idx,
                    .f_val = $1.f_val / $3.f_val
                };
            }
        } else {
            fprintf(stderr, "error:%d: type mismatch in '/'\n", yylineno);
            $$ = (ExprVal){ .type = strdup("undefined"), .local_idx = -1 };
        }
    }
    | Expression '%' Expression {
        if (strcmp($1.type, "i32") == 0 && strcmp($3.type, "i32") == 0) {
            if ($3.i_val == 0) {
                fprintf(stderr, "error:%d: division by zero in modulus\n", yylineno);
                $$ = (ExprVal){ .type = strdup("undefined"), .local_idx = -1 };
            } else {
                int idx = alloc_local_i32();
                CODEGEN("iload %d", $1.local_idx);
                CODEGEN("iload %d", $3.local_idx);
                CODEGEN("irem");
                CODEGEN("istore %d", idx);
                $$ = (ExprVal){
                    .type = strdup("i32"),
                    .local_idx = idx,
                    .i_val = $1.i_val % $3.i_val
                };
            }
        } else {
            fprintf(stderr, "error:%d: unsupported type for modulus (only i32 allowed)\n", yylineno);
            $$ = (ExprVal){ .type = strdup("undefined"), .local_idx = -1 };
        }
    }
    | Expression '>' Expression {
        if (strcmp($1.type, $3.type) != 0)
            printf("error:%d: invalid operation: GTR (mismatched types)\n", yylineno);

        int idx = alloc_local_i32();

        if (strcmp($1.type, "i32") == 0) {
            CODEGEN("iload %d", $1.local_idx);
            CODEGEN("iload %d", $3.local_idx);
            CODEGEN("if_icmpgt Ltrue%d", label_count);
        } else if (strcmp($1.type, "f32") == 0) {
            CODEGEN("fload %d", $1.local_idx);
            CODEGEN("fload %d", $3.local_idx);
            CODEGEN("fcmpg");
            CODEGEN("iconst_0");
            CODEGEN("if_icmpgt Ltrue%d", label_count);
        } else {
            printf("error:%d: '>' not supported for type %s\n", yylineno, $1.type);
        }

        CODEGEN("iconst_0");
        CODEGEN("goto Lend%d",  label_count);
        CODEGEN("Ltrue%d:",     label_count);
        CODEGEN("iconst_1");
        CODEGEN("Lend%d:",      label_count);

        CODEGEN("istore %d", idx);
        $$ = (ExprVal){ .type = "bool", .local_idx = idx };
        label_count++;
    }
    
    | Expression '<' Expression
    {
        if (strcmp($1.type, $3.type) != 0)
            printf("error:%d: invalid operation: LSS (mismatched types)\n", yylineno);

        if (strcmp($1.type, "i32") == 0) {
            CODEGEN("iload %d", $1.local_idx);
            CODEGEN("iload %d", $3.local_idx);
            CODEGEN("if_icmplt Ltrue%d", label_count);
        } else if (strcmp($1.type, "f32") == 0) {
            CODEGEN("fload %d", $1.local_idx);
            CODEGEN("fload %d", $3.local_idx);
            CODEGEN("fcmpg");
            CODEGEN("iconst_0");
            CODEGEN("if_icmplt Ltrue%d", label_count);
        } else {
            printf("error:%d: '<' not supported for %s\n", yylineno, $1.type);
        }

        CODEGEN("iconst_0");
        CODEGEN("goto Lend%d",  label_count);
        CODEGEN("Ltrue%d:",     label_count);
        CODEGEN("iconst_1");
        CODEGEN("Lend%d:",      label_count);

        int idx = alloc_local_i32();
        CODEGEN("istore %d", idx);
        $$ = (ExprVal){ .type = "bool", .local_idx = idx };
        label_count++;
    }

    | Expression LAND Expression {
        int result = alloc_local_i32();
        int false_label = label_count++;
        int end_label = label_count++;
        // if left operand is false → short-circuit false
        CODEGEN("iload %d", $1.local_idx);
        CODEGEN("ifeq Lfalse%d", false_label);
        // else evaluate right
        CODEGEN("iload %d", $3.local_idx);
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
        $$ = (ExprVal){ .type = "bool", .local_idx = result };
    }
    | Expression LOR Expression {
        int result = alloc_local_i32();
        int true_label = label_count++;
        int end_label = label_count++;

        CODEGEN("iload %d", $1.local_idx);
        CODEGEN("ifne Ltrue%d", true_label);  // if left is true, short-circuit
        CODEGEN("iload %d", $3.local_idx);    // evaluate right
        CODEGEN("ifne Ltrue%d", true_label);
        CODEGEN("iconst_0");
        CODEGEN("goto Lend%d", end_label);
        CODEGEN("Ltrue%d:", true_label);
        CODEGEN("iconst_1");
        CODEGEN("Lend%d:", end_label);
        CODEGEN("istore %d", result);
        $$ = (ExprVal){ .type = "bool", .local_idx = result };
    }
    | '!' Expression {
        int result = alloc_local_i32();
        int true_label = label_count++;
        int end_label = label_count++;

        CODEGEN("iload %d", $2.local_idx);
        CODEGEN("ifeq Ltrue%d", true_label);
        CODEGEN("iconst_0");
        CODEGEN("goto Lend%d", end_label);
        CODEGEN("Ltrue%d:", true_label);
        CODEGEN("iconst_1");
        CODEGEN("Lend%d:", end_label);
        CODEGEN("istore %d", result);

        $$ = (ExprVal){ .type = "bool", .local_idx = result };
        label_count++;
    }
    | '-' Expression %prec UMINUS {
        if (strcmp($2.type, "i32") == 0) {
            CODEGEN("iload %d", $2.local_idx);
            CODEGEN("ineg");
            int idx = alloc_local_i32();
            CODEGEN("istore %d", idx);
            $$ = (ExprVal){ .type = "i32", .i_val = -$2.i_val, .local_idx = idx };
        } else if (strcmp($2.type, "f32") == 0) {
            CODEGEN("fload %d", $2.local_idx);
            CODEGEN("fneg");
            int idx = alloc_local_f32();
            CODEGEN("fstore %d", idx);
            $$ = (ExprVal){ .type = "f32", .f_val = -$2.f_val, .local_idx = idx };
        } else {
            fprintf(stderr, "error:%d: unary minus on unsupported type\n", yylineno);
            $$ = (ExprVal){ .type = "undefined" };
        }
    }
    | '(' Expression ')' {
        $$ = $2;
    }
    | Expression EQL Expression {
        CODEGEN("iload %d", $1.local_idx);
        CODEGEN("iload %d", $3.local_idx);

        CODEGEN("if_icmpeq Ltrue%d", label_count);
        CODEGEN("iconst_0");
        CODEGEN("goto Lend%d",  label_count);
        CODEGEN("Ltrue%d:",     label_count);
        CODEGEN("iconst_1");
        CODEGEN("Lend%d:",      label_count);

        int idx = alloc_local_i32();
        CODEGEN("istore %d", idx);
        $$ = (ExprVal){ .type = "bool", .local_idx = idx };
        label_count++;
    }
    | Expression NEQ Expression {
        CODEGEN("iload %d", $1.local_idx);
        CODEGEN("iload %d", $3.local_idx);

        CODEGEN("if_icmpne Ltrue%d", label_count);
        CODEGEN("iconst_0");
        CODEGEN("goto Lend%d",  label_count);
        CODEGEN("Ltrue%d:",     label_count);
        CODEGEN("iconst_1");
        CODEGEN("Lend%d:",      label_count);

        int idx = alloc_local_i32();
        CODEGEN("istore %d", idx);
        $$ = (ExprVal){ .type = "bool", .local_idx = idx };
        label_count++;
    }
    | Expression '[' INT_LIT ']' {
        if (strcmp($1.type, "array") != 0) {
            printf("error:%d: trying to index a non-array\n", yylineno);
            $$ = (ExprVal){ .type = "undefined" };
        } else {
            CODEGEN("ldc %d", $3);
            CODEGEN("aaload");
            $$ = (ExprVal){ .type = "i32" };
        }
    }
    | Expression LSHIFT Expression {
        if (strcmp($1.type, "undefined") != 0 && strcmp($3.type, "undefined") != 0 && strcmp($1.type, $3.type) != 0) {
            printf("error:%d: invalid operation: LSHIFT (mismatched types)\n", yylineno);
            $$ = (ExprVal){ .type = "undefined" };
        } else {
            CODEGEN("ishl");
            $$ = (ExprVal){ .type = $1.type };
        }
    }
    | TRUE {
        int idx = alloc_local_i32();
        CODEGEN("iconst_1");
        CODEGEN("istore %d", idx);
        $$ = (ExprVal){ .type = "bool", .local_idx = idx, .i_val = 1 };
    }
    | FALSE {
        int idx = alloc_local_i32();
        CODEGEN("iconst_0");
        CODEGEN("istore %d", idx);
        $$ = (ExprVal){ .type = "bool", .local_idx = idx, .i_val = 0 };
    }
    | Expression AS Type {
        if (strcmp($3, "i32") == 0 && strcmp($1.type, "f32") == 0) {
            int idx = alloc_local_i32();
            CODEGEN("fload %d", $1.local_idx);
            CODEGEN("f2i");
            CODEGEN("istore %d", idx);
            $$ = (ExprVal){ .type = "i32", .local_idx = idx };
        } else if (strcmp($3, "f32") == 0 && strcmp($1.type, "i32") == 0) {
            int idx = alloc_local_f32();
            CODEGEN("iload %d", $1.local_idx);
            CODEGEN("i2f");
            CODEGEN("fstore %d", idx);
            $$ = (ExprVal){ .type = "f32", .local_idx = idx };
        } else {
            fprintf(stderr, "error:%d: invalid cast from %s to %s\n", yylineno, $1.type, $3);
            $$ = (ExprVal){ .type = strdup("undefined"), .local_idx = -1 };
        }
    }
;

Type
    : INT   { $$ = "i32"; }
    | FLOAT { $$ = "f32"; }
    | BOOL  { $$ = "bool"; }
    | '&' STR { $$ = "str"; }
    | '[' Type ';' INT_LIT ']' { $$ = "array"; }
;
%%

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
