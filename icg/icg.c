
#include <stdio.h>
#include <ctype.h>
#include <string.h>

char op_stack[20];
char val_stack[20][10];
int top = -1, vtop = -1, temp = 1;

int precedence(char op)
{
    if(op == '*' || op == '/')
        return 2;

    if(op == '+' || op == '-')
        return 1;

    return 0;
}

void generate()
{
    char op, a[10], b[10], t[10];

    op = op_stack[top--];

    strcpy(b, val_stack[vtop--]);
    strcpy(a, val_stack[vtop--]);

    sprintf(t, "t%d", temp++);

    printf("%s = %s %c %s\n", t, a, op, b);

    strcpy(val_stack[++vtop], t);
}

int main()
{
    char expr[50];
    char result[10];
    int i;

    printf("Enter result variable: ");
    scanf("%9s", result);

    printf("Enter arithmetic expression: ");
    scanf("%49s", expr);

    printf("\nInput Expression: %s = %s\n", result, expr);

    printf("\nThree Address Code:\n");

    for(i = 0; expr[i] != '\0'; i++)
    {
        if(isalnum(expr[i]))
        {
            val_stack[++vtop][0] = expr[i];
            val_stack[vtop][1] = '\0';
        }
        else
        {
            while(top != -1 &&
                  precedence(op_stack[top]) >= precedence(expr[i]))
            {
                generate();
            }

            op_stack[++top] = expr[i];
        }
    }

    while(top != -1)
        generate();

    printf("%s = %s\n", result, val_stack[vtop]);

    return 0;
}
