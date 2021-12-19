#ifndef PILA_H
#define PILA_H
#include "lista.h"

#include <iostream>
using namespace std;

class Pila : public Lista
{
public:
    Pila();
    void insertar(string cancion);// override;
    void desapilar();
    string cima();
};

#endif // PILA_H
