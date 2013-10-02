#ifndef HASH_H
#define HASH_H

#include <iostream>
#include "headers/c_list.h"

template <class T, class K, int pf(void *k, int tam), int tam = 17>
class Hash
{
    typedef Nodo<T> Node_T;
    typedef C_List<T> Container;

private:

    Container **m_tabla;

public:

    Hash();

    ~Hash();

    bool find(K &key, Node_T **&p);

    bool add(T &d, K &key);

    bool remove(K &key);
};

#include "hash.cpp"

#endif // HASH_H
