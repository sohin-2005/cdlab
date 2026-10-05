%{
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "y.tab.h"
static char *copy_text(const char *s) {
    char *p = malloc(strlen(s) + 1);
    if (!p) { fputs("Out of memory\n", stderr); exit(EXIT_FAILURE); }
    strcpy(p, s);
    return p;
}
%}
%%
[a-zA-Z_][a-zA-Z0-9_]*|[0-9]+   { yylval.text = copy_text(yytext);
                                  return isdigit(yytext[0]) ? NUM : ID; }
[ \t]                           ;
.|\n                            { return yytext[0]; }
%%
int yywrap(void) {
    return 1;
}
