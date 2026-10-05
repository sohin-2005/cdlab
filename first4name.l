%{
#include <stdio.h>
%}

%option caseless

%%
.*name.*    { printf("REJECT\n"); }
.+          { printf("ACCEPT\n"); }
\n          ;
%%

int main()
{
    yylex();
    return 0;
}

int yywrap()
{
    return 1;
}
