
#include <stdio.h>

int main() {
    int n, t, i, j, k;
    int a[20][20] = {0};
    int from, to;
    char ch;

    printf("Enter number of states and transitions: ");
    scanf("%d %d", &n, &t);

  
    printf("Enter transitions (from symbol to):\n");

    for (i = 0; i < t; i++) {
        scanf("%d %c %d", &from, &ch, &to);

        if (ch == 'e')
            a[from][to] = 1;
    }

   
    for (i = 0; i < n; i++)
        a[i][i] = 1;

    for (k = 0; k < n; k++) {
        for (i = 0; i < n; i++) {
            for (j = 0; j < n; j++) {
                if (a[i][k] && a[k][j])
                    a[i][j] = 1;
            }
        }
    }


    for (i = 0; i < n; i++) {
        printf("E-closure(q%d) = { ", i);

        for (j = 0; j < n; j++) {
            if (a[i][j])
                printf("q%d ", j);
        }

        printf("}\n");
    }

    return 0;
}
