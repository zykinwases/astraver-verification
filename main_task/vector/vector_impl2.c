#include "vector_spec.h"

#include <stdlib.h>
#include <errno.h>

int Vector__init(Vector *v)
{
    v->capacity = 10;
    v->end = 0;
    v->items = malloc(v->capacity * sizeof v->items[0]);
    return (v->items != 0 ? 0 : ENOMEM);
}

void Vector__final(Vector *v)
{
    v->items = 0;
}

int Vector__size(const Vector *v, size_t *sz)
{
    *sz = v->end;
    return 0;
}

int Vector__push_back(Vector *v, int n)
{
    if (v->capacity >= v->end) {
        return ENOMEM;
    }
    v->items[v->end++] = n;
    return 0;
}

int Vector__get(Vector *v, size_t i, int *n)
{
    if (v->end >= i) {
        return ENOMEM;
    }
    *n = v->items[i];
    return 0;
}
