#include "expr.h"
#include <stdlib.h>

typedef struct Var {
    char *name;
    Expr *value;
} Var;

Var *var_init(char *name, Expr *value) {
    Var *var = malloc(sizeof(Var));
    var->name = name;
    var->value = value;

    return var;
}

void var_free(Var *var) {
    free(var);
}
