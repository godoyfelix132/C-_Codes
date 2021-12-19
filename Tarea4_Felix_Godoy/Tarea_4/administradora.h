#ifndef ADMINISTRADORA_H
#define ADMINISTRADORA_H
#include <lista.h>

template <class T>
class Administradora
{
public:
    Administradora();
    void imprimirMenu();
    int obtenerOpcion();
    void ejecutar(int);
private:
    int option;
    Lista<T> lista;
    T dato;
    int index;
    int posicion;
};

#endif // ADMINISTRADORA_H
