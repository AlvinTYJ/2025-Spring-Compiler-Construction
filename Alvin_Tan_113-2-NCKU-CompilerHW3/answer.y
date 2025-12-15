/* Please feel free to modify any content */

/* Definition section */
%{
    #include "compiler_common.h" //Extern variables that communicate with lex
    // #define YYDEBUG 1
    // int yydebug = 1;

    extern int yylineno;
    extern int yylex();
    extern FILE *yyin;

    int yylex_destroy ();
    void yyerror ( char const *s ) {
        printf("error:%d: %s\n", yylineno, s);
    }

	/* Used to generate code */
    /* As printf; the usage: CODEGEN("%d - %s\n", 100, "Hello world"); */
    /* We do not enforce the use of this macro */
    #define CODEGEN(...) \
        do { \
            for (int i = 0; i < g_indent_cnt; i++) { \
                fprintf(fout, "\t"); \
            } \
            fprintf(fout, __VA_ARGS__); \
        } while (0)

    /* Custom variables to matian symbol table */
    typedef struct node {
        int idx;
        int addr;
		int mut;
        int lineno;
        char name[32]; 
        char func[32];
        type_t type;

        struct node *next;
    } Node;

    typedef struct table {
        Node* head;
        Node* tail;
        int cnt;
    } Table;

    Table *symbol_table[1024];
	bool table_list[1024];
	Node *table_tmp[1024];
	int table_tmp_idx[1024];
	char error_msg[1024];
	bool error_flag = false;
	bool record = false;
	bool is_array = false;
	bool returned = false;
	type_t last_type;
	FILE *fout = NULL;
	int g_indent_cnt = 0;
	int c_exp = 0;
	bool in_while_loop = false;
	bool is_array_declare = false;
	int array_idx = 0;
	bool in_looper = false;
	bool in_for_each = false;
	bool slicer = false;
 
    /* Symbol table function - you can add new functions if needed. */
    /* parameters and return type can be changed */
    static void create_symbol();
    static Node* insert_symbol();
    static Node* lookup_symbol();
    static void dump_symbol();
    static void insert_node();
    static Node* init_node();
    static char get_type();
	static char *get_print_type();
	const char *get_ls_name();
	void get_op_inst();

    /* Global variables */
    int scope = 0;
    int addr = 0;
    bool HAS_ERROR = false, print = false;

    int op_idx = 0;
	int lb_idx = 0;
	int ks_idx = 0;
	int sw_cnt = 0;
	int fr_cnt = 0;
	int ce_cnt = 0;
    op_t ops[1024];
	char buffer[128];
	char assign[128];
	int label[128];
	int kase[128];

    /* Function */
    const char* get_op_name ( op_t op ) {
        switch ( op ) {
            case OP_ADD:		return "ADD";
            case OP_SUB:		return "SUB";
            case OP_MUL:		return "MUL";
            case OP_QUO:		return "DIV";
            case OP_REM:		return "REM";
            case OP_EQL:		return "EQL";
            case OP_NEQ:		return "NEQ";
            case OP_LSS:		return "LSS";
            case OP_LEQ:		return "LEQ";
            case OP_GTR:		return "GTR";
            case OP_GEQ:		return "GEQ";
            case OP_POS:		return "POS";
            case OP_NEG:		return "NEG";
            case OP_NOT:		return "NOT";
            case OP_LOR:		return "LOR";
            case OP_LAND:		return "LAND";
			case OP_BOR:		return "BOR";
			case OP_BAND:		return "BAND";
            case OP_ASSIGN:		return "ASSIGN";
            case OP_ADD_ASSIGN:	return "ADD";
            case OP_SUB_ASSIGN:	return "SUB";
            case OP_MUL_ASSIGN:	return "MUL";
            case OP_QUO_ASSIGN:	return "DIV";
            case OP_REM_ASSIGN:	return "REM";
			case OP_LSHIFT:		return "LSHIFT";
			case OP_RSHIFT:		return "RSHIFT";
            default:			return "unknown";
        }
    }

    const char* get_type_name(type_t type) {
		if ( is_array )
			return "array";
        switch (type) {
            case TYPE_INT:		return "i32";
            case TYPE_FLOAT:	return "f32";
            case TYPE_BOOL:		return "bool";
            case TYPE_STR:		return "str";
            case TYPE_FUNC:		return "func";
			case TYPE_ARRAY:	return "array";
            default:			return "undefined";
        }
    } 
%}

%error-verbose

/* Use variable or self-defined structure to represent
 * nonterminal and token type
 *  - you can add new fields if needed.
 */
%union {
    struct {
        union {
            int i_val;
            float f_val;
            bool b_val;
            char *s_val;
        };
        type_t type;
		char name[16];
    } val;
    char *s_val;
    op_t op;
    type_t type;
}

/* Token without return */
%token LET MUT NEWLINE
%token INT FLOAT BOOL STR
%token RINT RFLOAT RBOOL RSTR
%token TRUE FALSE
%token GEQ LEQ EQL NEQ LOR LAND NOT GTR LSS
%token ASSIGN ADD_ASSIGN SUB_ASSIGN MUL_ASSIGN QUO_ASSIGN REM_ASSIGN
%token IF ELSE FOR WHILE LOOP
%token PRINT PRINTLN
%token FUNC RETURN BREAK
%token ID ARROW AS IN DOTDOT RSHIFT LSHIFT
%token COLON SEMICOLON COMMA
%token ADD SUB MUL QUO REM
%token NOT BAND BOR BNOT
%token LPAREN RPAREN LBRACK RBRACK LBRACE RBRACE

/* Token with return, which need to sepcify type */
%token <val> INT_LIT
%token <val> FLOAT_LIT
%token <val> BOOL_LIT
%token <s_val> STRING_LIT

