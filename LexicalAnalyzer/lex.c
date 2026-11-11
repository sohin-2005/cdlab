
#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main() {
    char word[64];
    char *keywords[] = {"int", "float", "char", "if", "else",
                        "while", "for", "return", NULL};
    int ch, i, keyword;
    printf("Enter the input string: ");

    while ((ch = getchar()) != EOF) {

        if (isspace(ch))
            continue;


        if (isalpha(ch) || ch == '_') {
            i = 0;

            do {
                word[i++] = ch;
                ch = getchar();
            } while (isalnum(ch) || ch == '_');

            word[i] = '\0';

            if (ch != EOF)
                ungetc(ch, stdin);

            keyword = 0;

            for (i = 0; keywords[i] != NULL; i++) {
                if (strcmp(word, keywords[i]) == 0)
                    keyword = 1;
            }

            if (keyword)
                printf("KEYWORD\t%s\n", word);
            else
                printf("IDENTIFIER\t%s\n", word);
        }

        else if (isdigit(ch)) {
            i = 0;

            do {
                word[i++] = ch;
                ch = getchar();
            } while (isdigit(ch));

            word[i] = '\0';

            if (ch != EOF)
                ungetc(ch, stdin);

            printf("NUMBER\t%s\n", word);
        }
        else {
            printf("SYMBOL\t%c\n", ch);
        }
    }

    return 0;
}
