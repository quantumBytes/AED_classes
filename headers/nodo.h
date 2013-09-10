#ifndef NODO_H
#define NODO_H

#include <iostream>

using namespace std;

template<class T>
class Nodo {
public:
    T m_dato;
    Nodo<T> *m_pSig;

public:
    Nodo(T &d) :
        m_dato(d),
        m_pSig(NULL)
    {}
    friend ostream& operator<<(ostream &os, Nodo &node) {
        os << node.m_dato;
        return os;
    }

    void kill_me();
};

template<class T>
class DNodo {
public:
    T m_dato;
    DNodo<T> *m_pSig;
    DNodo<T> *m_pAnt;

public:
    DNodo(T &d) :
        m_dato(d),
        m_pSig(NULL),
        m_pAnt(NULL)
    {}
    friend ostream& operator<<(ostream &os, DNodo &node) {
        os << node.m_dato;
        return os;
    }

    void kill_me();
};

#include "headers/nodo.cpp"

#endif // NODO_H