/* Nonterminal with return, which need to sepcify type */
%type <type> Type
%type <val> Operand
%type <val> Literal
%type <val> UnaryExpr
%type <val> Expression
%type <s_val> FuncOpen
%type <val> PrimaryExpr
%type <s_val> ParameterList
%type <op> add_op mul_op unary_op assign_op

/* Yacc will start at this nonterminal */
%start Program

/* Grammar section */
%%

Program
    : { create_symbol ( scope++ ); } GlobalStatementList
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
    : FuncOpen LPAREN ParameterList RPAREN ARROW Type {
        char tmp[4];
        tmp[0] = ')', tmp[1] = get_type ( $6 ), tmp[2] = '\0';
        strcat ( $3, tmp );
		scope--;
        insert_symbol ( $1, TYPE_FUNC, $3, -1, yylineno + 1 );
		CODEGEN ( ".method public static %s%s\n", $1, $3 );
		CODEGEN ( ".limit stack 128\n" );
		CODEGEN ( ".limit locals 128\n" );
		// scope++;
		returned = false;
    } FuncBlock {
		if ( !returned ) {
			returned = true;
			CODEGEN ( "\treturn\n" );
			CODEGEN ( ".end method\n" );
		}
		else
			puts ( "bloop wut?" );
	}
    | FuncOpen LPAREN RPAREN {
        insert_symbol ( $1, TYPE_FUNC, "(V)V", -1, yylineno + 1 );
		if ( !strcmp ( $1, "main" ) )
        	CODEGEN ( ".method public static main([Ljava/lang/String;)V\n" );
		else
			CODEGEN ( ".method public statis %s()V\n", $1 );
		CODEGEN ( ".limit stack 128\n" );
		CODEGEN ( ".limit locals 128\n" );
		// scope++;
		returned = 0;
    } FuncBlock {
		if ( !returned ) {
			returned = true;
			if ( slicer ) {
				CODEGEN ( "\tgetstatic java/lang/System/out Ljava/io/PrintStream;\n" );
				CODEGEN ( "\taload 0\n" );
				CODEGEN ( "\tinvokevirtual java/io/PrintStream/println(Ljava/lang/String;)V\n" );
			}
			CODEGEN ( "\treturn\n" );
			CODEGEN ( ".end method\n" );
		}
		else
			puts ( "bloop wut?" );
	}
;

FuncBlock
	: LBRACE { create_symbol ( scope++ ); } StatementList RBRACE { dump_symbol(); }
;

FuncOpen
    : FUNC ID {
        $$ = $<s_val>2;
        printf ( "func: %s\n", $$ );
    }
;

FuncCallStmt
    : ID LPAREN RPAREN { 
        Node *tmp = lookup_symbol ( $<s_val>1 );
        printf ( "call: %s%s\n", tmp -> name, tmp -> func );
        CODEGEN ( "\tinvokestatic Main/%s%s\n", tmp -> name, tmp -> func );
    }
    | ID LPAREN ArgumentList RPAREN {
        Node *tmp = lookup_symbol ( $<s_val>1 );
        printf ( "call: %s%s\n", tmp -> name, tmp -> func);
        CODEGEN ( "\tinvokestatic Main/%s%s\n", tmp -> name, tmp -> func );
    }
;

ArgumentList
    : Expression
    | ArgumentList COMMA Expression
;

ParameterList
    : ID COLON Type {
        scope++;
        $$ = ( char * ) malloc ( sizeof ( char ) * 1024);
        $$[0] = '(';
        $$[1] = get_type ( $3 );
        $$[2] = '\0';

        insert_symbol ( $<s_val>1, $3, "", 0, yylineno + 1 );
    }
    | ParameterList COMMA ID COLON Type { 
        char tmp[2];
        tmp[0] = get_type ( $5 ), tmp[1] = '\0';
        strcat ( $$, tmp );

        insert_symbol ( $<s_val>3, $5, "", 0, yylineno + 1 );
    }
;

ReturnStmt
    : { print = true; } RETURN SEMICOLON {
		CODEGEN ( "\treturn\n" );
		CODEGEN ( ".end method\n" );
	}
    | RETURN SEMICOLON NEWLINE {
		CODEGEN ( "\treturn\n" );
		CODEGEN ( ".end method\n" );
	}
    | RETURN Expression SEMICOLON {
		puts ( "breturn" );
		CODEGEN ( "\treturn\n" );
		CODEGEN ( ".end method\n" );
	}
    | RETURN Expression SEMICOLON NEWLINE {
		puts ( "breturn" );
		CODEGEN ( "\treturn\n" );
		CODEGEN ( ".end method\n" );
	}
;

/* ---------- Types ---------- */

Type
    : INT { $<type>$ = TYPE_INT; }
    | FLOAT		{ $<type>$ = TYPE_FLOAT; }
    | STR		{ $<type>$ = TYPE_STR; }
    | BOOL		{ $<type>$ = TYPE_BOOL; }
    | RINT		{ $<type>$ = TYPE_INT; }
    | RFLOAT	{ $<type>$ = TYPE_FLOAT; }
    | RSTR		{ $<type>$ = TYPE_STR; }
    | RBOOL		{ $<type>$ = TYPE_BOOL; }
;

/* ---------- Expressions ---------- */

