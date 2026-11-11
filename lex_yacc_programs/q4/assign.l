%{
#include "y.tab.h"
%}
%option noyywrap
%%
[0-9]+             { return NUM; }
[A-Za-z_][A-Za-z0-9_]*  { return ID; }
"="                { return '='; }
"+"                { return '+'; }
";"                { return ';'; }
[ \t]              { }
\n                 { return '\n'; }
.                  { return yytext[0]; }
%%
