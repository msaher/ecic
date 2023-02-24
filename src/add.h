#ifndef ADD_H
#define ADD_H
#include "expr.h"

Add *add_init(Expr *a, Expr *b);
Expr *simplify(Add *add);
Expr *int_init(int n);
void add_free(Add *add);

#endif
