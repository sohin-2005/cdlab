
#include <stdio.h>
#include <ctype.h>
#include <string.h>

int n, count = 0;
char prod[10][10], result[20];

void first(char c);
void follow(char c);

int main()
{
    int i, choice;
    char c;

    printf("Enter number of productions: ");
    scanf("%d", &n);

    printf("Enter productions (Example: S=aA):\n");
    for(i = 0; i < n; i++)
        scanf("%s", prod[i]);

    do
    {
        count = 0;

        printf("\nEnter the non-terminal: ");
        scanf(" %c", &c);

        first(c);

        printf("FIRST(%c) = { ", c);
        for(i = 0; i < count; i++)
            printf("%c ", result[i]);
        printf("}\n");

        count = 0;
        follow(c);

        printf("FOLLOW(%c) = { ", c);
        for(i = 0; i < count; i++)
            printf("%c ", result[i]);
        printf("}\n");

        printf("\nContinue? (1 = Yes, 0 = No): ");
        scanf("%d", &choice);

    } while(choice == 1);

    return 0;
}

void first(char c)
{
    int i;

    if(!isupper(c))
    {
        result[count++] = c;
        return;
    }

    for(i = 0; i < n; i++)
    {
        if(prod[i][0] == c)
        {
            if(prod[i][2] == '$')
                follow(prod[i][0]);
            else if(!isupper(prod[i][2]))
                result[count++] = prod[i][2];
            else
                first(prod[i][2]);
        }
    }
}

void follow(char c)
{
    int i, j;

    if(prod[0][0] == c)
        result[count++] = '$';

    for(i = 0; i < n; i++)
    {
        for(j = 2; j < strlen(prod[i]); j++)
        {
            if(prod[i][j] == c)
            {
                if(prod[i][j+1] != '\0')
                    first(prod[i][j+1]);

                if(prod[i][j+1] == '\0' && prod[i][0] != c)
                    follow(prod[i][0]);
            }
        }
    }
}
