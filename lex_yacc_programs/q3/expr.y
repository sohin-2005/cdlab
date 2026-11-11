%{
#include <stdio.h>
#include <stdlib.h>
int yylex(void);
void yyerror(const char *s);
int ok = 1;
%}
%token NUM
%%
input : /* empty */
      | input line
      ;
line  : E '\n'        { if (ok) printf("Valid expression\n"); ok = 1; }
      | '\n'
      | error '\n'    { printf("Invalid expression\n"); ok = 1; yyerrok; }
      ;
E : E '+' T
  | E '-' T
  | T
  ;
T : T '*' F
  | T '/' F
  | F
  ;
F : '(' E ')'
  | NUM
  ;
%%
void yyerror(const char *s) { /* message printed by 'error' rule */ }
int main(void) {
    printf("Enter expressions (Ctrl+D to quit):\n");
    yyparse();
    return 0;
}
