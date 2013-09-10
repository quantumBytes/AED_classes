#ifndef DLIST_H
#define DLIST_H

#include "headers/nodo.h"

template<class T>
class DList
{
    typedef DNodo<T> Nodo_T;
private:
    Nodo_T *m_pHead;
    Nodo_T *m_pLast;
    int tam;

public:
    DList() :
        m_pHead(NULL),
        m_pLast(NULL),
        tam(0)
    {}
    DList operator+(DList &B);
    DList operator-(DList &B);
    friend ostream &operator<<(ostream &os, DList<T> &List) {
        Nodo_T *tmp = List.m_pHead;

        while(tmp) {
            os << tmp->m_dato << "\t";
            tmp = tmp->m_pSig;
        }

        os << endl;
        return os;
    }

    DList &operator>>(T &d) {
        push_back(d);
        return *this;
    }

    void push_front(T &d);
    void push_back(T &d);
    void sort();
    int size();
    T &operator[](int p);
    void reverse();
    bool find(T &d);
    bool &find_reverse(T &d);
    void index(string file);
};

template<typename T>
bool DList<T>::find(T &d) {
    Nodo_T *tmp = m_pHead;
    while(tmp) {
        if(tmp->m_dato == d)
            return true;
        tmp = tmp->m_pSig;
    }
    return false;
}

template<typename T>
DList<T> DList<T>::operator+(DList &B) {
    DList<T> ret;
    Nodo_T *tmp;

    for(tmp = m_pHead; tmp; tmp = tmp->m_pSig)
        ret.push_back(tmp->m_dato);

    for(tmp = B.m_pHead; tmp; tmp = tmp->m_pSig)
        if(!ret.find(tmp->m_dato))
            ret.push_back(tmp->m_dato);

    return ret;
}

template<typename T>
DList<T> DList<T>::operator-(DList &B) {
    DList<T> ret;
    Nodo_T *tmp;

    for(tmp = m_pHead; tmp; tmp = tmp->m_pSig)
        if(B.find(tmp->m_dato))
            ret.push_back(tmp->m_dato);

    return ret;
}

template<typename T>
void DList<T>::push_front(T &d) {
    Nodo_T *neo = new Nodo_T(d);
    if(m_pHead)
        m_pHead->m_pAnt = neo;
    else
        m_pLast = neo;
    neo->m_pSig = m_pHead;
    neo->m_pAnt = NULL;
    m_pHead = neo;
    tam++;
}

template<typename T>
void DList<T>::push_back(T &d) {
    Nodo_T *neo = new Nodo_T(d);
    if(!m_pHead) {
        neo->m_pAnt = NULL;
        m_pHead=neo;
    }
    else {
        Nodo_T *tmp = m_pHead;
        while(tmp->m_pSig)
            tmp = tmp->m_pSig;
        tmp->m_pSig = neo;
        neo->m_pAnt = tmp;
    }
    m_pLast = neo;
    tam++;
}

template<typename T>
void DList<T>::sort() {

}

template<typename T>
int DList<T>::size() {
    /*int i = 0;
    for(Nodo_T *tmp = m_pHead; tmp; tmp = tmp->m_pSig, i++);
    return i;*/
    return tam;
}

template<typename T>
T &DList<T>::operator[](int p) {
    if(p > tam)
        return m_pLast->m_dato;
    Nodo_T *tmp;
    for(tmp = m_pHead; p > 0; tmp = tmp->m_pSig, p--);
    return tmp->m_dato;
}

template<typename T>
void DList<T>::reverse() {
    int my_size = tam/2,
        i;
    Nodo_T *tmp_beg,
           *tmp_end;
    T Nodo_T::*dato = &Nodo_T::m_dato,
      tmp;

    for(i = 0,
        tmp_beg = m_pHead,
        tmp_end = m_pLast;
        i < my_size;
        ++i,
        tmp_beg = tmp_beg->m_pSig,
        tmp_end = tmp_end->m_pAnt) {
        tmp = tmp_beg->*dato;
        tmp_beg->*dato = tmp_end->*dato;
        tmp_end->*dato = tmp;
    }

    /*Nodo_T *tmp,
           *tmp_beg,
           *tmp_end;
        for(tmp_beg = m_pHead,
            tmp_end = m_pLast;;) {
            tmp = th->m_pSig,
            th->m_pSig = th->m_pAnt,
            th->m_pAnt = tmp,
            th = tmp
        }

        tmp = m_pHead;
        m_pHead = m_pLast;
        m_pLast = tmp;

    */
}

template<typename T>
bool &DList<T>::find_reverse(T &d) {
    Nodo_T *tmp = m_pLast;
    while(tmp) {
        if(tmp->m_dato == d)
            return true;
        tmp = tmp->m_pAnt;
    }
    return false;
}

template<typename T>
void DList<T>::index(string file) {

}

#endif // DLIST_H
