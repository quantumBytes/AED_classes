#ifndef STACK_H
#define STACK_H

#include "nodo.h"

template <typename T>
class Stack {
	typedef Nodo<T> Nodo_T;
    Nodo_T *Nodo_T::*p_Ant = &Nodo_T::m_pSig;

private:
    Nodo_T *m_pTop;

public:
	Stack() :
		m_pTop(NULL)
	{}

	~Stack() {
		if(m_pTop)
            m_pTop->kill_me();
	}

	void push(T &d);

	void pop();

	T& top();

	bool isEmpty();
};

template <typename T>
void Stack<T>::push(T &d) {
	Nodo_T *neo = new Nodo_T(d);
    neo->*p_Ant = m_pTop;
	m_pTop = neo;
}

template <typename T>
void Stack<T>::pop() {
	if(m_pTop) {
		Nodo_T *temp = m_pTop;
        m_pTop = m_pTop->*p_Ant;
		delete temp;
	}
}

template <typename T>
T& Stack<T>::top() {
	if(m_pTop)
        return m_pTop->m_dato;
    else
        throw 0;
}

template <typename T>
bool Stack<T>::isEmpty() {
	return m_pTop == NULL;
}

#endif // STACK_H