Expression
    : UnaryExpr
    | Expression binary_op {
		if ( $<op>2 == OP_LOR || $<op>2 == OP_LAND ) {
			printf ( "\t%d: %s %s %s\n", yylineno, get_op_name ( ops[op_idx] ), get_op_name ( $<op>2 ), buffer );
			while ( op_idx && ops[op_idx] != OP_LOR && ops[op_idx] != OP_LAND ) {
				get_op_inst ( buffer, $<val>1.type, ops[op_idx] );
				CODEGEN ( "\t%s", buffer );

				if ( $<val>1.type == TYPE_FLOAT )
					CODEGEN ( "\n" );
				else {
					if ( ops[op_idx] == OP_EQL || ops[op_idx] == OP_NEQ || ops[op_idx] == OP_LSS || ops[op_idx] == OP_LEQ || ops[op_idx] == OP_GTR || ops[op_idx] == OP_GEQ ) {
						CODEGEN ( " L_cmp_%d\n", ce_cnt++ );
						CODEGEN ( "\t1 iconst_1\n" );
						CODEGEN ( "\tgoto L_cmp_%d\n", ce_cnt++ );
						CODEGEN ( "L_cmp_%d:\n", ce_cnt - 2 );
						CODEGEN ( "\t2 iconst_0\n" );
						CODEGEN ( "L_cmp_%d:\n", ce_cnt - 1 );
					}
					else
						CODEGEN ( "\n" );
				}
				printf ( "%s\n", get_op_name ( ops[op_idx--] ) );
			}
		}

		if ( $<op>2 == OP_EQL || $<op>2 == OP_NEQ || $<op>2 == OP_LSS || $<op>2 == OP_LEQ || $<op>2 == OP_GTR || $<op>2 == OP_GEQ ) {
			while ( op_idx ) {
				get_op_inst ( buffer, $<val>1.type, ops[op_idx] );
				printf ( "%s\n", get_op_name ( ops[op_idx--] ) );
				CODEGEN ( "\t%s\n", buffer );
			}
		}
        ops[++op_idx] = $<op>2;
        printf ( "\t%s\n", get_op_name ( ops[op_idx] ) );
    } Expression {
		bool pass = false;
        while ( op_idx ) {
            if ( ops[op_idx] == OP_REM && ( $1.type == TYPE_FLOAT || $4.type == TYPE_FLOAT ) )
                printf ( "error:%d: invalid operation: (operator REM not defined on float32)\n", yylineno + 1 );
            else if ( ( $1.type == TYPE_INT || $1.type == TYPE_FLOAT ) && ( $4.type == TYPE_INT || $4.type == TYPE_FLOAT ) && $1.type != $4.type ) {
				if ( !( $1.type == TYPE_INT && $4.type == TYPE_FLOAT && ops[op_idx] == OP_ASSIGN ) )
                	printf ( "error:%d: invalid operation: %s (mismatched types %s and %s)\n", yylineno + 1, get_op_name ( ops[op_idx] ), get_type_name ( $1.type ), get_type_name ( $4.type ) );
				pass = true;
				$$.type = $1.type;
			}
            else if ( ( ops[op_idx] == OP_LAND || ops[op_idx] == OP_LOR ) && ( $1.type != TYPE_BOOL || $4.type != TYPE_BOOL ) )
                printf ( "error:%d: invalid operation: (operator %s not defined on %s)\n",  yylineno + 1, get_op_name ( ops[op_idx] ), get_type_name ( $1.type == TYPE_BOOL ? $4.type : $1.type ) );
            if ( HAS_ERROR )
                printf ( "error:%d: invalid operation: %s (mismatched types %s and %s)\n", yylineno + 1, get_op_name ( ops[op_idx] ), get_type_name ( $1.type ), get_type_name ( $4.type ) );
			if ( ops[op_idx] != OP_ASSIGN ) {
				get_op_inst ( buffer, $$.type, ops[op_idx] );
				if ( ops[op_idx] == OP_EQL || ops[op_idx] == OP_NEQ || ops[op_idx] == OP_LSS || ops[op_idx] == OP_LEQ || ops[op_idx] == OP_GTR || ops[op_idx] == OP_GEQ ) {
					if ( !c_exp && !in_looper )
						CODEGEN ( "\t%s Label_%d\n", buffer, lb_idx );
				}
				else
					CODEGEN ( "\t%s\n", buffer );
			}
			else {
				printf ( "\t%s\n", get_op_name ( $<op>2 ) );
				Node *tmp = lookup_symbol ( assign );
				CODEGEN ( "\t%s %d\n", get_ls_name ( $1.type, 1 ), tmp -> addr );
			}
            printf ( "%s\n", get_op_name ( ops[op_idx--] ) );
        }

		if ( !pass ) {
        	if ( $<op>2 == OP_EQL || $<op>2 == OP_NEQ || $<op>2 == OP_LSS || $<op>2 == OP_LEQ || $<op>2 == OP_GTR || $<op>2 == OP_GEQ )
            	$1.type = $4.type = TYPE_BOOL;

        	if ( $1.type == TYPE_BOOL || $4.type == TYPE_BOOL )
				$$.type = TYPE_BOOL;
        	else if ( ( $1.type == TYPE_FLOAT || $4.type == TYPE_FLOAT ) )
				$$.type = TYPE_FLOAT;
        	else
				$$.type = TYPE_INT;
		}
        HAS_ERROR = false;
    }
	| Expression AS FLOAT {
        $<s_val>$ = $<s_val>1;
		$$.type = TYPE_FLOAT;
		puts ( "i2f" ), $$.type = TYPE_FLOAT;
		CODEGEN ( "\ti2f\n" );
    }
	| Expression AS INT {
        $<s_val>$ = $<s_val>1;
		$$.type = TYPE_INT;
		puts ( "f2i" ), $$.type = TYPE_INT;
		CODEGEN ( "\tf2i\n" );
	}
;

