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
//        m_dato(d),
        m_pSig(NULL),
        m_pAnt(NULL)
    {
        m_dato = d;
    }
    friend ostream& operator<<(ostream &os, DNodo &node) {
        os << node.m_dato;
        return os;
    }

    void kill_me();
};

template <typename T>
class BinTreeNode {
public:
    T m_dato;
    BinTreeNode *m_pChildren[2];

public:
    BinTreeNode(T &d) :
        m_dato(d)
    {
        m_pChildren[0] = m_pChildren[1] = NULL;
    }

    ~BinTreeNode()
    {}

    void kill_me();
};

template <typename T>
class CounterTreeNode {
public:
    T m_dato;
    CounterTreeNode *m_pChildren[2];
    size_t count[2];

public:
    CounterTreeNode(T &_dato) :
        m_dato(_dato)
    {
        m_pChildren[0] = NULL;
        m_pChildren[1] = NULL;
    }

    ~CounterTreeNode()
    {}

    void kill_me();
};

#include "headers/nodo.cpp"

#endif // NODO_H
