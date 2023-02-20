#include "vector.h"

/*@
    assigns \nothing;
    allocates \nothing;
*/
int main(void)
{
    int __ret__ = 0;

    Vector v;
    if (Vector__init(&v) != 0) goto __FINALLY0__;

    size_t sz;
    if (Vector__size(&v, &sz) != 0) goto __FINALLY1__;
    //@ assert sz == 0;

    if (Vector__push_back(&v, 10) != 0) goto __FINALLY1__;
    if (Vector__size(&v, &sz) != 0) goto __FINALLY1__;
    //@ assert sz == 1;
    int n; if (Vector__get(&v, 0, &n) != 0) goto __FINALLY1__;
    //@ assert n == 10;

    if (Vector__push_back(&v, 20) != 0) goto __CATCH1__;
    if (Vector__size(&v, &sz) != 0) goto __CATCH1__;
    //@ assert sz == 2;
    int n1; if (Vector__get(&v, 0, &n1) != 0) goto __CATCH1__;
    //@ assert n1 == 10;
    int n2; if (Vector__get(&v, 0, &n2) != 0) goto __CATCH1__;
    //@ assert n2 == 10;
    goto __AFTERTRY__;

__CATCH1__:
    if (Vector__size(&v, &sz) != 0) goto __FINALLY1__;
    //@ assert sz == 1;
    int n3; if (Vector__get(&v, 0, &n3) != 0) goto __FINALLY1__;
    //@ assert n3 == 10;
    goto __AFTERTRY__;
    

__AFTERTRY__:

    // new code especially for C
    {
    int large_array[1024];
    Vector v3 = { .items = &large_array[0],
                .capacity = 100,
                .begin = 0,
                .end = 0 },
           v4 = { .items = &large_array[512],
                .capacity = 200,
                .begin = 3,
                .end = 5 };
    if (Vector__push_back(&v3, -1) != 0) goto __FINALLY2__;
    if (Vector__size(&v4, &sz) != 0) goto __FINALLY2__;
    //@ assert sz == 2;

__FINALLY2__:
    ;
    }

__FINALLY1__:
    Vector__final(&v);
__FINALLY0__:
    return __ret__;
}
