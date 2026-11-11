
#include <stdio.h>

int main()
{
    int n, t, noalpha, n_final;
    int i, j, k, a, q, r, w;
    int e[20][20] = {0};
    int trans[20][10][20] = {0};
    int final[20] = {0};
    int result[20];
    char alpha[10], ch;
    int from, to;

    printf("Enter number of states and transitions: ");
    scanf("%d %d", &n, &t);

    printf("Enter number of alphabets: ");
    scanf("%d", &noalpha);

    printf("Enter alphabets: ");
    for(i = 0; i < noalpha; i++)
        scanf(" %c", &alpha[i]);

    printf("Enter transitions (from symbol to):\n");

    for(i = 0; i < t; i++)
    {
        scanf("%d %c %d", &from, &ch, &to);

        if(ch == 'e')
            e[from][to] = 1;
        else
        {
            for(a = 0; a < noalpha; a++)
            {
                if(alpha[a] == ch)
                    trans[from][a][to] = 1;
            }
        }
    }

    /* Calculate E-closure */

    for(i = 0; i < n; i++)
        e[i][i] = 1;

    for(k = 0; k < n; k++)
    {
        for(i = 0; i < n; i++)
        {
            for(j = 0; j < n; j++)
            {
                if(e[i][k] && e[k][j])
                    e[i][j] = 1;
            }
        }
    }

    printf("\nE-closure of states:\n");

    for(i = 0; i < n; i++)
    {
        printf("E-closure(q%d) = { ", i);

        for(j = 0; j < n; j++)
        {
            if(e[i][j])
                printf("q%d ", j);
        }

        printf("}\n");
    }

    /* Find transitions without epsilon */

    printf("\nNFA without Epsilon transitions:\n");

    for(i = 0; i < n; i++)
    {
        for(a = 0; a < noalpha; a++)
        {
            for(j = 0; j < n; j++)
                result[j] = 0;

            for(q = 0; q < n; q++)
            {
                if(e[i][q])
                {
                    for(r = 0; r < n; r++)
                    {
                        if(trans[q][a][r])
                        {
                            for(w = 0; w < n; w++)
                            {
                                if(e[r][w])
                                    result[w] = 1;
                            }
                        }
                    }
                }
            }

            printf("delta'(q%d, %c) = { ", i, alpha[a]);

            for(j = 0; j < n; j++)
            {
                if(result[j])
                    printf("q%d ", j);
            }

            printf("}\n");
        }
    }

    /* Find new final states */

    printf("\nEnter number of final states: ");
    scanf("%d", &n_final);

    printf("Enter final states: ");

    for(i = 0; i < n_final; i++)
    {
        scanf("%d", &from);
        final[from] = 1;
    }

    printf("\nNew Final States: { ");

    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n; j++)
        {
            if(e[i][j] && final[j])
            {
                printf("q%d ", i);
                break;
            }
        }
    }

    printf("}\n");

    return 0;
}
