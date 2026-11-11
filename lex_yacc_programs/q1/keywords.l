%{
#include <stdio.h>
%}
%option noyywrap
%%
"auto"|"break"|"case"|"char"|"const"|"continue"|"default"|"do"|"double"|"else"|"enum"|"extern"|"float"|"for"|"goto"|"if"|"inline"|"int"|"long"|"register"|"return"|"short"|"signed"|"sizeof"|"static"|"struct"|"switch"|"typedef"|"union"|"unsigned"|"void"|"volatile"|"while"  { printf("KEYWORD: %s\n", yytext); }
[A-Za-z_][A-Za-z0-9_]*   { /* identifier: ignore */ }
.|\n                     { /* ignore everything else */ }
%%
int main(void) {
    yylex();
    return 0;
}
