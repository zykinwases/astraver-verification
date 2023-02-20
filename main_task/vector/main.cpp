#include "vector.hpp"

int main()
{
    Vector v;
    size_t sz = v.size();
    //@ assert sz == 0;

    v.push_back(10);

    sz = v.size();
    //@ assert sz == 1;
    int n = v.get(0);
    //@ assert n == 10;

    try {
        v.push_back(20);

        sz = v.size(); 
        //@ assert sz == 2;
        int n1 = v.get(0);
        //@ assert n1 == 10;
        int n2 = v.get(1);
        //@ assert n2 == 20;
    } catch (...) {
        sz = v.size();
        //@ assert sz == 1;
        int n3 = v.get(0);
        //@ assert n3 == 10;
    }
}
