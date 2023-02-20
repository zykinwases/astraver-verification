#include "vector_spec.h"

#include <errno.h>

int Vector__init(Vector *v)
{
    v->capacity = 0;
    v->begin = 0;
    return 0;
}

void Vector__final(Vector *v)
{
}

int Vector__size(const Vector *v, size_t *sz)
{
    *sz = v->capacity;
    return 0;
}

int Vector__push_back(Vector *v, int n)
{
    if (v->capacity) {
        return ENOMEM;
    }
    v->end = n;
    v->capacity = 1;
    return 0;
}

int Vector__get(Vector *v, size_t i, int *n)
{
    if (!v->capacity || i) {
        return ENOMEM;
    }
    *n = v->end;
    return 0;
}
