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
size_t BinTree<T>::level(Node_T *&p) {       //A)
    Node_T *tmp = m_pRoot;
    size_t level = 0;
    while(tmp) {
        if(tmp->m_dato == p->m_dato)
            return level;

    }
}

template <typename T>
size_t BinTree<T>::height(Node_T *&p) { //Calcula la profundidad partiendo del nodo que se pasa como parámetro
    if(p) {
        size_t height_left = height(p->m_pChildren[0]),
               height_right = height(p->m_pChildren[1]);
        return ((height_left < height_right) ? height_right : height_left) + 1;
    }

    return 0;
}

template <typename T>
size_t BinTree<T>::height() {                //B)
    return height(m_pRoot);
}

template <typename T>
BinTreeNode<T> *BinTree<T>::brother(Node_T *&p) {   //C)
    Node_T *father = m_pRoot;
    while(father) {
        if(father->m_pChildren[father->m_dato < p->m_dato] = p)
            return father->m_pChildren[father->m_dato > p->m_dato];
        father = father->m_pChildren[father->m_dato < p->m_dato];
    }
    return NULL;
}

template <typename T>
BinTreeNode<T> *BinTree<T>::father(Node_T *&p) {    //D)
    Node_T *father = m_pRoot;
    while(father) {
        if(father->m_pChildren[father->m_dato < p->m_dato] = p)
            return father;
        father = father->m_pChildren[father->m_dato < p->m_dato];
    }
    return NULL;
}

template <typename T>
BinTreeNode<T> *BinTree<T>::grand_father(Node_T *&p) { //E)
//    Node_T *father = m_pRoot;
//    while(father) {
//        if(father->m_pChildren[father->m_dato < p->m_dato] = p)
//            return father;
//        father = father->m_pChildren[father->m_dato < p->m_dato];
//    }
//    return NULL;
}

template <typename T>
size_t BinTree<T>::nodeCount(Node_T *&p) {
    size_t count = 0;
    if(p) {
        count +=
                nodeCount(p->m_pChildren[0]) +  //Nodos por la izquierda
                nodeCount(p->m_pChildren[1]) +  //Nodos por la derecha
                1;                              //Nodo por sí mismo
    }
    return count;
}

template <typename T>
size_t BinTree<T>::nodeCount() {             //F)
    return nodeCount(m_pRoot);
}

template <typename T>
size_t BinTree<T>::leafCount(Node_T *&p) {
    if(p->m_pChildren[0])
        return leafCount(p->m_pChildren[0]) + (p->m_pChildren[1]) ? leafCount(p->m_pChildren[1]) : 0;
    else
        return (p->m_pChildren[1]) ? leafCount(p->m_pChildren[1]) : 1;
    return 0;
}

template <typename T>
size_t BinTree<T>::leafCount() {            //G)
    return leafCount(m_pRoot);
}

template <typename T>
BinTreeNode<T> *&BinTree<T>::maximum() {             //H)   //Puede ser combinada con minimum
    Node_T *max = m_pRoot;
    while(max) {
        if(max->m_pChildren[1])
            max = max->m_pChildren[1];
        else
            return max;
    }
}

template <typename T>
BinTreeNode<T> *&BinTree<T>::minimum() {             //I)
    Node_T *min = m_pRoot;
    while(min) {
        if(min->m_pChildren[0])
            min = min->m_pChildren[0];
        else
            return min;
    }
}

template <typename T>
BinTreeNode<T> *&BinTree<T>::next(Node_T *&p) {     //J)

}
template <typename T>
BinTreeNode<T> *&BinTree<T>::previous(Node_T *&p) { //K)

}
