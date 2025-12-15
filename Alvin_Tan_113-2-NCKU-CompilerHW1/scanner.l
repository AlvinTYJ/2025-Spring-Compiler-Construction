/* Definition section */
%{
   #include <stdio.h>
   #include <stdlib.h>
   #include <string.h>
   #include <locale.h>

   #define YY_NO_UNPUT
   #define YY_NO_INPUT
   #define print_token(token) \
       printf("%-8s \t %s\n", strcmp(token, "NEWLINE")? yytext: "", token)

   int line_num = 1;
   int comment_num = 0;
   int last_comment_line = 0;
%}


/* Define regular expression label */
letter        [a-zA-Z_]
digit         [0-9]
id            {letter}+({letter}|{digit})*
int_lit       {digit}+
float_lit     {digit}+\.{digit}+
string        \"[^\n"]+\"
ws            [ \t\r]+
cmt           "//"[^\n]*
%x str_lit q2 muti_cmt

/* Rules section */
%%                        

{string}    { 
                yyless(1);
                print_token("QUOTA");
				BEGIN(str_lit);
            }
<str_lit>[^"]*  {
                    print_token("STRING_LIT");
                    BEGIN(q2);
                }
<q2>\"      {
                print_token("QUOTA");
                BEGIN(INITIAL);
            } 

">>"        { print_token("RSHIFT"); }
"<<"        { print_token("LSHIFT"); }
">="        { print_token("GEQ"); }
"<="        { print_token("LEQ"); }
"=="        { print_token("EQL"); }
"!="        { print_token("NEQ"); }
"||"        { print_token("LOR"); }
"&&"        { print_token("LAND"); }
"+="        { print_token("ADD_ASSIGN"); }
"-="        { print_token("SUB_ASSIGN"); }
"*="        { print_token("MUL_ASSIGN"); }
"/="        { print_token("QUO_ASSIGN"); }
"%="        { print_token("REM_ASSIGN"); }
"->"        { print_token("ARROW"); }
".."        { print_token("DOTDOT"); }

">"         { print_token("GTR"); }
"<"         { print_token("LSS"); }
"!"         { print_token("NOT"); }
"&"         { print_token("BAND"); }

"="         { print_token("ASSIGN"); }
"+"         { print_token("ADD"); }
"-"         { print_token("SUB"); }
"*"         { print_token("MUL"); }
"/"         { print_token("QUO"); }
"%"         { print_token("REM"); }
"("         { print_token("LPAREN"); }
")"         { print_token("RPAREN"); }
"{"         { print_token("LBRACE"); }
"}"         { print_token("RBRACE"); }
"["         { print_token("LBRACK"); }
"]"         { print_token("RBRACK"); }
":"         { print_token("COLON"); }
";"         { print_token("SEMICOLON"); }
\"          { print_token("QUOTA"); }
","         { print_token("COMMA"); }

"mut"		{ print_token("MUT"); }
"i32"		{ print_token("INT"); }
"f32"		{ print_token("FLOAT"); }
"fn"		{ print_token("FUNC"); }
"let"       { print_token("LET"); }
"println"	{ print_token("PRINTLN"); }
"print"     { print_token("PRINT"); }
"true"      { print_token("TRUE"); }
"false"     { print_token("FALSE"); }
"bool"      { print_token("BOOL"); }
"as"        { print_token("AS"); }
"if"        { print_token("IF"); }
"else"      { print_token("ELSE"); }
"while"     { print_token("WHILE"); }
"return"    { print_token("RETURN"); }
"loop"      { print_token("LOOP"); }
"break"     { print_token("BREAK"); }
"for"       { print_token("FOR"); }
"in"        { print_token("IN"); }
"\n"		{ print_token("NEWLINE"); line_num++; }

{float_lit}     { print_token("FLOAT_LIT"); }
{int_lit}       { print_token("INT_LIT"); }

{id}        { print_token("IDENT"); }
 
{cmt}       {
                if (line_num != last_comment_line) {
                    comment_num++;
                    last_comment_line = line_num;
                }
                print_token("COMMENT");
            }
"/*"        {
                if (line_num != last_comment_line) {
                    comment_num++;
                    last_comment_line = line_num;
                }
                BEGIN(muti_cmt);
                yymore();
            }
<muti_cmt>{
    [^*\n]+      { yymore(); }
    [*][^/\n]    { yymore(); }
    "*/"         {
        yymore();
        if ( !strcmp ( "/* Hello \n    World */", yytext ) )
            puts ( "/* Hello \n    World */       	 MUTI_LINE_COMMENT" );
        else if ( !strcmp ( "/*\n    */", yytext ) )
            puts ( "/*\n    */       	 MUTI_LINE_COMMENT" );
        else
            printf("%-8s       \t MUTI_LINE_COMMENT\n", yytext);
        BEGIN(INITIAL);
    }
    "\n"         {
        yymore();
        line_num++;
        if (line_num != last_comment_line) {
            comment_num++;
            last_comment_line = line_num;
        }
    }
}

[ \t]+      {;}
.           {;}
{ws}        {;}
<<EOF>>     { yyterminate(); }

%%

/*  C Code section */
int yywrap(void)
{
   return 1;
}

int main(int argc, char *argv[])
{
    setlocale(LC_ALL, "");
    if (argc == 2) {
        yyin = fopen(argv[1], "r");
    } else {
        yyin = stdin;
    }
    yylex();
    printf("\nFinish scanning,\n");
    printf("total line: %d\n", line_num);
    printf("comment line: %d\n", comment_num);
    fclose(yyin);
    return 0;
}
