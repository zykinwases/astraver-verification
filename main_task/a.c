#include <limits.h>
#include <stdlib.h>

/*@ requires \valid(p);
    requires *p < INT_MAX;
    ensures *p == \old(*p) + 1;
*/

void increment(int *p) {
    // *p = *p + 1;
    (*p)++;
}

int main() {
    int i = 0;
    increment(&i);
    //@ assert(i == 1);
}

int norm_main() {
    int *i = malloc(sizeof(int));
    *i = 0;
    increment(i);
    //@ assert *i == 1;
    free(i);
    return 0;
}