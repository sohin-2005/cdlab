%{
#include <stdlib.h>
<<<<<<< HEAD
#define YYSTYPE double      /* every value passed between lex and yacc is a double */
#include "y.tab.h"
%}
%%
  /* a number such as 12 or 3.5: store its value in yylval, tell yacc it is N */
[0-9]+(\.[0-9]+)?   { yylval = atof(yytext); return N; }
  /* skip spaces and tabs */
[ \t]               ;
  /* + - * / ( ) and newline are passed to yacc as themselves */
=======
#define YYSTYPE double
#include "y.tab.h"
%}
%%
[0-9]+(\.[0-9]+)?   { yylval = atof(yytext); return N; }
[ \t]               ;
>>>>>>> dd1b794c26d7a86b2665e2346bf40670532c01b9
.|\n                { return yytext[0]; }
%%
int yywrap(void) {
    return 1;
}
