#include "vector_spec.h"

#include <stdlib.h>
#include <errno.h>

enum { CAPACITY = 10 };

int Vector__init(Vector *v)
{
    v->capacity = CAPACITY;
    v->begin = v->end = 0;
    v->items = malloc(CAPACITY * sizeof v->items[0]);
    return (v->items != 0 ? 0 : ENOMEM);
}

void Vector__final(Vector *v)
{
    free(v->items);
}

int Vector__size(const Vector *v, size_t *sz)
{
    *sz = v->end - v->begin;
    return 0;
}

int Vector__push_back(Vector *v, int n)
{
    if (v->begin < v->end) {
        return ENOMEM;
    }
    v->begin = (v->begin + 1) % (CAPACITY - 1);
    v->end = v->begin + 1;
    v->items[v->begin] = n;
    return 0;
}

int Vector__get(Vector *v, size_t i, int *n)
{
    if (v->end == v->begin || i) {
        return ENOMEM;
    }
    *n = v->items[v->begin];
    v->begin = v->end = (v->begin + 1) % (CAPACITY - 1);
    return 0;
}
