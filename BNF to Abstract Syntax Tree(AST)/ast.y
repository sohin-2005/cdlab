%{
#include <stdio.h>
#include <stdlib.h>
typedef struct node {
    const char *label;
    struct node *left, *right;
} Node;
Node *make_node(const char *label, Node *left, Node *right) {
    Node *p = malloc(sizeof(Node));
    if (p == NULL) {
        fputs("Out of memory\n", stderr);
        exit(EXIT_FAILURE);
    }
    p->label = label;
    p->left = left;
    p->right = right;
    return p;
}
void free_tree(Node *p) {
    if (p == NULL) return;
    free_tree(p->left);
    free_tree(p->right);
    if (p->left == NULL && p->right == NULL) free((void *)p->label);
    free(p);
}
void print_tree(Node *p, int depth) {
    if (p == NULL) {
        return;
    }
    print_tree(p->right, depth + 1);
    printf("%*s%s\n", depth * 4, "", p->label);
    print_tree(p->left, depth + 1);
}
int yylex(void);
void yyerror(const char *msg) {
    (void)msg;
    puts("syntax error");
}
%}
%union {
    char *text;
    struct node *node;
}
%token <text> ID NUM
%type <node> expr term factor
%destructor { free($$); } <text>
%destructor { free_tree($$); } <node>
%%
lines : lines expr '\n'     { print_tree($2, 0); puts("-----"); free_tree($2); }
      | lines error '\n'    { yyerrok; }
      |
      ;
expr   : expr '+' term      { $$ = make_node("+", $1, $3); }
       | expr '-' term      { $$ = make_node("-", $1, $3); }
       | term
       ;
term   : term '*' factor    { $$ = make_node("*", $1, $3); }
       | term '/' factor    { $$ = make_node("/", $1, $3); }
       | factor
       ;
factor : '(' expr ')'       { $$ = $2; }
       | ID                 { $$ = make_node($1, NULL, NULL); }
       | NUM                { $$ = make_node($1, NULL, NULL); }
       ;
%%
int main(void) {
    return yyparse();
}
