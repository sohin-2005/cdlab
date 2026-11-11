%{
#include "y.tab.h"
%}
%option noyywrap
%%
[0-9]+(\.[0-9]+)?  { return NUM; }
"+"                { return '+'; }
"-"                { return '-'; }
"*"                { return '*'; }
"/"                { return '/'; }
"("                { return '('; }
")"                { return ')'; }
[ \t]              { }
\n                 { return '\n'; }
.                  { return yytext[0]; }   /* unknown char -> syntax error */
%%
