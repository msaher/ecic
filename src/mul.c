#include "expr.h"
#include "stdlib.h"
#include "add.h"

typedef struct Mul {
    Expr *a;
    Expr *b;
} Mul;

Mul *mul_init(Expr *a, Expr *b) {
    Mul *mul = malloc(sizeof(Mul));
    mul->a = a;
    mul->b = b;

    return mul;
}

Expr *mul_simplify(Mul *mul) {
    Expr *e1 = mul->a;
    Expr *e2 = mul->b;

    Expr *res = expr_init();
    if (expr_iszero(e1) || expr_iszero(e2)) {
        res->type = INT;
        res->integer = 0;
        return res;
    }

    if (e1->type == MUL)
        e1 = mul_simplify(e1->mul);

    if (e2->type == MUL)
        e2 = mul_simplify(e2->mul);

    if (e1->type == INT && e2->type == INT) {
        res->type = INT;
        res->integer = e1->integer * e2->integer;
    }
    else {
        res->type = MUL;
        res->mul = mul;
    }

    return res;
}
