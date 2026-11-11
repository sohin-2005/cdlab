%{
#include "y.tab.h"
%}
%option noyywrap
%%
"if"               { return IF; }
[0-9]+             { return NUM; }
[A-Za-z_][A-Za-z0-9_]*  { return ID; }
"<="|">="|"=="|"!="|"<"|">"  { return RELOP; }
"="                { return '='; }
"("                { return '('; }
")"                { return ')'; }
";"                { return ';'; }
[ \t]              { }
\n                 { return '\n'; }
.                  { return yytext[0]; }
%%
