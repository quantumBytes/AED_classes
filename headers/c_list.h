#ifndef C_LIST_H
#define C_LIST_H

#include "headers/nodo.h"

template<class T>
class C_List
{
    typedef Nodo<T> Nodo_T;
private:
    Nodo_T *m_pHead,
           *m_pLast;
    int tam;
public:
    C_List() :
        m_pHead(NULL),
        m_pLast(NULL),
        tam(0)
    {}

    friend ostream &operator<<(ostream &os, C_List<T> &List) {
        Nodo_T *tmp;
        size_t i;
        for(tmp = List.m_pHead, i = List.tam;
            i > 0;
            tmp = tmp->m_pSig, --i)
            os << tmp->m_dato << "\t";
        os << endl;
        return os;
    }

    C_List &operator>>(T &d) {
        push_back(d);
        return *this;
    }

    C_List operator+(C_List &B);
    C_List operator-(C_List &B);
    void push_front(T &d);
    void push_back(T &d);
    void pop_front();
    void pop_back();
    int size();
    T &operator[](size_t p);
    void reverse();
    bool find(T &d);
    bool &find_reverse(T &d);
};

template <typename T>
C_List<T> C_List<T>::operator+(C_List &B) {
    C_List<T> ret;
    Nodo_T *tmp;
    size_t i;

    for(tmp = m_pHead, i = tam;
        i > 0;
        tmp = tmp->m_pSig, --i)
        ret.push_back(tmp->m_dato);

    for(tmp = B.m_pHead, i = B.tam;
        i > 0;
        tmp = tmp->m_pSig, --i)
        if(!ret.find(tmp->m_dato))
            ret.push_back(tmp->m_dato);

    return ret;
}

template <typename T>
C_List<T> C_List<T>::operator-(C_List &B) {
    C_List<T> ret;
    Nodo_T *tmp;
    size_t i;

    for(tmp = m_pHead, i = tam;
        i > 0;
        tmp = tmp->m_pSig, --i)
        if(B.find(tmp->m_dato))
            ret.push_back(tmp->m_dato);

    return ret;
}

template <typename T>
void C_List<T>::push_front(T &d) {
    Nodo_T *neo = new Nodo_T(d);

    if(!m_pHead) {
        neo->m_pSig = neo;
        m_pHead = neo;
        m_pLast = neo;
        ++tam;
        return;
    }

    m_pLast->m_pSig = neo;
    neo->m_pSig = m_pHead;

    m_pHead = neo;
    ++tam;
}

template <typename T>
void C_List<T>::push_back(T &d) {
    Nodo_T *neo = new Nodo_T(d);

    if(!m_pHead) {
        neo->m_pSig = neo;
        m_pHead = neo;
        m_pLast = neo;
        ++tam;
        return;
    }
    m_pLast->m_pSig = neo;
    m_pLast = neo;
    m_pLast->m_pSig = m_pHead;
    ++tam;
}

template <typename T>
void C_List<T>::pop_front() {
    if(m_pHead) {
        Nodo_T *tmp = m_pHead->m_pSig;
        delete m_pHead;
        m_pHead = tmp;
        --tam;
    }
}

template <typename T>
void C_List<T>::pop_back() {
    if(m_pHead /*&& tam > 1*/) {
        Nodo_T *tmp;
        size_t i = tam;
        for(tmp = m_pHead;
            i > 2;
            tmp = tmp->m_pSig, --i);
        tmp->m_pSig = m_pHead;
        delete m_pLast;
        m_pLast = tmp;
        --tam;
//        return;
    }
//    delete m_pHead;
//    m_pHead = m_pLast = NULL;
}

template <typename T>
int C_List<T>::size() {
    return tam;
}

template <typename T>
T &C_List<T>::operator[](size_t p) {
    if(p < tam) {
        Nodo_T *tmp;
        size_t i;
        for(tmp = m_pHead, i = 0;
            i < p;
            tmp = tmp->m_pSig, ++i);
        return *tmp;
    }
    else
        throw 0;
}

template <typename T>
void C_List<T>::reverse() {
    Nodo_T *tmp1 = m_pHead,
           *tmp2,
           *tmp3;
    size_t i;
    for(tmp1 = m_pHead, tmp2 = tmp1->m_pSig, i = tam;
        i > 1;
        --i) {
        tmp3 = tmp2->m_pSig;
        tmp2->m_pSig = tmp1;
        tmp1 = tmp2;
        tmp2 = tmp3;
    }
    m_pHead->m_pSig = NULL;
    m_pHead = tmp1;
}

template <typename T>
bool C_List<T>::find(T &d) {
    Nodo_T *tmp;
    size_t i;
    for(tmp = m_pHead, i = tam;
        i > 0;
        tmp = tmp->m_pSig, --i)
        if(tmp->m_dato == d)
            return true;
//    if(tam == 1)
//        return tmp->m_dato == d;
    return false;
}

#endif // C_LIST_H
