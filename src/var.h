#ifndef VAR_H
#define VAR_H
#include "expr.h"

Var *var_init(char *name, Expr *value);
void var_free(Var *var);

char *var_name(Var *var);
Expr *var_value(Var *var);


#endif
