#ifndef ADMINISTRADORA_H
#define ADMINISTRADORA_H
#include <lista.h>

class Administradora
{
public:
    Administradora();
    void imprimirMenu();
    int obtenerOpcion();
    void ejecutar(int);
private:
    int option;
    Lista lista;
    string cancion;
    int index;
    int posicion;
};

#endif // ADMINISTRADORA_H