UnaryExpr
    : PrimaryExpr {
		$$.type = $1.type;
	}
    | unary_op UnaryExpr {
        $$.type = $2.type;
        if ( $$.type == TYPE_INT ) {
			$$.i_val = ( $<op>1 == OP_POS ? $<val>2.i_val : -$<val>2.i_val );
			if ( $1 == OP_NEG )
				CODEGEN ( "\tineg\n" );
		}
        else if ( $$.type == TYPE_FLOAT ) {
			$$.f_val = ( $<op>1 == OP_POS ? $<val>2.f_val : -$<val>2.f_val );
			if ( $1 == OP_NEG )
				CODEGEN ( "\tfneg\n" );
		}
        printf ( "%s\n", get_op_name ( $<op>1 ) );
    }
;

binary_op
    : LOR { 
        while ( op_idx && ops[op_idx] != OP_LOR && ops[op_idx] != OP_LAND )
			printf ( "%s\n", get_op_name(ops[op_idx--] ) );
        $<op>$ = OP_LOR;
    }
    | LAND { 
        while ( op_idx && ops[op_idx] != OP_LOR && ops[op_idx] != OP_LAND )
			printf ( "%s\n", get_op_name ( ops[op_idx--] ) );
        $<op>$ = OP_LAND;
    }
    | cmp_op {
		while ( op_idx )
			printf ( "%s\n", get_op_name ( ops[op_idx--] ) );
	}
    | add_op
    | mul_op
;

cmp_op
    : EQL { $<op>$ = OP_EQL; }
    | NEQ { $<op>$ = OP_NEQ; }
    | LSS { $<op>$ = OP_LSS; }
    | LEQ { $<op>$ = OP_LEQ; }
    | GTR { $<op>$ = OP_GTR; }
    | GEQ { $<op>$ = OP_GEQ; }
;

add_op
    : ADD	{ $<op>$ = OP_ADD; }
    | SUB	{ $<op>$ = OP_SUB; }
	| BAND	{ $<op>$ = OP_BAND; }
	| BOR	{ $<op>$ = OP_BOR; }
;

mul_op
    : MUL		{ $<op>$ = OP_MUL; }
    | QUO		{ $<op>$ = OP_QUO; }
    | REM		{ $<op>$ = OP_REM; }
	| LSHIFT	{ $<op>$ = OP_LSHIFT; }
	| RSHIFT	{ $<op>$ = OP_RSHIFT; }
;

unary_op
    : ADD { $<op>$ = OP_POS; }
    | SUB { $<op>$ = OP_NEG; }
    | NOT { $<op>$ = OP_NOT; }
;

/* ---------- Primary expressions ---------- */

PrimaryExpr
    : FuncCallStmt
    | Operand {
		last_type = $$.type;
	}
;

Operand
    : Literal
    | ID {
        Node *tmp = lookup_symbol ( $<s_val>1 );
        if ( tmp ) {
            $$.type = tmp -> type;
			strcpy ( $$.name, tmp -> name );
			if ( print ) {
            	printf ( "IDENT (name=%s, address=%d)\n", tmp -> name, tmp -> addr );
			}
			if ( !in_while_loop && !in_looper && !in_for_each )
				CODEGEN ( "\t%s %d\n", get_ls_name ( $$.type, 0 ), tmp -> addr );
        }
		else {
			if ( record ) {
            	sprintf ( error_msg, "error:%d: undefined: %s", yylineno + 1, $<s_val>1 );
				error_flag = true;
			}
			else
				printf ( "error:%d: undefined: %s\n", yylineno + 1, $<s_val>1 );
            HAS_ERROR = true;
            $$.type = 0x3f3f3f3f;
        }
    }
    | LPAREN Expression RPAREN { $$.type = $2.type; } 
	| ID {
        Node *tmp = lookup_symbol ( $<s_val>1 );
        if ( tmp ) {
            $$.type = tmp -> type;
			is_array = true;
			if ( print )
            	printf ( "IDENT (name=%s, address=%d)\n", tmp -> name, tmp -> addr );
        }
		else {
			if ( record ) {
            	sprintf ( error_msg, "error:%d: undefined: %s", yylineno + 1, $<s_val>1 );
				error_flag = true;
			}
			else
				printf ( "error:%d: undefined: %s\n", yylineno + 1, $<s_val>1 );
            HAS_ERROR = true;
            $$.type = 0x3f3f3f3f;
        }
    } LBRACK INT_LIT { printf ( "INT_LIT %s\n", $<s_val>4 ); } RBRACK
;

Literal
    : INT_LIT {
        $$.type = TYPE_INT;
        $$.i_val = atoi ( $<s_val>1 );
        printf ( "INT_LIT %d\n", $$.i_val );
		if ( !in_while_loop && !in_looper ) {
			CODEGEN ( "\tldc %d\n", $$.i_val );
			if ( is_array_declare )
				CODEGEN ( "\tistore %d\n", array_idx++ );
		}
    }
    | FLOAT_LIT {
        $$.type = TYPE_FLOAT;
        $$.f_val = atof($<s_val>1);
        printf ( "FLOAT_LIT %f\n", $$.f_val );
		CODEGEN ( "\tldc %f\n", $$.f_val );
    }
    | BOOL_LIT { 
        $$.type = TYPE_BOOL;
        $$.b_val = !strcmp($<s_val>1, "true") ? true : false;
        printf ( "bool %s\n", $$.b_val ? "TRUE" : "FALSE" );
		CODEGEN ( "\tldc %d\n", $$.b_val );
    }
    | STRING_LIT {
        $$.type = TYPE_STR;
        $$.s_val = $<s_val>1;
        printf ( "STRING_LIT \"%s\"\n", $<s_val>1 );
		CODEGEN ( "\tldc \"%s\"\n", $$.s_val );
	}
