#ifndef __VECTOR__
#define __VECTOR__

#include <stddef.h>

typedef struct {
    int *items;
    size_t capacity;
    size_t begin;
    size_t end;
} Vector;

/**
    Allocates memory for v->items
*/
/*@ requires \valid(v);
    ensures \result == 0 ==> 
        v->capacity >= 0 && 
        v->end == 0 &&
        \valid(v->items + (0..v->capacity-1));
*/
int Vector__init(Vector *v);

/**
    Deallocates memory for v->items
*/
/*@ requires \valid(v);
    requires \valid(v->items + (0..v->capacity-1))
    ensures !(\valid(v->items + (0..v->capacity-1)));
    frees v->items;
*/
void Vector__final(Vector *v);

/**
    Gets the count of items of the vector added before and not removed
*/
/*@ requires \valid(v) && \valid(sz);
    requires \valid(v->items + (0..v->capacity-1));
    ensures *sz == v->end - v->begin;
*/
int Vector__size(const Vector *v, size_t *sz);

/**
    Adds n to the end of the vector if the vector allows
*/
/*@ requires \valid(v);
    requires \valid(v->items + (0..v->capacity-1));
    ensures \result == 0 ==> 
        \old(v->end) + 1 == v->end && 
        v->items[v->end] == n;
    ensures \old(v->capacity) + \old(v->begin) >= \old(v->end) ==> \result != 0;
*/
int Vector__push_back(Vector *v, int n);

/**
    Gets the i-th item of the vector if the item is exist
*/
/*@ requires \valid(v) && \valid(n);
    requires \valid(v->items + (0..v->capacity-1));
    ensures \old(v->begin) <= i < \old(v->end) ==> \result == 0 && *n == v->items[n];
    ensures \old(v->begin) + i >= \old(v->end) ==> \result != 0;
*/
int Vector__get(Vector *v, size_t i, int *n);


#endif
