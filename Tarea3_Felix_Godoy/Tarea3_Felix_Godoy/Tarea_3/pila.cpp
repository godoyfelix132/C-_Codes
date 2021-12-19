#include "pila.h"


Pila::Pila()
{

}

void Pila::insertar(string cancion)
{
    Lista::insertar(cancion);
}

void Pila::desapilar()
{
    nodo=nodo->siguiente;
    size--;
}

string Pila::cima()
{
    return Lista::tomarPrimero();
}


