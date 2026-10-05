%{
#include <stdio.h>
int yylex(void);
void yyerror(const char *msg) {
    (void)msg;
    puts("Invalid FOR statement");
}
%}
%token FOR T ID NUM REL INC
%left '+' '-'
%left '*' '/'
%%
for_stmt : FOR '(' init ';' cond ';' update ')' body '\n'
                { puts("Valid FOR statement"); YYACCEPT; }
         ;
init   : ID '=' expr
       | T ID '=' expr
       |
       ;
cond   : expr REL expr
       |
       ;
update : ID INC
       | ID '=' expr
       |
       ;
expr   : expr '+' expr
       | expr '-' expr
       | expr '*' expr
       | expr '/' expr
       | ID
       | NUM
       ;
body   : ';'
       | '{' stmts '}'
       ;
stmts  : stmts ID '=' expr ';'
       |
       ;
%%
int main(void) {
    return yyparse();
}
