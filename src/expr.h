#ifndef EXPR_H
#define EXPR_H
#include <stdbool.h>

typedef enum Etype {
    ADD,
    SUB,
    MUL,
    DIV,
    INT,
    VAR,
} Etype;

typedef struct Add Add;
typedef struct Mul Mul;
typedef struct Var Var;

typedef struct Expr {
    union {
        Add *add;
        Mul *mul;
        int integer;
    };
    Etype type;
} Expr;

Expr *expr_init();
void expr_free(Expr *e);

Expr *expr_simplify(Expr *e);
Expr *expr_int(int n);

bool expr_iszero(Expr *e);

#endif
