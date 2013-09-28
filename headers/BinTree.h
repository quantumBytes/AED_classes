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

    size_t level(Node_T *&p);       //A)

    size_t height(Node_T *&p);

    size_t height();               //B)

    Node_T *brother(Node_T *&p);   //C)

    Node_T *father(Node_T *&p);    //D)

    Node_T *grand_father(Node_T *&p);  //E)

    size_t nodeCount(Node_T *&p);

    size_t nodeCount();             //F)

    size_t leafCount(Node_T *&p);

    size_t leafCount();             //G)

    Node_T *&maximum();             //H)

    Node_T *&minimum();             //I)

    Node_T *&next(Node_T *&p);      //J)

//    friend ostream &operator<<(ostream &os, BinTree<T> &List) {
//        os << endl;
//        return os;
//    }
};

#include "headers/BinTree.cpp"

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
