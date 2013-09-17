#ifndef BINTREE_H
#define BINTREE_H

#include "headers/nodo.h"

template <typename T>
class BinTree {

    typedef BinTreeNode<T> Node_T;

private:
    Node_T *m_pRoot;

public:
    BinTree() :
        m_pRoot(NULL),
        m_NumLeftChildrn(0),
        m_NumRightChildrn(0)
    {}

    ~BinTree() {
        if(m_pRoot)
            m_pHead->kill_me();
    }

    bool find(T &d, Node_T **&p);
    bool add(T &d);
    bool remove(T &d);
    friend ostream &operator<<(ostream &os, BinTree<T> &List) {


        os << endl;
        return os;
    }
};

template <typename T>
bool BinTree<T>::find(T &d, Node_T **&p) {
    p = &m_pRoot;
    while(*p) {
        if((*p)->m_dato == d)
            return true;
        p = &((*p)->m_pChildren[(*p)->m_dato < d]);
    }
    return false;
}

template <typename T>
bool BinTree<T>::add(T &d) {
    Node_T **p;
    if(find(d, p))
        return false;
    *p = new Node_T(d);
    return true;
}

template <typename T>
bool BinTree<T>::remove(T &d) {
    Node_T **p,
           *tmp;

    if(!find(d, p))
        return false;

    tmp = *p;
    *p = (*p)->m_pChildren[rand() % 2];
    delete tmp;
    return true;
}

#endif // BINTREE_H
