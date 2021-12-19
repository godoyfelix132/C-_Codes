#include "nodo.h"

Nodo::Nodo()
{
    this -> siguiente=NULL;
}

void Nodo::setDato(string cancion)
{
    this->cancion = cancion;
}

string Nodo::getDato()
{
    return this->cancion;
}
