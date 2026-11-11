
#include <stdio.h>

int main()
{
    int n, t, i, j, k;
    int a[20][20] = {0};
    int from, to;
    char ch;

    printf("Enter number of states and transitions: ");
    scanf("%d%d", &n, &t);

    printf("Enter transitions (from symbol to):\n");

    for(i = 0; i < t; i++)
    {
        scanf("%d %c %d", &from, &ch, &to);

        if(ch == 'e')
            a[from][to] = 1;
    }

    // Every state belongs to its own closure
    for(i = 0; i < n; i++)
        a[i][i] = 1;

    // Find epsilon closure
    for(k = 0; k < n; k++)
    {
        for(i = 0; i < n; i++)
        {
            for(j = 0; j < n; j++)
            {
                if(a[i][k] == 1 && a[k][j] == 1)
                    a[i][j] = 1;
            }
        }
    }

    // Print epsilon closure
    for(i = 0; i < n; i++)
    {
        printf("E-closure(q%d) = { ", i);

        for(j = 0; j < n; j++)
        {
            if(a[i][j] == 1)
                printf("q%d ", j);
        }

        printf("}\n");
    }

    return 0;
}


4 4

0 e 1
1 e 2
2 a 3
3 e 0
