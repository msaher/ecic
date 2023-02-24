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

struct Add;
typedef struct Add Add;

typedef struct Expr {
    union {
        Add *add;
        int integer;
    };
    Etype type;
} Expr;

Expr *expr_init();
void expr_free(Expr *e);

#endif
