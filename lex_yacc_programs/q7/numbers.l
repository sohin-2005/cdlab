%{
#include <stdio.h>
int ints = 0, floats = 0;
%}
%option noyywrap
DIGIT [0-9]
%%
{DIGIT}+\.{DIGIT}+   { floats++; printf("%s : FLOAT\n", yytext); }
{DIGIT}+             { ints++;   printf("%s : INTEGER\n", yytext); }
[A-Za-z_][A-Za-z0-9_]*  { /* skip identifiers like x1 */ }
.|\n                 { }
%%
int main(void) {
    yylex();
    printf("\nIntegers: %d, Floats: %d\n", ints, floats);
    return 0;
}
