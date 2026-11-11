%{
#include <stdio.h>
int yylex(void);
void yyerror(const char *s);
%}
%token ID NUM
%%
input : /* empty */
      | input line
      ;
line  : stmt '\n'      { printf("Valid assignment\n"); }
      | '\n'
      | error '\n'     { printf("Invalid assignment\n"); yyerrok; }
      ;
stmt  : ID '=' operand '+' operand ';'
      ;
operand : ID
        | NUM
        ;
%%
void yyerror(const char *s) { }
int main(void) {
    printf("Enter assignment statements (Ctrl+D to quit):\n");
    yyparse();
    return 0;
}
