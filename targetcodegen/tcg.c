
#include <stdio.h>
#include <string.h>

int main()
{
    char code[10][30];
    char op[10];
    int i = 0;

    printf("Enter intermediate code (type exit to stop):\n");

    do
    {
        scanf("%s", code[i]);
    } while(strcmp(code[i++], "exit") != 0);

    printf("\nTarget Code:\n");

    i = 0;

    while(strcmp(code[i], "exit") != 0)
    {
        switch(code[i][3])
        {
            case '+': strcpy(op, "ADD"); break;
            case '-': strcpy(op, "SUB"); break;
            case '*': strcpy(op, "MUL"); break;
            case '/': strcpy(op, "DIV"); break;
            default:  strcpy(op, "INVALID"); break;
        }

        printf("MOV R%d, %c\n", i, code[i][2]);
        printf("%s R%d, %c\n", op, i, code[i][4]);
        printf("MOV %c, R%d\n", code[i][0], i);

        i++;
    }

    return 0;
}
