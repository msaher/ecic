#include "expr.h"
#include "add.h"
#include "int.h"
#include <stdlib.h>

Expr *expr_init() {
    Expr *e = malloc(sizeof(Expr));
    return e;
}

void expr_free(Expr *e) {
    free(e);
}
