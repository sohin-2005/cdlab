%{
#include <stdio.h>
int yylex(void);
void yyerror(const char *s);
%}
%token IF ID NUM RELOP
%%
input : /* empty */
      | input line
      ;
line  : stmt '\n'     { printf("Valid IF statement\n"); }
      | '\n'
      | error '\n'    { printf("Invalid IF statement\n"); yyerrok; }
      ;
stmt  : IF '(' cond ')' body
      ;
body  : assign
      | stmt                 /* nested if:  stmt -> if (condition) stmt */
      ;
assign : ID '=' operand ';'
       ;
cond  : operand RELOP operand
      | operand               /* e.g. if(a) */
      ;
operand : ID
        | NUM
        ;
%%
void yyerror(const char *s) { }
int main(void) {
    printf("Enter IF statements (Ctrl+D to quit):\n");
    yyparse();
    return 0;
}
