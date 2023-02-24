#include "expr.h"
#include "add.h"
#include <stdlib.h>

Expr *expr_init() {
    Expr *e = malloc(sizeof(Expr));
    return e;
}

void expr_free(Expr *e) {
    free(e);
}

Expr *expr_simplify(Expr *e) {
    switch (e->type) {
        case INT:
            return e;
        case ADD:
            return add_simplify(e->add);
        case VAR:
            return e;
        default:
            return e;
    }
}

Expr *expr_int(int n) {
    Expr *e = expr_init();
    e->type = INT;
    e->integer = n;
    return e;
}
