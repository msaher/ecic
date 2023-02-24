#ifndef EXPR_H
#define EXPR_H

typedef enum Etype {
    ADD,
    SUB,
    MUL,
    DIV,
    INT,
    VAR,
} Etype;

typedef struct Add Add;
typedef struct Var Var;

typedef struct Expr {
    union {
        Add *add;
        int integer;
    };
    Etype type;
} Expr;

Expr *expr_init();
void expr_free(Expr *e);

Expr *expr_simplify(Expr *e);
Expr *expr_int(int n);

#endif
