#include "expr.h"
#include <stdlib.h>
#include <stdio.h>

typedef struct Add {
    Expr *a;
    Expr *b;
} Add;

Add *add_init(Expr *a, Expr *b) {
    Add *add = malloc(sizeof(Add));
    add->a = a;
    add->b = b;

    return add;
}

Expr *simplify(Add *add) {
    Expr *e1 = add->a;
    Expr *e2 = add->b;

    if (e1->type == ADD)
        e1 = simplify(e1->add);

    if (e2->type == ADD)
        e2 = simplify(e2->add);

    // TODO: free memory for add, e1, and e2?
    if (e1->type == INT && e2->type == INT) {

        Expr *e = malloc(sizeof(Expr));
        e->type = INT;
        e->integer = e1->integer + e2->integer;
        return e;
    }

    fprintf(stderr, "idk what to do here");
    exit(1);
}
