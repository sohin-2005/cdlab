
%{
#include <stdio.h>

int plus=0, minus=0, mul=0, div=0;
int mod=0, assign=0, equal=0;
%}

%%
"=="    equal++;
"+"     plus++;
"-"     minus++;
"*"     mul++;
"/"     div++;
"%"     mod++;
"="     assign++;
.       ;
\n      ;
%%

int main()
{
    printf("Enter an expression:\n");
    yylex();

    printf("\nOperator Count:\n");
    printf("+  : %d\n", plus);
    printf("-  : %d\n", minus);
    printf("*  : %d\n", mul);
    printf("/  : %d\n", div);
    printf("%%  : %d\n", mod);
    printf("=  : %d\n", assign);
    printf("== : %d\n", equal);

    return 0;
}
