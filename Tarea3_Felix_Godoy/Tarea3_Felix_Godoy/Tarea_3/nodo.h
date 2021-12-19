#ifndef NODO_H
#define NODO_H
#include <iostream>
using namespace std;
class Nodo
{
private:
    string cancion;
public:
    Nodo();
    Nodo *siguiente;
    void setDato(string cancion);
    string getDato();
};

#endif // NODO_H