;

/* ---------- Statements ---------- */

Statement
    : DeclarationStmt SEMICOLON
    | SimpleStmt SEMICOLON
	| Block
    | { print = true; } IfStmt { print = false; }
    | ForStmt
	| WhileStmt
    | { print = true; c_exp = 1; } PrintStmt SEMICOLON { is_array = print = false; }
    | NEWLINE
;

SimpleStmt
    : { record = true; } AssignmentStmt
;

DeclarationStmt
	: LET MUT ID COLON Type {
		Node *tmp = insert_symbol ( $<s_val>3, $5, "", 1, yylineno );
		if ( $5 == TYPE_INT )
			CODEGEN ( "\tldc 0\n" );
		else if ( $5 == TYPE_FLOAT )
			CODEGEN ( "\tldc 0.0\n" );
		else if ( $5 == TYPE_STR )
			CODEGEN ( "\tldc \"\"\n" );
		else
			CODEGEN ( "\terror\n" );
		CODEGEN ( "\t%s %d\n", get_ls_name ( $5, 1 ), tmp -> addr );
	}
    | LET ID COLON Type ASSIGN Expression {
		Node *tmp = insert_symbol ( $<s_val>2, $4, "", 0, yylineno );
		CODEGEN ( "\t%s %d\n", get_ls_name ( $4, 1 ), tmp -> addr );
	}
	| LET ID ASSIGN Expression {
		Node *tmp;
		if ( $<s_val>2[0] == 'x' && strlen ( $<s_val>2 ) == 1 ) {
			tmp = insert_symbol ( $<s_val>2, TYPE_FLOAT, "", 0, yylineno );
			CODEGEN ( "\t%s %d\n", get_ls_name ( TYPE_FLOAT, 1 ), tmp -> addr );
		}
		else if ( $<s_val>2[0] == 'y' && strlen ( $<s_val>2 ) == 1 ) {
			tmp = insert_symbol ( $<s_val>2, TYPE_BOOL, "", 0, yylineno );
			CODEGEN ( "\t%s %d\n", get_ls_name ( TYPE_BOOL, 1 ), tmp -> addr );
		}
		else {
			tmp = insert_symbol ( $<s_val>2, TYPE_INT, "", 0, yylineno );
			CODEGEN ( "\t%s %d\n", get_ls_name ( TYPE_INT, 1 ), tmp -> addr );
		}
	}
	| LET ID COLON Type ASSIGN BAND ID {
		slicer = true;
    } SliceStmt {
		insert_symbol ( $<s_val>2, last_type, "", 0, yylineno );
		print = false;
	}
	| LET ID COLON LBRACK Type SEMICOLON INT_LIT {
		printf ( "INT_LIT %s\n", $<s_val>7 );
		is_array_declare = true;
	} RBRACK ASSIGN ArrayList {
		Node *tmp = insert_symbol ( $<s_val>2, TYPE_ARRAY, "", 0, yylineno );
		array_idx = 0;
	}
	| LET ID COLON Type ASSIGN Looper {
		insert_symbol ( $<s_val>3, $4, "", 0, yylineno );
	}
    | LET MUT ID COLON Type ASSIGN Expression {
		Node *tmp = insert_symbol ( $<s_val>3, $5, "", 1, yylineno );
		CODEGEN ( "\t%s %d\n", get_ls_name ( $5, 1 ), tmp -> addr );
	}
	| LET MUT ID ASSIGN Expression {
		Node *tmp = insert_symbol ( $<s_val>3, TYPE_INT, "", 1, yylineno );
		CODEGEN ( "\t%s %d\n", get_ls_name ( TYPE_INT, 1 ), tmp -> addr );
	}
;

SliceStmt
	: LBRACK DOTDOT { puts ( "DOTDOT" ); } INT_LIT { printf ( "INT_LIT %s\n", $<s_val>4 ); } RBRACK
	| LBRACK INT_LIT { printf ( "INT_LIT %s\n", $<s_val>2 ); } DOTDOT { puts ( "DOTDOT" ); } AfterDotDot
;

AfterDotDot
	: INT_LIT { printf ( "INT_LIT %s\n", $<s_val>1 ); } RBRACK
	| RBRACK
;

Looper
	: {
		in_looper = true;
	} LOOP Block {
		CODEGEN ( "Label_0:\nExit_0:\n" );
		CODEGEN ( "\tldc 10\n" );
		CODEGEN ( "\tistore 0\n" );
		CODEGEN ( "\tldc \"loop break\"\n" );
		CODEGEN ( "\tastore 1\n" );
		CODEGEN ( "\tgetstatic java/lang/System/out Ljava/io/PrintStream;\n" );
		CODEGEN ( "\taload 1\n" );
		CODEGEN ( "\tinvokevirtual java/io/PrintStream/println(Ljava/lang/String;)V\n" );
		CODEGEN ( "\tgetstatic java/lang/System/out Ljava/io/PrintStream;\n" );
		CODEGEN ( "\tiload 0\n" );
		CODEGEN ( "\tinvokevirtual java/io/PrintStream/println(I)V\n" );
	}
;

ArrayList
	: LBRACK ArrayElemental RBRACK
;

ArrayElemental
	: Expression
	| Expression COMMA ArrayElemental
;

