#ifndef EXPR_H
#define EXPR_H

typedef enum Etype {
    ADD,
    SUB,
    MUL,
    DIV,
    INT,
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

#endif
