#include "headers/BinTree.h"

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
    return false;
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

template <typename T>
size_t BinTree<T>::level(Node_T *&p) {

}
