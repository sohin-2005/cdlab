
#include <stdio.h>
#include <string.h>

int main() {
    char stack[100], input[100];
    char table[10][10], ter[10];
    int n, i, j, top = 0, row, col;

    printf("Enter number of terminals: ");
    scanf("%d", &n);

    printf("Enter terminals: ");
    scanf("%s", ter);

    printf("Enter precedence table:\n");

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            printf("%c and %c: ", ter[i], ter[j]);
            scanf(" %c", &table[i][j]);
        }
    }

    printf("Enter input string (end with $): ");
    scanf("%s", input);

    stack[top] = '$';
    stack[top + 1] = '\0';

    i = 0;

    printf("\nSTACK\t\tINPUT\t\tACTION\n");

    while (1) {
        row = -1;
        col = -1;


        for (j = 0; j < n; j++) {
            if (stack[top] == ter[j])
                row = j;

            if (input[i] == ter[j])
                col = j;
        }

        if (row == -1 || col == -1) {
            printf("String Rejected\n");
            break;
        }

    
        if (stack[top] == '$' && input[i] == '$') {
            printf("String Accepted\n");
            break;
        }

     
        if (table[row][col] == '<' ||
            table[row][col] == '=') {

            stack[++top] = table[row][col];
            stack[++top] = input[i++];
            stack[top + 1] = '\0';

            printf("%s\t\t%s\t\tShift\n",
                   stack, input + i);
        }

        
        else if (table[row][col] == '>') {

            while (top > 0 && stack[top] != '<')
                top--;

            if (top == 0) {
                printf("String Rejected\n");
                break;
            }

            top--;
            stack[top + 1] = '\0';

            printf("%s\t\t%s\t\tReduce\n",
                   stack, input + i);
        }

        else {
            printf("String Rejected\n");
            break;
        }
    }

    return 0;
}
