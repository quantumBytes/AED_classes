#ifndef QUEUE_H
#define QUEUE_H

#include "headers/nodo.h"

template <typename T>
class Queue {
    typedef Nodo<T> Nodo_T;

private:
    Nodo_T *m_pTop,
           *m_pLast;

public:
    Queue() :
        m_pTop(NULL),
        m_pLast(NULL)
    {}

    ~Queue() {
        if(m_pTop)
            m_pTop->kill_me();
    }

    void push(T &d);

    void pop();

    T& top();

    bool isEmpty();
};

template <typename T>
void Queue<T>::push(T &d) {
    Nodo_T *neo = new Nodo_T(d);
    if(!m_pTop) {
        m_pTop = neo;
        m_pLast = neo;
        return;
    }
    m_pLast->m_pSig = neo;
    m_pLast = neo;
}

template <typename T>
void Queue<T>::pop() {
    if(m_pTop) {
        Nodo_T *temp = m_pTop;
        m_pTop = m_pTop->m_pSig;
        delete temp;
    }
}

template <typename T>
T& Queue<T>::top() {
    if(m_pTop)
        return m_pTop->m_dato;
    else
        throw 0;
}

template <typename T>
bool Queue<T>::isEmpty() {
    return m_pTop == NULL;
}

#endif // QUEUE_H
