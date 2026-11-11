%{
#include <stdlib.h>
#include "y.tab.h"
%}
%option noyywrap
%%
[0-9]+   { yylval = atoi(yytext); return NUM; }
"+"      { return '+'; }
"-"      { return '-'; }
[ \t]    { }
\n       { return '\n'; }
.        { return yytext[0]; }
%%
