#ifndef __VECTOR__
#define __VECTOR__

#include <cstddef>

class Vector {
public:
    Vector();
    ~Vector();

    size_t size() const;
    int push_back(int n);
    int get(size_t i);

private:
    int *items;
    size_t capacity;
    size_t begin;
    size_t end;
};


#endif
