#include "pila.h"

template <class T>
Pila<T>::Pila()
{

}
template <class T>
void Pila<T>::insertar(T dato)
{
    Lista<T>::insertar(dato);
}

template <class T>
void Pila<T>::desapilar()
{
    if (this->nodo!=0){
        this->temp = this->nodo;
        this->nodo=this->nodo->siguiente;
        delete (this->temp);
        this->size--;
    }
}

template <class T>
T Pila<T>::cima()
{
    return Lista<T>::tomarPrimero();
}


