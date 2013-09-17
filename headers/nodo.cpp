#include "headers/nodo.h"

template<typename T>
void Nodo<T>::kill_me() {
    if(m_pSig)
        m_pSig->kill_me();
    delete this;
}

template<typename T>
void DNodo<T>::kill_me() {
    if(m_pSig)
        m_pSig->kill_me();
    delete this;
}

template<typename T>
void BinTreeNode<T>::kill_me() {
    for(register size_t i = 0; i < 2; ++i)
        if(m_pChildren[i])
            m_pChildren[i]->kill_me();
    delete this;
}
