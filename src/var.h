#ifndef VAR_H
#define VAR_H
#include "expr.h"

Var *var_init(char *name, Expr *value);
void var_free(Var *var);

#endif