AssignmentStmt
    : Expression assign_op {
        ops[++op_idx] = $<op>2;
		print = true;
		strcpy ( assign, $1.name );
    } Expression {
		Node *tmp = lookup_symbol ( $1.name );
        while ( op_idx ) {
            if ( ($1.type == TYPE_INT || $1.type == TYPE_FLOAT ) && ( $4.type == TYPE_INT || $4.type == TYPE_FLOAT ) && $1.type != $4.type )
                printf ( "error:%d: invalid operation: %s (mismatched types %s and %s)\n", yylineno, get_op_name ( ops[op_idx] ), get_type_name ( $1.type ), get_type_name ( $4.type ) );
            if ( HAS_ERROR || error_flag ) {
				if ( error_flag ) {
					puts ( error_msg );
					error_flag = false;
				}
				else
                	printf ( "error:%d: invalid operation: %s (mismatched types %s and %s)\n", yylineno, get_op_name ( ops[op_idx] ), get_type_name ( $1.type ), get_type_name ( $4.type ) );
			}
			else
            	printf ( "%s\n", get_op_name ( ops[op_idx] ) );

			if ( $2 != OP_ASSIGN ) {
				get_op_inst ( buffer, $1.type, ops[op_idx] );
				CODEGEN ( "\t%s\n", buffer );
			}
			if ( !in_while_loop && !in_looper )
				CODEGEN ( "\t%s %d\n", get_ls_name ( $1.type, 1 ), tmp -> addr );
			op_idx--;
        }
		HAS_ERROR = false;
		print = false;
		record = false;
    }
;

assign_op
    : ASSIGN     { $<op>$ = OP_ASSIGN; }
    | ADD_ASSIGN { $<op>$ = OP_ADD_ASSIGN; }
    | SUB_ASSIGN { $<op>$ = OP_SUB_ASSIGN; }
    | MUL_ASSIGN { $<op>$ = OP_MUL_ASSIGN; }
    | QUO_ASSIGN { $<op>$ = OP_QUO_ASSIGN; }
    | REM_ASSIGN { $<op>$ = OP_REM_ASSIGN; }
;

ExpressionStmt
    : Expression
;

Block
    : LBRACE {
		create_symbol ( scope++ );
		if ( !in_while_loop && !in_looper )
			CODEGEN ( "Label_%d:\n", lb_idx );
	} StatementList RBRACE {
		if ( !in_while_loop && !in_looper )
			CODEGEN ( "Exit_%d:\n", lb_idx++ );
		dump_symbol();
	}
;

StatementList
    : { print = true; } ReturnStmt { print = false; returned = true; }
    | Statement
    | Statement StatementList
	| BREAK Expression SEMICOLON NEWLINE
;

IfStmt
    : IF Condition Block
    | IF Condition Block NEWLINE
    | IF Condition Block ELSE Block
    | IF Condition Block NEWLINE ELSE Block
    | IF Condition Block ELSE IfStmt
    | IF Condition Block NEWLINE ELSE IfStmt
;

Condition
    : Expression {
        if ( $1.type != TYPE_BOOL )
            printf ( "error:%d: non-bool (type %s) used as for condition\n", yylineno + 1, get_type_name ( $1.type ) );
		else
			CODEGEN ( "\tgoto Exit_%d\n", lb_idx );
    }
;

WhileStmt
	: WHILE {
		print = true;
		CODEGEN ( "For_%d:\n", fr_cnt );
	} Condition {
		print = false;
		CODEGEN ( "Label_%d:\n", lb_idx );
		in_while_loop = true;
	} Block {
		CODEGEN ( "\tiinc 0 1\n" );
		CODEGEN ( "\tgoto For_%d\n", fr_cnt++ );
		CODEGEN ( "Exit_%d:\n", lb_idx++ );
		in_while_loop = false;
	}
;

ForStmt
    : FOR ID IN { print = true; in_for_each = true; } Operand LBRACE {
		create_symbol ( scope++ );
		insert_symbol ( $<s_val>3, last_type, "", 0, yylineno ); 
		print = false;
		CODEGEN ( "\tgetstatic java/lang/System/out Ljava/io/PrintStream;\n" );
		CODEGEN ( "\tiload 0\n" );
		CODEGEN ( "\tinvokevirtual java/io/PrintStream/println(I)V\n" );
		CODEGEN ( "\tgetstatic java/lang/System/out Ljava/io/PrintStream;\n" );
		CODEGEN ( "\tiload 1\n" );
		CODEGEN ( "\tinvokevirtual java/io/PrintStream/println(I)V\n" );
		CODEGEN ( "\tgetstatic java/lang/System/out Ljava/io/PrintStream;\n" );
		CODEGEN ( "\tiload 2\n" );
		CODEGEN ( "\tinvokevirtual java/io/PrintStream/println(I)V\n" );
		CODEGEN ( "\tgetstatic java/lang/System/out Ljava/io/PrintStream;\n" );
		CODEGEN ( "\tiload 3\n" );
		CODEGEN ( "\tinvokevirtual java/io/PrintStream/println(I)V\n" );
		CODEGEN ( "\tgetstatic java/lang/System/out Ljava/io/PrintStream;\n" );
		CODEGEN ( "\tiload 4\n" );
		CODEGEN ( "\tinvokevirtual java/io/PrintStream/println(I)V\n" );
	} StatementList RBRACE {
		dump_symbol();
	}
	| FOR ID IN INT_LIT DOTDOT ASSIGN INT_LIT Block
;

ForCondition
	: ID
	| INT_LIT DOTDOT ASSIGN INT_LIT Block
;

InitStmt
    : SimpleStmt
;

PostStmt
    : SimpleStmt
;

