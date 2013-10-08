#ifndef RB_TREE_H
#define RB_TREE_H

#include "headers/nodo.h"

class RB_Tree
{
    typedef RB_Node<T> Node_T;

private:
    Node_T *m_pRoot;

private:        //Funciones Privadas

public:         //Funciones Públicas
    RB_Tree() :
        m_pRoot(NULL)
    {}

    bool insert(T &d);

};

#include "avl_tree.cpp"

#endif // RB_TREE_H
