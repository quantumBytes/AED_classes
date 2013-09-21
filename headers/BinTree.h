#ifndef BINTREE_H
#define BINTREE_H

#include "headers/nodo.h"
#include <iostream>

using namespace std;

template <typename T>
class BinTree {

    typedef BinTreeNode<T> Node_T;

private:
    Node_T *m_pRoot;

public:
    BinTree() :
        m_pRoot(NULL)
    {}

    ~BinTree() {
        if(m_pRoot)
            m_pRoot->kill_me();
    }

    bool find(T &d, Node_T **&p);
    bool add(T &d);
    bool remove(T &d);
    bool addRec(T &d, Node_T *&p);
    bool findRec(T &d, Node_T *&p);
    void printIn(Node_T *p);
    void printPre(Node_T *p);
    void printPos(Node_T *p);
    void printIn();
    void printPre();
    void printPos();
    void printElem(Node_T *&p);
//    friend ostream &operator<<(ostream &os, BinTree<T> &List) {


//        os << endl;
//        return os;
//    }
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
    if((*p)->m_pChildren[0] && (*p)->m_pChildren[1]) {
        tmp = (*p)->m_pChildren[0];
        for(; tmp; tmp = (*p)->m_pChildren[1]);

    }
    else {
        tmp = *p;
        if((*p)->m_pChildren[0] && !(*p)->m_pChildren[1])
            *p = tmp->m_pChildren[0];
        else
            *p = tmp->m_pChildren[1];
        delete tmp;
        return true;
    }
}

template <typename T>
bool BinTree<T>::addRec(T &d, Node_T *&p) {    
    if(p)
        return addRec(d, p->m_pChildren[p->m_dato < d]);
    Node_T *neo = Node_T(d);
    p = neo;
    return true;
}

template <typename T>
bool BinTree<T>::findRec(T &d, Node_T *&p) {
    if(p->m_dato == d)
        return true;
    return findRec(d, p->m_pChildren[p->m_dato < d]);
}

template <typename T>
void BinTree<T>::printElem(Node_T *&p) {
    cout << p->m_dato << "\t";
}

template <typename T>
void BinTree<T>::printIn(Node_T *p) {
    if(!p)  return;
    if(p->m_pChildren[0])   printIn(p->m_pChildren[0]);
    printElem(p);
    if(p->m_pChildren[1])   printIn(p->m_pChildren[1]);
}

template <typename T>
void BinTree<T>::printPre(Node_T *p) {
    if(!p)  return;
    printElem(p);
    if(p->m_pChildren[0])   printIn(p->m_pChildren[0]);
    if(p->m_pChildren[1])   printIn(p->m_pChildren[1]);
}

template <typename T>
void BinTree<T>::printPos(Node_T *p) {
    if(!p)  return;
    if(p->m_pChildren[0])   printIn(p->m_pChildren[0]);
    if(p->m_pChildren[1])   printIn(p->m_pChildren[1]);
    printElem(p);
}

template <typename T>
void BinTree<T>::printIn() {
    printIn(m_pRoot);
    cout << endl;
}

template <typename T>
void BinTree<T>::printPre() {
    printPre(m_pRoot);
    cout << endl;
}

template <typename T>
void BinTree<T>::printPos() {
    printPos(m_pRoot);
    cout << endl;
}

//A) Hallar nivel de un nodo
//B) Hallar altura
//C) Retornar hermano
//D) Retornar padre
//E) Retornar abuelo
//F) Contar nodos
//G) Contar hojas
//H) Hallar máximo
//I) Hallar mínimo
//J) Si p es un puntero a un nodo de un Árbol<int> retornar el siguiente entero
//K) Si p es un puntero a un nodo de un Árbol<int> retornar el entero anterior
//L) Intersección de dos árboles binarios
//M) Unión de dos árboles binarios
//N) ¿Si se tiene n nodos, cuántos árboles binarios diferentes se pueden crear?

#endif // BINTREE_H
