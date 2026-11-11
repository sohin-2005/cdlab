#include <stdio.h>
#include <ctype.h>
#include <string.h>
int main(void) {
    char *keywords[] = {"int", "float", "char", "if", "else", "while", "for", "return", NULL};
    char word[64];
    int ch, len, i, is_keyword;
    while ((ch = getchar()) != EOF) {
        if (isspace(ch)) {
            continue;
        }
        if (isalpha(ch) || ch == '_') {
            len = 0;
            while ((isalnum(ch) || ch == '_') && len < 63) {
                word[len++] = ch;
                ch = getchar();
            }
            if (isalnum(ch) || ch == '_') {
                fputs("Identifier exceeds 63 characters\n", stderr);
                return 1;
            }
            word[len] = '\0';
            if (ch != EOF) ungetc(ch, stdin);
            is_keyword = 0;
            for (i = 0; keywords[i] != NULL; i++) {
                if (strcmp(word, keywords[i]) == 0) {
                    is_keyword = 1;
                }
            }
            printf("%s\t%s\n", is_keyword ? "KEYWORD" : "IDENTIFIER", word);
        }
        else if (isdigit(ch)) {
            len = 0;
            while (isdigit(ch) && len < 63) {
                word[len++] = ch;
                ch = getchar();
            }
            if (isdigit(ch)) {
                fputs("Number exceeds 63 characters\n", stderr);
                return 1;
            }
            word[len] = '\0';
            if (ch != EOF) ungetc(ch, stdin);
            printf("NUMBER\t%s\n", word);
        }

        else {
            printf("SYMBOL\t%c\n", ch);
        }
    }
    return 0;
}