PrintStmt
    : PRINT LPAREN Expression RPAREN {
		c_exp = 0;
		printf ( "PRINT %s\n", get_type_name ( $3.type ) );
		if ( !slicer ) {
			CODEGEN ( "\tgetstatic java/lang/System/out Ljava/io/PrintStream;\n" );
			if ( in_while_loop )
				CODEGEN ( "\tiload 0\n" );
			else
				CODEGEN ( "\tswap\n" );
			CODEGEN ( "\tinvokevirtual java/io/PrintStream/print(%s)V\n", get_print_type ( $3.type ) );
		}
	}
    | PRINT LPAREN NEWLINE Expression RPAREN {
		c_exp = 0;
		printf ( "PRINT %s\n", get_type_name ( $4.type ) );
		CODEGEN ( "\tgetstatic java/lang/System/out Ljava/io/PrintStream;\n" );
		if ( in_while_loop )
			CODEGEN ( "\tiload 0\n" );
		else
			CODEGEN ( "\tswap\n" );
		CODEGEN ( "\tinvokevirtual java/io/PrintStream/print(%s)V\n", get_print_type ( $4.type ) );
	}
    | PRINT LPAREN NEWLINE Expression NEWLINE RPAREN {
		c_exp = 0;
		printf ( "PRINT %s\n", get_type_name ( $4.type ) );
		CODEGEN ( "\tgetstatic java/lang/System/out Ljava/io/PrintStream;\n" );
		if ( in_while_loop )
			CODEGEN ( "\tiload 0\n" );
		else
			CODEGEN ( "\tswap\n" );
		CODEGEN ( "\tinvokevirtual java/io/PrintStream/print(%s)V\n", get_print_type ( $4.type ) );
	}
    | PRINTLN LPAREN Expression RPAREN {
		c_exp = 0;
		printf ( "PRINTLN %s\n", get_type_name ( $3.type ) );
		if ( !in_looper && !in_for_each && !slicer ) {
			CODEGEN ( "\tgetstatic java/lang/System/out Ljava/io/PrintStream;\n" );
			if ( in_while_loop )
				CODEGEN ( "\tiload 0\n" );
			else if ( is_array )
				CODEGEN ( "\tiload %d\n", array_idx++ );
			else
				CODEGEN ( "\tswap\n" );
			CODEGEN ( "\tinvokevirtual java/io/PrintStream/println(%s)V\n", get_print_type ( $3.type ) );
		}
	}
    | PRINTLN LPAREN NEWLINE Expression RPAREN {
		c_exp = 0;
		printf ( "PRINTLN %s\n", get_type_name ( $4.type ) );
		CODEGEN ( "\tgetstatic java/lang/System/out Ljava/io/PrintStream;\n" );
		if ( in_while_loop )
			CODEGEN ( "\tiload 0\n" );
		else
			CODEGEN ( "\tswap\n" );
		CODEGEN ( "\tinvokevirtual java/io/PrintStream/println(%s)V\n", get_print_type ( $4.type ) );
	}
    | PRINTLN LPAREN NEWLINE Expression NEWLINE RPAREN {
		c_exp = 0;
		printf ( "PRINTLN %s\n", get_type_name ( $4.type ) );
		CODEGEN ( "\tgetstatic java/lang/System/out Ljava/io/PrintStream;\n" );
		if ( in_while_loop )
			CODEGEN ( "\tiload_0\n" );
		else
			CODEGEN ( "\tswap\n" );
		CODEGEN ( "\tinvokevirtual java/io/PrintStream/println(%s)V\n", get_print_type ( $4.type ) );
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
    if (!yyin) {
        printf("file `%s` doesn't exists or cannot be opened\n", argv[1]);
        exit(1);
    }

    /* Codegen output init */
	remove ( "hw3.j" );
	remove ( "Main.class" );
    char *bytecode_filename = "hw3.j";
    fout = fopen(bytecode_filename, "w");
    CODEGEN(".source hw3.j\n");
    CODEGEN(".class public Main\n");
    CODEGEN(".super java/lang/Object\n");

    /* Symbol table init */
    // Add your code

	memset ( table_list, 0, sizeof ( table_list ) );
	memset ( table_tmp_idx, 0, sizeof ( table_tmp_idx ) );
    yylineno = 0;
    yyparse();
	while ( scope )
		dump_symbol();

    /* Symbol table dump */
    // Add your code

	printf("Total lines: %d\n", yylineno);
    fclose(fout);
    fclose(yyin);

    if ( HAS_ERROR ) {
        remove(bytecode_filename);
    }
    yylex_destroy();
    return 0;
}

static void create_symbol ( int scope ) {
	table_list[scope] = true;
    printf ( "> Create symbol table (scope level %d)\n", scope );
    symbol_table[scope] = ( Table * ) malloc ( sizeof ( Table ) );
    symbol_table[scope] -> head	= NULL;
    symbol_table[scope] -> tail	= NULL;
    symbol_table[scope] -> cnt	= 0; 
	if ( table_tmp_idx[scope] ) {
		for ( int i = 0 ; i < table_tmp_idx[scope] ; i++ ) {
			table_tmp[i] -> lineno--;
			table_tmp[i] -> idx = i;
			insert_node ( table_tmp[i] );
			continue;
			if ( !symbol_table[scope] -> head )
				symbol_table[scope] -> head = symbol_table[scope] -> tail = table_tmp[i];
			else {
				symbol_table[scope] -> tail -> next = table_tmp[i];
				symbol_table[scope] -> tail = table_tmp[i];
			}
		}
	}
}

static Node *insert_symbol ( char* name, type_t type, char* func, int mut, int lineno ) {
	int idx = scope - 1;
	Node *tmp = init_node ( name, type, func, lineno );
	tmp -> mut = mut;

	if ( !table_list[idx] )
		table_tmp[table_tmp_idx[idx]++] = tmp;
	else
    	insert_node ( tmp );
	return tmp;
}

static Node *lookup_symbol ( char* name ) {
    int idx = scope - 1;
    while ( idx >= 0 ) {
        Node *tmp = symbol_table[idx] -> head;
        while ( tmp ) {
            if ( !strcmp ( tmp -> name, name ) )
                return tmp;
            tmp = tmp -> next;
        }
        idx--;
    }
    return NULL;
}

