%{
#include <stdio.h>
int single = 0, multi = 0;
%}
%option noyywrap
%%
"//".*                          { single++; printf("Single-line comment: %s\n", yytext); }
"/*"([^*]|\*+[^*/])*\*+"/"      { multi++;  printf("Multi-line comment:\n%s\n", yytext); }
.|\n                            { }
%%
int main(void) {
    yylex();
    printf("\nSingle-line comments : %d\n", single);
    printf("Multi-line comments  : %d\n", multi);
    return 0;
}
