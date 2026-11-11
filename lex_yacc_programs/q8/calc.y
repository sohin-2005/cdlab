%{
#include <stdio.h>
int yylex(void);
void yyerror(const char *s);
%}
%token NUM
%%
input : /* empty */
      | input line
      ;
line  : E '\n'      { printf("Result = %d\n", $1); }
      | '\n'
      | error '\n'  { printf("Invalid expression\n"); yyerrok; }
      ;
E : E '+' NUM   { $$ = $1 + $3; }
  | E '-' NUM   { $$ = $1 - $3; }
  | NUM         { $$ = $1; }
  ;
%%
void yyerror(const char *s) { }
int main(void) {
    printf("Enter expressions with + and - (Ctrl+D to quit):\n");
    yyparse();
    return 0;
}
