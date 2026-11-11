
#include <stdio.h>
#include <stdlib.h>

char ip[50];
int pos = 0;

void E();
void E1();
void T();
void T1();
void F();

void error()
{
    printf("\nSyntax Error");
    exit(0);
}

void match(char ch)
{
    if(ip[pos] == ch)
        pos++;
    else
        error();
}

void E()
{
    printf("E -> T E'\n");
    T();
    E1();
}

void E1()
{
    if(ip[pos] == '+')
    {
        printf("E' -> + T E'\n");
        match('+');
        T();
        E1();
    }
    else
        printf("E' -> e\n");
}

void T()
{
    printf("T -> F T'\n");
    F();
    T1();
}

void T1()
{
    if(ip[pos] == '*')
    {
        printf("T' -> * F T'\n");
        match('*');
        F();
        T1();
    }
    else
        printf("T' -> e\n");
}

void F()
{
    if(ip[pos] == 'i' || ip[pos] == 'I')
    {
        printf("F -> i\n");
        pos++;
    }
    else if(ip[pos] == '(')
    {
        printf("F -> ( E )\n");
        match('(');
        E();
        match(')');
    }
    else
        error();
}

int main()
{
    printf("Enter input expression: ");
    scanf("%s", ip);

    printf("\nProduction rules:\n");

    E();

    if(ip[pos] == '\0')
        printf("\nString Accepted");
    else
        printf("\nSyntax Error");

    return 0;
}
