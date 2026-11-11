
#include <stdio.h>
#include <string.h>

char input[50], stack[50];
int top = -1;

void reduce()
{
    int changed = 1;

    while(changed)
    {
        changed = 0;

        // Reduce id to E
        if(top >= 1 && stack[top-1] == 'i' && stack[top] == 'd')
        {
            stack[top-1] = 'E';
            top--;
            changed = 1;
        }

        // Reduce E+E to E
        else if(top >= 2 && stack[top-2] == 'E' &&
                stack[top-1] == '+' && stack[top] == 'E')
        {
            stack[top-2] = 'E';
            top -= 2;
            changed = 1;
        }

        // Reduce E*E to E
        else if(top >= 2 && stack[top-2] == 'E' &&
                stack[top-1] == '*' && stack[top] == 'E')
        {
            stack[top-2] = 'E';
            top -= 2;
            changed = 1;
        }

        // Reduce (E) to E
        else if(top >= 2 && stack[top-2] == '(' &&
                stack[top-1] == 'E' && stack[top] == ')')
        {
            stack[top-2] = 'E';
            top -= 2;
            changed = 1;
        }

        stack[top+1] = '\0';

        if(changed)
            printf("%s\t\tREDUCE\n", stack);
    }
}

int main()
{
    int i = 0;

    printf("Enter input string: ");
    scanf("%s", input);

    printf("\nSTACK\t\tACTION\n");

    while(input[i] != '\0')
    {
        // SHIFT
        if(input[i] == 'i' && input[i+1] == 'd')
        {
            stack[++top] = 'i';
            stack[++top] = 'd';
            i += 2;
        }
        else
        {
            stack[++top] = input[i];
            i++;
        }

        stack[top+1] = '\0';

        printf("%s\t\tSHIFT\n", stack);

        // REDUCE
        reduce();
    }

    if(top == 0 && stack[0] == 'E')
        printf("\nString Accepted\n");
    else
        printf("\nString Rejected\n");

    return 0;
}
id+id*id
E -> E + E
    E -> E * E
    E -> ( E )
    E -> id
