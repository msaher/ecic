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

char *var_name(Var *var) {
    return var->name;
}

Expr *var_value(Var *var) {
    return var->value;
}

void var_free(Var *var) {
    free(var);
}
