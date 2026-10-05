%{
#include <stdio.h>
#define YYSTYPE double
int yylex(void);
void yyerror(const char *msg) {
    (void)msg;
    puts("error");
}
%}
%token N
%left '+' '-'
%left '*' '/'
%right UMINUS
%%
input : input expr '\n'     { printf("= %g\n", $2); }
      | input error '\n'    { yyerrok; }
      |
      ;
expr  : expr '+' expr       { $$ = $1 + $3; }
      | expr '-' expr       { $$ = $1 - $3; }
      | expr '*' expr       { $$ = $1 * $3; }
      | expr '/' expr       { if ($3 == 0) {
                                  puts("division by zero");
                                  YYERROR;
                              }
                              $$ = $1 / $3; }
      | '(' expr ')'        { $$ = $2; }
      | '-' expr %prec UMINUS { $$ = -$2; }
      | N
      ;
%%
int main(void) {
    return yyparse();
}