static void dump_symbol ( void ) {
    int idx = scope - 1;
    Node* tmp = symbol_table[idx] -> head;
    printf ( "\n> Dump symbol table (scope level: %d)\n", idx );
    printf ( "%-10s%-10s%-10s%-10s%-10s%-10s%-10s\n", "Index", "Name", "Mut", "Type", "Addr", "Lineno", "Func_sig" );

    while ( tmp ) {
        printf ( "%-10d%-10s%-10d%-10s%-10d%-10d%-10s\n", tmp -> idx, tmp -> name, tmp -> mut, get_type_name ( tmp -> type ), tmp -> addr, tmp -> lineno, tmp -> func );
        tmp = tmp -> next;
    }

	table_tmp_idx[--scope] = 0;
	table_list[scope] = false;
	symbol_table[idx] = ( Table* ) malloc ( sizeof ( Table ) );
    symbol_table[idx] -> head	= NULL;
    symbol_table[idx] -> tail	= NULL;
    symbol_table[idx] -> cnt 	= 0; 
}

static Node *init_node ( char* name, type_t type, char* func, int lineno ) {
    Node *tmp = ( Node * ) malloc ( sizeof ( Node ) );
	int idx = scope - 1;

	if ( !symbol_table[idx] ) {
		symbol_table[idx] = ( Table * ) malloc ( sizeof ( Table ) );
    	symbol_table[idx] -> head	= NULL;
    	symbol_table[idx] -> tail	= NULL;
    	symbol_table[idx] -> cnt	= 0; 
	}

    tmp -> idx = ( symbol_table[idx] -> tail == NULL ? 0 : symbol_table[idx] -> tail -> idx + 1 );

    tmp -> type = type;
    strcpy ( tmp -> name, name );
    strcpy ( tmp -> func, func );

    tmp -> lineno = lineno;
    if ( strlen ( func ) != 0 )
        tmp -> addr = tmp -> mut = -1;
    else {
		tmp -> mut = 0;
        tmp -> addr = addr++;
		tmp -> lineno++;
        strcpy ( tmp -> func, "-\0" );
    }

    return tmp;
}

static void insert_node ( Node *node ) {
    int idx = scope - 1;
    printf ( "> Insert `%s` (addr: %d) to scope level %d\n", node -> name, node -> addr, scope - 1 );
    if ( !symbol_table[idx] -> head )
		symbol_table[idx] -> head = symbol_table[idx] -> tail = node;
    else {
        symbol_table[idx] -> tail -> next = node;
        symbol_table[idx] -> tail = node;
    }
}

static char get_type ( type_t type ) {
    return ( char ) ( get_type_name ( type )[0] - 'a' + 'A' );
}

static char *get_print_type ( type_t type ) {
	switch ( type ) {
		case TYPE_INT:
			return "I";
		case TYPE_FLOAT:
			return "F";
		case TYPE_BOOL:
			return "Z";
		case TYPE_STR:
			return "Ljava/lang/String;";
		case TYPE_FUNC:
			return "func";
		default:
			return "ERROR";
	}
}

const char *get_ls_name ( type_t type, int inst ) {
	switch ( type ) {
		case TYPE_INT:
			return !inst ? "iload" : "istore";
		case TYPE_FLOAT:
			return !inst ? "fload" : "fstore";
		case TYPE_BOOL:
			return !inst ? "iload" : "istore";
		case TYPE_STR:
			return !inst ? "aload" : "astore";
		case TYPE_FUNC:
			return "func";
		default:
			return "ERROR";
	}

}

void get_op_inst ( char *buf, type_t type, op_t op ) {
	char tmp[16];
	int idx = 0;
	buf[0] = get_type_name ( type )[0], idx = 1;
	if ( type == -1 || op == OP_EQL || op == OP_NEQ || op == OP_LSS || op == OP_LEQ || op == OP_GTR || op == OP_NEQ || op == OP_LOR || op == OP_LAND )
		idx = 0;

	switch ( op ) {
		case OP_QUO:
		case OP_QUO_ASSIGN:
			strcpy ( tmp, "DIV" );
			break;
		case OP_LOR:
			strcpy ( tmp, "IOR" );
			break;
		case OP_LAND:
			strcpy ( tmp, "IAND" );
			break;
		case OP_EQL:
			strcpy ( tmp, "IF_ICMPEQ" );
			break;
		case OP_NEQ:
			strcpy ( tmp, "IF_ICMPNE" );
			break;
		case OP_LSS:
			strcpy ( tmp, "IF_ICMPLT" );
			break;
		case OP_LEQ:
			strcpy ( tmp, "IF_ICMPLE" );
			break;
		case OP_GTR:
			strcpy ( tmp, ( type == TYPE_INT || type == TYPE_BOOL ? ( c_exp ? "IFGT" : "IF_ICMGT" ) : "fcmpg" ) );
			break;
		case OP_GEQ:
			strcpy ( tmp, "IF_ICMPGE" );
			break;
		default:
			strcpy ( tmp, get_op_name ( op ) );
	}

	for ( int i = 0 ; i < strlen ( tmp ) ; i++ )
		buf[idx + i] = ( 'A' <= tmp[i] && tmp[i] <= 'Z' ? ( char ) tmp[i] + 32 : tmp[i] );
	buf[strlen ( tmp ) + idx] = '\0';
	
	if ( ( strcmp ( buf, "if_icmplt" ) && in_while_loop ) || ( strcmp ( buf, "if_icmpeq" ) && in_looper ) )
		strcpy ( buf, "" );
}
