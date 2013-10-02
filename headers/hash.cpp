#include "hash.h"

template <class T, class K, int pf(void *k, int tam), int tam>
Hash::Hash() {
    m_tabla = new Container*[tam];
    for(register size_t i = 0; i < tam; ++i)
        *(m_tabla + i) = NULL;
}

template <class T, class K, int pf(void *k, int tam), int tam>
Hash<T, K, pf, tam>::~Hash() {
    for(register size_t i = 0; i < tam; ++i)
        if(*(m_tabla + i))
            delete *(m_tabla + i);
    delete []m_tabla;
}

template <class T, class K, int pf(void *k, int tam), int tam>
bool Hash<T, K, pf, tam>::find(K &key, Node_T **&p) {
    T obj(key);
    int pos = pf(&key, tam);
    Container *l = m_tabla[pos];
    if(l)
        return l->find(obj, p);
    return false;
}

template <class T, class K, int pf(void *k, int tam), int tam>
bool Hash<T, K, pf, tam>::add(T &d, K &key) {
    int pos = pf(&key, tam);
    Container *L = m_tabla[pos];
    if(L)
        return L->push_front(d);
    return false;
}

template <class T, class K, int pf(void *k, int tam), int tam>
bool Hash<T, K, pf, tam>::remove(K &key) {
    int pos = pf(&key, tam);
    Container *L = m_tabla[pos];
    if(L)
        return L->remove(T(key));
    return false;
}
