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
