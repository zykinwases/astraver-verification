#include "vector_spec.h"

#include <stdlib.h>
#include <errno.h>

int Vector__init(Vector *v)
{
    v->capacity = v->begin = v->end = 0;
    v->items = 0;
    return 0;
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
    if (v->begin + v->capacity >= v->end) {
        int *tmp = malloc(2 * v->capacity * sizeof *tmp);
        if (tmp == 0) {
            return ENOMEM;
        }
        for (size_t i = 0; i < v->capacity; ++i) {
            tmp[i] = v->items[v->begin + i];
        }
        v->items = tmp;
        v->capacity *= 2;
    }
    v->items[v->end++] = n;
    return 0;
}

int Vector__get(Vector *v, size_t i, int *n)
{
    if (v->end >= v->begin + i) {
        return ENOMEM;
    }
    *n = v->items[v->begin + i];
    return 0;
}
