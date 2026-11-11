%{
#include <stdio.h>
int plus=0, minus=0, mul=0, divi=0, mod=0, assign=0, eq=0;
%}
%option noyywrap
%%
"=="   { eq++; }
"="    { assign++; }
"+"    { plus++; }
"-"    { minus++; }
"*"    { mul++; }
"/"    { divi++; }
"%"    { mod++; }
.|\n   { }
%%
int main(void) {
    yylex();
    if (plus)   printf("+  : %d\n", plus);
    if (minus)  printf("-  : %d\n", minus);
    if (mul)    printf("*  : %d\n", mul);
    if (divi)   printf("/  : %d\n", divi);
    if (mod)    printf("%%  : %d\n", mod);
    if (assign) printf("=  : %d\n", assign);
    if (eq)     printf("== : %d\n", eq);
    printf("Total operators: %d\n", plus+minus+mul+divi+mod+assign+eq);
    return 0;
}
